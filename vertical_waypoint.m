clear all;
map = imread('ASTGTM2_N24E121_dem.tif');
waypoint = [22.9202,120.9023;
            22.7020,120.7012;
            22.4020,120.4014;
            22.1020,120.1021];
        
%% Increase waypoint
step_accu = 0;
for i = 1:size(waypoint,1)-1
    dis_latlon = waypoint(i+1,:) - waypoint(i,:);
    slope = dis_latlon(1)/dis_latlon(2);
    steps = abs(round(dis_latlon(2)/0.0001));
    for j = 0:steps-1
        waypoint_add(j+1+step_accu,2) = waypoint(i,2) + 0.0001*j*sign(dis_latlon(2));
        waypoint_add(j+1+step_accu,1) = waypoint(i,1) + round(slope*0.0001*j*sign(dis_latlon(2)),4);
    end
    step_accu = steps + step_accu;
end
waypoint_add(1+step_accu,:) = waypoint(end,:);

%% Calculate distance
InitLat = waypoint(1,1);
dis_accu(1,1) = 0;
MetperLat = 110574;
MetperLon = 111320*cos(InitLat*pi/180); % meter per degree
for i = 1:size(waypoint_add,1)-1
    dis_latlon = waypoint_add(i+1,:) - waypoint_add(i,:);
    dis_meter(i,1) = sqrt((dis_latlon(1)*MetperLat)^2  + (dis_latlon(2)*MetperLon)^2);
    dis_accu(i+1,1) = dis_accu(i,1) + dis_meter(i,1);
end

%% Calculate slope
[H,c_record] = GPS2HIGHTC(waypoint_add(:,1),waypoint_add(:,2),map);
for i = 1 :size(H,1)-1
    hight_diff = H(i+1) - H(i);
    slope(i,1) = double(hight_diff)/dis_meter(i);
end
% ss = 1;
% ee = 3601;
% [xx,yy] = meshgrid(ss:ee,ss:ee);
% mesh(xx,yy,map(ss:ee,ss:ee));
% hold on;
% plot3(c_record(:,2),c_record(:,1),H,'*r');
%% slope judgement
hight = double(H);
slope_threshold = 0.9;
for i = 1:size(slope,1)
    if slope(i,1) > slope_threshold
        num_of_advance = 0;
        slope_adjust = slope_threshold+1;
        while (~isempty(find(slope_adjust>slope_threshold)))
            num_of_advance = num_of_advance + 1;
            hight_change = linspace(hight(i-num_of_advance),hight(i+1),num_of_advance+2);
            hight(i-num_of_advance:i+1) = hight_change;
            slope_adjust = 
        end
    end
end
