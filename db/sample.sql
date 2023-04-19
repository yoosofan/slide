insert into s(sn, sname,  status, city) values('S1', 'Smith', 20, 'London');
insert into s(sn, sname,  status, city) values('S2', 'Jones', 10, 'Paris' );
insert into s(sn, sname,  status, city) values('S3', 'Blake', 30, 'Paris' );
insert into s(sn, sname,  "status", city) values('S4', 'Clark', 20, 'London');
insert into s(sname, status, city, sn) values('Adams', 30, 'Athens', 'S5');
insert into s values('S6', 'Ali', 40, 'کاشان');

insert into p(pn,pname,color,weight,city) values('P1','Nut'  ,'Red'  ,12.0,'London');
insert into p(pn,pname,color,weight,city) values('P2','Bolt' ,'Green',17.0,'Paris' ),
                                                ('P3','Screw','Blue' ,17.0,'Oslo'  ),
                                                ('P4','Screw','Red'  ,14.0,'London'),
                                                ('P5','Cam'  ,'Blue' ,12.0,'Paris' ),
                                                ('P6','Cog'  ,'Red'  ,19.0,'London');

insert into p(pn,pname,color,city) values('P7','Nut'  ,'Red'  ,'London');
insert into p(pn,pname,color,city) values('P8','Bolt' ,'Green','Paris' );

insert into sp(sn,pn,qty) values('S1','P1',300),
                                ('S1','P2',200),
                                ('S1','P3',400),
                                ('S1','P4',200),
                                ('S1','P5',100),
                                ('S1','P6',100),
                                ('S2','P1',300),
                                ('S2','P2',400),
                                ('S3','P2',200),
                                ('S4','P2',200),
                                ('S4','P4',300),
                                ('S4','P5',400);
