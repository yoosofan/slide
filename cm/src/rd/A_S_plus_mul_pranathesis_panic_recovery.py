import sys, lexical_number_plus_mul_par
def S(lex1):
  while True:
    if A(lex1) == False: return False
    if lex1.ct.type != '+' and lex1.ct.type != '*':
      break
    print(lex1.ct.type, ':', lex1.s[lex1.end:])
    lex1.getToken()
  if lex1.ct.type == 'EOF' or lex1.ct.type == ')':
    return True
  return False
def A(lex1):
  if lex1.ct.type == 'a':
    print('a: ', lex1.ct.value, end=',')
    print('\t: ', lex1.s[lex1.end:])
    lex1.getToken()
  elif lex1.ct.type == '(':
    print('(\t: ', lex1.s[lex1.end:])
    lex1.getToken()
    if S(lex1) == False: return False
    if lex1.ct.type != ')' :
      print('Synatx Error: ) expected')
      print(lex1.ct.type, '\t', lex1.s[lex1.begin:])
      return False
    else: print(')'); lex1.getToken()
  else:
    print(' a or ( expected:: ', lex1.ct.type)
    return False;
  return True
def run(s):
  lex1 = lexical_number_plus_mul_par.lexical(s);
  lex1.getToken()
  if S(lex1) == True:
    if lex1.ct.type == 'EOF':
      print(True)
    else:
      print('Syntax Error: extra characters')
      print(lex1.s[lex1.begin:])
  else:
    print('Syntax Error at')
    print(lex1.s[lex1.begin:])
if __name__ == "__main__":
  if len(sys.argv) < 2:
    print("python3 a.py '12.1  + (35.45 * 2)'")
    raise SystemExit(f"Usage: {argvs[0]} input expression")
  s = ''.join(sys.argv[1:])
  run(s)
