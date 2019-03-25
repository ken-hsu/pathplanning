a = imread('ASTGTM2_N30E117_dem.tif');
b = imread('ASTGTM2_N30E117_dem.tif');
a(find(a<0)) = 0;
mapsize = 200;
startx = 833
starty = 1321;
c = a(startx:startx+mapsize,starty:starty+mapsize);
d = a;
d(startx:startx+mapsize,starty:starty+mapsize)=10000;
[x,y] = meshgrid(1:length(c),1:length(c));
figure;
mesh(x,y,c);
colormap jet;
figure;
image(d);
save('c','c')