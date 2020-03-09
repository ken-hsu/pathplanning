% input definition
% waypoint_polar(1) = distance in meter
% waypoint_polar(2) = angle in rad
function waypoint_polar = Cartesian2Polar(waypoint_cartesian)
    numOfWaypoint = size(waypoint_cartesian,2);
    waypoint_polar = zeros(2,numOfWaypoint);
    for i = 1:numOfWaypoint
        waypoint_polar(1,i) = norm(waypoint_cartesian(:,i));
        waypoint_polar(2,i) = atan2(waypoint_cartesian(2,i),waypoint_cartesian(1,i));
    end
end