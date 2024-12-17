% a)  Basic Image Manipulation
% Read an image file
image = imread('/MATLAB Drive/WALLPAPERS/C9.jpg');  
% Convert the image to grayscale
grayImage = rgb2gray(image);
% Display the original and grayscale images side by side
figure;
subplot(1, 2, 1);
imshow(image);
title('Original Image');
subplot(1, 2, 2);
imshow(grayImage);
title('Grayscale Image');