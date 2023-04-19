import sys, lexical_number_plus

def E(lex1):
  x = 0.0
  while True:
    t = lex1.getToken()
    if t.type == 'a':
      print('a: ',  t.value, end=',')
      print('\t: ', lex1.s[lex1.end:])
      x += t.value
    else:
      print('Synatx Error: number expected')
      print('\t', lex1.s[lex1.begin:])
      break
    t = lex1.getToken()
    if t.type != '+':
      if t.type != 'EOF':
        print('End of input expected')
      break
  if t.type != 'EOF': return False, x
  return True, x

def run(s):
  lex1 = lexical_number_plus.lexical(s);
  print(E(lex1))

if __name__ == "__main__":
  if len(sys.argv) < 2:
    print('python3 a.py 12.1  + 35.45 + 2')
    raise SystemExit(f"Usage: {argvs[0]} input expression")
  s = ''.join(sys.argv[1:])
  run(s)
