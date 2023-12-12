import psycopg
conn = psycopg.connect(dbname="sp", user="ali", 
        password="12", host = '127.0.0.1')
cur = conn.cursor()
cur.execute("select * from s;");
for a in cur.fetchall():
  print(a)
cur.close()
conn.close()
