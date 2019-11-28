% This script is produce a waypoint before the home position in order to
% stable the back transition. The waypoint represent as a distance and an
% angle refer to the north direction.
clear all
windSpeed = 20;
windDirection = 180; % the direction of wind come from
minumumAirspeed = 23;
deaccelaration = 0.7; % deacceleration
waypointDirection = 0;
waypointDistance =  380;
% [R_min,PathAngleRange] = backTransitionMinimnumPath(deaccelaration,windSpeed,windDirection,minumumAirspeed,waypointDirection,waypointDistance);
% function [R_min,PathAngleRange] = backTransitionMinimnumPath(deaccelaration,windSpeed,windDirection,minumumAirspeed,waypointDirection,waypointDistance)
    R_min = minumumAirspeed^2/(2*deaccelaration); % V_f^2 = V_s^2 + 2*a*S
    MaxBeta = 15;% maximan side slip angle
    if (tand(MaxBeta)*minumumAirspeed/windSpeed > 1)
        rp1 = 1;
    elseif(tand(MaxBeta)*minumumAirspeed/windSpeed < 0)
        rp1 = 0;
    else 
        rp1 = tand(MaxBeta)*minumumAirspeed/windSpeed;
    end
    AcceptCrossWindAngle = asind(rp1);
    PathAngle = rem(windDirection + 180,360);
    PathAngleRange = [PathAngle+AcceptCrossWindAngle PathAngle PathAngle-AcceptCrossWindAngle];
    
    ExampleAngle = linspace(PathAngleRange(1),PathAngleRange(3),1000);
    for i = 1:size(ExampleAngle,2)
    angle = ExampleAngle(i);
    waypointDirection = rem(waypointDirection,360); % make sure waypointDirection is +-0~360
    v1(:,1) = [R_min*cosd(angle) - waypointDistance*cosd(waypointDirection);
                R_min*sind(angle) - waypointDistance*sind(waypointDirection)];
    v2(:,1) = [-R_min*cosd(angle);
                -R_min*sind(angle)];
    theta = acosd((v1'*v2)/(norm(v1)*norm(v2)));
    minimunReturnRadius = 110;
    % map angle(theta) 0-180 to gain 0-3
    gain = theta/60;
    distance(i,1) = R_min + gain*minimunReturnRadius;
    end
% end
figure(1);
subplot(2,1,1);
compass(-windSpeed*cosd(windDirection),-windSpeed*sind(windDirection));
hold on;
compass(R_min*cosd(PathAngleRange(1)),R_min*sind(PathAngleRange(1)),'r');
hold on;
compass(R_min*cosd(PathAngleRange(3)),R_min*sind(PathAngleRange(3)),'r');

subplot(2,1,2);
plot([0,R_min*cosd(PathAngleRange(1))],[0,R_min*sind(PathAngleRange(1))],'r');
hold on;
plot([0,R_min*cosd(PathAngleRange(2))],[0,R_min*sind(PathAngleRange(2))],'r');
hold on;
plot([0,R_min*cosd(PathAngleRange(3))],[0,R_min*sind(PathAngleRange(3))],'r');
hold on;
for i = 1:size(ExampleAngle,2)
    x(i)=distance(i)*cosd(ExampleAngle(i));
    y(i)=distance(i)*sind(ExampleAngle(i));
end
plot(x,y,'b');
plot(waypointDistance*cosd(waypointDirection),waypointDistance*sind(waypointDirection),'*r');