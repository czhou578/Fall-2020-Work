create table if not exists Coach (
name varchar(45) primary key not null,
email varchar(45)
);

create table if not exists player (
name varchar(45) primary key not null,
number int,
score int,
team_id int,
foreign key (team_id)
references team(sub_id)
);

create table if not exists team (
sub_id int primary key not null,
name varchar(45),
coach varchar(45),
captain varchar(45),
foreign key (coach) 
references Coach(name),
foreign key (captain)
references player(name)
);

create table if not exists game (
teamA int not null,
teamB int not null,
scoreA int,
scoreB int,
foreign key(teamA)
references team(sub_id),
foreign key(teamB)
references team(sub_id),
primary key(teamA, teamB)
);
