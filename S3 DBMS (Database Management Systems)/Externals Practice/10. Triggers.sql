CREATE OR REPLACE TRIGGER TRANS 
AFTER INSERT OR UPDATE OR DELETE ON employeee
FOR EACH ROW
BEGIN
    IF INSERTING THEN
        insert into nemployeee values(:new.id, :new.name, :new.salary);
    ELSIF UPDATING THEN
        insert into cemployeee values(:new.id, :new.name, :new.salary);
    ELSIF deleting THEN
        insert into xemployeee values(:new.id, :new.name, :new.salary);
    END IF;
END;
/


select * from employeee;
select * from xemployeee;
select * from nemployeee;
select * from cemployeee;


insert into employeee values(4,'Alwin Joseph',13000);
update employeee set salary=13000 where id=1;
alter table employeee modify id number(3);              
delete from employeee where id=4;

