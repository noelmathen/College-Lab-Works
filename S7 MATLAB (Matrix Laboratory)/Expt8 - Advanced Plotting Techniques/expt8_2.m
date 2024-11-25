[x, y] = meshgrid(-5:0.5:5, -5:0.5:5); z = sin(sqrt(x.^2 + y.^2));
figure;
surf(x, y, z);
title('3D Surface Plot of z = sin(√(x² + y²))');
xlabel('X-axis');
ylabel('Y-axis');
zlabel('Z-axis');
colorbar;grid on;
hold on;

plot3(x(1,:), y(1,:), z(1,:), 'k', 'LineWidth', 2); 
scatter3(x(:), y(:), z(:), 20, 'r', 'filled'); 
hold off;
