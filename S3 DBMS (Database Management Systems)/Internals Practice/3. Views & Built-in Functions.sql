create table Employee(
		EmpId Varchar(20) primary key,
		EmpName Varchar(20),
		Job Varchar(15),
		Manager Varchar(20));

	insert into Employee values('E0001', 'Abey', 'Tester', 'E0004');
	insert into Employee values('E0002', 'Jesto', 'Analyst', 'E0001');
	insert into Employee values('E0003', 'Adarsh', 'Clerk', 'E0004');
	insert into Employee values('E0004', 'Kevin', 'Admin', 'E0005');
	insert into Employee values('E0005', 'Bony', 'Manager', 'E0005');
	insert into Employee values('E0006', 'Manu', 'Supplier', 'E0001');

create view CUST_VW as select * from employee; 

select power(16,5) from DUAL;
select length('application') from dual;
select sysdate, last_day(sysdate) as last_day_curr_month from dual;
select last_day(SYSDATE) as last_day_curr_month from dual;
select to_char(65432,'$99999') from dual;
select systimestamp from dual;
alter table employee add HIRE_DATE date; 
insert into employee values('E0007', 'Manu', 'Supplier', 'E0001','19-JUN-13');

