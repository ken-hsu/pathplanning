a =[1,2,3,4,5,6;1,5,6,7,7,2];
bb = minBoundingBox(a);
plot(a(1,:),a(2,:),'*');
hold on;
plot(bb(1,:),bb(2,:));