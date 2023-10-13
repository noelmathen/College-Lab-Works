

create table Employee(
		EmpId Varchar(5) primary key,
		EmpName Varchar(8),
		Job Varchar(10),
		Manager Varchar(5),
		HIRE_DATE date,
		salary number(6),
		comm number(5),
		DNO varchar(4));

	insert into Employee values('E0001', 'Abey', 'Tester', 'E0004','15-DEC-12',30000,525,'D001');
	insert into Employee values('E0002', 'Jesto', 'Analyst', 'E0001','24-MAR-11',10000,683,'D004');
	insert into Employee values('E0003', 'Adarsh', 'Clerk', 'E0004','10-JAN-13',15000,525,'D004');
	insert into Employee values('E0004', 'Kevin', 'Admin', 'E0005','14-MAY-11',51000,225,'D001');
	insert into Employee values('E0005', 'Bony', 'Manager', 'E0005','11-APR-11',49000,1050,'D001');
	insert into Employee values('E0006', 'Manu', 'Supplier', 'E0001',' 19-JUN-13',30000,473,'D002');

create table dept(
	     Deptno varchar(4),
	     Deptname varchar(4),
	     location varchar(9));
	
	insert into dept values('D001','DIT','A BLOCK');
	insert into dept values('D002','DCS','B BLOCK');
	insert into dept values('D003','DEC','C BLOCK');
	insert into dept values('D004','DEE','D BLOCK');

create table Client(
	     Cno varchar(6),
	     Name varchar(9),
	     City varchar(12),
	     Pincode number(7),
	     State varchar(13),
	     Baldue number(10));
	
	insert into Client values('C001','Riya','Kochi',680324,'Kerala',14000);
	insert into Client values('C002','Susan','Kochi',680324,'Kerala',0);
	insert into Client values('C003','Anita','Chennai',680345,'Tamil Nadu',5000);
	insert into Client values('C004','Kumar','Pune',680223,'Maharashtra',500);
	insert into Client values('C005','Anu','Nilampur',680321,'Kerala',7600);
	insert into Client values('C006','Vishnu','Bombay',682111,'Maharashtra',2055);

select count(baldue) from client;
select count(*) from employee;
select max(baldue), min(baldue) from client;
select avg(salary) from employee;
select name from client order by name;
select min(salary) from employee;

select dno, deptno from employee, dept where employee.dno=dept.deptno;
select distinct(dno) from employee union select distinct(deptno) from dept;
select dno from employee where dno not in(select deptno from dept);
select * from employee where salary > (select salary from employee where empname='Adarsh');
select * from employee where salary < (select salary from employee where dno='D002');
select empname, salary from employee where salary > (select min(salary) from employee) and job like 'A%';

select employee.empname,employee.job,employee.manager from employee left outer join dept on Employee.Dno=dept.DeptNo;

select employee.empname,employee.job,employee.manager from employee right outer join dept on Employee.Dno=dept.DeptNo;