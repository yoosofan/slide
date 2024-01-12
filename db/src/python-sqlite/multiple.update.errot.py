import sqlite3
conn = sqlite3.connect('library.sqlite')
c1 = conn.cursor()
c2 = conn.cursor()
r1 = c.execute('select * from book;')
for m1 in r1:
  if m1.fpd <18:
    r2 = c.execute('UPDATE book SET fpd = fpd + 5 WHERE bn = m1.bn;')
  elif m1.fpd >= 18 and m1 < 24:
    r2 = c.execute('UPDATE book SET fpd = fpd + 8 WHERE bn = m1.bn;')
  else:
    r2 = c.execute('UPDATE book SET fpd = fpd + 10 WHERE bn = m1.bn;')
c.close()
conn.close()
