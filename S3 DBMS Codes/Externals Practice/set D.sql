
create table dept3(
    deptno number primary key, 
    dname varchar2(20), 
    depthead varchar2(20)
);

create table project(
    pno number, 
    pname varchar2(20), 
    deptno number, 
    foreign key(deptno) references dept3(deptno)
);

insert into dept3 values(1, 'IT', 'John');
insert into dept3 values(2, 'CS', 'James');
insert into dept3 values(3, 'EC', 'John');
insert into dept3 values(4, 'HR', 'John');
insert into dept3 values(5, 'RD', 'Shruti');

insert into project values(1, 'Recruitment', 2);
insert into project values(2, 'Management', 1);

insert into empp values(1, 'Smith', 'Clerk', 'Mumbai', 20000, 123456, 3, 2);
insert into empp values(2, 'Harry', 'Tester', 'Delhi', 50000, 123458, 1, 1);
insert into empp values(3, 'Shruti', 'Manager', 'Delhi', 80000, 123459, 4, 1);
insert into empp values(4, 'Noel', 'Asst Manager', 'Kerala', 70000, 12345678, 4, 1);
insert into empp values(5, 'Roshni', 'Clerk', 'Hyderabad', 5000, 12345, 5, 2);

select * from dept3;
select * from project;
select * from empp;

--DO NOT NAME A DEPARTMENT LIKE R&D BECUASE THAT ACTS AS A POINTER R TO D. INSTEAD USE RD

--Q1(a)
select ename from emp, project, dept3 where (emp.dno=dept3.deptno and dept3.dname='HR') and (emp.pno=project.pno and project.pname='Recruitment');

--Q1(b)
select ename from emp where sal IN (select max(sal) from emp where dno IN(select deptno from dept3 where dname = 'HR'));

--Q1(c)
select ename from emp, dept3 where emp.dno = dept3.deptno and dept3.depthead = 'John';

--Q1(d)
declare
	hr number;
	rd number;
	hno number;
	rno number;
begin
	--Only updates value of 1 employee. So in your table just add 1 employee each who's department is HR and RD
	select MAX(sal), dno into hr, hno from emp, dept3 where dept3.deptno=emp.dno and dept3.dname='HR' group by dno;
	select MAX(sal), dno into rd, rno from emp, dept3 where dept3.deptno=emp.dno and dept3.dname='RD' group by dno;
	hr := 0.2*(hr) + hr;
	rd := 0.3*(rd) + rd;
	update emp set sal=hr where dno = hno;
	update emp set sal=rd where dno = rno;
	dbms_output.put_line('HR Department salary: '||hr);
	dbms_output.put_line('RD Department salary: '||rd);
end;
/

--Q1(e)
declare
	hno number;
	e emp.ename%type; 
	--In PL/SQL, when you execute a SELECT statement that returns one or more rows, you need to specify an INTO clause to store the result of the query into variables.
begin
	select deptno into hno from dept3 where dname = 'HR';
	select ename into e from emp where ename like 'S%' and dno = hno;
	dbms_output.put_line('Required employee: '||e);
end;
/



