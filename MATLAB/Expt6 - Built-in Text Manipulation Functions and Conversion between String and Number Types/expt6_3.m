inputStr = input('Enter a string: ', 's');
inputStr = lower(inputStr);
count_a = count(inputStr, 'a');
count_e = count(inputStr, 'e');
count_i = count(inputStr, 'i');
count_o = count(inputStr, 'o');
count_u = count(inputStr, 'u');
fprintf('Number of "a": %d\n', count_a);
fprintf('Number of "e": %d\n', count_e);
fprintf('Number of "i": %d\n', count_i);
fprintf('Number of "o": %d\n', count_o);
fprintf('Number of "u": %d\n', count_u);