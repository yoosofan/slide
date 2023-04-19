import sqlite3
conn = sqlite3.connect('sp.sqlite')
c1 = conn.cursor()
c2 = conn.cursor()

r1 = c1.execute('select * from s;')
r2 = c2.execute('select * from p;')

print('S')
for m1 in r1:
  print(m1)

print('P')
for m1 in r2:
  print(m1)

c1.close()
c2.close()
conn.close()
