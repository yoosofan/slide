#https://www.psycopg.org/docs/usage.html
import psycopg2
conn = psycopg2.connect(database="sp", user="postgres", 
        password="12344321",host='127.0.0.1')
cur = conn.cursor()
sql = """
      CREATE TABLE test (
        id serial PRIMARY KEY, 
        num integer, 
        data varchar);
      """
cur.execute(sql)
sql = "INSERT INTO test (num, data) VALUES (" + s1+ ',' +s2+ ");"
sql = "INSERT INTO test (num, data) VALUES (%s, %s)"
cur.execute(sql, (100, "abc'def"))

cur.execute("SELECT * FROM test;")
cur.fetchone()
conn.commit()
cur.close()
conn.close()

