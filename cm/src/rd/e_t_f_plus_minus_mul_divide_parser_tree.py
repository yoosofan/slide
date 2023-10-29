import sys, lexical_number_plus_mul_par
def S(lex1):
  lex1.getToken()
  if E(lex1) == True:
    if lex1.ct.type == 'EOF':  print(True)
    else:
      print('Syntax Error: extra characters at END: ')
      print(lex1.s[lex1.begin:])
  else: print('Syntax Error at', lex1.s[lex1.begin:])
def E(lex1):
  while True:
    print('E: ', lex1.s[lex1.begin:]) 
    if T(lex1) == False: return False
    if lex1.ct.type not in ['+', '-']: 
      break
    print('Op: ', lex1.s[lex1.begin:])
    lex1.getToken()
  return True
def T(lex1):
  while True:
    print('T: ', lex1.s[lex1.begin:])
    if F(lex1) == False: return False
    if lex1.ct.type not in ['*', '/']: 
      break
    print('Op: ', lex1.s[lex1.begin:])
    lex1.getToken()
  return True;
def F(lex1):
  print('F: ', lex1.s[lex1.begin:])
  if lex1.ct.type == 'a':
    print('Number: ', lex1.ct.value)
    lex1.getToken()
  elif lex1.ct.type == '(':
    lex1.getToken()
    if E(lex1) == False: return False
    if lex1.ct.type != ')' : 
      return False
    lex1.getToken()
  else: return False
  return True
def run(s):
  lex1 = lexical_number_plus_mul_par.lexical(s);
  S(lex1)
if __name__ == "__main__":
  while True:
    print("Enter an expression like 12.1  + (35.45 * 2)")
    s = input("> ")
    if s.strip() == '':
      break
    run(s)
'''    
  if len(sys.argv) < 2:
    print("python3 a.py '12.1  + (35.45 * 2)'")
    raise SystemExit(f"Usage: {sys.argv[0]} input expression")
  s = ''.join(sys.argv[1:])
  run(s)
'''