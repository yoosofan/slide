
create table s (
	sn      char(10) primary key,
	sname   char(30),
	status  int  default(0),
	city    char(20)
);

create table p (
	pn     char(10) primary key,
	pname  char(30),
	color  char(20),
	weight NUMERIC(9, 2),
	city   char(20)
);

create table sp (
	sn    char(10) references s,
	pn    char(10) references p,
	qty   int default(0),
	primary key (sn, pn)
);

insert into s(sn, sname,  status, city)
values('s1', 'Smith', 20, 'London')
;
insert into s(sn, sname,  status, city)
values('s2', 'Jones', 10, 'Paris' )
;
insert into s(sn, sname,  status, city)
values('s3', 'Blake', 30, 'Paris' )
;
insert into s(sn, sname,  "status", city)
values('s4', 'Clark', 20, 'London')
;
insert into s(sname, status, city, sn)
values('Adams', 30, 'Athens', 's5')
;
insert into s
values('s6', 'Ali', 40, 'کاشان')
;

insert into p(pn, pname, color, weight, city)
values('p1','Nut'  ,'Red'  ,12.0,'London')
;
insert into p(pn, pname, color, weight, city)
values
  ('p2', 'Bolt' , 'Green', 17.0, 'Paris' ),
  ('p3', 'Screw', 'Blue' , 17.0, 'Oslo'  ),
  ('p4', 'Screw', 'Red'  , 14.0, 'London'),
  ('p5', 'Cam'  , 'Blue' , 12.0, 'Paris' ),
  ('p6', 'Cog'  , 'Red'  , 19.0, 'London')
;

insert into p(pn, pname, color, city)
values('p7', 'Nut', 'Red', 'London')
;
insert into p(pn, pname, color, city)
values('p8', 'Bolt', 'Green', 'Paris')
;


  insert into sp(sn, pn, qty)
    values
    ('s1', 'p1', 300),
    ('s1', 'p2', 200),
    ('s1', 'p3', 400),
    ('s1', 'p4', 200),
    ('s1', 'p5', 100),
    ('s1', 'p6', 100),
    ('s2', 'p1', 300),
    ('s2', 'p2', 400),
    ('s3', 'p2', 200),
    ('s4', 'p2', 200),
    ('s4', 'p4', 300),
    ('s4', 'p5', 400),
    ('s6', 'p2', 350)
  ;
