alter table students modify ID varchar(6);
alter table STUDENTS modify DEPTNO varchar(4);
alter table students drop column stipend;
alter table students modify EMAIL varchar(30);

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

select * from students;
	

create table Dept(
    Deptno varchar(5),
    Deptname varchar(5),
    location varchar(10)
);

insert into dept values('D001','DIT','A BLOCK');
insert into dept values('D002','DCS','B BLOCK');
insert into dept values('D003','DEC','C BLOCK');
insert into dept values('D004','DEE','D BLOCK');

select * from dept;

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

select * from client;

insert into students values('S0007','Noel','U2007053@rajagiri.edu.in',9188022697,'14-May-2003','RSET-CSBS',181,'D002');
select * from client where Cno<='C004';
select name EMAIL, PHONENO from students;
select * from students where name like 'A%' or name like 'K%';
select distinct STATE from client;
select * from students where name BETWEEN 'E' and 'L';
update client set baldue=600 where name='Susan';
select * from dept where DEPTNO='D002' or DEPTNO='D004';
select * from client where state not like 'Kerala';
select count(*) from students S, dept D where S.DEPTNO=D.DEPTNO and D.DEPTNO='DEE'; 
select count(*) from students,dept where students.deptno = dept.Deptno and dept.Deptname='DEE';
select * from dept where DEPTNO not in (select DEPTNO from students);
select name, DEPTNAME from students, dept where students.deptno=dept.deptno and dob BETWEEN '20-Feb-2001' and '01-Jul-2003';
select * from students groupby name;



declare 
    cursor c_zip IS
        select * from employeee;
    item c_zip %rowtype;

BEGIN
    open c_zip;
    LOOP
        fetch c_zip into item;
        dbms_output.put_line('  '||item);
        exit when c_zip%Notfound;
    end loop;
end;
/

select * from employee;

DECLARE 
    CURSOR  c3(salr number) IS
    select empname, salary from employee where salary<salr;
    item c3%rowtype;

BEGIN
    open c3(31000);
    LOOP
        fetch c3 into item;
        exit when c3%notfound;
        dbms_output.put_line(item.empname|| '  '||item.salary);
    end loop;
    close c3;
end;
/

select * from client where cno >='C004';
select name, email, phoneno from students;
select name from students where name like 'A%' or name like 'K%';
select DISTINCT(deptname) from dept;
select name from students where name BETWEEN 'E' and 'L';
update client set city='Delhi' where cno = 'C003';
select name from students where deptno = 'D002' or deptno = 'D004';

select name from students where deptno = (select deptno from dept where deptname = 'DEE');
select count(*) from students, dept where students.deptno = dept.deptno and dept.deptname = 'DEE';




