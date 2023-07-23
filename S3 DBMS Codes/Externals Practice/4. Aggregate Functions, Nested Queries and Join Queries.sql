select count(job) from employee;
select max(baldue) from client;
select max(salary) from 
select dno, min(salary) from employee group by dno having dno not like 'D001'; 

2.
a.
select (deptno) from dept union select (dno) from employee;

b.
select dno from employee where dno not in (select deptno from dept);

c.
select * from employee where salary > (select salary from employee where empname = 'Adarsh');

d.
select * from employee where salary < (select salary from employee where dno = 'D004');

e.
select empname, salary, job from employee where salary > (select min(salary) from employee) and job like 'A%';

f.
select empname, job, manager from employee left outer join Dept on employee.dno=dept.deptno;
select empname, job, manager from employee right outer join Dept on employee.dno=dept.deptno;
select empname, job, manager from employee full outer join Dept on employee.dno=dept.deptno;
