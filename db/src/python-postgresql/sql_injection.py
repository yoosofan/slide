mport psycopg2
conn = psycopg2.connect(database="sp", user="postgres", 
            password="12344321",host='127.0.0.1')
cur = conn.cursor()
conn.commit();
cur.execute("select * from s;");
for a in cur.fetchall():
  print(a)
print()
n1=input('Enter Status for s1 :  ')
si=input("Enter si : ");
stmt="update s set status="+str(n1)+" where sn='"+si+"';"
stmt="update s set status="+str(n1)+" where sn='"+"'S12'"+"';"
stmt="update s set status="+str(n1)+" where sn='"+"S12' or '32'='32"+"';"

S12' or '32'='32

update s set status=13 where sn='S12' or '32'='32';

stmt="update s set status="+str(n1)+" where sn='"+"S12'; insert into p(pn, pname, weight, city) values('p31', 'ddd', 43, 'Kashan'); select * from p where pn='p4343"+"';"

S12'; insert into p(pn, pname, weight, city) values('p31', 'ddd', 43, 'Kashan'); select * from p where pn='p4343

update s set status=54 where sn='S12'; 
insert into p(pn, pname, weight, city) values('p31', 'ddd', 43, 'Kashan'); 
select * from p where pn='p4343';

print(stmt)
cur.execute(stmt)
#cur.execute("update s set status=20 where sn='s3';")
conn.commit();
print();
cur.execute("select * from s;");
for a in cur.fetchall():
  print(a)
cur.close()
conn.close()
