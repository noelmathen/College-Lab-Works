--1. Write a PL/SQL block to calculate gross salary on the 
    --basis of basic salary if DA is 40% of basic, HRA is 
    --20% of basic and PF deduction is 12% of basic salary.



--2. Write a PL/SQ block to calculate the sum of 
    --digits of a number entered through keyboard.

    DECLARE
        num number;
        sum number := 0;
        d number;
    BEGIN
        dbms_output.put_line('Enter a number: ');
        num:='&num';
        WHILE num<>0 LOOP
            d:=mod(num,10);
            dbms_output.put_line(d);
        end loop;
        DBMS_OUTPUT.PUT_LINE('the sum is: '||sum);
    END;
    /

    DECLARE
  num NUMBER;
  temp NUMBER := 0;
  d NUMBER;
BEGIN
  DBMS_OUTPUT.PUT_LINE('Enter a number: ');
  num:='&n';
  WHILE num<>0 LOOP
    d := MOD(num, 10);
    temp := temp + d;
    num := TRUNC(num / 10);
  END LOOP;
  DBMS_OUTPUT.PUT_LINE('The sum is: ' || temp);
END;
/


--3. Write  a PL/SQL block. Take the salary of an employee 
    --into a variable and check if his or her salary is less 
    --than 3000 then update the salary with 4000 .

DECLARE
    salary number;
BEGIN
    salary:='&salary';
    if salary  <3000 THEN
        DBMS_OUTPUT.PUT_LINE('The salary is less than 3000');
    end IF;
    salary := salary + 4000;
    DBMS_OUTPUT.PUT_LINE('The updated salary is: '|| salary);
END;
/


--4. Write a pl/sql program to check whether a given 3-digit 
    --number is Armstrong or not.
--5. Write a PL/SQL code block to find factorial of a number.
--6. Write a pl/sql program to display the reverse of a string.
    DECLARE
        strn varchar(100);
        revstrn varchar(100);
        lenstr varchar(100);
    BEGIN
        strn:='&strn';
        lenstr:=length(strn);
        for i in reverse 1..lenstr LOOP
            revstrn:=revstrn||substr(strn,i,1);
        end loop;
        dbms_output.put_line('The reversed string is: '||revstrn);
    END;
    /




--7. Write a pl/sql program to check whether a given number is palindrome or not.
--8. Create a sequence starting with 10 to 50 displaying the 
    --even numbers only. Insert the sequence into an empty
    --table named “EvenNo”.
    create table EvenNo(evenum number(38));

    DECLARE
        
    BEGIN
        for i in 10..50 LOOP
            if mod(i,2)=0 THEN
                insert into EvenNo values(i);
            end if;
        end loop;
    END;
    /

update EvenNo column set evennum number(50);
--9. Write a pl/sql block to accept the marks for three subjects from a student and classify according to the grade and insert into tables named gradea, gradeb and gradec.
    --(Hint: the student table contains rollno, name, m1, m2,m3 and tot_marks. If the total marks >75% insert into gradea table, between 60 and 75% insert into gradeb table and <60% gradec table. Grade table has the following fields : rollno, name, %marks)

