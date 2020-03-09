% waypoint_polar(1) = distance in meter
% waypoint_polar(2) = angle in rad
function waypoint_cartesian = Polar2Cartesian(waypoint_polar)
    numOfWaypoint = size(waypoint_polar,2);
    waypoint_cartesian = zeros(2,numOfWaypoint);
    for i = 1:numOfWaypoint
        distance = waypoint_polar(1,i);
        angle = waypoint_polar(2,i);
        waypoint_cartesian(1,i) = distance*cos(angle);
        waypoint_cartesian(2,i) = distance*sin(angle);
    end
end