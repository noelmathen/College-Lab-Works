% Define a structure array for 3 students
students(1).Name = 'Alice';
students(1).Age = 21;
students(1).Marks = [85, 90, 88, 92];
students(2).Name = 'Bob';
students(2).Age = 22;
students(2).Marks = [78, 85, 80, 82];
students(3).Name = 'Charlie';
students(3).Age = 20;
students(3).Marks = [92, 95, 90, 94];
% Compute and display average grade for each student
disp('Average Grades:');
for i = 1:length(students)
   avgGrade = mean(students(i).Marks);
   disp([students(i).Name, ': ', num2str(avgGrade)]);
   students(i).Average = avgGrade; % Store the average grade in the structure
end
% Create a ranklist and store it in another structure
[~, sortedIndices] = sort([students.Average], 'descend'); % Sort by average grade
ranklist = struct();
for i = 1:length(students)
   ranklist(i).Name = students(sortedIndices(i)).Name;
   ranklist(i).Average = students(sortedIndices(i)).Average;
   ranklist(i).Rank = i;
end
% Display the ranklist
disp('Ranklist:');
for i = 1:length(ranklist)
   disp(['Rank ', num2str(ranklist(i).Rank), ': ', ranklist(i).Name, ' with Average ', num2str(ranklist(i).Average)]);
end
