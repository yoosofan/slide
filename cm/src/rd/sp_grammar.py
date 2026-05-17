class Parser:
  def __init__(self, text):
    self.text = text; self.pos = 0
  def cur_ch(self):
    if self.pos < len(self.text):
      return self.text[self.pos]
    return None
  def match(self, token):
    if self.text.startswith(token, self.pos):
      self.pos += len(token); return True
    return False
  def error(self, message):
    raise SyntaxError(
      f"{message} at position {self.pos}")
  def S(self):
    while self.match('a'):print("S: consume 'a'")
    self.B()
    while self.cur_ch() in ('a', 'b'):
      old_pos = self.pos
      try: self.B()
      except SyntaxError: self.pos = old_pos; break
  def B(self):
    while self.match('b'): print("B: consume 'b'")
    if self.match('ab'):print("B: consume 'ab'")
    else:self.error("Expected 'ab'")
    while self.match('a'):self.B()
  def parse(self):
    self.S()
    if self.pos != len(self.text):
      self.error("Unexpected input")
    print("\nInput accepted.")

samples = ["ab","aab","bbab","abbab","aaabbab",]
for s in samples:
  print("\n==========\nInput:", s)
  try: parser = Parser(s); parser.parse()
  except SyntaxError as e:print("Syntax Error:", e)

# -------------------------------------------------
# Grammar:
#
# S:
#   a* B+
#
# B:
#   b* ab (a B)*
# -------------------------------------------------
# By Assistance of chatgpt.com
# full generatd code in cm/src/rd/simple.grammar.python/sp_grammar.py
