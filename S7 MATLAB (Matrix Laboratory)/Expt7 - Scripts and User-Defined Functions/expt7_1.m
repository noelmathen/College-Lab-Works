lowerBound = input('Enter the lower bound of the range: ');
upperBound = input('Enter the upper bound of the range: ');
primeNumbers = [];
for num = lowerBound:upperBound
   if isprime(num)
       primeNumbers = [primeNumbers num];
   end
end
fprintf('Prime numbers between %d and %d:\n', lowerBound, upperBound);
disp(primeNumbers);

