%% Increase waypoint
% waypoint = [22.0000,120.0009;22.0001,120.0007];
function [waypoint_add,waypoint_add_amount] = increase_waypoint(waypoint)
% waypoint = [22.0001,120.0001;22.0004,120.0006];
group = size(waypoint,1);
step_accu = 0; % step accumulation
waypoint_add_amount = 0;
for i = 1:group-1
    step_temp = floor(abs(waypoint(i+1,2) - waypoint(i,2))*10000);
    waypoint_add_amount = step_temp + waypoint_add_amount;
end
waypoint_add_amount = group + waypoint_add_amount;
waypoint_add = zeros(waypoint_add_amount,2);
for i = 1:group-1
    minus_latlon = waypoint(i+1,:) - waypoint(i,:);
    slope = abs(minus_latlon(1)/minus_latlon(2));
    steps = abs(floor(minus_latlon(2)*10000));
    for j = 0:steps-1
        waypoint_add(j+1+step_accu,2) = waypoint(i,2) + 0.0001*j*sign(minus_latlon(2));
        waypoint_add(j+1+step_accu,1) = waypoint(i,1) + slope*0.0001*j*sign(minus_latlon(1));
    end
    step_accu = steps + step_accu;
end
waypoint_add(1+step_accu,:) = waypoint(group,:);
end