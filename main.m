clear all;
% map = imread('ASTGTM2_N24E121_dem.tif');
map = imread('ASTGTM2_N25E055_dem.tif');
waypoint = [25.0783,55.4982;
            25.0883,55.5082;
            25.0983,55.5182;
            25.0983,55.9182];
[vertical_waypoint,index_of_waypoint,dis_accu] = function_verticalwaypoint(waypoint,map);
%% plot result
lon = linspace(0,110574,3601);
MetperLon = 111320*cos(waypoint(1,1)*pi/180);
lat = linspace(MetperLon,0,3601);
[xx,yy] = meshgrid(lon,lat);
mesh(xx,yy,map);axis equal
hold on;
x = lon(index_of_waypoint(:,2));
y = lat(index_of_waypoint(:,1));
plot3(x,y,vertical_waypoint(:,3),'*k');
%% examine the waypoint
clear a ;
for i = 1:size(index_of_waypoint,1)
a(i) = map(index_of_waypoint(i,1),index_of_waypoint(i,2));
end
safe_distance = 20;
distance = vertical_waypoint(:,3)+safe_distance - double(a');
unsafe_point = find(distance< 20);