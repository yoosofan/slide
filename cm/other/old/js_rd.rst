.. meta::
    :charset: utf-8
    :http-equiv=Content-Type: text/html; charset=utf-8

:data-transition-duration: 1000
:skip-help: true
:css: ./style.css
:substep: true
:slide-numbers: true

.. :

    :js-body: assets/d3.v5.min.js
    :js-body: assets/index.min.js
    :js-body: assets/d3-graphviz.js

.. :

    :js: ./temporary03454-images9877/tex-mml-chtml.js

    :js-body: assets/yoojs.js

----

Recursive Descendant Parser
==============================
Syntax Analysis
-----------------
Ahmad Yoosofan

Compiler course

University of Kashan

https://yoosofan.github.io/course/compiler.html

.. raw:: html

    <script src="https://d3js.org/d3.v5.min.js" charset="utf-8"></script>
    <script src="https://unpkg.com/@hpcc-js/wasm@0.3.11/dist/index.min.js" charset="utf-8"></script>
    <script src="https://unpkg.com/d3-graphviz@3.0.5/build/d3-graphviz.js" charset="utf-8"></script>

.. :

    <script>
      const _ = d3Graphviz.graphviz //Preload d3Graphiz so it register itself in d3 as a plugin
    </script>

----

Special State Diagram for Addition
==========================================
#. 2
#. 2+3
#. 86+54+876+432+32

Grammar
---------
.. class:: substep

#. E → a
#. E → a + E

.. class:: substep

*  E → a + E | a

.. raw:: html

    <div id="yoograph4" class="substep"></div>
    <script>
    d3.select("#yoograph4").graphviz().renderDot(`
      digraph {
        rankdir = "LR"
        node     [shape=circle]
        END      [shape=doublecircle, label="3"]
        0 -> END [label="a"]
        0 -> 1   [label="a"]
        1 -> 2   [label="+"]
        2 -> END [label="E"]
      }
    `);
    </script>


.. class:: substep

  * Which edge must we choose from node 0?
  * Node 1
  * Node 3

.. :

  c_{i_{j_k}}

----

:class: t2c

Left Factoring
=====================
* E → a + E
* E → a

.. raw:: html

    <div id="yoograph5" class="substep"></div>
    <script>
    d3.select("#yoograph5").graphviz().renderDot(`
      digraph {
        rankdir = "LR"
        node     [shape=circle]
        END      [shape=doublecircle, label="3"]
        0 -> END [label="a"]
        0 -> 1   [label="a"]
        1 -> 2   [label="+"]
        2 -> END [label="E"]
      }
    `);
    </script>

.. class:: substep

#. E → a B
#. B → + E
#. B → λ

.. raw:: html

    <div id="yoograph10" class="substep"></div>
    <script>
    d3.select("#yoograph10").graphviz().renderDot(`
      digraph {
          rankdir = "LR"
          node [shape=circle]
          END [shape=doublecircle, label="2"]
          E [shape=plaintext]
          0 -> 1 [label="a"]
          1 -> END [label="B"]
      }
    `);
    </script>

.. raw:: html

    <div id="yoograph20" class="substep"></div>
    <script>
    d3.select("#yoograph20").graphviz().renderDot(`
      digraph {
        rankdir = "LR"
        node [shape=circle]
        END [shape=doublecircle, label="2"]
        B [shape=plaintext]
        0 -> 1 [label="+"]
        1 -> END [label="E"]
        0 -> END [label="λ"]
      }
    `);
    </script>


----

:class: t2c

Parser Code for Add
======================
.. container::

  E

  .. raw:: html

      <div id="yoograph40"></div>
      <script>
      d3.select("#yoograph40").graphviz().renderDot(`
        digraph {
          rankdir = "LR"
          node [shape=circle]
          END [shape=doublecircle, label="2"]
          0 -> 1 [label="a"]
          1 -> END [label="B"]
        }
      `);
      </script>

  B

  .. raw:: html

      <div id="yoograph60"></div>
      <script>
      d3.select("#yoograph60").graphviz().renderDot(`
        digraph {
          rankdir = "LR"
          node [shape=circle]
          END [shape=doublecircle, label="2"]
          0 -> 1 [label="+"]
          1 -> END [label="E"]
          0 -> END [label="λ"]
        }
      `);
      </script>

.. include:: src/rd/aB.plus.E.recursive.parser.py
  :code: python
  :number-lines:
  :class: substep
  :start-line: 2
  :end-line: 24

.. code:: console
  :class: substep

  python3 a.py 12.1  + 35.45 + 2

  a B  a:  12.1,  B:  +35.45+2
  +E, E: 35.45+2
  a B  a:  35.45, B:  +2
  +E, E: 2
  a B  a:  2.0, B:
  True

.. code:: console
  :class: substep

  python3 a.py 12.1  + + 2

  12.1  + + 2
  a B  a:  12.1,  B:  ++2
  +E, E: +2
  Synatx Error: number expected
  Reminder:  +2
  False

----

:class: t2c

Parse Tree
================
.. container::

  .. include:: src/rd/aB.plus.E.recursive.parser.py
    :code: python
    :number-lines:
    :start-line: 2
    :end-line: 24

  .. code:: console

    python3 a.py 12.1  + 35.45 + 2

    a B  a:  12.1,  B:  +35.45+2
    +E, E: 35.45+2
    a B  a:  35.45, B:  +2
    +E, E: 2
    a B  a:  2.0, B:
    True

.. container:: substep

  .. raw:: html

      <div id="yoograph70" class="substep"></div>
      <script>
      d3.select("#yoograph70").graphviz().renderDot(`
        digraph {
          Start [label="12.1+35.45+2"]
          A12 [label="12.1"]
          Aplus1 [label = "+"]
          A35r [label="35.45+2"]
          A3545 [label="35.45"]
          Aplus2 [label="+"]
          A2 [label="2"]

          Start -> A12
          Start -> Aplus1
          Start -> A35r
          A35r  -> A3545
          A35r  -> Aplus2
          A35r  -> A2
       }
      `);
      </script>


  .. class:: substep

    #. E[12.1+35.45+2] ⇒
    #. a[12.1] + E[35.45+2] ⇒
    #. a[12.1] + a[35.45] + E[2] ⇒
    #. a[12.1] + a[35.45] + a[2] ⇒
    #. Left Most Derivation

----

:class: t2c

Doing Addition
======================
.. include:: src/rd/aB.plus.E.recursive.parser.py
  :code: python
  :number-lines:
  :class: substep
  :start-line: 2
  :end-line: 24

.. include:: src/rd/aB.plus.E.recursive.calculator.py
  :code: python
  :number-lines:
  :class: substep
  :start-line: 2
  :end-line: 23

.. code:: console
  :class: substep

  python3 a.py 12.1  + 35.45 + 2

  a B  a:  12.1,  B:  +35.45+2
  +E, E: 35.45+2
  a B  a:  35.45, B:  +2
  +E, E: 2
  a B  a:  2.0, B:
  (True, 49.550000000000004)

.. code:: console
  :class: substep

  python3 a.py 2 +

  a B  a:  2.0, B:  +
  +E, E:
  Synatx Error: number expected
  Reminder:
  (False, 2.0)

----

:class: t2c

Simplify Diagram
======================
.. container::

  E

   .. raw:: html

      <div id="yoograph80" class="substep"></div>
      <script>
      d3.select("#yoograph80").graphviz().renderDot(`
        digraph {
          rankdir = "LR"
          node [shape=circle]
          END [shape=doublecircle, label="2"]
          0 -> 1 [label="a"]
          1 -> END [label="B"]
        }
      `);
      </script>

  B

  .. raw:: html

      <div id="yoograph90" class="substep"></div>
      <script>
      d3.select("#yoograph90").graphviz().renderDot(`
        digraph {
          rankdir = "LR"
          node [shape=circle]
          END [shape=doublecircle, label="2"]
          0 -> 1 [label="+"]
          1 -> END [label="E"]
          0 -> END [label="λ"]
        }
      `);
      </script>

.. container:: substep

  Combine them

  .. raw:: html

      <div id="yoograph110" class="substep"></div>
      <script>
      d3.select("#yoograph110").graphviz().renderDot(`
        digraph {
          rankdir = "LR"
          node [shape=circle]
          END [shape=doublecircle, label="3"]
          0 -> 1     [label="a"]
          1 -> 2     [label="+"]
          1 -> END   [label="λ"]
          2 -> END   [label="E"]
        }
      `);
      </script>

  .. raw:: html

      <div id="yoograph120" class="substep"></div>
      <script>
      d3.select("#yoograph120").graphviz().renderDot(`
        digraph {
          rankdir = "LR"
          node [shape=circle]
          END [shape=doublecircle, label="3"]
          0 -> 1     [label="a"]
          1 -> 2     [label="+"]
          1 -> END   [label="λ"]
          2 -> 0     [label="λ"]
        }
      `);
      </script>

.. class:: substep

  E

.. raw:: html

    <div id="yoograph130" class="substep"></div>
    <script>
    d3.select("#yoograph130").graphviz().renderDot(`
      digraph {
        rankdir = "LR"
        node [shape=circle]
        END [shape=doublecircle, label="2"]
        0 -> 1     [label="a"]
        1 -> 0     [label="+"]
        1 -> END   [label="λ"]
      }
    `);
    </script>

----

:class: t2c

Parser Code for add Nonrecursive
===================================
.. container::

  E

  .. raw:: html

      <div id="yoograph140"></div>
      <script>
      d3.select("#yoograph140").graphviz().renderDot(`
        digraph {
          rankdir = "LR"
          node [shape=circle]
          END [shape=doublecircle, label="2"]
          0 -> 1     [label="a"]
          1 -> 0     [label="+"]
          1 -> END   [label="λ"]
        }
      `);
      </script>

.. include:: src/rd/a.plus.E.parser.py
  :code: python
  :number-lines:
  :class: substep
  :start-line: 2
  :end-line: 23

.. code:: console
  :class: substep

  input: 16+34+0.30
  output:
  a:  16.0, :  +34+0.30
  a:  34.0, :  +0.30
  a:  0.3,  :
  True

.. code:: console
  :class: substep

  input: 23+ + 34
  output:
  a:  23.0, :  ++34
  Synatx Error: number expected
     +34
  False

----

:class: t2c

Calculator Code for add Nonrecursive
======================================
.. container::

  E

  .. raw:: html

      <div id="yoograph150" class="substep"></div>
      <script>
      d3.select("#yoograph150").graphviz().renderDot(`
        digraph {
          rankdir = "LR"
          node [shape=circle]
          END [shape=doublecircle, label="2"]
          0 -> 1     [label="a"]
          1 -> 0     [label="+"]
          1 -> END   [label="λ"]
        }
      `);
      </script>


.. include:: src/rd/a.plus.E.calculator02.py
  :code: python
  :number-lines:
  :class: substep
  :start-line: 2
  :end-line: 21

.. code:: console
  :class: substep

  input: 16+34+0.30
  output:
  a:  16.0, :  +34+0.30
  a:  34.0, :  +0.30
  a:  0.3,  :
  (True, 50.3)

.. code:: console
  :class: substep

  input: 23+ + 34
  output:

  a:  23.0, :  ++34
  Synatx Error: number expected
     +34
  (False, 23.0)

----

Classes of Languages
======================
.. image:: img/sa/languages.png
  :height: 400px

https://www.researchgate.net/figure/Human-languages-and-the-classes-of-the-Chomsky-hierarchy-with-parsing-complexity_fig1_257299091

----

:class: t2c

Parse for + * ( ) no priority
=====================================
.. container::

  Consider the follwing sentences of a langauge:

  Write down the Grammar

  #. 3
  #. 9 +3
  #. 9 * 3
  #. (9 * 3)
  #. (9 + 3)
  #. (9 * 4) + 5
  #. 9 * (4 + 5)
  #. (9 * (4 + 5)) * 3
  #. 9 * ((4 + 5) * 3)
  #. 9 * ((4 + 5) + 3)
  #. (9 + (4 + 5)) * 3

  .. class:: substep

  #. S → A + A
  #. S → A * A
  #. S → A
  #. A → (S)
  #. A → a

.. container:: substep

  .. raw:: html

      <div id="yoograph162" class="substep"></div>
      <script>
      d3.select("#yoograph162").graphviz().renderDot(`
        digraph {
          rankdir = "LR"
          node [shape=circle]
          END [shape=doublecircle, label="7"]
          0 -> END [label="A"]
          0 -> 2 [label="A"]
          0 -> 3 [label="A"]
          2 -> 4 [label="+"]
          4 -> END [label="A"]
          3 -> 6 [label="*"]
          6 -> END [label="A"]
        }
      `);
      </script>

  .. raw:: html

      <div id="yoograph170" class="substep"></div>
      <script>
      d3.select("#yoograph170").graphviz().renderDot(`
        digraph {
          rankdir = "LR"
          node [shape=circle]
          END [shape=doublecircle, label="14"]
          10 -> END [label="a"]
          10 -> 12 [label="("]
          12 -> 13 [label="S"]
          13 -> END [label=")"]
        }
      `);
      </script>

.. :

  #. 9 + 4 + 5 * 3 == 54

  #. E → E + T | E * T | T
  #. T → (E) | a

  E --> E + T | E - T | E * T | T

----

:class: t2c

Left Factoring
=====================
.. container::

  #. S → A + A
  #. S → A * A
  #. S → A
  #. A → (S)
  #. A → a

  .. class:: substep

  #. S → A B
  #. B → + A | * A | λ
  #. A → ( S ) | a

.. container:: substep

  * S

  .. raw:: html

      <div id="yoograph180" class="substep"></div>
      <script>
      d3.select("#yoograph180").graphviz().renderDot(`
        digraph {
          rankdir = "LR"
          END [shape=doublecircle, label="2"]
          node [shape=circle]
          0 -> 1 [label="A"]
          1 -> END [label="B"]
        }
      `);
      </script>

  * B

  .. raw:: html

      <div id="yoograph190" class="substep"></div>
      <script>
      d3.select("#yoograph190").graphviz().renderDot(`
        digraph {
          rankdir = "LR"
          node [shape=circle]
          END [shape=doublecircle, label="17"]
          15 -> 16 [label="+|*"]
          16 -> END [label="A"]
          15 -> END [label="λ"]
        }
      `);
      </script>

.. container:: substep

  * A

  .. raw:: html

      <div id="yoograph200" class="substep"></div>
      <script>
      d3.select("#yoograph200").graphviz().renderDot(`
        digraph {
          rankdir = "LR"
          node [shape=circle]
          END [shape=doublecircle, label="14"]
          10 -> END [label="a"]
          10 -> 12 [label="("]
          12 -> 13 [label="S"]
          13 -> END [label=")"]
        }
      `);
      </script>

----

:class: t2c

Simplify Diagram
======================
.. container::

  * S

  .. raw:: html

      <div id="yoograph210" class="substep"></div>
      <script>
      d3.select("#yoograph210").graphviz().renderDot(`
        digraph {
          rankdir = "LR"
          END [shape=doublecircle, label="2"]
          node [shape=circle]
          0 -> 1 [label="A"]
          1 -> END [label="B"]
        }
      `);
      </script>


  * B

  .. raw:: html

      <div id="yoograph220" class="substep"></div>
      <script>
      d3.select("#yoograph220").graphviz().renderDot(`
        digraph {
          rankdir = "LR"
          node [shape=circle]
          END [shape=doublecircle, label="17"]
          15 -> 16 [label="+|*"]
          16 -> END [label="A"]
          15 -> END [label="λ"]
        }
      `);
      </script>

  * A

  .. raw:: html

      <div id="yoograph230" class="substep"></div>
      <script>
      d3.select("#yoograph230").graphviz().renderDot(`
        digraph {
          rankdir = "LR"
          node [shape=circle]
          END [shape=doublecircle, label="14"]
          10 -> END [label="a"]
          10 -> 12 [label="("]
          12 -> 13 [label="S"]
          13 -> END [label=")"]
        }
      `);
      </script>

.. container:: substep

  * Combine S and B

  .. raw:: html

      <div id="yoograph240" class="substep"></div>
      <script>
      d3.select("#yoograph240").graphviz().renderDot(`
        digraph {
          END [shape=doublecircle, label="17"]
          node [shape=circle]
          0  -> 1 [label="A"]
          1  -> 16 [label="+|*"]
          1  -> END [label="λ"]
          16 -> END [label="A"]
        }
      `);
      </script>

----

:class: t2c

Remove Some Recursion
=========================
.. container::

  * S

  .. raw:: html

      <div id="yoograph250" class="substep"></div>
      <script>
      d3.select("#yoograph250").graphviz().renderDot(`
        digraph {
          rankdir = "LR"
          END [shape=doublecircle, label="17"]
          node [shape=circle]
          0  -> 1 [label="A"]
          1  -> 16 [label="+|*"]
          1  -> END [label="λ"]
          16 -> END [label="A"]
        }
      `);
      </script>

.. raw:: html

    <div id="yoograph260" class="substep"></div>
    <script>
    d3.select("#yoograph260").graphviz().renderDot(`
      digraph {
        rankdir = "LR"
        END [shape=doublecircle, label="17"]
        node [shape=circle]
        0  -> 1 [label="A"]
        1  -> 0 [label="+|*"]
        1  -> END [label="λ"]
      }
    `);
    </script>

.. container:: substep

  * A

  .. raw:: html

      <div id="yoograph270" class="substep"></div>
      <script>
      d3.select("#yoograph270").graphviz().renderDot(`
        digraph {
          rankdir = "LR"
          node [shape=circle]
          END [shape=doublecircle, label="14"]
          10 -> END [label="i"]
          10 -> 12 [label="("]
          12 -> 13 [label="S"]
          13 -> END [label="}"]
        }
      `);
      </script>


----

:class: t2c

Parser Code
=========================
.. container::

  * S

   .. raw:: html

      <div id="yoograph280" class="substep"></div><script>
      d3.select("#yoograph280").graphviz().renderDot(`digraph {
        rankdir = "LR"
        END [shape=doublecircle, label="17"]
        node [shape=circle]
        0  -> 1 [label="A"]
        1  -> 0 [label="+|*"]
        1  -> END [label="λ"]
      }`); </script>

  * A

  .. raw:: html

      <div id="yoograph290" class="substep"></div><script>
      d3.select("#yoograph290").graphviz().renderDot(`digraph {
        rankdir = "LR"
        node [shape=circle]
        END [shape=doublecircle, label="14"]
        10 -> END [label="a"]
        10 -> 12 [label="("]
        12 -> 13 [label="S"]
        13 -> END [label="}"]
      } `); </script>


.. include:: src/rd/A_S_plus_mul_pranathesis.py
  :code: python
  :number-lines:
  :class: substep
  :start-line: 1
  :end-line: 33

----

:class: t2c

Lexical
===========
.. include:: src/rd/lexical_number_plus_mul_par.py
  :code: python
  :number-lines: 2
  :class: substep
  :start-line: 1
  :end-line: 33

.. include:: src/rd/lexical_number_plus_mul_par.py
  :code: python
  :number-lines: 33
  :class: substep
  :start-line: 33
  :end-line: 65


----

:class: t2c

A Simple Calculator (, ), ``+``, ``*``
==========================================
.. container:: substep

  #. 34
  #. 34 + 2
  #. 34 + 45+98
  #. 34 + 45+98 * 4 * 554
  #. (34 * 2) + 3
  #. 43 * (54+3)
  #. 2 + (34)
  #. (34+3) * 2
  #. (34+3) * 2

  .. class:: substep

    Grammar 1

    #. S -> S + S
    #. S -> S * S
    #. S -> a
    #. S -> (S)

    Wrong Grammar (Why?)

.. container:: substep

  .. class:: substep

    Grammar 2

    #. E -> T + E | T
    #. T -> F * T | F
    #. F -> (E) | a

    Grammar 3

    * E -> E + T | T
    * T -> T * F | F
    * F -> (E) | a

    **Left Recursion**

    #. E -> T L
    #. L -> + T L | λ
    #. T -> F M
    #. M -> * T M | λ
    #. F -> (E) | a

----

:class: t2c

State Diagram(II)
=========================
.. container:: substep

  E -> T L

  .. raw:: html

      <div id="yoograph300" class="substep"></div><script>
      d3.select("#yoograph300").graphviz().renderDot(`digraph {
        rankdir = "LR"
        END [shape=doublecircle, label="3"]
        node [shape=circle]
        0  -> 1 [label="T"]
        1  -> END [label="L"]
      }`); </script>

.. container:: substep

  L -> + E | λ

  .. raw:: html

      <div id="yoograph310" class="substep"></div><script>
      d3.select("#yoograph310").graphviz().renderDot(`digraph {
      rankdir = "LR"
      END [shape=doublecircle, label="3"]
      node [shape=circle]
      0  -> 1 [label="+"]
      1  -> END [label="E"]
      0  -> END [label="λ"]
      }`); </script>

.. container:: substep

  T -> F M

  .. raw:: html

      <div id="yoograph320" class="substep"></div><script>
      d3.select("#yoograph320").graphviz().renderDot(`digraph {
        rankdir = "LR"
        END [shape=doublecircle, label="3"]
        node [shape=circle]
        0  -> 1 [label="F"]
        1  -> END [label="M"]
      }`); </script>

.. container:: substep

  M -> * T M | λ

  .. raw:: html

      <div id="yoograph330" class="substep"></div><script>
      d3.select("#yoograph330").graphviz().renderDot(`digraph {
        rankdir = "LR"
        END [shape=doublecircle, label="3"]
        node [shape=circle]
        0  -> 1 [label="*"]
        1  -> END [label="T"]
        1  -> 2 [label="M"]
        0  -> END [label="λ"]
      }`); </script>

.. container:: substep

  F -> (E) | a

  .. raw:: html

      <div id="yoograph340" class="substep"></div><script>
      d3.select("#yoograph340").graphviz().renderDot(`digraph {
        rankdir = "LR"
        END [shape=doublecircle, label="3"]
        node [shape=circle]
        0  -> 1 [label="("]
        1  -> 2 [label="E"]
        2  -> END [label=")"]
        0  -> END [label="a"]
      }`); </script>

#. E -> T L
#. L -> + E L | λ
#. T -> F M
#. M -> * T M | λ
#. F -> (E) | a

----

:class: t2c

Simplify Diagram(II) - Combine E, L
===================================
.. container::

  E -> T L

  .. raw:: html

      <div id="yoograph350" class="substep"></div><script>
      d3.select("#yoograph350").graphviz().renderDot(`digraph {
        rankdir = "LR"
        END [shape=doublecircle, label="3"]
        node [shape=circle]
        0  -> 1 [label="T"]
        1  -> END [label="L"]
      }`); </script>



.. container::

  L -> + E L | λ

  .. raw:: html

      <div id="yoograph360" class="substep"></div><script>
      d3.select("#yoograph360").graphviz().renderDot(`digraph {
        rankdir = "LR"
        END [shape=doublecircle, label="3"]
        node [shape=circle]
        0  -> 1 [label="+"]
        1  -> 2 [label="E"]
        2  -> END [label="L"]
        0  -> END [label="λ"]
      }`); </script>

  .. raw:: html

      <div id="yoograph370" class="substep"></div><script>
      d3.select("#yoograph370").graphviz().renderDot(`digraph {
        rankdir = "LR"
        END [shape=doublecircle, label="3"]
        node [shape=circle]
        0  -> 1 [label="T"]
        1  -> 2 [label="+"]
        2  -> END [label="E"]
        1  -> END [label="λ"]
      }`); </script>


.. raw:: html

    <div id="yoograph380" class="substep"></div><script>
    d3.select("#yoograph380").graphviz().renderDot(`digraph {
      rankdir = "LR"
      END [shape=doublecircle, label="3"]
      node [shape=circle]
      0  -> 1 [label="T"]
      1  -> 2 [label="+"]
      2  -> 0 [label="λ"]
      1  -> END [label="λ"]
    }`); </script>

.. raw:: html

    <div id="yoograph390" class="substep"></div><script>
    d3.select("#yoograph390").graphviz().renderDot(`digraph {
      rankdir = "LR"
      END [shape=doublecircle, label="3"]
      node [shape=circle]
      0  -> 1 [label="T"]
      1  -> 0 [label="+"]
      1  -> END [label="λ"]
    }`); </script>

----

:class: t2c

Simplify Diagram(III) - Combine T, M
========================================
.. container::

  T -> F M

  .. raw:: html

      <div id="yoograph400" class="substep"></div><script>
      d3.select("#yoograph400").graphviz().renderDot(`digraph {
        rankdir = "LR"
        END [shape=doublecircle, label="3"]
        node [shape=circle]
        0  -> 1 [label="F"]
        1  -> END [label="M"]
      }`); </script>


.. container::

  M -> * T M | λ

  .. raw:: html

      <div id="yoograph410" class="substep"></div><script>
      d3.select("#yoograph410").graphviz().renderDot(`digraph {
        rankdir = "LR"
        END [shape=doublecircle, label="3"]
        node [shape=circle]
        0  -> 1 [label="*"]
        1  -> 2 [label="T"]
        2  -> END [label="M"]
        0  -> END [label="λ"]
      }`); </script>


.. raw:: html

    <div id="yoograph420" class="substep"></div><script>
    d3.select("#yoograph420").graphviz().renderDot(`digraph {
      rankdir = "LR"
      END [shape=doublecircle, label="3"]
      node [shape=circle]
      0  -> 1 [label="F"]
      1  -> 2 [label="*"]
      2  -> END [label="T"]
      1  -> END [label="λ"]
    }`); </script>

.. raw:: html

    <div id="yoograph430" class="substep"></div><script>
    d3.select("#yoograph430").graphviz().renderDot(`digraph {
      rankdir = "LR"
      END [shape=doublecircle, label="3"]
      node [shape=circle]
      0  -> 1 [label="F"]
      1  -> 2 [label="*"]
      2  -> 0 [label="λ"]
      1  -> END [label="λ"]
    }`); </script>

.. raw:: html

    <div id="yoograph440" class="substep"></div><script>
    d3.select("#yoograph440").graphviz().renderDot(`digraph {
      rankdir = "LR"
      END [shape=doublecircle, label="3"]
      node [shape=circle]
      0  -> 1 [label="F"]
      1  -> 0 [label="*"]
      1  -> END [label="λ"]
    }`); </script>

----

:class: t2c

Diagrams of the Second Calculator
======================================
.. container::

  E

  .. raw:: html

      <div id="yoograph450" class="substep"></div><script>
      d3.select("#yoograph450").graphviz().renderDot(`digraph {
        rankdir = "LR"
        END [shape=doublecircle, label="3"]
        node [shape=circle]
        0  -> 1 [label="T"]
        1  -> 0 [label="+"]
        1  -> END [label="λ"]
      }`); </script>

  T

  .. raw:: html

      <div id="yoograph460" class="substep"></div><script>
      d3.select("#yoograph460").graphviz().renderDot(`digraph {
        rankdir = "LR"
        END [shape=doublecircle, label="3"]
        node [shape=circle]
        0  -> 1 [label="F"]
        1  -> 0 [label="*"]
        1  -> END [label="λ"]
      }`); </script>

  F


  .. raw:: html

      <div id="yoograph470" class="substep"></div><script>
      d3.select("#yoograph470").graphviz().renderDot(`digraph {
        rankdir = "LR"
        END [shape=doublecircle, label="3"]
        node [shape=circle]
        0  -> 1 [label="("]
        1  -> 2 [label="E"]
        2  -> END [label=")"]
        0  -> END [label="a"]
      }`); </script>

.. container:: substep

  *Can E and T be combined?*

  E

  .. raw:: html

      <div id="yoograph480" class="substep"></div><script>
      d3.select("#yoograph480").graphviz().renderDot(`digraph {
        rankdir = "LR"
        END [shape=doublecircle, label="2"]
        node [shape=circle]
        0  -> 1 [label="F"]
        1  -> 0 [label="+|*"]
        1  -> END [label="λ"]
      }`); </script>

  .. class:: substep

  #. 4 + 3 * 2
  #. ( 4 + 3 ) * 2
  #. 4 + ( 3 * 2 )
  #. 3 * 2 + 4
  #. 3 * ( 2 + 4 )
  #. ( 3 * 2 ) + 4

----

:class: t2c

State Diagram
=========================
.. container::

  * E -> T + E | T

  .. raw:: html

      <div id="yoograph490" class="substep"></div><script>
      d3.select("#yoograph490").graphviz().renderDot(`digraph {
        rankdir = "LR"
        END [shape=doublecircle, label="3"]
        node [shape=circle]
        0  -> 1 [label="T"]
        1  -> 2 [label="+"]
        2  -> END [label="E"]
        0  -> END [label="T"]
      }`); </script>

.. container::

  * T -> F * T | F

  .. raw:: html

      <div id="yoograph500" class="substep"></div><script>
      d3.select("#yoograph500").graphviz().renderDot(`digraph {
        rankdir = "LR"
        END [shape=doublecircle, label="3"]
        node [shape=circle]
        0  -> 1 [label="F"]
        1  -> 2 [label="*"]
        2  -> END [label="T"]
        0  -> END [label="F"]
      }`); </script>


.. container::

  * F -> (E) | a

  .. raw:: html

      <div id="yoograph510" class="substep"></div><script>
      d3.select("#yoograph510").graphviz().renderDot(`digraph {
        rankdir = "LR"
        END [shape=doublecircle, label="3"]
        node [shape=circle]
        0  -> 1 [label="("]
        1  -> 2 [label="E"]
        2  -> END [label=")"]
        0  -> END [label="a"]
      }`); </script>

----

:class: t2c

Simplify Diagram(IV) - Fewer steps
===================================
.. raw:: html

    <div id="yoograph520" class="substep"></div><script>
    d3.select("#yoograph520").graphviz().renderDot(`digraph {
      rankdir = "LR"
      END [shape=doublecircle, label="3"]
      node [shape=circle]
      0  -> 1 [label="T"]
      1  -> 2 [label="+"]
      2  -> END [label="E"]
      0  -> END [label="T"]
    }`); </script>


.. raw:: html

    <div id="yoograph530" class="substep"></div><script>
    d3.select("#yoograph530").graphviz().renderDot(`digraph {
      rankdir = "LR"
      END [shape=doublecircle, label="3"]
      node [shape=circle]
      0  -> 1 [label="T"]
      1  -> 0 [label="+"]
      1  -> END [label="λ"]
    }`); </script>


.. raw:: html

    <div id="yoograph540" class="substep"></div><script>
    d3.select("#yoograph540").graphviz().renderDot(`digraph {
      rankdir = "LR"
      END [shape=doublecircle, label="3"]
      node [shape=circle]
      0  -> 1 [label="F"]
      0  -> END [label="F"]
      1  -> 2 [label="*"]
      2  -> END [label="E"]
    }`); </script>


.. raw:: html

    <div id="yoograph550" class="substep"></div><script>
    d3.select("#yoograph550").graphviz().renderDot(`digraph {
      rankdir = "LR"
      END [shape=doublecircle, label="3"]
      node [shape=circle]
      0  -> 1 [label="F"]
      1  -> 0 [label="*"]
      1  -> END [label="λ"]
    }`); </script>


.. raw:: html

    <div id="yoograph560" class="substep"></div><script>
    d3.select("#yoograph560").graphviz().renderDot(`digraph {
      rankdir = "LR"
      END [shape=doublecircle, label="3"]
      node [shape=circle]
      0  -> 1 [label="("]
      1  -> 2 [label="E"]
      2  -> END [label=")"]
      0  -> END [label="a"]
    }`); </script>

----

:class: t2c

Parser Code for Add and Multiply
====================================
.. container::

  E

   .. raw:: html

      <div id="yoograph570" class="substep"></div><script>
      d3.select("#yoograph570").graphviz().renderDot(`digraph {
        rankdir = "LR"
        END [shape=doublecircle, label="3"]
        node [shape=circle]
        0  -> 1 [label="T"]
        1  -> 0 [label="+"]
        1  -> END [label="λ"]
      }`); </script>

  T

  .. raw:: html

      <div id="yoograph580" class="substep"></div><script>
      d3.select("#yoograph580").graphviz().renderDot(`digraph {
        rankdir = "LR"
        END [shape=doublecircle, label="3"]
        node [shape=circle]
        0  -> 1 [label="F"]
        1  -> 0 [label="*"]
        1  -> END [label="λ"]
      }`); </script>


  F


  .. raw:: html

      <div id="yoograph590" class="substep"></div><script>
      d3.select("#yoograph590").graphviz().renderDot(`digraph {
        rankdir = "LR"
        END [shape=doublecircle, label="3"]
        node [shape=circle]
        0  -> 1 [label="("]
        1  -> 2 [label="E"]
        2  -> END [label=")"]
        0  -> END [label="a"]
      }`); </script>


.. include:: src/rd/e_t_f_plus_mul_parser.py
  :code: python
  :number-lines:
  :class: substep
  :start-line: 1
  :end-line: 34

----

:data-rotate: 90

:class: t2c

Another Language for simple expression  + - * / ( )
=========================================================
.. container::

  #. 2 + 3 * 4 - 5
  #. 4 - 5 * 2 / ( 4 - 2 ) + 1
  #. ( ( 2 * ( 3 - 1) ) / (5 - 3) ) * ( 7 - 8 )

  Grammar ?

  .. class:: substep

  #. E → T + E | T - E | T
  #. T → F * T | F / T | F
  #. F → (E) | a

  .. class:: substep

  Is there any problem?

  .. class:: substep

  #. 4 - 3 - 2
  #. 16 / 4 / 2

  .. class:: substep

  It was a wrong grammar

.. container:: substep


  .. class:: substep

  #. E → E + T | E - T | T
  #. T → T * F | T / F | F
  #. F → (E) | a

  .. class:: substep

  Left Most Derivation

  .. class:: substep

    #. E ⇒ E + T ⇒
    #. T + T ⇒
    #. F + T ⇒
    #. 16 + T ⇒ 16 + T * F ⇒
    #. 16 + F * F ⇒
    #. 16 + 3 * F ⇒
    #. 16 + 3 * 4

----

Left Recursion Elimination
=============================================
A → A α | β
-----------------

.. table::

    +----------------------------------------------+------------------------------------------------+
    | .. image:: img/rd/with_left_recursion.png    |  .. image:: img/rd/without_left_recursion.png  |
    |    :align: center                            |     :align: center                             |
    |    :class: substep                           |     :class: substep                            |
    |    :height: 350px                            |     :height: 350px                             |
    +----------------------------------------------+------------------------------------------------+

.. class:: substep

    * A  → β A'
    * A' → α A' | λ

----

General Form of Direct Left Recursion Elimination
====================================================
A → A :math:`α_1` | A :math:`α_2` | :math:`...` | A :math:`α_m` |  :math:`β_1` |  :math:`β_2` | :math:`...` |  :math:`β_n`
------------------------------------------------------------------------------------------------------------------------------------
.. :

  .. math::
    :class: rtl-h1

    A → A α_1 | A α_2 | \dots | A α_m | β_1 |  β_2 | \dots |  β_n

.. class:: substep

    Convert to

    * A  → :math:`β_1` A' |  :math:`β_2` A' | :math:`...`  |  :math:`β_n` A'
    * A' → :math:`α_1` A' | :math:`α_2` A' | :math:`...`  |  :math:`α_m` A' | λ

----

:class: t2c

Calculator Grammar
=====================
.. container::

  .. math::

    A → A α_1 | A α_2 | \dots | A α_m | β_1 |  β_2 | \dots |  β_n

  Convert to

  * A  → :math:`β_1` A' |  :math:`β_2` A' | :math:`...`  |  :math:`β_n` A'
  * A' → :math:`α_1` A' | :math:`α_2` A' | :math:`...`  |  :math:`α_m` A' | λ

  .. class:: substep

    * E → E + T | E - T | T
    * T → T * F | T / F | F
    * F → a | (E)

    Convert to

    * E   → T E'
    * E'  → + T E' | - T E' | λ
    * T   → F T'
    * T'  → * F T' | / F T' | λ
    * F   → a | (E)

.. container:: substep

  .. class:: substep

    .. raw:: html

        <div id="yoograph610" class="substep"></div>
        <script>
        d3.select("#yoograph610").graphviz().renderDot(`

          digraph {
            rankdir = "LR"
            END [shape=doublecircle, label="2"]
            node [shape=circle]
            0  -> 1 [label="T"]
            1  -> END [label="E'"]
         }
        `);
        </script>


    .. raw:: html

        <div id="yoograph620" class="substep"></div><script>
        d3.select("#yoograph620").graphviz().renderDot(`digraph {
          rankdir = "LR"
          END [shape=doublecircle, label="3"]
          node [shape=circle]
          0  -> 1 [label="+|-"]
          1  -> 2 [label="T"]
          2  -> END [label="E'"]
          0  -> END [label="λ"]
        }`); </script>

    .. raw:: html

        <div id="yoograph630" class="substep"></div><script>
        d3.select("#yoograph630").graphviz().renderDot(`digraph {
          rankdir = "LR"
          END [shape=doublecircle, label="2"]
          node [shape=circle]
          0  -> 1 [label="F"]
          1  -> END [label="T'"]
        }`); </script>


    .. raw:: html

        <div id="yoograph640" class="substep"></div><script>
        d3.select("#yoograph640").graphviz().renderDot(`digraph {
          rankdir = "LR"
          END [shape=doublecircle, label="3"]
          node [shape=circle]
          0  -> 1 [label="*|/"]
          1  -> 2 [label="F"]
          2  -> END [label="T'"]
          0  -> END [label="λ"]
        }`); </script>

    .. raw:: html

        <div id="yoograph650" class="substep"></div><script>
        d3.select("#yoograph650").graphviz().renderDot(`digraph {
          rankdir = "LR"
          END [shape=doublecircle, label="3"]
          node [shape=circle]
          0  -> 1 [label="("]
          1  -> 2 [label="E"]
          2  -> END [label=")"]
          0  -> END [label="a"]
        }`); </script>

----

:class: t2c

Simplify Diagram(V) - Combine E and E'
====================================================
.. container::

    E

    .. raw:: html

        <div id="yoograph660" class="substep"></div><script>
        d3.select("#yoograph660").graphviz().renderDot(`digraph {
          rankdir = "LR"
          END [shape=doublecircle, label="2"]
          node [shape=circle]
          0  -> 1 [label="T"]
          1  -> END [label="E'"]
        }`); </script>

    E'

    .. raw:: html

        <div id="yoograph670" class="substep"></div><script>
        d3.select("#yoograph670").graphviz().renderDot(`digraph {
          rankdir = "LR"
          END [shape=doublecircle, label="3"]
          node [shape=circle]
          0  -> 1 [label="+|-"]
          1  -> 2 [label="T"]
          2  -> END [label="E'"]
          0  -> END [label="λ"]
        }`); </script>


.. container::

  .. class:: substep

    .. raw:: html

        <div id="yoograph680" class="substep"></div><script>
        d3.select("#yoograph680").graphviz().renderDot(`digraph {
          rankdir = "LR"
          END [shape=doublecircle, label="2"]
          node [shape=circle]
          0  -> 1 [label="+|-"]
          1  -> 0 [label="T"]
          0  -> END [label="λ"]
        }`); </script>

    .. raw:: html

        <div id="yoograph690" class="substep"></div><script>
        d3.select("#yoograph690").graphviz().renderDot(`digraph {
          rankdir = "LR"
          END [shape=doublecircle, label="3"]
          node [shape=circle]
          0  -> 1 [label="T"]
          1  -> 2 [label="+|-"]
          2  -> 1 [label="T"]
          1  -> END [label="λ"]
        }`); </script>

    .. raw:: html

        <div id="yoograph700" class="substep"></div><script>
        d3.select("#yoograph700").graphviz().renderDot(`digraph {
          rankdir = "LR"
          END [shape=doublecircle, label="2"]
          node [shape=circle]
          0  -> 1 [label="T"]
          1  -> 0 [label="+|-"]
          1  -> END [label="λ"]
        }`); </script>


----

:class: t2c

Simplify Diagram(VI) - Combining T and T'
===============================================
.. container::

    T

    .. raw:: html

        <div id="yoograph710" class="substep"></div><script>
        d3.select("#yoograph710").graphviz().renderDot(`digraph {
          rankdir = "LR"
          END [shape=doublecircle, label="2"]
          node [shape=circle]
          0  -> 1 [label="F"]
          1  -> END [label="T'"]
        }`); </script>

    T'

    .. raw:: html

        <div id="yoograph720" class="substep"></div><script>
        d3.select("#yoograph720").graphviz().renderDot(`digraph {
          rankdir = "LR"
          END [shape=doublecircle, label="3"]
          node [shape=circle]
          0  -> 1 [label="*|/"]
          1  -> 2 [label="F"]
          2  -> END [label="T'"]
          0  -> END [label="λ"]
        }`); </script>

.. container::

  .. class:: substep

    .. raw:: html

        <div id="yoograph730" class="substep"></div><script>
        d3.select("#yoograph730").graphviz().renderDot(`digraph {
        rankdir = "LR"
        END [shape=doublecircle, label="2"]
        node [shape=circle]
        0  -> 1 [label="*|/"]
        1  -> 0 [label="F"]
        0  -> END [label="λ"]
        }`); </script>

    .. raw:: html

        <div id="yoograph740" class="substep"></div><script>
        d3.select("#yoograph740").graphviz().renderDot(`digraph {
          rankdir = "LR"
          END [shape=doublecircle, label="3"]
          node [shape=circle]
          0  -> 1 [label="F"]
          1  -> 2 [label="*|/"]
          2  -> 1 [label="F"]
          1  -> END [label="λ"]
        }`); </script>

    .. raw:: html

        <div id="yoograph750" class="substep"></div><script>
        d3.select("#yoograph750").graphviz().renderDot(`digraph {
          rankdir = "LR"
          END [shape=doublecircle, label="2"]
          node [shape=circle]
          0  -> 1 [label="F"]
          1  -> 0 [label="*|/"]
          1  -> END [label="λ"]
        }`); </script>

----

:class: t2c

Parser Code for Last Calculator
====================================================
.. container::

  E

  .. raw:: html

      <div id="yoograph760" class="substep"></div><script>
      d3.select("#yoograph760").graphviz().renderDot(`digraph {
        rankdir = "LR"
        END [shape=doublecircle, label="2"]
        node [shape=circle]
        0  -> 1 [label="T"]
        1  -> 0 [label="+|-"]
        1  -> END [label="λ"]
      }`); </script>

  T

  .. raw:: html

      <div id="yoograph770" class="substep"></div><script>
      d3.select("#yoograph770").graphviz().renderDot(`digraph {
        rankdir = "LR"
        END [shape=doublecircle, label="2"]
        node [shape=circle]
        0  -> 1 [label="F"]
        1  -> 0 [label="*|/"]
        1  -> END [label="λ"]
      }`); </script>

  F

  .. raw:: html

      <div id="yoograph780" class="substep"></div><script>
      d3.select("#yoograph780").graphviz().renderDot(`digraph {
        rankdir = "LR"
        END [shape=doublecircle, label="3"]
        node [shape=circle]
        0  -> 1 [label="("]
        1  -> 2 [label="E"]
        2  -> END [label=")"]
        0  -> END [label="a"]
      }`); </script>

.. include:: src/rd/e_t_f_plus_minus_mul_divide_parser.py
  :code: python
  :number-lines:
  :class: substep
  :start-line: 1
  :end-line: 34

----

:class: t2c

Parser Tree
===========
.. include:: src/rd/e_t_f_plus_minus_mul_divide_parser_tree.py
  :code: python
  :number-lines: 9
  :start-line: 9
  :end-line: 40

.. code:: console
  :number-lines:

  python3 t.py '1+4*(3-1)'
  E:  1+4*(3-1)
  T:  1+4*(3-1)
  F:  1+4*(3-1)
  Number:  1.0
  Op:  +4*(3-1)
  T:  4*(3-1)
  F:  4*(3-1)
  Number:  4.0
  Op:  *(3-1)
  F:  (3-1)
  E:  3-1)
  T:  3-1)
  F:  3-1)
  Number:  3.0
  Op:  -1)
  T:  1)
  F:  1)
  Number:  1.0
  True

----

.. raw:: html

    <div id="yoograph790" class="substep"></div><script>
    d3.select("#yoograph790").graphviz().renderDot(`digraph {
        Start [label="E[1+4*(3-1)]"]
        A12 [label="E[1]"]
        A54 [label="T[1]"]
        A56 [label="F[1]"]
        Aplus1 [label="+"]
        A35r [label="T[4*(3-1)]"]
        A3545 [label="T[4]"]
        A35452 [label="F[4]"]
        Aplus2 [label="*"]
        A2 [label="F[(3-1)]"]
        A23 [label="("]
        A24 [label="E[3-1]"]
        A25 [label=")"]
        A1  [label="E[3]"]
        A13 [label="-"]
        A16 [label="T[1]"]
        A04 [label="T[3]"]
        A07 [label="F[1]"]
        A08 [label="F[3]"]
        Start -> A12
        Start -> Aplus1
        Start -> A35r
        A35r  -> A3545
        A3545 -> A35452
        A35r -> Aplus2
        A35r -> A2
        A2  -> A23
        A2  -> A24
        A2  -> A25
        A24 -> A1
        A24 -> A13
        A24 -> A16
        A1  -> A04
        A16 -> A07
        A04 -> A08
        A12 -> A54
        A54 -> A56
    }`); </script>

.. :

    1. E → E + T | E - T | T  ,  2.  T → T * F | T / F | F , 3. F → (E) | a

----

:class: grid-2col-class

.. raw:: html

    <div id="yoograph800" class="substep"></div><script>
    d3.select("#yoograph800").graphviz().renderDot(`digraph {
      Start [label="E[1+4*(3-1)]"]
      A54 [label="T[1]"]
      A56 [label="F[1]"]
      Aplus1 [label = "+"]
      A35r [label="T[4*(3-1)]"]
      A35452 [label="F[4]"]
      Aplus2 [label="*"]
      A2 [label="F[(3-1)]"]
      A23 [label="("]
      A24 [label="E[3-1]"]
      A25 [label=")"]
      A04 [label="T[3]"]
      A13 [label="-"]
      A16 [label="T[1]"]
      A07 [label="F[1]"]
      A08 [label="F[3]"]
      Start -> A54
      Start -> Aplus1
      Start -> A35r
      A35r  -> A35452
      A35r  -> Aplus2
      A35r  -> A2
      A2    -> A23
      A2    -> A24
      A2    -> A25
      A24   -> A04
      A24   -> A13
      A24   -> A16
      A16   -> A07
      A04   -> A08
      A54   -> A56
    }`); </script>


.. code:: console
  :number-lines:

  python3 t.py '1+4*(3-1)'
  E:  1+4*(3-1)
  T:  1+4*(3-1)
  F:  1+4*(3-1)
  Number:  1.0
  Op:  +4*(3-1)
  T:  4*(3-1)
  F:  4*(3-1)
  Number:  4.0
  Op:  *(3-1)
  F:  (3-1)
  E:  3-1)
  T:  3-1)
  F:  3-1)
  Number:  3.0
  Op:  -1)
  T:  1)
  F:  1)
  Number:  1.0
  True


----

:class: t2c

Calculator
====================================================
.. include:: src/rd/e_t_f_plus_minus_mul_divide_calc.py
  :code: python
  :number-lines: 2
  :start-line: 2
  :end-line: 31

.. include:: src/rd/e_t_f_plus_minus_mul_divide_calc.py
  :code: python
  :number-lines: 31
  :start-line: 31
  :end-line: 76


----

:class: t2c

Calculator(IV)(lexical)
====================================================
.. include:: src/rd/e_t_f_plus_minus_mul_divide_calc2.py
  :code: python
  :number-lines: 0
  :start-line: 0
  :end-line: 25

.. include:: src/rd/e_t_f_plus_minus_mul_divide_calc2.py
  :code: python
  :number-lines: 25
  :start-line: 25
  :end-line: 47


----

:class: t2c

Calculator(V)
====================================================
.. include:: src/rd/e_t_f_plus_minus_mul_divide_calc2.py
  :code: python
  :number-lines: 47
  :start-line: 47
  :end-line: 70

.. include:: src/rd/e_t_f_plus_minus_mul_divide_calc2.py
  :code: python
  :number-lines: 70
  :start-line: 70
  :end-line: 100

----

:class: t2c

Calculator(VI) - lexical
====================================================
.. include:: src/rd/e_t_f_plus_minus_mul_divide_calc16.cpp
  :code: python
  :number-lines: 0
  :start-line: 0
  :end-line: 31

.. include:: src/rd/e_t_f_plus_minus_mul_divide_calc16.cpp
  :code: python
  :number-lines: 31
  :start-line: 31
  :end-line: 63

----

:class: t2c

Calculator(VII)
====================================================
.. include:: src/rd/e_t_f_plus_minus_mul_divide_calc16.cpp
  :code: python
  :number-lines: 63
  :start-line: 63
  :end-line: 90

.. include:: src/rd/e_t_f_plus_minus_mul_divide_calc16.cpp
  :code: python
  :number-lines: 90
  :start-line: 90
  :end-line: 113


----

End

.. comments:

    rst2html syn.rst syn.html
    hovercraft syn.rst

    https://www.csd.uwo.ca/~mmorenom/CS447/Lectures/Syntax.html/node8.html

    https://www.researchgate.net/publication/2367776_An_Introduction_to_Compilers?enrichId=rgreq-3d6589b36b650b1be61ea0ce1b1b7805-XXX&enrichSource=Y292ZXJQYWdlOzIzNjc3NzY7QVM6OTg4Mjk0MzcyNDMzOTVAMTQwMDU3NDE4MjE5Ng%3D%3D&el=1_x_2&_esc=publicationCoverPdf

    https://www.tutorialspoint.com/compiler_design/compiler_design_syntax_analysis.htm

