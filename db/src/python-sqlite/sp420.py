import sqlite3, os
def createTable(c):  
  c.execute('''CREATE TABLE IF NOT EXISTS stocks (
                  date1 char(10) primary key, 
                  trans char(15), 
                  symbol char(10), 
                  qty numeric(8,2), 
                  price numeric(8,2)
                  );
            ''')
  c.execute('''INSERT INTO stocks 
                VALUES ('2006-01-05','BUY','RHAT',100,35.14);
            ''')
def test2(c):
  t = ('RAT',)
  c.execute('SELECT * FROM stocks WHERE symbol=?', t)
  print(c.fetchone())
  
  # Larger example that inserts many records at a time
  purchases = [('2006-03-28', 'BUY', 'IBM', 1000, 45.00),
               ('2006-04-05', 'BUY', 'MSFT', 1000, 72.00),
               ('2006-04-06', 'SELL', 'IBM', 500, 53.00),
              ]
  c.executemany('INSERT INTO stocks VALUES (?,?,?,?,?)', purchases)
def testDelete(c):
  c.execute("DELETE FROM stocks WHERE symbol='IBM';")
  c.execute("select * from stocks");
  print("آخرین خروچی‌های");
  print(c.fetchone())
def testFor(c):
  for row in c.execute('SELECT * FROM stocks ORDER BY price'):
    print(row)
conn = sqlite3.connect('example.db')
c = conn.cursor()
createTable(c)
test2(c)
testDelete(c)
testFor(c)
conn.commit()
conn.close()
os.system('rm example.db')
