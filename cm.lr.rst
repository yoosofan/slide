.. prezento:: CM - Lr
   :css: ./assets/style.css

.. slido:: Syntax Analysis(LR), Ahmad Yoosofan

    Compiler course

    https://yoosofan.github.io/course/compiler.html

.. slido:: Simple Add(I)
   :class: t2c

    #. S → E
    #. E → E + a
    #. E → a

    .. yographviz::
       :width: 1000px

        digraph aaa{
            graph [splines=true  rankdir = "LR"];
            ratio = auto;

            "state0" [class="incremental" shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td align="left" port="r0">S → .E </td></tr>
              <tr><td align="left" port="r0">E → .E + a</td></tr>
              <tr><td align="left" port="r1">E → .a </td></tr>
              </table>>];

            "state1" [class="incremental"  shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td align="left" port="r0">S → E. </td></tr>
              <tr><td align="left" port="r0">E → E. + a</td></tr>
              </table>>];

            "state2" [class="incremental"  shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td align="left" port="r1">E → a. </td></tr>
              </table>>];

            "state3" [class="incremental"  shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td align="left" port="r1">E → E +. a </td></tr>
              </table>>];

            "state4" [class="incremental"  shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td align="left" port="r1">E → E + a. </td></tr>
              </table>>];

            state0 -> state1 [class="incremental"  label = "E" ];
            state0 -> state2 [class="incremental"  label = "a" ];
            state1 -> state3 [class="incremental"  label = "+" ];
            state3 -> state4 [class="incremental"  label = "a" ];
        }

    .. class:: step

        #. a[1.4]+a[2.5]+a[3.6]
        #. E(a[1.4])+a[2.5]+a[3.6]
        #. E(E(a[1.4])+a[2.5])+a[3.6]
        #. E(E(E(a[1.4])+a[2.5])+a[3.6])


        .. yographviz::
           :class: step

                digraph ParseTree {
                  node [fontname="Courier", shape=circle, style=filled, fillcolor="#f9f9f9"];
                  edge [fontname="Courier", arrowhead=none];

                  // Root Rule: S -> E
                  S [label="S", fillcolor="#dee2e6", style="filled,bold"];

                  // Top-level reduction node
                  E3 [label="E"];
                  S -> E3;

                  // Intermediate elements
                  E2 [label="E"];
                  plus2 [label="+"];
                  a3 [label="a [3.6]", fillcolor="#fff3cd", shape=ellipse];

                  // Connected left-to-right to place '+' in the middle
                  E3 -> E2;
                  E3 -> plus2;
                  E3 -> a3;

                  // Base elements
                  E1 [label="E"];
                  plus1 [label="+"];
                  a2 [label="a [2.5]", fillcolor="#fff3cd", shape=ellipse];

                  // Connected left-to-right to place '+' in the middle
                  E2 -> E1;
                  E2 -> plus1;
                  E2 -> a2;

                  // Terminal base reduction: E -> a
                  a1 [label="a [1.4]", fillcolor="#fff3cd", shape=ellipse];
                  E1 -> a1;
                }

.. slido:: Simple Add(II)
   :class: t2c

    #. S → E
    #. E → E + a
    #. E → a

    .. yographviz::

        digraph {
          graph [splines=true  rankdir = "LR"];
          ratio = auto;

          "state0" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
            <tr><td>(I<sub>0</sub>)</td></tr>
            <tr><td align="left" port="r0">S → .E </td></tr>
            <tr><td align="left" port="r0">E → .E + a</td></tr>
            <tr><td align="left" port="r1">E → .a </td></tr>
            </table>>];

          "state1" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
            <tr><td>(I<sub>1</sub>)</td></tr>
            <tr><td align="left" port="r0">S → E. </td></tr>
            <tr><td align="left" port="r0">E → E. + a</td></tr>
            </table>>];

          "state2" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
            <tr><td>(I<sub>2</sub>)</td></tr>
            <tr><td align="left" port="r1">E → a. </td></tr>
            </table>>];

          "state3" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
            <tr><td>(I<sub>3</sub>)</td></tr>
            <tr><td align="left" port="r1">E → E +. a </td></tr>
            </table>>];

          "state4" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
            <tr><td>(I<sub>4</sub>)</td></tr>
            <tr><td align="left" port="r1">E → E + a. </td></tr>
            </table>>];

          state0 -> state1 [ label = "E" ];
          state0 -> state2 [ label = "a" ];
          state1 -> state3 [ label = "+" ];
          state3 -> state4 [ label = "a" ];
        }

.. slido:: Simple Calculator(I)
   :class: t2c

    #. E → E + T
    #. E → E - T
    #. E → T
    #. T → T * F
    #. T → T / F
    #. T → F
    #. F → (E)
    #. F → a

    .. yographviz::
      :class: step

      digraph {
        graph [splines=true  rankdir = "LR"];
        ratio = auto;
        "state0" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
          <tr><td>(I<sub>0</sub>)</td></tr>
          <tr><td align="left" port="r0">S → .E </td></tr>
          <tr><td align="left" port="r1">E → .E + T </td></tr>
          <tr><td align="left" port="r2">E → .E - T </td></tr>
          <tr><td align="left" port="r3">E → .T </td></tr>
          <tr><td align="left" port="r4">T → .T * F </td></tr>
          <tr><td align="left" port="r5">T → .T / F </td></tr>
          <tr><td align="left" port="r5">T → .F </td></tr>
          <tr><td align="left" port="r5">F → .a </td></tr>
          <tr><td align="left" port="r5">F → .(E) </td></tr>
        </table>>];
      }

.. slido:: Simple Calculator(II)
   :class: t2c

    #. E → E + T
    #. E → E - T
    #. E → T
    #. T → T * F
    #. T → T / F
    #. T → F
    #. F → (E)
    #. F → a

    .. yographviz::
      :class: step

      digraph {
        graph [splines=true  rankdir = "LR"];
        ratio = auto;
        "state0" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
          <tr><td>(I<sub>0</sub>)</td></tr>
          <tr><td align="left" port="r0">S → .E </td></tr>
          <tr><td align="left" port="r1">E → .E + T </td></tr>
          <tr><td align="left" port="r2">E → .E - T </td></tr>
          <tr><td align="left" port="r3">E → .T </td></tr>
          <tr><td align="left" port="r4">T → .T * F </td></tr>
          <tr><td align="left" port="r5">T → .T / F </td></tr>
          <tr><td align="left" port="r5">T → .F </td></tr>
          <tr><td align="left" port="r5">F → .a </td></tr>
          <tr><td align="left" port="r5">F → .(E) </td></tr>
        </table>>];
        "state1" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
          <tr><td>(I<sub>1</sub>)</td></tr>
          <tr><td align="left" port="r3">S → E. </td></tr>
          <tr><td align="left" port="r3">E → E. + T</td></tr>
          <tr><td align="left" port="r3">E → E. - T</td></tr>
        </table>> ];
        "state2" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
          <tr><td>(I<sub>2</sub>)</td></tr>
          <tr><td align="left" port="r1">E → T. </td></tr>
          <tr><td align="left" port="r5">T → T. * F </td></tr>
          <tr><td align="left" port="r5">T → T. / F </td></tr>
        </table>>];
        "state3" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
          <tr><td>(I<sub>3</sub>)</td></tr>
          <tr><td align="left" port="r1">T → F. </td></tr>
        </table>>];
        "state4" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
          <tr><td>(I<sub>4</sub>)</td></tr>
          <tr><td align="left" port="r3">F → a </td></tr>
        </table>>];
        "state5" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
          <tr><td>(I<sub>5</sub>)</td></tr>
          <tr><td align="left" port="r1">F → (.E) </td></tr>
        </table>>];

        state0 -> state1 [ label = "E" ];
        state0 -> state2 [ label = "T" ];
        state0 -> state3 [ label = "F" ];
        state0 -> state4 [  label = "a" ];
        state0 -> state5 [  label = "(" ];

      }

.. slido:: Simple Calculator(XX)
   :class: t2c

    #. E → E + T
    #. E → E - T
    #. E → T
    #. T → T * F
    #. T → T / F
    #. T → F
    #. F → (E)
    #. F → a

    .. yographviz::
      :class: step

      digraph {
        graph [splines=true  rankdir = "LR"];
        ratio = auto;
        "state0" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
          <tr><td>(I<sub>0</sub>)</td></tr>
          <tr><td align="left" port="r0">S → .E </td></tr>
          <tr><td align="left" port="r1">E → .E + T </td></tr>
          <tr><td align="left" port="r2">E → .E - T </td></tr>
          <tr><td align="left" port="r3">E → .T </td></tr>
          <tr><td align="left" port="r4">T → .T * F </td></tr>
          <tr><td align="left" port="r5">T → .T / F </td></tr>
          <tr><td align="left" port="r5">T → .F </td></tr>
          <tr><td align="left" port="r5">F → .a </td></tr>
          <tr><td align="left" port="r5">F → .(E) </td></tr>
        </table>>];
        "state1" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
          <tr><td>(I<sub>1</sub>)</td></tr>
          <tr><td align="left" port="r3">S → E. </td></tr>
          <tr><td align="left" port="r3">E → E. + T</td></tr>
          <tr><td align="left" port="r3">E → E. - T</td></tr>
        </table>> ];
        "state2" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
          <tr><td>(I<sub>2</sub>)</td></tr>
          <tr><td align="left" port="r1">E → T. </td></tr>
          <tr><td align="left" port="r5">T → T. * F </td></tr>
          <tr><td align="left" port="r5">T → T. / F </td></tr>
        </table>>];
        "state3" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
          <tr><td>(I<sub>3</sub>)</td></tr>
          <tr><td align="left" port="r1">T → F. </td></tr>
        </table>>];
        "state4" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
          <tr><td>(I<sub>4</sub>)</td></tr>
          <tr><td align="left" port="r3">F → a </td></tr>
        </table>>];
        "state5" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
          <tr><td>(I<sub>5</sub>)</td></tr>
          <tr><td align="left" port="r1">F → (.E) </td></tr>
        </table>>];
        "state6" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
          <tr><td>(I<sub>6</sub>)</td></tr>
          <tr><td align="left" port="r1">L → * R. </td></tr>
        </table>>];
        "state7" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
          <tr><td>(I<sub>7</sub>)</td></tr>
          <tr><td align="left" port="r1">R → L. </td></tr>
        </table>>];
        "state8" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
          <tr><td>(I<sub>8</sub>)</td></tr>
          <tr><td align="left" port="r1">S → L =. R </td></tr>
          <tr><td align="left" port="r5">R → .L </td></tr>
          <tr><td align="left" port="r3">L → .* R </td></tr>
          <tr><td align="left" port="r4">L → .a </td></tr>
        </table>>];
        "state9" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
          <tr><td>(I<sub>9</sub>)</td></tr>
          <tr><td align="left" port="r1">S → L = R. </td></tr>
        </table>>];

        "I7"     [ shape = "circle"  label = "I7"]
        "I4"     [ shape = "circle"  label = "I4"]
        "I5"     [ shape = "circle"  label = "I5"]
        state0 -> state1 [ label = "S" ];
        state0 -> state2 [ label = "L" ];
        state0 -> state3 [ label = "R" ];
        state0 -> state4 [  label = "*" ];
        state0 -> state5 [  label = "a" ];
        state4 -> state6 [  label = "R" ];
        state4 -> state7 [  label = "L" ];
        state4 -> state4 [  label = "*" ];
        state4 -> state5 [  label = "a" ];
        state2 -> state8 [  label = "=" ];
        state8 -> state9 [  label = "R" ];
        state8 -> I7 [  label = "L" ];
        state8 -> I4 [  label = "*" ];
        state8 -> I5 [  label = "a" ];
      }

.. slido::

    .. image:: cm/img/lr/slr_etf.png

.. slido:: LR Table

    .. csv-table::
      :header-rows: 1
      :class: smallerelementwithfullborder equal-col

        , id, + , * , `(`, `)`, $ , E , T , F
      I0, s5,   ,   , s4 ,    ,acc,   ,   ,
      I1,   , s6,   ,    ,    ,   ,   ,   ,
      I2,   ,   , s7,    ,    ,   ,   ,   ,
      I3,   ,   ,   ,    ,    ,   ,   ,   ,
      I4, s5,   ,   , s4 ,    ,   , 8 , 2 , 3
      I5,   ,   ,   ,    ,    ,   ,   ,   ,
      I6, s5,   ,   , s4 ,    ,   ,   , 9 , 3
      I7,   ,   ,   ,    ,    ,   ,   ,   , 10
      I8,   ,   ,   ,    ,    ,   ,   ,   ,

.. slido:: Ambiguous Grammar
   :class: t2c

    .. code:: fortran

        IF x = 2 THEN
            x = 3
        ELSE
            x = 4

    .. class:: step

    #. S → i S
    #. S → i S e S
    #. S → o

.. slido::
   :class: t2c

    .. container::

        * S`  →  S

        #. S → i S
        #. S → i S e S
        #. S → o

    .. yographviz::
      :class: step

      digraph {
        graph [splines=true  rankdir = "LR"];
        ratio = auto;
        "state0" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
          <tr><td>(I<sub>0</sub>)</td></tr>
          <tr><td align="left" port="r0">S` → .S </td></tr>
          <tr><td align="left" port="r1">S → .i S </td></tr>
          <tr><td align="left" port="r2">S → .i S e S </td></tr>
          <tr><td align="left" port="r3">S → .o </td></tr>
        </table>>];
        "state1" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
          <tr><td>(I<sub>1</sub>)</td></tr>
          <tr><td align="left" port="r3">S` → S. </td></tr>
        </table>> ];
        "state2" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
          <tr><td>(I<sub>2</sub>)</td></tr>
          <tr><td align="left" port="r1">S → i . S  </td></tr>
          <tr><td align="left" port="r3">S → i . S e S </td></tr>
          <tr><td align="left" port="r5">S → . i S </td></tr>
          <tr><td align="left" port="r5">S → . i S e S </td></tr>
          <tr><td align="left" port="r5">S → . o </td></tr>
        </table>>];
        "state3" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
          <tr><td>(I<sub>3</sub>)</td></tr>
          <tr><td align="left" port="r1">S → o . </td></tr>
        </table>>];
        "state4" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
          <tr><td>(I<sub>4</sub>)</td></tr>
          <tr><td align="left" port="r1">S → i S . </td></tr>
          <tr><td align="left" port="r3">S → i S . e S </td></tr>
        </table>>];
        "state5" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
          <tr><td>(I<sub>5</sub>)</td></tr>
          <tr><td align="left" port="r1">S → i S  e . S </td></tr>
          <tr><td align="left" port="r2">S → . i S </td></tr>
          <tr><td align="left" port="r2">S → . i S e S </td></tr>
          <tr><td align="left" port="r2">S → . o </td></tr>
        </table>>];
        "state6" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
          <tr><td>(I<sub>6</sub>)</td></tr>
          <tr><td align="left" port="r1">S → i S e S . </td></tr>
        </table>>];

        state0 -> state1 [ label = "S" ];
        state0 -> state2 [ label = "i" ];
        state0 -> state3 [ label = "o" ];
        state2 -> state4 [  label = "S" ];
        state2 -> state2 [  label = "i" ];
        state2 -> state3 [  label = "o" ];
        state4 -> state5 [  label = "e" ];
        state5 -> state6 [  label = "S" ];
        state5 -> state3 [  label = "o" ];
        state5 -> state2 [  label = "i" ];
      }

.. slido::

    .. yographviz::

      digraph {
        graph [splines=true  rankdir = "LR"];
        ratio = auto;
        "state0" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
          <tr><td>(I<sub>0</sub>)</td></tr>
          <tr><td align="left" port="r0">S` → .S </td></tr>
          <tr><td align="left" port="r1">S → .i S </td></tr>
          <tr><td align="left" port="r2">S → .i S e S </td></tr>
          <tr><td align="left" port="r3">S → .o </td></tr>
        </table>>];
        "state1" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
          <tr><td>(I<sub>1</sub>)</td></tr>
          <tr><td align="left" port="r3">S` → S. </td></tr>
        </table>> ];
        "state2" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
          <tr><td>(I<sub>2</sub>)</td></tr>
          <tr><td align="left" port="r1">S → i . S  </td></tr>
          <tr><td align="left" port="r3">S → i . S e S </td></tr>
          <tr><td align="left" port="r5">S → . i S </td></tr>
          <tr><td align="left" port="r5">S → . i S e S </td></tr>
          <tr><td align="left" port="r5">S → . o </td></tr>
        </table>>];
        "state3" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
          <tr><td>(I<sub>3</sub>)</td></tr>
          <tr><td align="left" port="r1">S → o . </td></tr>
        </table>>];
        "state4" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
          <tr><td>(I<sub>4</sub>)</td></tr>
          <tr><td align="left" port="r1">S → i S . </td></tr>
          <tr><td align="left" port="r3">S → i S . e S </td></tr>
        </table>>];
        "state5" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
          <tr><td>(I<sub>5</sub>)</td></tr>
          <tr><td align="left" port="r1">S → i S  e . S </td></tr>
          <tr><td align="left" port="r2">S → . i S </td></tr>
          <tr><td align="left" port="r2">S → . i S e S </td></tr>
          <tr><td align="left" port="r2">S → . o </td></tr>
        </table>>];
        "state6" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
          <tr><td>(I<sub>6</sub>)</td></tr>
          <tr><td align="left" port="r1">S → i S e S . </td></tr>
        </table>>];

        state0 -> state1 [ label = "S" ];
        state0 -> state2 [ label = "i" ];
        state0 -> state3 [ label = "o" ];
        state2 -> state4 [  label = "S" ];
        state2 -> state2 [  label = "i" ];
        state2 -> state3 [  label = "o" ];
        state4 -> state5 [  label = "e" ];
        state5 -> state6 [  label = "S" ];
        state5 -> state3 [  label = "o" ];
        state5 -> state2 [  label = "i" ];
      }

    .. list-table::

      * -  .. csv-table::
              :header-rows: 1
              :class: smallerelementwithfullborder equal-col

                , i , e , o ,  $  , S
              I0, s2,   , s3,     , 1
              I1,   ,   ,   , acc ,
              I2, s2,   , s3,     , 4
              I3, r3, r3, r3,  r3 ,
              I4, r1,s5/r1, r1  ,r1     ,
              I5, s2  ,   , s3  ,     ,   6
              I6, r2, r2  , r2  ,  r2   ,

        -  .. container::

              #. S → i S
              #. S → i S e S
              #. S → o

.. slido::

    #. S → i S M
    #. M → e S
    #. M → λ
    #. S → o

.. slido:: An Especial Grammar

    .. :

        :class: t2c

        #. S → a L
        #. S → S b
        #. L → L a
        #. L →  b

        .. container:: step

          Augmented Grammer

          * S' → S

          * S → a L
          * S → S b
          * L → L a
          * L →  b

        .. class:: step

            * first(S)  = {a}
            * first(L)  = {b}

        .. class:: step

            * follow(S)  = {$, b}
            * follow(L)  = {$, a}

        ----

        .. yographviz::

              digraph g {
                graph [splines=true  rankdir = "LR"];
                ratio = auto;
                "state0" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
                  <tr><td>(I<sub>0</sub>)</td></tr>
                  <tr><td align="left" port="r0">S' → . S </td></tr>
                  <tr><td align="left" port="r1">S  → . a L </td></tr>
                  <tr><td align="left" port="r2">S  → . S b </td></tr>
                </table>>];
                "state1" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
                  <tr><td>(I<sub>1</sub>)</td></tr>
                  <tr><td align="left" port="r3">S' → S . </td></tr>
                  <tr><td align="left" port="r3">S  → S . b </td></tr>
                </table>> ];
                "state2" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
                  <tr><td>(I<sub>2</sub>)</td></tr>
                  <tr><td align="left" port="r1"> S → a . L </td></tr>
                  <tr><td align="left" port="r5"> L → . L a </td></tr>
                  <tr><td align="left" port="r5"> L → . b </td></tr>
                </table>>];
                "state3" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
                  <tr><td>(I<sub>3</sub>)</td></tr>
                  <tr><td align="left" port="r1">S → S b . </td></tr>
                </table>>];
                "state4" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
                  <tr><td>(I<sub>4</sub>)</td></tr>
                  <tr><td align="left" port="r3"> S → a L . </td></tr>
                  <tr><td align="left" port="r5"> L → L . a </td></tr>
                </table>>];
                "state5" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
                  <tr><td>(I<sub>5</sub>)</td></tr>
                  <tr><td align="left" port="r1"> L → b . </td></tr>
                </table>>];
                "state6" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
                  <tr><td>(I<sub>6</sub>)</td></tr>
                  <tr><td align="left" port="r1"> L → L a . </td></tr>
                </table>>];

                state0 -> state1 [ label = "S" ];
                state0 -> state2 [ label = "a" ];
                state1 -> state3 [  label = "b" ];
                state2 -> state4 [  label = "L" ];
                state2 -> state5 [  label = "b" ];
                state4 -> state6 [  label = "a" ];
              }

        .. class:: step

            * follow(S)  = {$, b}

        ----

    :class: t2c

    **An Especial Grammar**
    #. S → L = R
    #. S → R
    #. L → * R
    #. L → a
    #. R → L

    .. container:: step

      Augmented Grammer

      * S' → S

      #. S → L = R
      #. S → R
      #. L → * R
      #. L → a
      #. R → L

.. slido::

    .. yographviz::

          digraph g {
            graph [splines=true  rankdir = "LR"];
            ratio = auto;
            "state0" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>0</sub>)</td></tr>
              <tr><td align="left" port="r0">S' → . S </td></tr>
              <tr><td align="left" port="r1">S  → . L = R </td></tr>
              <tr><td align="left" port="r2">S  → . R </td></tr>
              <tr><td align="left" port="r3">L  → . * R </td></tr>
              <tr><td align="left" port="r4">L  → . a </td></tr>
              <tr><td align="left" port="r5">R  → . L </td></tr>
            </table>>];
            "state1" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>1</sub>)</td></tr>
              <tr><td align="left" port="r3">S' → S . </td></tr>
            </table>> ];
            "state2" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>2</sub>)</td></tr>
              <tr><td align="left" port="r1">S → L . = R </td></tr>
              <tr><td align="left" port="r5">R → L . </td></tr>
            </table>>];
            "state3" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>3</sub>)</td></tr>
              <tr><td align="left" port="r1">S → R . </td></tr>
            </table>>];
            "state4" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>4</sub>)</td></tr>
              <tr><td align="left" port="r3">L → * . R </td></tr>
              <tr><td align="left" port="r5">R → . L </td></tr>
              <tr><td align="left" port="r3">L → . * R </td></tr>
              <tr><td align="left" port="r4">L → . a </td></tr>
            </table>>];
            "state5" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>5</sub>)</td></tr>
              <tr><td align="left" port="r1">L → a . </td></tr>
            </table>>];
            "state6" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>6</sub>)</td></tr>
              <tr><td align="left" port="r1">L → * R . </td></tr>
            </table>>];
            "state7" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>7</sub>)</td></tr>
              <tr><td align="left" port="r1">R → L . </td></tr>
            </table>>];
            "state8" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>8</sub>)</td></tr>
              <tr><td align="left" port="r1">S → L = . R </td></tr>
              <tr><td align="left" port="r5">R → . L </td></tr>
              <tr><td align="left" port="r3">L → . * R </td></tr>
              <tr><td align="left" port="r4">L → . a </td></tr>
            </table>>];
            "state9" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>9</sub>)</td></tr>
              <tr><td align="left" port="r1">S → L = R . </td></tr>
            </table>>];

            "I7"     [ shape = "circle"  label = "I7"]
            "I4"     [ shape = "circle"  label = "I4"]
            "I5"     [ shape = "circle"  label = "I5"]
            state0 -> state1 [ label = "S" ];
            state0 -> state2 [ label = "L" ];
            state0 -> state3 [ label = "R" ];
            state0 -> state4 [  label = "*" ];
            state0 -> state5 [  label = "a" ];
            state4 -> state6 [  label = "R" ];
            state4 -> state7 [  label = "L" ];
            state4 -> state4 [  label = "*" ];
            state4 -> state5 [  label = "a" ];
            state2 -> state8 [  label = "=" ];
            state8 -> state9 [  label = "R" ];
            state8 -> I7 [  label = "L" ];
            state8 -> I4 [  label = "*" ];
            state8 -> I5 [  label = "a" ];
          }

.. slido::
   :class: t2c

    * first(S)  = {a, `*`}
    * first(L)  = {a, `*`}
    * first(R)  = {a, `*`}
    * follow(S) = {$, =}
    * follow(L) = {$, =}
    * follow(R) = {$, =}

    .. csv-table::
      :header-rows: 1
      :class: smallerelementwithfullborder equal-col

      t , a , * , = , $ , S , L , R
      I0, s5, s4,   ,   , 1 , 2 , 3
      I1,   ,   ,   ,acc,   ,   ,
      I2,   ,   ,s8/   ,   ,   ,   ,
      I3,   ,   ,   ,   ,   ,   ,
      I4,   ,   ,   ,   ,   ,   ,
      I5,   ,   ,   ,   ,   ,   ,
      I6,   ,   ,   ,   ,   ,   ,
      I7,   ,   ,   ,   ,   ,   ,
      I8,   ,   ,   ,   ,   ,   ,

.. slido::

    .. yographviz::

          digraph g {
            graph [splines=true  rankdir = "LR"];
            ratio = auto;
            "state0" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>0</sub>)</td></tr>
              <tr><td align="left" port="r0">S' → . S , $ </td></tr>
              <tr><td align="left" port="r1">S  → . L = R , $ </td></tr>
              <tr><td align="left" port="r2">S  → . R , $ </td></tr>
              <tr><td align="left" port="r3">L  → . * R , = $ </td></tr>
              <tr><td align="left" port="r4">L  → . a , = $ </td></tr>
              <tr><td align="left" port="r5">R  → . L , $ </td></tr>
            </table>>];
            "state1" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>1</sub>)</td></tr>
              <tr><td align="left" port="r3">S' → S . , $ </td></tr>
            </table>> ];
            "state2" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>2</sub>)</td></tr>
              <tr><td align="left" port="r1">S → L . = R , $</td></tr>
              <tr><td align="left" port="r5">R → L . , $ </td></tr>
            </table>>];
            "state3" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>3</sub>)</td></tr>
              <tr><td align="left" port="r1">S → R . , $ </td></tr>
            </table>>];
            "state4" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>4</sub>)</td></tr>
              <tr><td align="left" port="r3">L → * . R , = $ </td></tr>
              <tr><td align="left" port="r5">R → . L , = $</td></tr>
              <tr><td align="left" port="r3">L → . * R , = $ </td></tr>
              <tr><td align="left" port="r4">L → . a , = $ </td></tr>
            </table>>];
            "state5" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>5</sub>)</td></tr>
              <tr><td align="left" port="r1">L → a . , = $ </td></tr>
            </table>>];
            "state6" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>6</sub>)</td></tr>
              <tr><td align="left" port="r1">L → * R . , = $ </td></tr>
            </table>>];
            "state7" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>7</sub>)</td></tr>
              <tr><td align="left" port="r1">R → L . , = $ </td></tr>
            </table>>];
            "state8" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>8</sub>)</td></tr>
              <tr><td align="left" port="r1">S → L = . R , $ </td></tr>
              <tr><td align="left" port="r5">R → . L , $</td></tr>
              <tr><td align="left" port="r3">L → . * R  , $</td></tr>
              <tr><td align="left" port="r4">L → . a , $ </td></tr>
            </table>>];
            "state9" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>9</sub>)</td></tr>
              <tr><td align="left" port="r1">S → L = R . , $ </td></tr>
            </table>>];

            "I7"     [ shape = "circle"  label = "I7"]
            "I4"     [ shape = "circle"  label = "I4"]
            "I5"     [ shape = "circle"  label = "I5"]
            state0 -> state1 [ label = "S" ];
            state0 -> state2 [ label = "L" ];
            state0 -> state3 [ label = "R" ];
            state0 -> state4 [  label = "*" ];
            state0 -> state5 [  label = "a" ];
            state4 -> state6 [  label = "R" ];
            state4 -> state7 [  label = "L" ];
            state4 -> state4 [  label = "*" ];
            state4 -> state5 [  label = "a" ];
            state2 -> state8 [  label = "=" ];
            state8 -> state9 [  label = "R" ];
            state8 -> I7 [  label = "L" ];
            state8 -> I4 [  label = "*" ];
            state8 -> I5 [  label = "a" ];
          }

.. slido:: Look ahead

    .. yographviz::

          digraph g {
            graph [splines=true  rankdir = "LR"];
            ratio = auto;
            "state0" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>0</sub>)</td></tr>
              <tr><td align="left" port="r0">S' → .S, $</td></tr>
              <tr><td align="left" port="r1">S → .L = R, $ </td></tr>
              <tr><td align="left" port="r2">S → .R , $ </td></tr>
              <tr><td align="left" port="r3">L → .* R, = </td></tr>
              <tr><td align="left" port="r4">L → .a, = </td></tr>
              <tr><td align="left" port="r5">R → .L, $ </td></tr>
            </table>>];
            "state1" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>1</sub>)</td></tr>
              <tr><td align="left" port="r3">S' → S. </td></tr>
            </table>> ];
            "state2" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>2</sub>)</td></tr>
              <tr><td align="left" port="r1">S → L. = R </td></tr>
              <tr><td align="left" port="r5">R → L. </td></tr>
            </table>>];
            "state3" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>3</sub>)</td></tr>
              <tr><td align="left" port="r1">S → R. </td></tr>
            </table>>];
            "state4" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>4</sub>)</td></tr>
              <tr><td align="left" port="r3">L → *.R </td></tr>
              <tr><td align="left" port="r5">R → .L </td></tr>
              <tr><td align="left" port="r3">L → .* R </td></tr>
              <tr><td align="left" port="r4">L → .a </td></tr>
            </table>>];
            "state5" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>5</sub>)</td></tr>
              <tr><td align="left" port="r1">L → a. </td></tr>
            </table>>];
            "state6" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>6</sub>)</td></tr>
              <tr><td align="left" port="r1">L → * R. </td></tr>
            </table>>];
            "state7" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>7</sub>)</td></tr>
              <tr><td align="left" port="r1">R → L. </td></tr>
            </table>>];
            "state8" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>8</sub>)</td></tr>
              <tr><td align="left" port="r1">S → L =. R </td></tr>
              <tr><td align="left" port="r5">R → .L </td></tr>
              <tr><td align="left" port="r3">L → .* R </td></tr>
              <tr><td align="left" port="r4">L → .a </td></tr>
            </table>>];
            "state9" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>9</sub>)</td></tr>
              <tr><td align="left" port="r1">S → L = R. </td></tr>
            </table>>];

            "I7"     [ shape = "circle"  label = "I7"]
            "I4"     [ shape = "circle"  label = "I4"]
            "I5"     [ shape = "circle"  label = "I5"]
            state0 -> state1 [ label = "S" ];
            state0 -> state2 [ label = "L" ];
            state0 -> state3 [ label = "R" ];
            state0 -> state4 [  label = "*" ];
            state0 -> state5 [  label = "a" ];
            state4 -> state6 [  label = "R" ];
            state4 -> state7 [  label = "L" ];
            state4 -> state4 [  label = "*" ];
            state4 -> state5 [  label = "a" ];
            state2 -> state8 [  label = "=" ];
            state8 -> state9 [  label = "R" ];
            state8 -> I7 [  label = "L" ];
            state8 -> I4 [  label = "*" ];
            state8 -> I5 [  label = "a" ];
          }

.. slido::

    .. yographviz::

          digraph g {
            graph [splines=true  rankdir = "LR"];
            ratio = auto;
            "state0" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>0</sub>)</td></tr>
              <tr><td align="left" port="r0">S' → .S, $</td></tr>
              <tr><td align="left" port="r1">S → .L = R, $ </td></tr>
              <tr><td align="left" port="r2">S → .R , $ </td></tr>
              <tr><td align="left" port="r3">L → .* R, = $ </td></tr>
              <tr><td align="left" port="r4">L → .a, = $ </td></tr>
              <tr><td align="left" port="r5">R → .L, $ </td></tr>
            </table>>];
            "state1" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>1</sub>)</td></tr>
              <tr><td align="left" port="r3">S' → S. </td></tr>
            </table>> ];
            "state2" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>2</sub>)</td></tr>
              <tr><td align="left" port="r1">S → L. = R </td></tr>
              <tr><td align="left" port="r5">R → L. </td></tr>
            </table>>];
            "state3" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>3</sub>)</td></tr>
              <tr><td align="left" port="r1">S → R. </td></tr>
            </table>>];
            "state4" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>4</sub>)</td></tr>
              <tr><td align="left" port="r3">L → *.R </td></tr>
              <tr><td align="left" port="r5">R → .L </td></tr>
              <tr><td align="left" port="r3">L → .* R </td></tr>
              <tr><td align="left" port="r4">L → .a </td></tr>
            </table>>];
            "state5" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>5</sub>)</td></tr>
              <tr><td align="left" port="r1">L → a. </td></tr>
            </table>>];
            "state6" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>6</sub>)</td></tr>
              <tr><td align="left" port="r1">L → * R. </td></tr>
            </table>>];
            "state7" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>7</sub>)</td></tr>
              <tr><td align="left" port="r1">R → L. </td></tr>
            </table>>];
            "state8" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>8</sub>)</td></tr>
              <tr><td align="left" port="r1">S → L =. R </td></tr>
              <tr><td align="left" port="r5">R → .L </td></tr>
              <tr><td align="left" port="r3">L → .* R </td></tr>
              <tr><td align="left" port="r4">L → .a </td></tr>
            </table>>];
            "state9" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>9</sub>)</td></tr>
              <tr><td align="left" port="r1">S → L = R. </td></tr>
            </table>>];

            "I7"     [ shape = "circle"  label = "I7"]
            "I4"     [ shape = "circle"  label = "I4"]
            "I5"     [ shape = "circle"  label = "I5"]
            state0 -> state1 [ label = "S" ];
            state0 -> state2 [ label = "L" ];
            state0 -> state3 [ label = "R" ];
            state0 -> state4 [  label = "*" ];
            state0 -> state5 [  label = "a" ];
            state4 -> state6 [  label = "R" ];
            state4 -> state7 [  label = "L" ];
            state4 -> state4 [  label = "*" ];
            state4 -> state5 [  label = "a" ];
            state2 -> state8 [  label = "=" ];
            state8 -> state9 [  label = "R" ];
            state8 -> I7 [  label = "L" ];
            state8 -> I4 [  label = "*" ];
            state8 -> I5 [  label = "a" ];
          }

.. slido::

    .. yographviz::

          digraph g {
            graph [splines=true  rankdir = "LR"];
            ratio = auto;
            "state0" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>0</sub>)</td></tr>
              <tr><td align="left" port="r0">S' → .S, $</td></tr>
              <tr><td align="left" port="r1">S → .L = R, $ </td></tr>
              <tr><td align="left" port="r2">S → .R , $ </td></tr>
              <tr><td align="left" port="r3">L → .* R, = $ </td></tr>
              <tr><td align="left" port="r4">L → .a, = $ </td></tr>
              <tr><td align="left" port="r5">R → .L, $ </td></tr>
            </table>>];
            "state1" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>1</sub>)</td></tr>
              <tr><td align="left" port="r3">S' → S., $ </td></tr>
            </table>> ];
            "state2" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>2</sub>)</td></tr>
              <tr><td align="left" port="r1">S → L. = R </td></tr>
              <tr><td align="left" port="r5">R → L. </td></tr>
            </table>>];
            "state3" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>3</sub>)</td></tr>
              <tr><td align="left" port="r1">S → R. </td></tr>
            </table>>];
            "state4" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>4</sub>)</td></tr>
              <tr><td align="left" port="r3">L → *.R </td></tr>
              <tr><td align="left" port="r5">R → .L </td></tr>
              <tr><td align="left" port="r3">L → .* R </td></tr>
              <tr><td align="left" port="r4">L → .a </td></tr>
            </table>>];
            "state5" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>5</sub>)</td></tr>
              <tr><td align="left" port="r1">L → a. </td></tr>
            </table>>];
            "state6" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>6</sub>)</td></tr>
              <tr><td align="left" port="r1">L → * R. </td></tr>
            </table>>];
            "state7" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>7</sub>)</td></tr>
              <tr><td align="left" port="r1">R → L. </td></tr>
            </table>>];
            "state8" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>8</sub>)</td></tr>
              <tr><td align="left" port="r1">S → L =. R </td></tr>
              <tr><td align="left" port="r5">R → .L </td></tr>
              <tr><td align="left" port="r3">L → .* R </td></tr>
              <tr><td align="left" port="r4">L → .a </td></tr>
            </table>>];
            "state9" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>9</sub>)</td></tr>
              <tr><td align="left" port="r1">S → L = R. </td></tr>
            </table>>];

            "I7"     [ shape = "circle"  label = "I7"]
            "I4"     [ shape = "circle"  label = "I4"]
            "I5"     [ shape = "circle"  label = "I5"]
            state0 -> state1 [ label = "S" ];
            state0 -> state2 [ label = "L" ];
            state0 -> state3 [ label = "R" ];
            state0 -> state4 [  label = "*" ];
            state0 -> state5 [  label = "a" ];
            state4 -> state6 [  label = "R" ];
            state4 -> state7 [  label = "L" ];
            state4 -> state4 [  label = "*" ];
            state4 -> state5 [  label = "a" ];
            state2 -> state8 [  label = "=" ];
            state8 -> state9 [  label = "R" ];
            state8 -> I7 [  label = "L" ];
            state8 -> I4 [  label = "*" ];
            state8 -> I5 [  label = "a" ];
          }

.. slido::

    .. yographviz::

          digraph g {
            graph [splines=true  rankdir = "LR"];
            ratio = auto;
            "state0" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>0</sub>)</td></tr>
              <tr><td align="left" port="r0">S' → .S, $</td></tr>
              <tr><td align="left" port="r1">S → .L = R, $ </td></tr>
              <tr><td align="left" port="r2">S → .R , $ </td></tr>
              <tr><td align="left" port="r3">L → .* R, = $ </td></tr>
              <tr><td align="left" port="r4">L → .a, = $ </td></tr>
              <tr><td align="left" port="r5">R → .L, $ </td></tr>
            </table>>];
            "state1" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>1</sub>)</td></tr>
              <tr><td align="left" port="r3">S' → S., $ </td></tr>
            </table>> ];
            "state2" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>2</sub>)</td></tr>
              <tr><td align="left" port="r1">S → L. = R, $ </td></tr>
              <tr><td align="left" port="r5">R → L., $ </td></tr>
            </table>>];
            "state3" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>3</sub>)</td></tr>
              <tr><td align="left" port="r1">S → R. </td></tr>
            </table>>];
            "state4" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>4</sub>)</td></tr>
              <tr><td align="left" port="r3">L → *.R </td></tr>
              <tr><td align="left" port="r5">R → .L </td></tr>
              <tr><td align="left" port="r3">L → .* R </td></tr>
              <tr><td align="left" port="r4">L → .a </td></tr>
            </table>>];
            "state5" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>5</sub>)</td></tr>
              <tr><td align="left" port="r1">L → a. </td></tr>
            </table>>];
            "state6" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>6</sub>)</td></tr>
              <tr><td align="left" port="r1">L → * R. </td></tr>
            </table>>];
            "state7" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>7</sub>)</td></tr>
              <tr><td align="left" port="r1">R → L. </td></tr>
            </table>>];
            "state8" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>8</sub>)</td></tr>
              <tr><td align="left" port="r1">S → L =. R </td></tr>
              <tr><td align="left" port="r5">R → .L </td></tr>
              <tr><td align="left" port="r3">L → .* R </td></tr>
              <tr><td align="left" port="r4">L → .a </td></tr>
            </table>>];
            "state9" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>9</sub>)</td></tr>
              <tr><td align="left" port="r1">S → L = R. </td></tr>
            </table>>];

            "I7"     [ shape = "circle"  label = "I7"]
            "I4"     [ shape = "circle"  label = "I4"]
            "I5"     [ shape = "circle"  label = "I5"]
            state0 -> state1 [ label = "S" ];
            state0 -> state2 [ label = "L" ];
            state0 -> state3 [ label = "R" ];
            state0 -> state4 [  label = "*" ];
            state0 -> state5 [  label = "a" ];
            state4 -> state6 [  label = "R" ];
            state4 -> state7 [  label = "L" ];
            state4 -> state4 [  label = "*" ];
            state4 -> state5 [  label = "a" ];
            state2 -> state8 [  label = "=" ];
            state8 -> state9 [  label = "R" ];
            state8 -> I7 [  label = "L" ];
            state8 -> I4 [  label = "*" ];
            state8 -> I5 [  label = "a" ];
          }

.. slido::

    .. yographviz::

          digraph g {
            graph [splines=true  rankdir = "LR"];
            ratio = auto;
            "state0" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>0</sub>)</td></tr>
              <tr><td align="left" port="r0">S' → .S, $</td></tr>
              <tr><td align="left" port="r1">S → .L = R, $ </td></tr>
              <tr><td align="left" port="r2">S → .R , $ </td></tr>
              <tr><td align="left" port="r3">L → .* R, = $ </td></tr>
              <tr><td align="left" port="r4">L → .a, = $ </td></tr>
              <tr><td align="left" port="r5">R → .L, $ </td></tr>
            </table>>];
            "state1" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>1</sub>)</td></tr>
              <tr><td align="left" port="r3">S' → S., $ </td></tr>
            </table>> ];
            "state2" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>2</sub>)</td></tr>
              <tr><td align="left" port="r1">S → L. = R, $ </td></tr>
              <tr><td align="left" port="r5">R → L., $ </td></tr>
            </table>>];
            "state3" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>3</sub>)</td></tr>
              <tr><td align="left" port="r1">S → R., $ </td></tr>
            </table>>];
            "state4" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>4</sub>)</td></tr>
              <tr><td align="left" port="r3">L → *.R </td></tr>
              <tr><td align="left" port="r5">R → .L </td></tr>
              <tr><td align="left" port="r3">L → .* R </td></tr>
              <tr><td align="left" port="r4">L → .a </td></tr>
            </table>>];
            "state5" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>5</sub>)</td></tr>
              <tr><td align="left" port="r1">L → a. </td></tr>
            </table>>];
            "state6" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>6</sub>)</td></tr>
              <tr><td align="left" port="r1">L → * R. </td></tr>
            </table>>];
            "state7" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>7</sub>)</td></tr>
              <tr><td align="left" port="r1">R → L. </td></tr>
            </table>>];
            "state8" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>8</sub>)</td></tr>
              <tr><td align="left" port="r1">S → L =. R </td></tr>
              <tr><td align="left" port="r5">R → .L </td></tr>
              <tr><td align="left" port="r3">L → .* R </td></tr>
              <tr><td align="left" port="r4">L → .a </td></tr>
            </table>>];
            "state9" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>9</sub>)</td></tr>
              <tr><td align="left" port="r1">S → L = R. </td></tr>
            </table>>];

            "I7"     [ shape = "circle"  label = "I7"]
            "I4"     [ shape = "circle"  label = "I4"]
            "I5"     [ shape = "circle"  label = "I5"]
            state0 -> state1 [ label = "S" ];
            state0 -> state2 [ label = "L" ];
            state0 -> state3 [ label = "R" ];
            state0 -> state4 [  label = "*" ];
            state0 -> state5 [  label = "a" ];
            state4 -> state6 [  label = "R" ];
            state4 -> state7 [  label = "L" ];
            state4 -> state4 [  label = "*" ];
            state4 -> state5 [  label = "a" ];
            state2 -> state8 [  label = "=" ];
            state8 -> state9 [  label = "R" ];
            state8 -> I7 [  label = "L" ];
            state8 -> I4 [  label = "*" ];
            state8 -> I5 [  label = "a" ];
          }

.. slido::

    .. yographviz::

          digraph g {
            graph [splines=true  rankdir = "LR"];
            ratio = auto;
            "state0" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>0</sub>)</td></tr>
              <tr><td align="left" port="r0">S' → .S, $</td></tr>
              <tr><td align="left" port="r1">S → .L = R, $ </td></tr>
              <tr><td align="left" port="r2">S → .R , $ </td></tr>
              <tr><td align="left" port="r3">L → .* R, = $ </td></tr>
              <tr><td align="left" port="r4">L → .a, = $ </td></tr>
              <tr><td align="left" port="r5">R → .L, $ </td></tr>
            </table>>];
            "state1" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>1</sub>)</td></tr>
              <tr><td align="left" port="r3">S' → S., $ </td></tr>
            </table>> ];
            "state2" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>2</sub>)</td></tr>
              <tr><td align="left" port="r1">S → L. = R, $ </td></tr>
              <tr><td align="left" port="r5">R → L., $ </td></tr>
            </table>>];
            "state3" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>3</sub>)</td></tr>
              <tr><td align="left" port="r1">S → R., $ </td></tr>
            </table>>];
            "state4" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>4</sub>)</td></tr>
              <tr><td align="left" port="r3">L → *.R,  </td></tr>
              <tr><td align="left" port="r5">R → .L </td></tr>
              <tr><td align="left" port="r3">L → .* R </td></tr>
              <tr><td align="left" port="r4">L → .a </td></tr>
            </table>>];
            "state5" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>5</sub>)</td></tr>
              <tr><td align="left" port="r1">L → a. </td></tr>
            </table>>];
            "state6" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>6</sub>)</td></tr>
              <tr><td align="left" port="r1">L → * R. </td></tr>
            </table>>];
            "state7" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>7</sub>)</td></tr>
              <tr><td align="left" port="r1">R → L. </td></tr>
            </table>>];
            "state8" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>8</sub>)</td></tr>
              <tr><td align="left" port="r1">S → L =. R, $ </td></tr>
              <tr><td align="left" port="r5">R → .L, $</td></tr>
              <tr><td align="left" port="r3">L → .* R, $ </td></tr>
              <tr><td align="left" port="r4">L → .a, $ </td></tr>
            </table>>];
            "state9" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>9</sub>)</td></tr>
              <tr><td align="left" port="r1">S → L = R. </td></tr>
            </table>>];

            "I7"     [ shape = "circle"  label = "I7"]
            "I4"     [ shape = "circle"  label = "I4"]
            "I5"     [ shape = "circle"  label = "I5"]
            state0 -> state1 [ label = "S" ];
            state0 -> state2 [ label = "L" ];
            state0 -> state3 [ label = "R" ];
            state0 -> state4 [  label = "*" ];
            state0 -> state5 [  label = "a" ];
            state4 -> state6 [  label = "R" ];
            state4 -> state7 [  label = "L" ];
            state4 -> state4 [  label = "*" ];
            state4 -> state5 [  label = "a" ];
            state2 -> state8 [  label = "=" ];
            state8 -> state9 [  label = "R" ];
            state8 -> I7 [  label = "L" ];
            state8 -> I4 [  label = "*" ];
            state8 -> I5 [  label = "a" ];
          }

.. slido::

    .. yographviz::

          digraph g {
            graph [splines=true  rankdir = "LR"];
            ratio = auto;
            "state0" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>0</sub>)</td></tr>
              <tr><td align="left" port="r0">S' → .S, $</td></tr>
              <tr><td align="left" port="r1">S → .L = R, $ </td></tr>
              <tr><td align="left" port="r2">S → .R , $ </td></tr>
              <tr><td align="left" port="r3">L → .* R, = $ </td></tr>
              <tr><td align="left" port="r4">L → .a, = $ </td></tr>
              <tr><td align="left" port="r5">R → .L, $ </td></tr>
            </table>>];
            "state1" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>1</sub>)</td></tr>
              <tr><td align="left" port="r3">S' → S., $ </td></tr>
            </table>> ];
            "state2" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>2</sub>)</td></tr>
              <tr><td align="left" port="r1">S → L. = R, $ </td></tr>
              <tr><td align="left" port="r5">R → L., $ </td></tr>
            </table>>];
            "state3" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>3</sub>)</td></tr>
              <tr><td align="left" port="r1">S → R., $ </td></tr>
            </table>>];
            "state4" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>4</sub>)</td></tr>
              <tr><td align="left" port="r3">L → *.R, = $ </td></tr>
              <tr><td align="left" port="r5">R → .L, = $ </td></tr>
              <tr><td align="left" port="r3">L → .* R, = $ </td></tr>
              <tr><td align="left" port="r4">L → .a, = $ </td></tr>
            </table>>];
            "state5" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>5</sub>)</td></tr>
              <tr><td align="left" port="r1">L → a. </td></tr>
            </table>>];
            "state6" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>6</sub>)</td></tr>
              <tr><td align="left" port="r1">L → * R. </td></tr>
            </table>>];
            "state7" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>7</sub>)</td></tr>
              <tr><td align="left" port="r1">R → L. </td></tr>
            </table>>];
            "state8" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>8</sub>)</td></tr>
              <tr><td align="left" port="r1">S → L =. R, $ </td></tr>
              <tr><td align="left" port="r5">R → .L, $</td></tr>
              <tr><td align="left" port="r3">L → .* R, $ </td></tr>
              <tr><td align="left" port="r4">L → .a, $ </td></tr>
            </table>>];
            "state9" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>9</sub>)</td></tr>
              <tr><td align="left" port="r1">S → L = R. </td></tr>
            </table>>];

            "I7"     [ shape = "circle"  label = "I7"]
            "I4"     [ shape = "circle"  label = "I4"]
            "I5"     [ shape = "circle"  label = "I5"]
            state0 -> state1 [ label = "S" ];
            state0 -> state2 [ label = "L" ];
            state0 -> state3 [ label = "R" ];
            state0 -> state4 [  label = "*" ];
            state0 -> state5 [  label = "a" ];
            state4 -> state6 [  label = "R" ];
            state4 -> state7 [  label = "L" ];
            state4 -> state4 [  label = "*" ];
            state4 -> state5 [  label = "a" ];
            state2 -> state8 [  label = "=" ];
            state8 -> state9 [  label = "R" ];
            state8 -> I7 [  label = "L" ];
            state8 -> I4 [  label = "*" ];
            state8 -> I5 [  label = "a" ];
          }

.. slido::

    .. yographviz::

          digraph g {
            graph [splines=true  rankdir = "LR"];
            ratio = auto;
            "state0" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>0</sub>)</td></tr>
              <tr><td align="left" port="r0">S' → .S, $</td></tr>
              <tr><td align="left" port="r1">S → .L = R, $ </td></tr>
              <tr><td align="left" port="r2">S → .R , $ </td></tr>
              <tr><td align="left" port="r3">L → .* R, = $ </td></tr>
              <tr><td align="left" port="r4">L → .a, = $ </td></tr>
              <tr><td align="left" port="r5">R → .L, $ </td></tr>
            </table>>];
            "state1" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>1</sub>)</td></tr>
              <tr><td align="left" port="r3">S' → S., $ </td></tr>
            </table>> ];
            "state2" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>2</sub>)</td></tr>
              <tr><td align="left" port="r1">S → L. = R, $ </td></tr>
              <tr><td align="left" port="r5">R → L., $ </td></tr>
            </table>>];
            "state3" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>3</sub>)</td></tr>
              <tr><td align="left" port="r1">S → R., $ </td></tr>
            </table>>];
            "state4" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>4</sub>)</td></tr>
              <tr><td align="left" port="r3">L → *.R, = $ </td></tr>
              <tr><td align="left" port="r5">R → .L, = $ </td></tr>
              <tr><td align="left" port="r3">L → .* R, = $ </td></tr>
              <tr><td align="left" port="r4">L → .a, = $ </td></tr>
            </table>>];
            "state5" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>5</sub>)</td></tr>
              <tr><td align="left" port="r1">L → a., = $ </td></tr>
            </table>>];
            "state6" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>6</sub>)</td></tr>
              <tr><td align="left" port="r1">L → * R., = $ </td></tr>
            </table>>];
            "state7" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>7</sub>)</td></tr>
              <tr><td align="left" port="r1">R → L., = $ </td></tr>
            </table>>];
            "state8" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>8</sub>)</td></tr>
              <tr><td align="left" port="r1">S → L =. R, $ </td></tr>
              <tr><td align="left" port="r5">R → .L, $</td></tr>
              <tr><td align="left" port="r3">L → .* R, $ </td></tr>
              <tr><td align="left" port="r4">L → .a, $ </td></tr>
            </table>>];
            "state9" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>9</sub>)</td></tr>
              <tr><td align="left" port="r1">S → L = R. </td></tr>
            </table>>];

            "I7"     [ shape = "circle"  label = "I7"]
            "I4"     [ shape = "circle"  label = "I4"]
            "I5"     [ shape = "circle"  label = "I5"]
            state0 -> state1 [ label = "S" ];
            state0 -> state2 [ label = "L" ];
            state0 -> state3 [ label = "R" ];
            state0 -> state4 [  label = "*" ];
            state0 -> state5 [  label = "a" ];
            state4 -> state6 [  label = "R" ];
            state4 -> state7 [  label = "L" ];
            state4 -> state4 [  label = "*" ];
            state4 -> state5 [  label = "a" ];
            state2 -> state8 [  label = "=" ];
            state8 -> state9 [  label = "R" ];
            state8 -> I7 [  label = "L" ];
            state8 -> I4 [  label = "*" ];
            state8 -> I5 [  label = "a" ];
          }

.. slido::

    .. yographviz::

          digraph g {
            graph [splines=true  rankdir = "LR"];
            ratio = auto;
            "state0" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>0</sub>)</td></tr>
              <tr><td align="left" port="r0">S' → .S, $</td></tr>
              <tr><td align="left" port="r1">S → .L = R, $ </td></tr>
              <tr><td align="left" port="r2">S → .R , $ </td></tr>
              <tr><td align="left" port="r3">L → .* R, = $ </td></tr>
              <tr><td align="left" port="r4">L → .a, = $ </td></tr>
              <tr><td align="left" port="r5">R → .L, $ </td></tr>
            </table>>];
            "state1" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>1</sub>)</td></tr>
              <tr><td align="left" port="r3">S' → S., $ </td></tr>
            </table>> ];
            "state2" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>2</sub>)</td></tr>
              <tr><td align="left" port="r1">S → L. = R, $ </td></tr>
              <tr><td align="left" port="r5">R → L., $ </td></tr>
            </table>>];
            "state3" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>3</sub>)</td></tr>
              <tr><td align="left" port="r1">S → R., $ </td></tr>
            </table>>];
            "state4" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>4</sub>)</td></tr>
              <tr><td align="left" port="r3">L → *.R, = $ </td></tr>
              <tr><td align="left" port="r5">R → .L, = $ </td></tr>
              <tr><td align="left" port="r3">L → .* R, = $ </td></tr>
              <tr><td align="left" port="r4">L → .a, = $ </td></tr>
            </table>>];
            "state5" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>5</sub>)</td></tr>
              <tr><td align="left" port="r1">L → a., = $ </td></tr>
            </table>>];
            "state6" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>6</sub>)</td></tr>
              <tr><td align="left" port="r1">L → * R., = $ </td></tr>
            </table>>];
            "state7" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>7</sub>)</td></tr>
              <tr><td align="left" port="r1">R → L., = $ </td></tr>
            </table>>];
            "state8" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>8</sub>)</td></tr>
              <tr><td align="left" port="r1">S → L =. R, $ </td></tr>
              <tr><td align="left" port="r5">R → .L, $</td></tr>
              <tr><td align="left" port="r3">L → .* R, $ </td></tr>
              <tr><td align="left" port="r4">L → .a, $ </td></tr>
            </table>>];
            "state9" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>9</sub>)</td></tr>
              <tr><td align="left" port="r1">S → L = R., $ </td></tr>
            </table>>];

            "I7"     [ shape = "circle"  label = "I7"]
            "I4"     [ shape = "circle"  label = "I4"]
            "I5"     [ shape = "circle"  label = "I5"]
            state0 -> state1 [ label = "S" ];
            state0 -> state2 [ label = "L" ];
            state0 -> state3 [ label = "R" ];
            state0 -> state4 [  label = "*" ];
            state0 -> state5 [  label = "a" ];
            state4 -> state6 [  label = "R" ];
            state4 -> state7 [  label = "L" ];
            state4 -> state4 [  label = "*" ];
            state4 -> state5 [  label = "a" ];
            state2 -> state8 [  label = "=" ];
            state8 -> state9 [  label = "R" ];
            state8 -> I7 [  label = "L" ];
            state8 -> I4 [  label = "*" ];
            state8 -> I5 [  label = "a" ];
          }

.. slido:: LALR

    .. csv-table::
      :header-rows: 1
      :class: smallerelementwithfullborder equal-col

      t , a , * , = , $ , S , L , R
      I0, s5, s4,   ,   , 1 , 2 , 3
      I1,   ,   ,   ,acc,   ,   ,
      I2,   ,   ,s8/   ,   ,   ,   ,
      I3,   ,   ,   ,   ,   ,   ,
      I4,   ,   ,   ,   ,   ,   ,
      I5,   ,   ,   ,   ,   ,   ,
      I6,   ,   ,   ,   ,   ,   ,
      I7,   ,   ,   ,   ,   ,   ,
      I8,   ,   ,   ,   ,   ,   ,

.. slido::

    END
