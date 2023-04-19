import psycopg2
conn = psycopg2.connect(database="sp", user="ali", 
         password="1234", host = '127.0.0.1')
cur = conn.cursor()
cur.execute("select * from s;");
for a in cur.fetchall():
  print('[ ', end = '')
  for m1 in a:
    if type(m1) is str:
      print(m1.strip(), end=', ')
    else:
      print(m1, end=', ')
  print(']')
cur.close()
conn.close()
