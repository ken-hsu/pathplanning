%%% This script is used to estimate the turning radius of a trajectory
%%% where the bank angle and airspeed are held approximately as a constant
clear variables
close all

g = 9.81;
v_air = 22; % air speed m/s
v_ground = 30;

filePath = '/home/ningyuan/src/logs/identification/';
fileName = 'turning_radius_vehicle_attitude_0.csv';
att_data = csvread([filePath, fileName], 1, 0);

fileName = 'turning_radius_vehicle_local_position_0.csv';
pos_data = csvread([filePath, fileName], 1, 0);

time_att = att_data(:,1);
time_pos = pos_data(:,1);

quat = att_data(:,5:8); % att quaternion
eul = quat2eul(quat);   % quaternion to euler angle
pos = pos_data(:,5:7);

time_start = time_att(8915);    % manually select start and stop time of turning
time_stop = time_att(9015);     % absolute time

pos_turning = pos(time_stop>time_pos & time_start<time_pos, 1:2);
plot(pos_turning(:,1), pos_turning(:,2))
axis equal
xlabel('x(m)'); ylabel('y(m)');

% calculate predicted radius
bank_avg = mean(eul(time_stop>=time_att & time_start<=time_att, 3));
R_predicted = v_ground^2/tan(bank_avg)/g;

% estimate real radius, assuming it's a perfect arc.
% assume y = a*x + b
a = (pos_turning(end,2) - pos_turning(1,2))/(pos_turning(end,1) - pos_turning(1,1));
b = pos_turning(1,2) - a*pos_turning(1,1);

x = pos_turning(1:end,1);
y = a*x + b;
hold on
plot(x, y)

% search for the value of b that makes the straightline tanget to the arc
db = .1;
b_tangent = b + db;
keep_searching = true;

while(~all((y - pos_turning(:,2) > 0) > 0))
    b_tangent = b_tangent + db;
    y = a*x + b_tangent;
end

plot(x, y)

h = abs(b_tangent - b)/sqrt(a^2 + 1);
w = sqrt((pos_turning(end,2) - pos_turning(1,2))^2 + ...
    (pos_turning(end,1) - pos_turning(1,1))^2);
R_estimated = sqrt(h^2 + w^2/4)/sin(atan(h/(w/2)))/2;

R_estimated - R_predicted

