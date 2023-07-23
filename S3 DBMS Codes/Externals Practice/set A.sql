--SET A

--Q1
create table employee(emp_no number, emp_name varchar2(20), DOB date, address varchar2(20), DOJ date, mobile_no number, salary number);

--Q1(a)
alter table employee add deptname number;
--INSERTING VALUES INTO TABLE
insert into employee values(1, 'Shruti', '23-Jun-2002', 'Delhi', '12-Dec-2021', 6981629772, 200000, 2);
insert into employee values(2, 'Celina', '05-Dec-2002', 'Hyderabad', '13-Jan-2022', 68790968, 100000, 1);
insert into employee values(3, 'Roshni', '17-Sep-2003', 'Bangalore', '15-Jan-2022', 98767564, 150000, 2);
insert into employee values(4, 'Noel', '14-May-2003', 'Kerala', '28-Dec-2021', 9876542, 250000, 3);
insert into employee values(5, 'Stesha', '16-Jun-2003', 'Bangalore', '13-Jan-2022', 8765424, 150000, 1);

--Q1(b)
select emp_name from employee where emp_name like 'S%' or emp_name like 'R%';

--Q2(a)
create trigger salcheck
before 
update on employee
for each row
declare
	sal employee.salary%TYPE := :new.salary;
begin
	if sal>300000 then
		raise_application_error(-20001,'Salary cannot be greater than 300000');
	end if;
end;
/



--TRYING DIFFERENT EXAMPLES TO CHECK THE TRIGGER FUNCTIONALITY
update employee set salary = 350000 where emp_no=1;
update employee set salary = 150000 where emp_no=2;

--Q2(b)
create or replace procedure avgsal(deptno IN number)
is
a number;
c number;
begin
	select count(*), avg(salary) into c,a from employee where deptname = deptno;
	dbms_output.put_line('Total employees: '||c);
	dbms_output.put_line('Average Department Salary: '||a);
end;
/
--CALLING A PROCEDURE
declare
	dno number;
begin
	dno := '&Departmentno';
	avgsal(dno);
end;
/
