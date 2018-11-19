%% GPS to HIGHT
% A function with a given DEM, input a GPS location, output a terrian
% Input double(Longitude,Altitude)
% Output int16(Hight)
function H = GPS2HIGHTC(Latitude,Lontitude,map) %lat:10 lon:9
    MapSize = 3601;
    amount = size(Latitude,2);
    for i = 1:amount
        Lat = Latitude(i);
        Lon = Lontitude(i);
        LonDec = (Lon - floor(Lon)); % take the number after the decimal point
        LonDec4 = floor(LonDec*10000); % the number of 4 variable after the decimal point
        LonDec4p1 = round(LonDec4*0.36);
        if LonDec4*0.36 - LonDec4p1 > 0
            flagLon = 1;
        else
            flagLon = -1;
        end
        LonDecCollumn = LonDec4p1+1;


        LatDec = (Lat - floor(Lat));
        LatDec4 = floor(LatDec*10000);
        LatDec4p1 = round(LatDec4*0.36);
        if LatDec4*0.36 - LatDec4p1 > 0
            flagLat = -1;
        else
            flagLat = 1;
        end
        LatDecRow = (MapSize+1) - (LatDec4p1+1); % Index of latitude accounted from lower row to higher
        c = [LatDecRow,LonDecCollumn];
        c1 = [LatDecRow+flagLat,LonDecCollumn];
        c2 = [LatDecRow,LonDecCollumn+flagLon];
    %     if c1(1) > 3601 || c1(1) < 1
    %         c1(1) = c(1);
    %     end
    %     if c2(2) > 3601 || c2(2) < 1
    %         c2(2) = c(2);
    %     end
    %     H = map(c(1),c(2));
    %     H = (map(c(1),c(2))+map(c1(1),c1(2))+map(c2(1),c2(2)))/3;
          H(i) = max([map(c(1),c(2)), map(c1(1),c1(2)) ,map(c2(1),c2(2)) ]);
    end
end
