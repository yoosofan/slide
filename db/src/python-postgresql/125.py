import psycopg
conn = psycopg.connect(dbname="sp", user="ali", 
        password="12",host='127.0.0.1')
cur = conn.cursor()
conn.commit();
cur.execute("select * from a1;");
for a in cur.fetchall():
  print(a)
cur.close()
conn.close()
