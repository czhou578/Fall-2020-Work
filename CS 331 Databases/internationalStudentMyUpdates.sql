-- -----------------------------------------------------
-- CS 331 -Project Assignment Problem Description - Project 1
-- By: Colin Zhou , Ruiting Zhang , Samuel Faulkner
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema InternationalStudent
-- -----------------------------------------------------

CREATE SCHEMA IF NOT EXISTS InternationalStudent ;
USE InternationalStudent ;

-- -----------------------------------------------------
-- Table college
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS college (
  college_id INT NOT NULL,
  college_name VARCHAR(45) NULL,
  college_addr VARCHAR(45) NULL,
  dean_name VARCHAR(45) NULL,
  dean_addr VARCHAR(45) NULL,
  PRIMARY KEY (college_id));


-- -----------------------------------------------------
-- Table country
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS country ( -- data imported
  country_name VARCHAR(45) NOT NULL,
  language VARCHAR(45) NULL,
  capital VARCHAR(45) NULL,
  ethnicity VARCHAR(45) NULL,
  PRIMARY KEY (country_name));
  
  -- Insert into country(country_name, language, capital, ethnicity) values ("Japan", "Japanese", "Tokyo", "Japanese");
--   Insert into country(country_name, language, capital, ethnicity) values ("France", "French", "Paris", "French");
--   Insert into country(country_name, language, capital, ethnicity) values ("Germany", "German", "Berlin", "German");
--   Insert into country(country_name, language, capital, ethnicity) values ("Sweden" , "Swedish", "Stockholm", "Swedish");
--   Insert into country(country_name, language, capital, ethnicity) values ("England", "English", "London", "English");
--   Insert into country(country_name, language, capital, ethnicity) values ("Canada", "English", "Ottawa", "English");
--   Insert into country(country_name, language, capital, ethnicity) values ("China", "Chinese", "Beijing", "Chinese");
--   Insert into country(country_name, language, capital, ethnicity) values ("Thailand", "Thai", "Bangkok", "Thai");
--    


-- -----------------------------------------------------
-- Table department
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS department (
  department_id INT NOT NULL,
  department_name VARCHAR(45) NULL,
  department_addr VARCHAR(45) NULL,
  head_name VARCHAR(45) NULL,
  head_addr VARCHAR(45) NULL,
  college_id INT NOT NULL,
  PRIMARY KEY (department_id),
    FOREIGN KEY (college_id)
    REFERENCES college(college_id)
    ON DELETE cascade
    ON UPDATE cascade);



-- -----------------------------------------------------
-- Table course
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS course (
  course_id INT NOT NULL,
  course_name VARCHAR(45) NULL,
  credits INT NULL,
  department_id INT NOT NULL,
  PRIMARY KEY (course_id),
    FOREIGN KEY (department_id)
    REFERENCES department(department_id)
    ON DELETE cascade
    ON UPDATE cascade);


-- -----------------------------------------------------
-- Table degree
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS degree (
  degree_name VARCHAR(45) NOT NULL,
  description VARCHAR(45) NULL,
  department_id INT NOT NULL,
  PRIMARY KEY (degree_name),
    FOREIGN KEY (department_id)
    REFERENCES department(department_id)
    ON DELETE cascade
    ON UPDATE cascade);


-- -----------------------------------------------------
-- Table job
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS job (
  job_name VARCHAR(45) NOT NULL,
  job_type VARCHAR(45) NULL,
  job_hours INT NULL,
  employer_name VARCHAR(45) NULL,
  employer_addr VARCHAR(45) NULL,
  employer_phone VARCHAR(45) NULL,
  PRIMARY KEY (job_name));
  
-- -----------------------------------------------------
-- Table rules
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS rules ( -- data imported
  rules_id INT NOT NULL,
  rules_name VARCHAR(45) NULL,
  rules_description VARCHAR(45) NULL,
  PRIMARY KEY (rules_id));
  
--   Insert into rules(rules_id, rules_name, rules_description) values (1, "rule1", "desc1");
--   Insert into rules(rules_id, rules_name, rules_description) values (2, "rule2", "desc2");
--   Insert into rules(rules_id, rules_name, rules_description) values (3, "rule3", "desc3");
--   Insert into rules(rules_id, rules_name, rules_description) values (4, "rule4", "desc4");
--   Insert into rules(rules_id, rules_name, rules_description) values (5, "rule5", "desc5");
--   Insert into rules(rules_id, rules_name, rules_description) values (6, "rule6", "desc6");
--   Insert into rules(rules_id, rules_name, rules_description) values (7, "rule7", "desc7");
--   Insert into rules(rules_id, rules_name, rules_description) values (8, "rule8", "desc8");


-- -----------------------------------------------------
-- Table student
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS student ( -- data imported
  Ssn INT NOT NULL,
  first_name VARCHAR(45) NULL,
  last_name VARCHAR(45) NULL,
  birthdate DATE NULL,
  gender VARCHAR(45) NULL,
  addr VARCHAR(45) NULL,
  enroll_date DATE NULL,
  type VARCHAR(45) NULL,
  visa_type VARCHAR(45) NULL,
  PRIMARY KEY (Ssn));

-- -----------------------------------------------------
-- Table history
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS history ( -- data imported
  school_name VARCHAR(45) NOT NULL,
  degree VARCHAR(45) NULL,
  gpa DECIMAL(2,1) NULL,
  student_Ssn INT NOT NULL,
  PRIMARY KEY (school_name, student_Ssn),
    FOREIGN KEY (student_Ssn)
    REFERENCES student(Ssn)
    ON DELETE cascade
    ON UPDATE cascade);
    
-- insert into history values("a1", "degree", 4.0, 100000000);
-- insert into history values("a2", "degree2", 4.0, 100000001);
-- insert into history values("a3", "degree3", 4.0, 100000002);
-- insert into history values("a4", "degree4", 4.0, 100000003);
-- insert into history values("a5", "degree5", 4.0, 100000004);
-- insert into history values("a6", "degree6", 4.0, 100000005);
-- insert into history values("a7", "degree7", 4.0, 100000006);
-- insert into history values("a8", "degree8", 4.0, 100000007);


-- -----------------------------------------------------
-- Table rules_appy_student
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS rules_apply_student ( -- data imported
  rules_id INT NOT NULL,
  student_Ssn INT NOT NULL,
  PRIMARY KEY (rules_id, student_Ssn),
    FOREIGN KEY (rules_id)
    REFERENCES rules (rules_id)
    ON DELETE cascade
    ON UPDATE cascade,
    FOREIGN KEY (student_Ssn)
    REFERENCES student (Ssn)
    ON DELETE cascade
    ON UPDATE cascade);

-- insert into rules_apply_student values(1, 100000000);
-- insert into rules_apply_student values(2, 100000001);
-- insert into rules_apply_student values(3, 100000002);
-- insert into rules_apply_student values(4, 100000003);
-- insert into rules_apply_student values(5, 100000004);
-- insert into rules_apply_student values(6, 100000005);
-- insert into rules_apply_student values(7, 100000006);
-- insert into rules_apply_student values(8, 100000007);



-- -----------------------------------------------------
-- Table student_origin_country
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS student_origin_country ( -- data imported
  country_name VARCHAR(45) NOT NULL,
  student_Ssn INT NOT NULL,
  PRIMARY KEY (country_name, student_Ssn),
    FOREIGN KEY (country_name)
    REFERENCES country (country_name)
    ON DELETE cascade
    ON UPDATE cascade,
    FOREIGN KEY (student_Ssn)
    REFERENCES student (Ssn)
    ON DELETE cascade
    ON UPDATE cascade);
    
-- Insert into student_origin_country(country_name, student_SSN) values ("Japan", 100000000);
-- Insert into student_origin_country(country_name, student_SSN) values ("France", 100000001);
-- Insert into student_origin_country(country_name, student_SSN) values ("Germany", 100000002);
-- Insert into student_origin_country(country_name, student_SSN) values ("Sweden", 100000003);
-- Insert into student_origin_country(country_name, student_SSN) values ("England", 100000004);
-- Insert into student_origin_country(country_name, student_SSN) values ("China", 100000005);
-- Insert into student_origin_country(country_name, student_SSN) values ("Thailand", 100000006);

-- -----------------------------------------------------
-- Table degree_seeking_student
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS degree_seeking_student (
  degree_name VARCHAR(45) NOT NULL,
  student_Ssn INT NOT NULL,
  PRIMARY KEY (degree_name, student_Ssn),
    FOREIGN KEY (degree_name)
    REFERENCES degree (degree_name)
    ON DELETE cascade
    ON UPDATE cascade,
    FOREIGN KEY (student_Ssn)
    REFERENCES student (Ssn)
    ON DELETE cascade
    ON UPDATE cascade);


-- -----------------------------------------------------
-- Table student_belong_department
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS student_belong_department (
  student_Ssn INT NOT NULL,
  department_id INT NOT NULL,
  PRIMARY KEY (student_Ssn, department_id),
    FOREIGN KEY (student_Ssn)
    REFERENCES student (Ssn)
    ON DELETE cascade
    ON UPDATE cascade,
    FOREIGN KEY (department_id)
    REFERENCES department (department_id)
    ON DELETE cascade
    ON UPDATE cascade);


-- -----------------------------------------------------
-- Table employed_student
-- -----------------------------------------------------
    CREATE TABLE IF NOT EXISTS employed_student (
  student_Ssn INT NOT NULL,
  job_name VARCHAR(45) NOT NULL,
  PRIMARY KEY (student_Ssn, job_name),
    FOREIGN KEY (student_Ssn)
    REFERENCES student (Ssn)
    ON DELETE cascade
    ON UPDATE cascade,
    FOREIGN KEY (job_name)
    REFERENCES job (job_name)
    ON DELETE cascade
    ON UPDATE cascade);

-- -----------------------------------------------------
-- Table student_has_course
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS student_has_course(
  student_Ssn INT NOT NULL,
  course_course_id INT NOT NULL,
  course_quarter VARCHAR(45) NOT NULL,
  PRIMARY KEY (student_Ssn, course_course_id, course_quarter),
    FOREIGN KEY (student_Ssn)
    REFERENCES student (Ssn)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
    FOREIGN KEY (course_course_id)
    REFERENCES course (course_id)
    ON DELETE CASCADE
    ON UPDATE CASCADE);


-- -----------------------------------------------------
-- Drop Table and Schema script
-- -----------------------------------------------------

	-- drop table student_has_course;
-- 	drop table employed_student;
-- 	drop table student_belong_department;
-- 	drop table degree_seeking_student;
-- 	drop table student_origin_country;
-- 	drop table rules_apply_student;
-- 	drop table history;
-- 	drop table student;
-- 	drop table rules;
-- 	drop table job;
-- 	drop table degree;
-- 	drop table course;
--     drop table department;
--     drop table country;
--     drop table college;
--     drop schema InternationalStudent;