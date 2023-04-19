import sqlite3
conn = sqlite3.connect('library.sqlite')
c = conn.cursor()

r1=c.execute('select year,name from book;')
print(r1)
for m1 in r1:
  print(m1)

#c.execute("insert into book values('21','حسنی به خانه نرسید',1390);")
conn.commit()
c.close()
conn.close()
