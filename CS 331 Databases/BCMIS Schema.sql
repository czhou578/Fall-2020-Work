Create Table if not exists BellevueCollegeAlumni
(
FormerBCID int unsigned unique not null,
AlumniEmailAddress varchar(45) unique not null,
primary key(FormerBCID, AlumniEmailAddress),
FirstName varchar(45) not null,
LastName varchar(45) not null,
HomeAddresStudents varchar(45),
HomeCity varchar(30),
HomeState varchar(35),
HomeZIP int,
PhoneNum int
) ENGINE=InnoDB character set utf8mb4
collate utf8mb4_unicode_520_ci;

Create Table if not exists FacultyAdvisor
(
CollegeID int not null,
FacultyAdvisorEmailAddress varchar(45) not null, 
primary key(CollegeID, FacultyAdvisorEmailAddress),
FirstName varchar(30) not null,
SecondName varchar(30) not null,
Department varchar(45),
OfficeBuildingName varchar(45),
OfficeRmNum int,
OfficePhoneNum int,
AssignmentMentorStart int,
AssignmentMentorEnd int,
BCAlumniFormerBCID int unsigned unique not null,
BCAlumniEmailAddress varchar(45) unique not null,
constraint BCAlumniFK foreign key (BCAlumniFormerBCID, BCAlumniEmailAddress) references BellevueCollegeAlumni (FormerBCID, AlumniEmailAddress)
on delete cascade -- This should be delete cascade because if faculty advisor is not a BC alumni, there is no need to keep their old records
on update no action -- highly unlikely that former records will be updated, so this is not necessary to cascade
) ENGINE=InnoDB character set utf8mb4
collate utf8mb4_unicode_520_ci;

Create Table if not exists Mentor
(
MentorEmailAddress varchar(45) not null primary key,
FirstName varchar(45) not null,
SecondName varchar(45) not null,
CompanyName varchar(45),
CompanyAddress varchar(45),
CompanyCity varchar(45),
CompanyState varchar(35),
CompanyZIP int,
CompanyPhoneNum int,
FacultyAdvisorCollegeID int,
FacultyAdvisorEmailAddress varchar(45),
OldBCID int unsigned unique not null,
AlumniEmailAddress varchar(45) unique not null,
AssignmentStudentStart int,
AssignmentStudentEnd int,
constraint BCAlumniFK foreign key (OldBCID, AlumniEmailAddress) references BellevueCollegeAlumni (FormerBCID, AlumniEmailAddress)
on delete cascade -- This should be delete cascade because if faculty advisor is not a BC alumni, there is no need to keep their old records
on update no action, -- highly unlikely that former records will be updated, so this is not necessary to cascade
constraint FacultyAdvisorFK foreign key (FacultyAdvisorCollegeID, FacultyAdvisorEmailAddress) references FacultyAdvisor(CollegeID, FacultyAdvisorEmailAddress)
on delete cascade on update cascade -- The mentor and faculty are closely connected through working relationship, so records need to be updated
) ENGINE=InnoDB character set utf8mb4
collate utf8mb4_unicode_520_ci;

Create Table if not exists Student
(
CollegeID int not null,
EmailAddress varchar(45) not null,
primary key(CollegeID, EmailAddress),
FirstName varchar(45) not null,
SecondName varchar(45) not null,
DormName varchar(45),
DormRoomNum int,
DormPhoneNum int,
OffCampusAddr varchar(45),
StudentDateEnrolled int,
StudentDateGraduated int,
StudentDegree varchar(45),
FacultyAdvisor_CollegeID int not null,
FacultyAdvisor_EmailAddress varchar(45) not null,
constraint FacultyAdvisorFK foreign key (FacultyAdvisor_CollegeID, FacultyAdvisor_EmailAddress) references FacultyAdvisor(CollegeID, FacultyAdvisorEmailAddress)
on delete cascade on update cascade, -- The Student and faculty are closely connected through working relationship, so records need to be updated
MentorEmailAddress varchar(45),
constraint MentorFK foreign key (MentorEmailAddress) references Mentor(MentorEmailAddress)
on delete cascade on update cascade, -- If deleted, then changes have to cascade since students are working with mentor and updates mean that student has changed mentors
Mentor_BCAlumniEmailAddress varchar(45) unique not null,
Mentor_BCAlumniFormerBCID int unsigned unique not null,
constraint BCAlumniFK foreign key (Mentor_BCAlumniEmailAddress, Mentor_BCAlumniFormerBCID) references BellevueCollegeAlumni(AlumniEmailAddress, FormerBCID)
on delete cascade -- This should be delete cascade because if faculty advisor is not a BC alumni, there is no need to keep their old records
on update no action -- highly unlikely that former records will be updated, so this is not necessary to cascade
)ENGINE=InnoDB character set utf8mb4
collate utf8mb4_unicode_520_ci;

/*Drop table Student;
Drop table Mentor;
Drop table FacultyAdvisor;
Drop table BellevueCollegeAlumni;
*/


