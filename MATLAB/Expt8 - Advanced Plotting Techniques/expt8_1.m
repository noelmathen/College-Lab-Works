x = 0:0.01:2*pi;
y_sin = sin(x);
y_cos = cos(x);
% First figure: Sine wave
figure;
plot(x, y_sin, 'b', 'LineWidth', 2);
title('Sine Wave');
xlabel('x (radians)');
ylabel('sin(x)');
legend('sin(x)');
grid on;
% Second figure: Cosine wave
figure;
plot(x, y_cos, 'r', 'LineWidth', 2);
title('Cosine Wave');
xlabel('x (radians)');
ylabel('cos(x)');
legend('cos(x)');
grid on;
