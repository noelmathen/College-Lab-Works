--SET C

--Q1(a)
create table library(bookid number, bookname varchar2(20), bookauthor varchar2(20), bookcount number, price number, edition number);
--INSERTING VALUES
insert into library values(1, 'Harry Potter', 'JK Rowling', 7, 550, 3);
insert into library values(2, 'Little Women', 'Louisa MA', 3, 350, 2);
insert into library values(3, 'Me before you', 'I forgot name', 1, 200, 4);
insert into library values(4, 'Crucifix Killer', 'Chris Carter', 2, 650, 1);
insert into library values(5, 'Shining', 'Stephen Hawking', 3, 200, 4);
insert into library values(6, 'Metamorphosis', 'Firstname Kafka', 2, 500, 1);

--Q1(b)
select bookname from library where bookname like 'S%' or bookname like 'M%';

--Q1(c)
create table bookborrow(borrowid number, studentid number, b_id number, dateofborrow date);

--Q2
create or replace trigger borrow
before 
insert on bookborrow
for each row
declare
	id library.bookid%TYPE := :new.b_id;
	bcount number;
begin
	select bookcount into bcount from library where bookid = id;
	if bcount<2 then
		raise_application_error(-20001, 'Not enough copies');
	else
		bcount := bcount-1;	
		update library set bookcount = bcount where bookid = id;
	end if;
end;
/

--CHECKING THE FUNCTIONALITY OF TRIGGER
insert into bookborrow values(1, 1, 1, '13-Feb-2023');
insert into bookborrow values(2, 2, 2, '14-Feb-2023');
insert into bookborrow values(3, 3, 3, '15-Feb-2023');

--Q3
create or replace procedure stock(bid IN number, bcount IN number)
is 
c number;
begin
	select bookcount into c from library where bookid = bid;
	c := c + bcount;
	update library set bookcount = c where bookid =bid;
end;
/
--CALLING THE PROCEDURE
declare
	id number;
	bcount number;
begin
	id := '&Bookid';
	bcount := '&Bookcount';
	stock(id, bcount);
end;
/

