CREATE TABLE S (
   sno     CHAR(10) PRIMARY KEY,
   sname   CHAR(30),
   status  int  DEFAULT 0,
   city    CHAR(20)
);

CREATE TABLE P (
   pno    CHAR(10) PRIMARY KEY,
   pname  CHAR(30),
   color  CHAR(15),
   weight NUMERIC(9,2) DEFAULT 0,
   city   CHAR(20)
);

CREATE TABLE SP (
   sno   CHAR(10) REFERENCES S,
   pno   CHAR(10) REFERENCES P,
   qty   INT DEFAULT 0,
   PRIMARY KEY (sno,pno)
);


insert into S values('S1','Smith',20,'London');
insert into S values('S2','Jones',10,'Paris' );
insert into S values('S3','Blake',30,'Paris' );
insert into S values('S4','Clark',20,'London');
insert into S values('S5','Adams',30,'Athens');


insert into P values('P1','Nut'  ,'Red'  ,12.0,'London');
insert into P values('P2','Bolt' ,'Green',17.0,'Paris' );
insert into P values('P3','Screw','Blue' ,17.0,'Oslo'  );
insert into P values('P4','Screw','Red'  ,14.0,'London');
insert into P values('P5','Cam'  ,'Blue' ,12.0,'Paris' );
insert into P values('P6','Cog'  ,'Red'  ,19.0,'London');

insert into SP values('S1','P1',300);
insert into SP values('S1','P2',200);
insert into SP values('S1','P3',400);
insert into SP values('S1','P4',200);
insert into SP values('S1','P5',100);
insert into SP values('S1','P6',100);
insert into SP values('S2','P1',300);
insert into SP values('S2','P2',400);
insert into SP values('S3','P2',200);
insert into SP values('S4','P2',200);
insert into SP values('S4','P4',300);
insert into SP values('S4','P5',400);
