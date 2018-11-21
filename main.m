map = imread('ASTGTM2_N24E121_dem.tif');
waypoint = [24.9202,120.7023;
            24.7020,120.9012;
            24.9020,120.7012];
[vertical_waypoint,index_of_waypoint] = function_verticalwaypoint(waypoint,map);
%% plot result
[xx,yy] = meshgrid(1:3601,3601:-1:1);
mesh(xx,yy,map);
hold on;
plot3(index_of_waypoint(:,2),3602-index_of_waypoint(:,1),vertical_waypoint(:,3),'*k');