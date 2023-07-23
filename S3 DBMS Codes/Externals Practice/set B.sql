--SET B

--Q1
create table movie(movie_id number, moviename varchar2(20), year number, language varchar2(20), rating number);

alter table movie add constraint c1 check(rating>=0);
insert into movie values(1, 'ABC', 2011, 'Hindi', 3);
--TO CHECK IF CHECK CONSTRAINT WORKS
insert into movie values(1, 'ABC', 2011, 'Hindi', -0.2);
insert into movie values(2, 'BCD', 2021, 'English', 4);
insert into movie values(3, 'MAL', 2019, 'Malayalam', 3.5);
insert into movie values(4, 'SHR', 2018, 'Malayalam', 2);
insert into movie values(5, 'BLR', 2017, 'Malayalam', 2.7);

--Q2
create or replace procedure five(id IN number, name IN varchar2, yr IN number, lang IN varchar2, rate IN number)
is
begin
	if rate>5 then
		insert into movie values(id, name, yr, lang, rate);
	else
		raise_application_error(-20001, 'Rating is less than 5. Cannot be inserted!');
	end if;
end;
/
declare
	id number;
	name varchar2(20);
	yr number;
	lang varchar2(20);
	rate number;
begin
	id := '&id';
	name := '&name';
	yr := '&yr';
	lang := '&lang';
	rate := '&rate';
	five(id, name, yr, lang, rate);
end;
/

--Q3
create or replace procedure delmal(rate IN number)
is
begin
	delete from movie where rating < rate and language = 'Malayalam';
end;
/
declare
	threshrate number;
begin
	threshrate := '&Threshholdrating';
	delmal(threshrate);
end;
/

