select
fname
from
dept, employee
where
dnum = dno and dname = "software";

select 
fname
from
employee join dept on dnum = dno
wheresuppliersuppliersupplier
dname = "software";

select e.fname, e.lname, g.fname, g.lname
from 
employee as e, manager as g
where e.ssn = g. ssn;

select e.fname as employee, g.fname as manager
from
(employee as e
	left outer join manager as g on e.ssn = g.ssn)
    where g.ssn is not null;
    
select fname, lname 
from employee
where superssn = null;

select middleName
from table2
where dno = 9;

select *
from table1 join table2
where table1.name = table2.name;

select fname, lname
from table1
where dno = 5;

