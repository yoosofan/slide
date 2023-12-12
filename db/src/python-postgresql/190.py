import psycopg
#conn = psycopg.connect(dbname="sp", user="postgres", password="12",host='localhost')
conn = psycopg2.connect(dbname="sp", user="postgres", password="12344321",host='127.0.0.1')
cur = conn.cursor()
#cur.execute("SELECT * from s")
#print(cur.fetchone())
#cur.execute(
# "create view vs2 as select sno,pno,sname from s natural join sp;");
#cur.execute(
# "select * from vs2");
#print(cur.fetchone());
#for a  in cur.fetchall():
#  print(a)
#cur.execute(
#  "insert into s values ('s6','ali',20,null);")
#conn.commit();
cur.execute("select * from s;");
for a in cur.fetchall():
  for l1 in a:
    #print(l1,type(l1),end=' ');
    if type(l1) != int and type(l1)!=float and l1!=None:
      print(l1,len(l1),end=' ');
  print()
cur.execute('''
create table if not exists a2 (
  sn varchar(10),
  sname varchar(25),
  primary key(sn)
);
''')
conn.commit()
cur.execute(
 "insert into a2 values('s1','ali');")
conn.commit()
cur.execute("select * from a1;");
for a in cur.fetchall():
  for l1 in a:
    #print(l1,type(l1),end=' ');
    if type(l1) != int and type(l1)!=float and l1!=None:
      print(l1,len(l1),end=' ');
  print()
cur.close()
conn.close()
