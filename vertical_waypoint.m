clear all;
map = imread('ASTGTM2_N24E121_dem.tif');
waypoint = [22.9202,120.9023;
            22.7020,120.7012;
            22.4020,120.4014;
            22.1020,120.1021];
        
%% Increase waypoint
step_accu = 0;
for i = 1:size(waypoint,1)-1
    dis_latlon = waypoint(i+1,:) - waypoint(i,:);
    slope = dis_latlon(1)/dis_latlon(2);
    steps = abs(round(dis_latlon(2)/0.0001));
    for j = 0:steps-1
        waypoint_add(j+1+step_accu,2) = waypoint(i,2) + 0.0001*j*sign(dis_latlon(2));
        waypoint_add(j+1+step_accu,1) = waypoint(i,1) + round(slope*0.0001*j*sign(dis_latlon(2)),4);
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
[H,c_record] = GPS2HIGHTC(waypoint_add(:,2),waypoint_add(:,1),map);
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
end

% plot(dis_accu,H,'*');axis equal
% hold on;
% plot(dis_accu,hight2+20);axis equal
% legend('original','adjust');
% figure;
ss = 1000;
tt = 2800;
[xx,yy] = meshgrid(ss:tt,tt:-1:ss);
mesh(xx,yy,map(ss:tt,ss:tt)/5);axis equal
hold on;
plot3(c_record(:,2),3602-c_record(:,1),H/5,'*k');
hold on;
plot3(c_record(:,2),3602-c_record(:,1),hight2/5,'*r');