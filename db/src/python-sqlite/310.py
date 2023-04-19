import sqlite3
conn = sqlite3.connect('sp.sqlite')
c = conn.cursor()
c.execute(''' 
  insert into p(pn, pname, color, weight, city)
  values('p19','Nut'  ,'Red'  ,12.0,'London')
  ;
 ''')
r1 = c.execute('select * from p;')
for m1 in r1:
  print(m1)
print('before commit')
conn.commit()
print('after commit')
r1 = c.execute('select * from p;')
for m1 in r1:
  print(m1)
c.close()
conn.close()
