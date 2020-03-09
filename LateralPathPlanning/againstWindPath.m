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
compass(R_min*sind(PathAngleRange(:)),R_min*cosd(PathAngleRange(:)));