CREATE TABLE  if not exists department (
  dname        varchar(25) not null,
  dnumber      int,
  mgrssn       char(9) not null, 
  mgrstartdate date,
  primary key (dnumber),
  key (dname)
);

CREATE TABLE  if not exists dept_locations (
  dnumber   int,
  dlocation varchar(15), 
  -- note how the composite primary key ois defined using SQL DDL
  primary key (dnumber,dlocation),
  foreign key (dnumber) references department(dnumber) on delete cascade
);

CREATE TABLE  if not exists project (
  pname      varchar(25) not null,
  pnumber    int,
  plocation  varchar(15),
  dnum       int not null,
  primary key (pnumber),
  unique (pname),
  foreign key (dnum) references department(dnumber) on delete cascade
);


CREATE TABLE  if not exists employee (
  fname    varchar(15) not null, 
  minit    varchar(1),
  lname    varchar(15) not null,
  ssn      char(9),
  bdate    date,
  address  varchar(50),
  sex      char,
  salary   decimal(10,2),
  superssn char(9),
  dno      int,
  primary key (ssn),
  foreign key (dno) references department(dnumber) on delete cascade
);
-- Alter the employee table to add superssn foreign key after table creation

alter table employee  Add foreign key (superssn) references employee(ssn) on delete cascade;

CREATE TABLE  if not exists dependent (
  essn           char(9),
  dependent_name varchar(15),
  sex            char,
  bdate          date,
  relationship   varchar(8),
  primary key (essn,dependent_name),
  foreign key (essn) references employee(ssn) on delete cascade
);

CREATE TABLE  if not exists works_on (
  essn   char(9),
  pno    int,
  hours  decimal(4,1),
  primary key (essn,pno),
  foreign key (essn) references employee(ssn) on delete cascade,
  foreign key (pno) references project(pnumber) on delete cascade
);

-- This is a single line comment: Don't Run the drop section of the script except unless you need to drop the tables
/*This a multi line comment
The drop sttatement has to be done in this order as well becaus of constriants*/

/*DROP TABLE works_on;
DROP TABLE dependent;
DROP TABLE employee;
DROP TABLE project;
DROP TABLE dept_locations;
DROP TABLE department;*/