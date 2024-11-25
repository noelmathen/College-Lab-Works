% 5_2 Factorial Calculation
n = input("Enter number: ");
factorial = 1;
if(n == 1 || n == 0)
    factorial = 1;
else
    for i = 1:n
        factorial = factorial * i;
    end
end
fprintf('Factorial of %d is %d\n', n, factorial);
