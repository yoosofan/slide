import psycopg
conn = psycopg.connect(database="sp", user="ali", 
        password="1234", host = '127.0.0.1')
cur = conn.cursor()
cur.execute("select * from s;");
for a in cur.fetchall():
  print(a)
cur.close()
conn.close()
