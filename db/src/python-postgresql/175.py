import psycopg
conn = psycopg.connect(dbname="sp", user="postgres", password="12",host='127.0.0.1')
cur = conn.cursor()
cur.execute("select * from s;");
for a in cur.fetchall():
  print(a)
print()
n1=input('Enter Status for s1 :  ')
si=input("Enter si : ");
si=si.replace("'","\\'")
"""
s8' or sname='3' or sname='Jones' or sname='Blake' or sname='Clark' or sname='Adams
s8' or 12=12 or sname='S1
"""
stmt="update s set status="+str(n1)+" where sn='"+si+"';"
print(stmt)
cur.execute(stmt)
#cur.execute("update s set status=20 where sn='s3';")
conn.commit();
print();
cur.execute("select * from s;");
for a in cur.fetchall():
  print(a)
cur.close()
conn.close()
