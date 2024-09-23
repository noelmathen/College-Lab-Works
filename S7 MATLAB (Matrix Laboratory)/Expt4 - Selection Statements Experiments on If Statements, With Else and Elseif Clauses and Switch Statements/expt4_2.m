% 4_2 - Quadratic Equation Solver
canContinue = true;
while canContinue
    a = input("Enter coefficient of x^2: ");
    b = input("Enter coefficient of x: ");
    c = input("Enter constant value: ");
    
    if(a == 0)
        disp("The entered values do not form a quadratic equation!");
    else
        fprintf('The given quadratic equation is %dx^2 + %dx + %d\n', a, b, c);
        d = b^2 - 4*a*c;
        if d > 0
            root1 = (-b + sqrt(d)) / (2*a);
            root2 = (-b - sqrt(d)) / (2*a);
            fprintf('The roots are real and distinct: %.2f and %.2f\n', root1, root2);
        elseif d == 0
            root1 = -b / (2*a);
            fprintf('The root is real and equal: %.2f\n', root1);
        else
            realPart = -b / (2*a);
            imagPart = sqrt(-d) / (2*a);
            fprintf('The roots are imaginary: %.2f + %.2fi and %.2f - %.2fi\n', realPart, imagPart, realPart, imagPart);
        end
    end
    
    loop = input("Do you want to continue? (Y/N): ", "s");
    if(loop == "Y")
        canContinue = true;
    else
        canContinue = false;
    end
end
