create or replace procedure incr(id in varchar, num in number)
IS
    sal number;
BEGIN
    select salary into sal from employee where empid = id;
    dbms_output.put_line('The old salary is: '||sal);
    UPDATE employee set salary = salary + num where empid = id;
    select salary into sal from employee where empid = id;
    dbms_output.put_line('The new salary is: '||sal);
END;
/

DECLARE
    n number;
    id varchar(6);
BEGIN
    n:='&n';
    id:='&id';
    incr(id,n);
END;
/

CREATE OR REPLACE PROCEDURE inc_comm()
IS
BEGIN

END;
/

DECLARE

BEGIN

END;
/

create table bank(
		username varchar2(12), 
		accid number(4), 
		balance number(6,2));

	insert into bank values('Shruti', 1234, 2000.5);
	insert into bank values('Minal', 1235, 1590.7);
	insert into bank values('Nirupama', 1236, 2908.5);
	insert into bank values('Roshni', 1238, 2560.4);
	insert into bank values('Noel', 1239, 1245.2);


CREATE OR REPLACE PROCEDURE withdraw(wamt IN number, id IN number)
	IS
        bal number;
        balamt number;
	BEGIN
		select balance into balamt from bank where id=accid;
		bal:=balamt-wamt;
		if(bal<1000) then
		  dbms_output.put_line('LOW BALANCE!!');
		else
		  update bank set balance=bal where id=accid;
		  dbms_output.put_line('Money withdrawn! Balance: '|| bal);
		end if;
	END;
	/


	DECLARE
		id number(4);
		wamt number(6,2);
		balamt number(6,2);
		bal number(6,2);

	BEGIN
		id:='&id';
		wamt:='&wamt';
		withdraw(wamt, id);
	END;
	/

CREATE or replace PROCEDURE AVEG
IS
avgg number;
BEGIN
    select avg(marks) into avgg from student;
    dbms_output.put_line(avgg);
END;
/



BEGIN
    aveg;
END;
/



