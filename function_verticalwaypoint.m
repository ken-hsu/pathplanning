function [vertical_waypoint,index_of_waypoint,num_point] = function_verticalwaypoint(waypoint,map)
clear all;
%% 1
map = imread('ASTGTM2_N24E121_dem.tif');
waypoint = [22.0008,121.1002;
            22.0001,121.1012];
% map = imread('ASTGTM2_N25E055_dem.tif');
%% 2
% waypoint = _IN
%             25.0983,55.5182;
%             25.4983,55.7182];
%% 3
% map = imread('ASTGTM2_N47E008_dem.tif');
% waypoint = [25.0783,55.4982;
%             25.0883,55.5082;
%             25.0983,55.5182;
%             25.0983,55.9182];
%% Round a number        
temp_waypoint = floor(waypoint*10000); %Round a number to 4 decimal places
waypoint = temp_waypoint/10000;
%% Increase waypoint
[waypoint_add_lat,waypoint_add_lon,num_point] = increase_waypoint2(waypoint(1:2,1),waypoint(1:2,2));
%% Calculate distance
InitLat = waypoint(1,1);
[x_coordination,dis_meter] = calculate_distance2(waypoint_add_lat,waypoint_add_lon,num_point,InitLat);
%% get DEM data
[H,index_of_waypoint] = GPS2HIGHTC(waypoint_add_lat,waypoint_add_lon,map);
%% Calculate slope
slope = HIGHT2SLOPE(double(H),dis_meter);


%% slope judgement
slope_threshold = 0.15;
[vertical_waypoint,unvalid] = slope_judgement(double(H),slope,x_coordination,num_point,slope_threshold);
%% delete redundant point
% delete_matrix = ones(size(H,1),1);
% slope2 = HIGHT2SLOPE(vertical_waypoint(:,3),dis_meter);
% for i = 1:num_point-1
%     sp = i;
%     repeat = 1;
%     if sp+repeat < num_point
%         while slope2(sp) == slope2(sp+repeat)
%             repeat = repeat + 1;
%             if sp+repeat >= num_point
%                 break;
%             end
%         end
%     end
%     fp = sp + repeat;
%     if repeat > 1
%         delete_matrix(sp+1:fp-1) = 0;
%     end
% end
% index = find(delete_matrix == 0);
% x_coordination(index) = [];
% index_of_waypoint(index,:) = [];
% vertical_waypoint(index,:) = [];
end