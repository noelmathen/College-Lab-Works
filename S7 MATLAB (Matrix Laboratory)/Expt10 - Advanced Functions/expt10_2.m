% Part 2: Nested Functions for Rectangle Area and Perimeter Calculation
% Main function to compute the area and perimeter of a rectangle
rectangleCalculation();
% Main function definition
function rectangleCalculation
   % Prompt the user for the length and width of the rectangle
   length = input('Enter the length of the rectangle: ');
   width = input('Enter the width of the rectangle: ');
  
   % Compute the area using the nested function
   area = computeArea(length, width);
  
   % Compute the perimeter using the nested function
   perimeter = computePerimeter(length, width);
  
   % Display the results
   disp(['The area of the rectangle is: ', num2str(area)]);
   disp(['The perimeter of the rectangle is: ', num2str(perimeter)]);
  
   % Nested function to compute the area of the rectangle
   function a = computeArea(l, w)
       a = l * w;
   end
   % Nested function to compute the perimeter of the rectangle
   function p = computePerimeter(l, w)
       p = 2 * (l + w);
   end
end
