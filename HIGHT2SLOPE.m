function () = HIGHT2SLOPE
    for i = 1 :size(H,1)-1
        hight_diff = H(i+1) - H(i);
        slope(i,1) = double(hight_diff)/dis_meter(i);
    end
end