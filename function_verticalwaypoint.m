function [vertical_waypoint,index_of_waypoint] = function_verticalwaypoint(waypoint,map)
% map = imread('ASTGTM2_N24E121_dem.tif');
%% Increase waypoint
step_accu = 0;
for i = 1:size(waypoint,1)-1
    dis_latlon = waypoint(i+1,:) - waypoint(i,:);
    slope = abs(dis_latlon(1)/dis_latlon(2));
    steps = abs(round(dis_latlon(2)/0.0001));
    for j = 0:steps-1
        waypoint_add(j+1+step_accu,2) = waypoint(i,2) + 0.0001*j*sign(dis_latlon(2));
        waypoint_add(j+1+step_accu,1) = waypoint(i,1) + round(slope*0.0001*j*sign(dis_latlon(1)),4);
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
[H,index_of_waypoint] = GPS2HIGHTC(waypoint_add(:,1),waypoint_add(:,2),map);
slope = HIGHT2SLOPE(double(H),dis_meter);


%% slope judgement
hight2 = double(H);
slope_threshold = 0.15;

point_need_change = find(slope > slope_threshold);
for i = 1:size(point_need_change,1)
    point_advance = 0;
    param = slope(point_need_change(i,1));
    while (param > slope_threshold)
        point_advance = point_advance + 1;
        ps = point_need_change(i,1) - point_advance;
        pf = point_need_change(i,1) + 1;
        param = HIGHT2SLOPE([hight2(ps);hight2(pf)],dis_accu(pf)-dis_accu(ps));
    end
    hight_change = hight2(ps) + param*(dis_accu(ps+1:pf-1)-dis_accu(ps));
    hight2(ps+1:pf-1) = hight_change;
    record_same_slope(i,1:point_advance) = ps+1:pf-1;
end
vertical_waypoint(:,1:2) = waypoint_add;
vertical_waypoint(:,3) = hight2;
%% delete redundant point
delete_matrix = ones(size(H,1),1);
slope2 = HIGHT2SLOPE(hight2,dis_meter);
for i = 1:size(slope2,1)-1
    sp = i;
    repeat = 1;
    while slope2(sp) == slope2(sp+repeat)
        repeat = repeat + 1;
    end
    fp = sp + repeat;
    if repeat > 1
        delete_matrix(sp+1:fp-1) = 0;
    end
end
index = find(delete_matrix == 0);
% dis_accu(index) = [];
index_of_waypoint(index,:) = [];
vertical_waypoint(index,:) = [];
end