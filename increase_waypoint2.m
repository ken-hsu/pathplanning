%% Increase waypoint2
% waypoint = [22.0000,120.0009;22.0001,120.0007];
function [waypoint_add_lat,waypoint_add_lon,waypoint_add_amount] = increase_waypoint2(lat,lon)
% lat = [22.0001;22.0004];
% lon = [120.0001;120.0004];

step = round(abs(lon(2) - lon(1))*10000);
waypoint_add_amount = step+1;
waypoint_add_lat = zeros(waypoint_add_amount,1);
waypoint_add_lon = zeros(waypoint_add_amount,1);
slope = abs((lat(2)-lat(1))/(lon(2)-lon(1)));
for j = 0:step-1
    waypoint_add_lon(j+1) = lon(1) + 0.0001*j*sign(lon(2)-lon(1));
    waypoint_add_lat(j+1) = lat(1) + slope*0.0001*j*sign(lat(2)-lat(1));
end
waypoint_add_lat(waypoint_add_amount) = lat(2);
waypoint_add_lon(waypoint_add_amount) = lon(2);
end