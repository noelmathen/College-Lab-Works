a = input('Enter the first number: ');
b = input('Enter the second number: ');
c = input('Enter the third number: ');
if isPythagoreanTriplet(a,b,c)
   fprintf('The numbers (%d, %d, %d) form a Pythagorean triplet.\n', a,b,c);
else
   fprintf('The numbers (%d, %d, %d) do not form a Pythagorean triplet.\n', a,b,c);
end
function result = isPythagoreanTriplet(a, b, c)
   % Calculate squares of the numbers
   a_squared = a^2;
   b_squared = b^2;
   c_squared = c^2;
   % Check for Pythagorean condition
   result = (a_squared + b_squared == c_squared) || ...
            (a_squared + c_squared == b_squared) || ...
            (b_squared + c_squared == a_squared);
end