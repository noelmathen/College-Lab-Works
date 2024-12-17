% c) Image Scaling with Custom Neighbor Averaging
% Read an image file
image = imread('/MATLAB Drive/WALLPAPERS/C9.jpg');  % Replace with your image file path
% Convert the image to grayscale
grayImage = double(rgb2gray(image));
% Get the size of the image
[rows, cols] = size(grayImage);
% Create a copy of the image for output
scaledImage = grayImage;
% Process each pixel (ignoring the borders)
for i = 2:rows-1
    for j = 2:cols-1
        % Calculate the average of the four nearest neighbors
        averageValue = (grayImage(i-1, j) + grayImage(i+1, j) + grayImage(i, j-1) + grayImage(i, j+1)) / 4;
        % Set the pixel to the average value
        scaledImage(i, j) = averageValue;
    end
end
% Convert the processed image back to uint8 for display
scaledImage = uint8(scaledImage);
% Display the original and scaled images side by side
figure;
subplot(1, 2, 1);
imshow(uint8(grayImage));
title('Original Grayscale Image');
subplot(1, 2, 2);
imshow(scaledImage);
title('Scaled Image (Neighbor Averaging)');