import psycopg
conn = psycopg.connect(dbname="sp", user="ali", 
         password="12",host='127.0.0.1')
cur = conn.cursor()
#cur.execute("select * from a1;");
cur.execute("""CREATE TABLE IF NOT EXISTS "a1"( 
                    "mn" INTEGER PRIMARY KEY, 
                    "st" VARCHAR(20)
                );
            """)
conn.commit();
cur.close()
conn.close()

