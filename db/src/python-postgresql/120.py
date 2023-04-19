import psycopg2
conn = psycopg2.connect(database="sp", user="ali", 
         password="1234",host='127.0.0.1')
cur = conn.cursor()
cur.execute("""ALTER TABLE "a1" ADD "status" INTEGER;""");
conn.commit();
cur.execute("""SELECT * FROM "a1";""")
cur.close()
conn.close()
