% 5_1 Sum of the First n Numbers
n = input("Enter number: ");
sum = 0;
for i = 1:n
    sum = sum + i;
end
fprintf('Sum of the first %d numbers is %d\n', n, sum);
