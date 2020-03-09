%% Prediction
% function to easily test
% Author: hsuncheng ken
% Date: 2019/03/25
% Input 
% Output
% function Locate = pathPredict(PredictTime,SampleRat,Vair,DelayTime)
Locate = zeros(30,2);
wind = 14;
vair = 25;
arc_length = 2; % unit: meter
latertal_accelaration = 5;   % N/m 0.5*rho*v^2*S*sind(30)/mass

delta = 0; % delta is the angle between wind vector and vehicle velocity
i = 0;
waypointDirection = 180*pi/180;
    while delta < waypointDirection
        i = i + 1;
        vground = vair + wind*cos(delta);
        Radius = (vground^2)./(latertal_accelaration);
        RadInThisStep = arc_length/Radius; % theta = L/R
        angle = [0,RadInThisStep];
        x = Radius*cos(angle);
        y = Radius*sin(angle);
        % Coordination transform
        [x,y] = CoordinationTranslate(x,y,delta,Locate(i,1),Locate(i,2));
        Locate(i+1,1) = x(2);
        Locate(i+1,2) = y(2);
        % Update
        delta = RadInThisStep + delta;
    end
    plot(Locate(:,1),Locate(:,2),'*'); axis equal
    hold on;
    plot(Locate(1,1),Locate(1,2),'r*');
% end


