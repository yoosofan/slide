import sqlite3
conn = sqlite3.connect('sp.sqlite')
c = conn.cursor()
r1 = c.execute('select * from s;')
r2 = c.execute('select * from p;')
print('r1: ', type(r1))
print('r2:',  type(r2))
r1 = ( ('p4', 'cog', 'green', 13),
        ('p8', 'bolt', 'red', 32)
     )
r2 = ( ('p15', 'screw', 'blue', 76),
       ( 'p45', 'Nut', 'Red', 27)
     )
print('r1: ', type(r1))
print('r2:',  type(r2))
print('S')
r1 = c.execute('select * from s;')
r2 = c.execute('select * from p;')
for m1 in r1:
  print(m1)
print('P')
for m1 in r2:
  print(m1)
c.close()
conn.close()
