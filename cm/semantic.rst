:data-transition-duration: 1000
:skip-help: true
:css: slide_style.css semantic.css
:substep: true
:slide-numbers: true

.. role:: raw-html(raw)
   :format: html


----

Semantic Analyzer
===================
Ahmad Yoosofan

Compiler course

University of Kashan

.. :

  https://github.com/magjac/d3-graphviz
  https://bl.ocks.org/magjac/a23d1f1405c2334f288a9cca4c0ef05b
  https://codepen.io/tlk/pen/rOpaEr
  http://viz-js.com/
  https://stackoverflow.com/questions/6344318/pure-javascript-graphviz-equivalent
  https://stackoverflow.com/questions/18444406/how-do-i-use-special-characters-in-a-dot-file-node-id
  https://www.geeksforgeeks.org/bottom-up-or-shift-reduce-parsers-set-2/
  https://renenyffenegger.ch/notes/tools/Graphviz/examples/index
  https://sketchviz.com/graphviz-examples
  https://github.com/Chiel92/graphviz/blob/master/doc/Dot.ref
  https://github.com/timtadh/dot
  https://stackoverflow.com/questions/49224484/how-to-specify-in-dot-file-that-edges-go-upwards/49226085
  https://en.wikipedia.org/wiki/DOT_(graph_description_language)
  https://en.wikipedia.org/wiki/DOT_(graph_description_language)
  https://renenyffenegger.ch/notes/tools/Graphviz/examples/index
  https://sketchviz.com/graphviz-examples
  dot convert to image


----

:id: Ea-LR-parse-id

#. E → E + a
#. E → a

..  csv-table:: 
    :header: ` `, a, `+`, `$`, `E`
    :class: smallerelementwithfullborder

    0, s2, , , 1
    1, , s3, acc, 
    2, , r2, r2, 
    3, s4, , ,
    4, , r1, r1, 

..  csv-table:: 
    :header: Stack, Input, Action
    :class: smallerelementwithfullborder yoosofantextalignleft

    :math:`I_0`, 8+9$,
    :math:`I_0` 8 :math:`I_2`, +9$, r2(E → a)
    :math:`I_0` E(8) :math:`I_1`, +9$
    :math:`I_0` E(8) :math:`I_1` + :math:`I_3`, 9$
    :math:`I_0` E(8) :math:`I_1` + :math:`I_3` 9 :math:`I_4`, $, r1(E→E+a)
    :math:`I_0` E(17) :math:`I_1`, $
    acc

.. image:: img/semantic/Ea-LR-parse-id.png

.. :

    :height: 128px
    :width: 122px

----

:id: Ea-LR-parse-semantic-id

..  csv-table:: 
    :header: ` `, Production, Semantic
    :class: smallerelementwithfullborder yoosofantextalignleft

    1, "E → a", "E.val = a"
    2, "E → E + a", "E.val = :math:`E_1`.val + a"


..  csv-table:: 
    :header: ` `, a, `+`, `$`, `E`
    :class: smallerelementwithfullborder

    0, s2, , , 1
    1, , s3, acc, 
    2, , r2, r2, 
    3, s4, , ,
    4, , r1, r1, 

..  csv-table:: 
    :header: Stack, Input, Action
    :class: smallerelementwithfullborder yoosofantextalignleft

    :math:`I_0`, 8+9+2$,
    :math:`I_0` 8 :math:`I_2`, +9+2$, r2(E → a)
    :math:`I_0` E(8) :math:`I_1`, +9+2$,
    :math:`I_0` E(8) :math:`I_1` + :math:`I_3`, 9+2$,
    :math:`I_0` E(8) :math:`I_1` + :math:`I_3` 9 :math:`I_4`, +2$, r1(E→E+a)
    :math:`I_0` E(17) :math:`I_1` + :math:`I_3`, 2$,
    :math:`I_0` E(17) :math:`I_1` + :math:`I_3` 2 :math:`I_4`, $, r1(E→E+a)
    :math:`I_0` E(19) :math:`I_1`, $,
    acc

.. image:: img/semantic/Ea-LR-parse-id-semantic.png
    :width: 340px
    :height: 341px



----

Anotated parse tree
==========================
.. image:: img/semantic/anotated_parse_tree.png
    :align: center

----

.. image:: img/semantic/Anotated_parse_tree1.png
    :align: center

----

:id: ply-calc220-id

.. include:: src/semantic/ply_calc220.py
    :code: python
    :number-lines:
    :start-line: 0
    :end-line: 18

.. include:: src/semantic/ply_calc220.py
    :code: python
    :number-lines:
    :start-line: 60
    :end-line: 69

----

:id: ply-calc220-2-id

.. include:: src/semantic/ply_calc220.py
    :code: python
    :number-lines:
    :start-line: 18
    :end-line: 38

.. include:: src/semantic/ply_calc220.py
    :code: python
    :number-lines:
    :start-line: 38
    :end-line: 58

.. image:: img/semantic/anotated_parse_tree.png
    :height: 300px


----

Syntax-Directed Definition
=============================
..  csv-table:: 
    :header: Production, Semantic Rules
    :class: smallerelementwithfullborder yoosofantextalignleft center

    S → E n, print(E.val)
    E → E1 + T, E.val = E1.val + T.val
    E → T, E.val = T.val
    T → T1 * F, T.val = T1.val * F.val
    T → F, T.val = F.val
    F → ( E ), F.val = E.val
    F → digit, F.val = digit.lexval

----

Dependency Graph
=========================

.. image:: img/semantic/dependency_graph1.png
    :align: center

----

:id: etf-code-id

..  csv-table:: 
    :header: Production, Semantic Rules
    :class: smallerelementwithfullborder yoosofantextalignleft

    "E → E1 + T", "E.loc=newtemp() , :raw-html:`<br />` E.code = E1.code || T.code || 'add E.loc, E1.loc, T.loc'"
    "E → T", "E.loc = T.loc, E.code=T.code"
    "T → T1 * F", "T.loc=newtemp() , :raw-html:`<br />` T.code = T1.code || F.code  || 'mult T.loc, T1.loc, F.loc'"
    "T → F", "T.loc = F.loc, T.code=F.code "
    "F → ( E )", "F.loc = E.loc,  F.code=E.code"
    "F → id", "F.loc = id.name,  F.code= “” "


* 3 * 4 + 5
* t1 ← 3 * 4,  mult t1, 3 , 4
* t2 ← t1 + 5, add t2, t1, 5

* mult t1, 3 , 4
* add t2, t1, 5

* (3 * 4) + 5
* F → (E)
* E → T
* T → T * F
* t1 ← 3 * 4,  mult t1, 3 , 4
* t2 ← t1 + 5, add t2, t1, 5

.. :

  ←

----

:id: ply-calc220-code-id

.. include:: src/semantic/ply_calc220_code.py
    :code: python
    :number-lines:
    :start-line: 19
    :end-line: 50

.. include:: src/semantic/ply_calc220_code.py
    :code: python
    :number-lines:
    :start-line: 50
    :end-line: 80

----


Inherited Attribute
===========================

..  csv-table:: 
    :header: Production, Semantic Rules
    :class: smallerelementwithfullborder yoosofantextalignleft center
    :align: center

    "D → T L", "L.in = T.type"
    "T → int", "T.type = integer"
    "T → real", "T.type = real"
    "L → L1, id", "L1.in = L.in,   addtype(id.entry,L.in)"
    "L → id", "addtype(id.entry,L.in)"

* int i
* int a,b,c
* real x,y

----

Dependency Graph for declaration
=====================================
real a, b, c

.. image:: img/semantic/dependency_graph_for_declaration.png
    :align: center

----

..  csv-table:: 
    :header: Production, Semantic Rules
    :class: smallerelementwithfullborder yoosofantextalignleft center

    "L → E \\n", "print(val[top-1])"
    "E → E1 + T", "val[ntop] = val[top-2] + val[top]"
    "E → T",
    "T → T1 * F", "val[ntop] = val[top-2] * val[top]"
    "T → F",
    "F → ( E )", "val[ntop] = val[top-1]"
    "F → digit"

----


..  csv-table:: 
    :header: ,Production, Semantic Rules
    :class: smallerelementwithfullborder yoosofantextalignleft center

    1, "A → B", "print(B.n0),  print(B.n1)"
    2, "B → 0 B1", "B.n0=B1.n0+1,  B.n1=B1.n1"
    3, "B → 1 B1", "B.n0=B1.n0,  B.n1=B1.n1+1"
    4, "B → λ	", "B.n0=0,  B.n1=0"

----

.. image:: img/semantic/constructing_syntax_tree_for_simple.png
    :align: center

----

.. image:: img/semantic/constructing_syntax_tree_for_simple_syntax_tree.png
    :align: center

----

Translation Scheme
=========================

* E → T R
* R → + T { print(“+”) } R1
* R → λ
* T → id { print(id.name) }

a+b+c

E → T R → id(a){print(id.name)} R → R → + T  {print("+")} R1 → T  {print("+")} R1 

id(b){print(id.name)} {print("+")} R1 → {print("+")} R1 → R1 → + T {print("+")} R1

→ T {print("+")} R1 → id(c){print(id.name)} {print("+")} R1 → {print("+")} R1 

→ R1 → λ


a b + c +

----

.. :

  ..  csv-table:: 
      :header: ,Production, Semantic Rules
      :class: smallerelementwithfullborder yoosofantextalignleft center

      1, "T → F T ' ", "T '.inh = F.val ,  T.val = T '.syn"
      2, "T ' → * F :math:`T '_1` ", ":math:`T '_1`.inh = T '.inh * F.val,  T '.syn = :math:`T '_1`.syn"
      3, "T ' → λ", "T '.syn = T '.inh"
      4, "F → id	", "F.val = id.name"

    5 * 7 * 2
    
.. image:: img/semantic/sdd_top_down_expression.png
    :align: center



.. image:: img/semantic/sdd_top_down_expression_dependency_graph.png
    :align: center

----

.. image:: img/semantic/type_definition_grammar.png
    :align: center

----

.. image:: img/semantic/constructing_tree_top_down_parsing.png
    :align: center

----

.. image:: img/semantic/constructing_tree_top_down_parsing_dependency_graph.png
    :align: center

----

Specification
======================

.. class:: substep

  * attributes
  * Semantic Rules
  * may generate intermediate codes
  * may put information into the symbol table
  * may perform type checking
  * may issue error messages
  * may perform some other activities
  * in fact, they may perform almost any activities.
  * An attribute may hold almost any thing.
  * a string, a number, a memory location, a complex record. 
  * inherited attribute
  * synthesized attribute

----

S-Attributed Definitions
=============================
.. class:: substep

    * An SDD that involves only synthesized attributes is called S-attributed
    * An S-attributed SDD can be implemented naturally in conjunction with an LR parser.

----

circular dependency
==============================
..  csv-table:: 
    :header: Production, Semantic Rules
    :class: smallerelementwithfullborder yoosofantextalignleft center

    "A → B", "A.s = B.i  ,   B.i = A.s + 1"

.. image:: img/semantic/The_circular_dependency.png
    :align: center

----

L-Attributed Definitions
================================
Each attribute must be either

.. class:: substep

    1. Synthesized, or
    2. Inherited, but for every rule like :math:`A → X_1X_2 ... X_n` which contains an inherited attribute :math:`X_i.a`, the rule may use only:
        
        * Inherited attributes associated with the head A.
        * attributes associated with the occurrences of symbols :math:`X_1, X_2 , . . . , X_{i-1}` is located to the left of :math:`X_i`.

----

Examples

.. class:: substep

    ..  csv-table:: 
        :header: Production, Semantic Rules
        :class: smallerelementwithfullborder yoosofantextalignleft center

        "D → T L", "L.in = T.type"
        "T → int", "T.type = integer"
        "T → real", "T.type = real"
        "L → :math:`L_1`, id", ":math:`L_1`.in = L.in,   addtype(id.entry,L.in)"
        "L → id", "addtype(id.entry,L.in)"

    .

    ..  csv-table:: 
        :header: Production, Semantic Rules
        :class: smallerelementwithfullborder yoosofantextalignleft center

        E → F R, "R.inh = F.val , E.val = R.val"
        R → + F :math:`R_1`, ":math:`R_1`.inh = R.inh + F.val , R.val = :math:`R_1`.val"
        R → λ, R.val = R.inh
        F → ( E ), F.val = E.val
        F → digit, F.val = digit.lexval

----

Not L-Attributed

.. class:: substep

    ..  csv-table:: 
        :header: Production, Semantic Rules
        :class: smallerelementwithfullborder yoosofantextalignleft center

        "A → B D", "A.s = B.b , B.i = f(D.d, A.s)"

    .

    ..  csv-table:: 
        :header: Production, Semantic Rules
        :class: smallerelementwithfullborder yoosofantextalignleft center

        "A → L M", "L.in = f1(A.i), M.in = f2(L.s), A.s = f3(M.s)"
        A → Q R, "R.in = f4(A.in), Q.in = f5(R.s), A.s = f3(Q.s)"

----

Translation Scheme vs SDD

.. class:: substep

    SDD

    ..  csv-table:: 
        :header: Production, Semantic Rules
        :class: smallerelementwithfullborder yoosofantextalignleft center

        E → F R, "R.inh = F.val , E.val = R.val"
        R → + F :math:`R_1`, ":math:`R_1`.inh = R.inh + F.val , R.val = :math:`R_1`.val"
        R → λ, R.val = R.inh
        F → ( E ), F.val = E.val
        F → digit, F.val = digit.lexval

    Translation Scheme

    ..  csv-table:: 
        :header: Production and Semantic Rules
        :class: smallerelementwithfullborder yoosofantextalignleft center

        E → F {R.inh = F.val} R {E.val = R.val}
        R → + F {:math:`R_1`.inh = R.inh + F.val} :math:`R_1` {R.val = :math:`R_1`.val}
        R → λ {R.val = R.inh}
        F → ( E ) {F.val = E.val}
        F → digit {F.val = digit.lexval}
    
----

SDD for typesetting boxes

.. image:: img/semantic/SDD_for_typesetting_boxes.png
    :align: center

----

End
===========

----

.. comments:

    rst2html syn.rst syn.html --stylesheet=farsi.css,html4css1.css

