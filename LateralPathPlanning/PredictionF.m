%% Prediction
% function to easily test
% Author: hsuncheng ken
% Date: 2018/08/15
% Input 
% Output
function Locate = PredictionF(PredictTime,SampleRat,ThetaRate,ThetaCurrent,ThetaTarget,Vair,DelayTime)
% clear all;
% PredictTime = 25; % Unit: sec
% SampleRat = 60;            % Unit: 60 hz
% ThetaRate = 5;
% ThetaCurrent = 3;
% ThetaTarget = 3;
% Vair = 25;     % m/s
% DelayTime = 0.2;

    
    ThetaCurrentRad = ThetaCurrent*(pi/180);% Unit: rad
    ThetaTargetRad = ThetaTarget*(pi/180); % Unit: rad
    ThetaRateInStep = (ThetaRate*(pi/(180*SampleRat)));  % Unit: rad/per sample step
    DistanceInOneStep = Vair/SampleRat;
    g = 9.81;   % N/m
    ThetaError = ThetaTargetRad - ThetaCurrentRad;
    PredictStep = PredictTime*SampleRat;
    DelayStep = DelayTime*SampleRat;                        % Delay before change
    TranslateStep = floor(abs(ThetaError/ThetaRateInStep)); % Translate turning
    TurnStep = PredictStep-(TranslateStep+DelayStep);       % Stable truning
    DelayIndex = 1;
    TranslateIndex = DelayIndex + DelayStep;
    TrunIndex = TranslateIndex + TranslateStep;
    % Make a Theta sequence
    ThetaState = zeros(1,PredictStep);
    ThetaState(1,DelayIndex:DelayIndex+DelayStep-1) = ThetaCurrentRad;
    ThetaState(1,TranslateIndex:TranslateIndex+TranslateStep-1) = linspace(ThetaCurrentRad,ThetaTargetRad,TranslateStep);
    ThetaState(1,TrunIndex:TrunIndex+TurnStep-1) = ThetaTargetRad;
    Radius = (Vair^2)./(g*tan(ThetaState));
    % Initialize
    delta = 0; 
    Locate = zeros(PredictStep,2);
    % Delay Step---------------------------------------------------------
    [x,y,RadInThisStep] = StableTurn(Radius(1,DelayIndex),DelayStep,DistanceInOneStep);
    [xout,yout] = CoordinationTranslate(x,y,delta,0,0);
    delta = delta + RadInThisStep;
    Locate(1:DelayStep,1) = xout;
    Locate(1:DelayStep,2) = yout; 
    %--------------------------------------------------------------------
    % Translate step-----------------------------------------------------
    for i = TranslateIndex:TranslateIndex+TranslateStep-1
        if Radius(1,i) >2000
            Radius(1,i) = 2000;
        end
        RadInThisStep = DistanceInOneStep/Radius(1,i);
        t = [0,RadInThisStep];
        x = Radius(1,i)*cos(t);
        y = Radius(1,i)*sin(t);
        % Coordination transform
        [x,y] = CoordinationTranslate(x,y,delta,Locate(i-1,1),Locate(i-1,1));
        Locate(i,1) = x(2);
        Locate(i,2) = y(2);
        % Updat
        delta = RadInThisStep + delta;
    end
    %---------------------------------------------------------------------
    % Turn Step-----------------------------------------------------------
    [x,y] = StableTurn(Radius(1,end),TurnStep,DistanceInOneStep);
    [xout,yout] = CoordinationTranslate(x,y,delta,Locate(i,1),Locate(i,2));
%     delta = delta + RadInThisStep;
    Locate(TrunIndex:TrunIndex+TurnStep-1,1) = xout;
    Locate(TrunIndex:TrunIndex+TurnStep-1,2) = yout; 

%     plot(Locate(:,1),Locate(:,2),'*');axis equal
end


