%% Prediction
% function to easily test
% Author: hsuncheng ken
% Date: 2019/03/25
% Input 
% Output
% function Locate = pathPredict(PredictTime,SampleRat,Vair,DelayTime)
Locate = zeros(30,2);
Vair = linspace(30,40,600);
DistanceInOneStep = 2;
theta = 20;
delta = 0;
    g = 9.81;   % N/m
    for i = 1:600
        Radius = (Vair(i)^2)./(g*tand(theta));
        RadInThisStep = DistanceInOneStep/Radius; % theta = L/R
        t = [0,RadInThisStep];
        x = Radius*cos(t);
        y = Radius*sin(t);
        % Coordination transform
        [x,y] = CoordinationTranslate(x,y,delta,Locate(i,1),Locate(i,2));
        Locate(i+1,1) = x(2);
        Locate(i+1,2) = y(2);
        % Update
        delta = RadInThisStep + delta;
    end
    plot(Locate(:,1),Locate(:,2)); axis equal
    hold on;
    plot(Locate(1,1),Locate(1,2),'*r');
% end


