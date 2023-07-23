create table students(
    ID varchar(5),
    Name varchar(9),
    email varchar(27),
    PhoneNo number(12),
    DOB date,
    Address varchar(10),
    Height_in_cm float(5),
    Deptno varchar(5)
);

insert into students values('S0001','Abey','U2007002@rajagiri.edu.in',9645765552,'15-Dec-2001','RSET-AID',160,'D004');
insert into students values('S0002','Jesto','U2007068@rajagiri.edu.in',9446907495,'24-Apr-2001','RSET-IT',165,'D002');
insert into students values('S0003','Adarsh','U2007003@rajagiri.edu.in',9446168018,'10-Jan-2003','RSET-AID',180,'D004');
insert into students values('S0004','Kevin','U2007004@rajagiri.edu.in',9048779636,'10-Oct-2002','RSET-IT',175,'D002');
insert into students values('S0005','Bony','U2007005@rajagiri.edu.in',8848647102,'11-Apr-2001','RSET-CSE',168,'D001');
insert into students values('S0006','Manu','U2007006@rajagiri.edu.in',9447026251,'19-Jun-2003','RSET-CSBS',190,'D002');


create table Dept(
    Deptno varchar(5),
    Deptname varchar(5),
    location varchar(10)
);

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
    Baldue number(10)
);

insert into Client values('C001','Riya','Kochi',680324,'Kerala',14000);
insert into Client values('C002','Susan','Kochi',680324,'Kerala',0);
insert into Client values('C003','Anita','Chennai',680345,'Tamil Nadu',5000);
insert into Client values('C004','Kumar','Pune',680223,'Maharashtra',500);
insert into Client values('C005','Anu','Nilampur',680321,'Kerala',7600);
insert into Client values('C006','Vishnu','Bombay',682111,'Maharashtra',2055);

select * from students;
select * from dept;
select * from client;


5.
insert into students values('S0007','Noel','U2007007@rajagiri.edu.in',9188022697,'14-Feb-2003','RSET-CSBS',300,'D001');

6.
select * from students where id<='S0004';

7.
select name, email, address from students;

8.
select * from students where name like 'K%' or name like 'A%';

9.
select distinct(deptname) from dept;

10.
select name from students where name between 'E' and 'L';

11.
update client set city='Delhi' where cno='C003';

12.
update client set baldue=600 where name = 'Susan';

13.
select id, name, deptno from students where deptno='D002' or deptno='D004' order by name asc, deptno asc;

15.
select * from client where state not like 'Kerala';

16.
select name from students, DEPT where students.DEPTNO=dept.DEPTNO and DEPTNAME='DEE';

17.
select deptno, deptname from dept where deptno not in(select deptno from students);

18.
select name, dob, deptname from students s, dept d where s.DEPTNO=d.DEPTNO and DOB between '20-Feb-2001' and '01-Jul-2003' order by dob asc;

