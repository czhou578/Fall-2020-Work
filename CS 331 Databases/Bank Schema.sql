Create Table If not exists Bank
(
Code int not null primary key,
BName VarChar(40) Not null,
BAddress VarChar(40) 
);

Create Table If not exists Bank_Branch
(
BankCode int not null,
Branch_no int not null,
primary key(BankCode, Branch_no),
BranchAddress VarChar(40),
foreign key (BankCode) references Bank(Code)
on delete cascade on update cascade
);

Create Table If not exists Account
(
Acc_no int not null primary key,
Balance VarChar(40),
Type VarChar(40),
BankCode int not null,
BankBranchNo int not null,
foreign key(BankCode, BankBranchNo) references Bank_Branch(BankCode, Branch_no)
on delete cascade on update cascade
);

Create Table If not exists Loan
(
Loan_no int not null primary key,
Amount VarChar(40) not null,
LType VarChar(40), 
BankCode int not null,
BankBranchNo int,
foreign key(BankCode, BankBranchNo) references Bank_Branch(BankCode, Branch_no)
on delete cascade on update cascade
);

Create Table If not exists Customer
(
Ssn int not null primary key,
Phone VarChar(40) not null,
CName VarChar(40) not null,
CAddress VarChar(40) 
);

Create Table If not exists AC
(
AccountNumber int not null,
Ssn int not null,
primary key (AccountNumber, Ssn),
foreign key (AccountNumber) references Account(Acc_no)
on delete cascade on update cascade,
foreign key (Ssn) references Customer (Ssn)
on delete cascade on update cascade
);

Create Table If not exists LC
(
LoanNumber int not null,
Ssn int not null,
primary key(LoanNumber, Ssn),
foreign key (LoanNumber) references Loan(Loan_no)
on delete cascade on update cascade,
foreign key (Ssn) references Customer(Ssn)
on delete cascade on update cascade

);


