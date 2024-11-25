a = input('Enter first element: ');
b = input('Enter first element: ');
c = input('Enter first element: ');
d = input('Enter first element: ');

A = [a b ; c d];

function result = findDet(A)
    result = (A(1, 1)*A(2, 2)) - (A(1, 2)*A(2, 1));
end

handle = @findDet
detA = handle(A);


if detA ~= 0
    invA = inv(A);
else
    disp('Matrix is singular, inverse doesnt exist');
end

newA = A;

for i=1:2
    for j=1:2
        if(A(i, j) > 10)
            newA(i, j) = 10;
        end
    end
end

CA = {A, detA, invA, newA}; 

%disp(CA{1, 1});
%disp(CA{1, 2});
%disp(CA{1, 3});
%disp(CA{1, 4});

celldisp(CA);