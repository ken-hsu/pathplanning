    function [x,y,RadInThisStep] = StableTurn(Radius,Step,DistanceInOneStep)
        % Turn step
        if Radius == Inf
            % Go straight
            x = zeros(1,Step);
            y = (DistanceInOneStep)*(1:Step);
        else  
            RadInThisStep = Step*DistanceInOneStep/Radius;
            t = linspace(0,RadInThisStep,Step);
            x = Radius*cos(t);
            y = Radius*sin(t);
        end
    end