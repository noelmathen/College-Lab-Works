create table students(
    Id INTEGER,
    Name varchar(10),
    Email varchar(20),
    Phoneno NUMBER,
    DOB DATE,
    Address VARCHAR(10),
    height FLOAT,
    deptno NUMBER
);


create table Deppt(
    Deptno varchar(5),
    Deptname varchar(5),
    location varchar(10)
);

select * from DEPTT;
select * from STUDENTS;

alter table STUDENTS add date_of_joining DATE;
alter table students add stipend NUMBER NOT NULL;
alter table students add check (stipend>0);
alter table STUDENTS modify Id primary key;
alter table DEPTT add UNIQUE(DEPTNAME);
alter table DEPTT modify DEPTNO PRIMARY KEY;
alter table STUDENTS add FOREIGN KEY(DEPTNO) references Deptt(DEPTNO);
alter table STUDENTS drop column date_of_joining;
alter table deptt modify DEPTNAME varchar(10);
alter table DEPTT drop UNIQUE(DEPTNAME);
alter table STUDENTS rename column name to SName;
rename studentss to STUDENTSSS;
select 'Noel' as name from DUAL;
select 18 as age from DUAL;
select (1*2+3) from dual;
select systime from dual;

select * from studentsss;