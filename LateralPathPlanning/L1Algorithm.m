%           A--------------B-------------C
%       previous         current        next
% waypoint definition follow the above figure
% function point_latlon = L1Algorithm (waypoint_latlon,L1_distance,uavHome_latlon,Yaw)
%% for simulation
    clear all;
    % parameter setting
    L1_distance = 110;
    % read plan from file
    fileID = fopen('/home/ken/Documents/xxxx.plan');
    C = textscan(fileID, '%s','Delimiter',',');
    co = 0;
    for i = 1:size(C{1},1)
    if (C{1}{i} == num2str(0))
    co = co +1;
    end
    end
    numOfWaypoint = co/3 +1;
    waypoint_latlon = zeros(2,numOfWaypoint);
    for i = 1:numOfWaypoint-1
    waypoint_latlon(1,i+1) = str2double(C{1}{29+(i-1)*19})*pi/180;
    waypoint_latlon(2,i+1) = str2double(C{1}{30+(i-1)*19})*pi/180;
    end

    % uav condition
    Yaw = 0;
    uavHome_latlon = [47.397742 8.545594]'*pi/180;

%% for code generation

    % number of waypoint
    numOfWaypoint = size(waypoint_latlon,2);
    
    % Constant
    radiousOfEarth = 6371000;

    % first waypoint is home position
    waypoint_latlon(:,1) = uavHome_latlon;
    
    % transfer latlon to meter
    waypoint_cartesianNE = [waypoint_latlon(1,:) - uavHome_latlon(1);(waypoint_latlon(2,:) - uavHome_latlon(2))*cos(uavHome_latlon(1))]*radiousOfEarth;
    uavHome_cartesian = [0 0]';
    uavLocation = uavHome_cartesian;
    
    % calculate total distance for the parameter declaration
    vector = waypoint_cartesianNE(:,2:end) - waypoint_cartesianNE(:,1:end-1);
    totalDistance = 0;
    for i = 1:numOfWaypoint-1
    totalDistance = norm(vector(:,i)) + totalDistance;
    end
    predictNumOfPoint = floor(totalDistance*1.2);
    point_cartesianNE = zeros(2,predictNumOfPoint);
    
    % L1 algorithm
    numOfPoint = 0;
    for i = 1:numOfWaypoint-1
        vectorBP = uavLocation - waypoint_cartesianNE(:,i+1);
        BP_distance = norm(vectorBP);

        vectorAB = waypoint_cartesianNE(:,i+1) - waypoint_cartesianNE(:,i);
        AB_distance = norm(vectorAB);
        vectorAB_unit = vectorAB/AB_distance;
        while BP_distance >30 && vectorBP'*-vectorAB > 0 % arrived determination
            vectorAP = uavLocation - waypoint_cartesianNE(:,i);
            AP_distance = norm(vectorAP);
            if (AP_distance == 0)
                vectorAP_unit = [0 0]';
            else
                vectorAP_unit = vectorAP./AP_distance;
            end
            

            vectorBP = uavLocation - waypoint_cartesianNE(:,i+1);
            BP_distance = norm(vectorBP);
            vectorBP_unit = vectorBP/BP_distance;

            vectorV = [sin(Yaw);cos(Yaw)];
            vectorV_unit = vectorV/norm(vectorV);

            alongTrackDist = vectorAP'*vectorAB_unit;
            angle_AB_BP = acos(vectorAB_unit'*vectorBP_unit);
            angle_V_AB = acos(vectorV_unit'*vectorAB_unit);
            if (AP_distance > L1_distance && (alongTrackDist / AP_distance) < -0.7071)% if ... go to waypoint A
                xtrack_vel = vectorV_unit(1)* -vectorAP_unit(2) - vectorV_unit(2)* -vectorAP_unit(1);
                ltrack_vel = -vectorAP_unit'*vectorV_unit;
                eta = atan2(xtrack_vel,ltrack_vel);
            elseif (abs(angle_AB_BP) < deg2rad(100) || abs(angle_V_AB) >= deg2rad(90))% if miss waypoint B, go to waypoint B
                xtrack_vel = vectorV_unit(1)* -vectorBP_unit(2) - vectorV_unit(2)* -vectorBP_unit(1);
                ltrack_vel = -vectorBP_unit'*vectorV_unit;
                eta = atan2(xtrack_vel,ltrack_vel);
            else
                xtrack_vel = vectorV_unit(1)* vectorAB_unit(2) - vectorV_unit(2)* vectorAB_unit(1);% fly along the line AB
                ltrack_vel = vectorAB_unit'*vectorV_unit;
                eta2 = atan2(xtrack_vel,ltrack_vel);
                xtrackErr = vectorAP(1)* vectorAB_unit(2) - vectorAP(2)* vectorAB_unit(1);
                sine_eta1 = sin(xtrackErr/L1_distance);
                if sine_eta1 > pi/4
                    sine_eta1 = pi/4;
                elseif sine_eta1 < -pi/4
                    sine_eta1 = -pi/4;
                end
                eta1 = asin(sine_eta1);
                eta = eta1 + eta2;
            end
            % The angle of eta large than 0 means require a negative roll (going to left)
            TransformMatrix =   [cos(Yaw) sin(Yaw);% transform from body to NED
                                -sin(Yaw) cos(Yaw)];
            % change sign of the eta for calculate correct lateral acceleration
            eta = -eta;
            LA = 2*sin(eta)/L1_distance;

            % airplane lateral dynamics
            MAX_LateralAcceleration = 0.01;
            if LA > MAX_LateralAcceleration
                LA = MAX_LateralAcceleration;
            end
            R = 1/LA;
            AL = 1; % arc length unit:m/s (this value determine the iteration precision)
            theta  = AL/R;
            vectorPP2_body = [R-R*cos(theta) R*sin(theta)]';% a vector in body coordination, represent uav location in this time stamp to the next time stamp

            vectorPP2_NED = TransformMatrix*vectorPP2_body;% tramsform vector to NED frame
            uavLocation = uavLocation + vectorPP2_NED;
            Yaw = Yaw + theta;

            numOfPoint = numOfPoint +1;
            if (numOfPoint > predictNumOfPoint)
                error('out of memory');
            end
            point_cartesianNE(:,numOfPoint) = uavLocation;
        end
    end
    point_latlon = zeros(2,numOfPoint);
    % cartesian to polar
    point_latlon(1,:) = uavHome_latlon(1) + point_cartesianNE(1,1:numOfPoint)./radiousOfEarth;
    point_latlon(2,:) = uavHome_latlon(2) + point_cartesianNE(2,1:numOfPoint)./radiousOfEarth./cos(uavHome_latlon(1));
% end


%% for simulation
plot(point_cartesianNE(2,1:numOfPoint),point_cartesianNE(1,1:numOfPoint)); axis equal
hold on;
plot(waypoint_cartesianNE(2,:),waypoint_cartesianNE(1,:)); % plot waypoint line
hold on;
plot(waypoint_cartesianNE(2,:),waypoint_cartesianNE(1,:),'*'); % plot waypoint
for i = 1:numOfWaypoint
    text(waypoint_cartesianNE(2,i),waypoint_cartesianNE(1,i),num2str(i-1));
end
text(uavHome_cartesian(2),uavHome_cartesian(1),'uav home');
title('uav trajectory simulation');
xlabel('east meter');
ylabel('north meter');