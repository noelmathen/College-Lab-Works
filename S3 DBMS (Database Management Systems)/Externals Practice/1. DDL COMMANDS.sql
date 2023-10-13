create table Students2(
    Id integer,
    Name varchar(10),
    Email varchar(20),
    Phoneno NUMBER,
    DOB DATE,
    Address VARCHAR(10),
    height FLOAT,
    deptno varchar(5)
);

create table Dept2(
    Deptno varchar(5),
    Deptname varchar(5),
    location varchar(10)
);

select * from Students2;
select * from Dept2;
desc students2;
desc dept2;

2.
alter table STUDENTS2 add date_of_joining date;

3.
alter table students2 add stipend number not null;

4.
alter table STUDENTS2 add check (stipend>0);

5.
alter table students2 add primary key(ID);

6.
alter table dept2 add unique (deptname);

7. 
alter table students2 add FOREIGN KEY(deptno) REFERENCES dept2(DEPTNO);

8.
alter table students2 drop column date_of_joining;
alter table students2 drop column address;

9.
alter table dept2 modify deptname varchar(10);

10.
alter table dept2 drop unique(deptname);

11.
alter table students2 rename column name to sname;
alter table students2 rename column sname to name;

13.
select 'Noel' as name, 18 as age from dual;

14.
select sysdate from dual;

15.
select 15+10-5*2/5 from dual;

16.
SELECT table_name FROM user_tables;



