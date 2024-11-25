% 5_3 Square of Each Element in a Vector
v = [1 2 3 4 5 6 7 8 9 10];
squares = zeros(1, length(v));
for i = 1:length(v)
    squares(i) = v(i)^2;
end
disp("Square of each element in the vector is: ");
disp(squares);
