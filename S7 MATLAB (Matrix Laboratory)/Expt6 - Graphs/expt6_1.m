% 6_1 - Plotting Sines and Cosines
x = 0:0.5:2*pi;
y = sin(x);
z = cos(x);

subplot(2,1,1);
plot(x, y, 'b-');
title("Sine");
xlabel("Values of sine");
ylabel("Values plotted");
legend('sin(x)');
grid on;

subplot(2,1,2);
plot(x, z, 'r:');
title("Cosine");
xlabel("Values of cosine");
ylabel("Values plotted");
legend('cos(x)');
grid on;
