% 4_3 - Circle Operations
canContinue = true;
while canContinue
    r = input('Enter radius of circle: ');
    disp('Operation:');
    disp('1. Perimeter of circle');
    disp('2. Area of circle');
    
    choice = input('Enter your choice of operation: ');
    switch choice
        case 1
            p = 2 * pi * r;
            fprintf('Perimeter of the circle is: %.2f\n', p);
        case 2
            A = pi * r^2;
            fprintf('Area of the circle is: %.2f\n', A);
        otherwise
            fprintf('Invalid choice. Please enter 1 or 2.\n');
    end
    
    loop = input('Do you want to continue? (Y/N): ', 's');
    if strcmpi(loop, 'Y')
        canContinue = true;
    else
        canContinue = false;
    end
end
