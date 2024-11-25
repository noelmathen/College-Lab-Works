% Create the cell array
C = {3.14, 'MATLAB', true; 7, [1 2 3], 'hello'};
% Access and display the second element of the first row
secondElement = C{1, 2};
disp('Second element of the first row:');
disp(secondElement);
% Replace the third element of the second row with a new matrix [4 5 6]
C{2, 3} = [4 5 6];
disp('Updated cell array:');
disp(C);
% Modify the content of the first cell to store a structure about a student
studentInfo.name = 'John Doe';
studentInfo.age = 20;
studentInfo.GPA = 3.75;
C{1, 1} = studentInfo;
% Display the updated cell array
disp('Cell array after modifying the first cell:');
disp(C);
