% 3_2 - Transpose of a Matrix
a11 = input('Enter element(1,1): ');
a12 = input('Enter element(1,2): ');
a21 = input('Enter element(2,1): ');
a22 = input('Enter element(2,2): ');

matrix = [a11 a12; a21 a22];
matrixt = matrix';

fprintf('Matrix inputted:\n');
disp(matrix);

fprintf('Matrix transpose:\n');
disp(matrixt);
