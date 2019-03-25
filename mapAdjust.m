% map = rand(25)*20;
map = imread('ASTGTM2_N24E121_dem.tif');
map = map(3400:3600,1:201);
originalMap = map;
[rowSize,columnSize] = size(map);
[xx,yy] = meshgrid(1:columnSize,1:rowSize);
threshold = 5;
for i = 1:rowSize
    for j = 1:columnSize
        if (i+1 <= rowSize && j+1 <= columnSize)
            if (map(i+1,j+1) -map(i,j)>threshold)
                map(i+1,j+1) = map(i,j) + threshold;
            end
            if (map(i+1,j) -map(i,j)>threshold)
                map(i+1,j) = map(i,j) + threshold;
            end
            if (map(i,j+1) -map(i,j)>threshold)
                map(i,j+1) = map(i,j) + threshold;
            end
        else
            if (i+1 <= rowSize)
                if (map(i+1,j) -map(i,j) > threshold)
                    map(i+1,j) = map(i,j) + threshold;
                end
            end
            if (j+1 <= columnSize)
                if (map(i,j+1) - map(i,j)> threshold)
                    map(i,j+1) = map(i,j) + threshold;
                end
            end
        end
        
        if (i-1 >= 1 && j-1 >= 1)
            if (map(i-1,j-1) - map(i,j) >threshold)
                map(i-1,j-1) = map(i,j) + threshold;
            end
            if (map(i-1,j) - map(i,j) > threshold)
                map(i-1,j) = map(i,j) + threshold;
            end
            if (map(i,j-1) - map(i,j) >threshold)
                map(i,j-1) = map(i,j) + threshold;
            end
        else
            if (i-1 >= 1)
                if (map(i-1,j) - map(i,j)>threshold)
                    map(i-1,j) = map(i,j) + threshold;
                end
            end
            if (j-1 >= 1)
                if (map(i,j-1) - map(i,j)>threshold)
                    map(i,j-1) = map(i,j)+threshold;
                end
            end
        end
    end
end
surf(xx,yy,originalMap,'FaceAlpha',0.5);
hold on;
surf(xx,yy,map);
increase = max(max(originalMap - map));
map = map + increase;
figure;
surf(xx,yy,originalMap,'FaceAlpha',0.5);
hold on;
surf(xx,yy,map);
