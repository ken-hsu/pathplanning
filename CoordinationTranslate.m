% clockwise is positive
function [xout,yout] = CoordinationTranslate(x,y,delta,xlest,ylest)
    TransMatric = [cos(delta) sin(delta); % delta is total of rotation in rad
                   -sin(delta)  cos(delta)];
    tempxy = TransMatric*[x;y];
    x = tempxy(1,:);
    y = tempxy(2,:);
    if isempty(xlest)
        xlest = 0;
    end
    if isempty(ylest)
        ylest = 0;
    end
    xout = x + (xlest-x(1));
    yout = y + (ylest-y(1));
end