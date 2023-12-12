mport psycopg
conn = psycopg.connect(dbname="sp", user="postgres", 
            password="12",host='127.0.0.1')
cur = conn.cursor()
conn.commit();
cur.execute("select * from s;");
for a in cur.fetchall():
  print(a)
print()
n1=input('Enter Status for s1 :  ')
si=input("Enter si : ");
stmt="update s set status=%s where sn= %s ;"
cur.execute(stmt, (n1, 's1'));
stmt="update s set status=%s where sn=%s;"
cur.execute(stmt, (n1, 'S12')
"""
update s set status=54 where sn='S12'; 
insert into p(pn, pname, weight, city) values('p31', 'ddd', 43, 'Kashan'); 
select * from p where pn='p4343';
"""
conn.commit();
print();
cur.execute("select * from s;");
for a in cur.fetchall():
  print(a)
cur.close()
conn.close()
