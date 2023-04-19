import psycopg2
conn = psycopg2.connect(database="sp", user="postgres", password="12344321",host='127.0.0.1')
cur = conn.cursor()
conn.commit();
cur.execute("select * from a1;");
for a in cur.fetchall():
  print(a)
cur.execute("update a1 set status=10 where sno='s1';")
cur.execute("update a1 set status=20 where sno='s3';")
conn.commit();
cur.execute("select * from a1;");
for a in cur.fetchall():
  print(a)
cur.close()
conn.close()
