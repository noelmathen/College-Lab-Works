--1. consider louis is doing all this. He has 5 qstns:- 1.a(creating table), 1.b(query), 2.a(query), 2.b(procedure), 2.c(trigger)
--2. this is a simple method to help eo during exams

--create a table exam
create table exam(
	qnumber varchar(4),
	answers varchar(1000)
);  

alter table exam modify answers varchar(2000);  --to modify the character limit of the answers

grant SELECT on exam to u2109051; --this means louis is granting select access of his exam table to nihal. this could be dont to any uid number.

select * from u2109037.exam; --this is how nihal can access louis's exam table(nihal can only select it, not modify)

--now the next step is inserting qstn numbers and corresponding answers into the table.

--1.a is creating table. suppose if the actual code be:
create table students(
		ID number,
		name varchar(50),
		Email varchar(30),
		phoneno number,
		dob date,
		Address varchar(70),
		height float,
		deptno number);

--now before inserting into table, make this code into a single line, use a "--"(two hyphens to seperate the lines). Example:
create table students(--ID number,--name varchar(50),--Email varchar(30),--phoneno number,--dob date,--Address varchar(70),--height float,--deptno number);

--nos this is in a single line. now copy paste this into the insert query



1. insert into exam values('1.a','create table students(--ID number,--name varchar(50),--Email varchar(30),--phoneno number,--dob date,--Address varchar(70),--height float,--deptno number);'); -- here, the first parameter is qstn number, 2nd parameter is the table creeation made into single line
--now after nihal select * from louis's table, he will get to see this. nihall can copy paste the code into notepad and make it into multiple lines using the -- as REFERENCE

2. insert into exam values('1.b','select * from students where Deptno=002 or Deptno=004;');  --example query. the first parameter is the qstn number, the 2nd parameter is the answer(here, the query)

3. insert into exam values('2.a','select trunc(months_between(sysdate,to_date(HIRE_DATE))) as HIRE_DATE from employee;');

--let this be the original procedure:
	CREATE OR REPLACE PROCEDURE salincrement(id IN varchar2, sal_incr IN number)
	IS
	BEGIN
		update EMPLOYEE set salary=salary+sal_incr where empid=id;
	END;
	/

	DECLARE
		id varchar2(6);
		sal_incr number(5);
	BEGIN
  		id:='&Empid';
		sal_incr:='&Increment';
		salincrement(id, sal_incr);
	END;
	/

--convert it into single line using --
--CREATE OR REPLACE PROCEDURE salincrement(id IN varchar2, sal_incr IN number)--IS--BEGIN--	update EMPLOYEE set salary=salary+sal_incr where empid=id;--END;--/--DECLARE--	id varchar2(6);--	sal_incr number(5);--BEGIN--	id:='&Empid';--	sal_incr:='&Increment';--	salincrement(id, sal_incr);--END;--/
--now copy paste into insertion
4. insert into exam values('2.b','--CREATE OR REPLACE PROCEDURE salincrement(id IN varchar2, sal_incr IN number)--IS--BEGIN--	update EMPLOYEE set salary=salary+sal_incr where empid=id;--END;--/--DECLARE--	id varchar2(6);--	sal_incr number(5);--BEGIN--	id:='&Empid';--	sal_incr:='&Increment';--	salincrement(id, sal_incr);--END;--/');


5. insert into exam values('2.c','--create or replace trigger emp_op -- AFTER INSERT OR DELETE or UPDATE on employeee-- for each ROW-- DECLARE-- BEGIN--IF INSERTING THEN--insert into nemployeee values(:new.id, :new.name, :new.salary);--ELSIF DELETING THEN--insert into xemployeee values(:new.id, :new.name, :new.salary);--ELSIF UPDATING THEN--insert into cemployeee values(:new.id, :new.name, :new.salary);--END IF;--END;--/');


select * from exam; --nihal can see all the answers from louis's exam TABLE

U MAY THINK THIS IS COMPLICATED BUT IT IS VERY EASY.
