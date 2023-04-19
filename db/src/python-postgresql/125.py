import psycopg2
conn = psycopg2.connect(database="sp", user="ali", 
        password="1234",host='127.0.0.1')
cur = conn.cursor()
conn.commit();
cur.execute("select * from a1;");
for a in cur.fetchall():
  print(a)
cur.close()
conn.close()
