import sqlite3
def createTable(c):  
  c.execute('''CREATE TABLE IF NOT EXISTS p (
                  pn char(10), 
                  pname char(15), 
                  city char(10), 
                  status numeric(8,2), 
                  primary key(pno)
                  );
            ''')
  c.execute('''INSERT INTO p 
               VALUES ('p1','keyboard','Kashan',100),
                 ('p2','mouse'   ,'Shiraz',200);
            ''')
def test2(c):
  t=input("Enter pno: ");
  print(t)	
  c.execute('SELECT * FROM p WHERE pn=? ;', (t,))
  print(c.fetchone())
  
  # Larger example that inserts many records at a time
  purchases = [
    ('p3', 'monitor', 'Lahijan', 1000),
    ('p4', 'keyboard2', 'Ghom', 1000),
    ('p5', 'mouse2', 'Fasa', 500),
  ]
  c.executemany('INSERT INTO p VALUES (?,?,?,?)', purchases)
  
def testFor(c):
  for row in c.execute('SELECT * FROM p ORDER BY weight'):
    print(row)
def testInputDeleteUser(c):
  t=input("Enter pn: ");
  c.execute('delete from p where pn=?;',(t,));
conn = sqlite3.connect('newdb.sqlite')
c = conn.cursor()
createTable(c)
testFor(c)
testInputDeleteUser(c)
testFor(c)
conn.commit()
