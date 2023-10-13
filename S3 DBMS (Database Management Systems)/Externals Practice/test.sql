create table movie(
    movie_id number,
    movie_name varchar(10),
    year number(4),
    language varchar(10),
    rating number
);

insert into movie values(1, 'ABC', 2011, 'Hindi', -0.2);
insert into movie values(2, 'BCD', 2021, 'English', 4);
insert into movie values(3, 'MAL', 2019, 'Malayalam', 3.5);
insert into movie values(4, 'SHR', 2018, 'Malayalam', 2);
insert into movie values(5, 'BLR', 2017, 'Malayalam', 2.7);

alter table movie add constraint c1 check (rating>0);

update movie set rating = 4.3 where movie_id=1;



create or replace procedure insertmovie(id in number, name in varchar, yr in number, lang in varchar, rate in number)
IS
BEGIN
    if(rate>5) then
        insert into movie values(id, name, yr, lang, rate);
    else
        raise_application_error(-20001,'The rating should be greater than 5!');
    end if;
END;
/

DECLARE
    id number;
    name varchar(10);
    year number;
    language varchar(10);
    rating number;
BEGIN
    id:='&id';
    name:='&name';
    year:='&year';
    language:='&language';
    rating:='&rating';
    insertmovie(id, name, year, language, rating);
END;
/

--*******************************************************************************************************************

create table library(
    bookid number, 
    bookname varchar2(20), 
    bookauthor varchar2(20), 
    bookcount number, 
    price number, 
    edition number
);

insert into library values(1, 'Harry Potter', 'JK Rowling', 7, 550, 3);
insert into library values(2, 'Little Women', 'Louisa MA', 3, 350, 2);
insert into library values(3, 'Me before you', 'I forgot name', 1, 200, 4);
insert into library values(4, 'Crucifix Killer', 'Chris Carter', 2, 650, 1);
insert into library values(5, 'Shining', 'Stephen Hawking', 3, 200, 4);
insert into library values(6, 'Metamorphosis', 'Firstname Kafka', 2, 500, 1);

create table bookborrow(
    borrowid number, 
    studentid number, 
    b_id number, 
    dateofborrow date
);

select bookname from library where bookname like 'S%' or bookname like 'M%' order by bookname asc;


create or replace trigger decc
before 
INSERT on bookborrow
for EACH ROW
DECLARE
    id library.bookid%TYPE := :new.b_id;
    bcount number;
    bookcount number;
BEGIN
    select bookcount into bcount from library where bookid = id;
    if bcount<2 THEN
        raise_application_error(-20001,'no minimnum no of copies........');
    ELSE
        bcount := bcount - 1;
        update library set bookcount = bcount where bookid = id;
    end if;
END;
/


--********************************************************

create table empp(
    eno number primary key, 
    ename varchar2(20), 
    designation varchar2(20), 
    address varchar2(20), 
    sal number, 
    phno number, 
    dno number, 
    pno number
);

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


