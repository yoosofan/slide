import sqlite3
conn = sqlite3.connect('sp.sqlite')
c = conn.cursor()
purchases = [('P9', 'monitor', 'RED', 1000, 'Lahijan'),
             ('P10', 'keyboard2', 'BLUE', 500, 'Ghom'),
             ('P11', 'mouse2', 'WHITE', 600, 'Fasa'),
            ]
c.executemany('INSERT INTO p VALUES (?,?,?,?,?)', purchases)
t = "P9"
for m1 in c.execute('SELECT * FROM p WHERE pn=? ;', (t,)):
  print(m1)
c.close(); conn.close() # no commit() means revoke
