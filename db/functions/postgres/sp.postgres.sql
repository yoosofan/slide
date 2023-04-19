DROP DATABASE IF EXISTS sp;

create database sp;

\c sp
-- \connect sp

DROP TABLE  IF EXISTS  sp ;
DROP TABLE  IF EXISTS  s  ;
DROP TABLE  IF EXISTS  p  ;

CREATE TABLE s (
   sn     CHAR(10) PRIMARY KEY,
   sname   CHAR(30),
   status  int  DEFAULT 0,
   city    CHAR(20)
);

CREATE TABLE p (
   pn    CHAR(10) PRIMARY KEY,
   pname  CHAR(30),
   color  CHAR(20),
   weight NUMERIC(9,2) DEFAULT 0,
   city   CHAR(20)
);

CREATE TABLE sp (
   sn   CHAR(10) REFERENCES s,
   pn   CHAR(10) REFERENCES p,
   qty   INT DEFAULT 0,
   PRIMARY KEY (sn,pn)
);


insert into s(sn,sname,status,city) values('S1','Smith',20,'London');
insert into s(sn,sname,status,city) values('S2','Jones',10,'Paris' );
insert into s(sn,sname,status,city) values('S3','Blake',30,'Paris' );
insert into s(sn,sname,status,city) values('S4','Clark',20,'London');
insert into s(sn,sname,status,city) values('S5','Adams',30,'Athens');


insert into p(pn,pname,color,weight,city) values('P1','Nut'  ,'Red'  ,12.0,'London');
insert into p(pn,pname,color,weight,city) values('P2','Bolt' ,'Green',17.0,'Paris' );
insert into p(pn,pname,color,weight,city) values('P3','Screw','Blue' ,17.0,'Oslo'  );
insert into p(pn,pname,color,weight,city) values('P4','Screw','Red'  ,14.0,'London');
insert into p(pn,pname,color,weight,city) values('P5','Cam'  ,'Blue' ,12.0,'Paris' );
insert into p(pn,pname,color,weight,city) values('P6','Cog'  ,'Red'  ,19.0,'London');

insert into sp(sn,pn,qty) values('S1','P1',300);
insert into sp(sn,pn,qty) values('S1','P2',200);
insert into sp(sn,pn,qty) values('S1','P3',400);
insert into sp(sn,pn,qty) values('S1','P4',200);
insert into sp(sn,pn,qty) values('S1','P5',100);
insert into sp(sn,pn,qty) values('S1','P6',100);
insert into sp(sn,pn,qty) values('S2','P1',300);
insert into sp(sn,pn,qty) values('S2','P2',400);
insert into sp(sn,pn,qty) values('S3','P2',200);
insert into sp(sn,pn,qty) values('S4','P2',200);
insert into sp(sn,pn,qty) values('S4','P4',300);
insert into sp(sn,pn,qty) values('S4','P5',400);

DROP TABLE  sp;
