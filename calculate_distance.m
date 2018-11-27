%% Calculate distance
function [x_coordination,dis_meter]=calculate_distance(waypoint_add,num_point,InitLat)
% InitLat = waypoint(1,1);
x_coordination = zeros(num_point,1);
dis_meter = zeros(num_point-1,1);
MetperLat = 110574;
MetperLon = 111320*cos(InitLat*pi/180); % meter per degree
for i = 1:num_point-1
    dis_latlon = waypoint_add(i+1,:) - waypoint_add(i,:);
    dis_meter(i,1) = sqrt((dis_latlon(1)*MetperLat)^2  + (dis_latlon(2)*MetperLon)^2);
    x_coordination(i+1,1) = x_coordination(i,1) + dis_meter(i,1);
end
end