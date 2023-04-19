import sqlite3
conn = sqlite3.connect('sp.sqlite')
c = conn.cursor()

r1 = c.execute('select * from s;')

print('S')
for m1 in r1:
  print(m1)

r2 = c.execute('select * from p;')

print('P')
for m1 in r2:
  print(m1)

c.close()
conn.close()
