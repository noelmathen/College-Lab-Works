% b) Edge Detection
% Read an image file
image = imread('/MATLAB Drive/WALLPAPERS/C9.jpg');  % Replace with your image file path
% Convert the image to grayscale
grayImage = rgb2gray(image);
% Apply different edge detection algorithms
edgesSobel = edge(grayImage, 'sobel');
edgesCanny = edge(grayImage, 'canny');
edgesPrewitt = edge(grayImage, 'prewitt');
% Display the original image and edge-detected images side by side with spacing
figure('Units', 'normalized', 'Position', [0.1 0.1 0.8 0.4]);  % Adjust figure size
% Display the original image
subplot(1, 4, 1);
imshow(image);
title('Original Image', 'FontSize', 14, 'FontWeight', 'bold');
% Display Sobel edge-detected image
subplot(1, 4, 2);
imshow(edgesSobel);
title('Sobel Edge Detection', 'FontSize', 14, 'FontWeight', 'bold');
% Display Canny edge-detected image
subplot(1, 4, 3);
imshow(edgesCanny);
title('Canny Edge Detection', 'FontSize', 14, 'FontWeight', 'bold');
% Display Prewitt edge-detected image
subplot(1, 4, 4);
imshow(edgesPrewitt);
title('Prewitt Edge Detection', 'FontSize', 14, 'FontWeight', 'bold');
% Add spacing between the images
subplotHandles = findall(gcf, 'type', 'axes');
for i = 1:numel(subplotHandles)
    subplotHandles(i).Position = subplotHandles(i).Position + [0 0.1 0 0];
end