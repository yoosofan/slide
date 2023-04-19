import sqlite3
conn = sqlite3.connect('sp.sqlite')
c = conn.cursor()
r1 = c.execute('select * from "s";')
print(r1)
for m1 in r1:
  print(m1)
c.close()
conn.close()
