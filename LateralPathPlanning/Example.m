for i = 1:129
    % PredictionF(PredictTime,SampleRat,ThetaRate,ThetaCurrent,ThetaTarget,Vair,DelayStep)
    Trajec1 = PredictionF(25,60,5,i/40,30,25,120);
    Trajec2 = PredictionF(25,60,5,i/40,-30,25,120);
    Trajec3 = PredictionF(25,60,5,i/40,3,25,120);
    Path = [Trajec1(:,2),Trajec1(:,4);Trajec2(:,2),Trajec2(:,4);Trajec3(:,2),Trajec3(:,4)];
    pause(1/60);
    plot(Path(:,1),Path(:,2),'.');axis equal
end
