import psycopg2
conn = psycopg2.connect(database="sp", user="ali", 
         password="1234",host='127.0.0.1')
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

