import sqlite3
conn = sqlite3.connect('sp.sqlite')
c = conn.cursor()
c.execute('''delete from p where pn='p19';''')
conn.commit()
r1 = c1.execute('select * from p;')
for m1 in r1:
  print(m1)
c.close()
conn.close()
