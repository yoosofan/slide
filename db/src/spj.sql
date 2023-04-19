create database SPJ;
CREATE TABLE S (
  sn     CHAR(10) PRIMARY KEY,
  sname  CHAR(30),
  status int  DEFAULT 0,
  city   CHAR(20)
);
CREATE TABLE P (
  pn     CHAR(10) PRIMARY KEY,
  pname  CHAR(30),
  color  CHAR(20),
  weight NUMERIC(9,2) DEFAULT 0,
  city   CHAR(20)
);
CREATE TABLE J (
  jn     CHAR(10) PRIMARY KEY,
  jname  CHAR(30),
  budget NUMERIC(14,5) DEFAULT 0,
  city   CHAR(20)
);
CREATE TABLE SPJ (
  sn    CHAR(10) REFERENCES S,
  pn    CHAR(10) REFERENCES P,
  jn    CHAR(10) REFERENCES J,
  qty   INT DEFAULT 0,
  PRIMARY KEY (sn, pn ,jn)
);

insert into S(sn,sname,status,city) values('S1','Smith',20,'London');
insert into S(sn,sname,status,city) values('S2','Jones',10,'Paris' );
insert into S(sn,sname,status,city) values('S3','Blake',30,'Paris' );
insert into S(sn,sname,status,city) values('S4','Clark',20,'London');
insert into S(sn,sname,status,city) values('S5','Adams',30,'Athens');

insert into P(pn, pname, color, weight, city) values('P1', 'Nut', 'Red', 12.0, 'London');
insert into P(pn, pname, color, weight, city) values('P2', 'Bolt', 'Green', 17.0, 'Paris');
insert into P(pn, pname, color, weight, city) values('P3', 'Screw', 'Blue', 17.0, 'Oslo');
insert into P(pn, pname, color, weight, city) values('P4', 'Screw', 'Red', 14.0, 'London');
insert into P(pn, pname, color, weight, city) values('P5', 'Cam', 'Blue', 12.0, 'Paris' );
insert into P(pn, pname, color, weight, city) values('P6', 'Cog', 'Red', 19.0, 'London');

insert into J(jn, jname, budget, city) values('J1', 'bulding A', 2000, 'Oslo ' );
insert into J(jn, jname, budget, city) values('J2', 'bulding B', 2500, 'Oslo ' );
insert into J(jn, jname, budget, city) values('J3', 'bulding C', 2900, 'Paris' );
insert into J(jn, jname, budget, city) values('J4', 'store A', 1400, 'Oslo'  );
insert into J(jn, jname, budget, city) values('J5', 'store B', 1300, 'London');

insert into SPJ(sn, pn, jn, qty) values('S1', 'P1','J1', 300);
insert into SPJ(sn, pn, jn, qty) values('S1', 'P2', 'J1', 200);
insert into SPJ(sn, pn, jn, qty) values('S1', 'P3', 'J1', 400);
insert into SPJ(sn, pn, jn, qty) values('S1', 'P4', 'J2', 200);
insert into SPJ(sn, pn, jn, qty) values('S1', 'P5', 'J2', 100);
insert into SPJ(sn, pn, jn, qty) values('S1', 'P6', 'J2', 100);
insert into SPJ(sn, pn, jn, qty) values('S2', 'P1', 'J3', 300);
insert into SPJ(sn, pn, jn, qty) values('S2', 'P2', 'J3', 400);
insert into SPJ(sn, pn, jn, qty) values('S3', 'P2', 'J3', 200);
insert into SPJ(sn, pn, jn, qty) values('S4', 'P2', 'J3', 200);
insert into SPJ(sn, pn, jn, qty) values('S4', 'P4', 'J3', 300);
insert into SPJ(sn, pn, jn, qty) values('S4', 'P5', 'J3', 400);
