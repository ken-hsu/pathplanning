%% GPS to HIGHT
% A function with a given DEM, input a GPS location, output a terrian
% Input double(Longitude,Altitude)
% Output int16(Hight)
function output = GPS2HIGHT(lon,lat,Map_Lon_Start,Map_Lon_End,Map_Lat_Start,Map_Lat_End)
% lon = 121.340-0.001; %69
% lat = 23.525; %96
    load('c.mat'); % load map
    map = c;
%     Map_Lat_Start = 24;
%     Map_Lat_End = 23;
%     Map_Lon_Start = 121;
%     Map_Lon_End = 122;
    x = linspace(Map_Lon_Start,Map_Lon_End,length(map));
    y = linspace(Map_Lat_Start,Map_Lat_End,length(map));
    %% find the nearst two value in the array
    [value_x,index_x1] = min(abs(x-lon));
    [value_y,index_y1] = min(abs(y-lat));
        if (value_x == 0 && value_y == 0) % point in the given data
            output = map(index_y1,index_x1);
        else                                % find the maxium value in 4 (or 2) point
            x(index_x1) = Inf;
            [~,index_x2] = min(abs(x-lon));
            y(index_y1) = Inf;
            [~,index_y2] = min(abs(y-lat));
            p1 = map(index_y1,index_x1);
            p2 = map(index_y1,index_x2);
            p3 = map(index_y2,index_x1);
            p4 = map(index_y2,index_x2);
            output = max([p1,p2,p3,p4]);
        end
%     [xx,yy] = meshgrid(x,y); % xx, yy is longitude and latitude respectively    
%     mesh(xx,yy,map);
%     hold on;
%     plot3(121.8,23.8,60,'r*');
end
