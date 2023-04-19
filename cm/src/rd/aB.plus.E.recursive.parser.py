import sys, lexical_number_plus

def E(lex1):
  t = lex1.getToken()
  if t.type == 'a':
    print('a B\t a: ',  t.value, end=',')
    print('\tB: ',  lex1.s[lex1.end:])
    return B(lex1)
  print('Synatx Error: number expected')
  print('Reminder: ',lex1.s[lex1.begin:])
  return False

def B(lex1):
  t = lex1.getToken()
  if t.type == '+': 
    print('+E,\tE:', lex1.s[lex1.end:] )
    return E(lex1)
  elif t.type == 'EOF': return True
  print('Error a a:', s[0])
  return False

def run(s):
  lex1 = lexical_number_plus.lexical(s);
  print(E(lex1))

if __name__ == "__main__":
  if len(sys.argv) < 2:
    print('python3 a.py 12.1  + 35.45 + 2')
    raise SystemExit(f"Usage: {argvs[0]} input expression")
  s = ''.join(sys.argv[1:])
  run(s)
'''
12.1  + + 2
12.1  + 
+3
12.1  + 35.45 + 2
'''