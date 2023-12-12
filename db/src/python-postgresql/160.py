import psycopg
conn = psycopg.connect(dbname="sp", user="postgres", password="12",host='127.0.0.1')
cur = conn.cursor()
s1=input('Enter a sn: ')
sname1=input('Enter sname ')
stmt1 ="insert into s(sn, sname, status, city) values('";
stmt1+=s1+"','"+sname1
stmt1+="',30,'Athens');"
cur.execute(stmt1)
cur.execute("select * from s;");
for a in cur.fetchall():
  print(a)
cur.close()
conn.commit()
conn.close()
