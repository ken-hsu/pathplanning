% survey = [  30.0063,117.0028;
%             30.5600,117.0021;
%             30.5612,117.5521;
%             30.0073,117.5511];
% space = 50; % Unit: meter
% InitLat = survey(1,1);
MetperLat = 110574;
MetperLon = 111320*cos(InitLat*pi/180); % meter per degree
% MetperLat*(waypoint(1,1)-waypoint(2,1))
% %% Flight performance
% MIN_vel = 21; % Uint: m/s
% MAX_pitch = 15;
% MAX_climb = MIN_vel*sind(MAX_pitch);