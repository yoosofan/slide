#https://www.psycopg.org/docs/usage.html
import psycopg2
conn = psycopg2.connect(database="sp", user="postgres", 
        password="12344321",host='127.0.0.1')
cur = conn.cursor()
cur.execute("CREATE TABLE test (id serial PRIMARY KEY, num integer, data varchar);")
cur.execute("INSERT INTO test (num, data) VALUES (%s, %s)", (100, "abc'def"))

cur.execute("SELECT * FROM test;")
cur.fetchone()
conn.commit()
cur.close()
conn.close()

"""
>>> cur.execute("SELECT (%s % 2) = 0 AS even", (10,))       # WRONG
>>> cur.execute("SELECT (%s %% 2) = 0 AS even", (10,))      # correct

>>> cur.mogrify("SELECT %s, %s, %s;", (None, True, False))
'SELECT NULL, true, false;'

>>> cur.mogrify("SELECT %s, %s, %s, %s;", (10, 10L, 10.0, Decimal("10.00")))
'SELECT 10, 10, 10.0, 10.00;'


>>> dt = datetime.datetime.now()
>>> dt
datetime.datetime(2010, 2, 8, 1, 40, 27, 425337)

>>> cur.mogrify("SELECT %s, %s, %s;", (dt, dt.date(), dt.time()))
"SELECT '2010-02-08T01:40:27.425337', '2010-02-08', '01:40:27.425337';"

>>> cur.mogrify("SELECT %s;", (dt - datetime.datetime(2010,1,1),))
"SELECT '38 days 6027.425337 seconds';"

>>> cur.mogrify("SELECT %s IN %s;", (10, (10, 20, 30)))
'SELECT 10 IN (10, 20, 30);'


with psycopg2.connect(DSN) as conn:
    with conn.cursor() as curs:
        curs.execute(SQL)
"""
