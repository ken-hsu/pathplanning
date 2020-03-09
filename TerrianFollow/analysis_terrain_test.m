% Analysis the performance of offline path planning
clear all;
wp = importdata('/home/ken/src/Ken/analysis/FT02.txt');
wp_size = size(wp,1);
% wp_size + 1 is the number of waypoint in QGC

Path = '/home/ken/Documents/log/FT02/real/';
Position_name = 'log_66_2018-12-20-15-05-06_vehicle_gps_position_0.csv';
Position = csvread([Path, Position_name],1,0);
Vxy_ground_I_Position(:,2) = Position(:,3)*10^-7;
Vxy_ground_I_Position(:,1) = Position(:,4)*10^-7; % x axis is East
Vxy_ground_I_Position_z = Position(:,7); % x axis is East

arrivedpoint_name = 'log_66_2018-12-20-15-05-06_arrived_point_0.csv';
arrivedpoint = csvread([Path, arrivedpoint_name],1,0);
GPSLat = arrivedpoint(end-wp_size+1:end,2);
GPSLon = arrivedpoint(end-wp_size+1:end,3);
hight = arrivedpoint(end-wp_size+1:end,4);

plot(Vxy_ground_I_Position(:,1),Vxy_ground_I_Position(:,2));axis equal
hold on;
plot(GPSLon,GPSLat,'*');axis equal
hold on;
plot(wp(:,2),wp(:,1));
legend('GPS','arrived point','wp');
title('Horizontal comparison');

figure;
plot(wp(:,3));
hold on;
plot(hight);
legend('wp','arrived');
title('Hight comparison');

hight_MSE = (sum(abs(hight(2:end) - wp(2:end,3))))/wp_size;
hight_Var = var((hight(2:end)-wp(2:end,3)));

dis = zeros(size(wp,1),1);
for i = 1:size(wp,1)
    dis(i) = lldistkm([GPSLat(i,1),GPSLon(i,1)],[wp(i,1),wp(i,2)]);
end
hori_MSE = (sum((dis).^2))/wp_size;
