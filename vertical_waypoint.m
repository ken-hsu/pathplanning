clear all;
map = imread('ASTGTM2_N22E120_dem.tif');
waypoint = [22.1202,120.1023;
            22.4020,120.4012;
            22.7020,120.7014;
            22.9020,120.9021];
        
H = GPS2HIGHTC(waypoint(:,1),waypoint(:,2),map);