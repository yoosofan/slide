import psycopg
conn = psycopg.connect(dbname="sp", user="postgres", 
          password="12",host='127.0.0.1')
cur = conn.cursor()
cur.execute("""SELECT * FROM "s";""");
for a in cur.fetchall():
  print(a)
cur.close()
conn.commit()
conn.close()

# psql --username=postgres --dbname=sp  --host=127.0.0.1  --password
# INSERT INTO "p"("pn", "pname", "color", "weight", "city") VALUES('p7','Bolt', 'Green', 12.1, 'Shiraz');

# with psk as (select city from p natural join s)
# select * from psk;
# CREATE OR REPLACE VIEW "psk" ("city") AS SELECT DISTINCT "p"."city" FROM "s" JOIN "p" ON "s"."city" = "p"."city" ;
"""
CREATE OR REPLACE VIEW "psk" ("city") AS 
    SELECT DISTINCT "p"."city" 
    FROM "s" JOIN "p" ON "s"."city" = "p"."city" ;
"""
