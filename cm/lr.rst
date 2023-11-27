:data-transition-duration: 1000
:skip-help: true
:css: ./style.css
:substep: true
:slide-numbers: true

----

LR
=====
Syntax Analysis(LR)
-----------------------
Bottom-Up Parsing

Ahmad Yoosofan

Compiler course

University of Kashan

https://yoosofan.github.io/course/compiler.html


----

:class: t2c

Simple Add(I)
======================
.. class:: substep

#. E → E + a
#. E → a

.. yographviz::
  :class: substep

  digraph {
    graph [splines=true  rankdir = "LR"];
    ratio = auto;

    "state0" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
      <tr><td align="left" port="r0">E → .E + a</td></tr>
      <tr><td align="left" port="r1">E → .a </td></tr>
    </table>>];
  }

.. :

----

:class: t2c

Simple Add(II)
======================
#. E → E + a
#. E → a

.. yographviz::
  :class: substep

    digraph {
      graph [splines=true  rankdir = "LR"];
      ratio = auto;

      "state0" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
        <tr><td align="left" port="r0">E → .E + a</td></tr>
        <tr><td align="left" port="r1">E → .a </td></tr>
        </table>>];

      "state2" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
        <tr><td align="left" port="r1">E → a. </td></tr>
        </table>>];

      state0 -> state2 [ label = "a" ];
    }


----

:class: t2c

Simple Add(III)
======================
#. E → E + a
#. E → a

.. yographviz::
  :class: substep

    digraph {
      graph [splines=true  rankdir = "LR"];
      ratio = auto;

      "state0" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
        <tr><td align="left" port="r0">E → .E + a</td></tr>
        <tr><td align="left" port="r1">E → .a </td></tr>
        </table>>];

      "state1" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
        <tr><td align="left" port="r1">E → E. + a </td></tr>
        </table>>];

      "state2" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
        <tr><td align="left" port="r1">E → a. </td></tr>
        </table>>];

      state0 -> state1 [ label = "E" ];
      state0 -> state2 [ label = "a" ];
    }


----

:class: t2c

Simple Add(IV)
======================
#. E → E + a
#. E → a

.. yographviz::

    digraph {
      graph [splines=true  rankdir = "LR"];
      ratio = auto;

      "state0" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
        <tr><td align="left" port="r0">E → .E + a</td></tr>
        <tr><td align="left" port="r1">E → .a </td></tr>
        </table>>];

      "state1" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
        <tr><td align="left" port="r1">E → E. + a </td></tr>
        </table>>];

      "state2" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
        <tr><td align="left" port="r1">E → a. </td></tr>
        </table>>];

      "state3" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
        <tr><td align="left" port="r1">E → E +. a </td></tr>
        </table>>];


      state0 -> state1 [ label = "E" ];
      state0 -> state2 [ label = "a" ];
      state1 -> state3 [ label = "+" ];
    }


----

:class: t2c

Simple Add(V)
======================
#. E → E + a
#. E → a

.. yographviz::

    digraph {
      graph [splines=true  rankdir = "LR"];
      ratio = auto;

      "state0" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
        <tr><td align="left" port="r0">E → .E + a</td></tr>
        <tr><td align="left" port="r1">E → .a </td></tr>
        </table>>];

      "state1" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
        <tr><td align="left" port="r1">E → E. + a </td></tr>
        </table>>];

      "state2" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
        <tr><td align="left" port="r1">E → a. </td></tr>
        </table>>];

      "state3" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
        <tr><td align="left" port="r1">E → E +. a </td></tr>
        </table>>];

      "state4" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
        <tr><td align="left" port="r1">E → E + a. </td></tr>
        </table>>];

      state0 -> state1 [ label = "E" ];
      state0 -> state2 [ label = "a" ];
      state1 -> state3 [ label = "+" ];
      state3 -> state4 [ label = "a" ];
    }


----

:class: t2c

Simple Add(VI)
======================
#. E → E + a
#. E → a

.. yographviz::

    digraph {
      graph [splines=true  rankdir = "LR"];
      ratio = auto;

      "state0" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
        <tr><td align="left" port="r0">E → .E + a</td></tr>
        <tr><td align="left" port="r1">E → .a </td></tr>
        </table>>];

      "state1" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
        <tr><td align="left" port="r1">E → E. + a </td></tr>
        </table>>];

      "state2" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
        <tr><td align="left" port="r1">E → a. </td></tr>
        </table>>];

      "state3" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
        <tr><td align="left" port="r1">E → E +. a </td></tr>
        </table>>];

      "state4" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
        <tr><td align="left" port="r1">E → E + a. </td></tr>
        </table>>];

      state0 -> state1 [ label = "E" ];
      state0 -> state2 [ label = "a" ];
      state1 -> state3 [ label = "+" ];
      state3 -> state4 [ label = "a" ];
    }

.. class:: substep

* input: 3+5+1
* a(3)+a(5)+a(1)
* a+a+a


----

:class: t2c

Simple Add(VII)
======================
#. S → E 
#. E → E + a
#. E → a

.. yographviz::

    digraph {
      graph [splines=true  rankdir = "LR"];
      ratio = auto;

      "state0" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
        <tr><td align="left" port="r0">S → .E </td></tr>
        <tr><td align="left" port="r0">E → .E + a</td></tr>
        <tr><td align="left" port="r1">E → .a </td></tr>
        </table>>];

      "state1" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
        <tr><td align="left" port="r0">S → E. </td></tr>
        <tr><td align="left" port="r0">E → E. + a</td></tr>
        </table>>];

      "state2" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
        <tr><td align="left" port="r1">E → a. </td></tr>
        </table>>];

      "state3" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
        <tr><td align="left" port="r1">E → E +. a </td></tr>
        </table>>];

      "state4" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
        <tr><td align="left" port="r1">E → E + a. </td></tr>
        </table>>];

      state0 -> state1 [ label = "E" ];
      state0 -> state2 [ label = "a" ];
      state1 -> state3 [ label = "+" ];
      state3 -> state4 [ label = "a" ];
    }


----

:class: t2c

Simple Add(VII)
======================
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


----

:class: t2c

Simple Calculator(I)
======================
#. E → E + T
#. E → E - T
#. E → T
#. T → T * F
#. T → T / F
#. T → F
#. F → (E)
#. F → a

.. yographviz::
  :class: substep

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
      <tr><td align="left" port="r3">E → a. </td></tr>
    </table>> ];

    state0 -> state1 [ label = "a" ];
  }

----

:class: t2c

Simple Calculator(II)
======================
#. E → E + T
#. E → E - T
#. E → T
#. T → T * F
#. T → T / F
#. T → F
#. F → (E)
#. F → a

.. yographviz::
  :class: substep

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
      <tr><td align="left" port="r3">F → a. </td></tr>
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

----

.. yographviz::

  digraph {
    graph [splines=true  rankdir = "LR" size="100pt,300pt"];
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
      <tr><td align="left" port="r1">F → (.E + T) </td></tr>
      <tr><td align="left" port="r1">F → (.E - T) </td></tr>
      <tr><td align="left" port="r1">F → (.T) </td></tr>
      <tr><td align="left" port="r1">F → (.T * F) </td></tr>
      <tr><td align="left" port="r1">F → (.T / F) </td></tr>
      <tr><td align="left" port="r1">T → .F </td></tr>
      <tr><td align="left" port="r1">F → (.a) </td></tr>
      <tr><td align="left" port="r1">F → .(E) </td></tr>
    </table>>];

    state0 -> state1 [ label = "E" ];
    state0 -> state2 [ label = "T" ];
    state0 -> state3 [ label = "F" ];
    state0 -> state4 [  label = ".a" ];
    state0 -> state5 [  label = "(" ];
  }


----

.. yographviz::
  :class: substep

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
      <tr><td align="left" port="r1">F → (.E + T) </td></tr>
      <tr><td align="left" port="r1">F → (.E - T) </td></tr>
      <tr><td align="left" port="r1">F → (.T) </td></tr>
      <tr><td align="left" port="r1">F → (.T * F) </td></tr>
      <tr><td align="left" port="r1">F → (.T / F) </td></tr>
      <tr><td align="left" port="r1">F → (.F) </td></tr>
      <tr><td align="left" port="r1">F → (.a) </td></tr>
      <tr><td align="left" port="r1">F → (.(E)) </td></tr>
    </table>>];

    state0 -> state1 [ label = "E" ];
    state0 -> state2 [ label = "T" ];
    state0 -> state3 [ label = "F" ];
    state0 -> state4 [  label = ".a" ];
    state0 -> state5 [  label = "(" ];
  }

----

.. image:: img/lr/slr_etf.png

----

Ambiguous Grammar
==================
.. code:: fortran

    if x = 2 then
        x = 3
    else
        x = 4

.. class:: substep

#. S → i S
#. S → i S e S
#. S → o

----


#. S → i S M
#. M → e S
#. M → λ
#. S → o

----


:class: t2c

An Especial Grammar
======================
#. S → L = R
#. S → R
#. L → * R
#. L → a
#. R → L

.. container:: substep

  Augmented Grammer

  * S' → S

  #. S → L = R
  #. S → R
  #. L → * R
  #. L → a
  #. R → L

----

.. :

    Testing Css flexbox

    .. yographviz::
      :class: substep

          digraph  {
            graph [splines=true  rankdir = "LR"];
            ratio = auto;
            "state0" [ shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="0">
              <tr><td>(I<sub>0</sub>)</td></tr>
              <tr><td align="left" port="r0">S' → .S </td></tr>
              <tr><td align="left" port="r1">S → .L = R </td></tr>
              <tr><td align="left" port="r2">S → .R </td></tr>
              <tr><td align="left" port="r3">L → .* R </td></tr>
              <tr><td align="left" port="r4">L → .a </td></tr>
              <tr><td align="left" port="r5">R → .L </td></tr>
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

    ----

    * follow(S) = { }
    * follow(L) = {}
    * follow(R) = {}

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

     
    ----

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
        `);
        </script>
     
    ----

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
     
    ----

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
     
    ----

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
     
    ----

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
     
    ----

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
     
    ----

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
     
    ----

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
     
    ----

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

    ----


    LALR
    =======
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
