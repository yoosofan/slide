from sly import Lexer; import argparse
class BasicLexer(Lexer):
  tokens = {
    BEGIN,END,LET,PRINT,WHILE,ID,NUMBER,NEWLINE,
  }
  literals = {"+", "-", "*", "/", "=", "(", ")"}
  ignore = " \t"
  @_(r"[A-Za-z_][A-Za-z0-9_]*")
  def ID(self, t):
    v = {"BEGIN", "END", "LET", "PRINT", "WHILE"}
    if t.value in v: t.type = t.value
    return t
  @_(r"\d+")
  def NUMBER(self, t):
    t.value = int(t.value); return t
  @_(r"\n+")
  def NEWLINE(self, t):
    self.lineno += len(t.value); return t
  def error(self, t): raise SyntaxError("Err")
class BlockNode:
  def __init__(self, s): self.s = s
  def eval(self, env):
    for st in self.s: st.eval(env)
class LetNode:
  def __init__(self, n, e): self.n, self.e = n, e
  def eval(self, env): env[self.n] = self.e.eval(env)
class PrintNode:
  def __init__(self, e): self.e = e
  def eval(self, env): print(self.e.eval(env))
class WhileNode:
  def __init__(self, c, b): self.c, self.b = c, b
  def eval(self, env):
    while self.c.eval(env) != 0: self.b.eval(env)
class BinOpNode:
  def __init__(self, o, l, r):
    self.o, self.l, self.r = o, l, r
  def eval(self, env):
    l, r = self.l.eval(env), self.r.eval(env)
    if self.o == "+": return l + r
    if self.o == "-": return l - r
    if self.o == "*": return l * r
    if self.o == "/": return l // r
class NumNode:
  def __init__(self, v): self.v = v
  def eval(self, env): return self.v
class VarNode:
  def __init__(self, n): self.n = n
  def eval(self, env): return env.get(self.n, 0)
class Interpreter:
  def __init__(self, src):
    self.tk = list(BasicLexer().tokenize(src))
    self.p = 0; self.vars = {}
  def cur(self):
    if self.p < len(self.tk): return self.tk[self.p]
    return None
  def cur_t(self):
    c = self.cur()
    return c.type if c else "EOF"
  def advance(self):
    t = self.cur(); self.p += 1; return t
  def match(self, k):
    if self.cur_t() == k: return self.advance()
    return None
  def expect(self, k):
    t = self.match(k)
    if not t: raise SyntaxError("Err")
    return t
  def parse(self):
    while self.cur_t() == "NEWLINE": self.advance()
    ast = self.B() # Annotated Syntax Tree
    while self.cur_t() == "NEWLINE": self.advance()
    return ast
  def B(self):
    self.expect("BEGIN"); self.expect("NEWLINE")
    st = self.M(); self.expect("END")
    return BlockNode(st)
  def M(self):
    st = []; v = ("LET", "PRINT", "WHILE", "NEWLINE")
    while self.cur_t() in v:
      if self.cur_t() == "NEWLINE":
        self.advance()
        continue
      st.append(self.L())
      if self.cur_t() == "NEWLINE": self.advance()
    return st
  def L(self):
    if self.match("LET"):
      n = self.expect("ID").value
      self.expect("=")
      return LetNode(n, self.E())
    if self.match("PRINT"):
      return PrintNode(self.E())
    if self.match("WHILE"):
      c = self.E()
      while self.cur_t() == "NEWLINE": self.advance()
      return WhileNode(c, self.B())
    raise SyntaxError("Err")
  def E(self):
    n = self.T()
    while self.cur_t() in ("+", "-"):
      o = self.advance().type
      n = BinOpNode(o, n, self.T())
    return n
  def T(self):
    n = self.F()
    while self.cur_t() in ("*", "/"):
      o = self.advance().type
      n = BinOpNode(o, n, self.F())
    return n
  def F(self):
    t = self.cur()
    if not t: raise SyntaxError("Err")
    if t.type == "NUMBER":
      self.advance()
      return NumNode(t.value)
    if t.type == "ID":
      self.advance()
      return VarNode(t.value)
    if t.type == "(":
      self.advance(); n = self.E(); self.expect(")")
      return n
    raise SyntaxError("Err")
if __name__ == "__main__":
  parser = argparse.ArgumentParser()
  parser.add_argument('filename'); source = ""
  with open(parser.parse_args().filename, "r",
      encoding="utf-8") as f1:
    source = f1.read()
  interp = Interpreter(source)
  program_ast = interp.parse()
  program_ast.eval(interp.vars)


# Thanks to Chatgpt.com, Grok.com(X.Ai) and Gemini AI for writing most of this code
# Please remove all comments in following python code and format it with minimized format like LLVM or google format (for clang_format) for the least size of program as much as possible.
