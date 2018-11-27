%% Calculate distance2
% waypoint_lat = [22.0001;22.0004;22.0005];
% waypoint_lon = [120.0001;120.0002;120.0004];
% num_point = 3;
% InitLat = 28.0;
function [x_coordination,dis_meter]=calculate_distance2(waypoint_lat,waypoint_lon,num_point,InitLat)
% InitLat = waypoint(1,1);
x_coordination = zeros(num_point,1);
dis_meter = zeros(num_point-1,1);
MetperLat = 110574;
MetperLon = 111320*cos(InitLat*pi/180); % meter per degree
for i = 1:num_point-1
    dis_meter(i) = sqrt(((waypoint_lat(i+1)-waypoint_lat(i))*MetperLat)^2  + ((waypoint_lon(i+1)-waypoint_lon(i))*MetperLon)^2);
    x_coordination(i+1) = x_coordination(i,1) + dis_meter(i);
end
end