function slope = HIGHT2SLOPE(hight,dis)
    amount = size(hight,1);
    slope = zeros(amount-1,1);
    for i = 1 :size(hight,1)-1
        hight_diff = hight(i+1) - hight(i);
        slope(i,1) = hight_diff/dis(i);
    end
end