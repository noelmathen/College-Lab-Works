declare 
    obj EMPLOYEEE%ROWTYPE;
    cursor c1 IS select * from employeee;
/

begin
    open c1;
    LOOP
        fetch c1 into obj;
        dbms_output.put_line(obj.id||', '||obj.name||', '||obj.salary);
        exit when c1%notfound;
     end loop;
end;
/   

declare cursor c2 IS
    select fname, lname from person where pid>50;
    obj %rowtype;
/

BEGIN
    for obj in c2 LOOP
        dbms_output.put_line(obj.fname||'  '||obj.lname);
    end loop;
end;
/

    