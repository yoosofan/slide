import sqlite3

def createTable(c):  
  c.execute('''CREATE TABLE IF NOT EXISTS p (
                  pno char(10), 
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
  c.execute('SELECT * FROM p WHERE pno=? ;', (t,))
  print(c.fetchone())
  
  # Larger example that inserts many records at a time
  purchases = [('p3', 'monitor', 'Lahijan', 1000),
               ('p4', 'keyboard2', 'Ghom', 1000),
               ('p5', 'mouse2', 'Fasa', 500),
              ]
  c.executemany('INSERT INTO p VALUES (?,?,?,?)', purchases)
  
'''
def testDelete(c):
  c.execute("DELETE FROM stocks WHERE symbol='IBM';")
  c.execute("select * from stocks");
  print("آخرین خروچی‌های");
  print(c.fetchone())
  print(c.fetchone())
  print(c.fetchone())
  print(c.fetchone())
'''
def testFor(c):
  for row in c.execute('SELECT * FROM p ORDER BY status'):
    print(row)
def testInputDeleteUser(c):
	t=input("Enter pno");
	c.execute('delete from p where pno=?;',(t,));
conn = sqlite3.connect('sp.db')
c = conn.cursor()
#createTable(c)
#test2(c)
#testDelete(c)
testFor(c)
testInputDeleteUser(c)
testFor(c)
conn.commit()
