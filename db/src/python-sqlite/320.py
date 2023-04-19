import sqlite3
conn = sqlite3.connect('sp.sqlite')
c = conn.cursor()
c1 = conn.cursor()
c.execute(''' 
  insert into p(pn, pname, color, weight, city)
  values('p20','Nut'  ,'Red'  ,12.0,'London')
  ;
 ''')
r1 = c1.execute('select * from p;')
for m1 in r1:
  print(m1)
print('before commit')
conn.commit()
print('after commit')
r1 = c1.execute('select * from p;')
for m1 in r1:
  print(m1)
c.close()
c.close()
conn.close()
