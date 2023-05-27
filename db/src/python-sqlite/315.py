import sqlite3
conn = sqlite3.connect('sp.sqlite')
c = conn.cursor()
pi = [ ('p19',) , ('p20',), ('p22',), ]
sql1 = '''delete from p where pn = ? ; ''' 
c.executemany(sql1, pi)
#c.execute(''' delete from p where pn = 'p19'; ''')
#c.execute(''' delete from p where pn = 'p20'; ''')
#c.execute(''' delete from p where pn = 'p22'; ''')
conn.commit()
c.close()
conn.close()
