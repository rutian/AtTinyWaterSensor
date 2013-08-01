% atTiny85 calibration 7/25/2013


%%
load AtTiny7_25data.mat


%%
hold on;
plot(AtlasSci,AtTiny,'o'); 
xlabel('Atlas Sci');
ylabel('AtTiny');
x = 1:100:3500;
plot(x,x,'--');
title('AtTiny85 vs Atlas Scientific');
hold off;

