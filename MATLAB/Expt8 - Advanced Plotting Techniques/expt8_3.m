t = linspace(0, pi, 50); % from 0 to pi
s = linspace(0, 2*pi, 100); % from 0 to 2*pi
[t, s] = meshgrid(t, s); 
x = cos(t) .* cos(s);
y = cos(t) .* sin(s);
z = sin(t);
% Create the sphere plot
figure;
surf(x, y, z, 'FaceAlpha', 0.7);
title('3D Sphere');
xlabel('X-axis');
ylabel('Y-axis');
zlabel('Z-axis');
axis equal; % Equal scaling for all axes
grid on;
light;
lighting phong;
