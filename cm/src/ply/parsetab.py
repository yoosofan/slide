
# parsetab.py
# This file is automatically generated. Do not edit.
# pylint: disable=W,C,R
_tabversion = '3.10'

_lr_method = 'LALR'

_lr_signature = 'ASG DIV ID LPAR MINUS MUL NUMBER PLUS RPARS : ES : L L : ID ASG EE : E PLUS TE : E MINUS TE : TT : T MUL FT : T DIV FT : FF : NUMBERF : IDF : LPAR E RPAR'
    
_lr_action_items = {'ID':([0,8,9,10,11,12,13,],[5,15,15,15,15,15,15,]),'NUMBER':([0,8,9,10,11,12,13,],[7,7,7,7,7,7,7,]),'LPAR':([0,8,9,10,11,12,13,],[8,8,8,8,8,8,8,]),'$end':([1,2,3,4,5,6,7,15,16,17,18,19,20,21,],[0,-1,-2,-6,-11,-9,-10,-11,-4,-5,-7,-8,-3,-12,]),'PLUS':([2,4,5,6,7,14,15,16,17,18,19,20,21,],[9,-6,-11,-9,-10,9,-11,-4,-5,-7,-8,9,-12,]),'MINUS':([2,4,5,6,7,14,15,16,17,18,19,20,21,],[10,-6,-11,-9,-10,10,-11,-4,-5,-7,-8,10,-12,]),'RPAR':([4,6,7,14,15,16,17,18,19,21,],[-6,-9,-10,21,-11,-4,-5,-7,-8,-12,]),'MUL':([4,5,6,7,15,16,17,18,19,21,],[11,-11,-9,-10,-11,11,11,-7,-8,-12,]),'DIV':([4,5,6,7,15,16,17,18,19,21,],[12,-11,-9,-10,-11,12,12,-7,-8,-12,]),'ASG':([5,],[13,]),}

_lr_action = {}
for _k, _v in _lr_action_items.items():
   for _x,_y in zip(_v[0],_v[1]):
      if not _x in _lr_action:  _lr_action[_x] = {}
      _lr_action[_x][_k] = _y
del _lr_action_items

_lr_goto_items = {'S':([0,],[1,]),'E':([0,8,13,],[2,14,20,]),'L':([0,],[3,]),'T':([0,8,9,10,13,],[4,4,16,17,4,]),'F':([0,8,9,10,11,12,13,],[6,6,6,6,18,19,6,]),}

_lr_goto = {}
for _k, _v in _lr_goto_items.items():
   for _x, _y in zip(_v[0], _v[1]):
       if not _x in _lr_goto: _lr_goto[_x] = {}
       _lr_goto[_x][_k] = _y
del _lr_goto_items
_lr_productions = [
  ("S' -> S","S'",1,None,None,None),
  ('S -> E','S',1,'p_S','160.E.T.F.Variable.py',26),
  ('S -> L','S',1,'p_SL','160.E.T.F.Variable.py',29),
  ('L -> ID ASG E','L',3,'p_L','160.E.T.F.Variable.py',32),
  ('E -> E PLUS T','E',3,'p_E_plus_T','160.E.T.F.Variable.py',44),
  ('E -> E MINUS T','E',3,'p_E_MINUS_T','160.E.T.F.Variable.py',48),
  ('E -> T','E',1,'p_E_T','160.E.T.F.Variable.py',52),
  ('T -> T MUL F','T',3,'p_T_MUL_F','160.E.T.F.Variable.py',56),
  ('T -> T DIV F','T',3,'p_T_DIV_F','160.E.T.F.Variable.py',60),
  ('T -> F','T',1,'p_T_F','160.E.T.F.Variable.py',65),
  ('F -> NUMBER','F',1,'p_F_a','160.E.T.F.Variable.py',69),
  ('F -> ID','F',1,'p_F_id','160.E.T.F.Variable.py',73),
  ('F -> LPAR E RPAR','F',3,'p_F_lpar_E_rpar','160.E.T.F.Variable.py',78),
]
