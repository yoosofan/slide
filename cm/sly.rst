:data-transition-duration: 1000
:skip-help: true
:css: ./style.css
:substep: true
:slide-numbers: true

.. role:: ltr
    :class: ltr

----

Lexical Analyzer
===================
SLY (Sly Lex-Yacc)
--------------------
Ahmad Yoosofan

Compiler course

University of Kashan

* https://yoosofan.github.io/course/compiler.html

----

.. :

  PLY
  ================
  * http://www.dabeaz.com/ply/
  * https://github.com/dabeaz/ply
  * https://ply.readthedocs.io/en/latest/
  * zero-dependency Python implementation of the traditional parsing tools lex and yacc
  * Using Python Langauge which is very good at text processing.
  * Based on Old Yacc notation.
  * Straight implementation of Lex/Yacc
  * Support old version of Python
  * It's free software that you are free to copy and modify in any way that makes sense.

Sly
=====
* https://github.com/dabeaz/sly
* https://sly.readthedocs.io/en/latest/
* zero-dependency Python implementation of the traditional parsing tools lex and yacc
* Using Python Langauge which is very good at text processing.
* SLY provides very extensive error reporting and diagnostic information to assist in parser construction.
* SLY provides full support for empty productions, error recovery, precedence specifiers, and moderately ambiguous grammars.
* SLY uses various Python metaprogramming features to specify lexers and parsers.
* A moderinized form of PLY (It is not follow the same rule of old Lex/Yacc)
* SLY requires the use of Python 3.6 or greater.
* 3-BSD like license

Install SLY
---------------
.. code:: console

  # install python (already installed in most Linux)
  # install pip3
  # sudo apt-get install python3-pip # for Debian and Ubuntu
  
  pip3 install sly
  
  # or just copy sly files in the same folder of the project

----

:class: t2c

Simple Lexer Code
================================
.. include:: src/sly/222.plus.py
  :code: python
  :number-lines:

.. code:: console
  :number-lines:
  :class: substep

  python3 222.plus.py 

  type='NUMBER', value='3'
  type='PLUS', value='+'
  type='NUMBER', value='42'
  type='PLUS', value='+'
  type='NUMBER', value='8'
  

----

:class: t2c

Simple Error handling
================================
.. include:: src/sly/233.error.py
  :code: python
  :number-lines:

.. code:: console
  :number-lines:
  :class: substep

  python3 233.error.py 

  type='NUMBER', value='3'
  type='PLUS', value='+'
  type='NUMBER', value='42'
  type='PLUS', value='+'
  type='NUMBER', value='8'
  Illegal character '.'
  type='NUMBER', value='43'
  type='PLUS', value='+'
  type='NUMBER', value='456'

----

:class: t2c

Converting Value Based on Type
================================
.. include:: src/sly/244.plus.py
  :code: python
  :number-lines:

.. code:: console
  :number-lines:
  :class: substep

  python3 244.plus.py 

  number: 3
  type='NUMBER', value=3
  type='PLUS', value='+'
  number: 42
  type='NUMBER', value=42
  type='PLUS', value='+'
  number: 8
  type='NUMBER', value=8

----

:class: t2c

Index of Token in Buffer
================================
.. include:: src/sly/255.index.py
  :code: python
  :number-lines:

.. code:: console
  :number-lines:
  :class: substep

  python3 255.index.py 

  type='NUMBER', value=3, index=0
  type='PLUS', value='+', index=2
  type='NUMBER', value=42, index=4
  type='PLUS', value='+', index=7
  type='NUMBER', value=8, index=8

----

:class: t2c

Just Number Function
================================
.. include:: src/sly/264.just.number.function.py
  :code: python
  :number-lines:

.. code:: console
  :number-lines:
  :class: substep

  python3 264.just.number.function.py

  type='NUMBER', value=3, index=0
  type='PLUS', value='+', index=2
  type='NUMBER', value=42, index=4
  type='PLUS', value='+', index=7
  type='NUMBER', value=8, index=8

----

:class: t2c

Ignore New Line and One Line Comment
========================================
.. include:: src/sly/274.ignore.lines.py
  :code: python
  :number-lines:

.. code:: console
  :number-lines:
  :class: substep

  python3 274.ignore.lines.py

  type='NUMBER', value=3, index=0
  type='PLUS', value='+', index=2
  type='NUMBER', value=42, index=4
  type='PLUS', value='+', index=7
  type='NUMBER', value=8, index=8
  type='PLUS', value='+', index=30
  type='NUMBER', value=46, index=32
  type='PLUS', value='+', index=34
  type='NUMBER', value=980, index=35
  type='PLUS', value='+', index=38
  type='NUMBER', value=51, index=39
  type='PLUS', value='+', index=41
  type='NUMBER', value=343, index=64
  type='PLUS', value='+', index=67
  type='NUMBER', value=43, index=68

----

:class: t2c

Counting Lines (Error)
========================================
.. include:: src/sly/280.lineno.wrong.py
  :code: python
  :number-lines:

.. code:: console
  :number-lines:
  :class: substep

  python3 280.lineno.wrong.py

  type='NUMBER', value=3, index=0, lineno=1
  type='PLUS', value='+', index=2, lineno=1
  type='NUMBER', value=42, index=4, lineno=1
  type='PLUS', value='+', index=7, lineno=1
  type='NUMBER', value=8, index=8, lineno=1
  type='PLUS', value='+', index=30, lineno=1
  type='NUMBER', value=46, index=32, lineno=1
  type='PLUS', value='+', index=34, lineno=1
  type='NUMBER', value=980, index=35, lineno=1
  type='PLUS', value='+', index=38, lineno=1
  type='NUMBER', value=51, index=39, lineno=1
  type='PLUS', value='+', index=41, lineno=1
  type='NUMBER', value=343, index=64, lineno=1
  type='PLUS', value='+', index=67, lineno=1
  type='NUMBER', value=43, index=68, lineno=1
    
----

:class: t2c

Line Number of Tokens
================================
.. include:: src/sly/284.lineno.py
  :code: python
  :number-lines:

.. code:: console
  :number-lines:
  :class: substep

  python3 284.lineno.py

  type='NUMBER', value=3, index=0, lineno=1
  type='PLUS', value='+', index=2, lineno=1
  type='NUMBER', value=42, index=4, lineno=1
  type='PLUS', value='+', index=7, lineno=1
  type='NUMBER', value=8, index=8, lineno=1
  type='PLUS', value='+', index=30, lineno=2
  type='NUMBER', value=46, index=32, lineno=2
  type='PLUS', value='+', index=34, lineno=2
  type='NUMBER', value=980, index=35, lineno=2
  type='PLUS', value='+', index=38, lineno=2
  type='NUMBER', value=51, index=39, lineno=2
  type='PLUS', value='+', index=41, lineno=2
  type='NUMBER', value=343, index=64, lineno=3
  type='PLUS', value='+', index=67, lineno=3
  type='NUMBER', value=43, index=68, lineno=3
  
----

:class: t2c

Token Remapping
================================
.. include:: src/sly/322.token.remapping.py
  :code: python
  :number-lines:

.. code:: console
  :number-lines:
  :class: substep

  python3 322.token.remapping.py

  type='ID', value='count'
  type='PLUS', value='+'
  type='IF', value='if'
  type='PLUS', value='+'
  type='ID', value='ifelse'
  type='PLUS', value='+'
  type='NUMBER', value=8
  type='PLUS', value='+'
  type='WHILE', value='while'

----

:class: t2c

More Token Type
================================
.. include:: src/sly/524.more.tokens.py
  :code: python
  :number-lines:

.. code:: console
  :number-lines:
  :class: substep

  python3 524.more.tokens.py

  type='ID', value='x'
  type='ASSIGN', value='='
  type='NUMBER', value='3'
  type='PLUS', value='+'
  type='NUMBER', value='42'
  type='TIMES', value='*'
  type='LPAREN', value='('
  type='ID', value='s'
  type='MINUS', value='-'
  type='ID', value='t'
  type='RPAREN', value=')'

.. :

  Regular expression patterns are compiled using the re.VERBOSE flag which can be used to help readability. However, unescaped whitespace is ignored and comments are allowed in this mode. If your pattern involves whitespace, make sure you use \s. If you need to match the # character, use [#] or \#.

----

:class: t2c

Longer Tokens before Short Tokens
===================================
.. include:: src/sly/544.longer.before.shorter.py
  :code: python
  :number-lines:

.. code:: console
  :number-lines:
  :class: substep

  python3 544.longer.before.shorter.py

  type='ID', value='x'
  type='ASSIGN', value='='
  type='NUMBER', value='3'
  type='PLUS', value='+'
  type='NUMBER', value='42'
  type='TIMES', value='*'
  type='LPAREN', value='('
  type='ID', value='s'
  type='EQ', value='=='
  type='ID', value='t'
  type='RPAREN', value=')'

----

:class: t2c

Longer Tokens before Short Tokens(Error)
===============================================
.. include:: src/sly/555.longer.before.shorter.error.py
  :code: python
  :number-lines:

.. code:: console
  :number-lines:
  :class: substep

  python3 555.longer.before.shorter.error.py

  type='ID', value='x'
  type='ASSIGN', value='='
  type='NUMBER', value='3'
  type='PLUS', value='+'
  type='NUMBER', value='42'
  type='TIMES', value='*'
  type='LPAREN', value='('
  type='ID', value='s'
  type='ASSIGN', value='='
  type='ASSIGN', value='='
  type='ID', value='t'
  type='RPAREN', value=')'

----

:class: t2c

Adding Match Actions
===============================================
.. include:: src/sly/575.adding.match.actions.py
  :code: python
  :number-lines:

.. code:: console
  :number-lines:
  :class: substep

  python3 575.adding.match.actions.py

  type='ID', value='x'
  type='ASSIGN', value='='
  type='NUMBER', value=3
  type='PLUS', value='+'
  type='NUMBER', value=162
  type='NUMBER', value=33
  type='ID', value='ab'
  type='TIMES', value='*'
  type='LPAREN', value='('
  type='ID', value='s'
  type='ASSIGN', value='='
  type='ASSIGN', value='='
  type='ID', value='t'
  type='RPAREN', value=')'

----

:class: t2c

Literals(I)
===============================================
.. include:: src/sly/584.literal.I.py
  :code: python
  :number-lines:

.. code:: console
  :number-lines:
  :class: substep

  python3 584.literal.I.py

  type='ID', value='x'
  type='+', value='+'
  type='ASSIGN', value='='
  type='(', value='('
  type='NUMBER', value='234'
  type='+', value='+'
  type='ID', value='d'
  type='ID', value='t'
  type=')', value=')'
  type='ID', value='aa'
  type=')', value=')'

----

:class: t2c

Literals(II) - Do Something
===============================================
.. include:: src/sly/588.literal.II.py
  :code: python
  :number-lines:

.. code:: console
  :number-lines:
  :class: substep

  python3 588.literal.II.py

  type='ID', value='x'
  type='+', value='+'
  type='ASSIGN', value='='
  nesting level:  1
  type='{', value='{'
  type='ID', value='s'
  type='(', value='('
  nesting level:  2
  type='{', value='{'
  type='ID', value='t'
  type=')', value=')'
  nesting level:  1
  type='}', value='}'
  type='ID', value='aa'
  nesting level:  0
  type='}', value='}'

----

:class: t2c

Complete Example
===============================================
.. include:: src/sly/624.complete.example.py
  :code: python
  :number-lines:
  :start-line: 1
  
.. code:: console
  :number-lines:
  :class: substep

  python3 624.py

  ( ID , x , 1 , 0 )
  ( ASSIGN , = , 1 , 2 )
  ( FLOAT , 0.1 , 1 , 4 )
  ( ; , ; , 1 , 7 )
  ( WHILE , while , 2 , 9 )
  ( ( , ( , 2 , 15 )
  ( ID , x , 2 , 16 )
  ( LT , < , 2 , 18 )
  ( INT , 10 , 2 , 20 )
  ( ) , ) , 2 , 22 )
  ( { , { , 2 , 24 )
  ( PRINT , print , 3 , 28 )
  ( ID , x , 3 , 34 )
  Line 3: Bad character ':'
  ( ID , x , 4 , 50 )
  ( ASSIGN , = , 4 , 52 )
  ( ID , x , 4 , 54 )
  ( + , + , 4 , 56 )
  ( INT , 1 , 4 , 58 )
  ( ; , ; , 4 , 59 )
  ( } , } , 5 , 61 )

----

Syntax Analysis(Recursive Descendant)
==========================================

.. :

  # http://cs.indstate.edu/~jkinne/cs420-s2019/code/?view=./sly-calc.py
  
  # note - use python3
  # note - example from https://github.com/dabeaz/sly
  # note - type ctrl-d as the end of input.

  # notes on lexer
  # - tokens are compiled with re.verbose flag
  #   (comments with #, gets rid of white space).
  #   If you need to match # use \#
  # - tokens matched in order in your file.
  #   If you want to use == and =, put the rule for == first.
  # - sometimes there is more than one way to do something in the
  #   lexer.  for example, can have a separate rule for each keyword
  #   or catch them under a generic "ID" or "NAME" rule and use "token remapping"

  # -----------------------------------------------------------------------------
  # calc.py
  # -----------------------------------------------------------------------------

  # package isn't installed at the moment, so add the path so python can find it
  import sys
  slyPath = "/u1/h0/jkinne/public_html/cs420-s2019/code/sly-0.4"
  sys.path.append(slyPath)


  from sly import Lexer, Parser

  class CalcLexer(Lexer):
      tokens = { NAME, NUMBER, PLUS, TIMES, MINUS, DIVIDE, ASSIGN, LPAREN, RPAREN, MOD, EQUALS, EXPONENT,
                 INC, # IF, THEN, # note - if-then will be in sly-calc2.py
                 PROMPT_FLIP}
      ignore = ' \t'

      # Tokens
      EXPONENT = r'\*\*'
      EQUALS = r'=='
      
      MOD = r'%'
      
      NAME = r'[a-zA-Z_][a-zA-Z0-9_]*'
      NUMBER = r'\d+'

      NAME['inc'] = INC 
      #NAME['if'] = IF # note - if-then will be in sly-calc2.py
      #NAME['then'] = THEN
      NAME['prompt_flip'] = PROMPT_FLIP

      # Special symbols
      PLUS = r'\+'
      MINUS = r'-'
      TIMES = r'\*'
      DIVIDE = r'/'
      ASSIGN = r'='
      LPAREN = r'\('
      RPAREN = r'\)'
      
      # Ignored pattern
      ignore_newline = r'\n+'

      # Extra action for newlines
      def ignore_newline(self, t):
          self.lineno += t.value.count('\n')

      def error(self, t):
          print("Illegal character '%s'" % t.value[0])
          self.index += 1

  class CalcParser(Parser):
      tokens = CalcLexer.tokens

      precedence = (
          # ('left', IF, THEN), # note - if-then will be in sly-calc2.py
          ('left', EQUALS),
          ('left', PLUS, MINUS),
          ('left', TIMES, DIVIDE, MOD),
          ('right', UMINUS),
          ('right', EXPONENT)
          )

      def __init__(self):
          self.names = { }
          self.prompt = True
          self.debug = False

      @_('expr')
      def statement(self, p):
          print(p.expr)

      @_('PROMPT_FLIP')
      def statement(self, p):
          self.prompt = not self.prompt

      @_('INC NAME')
      def statement(self, p):
          try:
              self.names[p.NAME] += 1
          except LookupError:
              print(f'Undefined name {p.NAME!r}')
          
      @_('NAME ASSIGN expr')
      def statement(self, p):
          self.names[p.NAME] = p.expr

      # note - if-then will be in sly-calc2.py
      #@_('IF expr THEN statement')
      #def statement(self, p):
      #    if p.expr:
      #        self.statement(p.statement)
              #NOTE - this will be fixed in like 15 minutes.
              # still working on it...
              # actually, needs a bit of reworking of things.  so doing that...

      @_('expr EXPONENT expr')
      def expr(self, p):
          return p.expr0 ** p.expr1
      
      @_('expr PLUS expr')
      def expr(self, p):
          return p.expr0 + p.expr1

      @_('expr MINUS expr')
      def expr(self, p):
          return p.expr0 - p.expr1

      @_('expr TIMES expr')
      def expr(self, p):
          return p.expr0 * p.expr1

      @_('expr DIVIDE expr')
      def expr(self, p):
          return p.expr0 / p.expr1

      @_('expr MOD expr')
      def expr(self, p):
          return p.expr0 % p.expr1

      @_('expr EQUALS expr')
      def expr(self, p):
          return p.expr0 == p.expr1

      @_('MINUS expr %prec UMINUS')
      def expr(self, p):
          return -p.expr

      @_('LPAREN expr RPAREN')
      def expr(self, p):
          return p.expr

      @_('NUMBER')
      def expr(self, p):
          return int(p.NUMBER)

      @_('NAME')
      def expr(self, p):
          try:
              return self.names[p.NAME]
          except LookupError:
              print(f'Undefined name {p.NAME!r}')
              return 0
          

  if __name__ == '__main__':
      lexer = CalcLexer()
      parser = CalcParser()
      while True:
          try:
              if parser.prompt:
                  text = input('calc > ')
              else:
                  text = input('')
          except EOFError:
              break
          if text:
              if parser.debug:
                  print("text is - " + text)
                  x = list(lexer.tokenize(text))
                  print(x)
                  x = iter(x)
                  parser.parse(x)
              else:
                  parser.parse(lexer.tokenize(text))
                  
                  


.. :

  # http://cs.indstate.edu/~jkinne/cs420-s2019/code/?view=./sly-prog.py
  
  # note - use python3
  # note - example from https://github.com/dabeaz/sly
  # note - type ctrl-d as the end of input.

  # notes on lexer
  # - tokens are compiled with re.verbose flag
  #   (comments with #, gets rid of white space).
  #   If you need to match # use \#
  # - tokens matched in order in your file.
  #   If you want to use == and =, put the rule for == first.
  # - sometimes there is more than one way to do something in the
  #   lexer.  for example, can have a separate rule for each keyword
  #   or catch them under a generic "ID" or "NAME" rule and use "token remapping"

  # -----------------------------------------------------------------------------
  # calc.py
  # -----------------------------------------------------------------------------

  # package isn't installed at the moment, so add the path so python can find it
  import sys
  slyPath = "/u1/h0/jkinne/public_html/cs420-s2019/code/sly-0.4"
  sys.path.append(slyPath)


  from sly import Lexer, Parser

  class CalcLexer(Lexer):
      tokens = { NAME, NUMBER, PLUS, TIMES, MINUS, DIVIDE, ASSIGN, LPAREN, RPAREN,
                 IF, THEN, WHILE, DO, PRINT, BEGIN, END}
      ignore = ' \t'
      ignore_comment = r'\#.*'

      # Tokens
      NAME = r'[a-zA-Z_][a-zA-Z0-9_]*'
      NUMBER = r'\d+'

      NAME['if'] = IF 
      NAME['then'] = THEN
      NAME['while'] = WHILE
      NAME['do'] = DO
      NAME['begin'] = BEGIN
      NAME['end'] = END
      NAME['print'] = PRINT

      # Special symbols
      PLUS = r'\+'
      MINUS = r'-'
      TIMES = r'\*'
      DIVIDE = r'/'
      ASSIGN = r'='
      LPAREN = r'\('
      RPAREN = r'\)'
      
      # Ignored pattern
      ignore_newline = r'\n+'

      # Extra action for newlines
      def ignore_newline(self, t):
          self.lineno += t.value.count('\n')

      def error(self, t):
          print("Illegal character '%s'" % t.value[0])
          self.index += 1

  class CalcParser(Parser):
      tokens = CalcLexer.tokens

      precedence = (
          # ('left', IF, THEN), # note - if-then will be in sly-calc2.py
          ('left', PLUS, MINUS),
          ('left', TIMES, DIVIDE),
          ('right', UMINUS),
          )

      def __init__(self):
          self.names = { }
          self.prompt = True

      @_('expr')
      def statement(self, p):
          return ('statement-expr', p.expr)

      @_('BEGIN statement_list END')
      def statement(self, p):
          return ('statement-compound', p.statement_list)

      @_('statement statement_list')
      def statement_list(self, p):
          return ('statement-list', p.statement, p.statement_list)

      @_('')
      def statement_list(self, p):
          return ('statement-list-end')

      @_('NAME ASSIGN expr')
      def statement(self, p):
          return ('assign', p.NAME, p.expr)

      @_('IF expr THEN statement')
      def statement(self, p):
          return ('if-then', p.expr, p.statement)

      @_('WHILE expr DO statement')
      def statement(self, p):
          return ('while', p.expr, p.statement)

      @_('PRINT expr') # for printing, since we're not always printing the result any more
      def statement(self, p):
          return ('print', p.expr)

      @_('') # basically epsilon, for comment lines that don't parse to anything
      def statement(self, p):
          return
      
      @_('expr PLUS expr')
      def expr(self, p):
          return ('plus', p.expr0, p.expr1)

      @_('expr MINUS expr')
      def expr(self, p):
          return ('minus', p.expr0, p.expr1)

      @_('expr TIMES expr')
      def expr(self, p):
          return ('times', p.expr0, p.expr1)

      @_('expr DIVIDE expr')
      def expr(self, p):
          return ('divide', p.expr0, p.expr1)

      @_('MINUS expr %prec UMINUS')
      def expr(self, p):
          return ('uminus', p.expr)

      @_('LPAREN expr RPAREN')
      def expr(self, p):
          return ('paren', p.expr)

      @_('NUMBER')
      def expr(self, p):
          return ('number', p.NUMBER)

      @_('NAME')
      def expr(self, p):
          return ('name', p.NAME)

  def evaluate(tree):
      global names

      if tree == None: return
      
      rule = tree[0]
      if rule == 'statement-expr':
          value = evaluate(tree[1])
          return value
      elif rule == 'assign':
          value = evaluate(tree[2])
          name = tree[1]
          names[name] = value
          return value
      elif rule == 'print':
          value = evaluate(tree[1])
          print(value)
          return value
      elif rule == 'times':
          return evaluate(tree[1]) * evaluate(tree[2])
      elif rule == 'plus':
          return evaluate(tree[1]) + evaluate(tree[2])
      elif rule == 'minus':
          return evaluate(tree[1]) - evaluate(tree[2])
      elif rule == 'divide':
          return evaluate(tree[1]) / evaluate(tree[2])
      elif rule == 'uminus':
          return -evaluate(tree[1])
      elif rule == 'number':
          return int(tree[1])
      elif rule == 'name':
          return names[tree[1]]
      elif rule == 'paren':
          return evaluate(tree[1])
      elif rule == 'if-then':
          value = evaluate(tree[1])
          if value:
              return evaluate(tree[2])
          else:
              return 0
      elif rule == 'while':
          while evaluate(tree[1]):
              evaluate(tree[2])
      
  if __name__ == '__main__':
      lexer = CalcLexer()
      parser = CalcParser()
      names = {}
      text = sys.stdin.read()
      tree = parser.parse(lexer.tokenize(text))
      evaluate(tree)
  