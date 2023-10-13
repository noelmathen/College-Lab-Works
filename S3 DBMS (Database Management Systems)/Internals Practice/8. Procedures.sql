create or replace PROCEDURE incrrement(id in varchar, sal_incr in number)
IS
BEGIN
    update EMPLOYEE set salary=salary+sal_incr where empid=id;
END;
/

DECLARE
    id varchar(5);
    sal_incr number;
BEGIN
    id:='&id';
    sal_incr:='&sal_incr';
    incrrement(id,sal_incr);
END;
/


create or replace PROCEDURE inc_comm(id IN varchar)
IS
BEGIN
    update employee set comm=comm+(comm*0.05) where empid=id;
END;
/
DECLARE
    emp_id varchar(6);
BEGIN
    emp_id:='&emp_id';
    inc_comm(emp_id);
END;
/



