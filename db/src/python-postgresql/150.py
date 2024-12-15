#Error
import psycopg
conn = psycopg.connect(dbname="sp", user="ali", password="12",host='127.0.0.1')
cur = conn.cursor()
cur.execute("select * from a1;");
for a in cur.fetchall():
  print(a)
cur.execute("update a1 set status=10 where sn='s1';")
cur.execute("update a1 set status=20 where sn='s2';")
#cur.execute("update a1 set status=10 where st='s1';")
#cur.execute("update a1 set status=20 where st='s2';")
conn.commit();
#cur.execute("select * from a1;")
for a in cur.fetchall():
  print(a)
cur.close()
conn.close()
