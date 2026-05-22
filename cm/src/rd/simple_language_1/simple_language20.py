from sly import Lexer

class BasicLexer(Lexer):
    tokens = {BEGIN, END, LET, PRINT, WHILE, ID, NUMBER, NEWLINE}
    literals = {'+', '-', '*', '/', '=', '(', ')'}
    ignore = ' \t'

    # Strictly handle keywords within ID to avoid priority collision
    @_(r'[A-Za-z_][A-Za-z0-9_]*')
    def ID(self, t):
        if t.value in {'BEGIN', 'END', 'LET', 'PRINT', 'WHILE'}:
            t.type = t.value
        return t

    @_(r'\d+')
    def NUMBER(self, t):
        t.value = int(t.value)
        return t

    @_(r'\n+')
    def NEWLINE(self, t):
        return t

    def error(self, t):
        raise SyntaxError(f"Illegal character '{t.value[0]}' at index {self.index}")

# --- ABSTRACT SYNTAX TREE (AST) NODES ---
class BlockNode:
    def __init__(self, statements): self.statements = statements
    def eval(self, env):
        for stmt in self.statements: stmt.eval(env)

class LetNode:
    def __init__(self, name, expr): self.name, self.expr = name, expr
    def eval(self, env): env[self.name] = self.expr.eval(env)

class PrintNode:
    def __init__(self, expr): self.expr = expr
    def eval(self, env): print(self.expr.eval(env))

class WhileNode:
    def __init__(self, cond, body): self.cond, self.body = cond, body
    def eval(self, env):
        while self.cond.eval(env) != 0:
            self.body.eval(env)

class BinOpNode:
    def __init__(self, op, left, right): self.op, self.left, self.right = op, left, right
    def eval(self, env):
        l, r = self.left.eval(env), self.right.eval(env)
        if self.op == '+': return l + r
        if self.op == '-': return l - r
        if self.op == '*': return l * r
        if self.op == '/':
            if r == 0: raise ZeroDivisionError("division by zero")
            return l // r

class NumNode:
    def __init__(self, val): self.val = val
    def eval(self, env): return self.val

class VarNode:
    def __init__(self, name): self.name = name
    def eval(self, env): return env.get(self.name, 0)


# --- PARSER / INTERPRETER ---
class Interpreter:
    def __init__(self, source):
        self.tokens = list(BasicLexer().tokenize(source))
        self.pos = 0
        self.vars = {}

    def cur(self): return self.tokens[self.pos] if self.pos < len(self.tokens) else None
    def cur_type(self): return self.cur().type if self.cur() else 'EOF'
    def advance(self): t = self.cur(); self.pos += 1; return t

    def match(self, kind):
        if self.cur_type() == kind: return self.advance()
        return None

    def expect(self, kind):
        t = self.match(kind)
        if not t: raise SyntaxError(f"Expected {kind}, got {self.cur_type()}")
        return t

    def parse(self):
        # Clean out any leading whitespace newlines before reading the root block
        while self.cur_type() == 'NEWLINE': self.advance()
        ast = self.B()
        while self.cur_type() == 'NEWLINE': self.advance()
        if self.cur() is not None: raise SyntaxError(f"Unexpected trailing token {self.cur_type()}")
        return ast

    def B(self):
        self.expect('BEGIN')
        self.expect('NEWLINE')
        statements = self.M()
        self.expect('END')
        return BlockNode(statements)

    def M(self):
        statements = []
        while self.cur_type() in ('LET', 'PRINT', 'WHILE', 'NEWLINE'):
            if self.cur_type() == 'NEWLINE':
                self.advance()
                continue
            statements.append(self.L())
            # Handle statement terminators safely
            if self.cur_type() == 'NEWLINE':
                self.advance()
        return statements

    def L(self):
        if self.match('LET'):
            name = self.expect('ID').value
            self.expect('=')
            expr = self.E()
            return LetNode(name, expr)
        if self.match('PRINT'):
            return PrintNode(self.E())
        if self.match('WHILE'):
            cond = self.E()
            # Clean up the flexible grammar newline layout around internal block initializations
            while self.cur_type() == 'NEWLINE': self.advance()
            body = self.B()
            return WhileNode(cond, body)
        raise SyntaxError(f"Unexpected token {self.cur_type()}")

    def E(self):
        node = self.T()
        while self.cur_type() in ('+', '-'):
            op = self.advance().type
            node = BinOpNode(op, node, self.T())
        return node

    def T(self):
        node = self.F()
        while self.cur_type() in ('*', '/'):
            op = self.advance().type
            node = BinOpNode(op, node, self.F())
        return node

    def F(self):
        t = self.cur()
        if t is None: raise SyntaxError("Unexpected EOF")
        if t.type == 'NUMBER':
            self.advance()
            return NumNode(t.value)
        if t.type == 'ID':
            self.advance()
            return VarNode(t.value)
        if t.type == '(':
            self.advance()
            node = self.E()
            self.expect(')')
            return node
        raise SyntaxError(f"Unexpected token {t.type}")

# --- EXECUTION ---
source = """BEGIN
LET X = 5
PRINT X

WHILE X
BEGIN
PRINT X
LET X = X - 1
END

PRINT 999
END"""

interpreter = Interpreter(source)
program_ast = interpreter.parse()
program_ast.eval(interpreter.vars)

# Thanks to Chatgpt.com, Grok.com(X.Ai) and Gemini AI for writing most of this code
