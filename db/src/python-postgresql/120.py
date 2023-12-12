import psycopg
conn = psycopg.connect(dbname="sp", user="ali", 
         password="12",host='127.0.0.1')
cur = conn.cursor()
cur.execute("""ALTER TABLE "a1" ADD "status" INTEGER;""");
#input("Enter something: ")
conn.commit();
cur.execute("""SELECT * FROM "a1";""")
cur.close()
conn.close()
