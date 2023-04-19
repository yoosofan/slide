import psycopg2
conn = psycopg2.connect(database="sp", user="postgres", 
        password="12344321",host='127.0.0.1')
cur = conn.cursor()
cur.execute("select sn,avg(qty) from sp group by sn;");
for a in cur.fetchall():
  print(a)
cur.execute("select sn,qty from sp;")
sum=0;
prev='s00'
for a in cur.fetchall():
  if a[0]==prev:
    sum+=a[1];
  else:
    if prev!='s00': 
      print(prev, sum)
    sum=a[1]
    prev=a[0]
cur.close()
conn.close()
