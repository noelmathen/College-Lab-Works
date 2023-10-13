CREATE or REPLACE FUNCTION find_mgr_name(id IN varchar)
    return VARCHAR
    IS
    mgrname varchar(10);
    BEGIN
        select empname into mgrname from employee where empid in (select manager from employee where empid=id);
        return mgrname;
    END;
    /

DECLARE
    id varchar(6);
    mgrname varchar(10);
BEGIN
    id:='&id';
    mgrname:=find_mgr_name(id);
    dbms_output.put_line('The manager name of employee '||id||' is: '||mgrname);
END;
/

