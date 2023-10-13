DECLARE
    a number;
    b number;
    c number;
BEGIN
    a := '&a';
    b := '&b';
    c := a + b;
    dbms_output.put_line('The sum is: '||c);
END;
/


DECLARE
    num number;
    d number;
    s number := 0;
BEGIN
    num := '&num';
    WHILE num > 0 
    LOOP
        d := mod(num,10);
        s := s + d;
        num := trunc(num/10);
    END LOOP;
    dbms_output.put_line('sum of digits of '||num||' is: '||s);
END;
/


DECLARE
BEGIN
    for i in 10..50
    LOOP
        if mod(i,2)=0 THEN
            dbms_output.put_line(i);
            insert into EvenNo values(i);
        end if;
    end loop;
END;
/

