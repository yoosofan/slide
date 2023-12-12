#https://www.psycopg.org/docs/usage.html
import psycopg
conn = psycopg.connect(dbname="sp", user="postgres", 
        password="12",host='127.0.0.1')
cur = conn.cursor()
sql = """
      CREATE TABLE if not exists test (
        id serial PRIMARY KEY, 
        num integer, 
        data varchar);
      """
cur.execute(sql)
s1 = 54; s2 = 'eeee'
sql = "INSERT INTO test (num, data) VALUES (" + str(s1)+ ',' +s2+ ");"
sql = "INSERT INTO test (num, data) VALUES (%s, %s)"
cur.execute(sql, (100, "abc'def"))

cur.execute("SELECT * FROM test;")
cur.fetchone()
conn.commit()
cur.close()
conn.close()

