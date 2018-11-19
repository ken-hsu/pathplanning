clear all;
map = imread('ASTGTM2_N22E120_dem.tif');
waypoint = [22.1202,120.1023;
            22.9020,120.4012;
            22.7020,120.9014;
            22.9020,120.7021];
        
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
MetperLat = 110574;
MetperLon = 111320*cos(InitLat*pi/180); % meter per degree
for i = 1:size(waypoint_add,1)-1
    dis_latlon = waypoint_add(i+1,:) - waypoint_add(i,:);
    dis_meter(i,1) = sqrt((dis_latlon(1)*MetperLat)^2  + (dis_latlon(2)*MetperLon)^2);
end

%% Calculate slope
H = GPS2HIGHTC(waypoint_add(:,1),waypoint_add(:,2),map);
for i = 1 :size(H,2)-1
    H(i+1) - H(i)
    slope = double(H)/dis_meter;
end
