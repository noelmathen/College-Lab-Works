create table employeee(id number primary key,
                        name varchar(20),
                        salary number);

create table xemployeee(id number primary key,
                        name varchar(20),
                        salary number);

create table nemployeee(id number primary key,
                        name varchar(20),
                        salary number);

create table cemployeee(id number primary key,
                        name varchar(20),
                        salary number);

insert into employeee values(1,'Noel Mathen',5000);
insert into employeee values(2,'Allen Prince',10000);
insert into employeee values(3,'Shruti Shibu',15000);

create or replace trigger emp_op
AFTER INSERT OR DELETE or UPDATE on employeee
for each ROW
DECLARE
BEGIN
    IF INSERTING THEN
        insert into nemployeee values(:new.id, :new.name, :new.salary);
    ELSIF DELETING THEN
        insert into xemployeee values(:new.id, :new.name, :new.salary);
    ELSIF UPDATING THEN
        insert into cemployeee values(:new.id, :new.name, :new.salary);
    END IF;
END;
/

select * from employeee;
select * from xemployeee;
select * from nemployeee;
select * from cemployeee;

insert into employeee values(4,'Alwin Joseph',13000);
update employeee set salary=12000 where id=1;
alter table employeee modify id number(3);
