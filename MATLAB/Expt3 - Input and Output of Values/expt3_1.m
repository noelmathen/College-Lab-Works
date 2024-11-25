% 3_1 - Basic Arithmetic Operations On Two Numbers And Manipulates Strings
format compact
num1 = input('Enter first number: ');
num2 = input('Enter the second number: ');

sum = num1 + num2;
diff = num2 - num1;
prod = num1 * num2;
quot = num2 / num1;

fprintf('Sum: %f\nDifference: %f\nProduct: %f\nQuotient: %f\n', sum, diff, prod, quot);

str1 = input('Enter string 1: ', 's');
str2 = input('Enter string 2: ', 's');

concat = strcat(str1, str2);
compare = strcmp(str1, str2);
substr = extractBetween(concat, 'l', 'r');
substra = extractAfter(concat, 'o');
substrb = extractBefore(concat, 'w');
ustr = upper(concat);
lstr = lower(ustr);
padded = pad(concat, 20);
trimmed = strtrim(padded);

fprintf('Concatenated string: "%s"\nString comparison: %s\nSubstring: %s\nSubstring after: %s\nSubstring before: %s\nUppercase: %s\nLowercase: %s\n', ...
    concat, mat2str(compare), substr{1}, substra, substrb, ustr, lstr);

fprintf('Size of padded string: %d\nSize of trimmed string: %d\n', strlength(padded), strlength(trimmed));
