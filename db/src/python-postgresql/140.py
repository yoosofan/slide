#Error 
import psycopg2
conn = psycopg2.connect(database="sp", user="postgres", 
          password="12344321",host='127.0.0.1')
cur = conn.cursor()
conn.commit();
cur.execute("select * from a1;");
for a in cur.fetchall():
  print(a)
#cur.execute("insert into a1(sno,status) values('s4','alll');")
cur.execute("""INSERT INTO "a1"("mn", "st", "status") VALUES
            (4, 'S4', 15);""")
cur.execute("""UPDATE "a1" SET "status" = 40 WHERE "st"='S4';""")
cur.execute("select * from a1;");
for a in cur.fetchall():
  print(a)
conn.commit()

cur.close()
conn.close()
