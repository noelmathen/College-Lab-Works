% Part 1: Anonymous Functions and Function Handles
% Define an anonymous function to compute the square of a number
squareFunc = @(x) x^2;
% Create a function handle to the anonymous function
squareHandle = squareFunc;
% Prompt the user to enter a number
num = input('Enter a number to compute its square: ');
% Use the function handle to compute and display the square
squareValue = squareHandle(num);  % Call the function handle
disp(['The square of ', num2str(num), ' is: ', num2str(squareValue)]);
