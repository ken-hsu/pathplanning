function Distance = horizontalUncertainty(p1,p2,p3,p4,k)
    % p1: UAV's scale along to y-axis
    % p2: GPS uncertainty (default is 8 meter)
    % p3: Controller
    % p4: UAV span
    p1 = 2;
    p2 = 8;
    p3 = 2;
    p4 = 2;
    k = 1;
    Distance = 2*(p1 + p2 + p3 + p4*k);
end