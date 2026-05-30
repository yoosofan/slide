.. role:: raw-html(raw)
   :format: html

.. prezento:: CM - Semantic
   :skip-help: true
   :css: assets/style.css semantic.css
   :substep: true
   :slide-numbers: true
   :data-width: 1024
   :data-height: 768

.. slido::
   :skip-help: true
   :css: style.css semantic.css
   :substep: true
   :slide-numbers: true
   .. IGNORED_UNIMPLEMENTED: data-width: 1024
   .. IGNORED_UNIMPLEMENTED: data-height: 768

    .. role:: raw-html(raw)
       :format: html

.. slido:: Semantic Analyzer

    Ahmad Yoosofan

    Compiler course

    University of Kashan

    http://yoosofan.github.io/course/compiler.html

.. slido::
   :class: grid-2col-class

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

        :math:`I_0`, a[8]+a[9]$,
        :math:`I_0` a[8] :math:`I_2`, +a[9]$, r2(E → a)
        :math:`I_0` E[8] :math:`I_1`, +a[9]$
        :math:`I_0` E[8] :math:`I_1` + :math:`I_3`, a[9]$
        :math:`I_0` E[8] :math:`I_1` + :math:`I_3` a[9] :math:`I_4`, $, r1(E→E+a)
        :math:`I_0` E[17] :math:`I_1`, $
        acc

    .. yographviz::

          digraph g {
            node [ shape = "plaintext" ];

            "a" [ label = "E[17]" ];
            "b" [ label = "E[8]" ];
            "d" [ label = "+" ];
            "c" [ label = "9" ];
            "e" [ label = "8" ];

            a -> c [dir="back"];
            a -> d [dir="back"];
            a -> b [dir="back"];
            b -> e [dir="back"];
          }

    .. :

        https://stackoverflow.com/a/61416465/886607
        https://stackoverflow.com/a/28863761/886607

.. slido::
   :class: grid-2col-class

    ..  csv-table::
        :header: ` `, Production, Semantic
        :class: smallerelementwithfullborder yoosofantextalignleft

        1, "E → a", "E.val = lexValue(a)"
        2, "E → E + a", "E.val = :math:`E_1`.val + lexValue(a)"


    ..  csv-table::
        :header: ` `, a, `+`, `$`, `E`
        :class: smallerelementwithfullborder

        0, s2, , , 1
        1, , s3, acc,
        2, , r2, r2,
        3, s4, , ,
        4, , r1, r1,

    ..  csv-table::
        :header: n, Stack, Input, Action
        :class: smallerelementwithfullborder yoosofantextalignleft

        0, :math:`I_0`, a[8]+a[9]+a[2]$,
        1, :math:`I_0` a[8] :math:`I_2`, +a[9]+a[2]$, r2(E → a)
        2, :math:`I_0` E[8] :math:`I_1`, +a[9]+a[2]$,
        3, :math:`I_0` E[8] :math:`I_1` + :math:`I_3`, a[9]+a[2]$,
        4, :math:`I_0` E[8] :math:`I_1` + :math:`I_3` a[9] :math:`I_4`, +a[2]$, r1(E→E+a)
        5, :math:`I_0` E[17] :math:`I_1`, +a[2]$,
        6, :math:`I_0` E[17] :math:`I_1` + :math:`I_3`, a[2]$,
        7, :math:`I_0` E[17] :math:`I_1` + :math:`I_3` a[2] :math:`I_4`, $, r1(E→E+a)
        8, :math:`I_0` E[19] :math:`I_1`, $,
        9, acc ,

    .. yographviz::

          digraph g {
            node [ shape = "plaintext" ];

            "i" [ label = "E[19]" ];
            "a" [ label = "E[17]" ];
            "r" [ label = "+" ];
            "p" [ label = "a[2]" ];
            "b" [ label = "E[8]" ];
            "d" [ label = "+" ];
            "c" [ label = "a[9]" ];
            "e" [ label = "a[8]" ];

            i -> a [dir="back"];
            i -> r [dir="back"];
            i -> p [dir="back"];
            a -> c [dir="back"];
            a -> d [dir="back"];
            a -> b [dir="back"];
            b -> e [dir="back"];
          }

.. slido:: Anotated parse tree

    a[8]+a[9]+a[2]

    .. yographviz::

          digraph g {
            node [ shape = "plaintext" ];

            "i" [ label = "E.val=19" ];
            "a" [ label = "E.val=17" ];
            "r" [ label = "+" ];
            "p" [ label = "a.val=2" ];
            "b" [ label = "E.val=8" ];
            "d" [ label = "+" ];
            "c" [ label = "a.val=9" ];
            "e" [ label = "a.val=8" ];

            i -> a [dir="back"];
            i -> r [dir="back"];
            i -> p [dir="back"];
            a -> c [dir="back"];
            a -> d [dir="back"];
            a -> b [dir="back"];
            b -> e [dir="back"];
          }

.. slido:: Dependency Graph
   :class: t2c

    #. E → T + E
    #. E → T
    #. T → F * T
    #. T → F
    #. F → ( E )
    #. F → a

    .. yographviz::

          digraph g {
            node [ shape = "plaintext" ];

            "i" [ label = "E.val=19" ];
            "a" [ label = "E.val=17" ];
            "r" [ label = "+" ];
            "p" [ label = "a.val=2" ];
            "b" [ label = "E.val=8" ];
            "d" [ label = "+" ];
            "c" [ label = "a.val=9" ];
            "e" [ label = "a.val=8" ];

            i -> a [dir="back"];
            i -> r [dir="back"];
            i -> p [dir="back"];
            a -> c [dir="back"];
            a -> d [dir="back"];
            a -> b [dir="back"];
            b -> e [dir="back"];
          }

    .. :

      .. image:: cm/img/semantic/Anotated_parse_tree1.png
          :align: center

.. slido:: Syntax-Directed Definition
   :class: t2c

    ..  csv-table::
        :header: Production, Semantic Rules
        :class: smallerelementwithfullborder yoosofantextalignleft center

        S → E n, print(E.v)
        E → :math:`E_1+T`, :math:`E.v=E_1.v + T.v`
        E → T, :math:`E.v=T.v`
        T → :math:`T_1*F.v`, :math:`T.v=T_1.v * F.v`
        T → F, :math:`T.v=F.v`
        F → ( E ), :math:`F.v=E.v`
        F → a, :math:`F.v=a.lexval`

    .. yographviz::

          digraph g {
            node [ shape = "plaintext" ];

            "i" [ label = "F.val=19" ];
            "a" [ label = "F.val=17" ];
            "r" [ label = "+" ];
            "p" [ label = "a.val=2" ];
            "b" [ label = "E.val=8" ];
            "d" [ label = "+" ];
            "c" [ label = "a.val=9" ];
            "e" [ label = "a.val=8" ];

            i -> a [dir="back"];
            i -> r [dir="back"];
            i -> p [dir="back"];
            a -> c [dir="back"];
            a -> d [dir="back"];
            a -> b [dir="back"];
            b -> e [dir="back"];
          }

.. slido::
   :class: grid-2col-class

    .. include:: cm/src/semantic/ply_calc220.py
        :code: python
        :number-lines:
        :start-line: 0
        :end-line: 18

    .. include:: cm/src/semantic/ply_calc220.py
        :code: python
        :number-lines:
        :start-line: 60
        :end-line: 69

.. slido::
   :class: grid-2col-class

    .. include:: cm/src/semantic/ply_calc220.py
        :code: python
        :number-lines:
        :start-line: 18
        :end-line: 38

    .. include:: cm/src/semantic/ply_calc220.py
        :code: python
        :number-lines:
        :start-line: 38
        :end-line: 58

    .. :

      .. image:: cm/img/semantic/anotated_parse_tree.png
          :height: 300px

.. slido:: Inherited Attribute

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

    #. D → T {L.in = T.type} L
    #. T → int {T.type = integer}
    #. T → real {T.type = real}
    #. L → {L1.in = L.in} L1, id {addtype(id.entry,L.in)}
    #. L → id {addtype(id.entry,L.in)}

.. slido::

    real a, b, c

    .. image:: cm/img/semantic/dependency_graph_for_declaration.png
        :align: center

.. slido::
   :class: t2c

    .. include:: cm/src/rd/aB.plus.E.recursive.parser.py
      :code: python
      :number-lines:
      :start-line: 2
      :end-line: 24

    .. include:: cm/src/rd/aB.plus.E.recursive.parser.py
      :code: python
      :number-lines:
      :start-line: 2
      :end-line: 24

.. slido::
   :class: t2c

    .. include:: cm/src/ply/420.type.py
      :code: python
      :number-lines:
      :end-line: 24

    .. include:: cm/src/ply/420.type.py
      :code: python
      :number-lines: 24
      :start-line: 23

.. slido::
   :class: t2c

    .. include:: cm/src/ply/426.type.py
      :code: python
      :number-lines:
      :end-line: 24

    .. include:: cm/src/ply/426.type.py
      :code: python
      :number-lines: 24
      :start-line: 23

.. slido::
   :class: t2c

    .. include:: cm/src/ply/430.type.py
      :code: python
      :number-lines:
      :end-line: 24

    .. include:: cm/src/ply/430.type.py
      :code: python
      :number-lines: 24
      :start-line: 23

.. slido::
   :class: t2c

    .. include:: cm/src/ply/436.type.literals.py
      :code: python
      :number-lines:
      :end-line: 24

    .. include:: cm/src/ply/436.type.literals.py
      :code: python
      :number-lines: 24
      :start-line: 23

.. slido::

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

.. slido::
   :class: t2c

    .. container::

      ..  csv-table::
          :header: ,Production, Semantic Rules
          :class: smallerelementwithfullborder yoosofantextalignleft center

          1, "A → B", "print(B.n0),  print(B.n1)"
          2, "B → 0 :math:`B_1`", "B.n0=B1.n0+1,  B.n1=B1.n1"
          3, "B → 1 :math:`B_1`", "B.n0=B1.n0,  B.n1=B1.n1+1"
          4, "B → λ ", "B.n0=0,  B.n1=0"

      input: 0 0 1 $


    .. yographviz::

          digraph g {
            node [ shape = "plaintext" ];

            "A"  [ label = "A {print(B.n0);print(B.n1);}" ];
            "B0" [ label = "B {Bn0 += 1, Bn1}" ];
            "B1" [ label = "B {Bn0 +=1, Bn1}" ];
            "B2" [ label = "B {Bn1 +=1, Bn0}" ];
            "B3"  [ label = "λ {Bn0 = Bn1 = 0}" ];
            "Z0"  [ label = " 0" ];
            "Z1"  [ label = " 0" ];
            "Z2"  [ label = " 1" ];

            A -> B0 [dir="back"];
            B0 -> Z0 [dir="back"];
            B0 -> B1 [dir="back"];
            B1 -> Z1 [dir="back"];
            B1 -> B2 [dir="back"];
            B2 -> Z2 [dir="back"];
            B2 -> B3 [dir="back"];
          }

.. slido::
   :class: t2c

    ..  csv-table::
        :header: ,Production, Semantic Rules
        :class: smallerelementwithfullborder yoosofantextalignleft center

        1, "A→B", "print(B.n0),  print(B.n1)"
        2, :math:`B→ 0 B_1`, ":math:`B.n_0=B_1.n_0+1, B.n_1=B_1.n_1`" 
        3, :math:`B→ 1 B_1`, ":math:`B.n_0=B_1.n_0, B.n_1=B_1.n_1+1`"
        4,  B→λ,":math:`B.n_0=0,  B.n_1=0`"

    .. yographviz::

          digraph g {
            graph [splines=true  rankdir = "LR"];
            ratio = auto;
            "state0" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>0</sub>)</td></tr>
              <tr><td align="left" port="r0">S → . A </td></tr>
              <tr><td align="left" port="r1">A  → . B </td></tr>
              <tr><td align="left" port="r2">B  → . 0 B</td></tr>
              <tr><td align="left" port="r3">B  → . 1 B </td></tr>
              <tr><td align="left" port="r4">B  → .  </td></tr>
            </table>>];
            "state1" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>1</sub>)</td></tr>
              <tr><td align="left" port="r3">S → A . </td></tr>
            </table>> ];
            "state2" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>2</sub>)</td></tr>
              <tr><td align="left" port="r1">A → B . </td></tr>
            </table>>];
            "state3" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>3</sub>)</td></tr>
              <tr><td align="left" port="r1">B → 0 . B </td></tr>
              <tr><td align="left" port="r2">B → . 0 B </td></tr>
              <tr><td align="left" port="r3">B → . 1 B </td></tr>
              <tr><td align="left" port="r4">B → . </td></tr>
            </table>>];
            "state4" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>4</sub>)</td></tr>
              <tr><td align="left" port="r1">B → 1 . B </td></tr>
              <tr><td align="left" port="r2">B → . 0 B </td></tr>
              <tr><td align="left" port="r3">B → . 1 B </td></tr>
              <tr><td align="left" port="r4">B → . </td></tr>
            </table>>];
            "state5" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>5</sub>)</td></tr>
              <tr><td align="left" port="r1">B → 0 B . </td></tr>
            </table>>];
            "state6" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>6</sub>)</td></tr>
              <tr><td align="left" port="r1">B → 1 B . </td></tr>
            </table>>];
            state0 -> state1 [ label = "A" ];
            state0 -> state2 [ label = "B" ];
            state0 -> state3 [ label = "0" ];
            state0 -> state4 [  label = "1" ];
            state3 -> state5 [  label = "B" ];
            state3 -> state3 [  label = "0" ];
            state3 -> state4 [  label = "1" ];
            state4 -> state4 [  label = "1" ];
            state4 -> state3 [  label = "0" ];
            state4 -> state6 [  label = "B" ];
          }

.. slido::
   :class: t2c

    .. csv-table::
      :header-rows: 1
      :class: smallerelementwithfullborder equal-col

      t , 0 , 1 , $ , A , B 
      I0, s3, s4,   , 1 , 2
      I1,   ,   ,acc,   ,
      I2,   ,   , r1,   ,   
      I3, s3, s4, r4,   , 5  
      I4, s3, s4, r4,   , 6 
      I5,   ,   , r2,   ,  
      I6,   ,   , r3,   ,  


    .. yographviz::

          digraph g {
            graph [splines=true  rankdir = "LR"];
            ratio = auto;
            "state0" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>0</sub>)</td></tr>
              <tr><td align="left" port="r0">S → . A </td></tr>
              <tr><td align="left" port="r1">1)A  → . B </td></tr>
              <tr><td align="left" port="r2">2)B  → . 0 B</td></tr>
              <tr><td align="left" port="r3">3)B  → . 1 B </td></tr>
              <tr><td align="left" port="r4">4)B  → .  </td></tr>
            </table>>];
            "state1" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>1</sub>)</td></tr>
              <tr><td align="left" port="r3">S → A . </td></tr>
            </table>> ];
            "state2" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>2</sub>)</td></tr>
              <tr><td align="left" port="r1">A → B . </td></tr>
            </table>>];
            "state3" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>3</sub>)</td></tr>
              <tr><td align="left" port="r1">B → 0 . B </td></tr>
              <tr><td align="left" port="r2">B → . 0 B </td></tr>
              <tr><td align="left" port="r3">B → . 1 B </td></tr>
              <tr><td align="left" port="r4">B → . </td></tr>
            </table>>];
            "state4" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>4</sub>)</td></tr>
              <tr><td align="left" port="r1">B → 1 . B </td></tr>
              <tr><td align="left" port="r2">B → . 0 B </td></tr>
              <tr><td align="left" port="r3">B → . 1 B </td></tr>
              <tr><td align="left" port="r4">B → . </td></tr>
            </table>>];
            "state5" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>5</sub>)</td></tr>
              <tr><td align="left" port="r1">B → 0 B . </td></tr>
            </table>>];
            "state6" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>6</sub>)</td></tr>
              <tr><td align="left" port="r1">B → 1 B . </td></tr>
            </table>>];
            state0 -> state1 [ label = "A" ];
            state0 -> state2 [ label = "B" ];
            state0 -> state3 [ label = "0" ];
            state0 -> state4 [  label = "1" ];
            state3 -> state5 [  label = "B" ];
            state3 -> state3 [  label = "0" ];
            state3 -> state4 [  label = "1" ];
            state4 -> state4 [  label = "1" ];
            state4 -> state3 [  label = "0" ];
            state4 -> state6 [  label = "B" ];
          }

.. slido::
   :class: t2c

    .. container::

      ..  csv-table::
          :class: smallerelementwithfullborder yoosofantextalignleft center

          1, "A→B", "print(B.n0),  print(B.n1)"
          2, :math:`B→ 0\ B_1`, ":math:`B.n_0=B_1.n_0+1, B.n_1=B_1.n_1`" 
          3, :math:`B→ 1\ B_1`, ":math:`B.n_0=B_1.n_0, B.n_1=B_1.n_1+1`"
          4,  B→λ,":math:`B.n_0=0, B.n_1=0`"

      .. csv-table::
        :header-rows: 1
        :class: smallerelementwithfullborder equal-col center

        t , 0 , 1 , $ , A , B 
        :math:`I_0`, s3, s4,   , 1 , 2
        :math:`I_1`,   ,   ,acc,   ,
        :math:`I_2`,   ,   , r1,   ,   
        :math:`I_3`, s3, s4, r4,   , 5  
        :math:`I_4`, s3, s4, r4,   , 6 
        :math:`I_5`,   ,   , r2,   ,  
        :math:`I_6`,   ,   , r3,   ,  

    .. csv-table::
      :header-rows: 1
      :class: smallerelementwithfullborder

      Stack                                           ,input, action
      :math:`I_0`                                     ,001$ , Shift 3
      :math:`I_0\ 0\ I_3`                             , 01$ , Shift 3
      :math:`I_0\ 0\ I_3\ 0\ I_3`                     , 1$  , Shift 4
      :math:`I_0\ 0\ I_3\ 0\ I_3\ 1\ I_4`             , $   , r4 B[0،0]
      :math:`I_0\ 0\ I_3\ 0\ I_3\ 1\ I_4\ B[0،0]\ I_6`, $   , r3 B[0،1]
      :math:`I_0\ 0\ I_3\ 0\ I_3\ B[0،1]\ I_5`        , $   , r2 B[1،1]
      :math:`I_0\ 0\ I_3\ B[1،1]\ I_5`                , $   , r2 B[2،1]
      :math:`I_0\ B[2،1]\ I_2`                        , $   , r1 print(B[2،1])
      :math:`I_0\ I_1`                                , $   , accept

.. slido:: Similar Grammar

    ..  csv-table::
        :class: smallerelementwithfullborder yoosofantextalignleft center

        1, "A→B", "print(B.n0),  print(B.n1)"
        2, :math:`B→ B_1 \ 0`, ":math:`B.n_0=B_1.n_0+1, B.n_1=B_1.n_1`" 
        3, :math:`B→ B_1 \ 1`, ":math:`B.n_0=B_1.n_0, B.n_1=B_1.n_1+1`"
        4,  B→λ,":math:`B.n_0=0,  B.n_1=0`"

.. slido::

    .. image:: cm/img/semantic/constructing_syntax_tree_for_simple.png
        :align: center

.. slido::

    .. image:: cm/img/semantic/constructing_syntax_tree_for_simple_syntax_tree.png
        :align: center

.. slido::
   :class: t2c

    ..  csv-table::
        :header: Production, Semantic Rules
        :class: smallerelementwithfullborder yoosofantextalignleft

        "E → E1 + T", "E.loc=newtemp() , :raw-html:`<br />` E.code = E1.code || T.code || 'add E.loc, E1.loc, T.loc'"
        "E → T", "E.loc = T.loc, E.code=T.code"
        "T → T1 * F", "T.loc=newtemp() , :raw-html:`<br />` T.code = T1.code || F.code  || 'mult T.loc, T1.loc, F.loc'"
        "T → F", "T.loc = F.loc, T.code=F.code "
        "F → ( E )", "F.loc = E.loc,  F.code=E.code"
        "F → id", "F.loc = id.name,  F.code= '' "


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

.. slido::
   :class: grid-2col-class

    .. include:: cm/src/ply/ply_calc220_code.py
        :code: python
        :number-lines:
        :start-line: 19
        :end-line: 50

    .. include:: cm/src/ply/ply_calc220_code.py
        :code: python
        :number-lines:
        :start-line: 50
        :end-line: 80

.. slido:: Translation Scheme
   :class: t2c

    .. container::

      * E → T R
      * R → + T { print("+") } R1
      * R → λ
      * T → id { print(id.name) }

      #. a+b+c
      #. a b + c +

    * E → T R → id(a){print(id.name)} R
    * → R → + T {print("+")} R1 
    * → T  {print("+")} R1 → 
    * id(b){print(id.name)}{print("+")} R1
    * → {print("+")} R1
    * → R1 → + T {print("+")} R1
    * → T {print("+")} R1
    * → id(c){print(id.name)}{print("+")} R1
    * → {print("+")} R1 → R1 → λ

.. slido::
   :class: t2c

    ..  csv-table::
        :header: ,Production, Semantic Rules
        :class: smallerelementwithfullborder yoosofantextalignleft center

        1, "T → F T ' ", "T '.inh = F.val ,  T.val = T '.syn"
        2, "T ' → * F :math:`T '_1` ", ":math:`T '_1`.inh = T '.inh * F.val,  T '.syn = :math:`T '_1`.syn"
        3, "T ' → λ", "T '.syn = T '.inh"
        4, "F → id  ", "F.val = id.name"

    .. :

        5 * 7 * 2

    .. :

        .. image:: cm/img/semantic/sdd_top_down_expression.png
            :align: center

    .. image:: cm/img/semantic/sdd_top_down_expression_dependency_graph.png
        :align: center
        :width: 400px

.. slido::

    .. image:: cm/img/semantic/type_definition_grammar.png
        :align: center

.. slido::

    .. image:: cm/img/semantic/constructing_tree_top_down_parsing.png
        :align: center

.. slido::

    .. image:: cm/img/semantic/constructing_tree_top_down_parsing_dependency_graph.png
        :align: center

.. slido:: Specification

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

.. slido:: S-Attributed Definitions

    .. class:: substep

        * An SDD that involves only synthesized attributes is called S-attributed
        * An S-attributed SDD can be implemented naturally in conjunction with an LR parser.

.. slido:: circular dependency

    ..  csv-table::
        :header: Production, Semantic Rules
        :class: smallerelementwithfullborder yoosofantextalignleft center

        "A → B", "A.s = B.i  ,   B.i = A.s + 1"

    .. image:: cm/img/semantic/The_circular_dependency.png
        :align: center

.. slido:: L-Attributed Definitions

    Each attribute must be either

    .. class:: substep

        1. Synthesized, or
        2. Inherited, but for every rule like :math:`A → X_1X_2 ... X_n` which contains an inherited attribute :math:`X_i.a`, the rule may use only:

            * Inherited attributes associated with the head A.
            * attributes associated with the occurrences of symbols :math:`X_1, X_2 , . . . , X_{i-1}` is located to the left of :math:`X_i`.

.. slido::

    Examples


    ..  csv-table::
        :header: Production, Semantic Rules
        :class: smallerelementwithfullborder yoosofantextalignleft center

        "D → T L", "L.in = T.type"
        "T → int", "T.type = integer"
        "T → real", "T.type = real"
        "L → :math:`L_1`, id", ":math:`L_1`.in = L.in,   addtype(id.entry,L.in)"
        "L → id", "addtype(id.entry,L.in)"


    ..  csv-table::
        :header: Production, Semantic Rules
        :class: smallerelementwithfullborder yoosofantextalignleft center

        E → F R, "R.inh = F.val , E.val = R.val"
        R → + F :math:`R_1`, ":math:`R_1`.inh = R.inh + F.val , R.val = :math:`R_1`.val"
        R → λ, R.val = R.inh
        F → ( E ), F.val = E.val
        F → digit, F.val = digit.lexval

.. slido::

    Not L-Attributed

    ..  csv-table::
        :header: Production, Semantic Rules
        :class: smallerelementwithfullborder yoosofantextalignleft center

        "A → B D", "A.s = B.b , B.i = f(D.d, A.s)"

    ..  csv-table::
        :header: Production, Semantic Rules
        :class: smallerelementwithfullborder yoosofantextalignleft center

        "A → L M", "L.in = f1(A.i), M.in = f2(L.s), A.s = f3(M.s)"
        A → Q R, "R.in = f4(A.in), Q.in = f5(R.s), A.s = f3(Q.s)"

.. slido:: Translation Scheme vs SDD

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

.. slido::

    SDD for typesetting boxes

    .. image:: cm/img/semantic/SDD_for_typesetting_boxes.png
        :align: center

.. slido::

    .. csv-table::

      B → S B1          , L1 = newlabel()
                          B.next = B1.next
                          B.code = S.code || 'label' || L1 || B1.code
                          S.next =  L1

      B → λ             , L1 = newlabel(); B.next = L1 ; B.code = 'Label ' || L1

      S → w ( C ) S1    , L1 = newlabel(); L2 = newlabel();
                          C.false = S.next
                          C.true = L2
                          S1.next = L1
                          S.code = 'label ' || L1 || C.code || 'label ' || L2 || S1.code
                                    || 'goto '  || L1

      S → i = C ;       , S.code = C.code || 'AsG' || i.name || ',' || C.val

      C → o ;           , C.val = 1

.. slido:: End

    .. :

        .. yographviz::

            digraph g {
              node [ shape = "plaintext" ];

              "a" [ label = "E.val = 9" ];
              "b" [ label = "E.val = 5" ];
              "d" [ label = "+" ];
              "c" [ label = "a.val = 4" ];
              "e" [ label = "a.val = 5" ];

              a -> { c d b } [dir="back"];
              b -> e [dir="back"];
            }

    .. :

        https://stackoverflow.com/a/29008563/886607
