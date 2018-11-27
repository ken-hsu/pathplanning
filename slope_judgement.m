%% slope judgement

function [vertical_waypoint,unvalid] = slope_judgement(H,slope,x_coordination,num_point,slope_threshold)
vertical_waypoint = zeros(num_point,1);
unvalid = 0;
point_need_change = find(slope > slope_threshold);
ps = 0;
pf = 0;
for i = 1:size(point_need_change,1)
    point_advance = 0;
    param = slope(point_need_change(i,1));
    while (param > slope_threshold)
        point_advance = point_advance + 1;
        ps = point_need_change(i,1) - point_advance;
        pf = point_need_change(i,1) + 1;
        if ps <= 0
            unvalid = 1;
            ps = 1;
            break;
        end
        param = HIGHT2SLOPE([H(ps);H(pf)],x_coordination(pf)-x_coordination(ps));
    end
    ps_next = ps+1;
    pf_prev = pf-1;
    hight_change = H(ps) + param*(x_coordination(ps_next:pf_prev)-x_coordination(ps));
    H(ps+1:pf-1) = hight_change;
    %record_same_slope(i,1:point_advance) = ps+1:pf-1;
end
vertical_waypoint(:,1) = H;
end