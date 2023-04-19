:data-transition-duration: 1000
:skip-help: true
:css: style.css
:substep: true
:slide-numbers: true

----

Intermediate Code generation
================================
Ahmad Yoosofan

Compiler course

University of Kashan, Spring 2020

----

Three-Address Statements
=============================
.. class:: substep

    * Binary Operators

        * op x, y, result    // result = x op y
        * add  a,b,c    // c = a + b
        * gt   a,b,c    // c = a > b
        * addr a,b,c
        * addi a,b,c

    * Unary Operators

        * op x,,result   //   result = op x
        * uminus    a,,c // c = -a
        * not       a,,c // c = not a or c = !a
        * inttoreal a,,c

----

Move & Jump
===============
.. class:: substep

    * Move Operator

        * mov x,,result  //   result = x
        * mov a,,c
        * movi a,,c
        * movr a,,c

    * Unconditional Jump

        * jmp,,L // goto L
        * jmp,,7 // goto statement 7
        * jmp,,-7 // relative backward jump
        * jmp,,+8 // relative forward jump

----

Conditional Jumps
===================
.. class:: substep

    * jmpgt   y,z,L1    // jump to L1 if y>z
    * jmpgte  y,z,L1    // jump to L1 if y>=z
    * jmpe    y,z,L1    // jump to L1 if y==z
    * jmpne   y,z,L1    // jump to L1 if y!=z
    * jmpnz   y,,L1 // jump to L1 if y is not zero
    * jmpz    y,,L1 // jump to L1 if y is zero
    * jmpt    y,,L1 // jump to L1 if y is true
    * jmpf    y,,L1 // jump to L1 if y is false

----

Function Call
==================
.. class:: substep

    * param :math:`x_1`,,
    * param :math:`x_2`,,
    * param :math:`x_3`,,
    * param :math:`x_4`,,
    * param :math:`x_5`,,
    * call  f,5, :math:`t_i`

    Example

    * f(x+1,y)
    * add   x,1,t1
    * param t1,,
    * param y,,
    * call  f,2,t2

----

Arrays & Pointers
======================
.. class:: substep

    Indexed Assignments

    * move y[i],,x or x := y[i]
    * move x,,y[i] or y[i] := x

    Address and Pointer Assignments

    * moveaddr y,,x  or  x := &y
    * movecont y,,x  or  x := `*y`

----

..  csv-table::
    :header: Production, Semantic Rules
    :class: smallerelementwithfullborder yoosofantextalignleft
    :align: center

    "E → :math:`E_1` + T", "E.loc = newTemp(); E.code = :math:`E_1`.code || T.code || ‘add’ || :math:`E_1`.loc || ‘,’ || T.loc || ‘,’ || E.loc || '\\n'"
    "E → T", "E.loc = T.loc; E.code = T.code"
    "T → :math:`T_1` * U", "T.loc = newTemp(); T.code = :math:`T_1`.code || U.code || ‘mult’ || :math:`T_1`.loc || ‘,’ || U.loc || ‘,’ || T.loc || '\\n'"
    "T → U", "T.loc = U.loc; T.code = U.code"
    "U → - F", "U.loc = newTemp(); U.code = F.code || ‘uminus’ || F.loc || ‘,,’ || U.loc || '\\n'"
    "U → F", "U.loc = F.loc; U.code = F.code"
    "F → ( E )", "F.loc = E.loc; F.code = E.code"
    "F → num", "F.loc = n.lexval; F.code = ''"
    "F → id", "F.loc = symbolTable.getLoc(id); F.code = ''"
    "F → C",  "F.loc = C.loc; F.code = C.code"

----

Function Call Rule
=====================

..  csv-table::
    :header: Production, Semantic Rules
    :class: smallerelementwithfullborder yoosofantextalignleft
    :align: center

    "C → id()", "C.loc = newTemp(); C.code = 'call ,' || id || ', 0,' || C.loc || '\\n'"
    "C → id(P)", "C.loc = newTemp(); C.code = P.code || 'call ,' || id || ', ' || P.n || ',' || C.loc || '\\n'"
    "P → id M", "P.n = M.n + 1; P.code = 'param ' || id || ',, \\n' || M.code"
    "M → λ", "M.n = 0; M.code=''"
    "M → , id :math:`M_1`", "M.n = :math:`M_1`.n + 1; M.code = 'param ' || id || ',, \\n' || :math:`M_1`.code"

----

..  csv-table::
    :header: Production, Semantic Rules
    :class: smallerelementwithfullborder yoosofantextalignleft
    :align: center

    START → Q, START.code = Q.code
    Q → λ, Q.code=''
    Q → B :math:`Q_1`, Q.code = B.code || :math:`Q_1`.code
    Q → {:math:`Q_1`}, Q.code = :math:`Q_1`.code;
    B → S, B.code = S.code
    B → {Q}, B.code = Q.code

----

Variable Scope
======================

.. code:: cpp
    :number-lines:
    
    int f(void){
        double x = 1, y = 2;
        int a = 1, b = 2;
        //...
        //...
        //....
        if(a){
            double x = 2; y = 4;
            //....
            //....
            
            while(b){
                double x = y;
                //...
                //...
            }
            while(a){
              double x = 3, z = 2;
              // ...
            }
            //...
            //...
        }
        //...
        //...
    }
            

----

Tree of Symbol Table
===========================
.

----

..  csv-table::
    :header: Production, Semantic Rules
    :class: smallerelementwithfullborder yoosofantextalignleft
    :align: center

    START → Q, START.code = Q.code
    Q → λ, Q.code=''
    Q → B :math:`Q_1`, Q.code = B.code || :math:`Q_1`.code
    Q → {:math:`Q_1`}, Q.code = :math:`Q_1`.code; symbolTable.createNewNode();
    B → S, B.code = S.code
    B → {Q}, B.code = Q.code; symbolTable.createNewNode();

Is it correct?

----

.. code:: cpp
    :number-lines:
    
    int f(void){
        double x = 1, y = 2;
        int a = 1, b = 2;
        //...
        //...
        //....
        if(a){
            double x = 2;
            //....
            //....
            
            while(b){
                double x = 3;
                //...
                //...
            } // destroy x in while(b)
            while(a){
                double x = 3;
                //...
                //...
            } // destroy x in while(a)

            //...
            //...
        } // destroy x in if
        //...
        //...
    } // destroy x in f
            

----

Tree of Symbol Table
===========================
It is more like a stack in run

----

..  csv-table::
    :header: Production, Semantic Rules
    :class: smallerelementwithfullborder yoosofantextalignleft
    :align: center

    START → Q, START.code = Q.code
    Q → λ, Q.code=''
    Q → B :math:`Q_1`, Q.code = B.code || :math:`Q_1`.code
    Q → {M :math:`Q_1` N}, Q.code = :math:`Q_1`.code;
    B → S, B.code = S.code
    B → {M Q N}, B.code = Q.code;
    M → λ,  symbolTable.createNewNode();
    N → λ,  symbolTable.destroyLastNode();

----

..  csv-table::
    :header: Production, Semantic Rules
    :class: smallerelementwithfullborder yoosofantextalignleft
    :align: center

    S → W, S.code = W.code
    S → A;, S.code = A.code
    S → I,  S.code = I.code
    S → D;, S.code = D.code
    S → ;, S.code = ''
    "A → id = E", "A.code = E.code || ‘mov’ || E.loc || ‘,,’  || id.loc || '\\n'"
    "A → E", "A.code = E.code"

----

..  csv-table::
    :header: Production, Semantic Rules
    :class: smallerelementwithfullborder yoosofantextalignleft
    :align: center


    W → while(E) B, "W.begin = newLabel(); W.after = newLabel(); W.code = W.begin || ':' ||  E.code  || ‘jmpf’ || E.loc || ‘,,’ W.after || '\\n`  || B.code || ‘jmp,,’ || W.begin || '\\n'  || W.after ‘:”"
    I → if( E ) B else :math:`B_1`, "I.else = newLabel(); I.after = newLabel();  I.code = E.code  || ‘jmpf’ || E.loc || ‘,,’ || I.else || B.code || ‘jmp,,’ I.after || '\\n' || I.else || ‘:‘ || :math:`B_1`.code || I.after ‘:‘ "


----

End
===========
.

----

.. comments:

    
    hovercraft intermediate_code_generation.rst
    rst2html intermediate_code_generation.rst intermediate_code_generation.rst.html

