%% This script is L1 navigator
%           A--------------B-------------C
%       previous         current        next
% waypoint definition follow the above figure
clear all
%% set the waypoint in cartesian coordination (unit: meter)
waypointDefine = [0,0;0, 200;200,300;400,200;400,1000; 400 0; 600 -200; 800 0;1200 0; 1200 -300; 1301 600;-200 -400]';
waypoint_polar = Cartesian2Polar(waypointDefine);
waypoint = Polar2Cartesian(waypoint_polar);
uavHome = [80,-80]';
uavLocation = uavHome;
% uavLocation = [80,280]'; % let abs(angle_AB_BP) < deg2rad(100) be true
%% set L1 parameter
L1_distance = 110;
% L1_damping is ksi in paper 
% L1_period * V is Lp(length-scale) in paper
%% set uav condition
Yaw = 0;
%% initialize algorithm
j = 0; % for record data
%% L1 algorithm
numOfWaypoint = size(waypoint,2);
for i = 1:numOfWaypoint-1
    vectorBP = uavLocation - waypoint(:,i+1);
    BP_distance = norm(vectorBP);
    
    vectorAB = waypoint(:,i+1) - waypoint(:,i);
    AB_distance = norm(vectorAB);
    vectorAB_unit = vectorAB/AB_distance;
    while BP_distance > 20 && vectorBP'*-vectorAB > 0 % arrived determination
        vectorAP = uavLocation - waypoint(:,i);
        AP_distance = norm(vectorAP);
        vectorAP_unit = vectorAP/AP_distance;

        vectorBP = uavLocation - waypoint(:,i+1);
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
            xtrackErr = vectorAP_unit(1)* vectorAB_unit(2) - vectorAP_unit(2)* vectorAB_unit(1);
            eta1 = asin(xtrackErr/L1_distance);
            eta = eta1 + eta2;
        end
        % The angle of eta large than 0 means require a negative roll (going to left)
        TransformMatrix =   [cos(Yaw) sin(Yaw);% transform from body to NED
                            -sin(Yaw) cos(Yaw)];
        % change sign of the eta for calculate correct lateral acceleration
        eta = -eta;
        LA = 2*sin(eta)/L1_distance;
        
        % airplane lateral dynamics
        MAX_LateralAcceleration = 10;
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
        
        j = j +1;
        uavLocationRecord(:,j) = uavLocation;
        YawRecord(j) = Yaw;
        RRecord(j) = R;
    end
end
plot(uavLocationRecord(1,:),uavLocationRecord(2,:)); axis equal
hold on;
plot(waypoint(1,:),waypoint(2,:)); % plot waypoint line
hold on;
plot(waypoint(1,:),waypoint(2,:),'*'); % plot waypoint
for i = 1:numOfWaypoint
    text(waypoint(1,i),waypoint(2,i),num2str(i));
end
text(uavHome(1),uavHome(2),'uav home');
title('uav trajectory simulation');
xlabel('east meter');
ylabel('north meter');