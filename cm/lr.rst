:data-transition-duration: 1000
:skip-help: true
:css: ./style.css
:substep: true
:slide-numbers: true

.. :

    .. meta::

      :charset: utf-8

    :js: https://d3js.org/d3.v5.min.js  https://unpkg.com/@hpcc-js/wasm@0.3.11/dist/index.min.js https://unpkg.com/d3-graphviz@3.0.5/build/d3-graphviz.js

----

LR
=====
Syntax Analysis(LR)
-----------------------
Ahmad Yoosofan

Compiler course

University of Kashan

https://yoosofan.github.io/course/compiler.html

.. raw:: html

    <script src="https://d3js.org/d3.v5.min.js"></script>
    <script src="https://unpkg.com/@hpcc-js/wasm@0.3.11/dist/index.min.js"></script>
    <script src="https://unpkg.com/d3-graphviz@3.0.5/build/d3-graphviz.js"></script>

.. :

    :js: d3.v5.min.js index.min.js  d3-graphviz.js



    ##https://graphviz.org/Gallery/directed/psg.html
    ##"I made a program to generate dot files representing the LR(0) state graph along with computed LALR(1) lookahead for an arbitrary context-free grammar, to make the diagrams I used in this article: http://blog.lab49.com/archives/2471. The program also highlights errant nodes in red if the grammar would produce a shift/reduce or reduce/reduce conflict -- you may be able to go to http://kthielen.dnsalias.com:8082/ to produce a graph more to your liking". Contributed by Kalani Thielen.

    ##Command to get the layout: "dot -Gsize=10,15 -Tpng thisfile > thisfile.png"


    digraph g {
      fontname="Helvetica,Arial,sans-serif"
      node [fontname="Helvetica,Arial,sans-serif"]
      edge [fontname="Helvetica,Arial,sans-serif"]
      graph [fontsize=30 labelloc="t" label="" splines=true overlap=false rankdir = "LR"];
      ratio = auto;
      "state0" [ style = "filled, bold" penwidth = 5 fillcolor = "white" fontname = "Courier New" shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="3" bgcolor="white"><tr><td bgcolor="black" align="center" colspan="2"><font color="white">State #0</font></td></tr><tr><td align="left" port="r0">(0) s → .e $ </td></tr><tr><td align="left" port="r1">(1) e → .l '=' r </td></tr><tr><td align="left" port="r2">(2) e → .r </td></tr><tr><td align="left" port="r3">(3) l → .'*' r </td></tr><tr><td align="left" port="r4">(4) l → .'n' </td></tr><tr><td align="left" port="r5">(5) r → .l </td></tr></table>> ];
      "state1" [ style = "filled" penwidth = 1 fillcolor = "white" fontname = "Courier New" shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="3" bgcolor="white"><tr><td bgcolor="black" align="center" colspan="2"><font color="white">State #1</font></td></tr><tr><td align="left" port="r3">(3) l → .'*' r </td></tr><tr><td align="left" port="r3">(3) l → '*' .r </td></tr><tr><td align="left" port="r4">(4) l → .'n' </td></tr><tr><td align="left" port="r5">(5) r → .l </td></tr></table>> ];
      "state2" [ style = "filled" penwidth = 1 fillcolor = "white" fontname = "Courier New" shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="3" bgcolor="white"><tr><td bgcolor="black" align="center" colspan="2"><font color="white">State #2</font></td></tr><tr><td align="left" port="r4">(4) l → 'n' .</td><td bgcolor="grey" align="right">=$</td></tr></table>> ];
      "state3" [ style = "filled" penwidth = 1 fillcolor = "white" fontname = "Courier New" shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="3" bgcolor="white"><tr><td bgcolor="black" align="center" colspan="2"><font color="white">State #3</font></td></tr><tr><td align="left" port="r5">(5) r → l .</td><td bgcolor="grey" align="right">=$</td></tr></table>> ];
      "state4" [ style = "filled" penwidth = 1 fillcolor = "white" fontname = "Courier New" shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="3" bgcolor="white"><tr><td bgcolor="black" align="center" colspan="2"><font color="white">State #4</font></td></tr><tr><td align="left" port="r3">(3) l → '*' r .</td><td bgcolor="grey" align="right">=$</td></tr></table>> ];
      "state5" [ style = "filled" penwidth = 1 fillcolor = "black" fontname = "Courier New" shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="3" bgcolor="black"><tr><td bgcolor="black" align="center" colspan="2"><font color="white">State #5</font></td></tr><tr><td align="left" port="r0"><font color="white">(0) s → e .$ </font></td></tr></table>> ];
      "state6" [ style = "filled" penwidth = 1 fillcolor = "white" fontname = "Courier New" shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="3" bgcolor="white"><tr><td bgcolor="black" align="center" colspan="2"><font color="white">State #6</font></td></tr><tr><td align="left" port="r1">(1) e → l .'=' r </td></tr><tr><td align="left" port="r5">(5) r → l .</td><td bgcolor="grey" align="right">$</td></tr></table>> ];
      "state7" [ style = "filled" penwidth = 1 fillcolor = "white" fontname = "Courier New" shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="3" bgcolor="white"><tr><td bgcolor="black" align="center" colspan="2"><font color="white">State #7</font></td></tr><tr><td align="left" port="r1">(1) e → l '=' .r </td></tr><tr><td align="left" port="r3">(3) l → .'*' r </td></tr><tr><td align="left" port="r4">(4) l → .'n' </td></tr><tr><td align="left" port="r5">(5) r → .l </td></tr></table>> ];
      "state8" [ style = "filled" penwidth = 1 fillcolor = "white" fontname = "Courier New" shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="3" bgcolor="white"><tr><td bgcolor="black" align="center" colspan="2"><font color="white">State #8</font></td></tr><tr><td align="left" port="r1">(1) e → l '=' r .</td><td bgcolor="grey" align="right">$</td></tr></table>> ];
      "state9" [ style = "filled" penwidth = 1 fillcolor = "white" fontname = "Courier New" shape = "Mrecord" label =<<table border="0" cellborder="0" cellpadding="3" bgcolor="white"><tr><td bgcolor="black" align="center" colspan="2"><font color="white">State #9</font></td></tr><tr><td align="left" port="r2">(2) e → r .</td><td bgcolor="grey" align="right">$</td></tr></table>> ];
      "I4"
      state0 -> state5 [ penwidth = 5 fontsize = 28 fontcolor = "black" label = "e" ];
      state0 -> state6 [ penwidth = 5 fontsize = 28 fontcolor = "black" label = "l" ];
      state0 -> state9 [ penwidth = 5 fontsize = 28 fontcolor = "black" label = "r" ];
      state0 -> state1 [ penwidth = 1 fontsize = 14 fontcolor = "grey28" label = "'*'" ];
      state0 -> state2 [ penwidth = 1 fontsize = 14 fontcolor = "grey28" label = "'n'" ];
      state1 -> state1 [ penwidth = 1 fontsize = 14 fontcolor = "grey28" label = "'*'" ];
      state1 -> state4 [ penwidth = 5 fontsize = 28 fontcolor = "black" label = "r" ];
      state1 -> state2 [ penwidth = 1 fontsize = 14 fontcolor = "grey28" label = "'n'" ];
      state1 -> state3 [ penwidth = 5 fontsize = 28 fontcolor = "black" label = "l" ];
      state6 -> state7 [ penwidth = 1 fontsize = 14 fontcolor = "grey28" label = "'='" ];
      state7 -> state8 [ penwidth = 5 fontsize = 28 fontcolor = "black" label = "r" ];
      state7 -> state1 [ penwidth = 1 fontsize = 14 fontcolor = "grey28" label = "'*'" ];
      state7 -> state2 [ penwidth = 1 fontsize = 14 fontcolor = "grey28" label = "'n'" ];
      state7 -> state3 [ penwidth = 5 fontsize = 28 fontcolor = "black" label = "l" ];
    }


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

Testing Css flexbox

.. raw:: html

    <div id="graph2"></div>
    <script>
    d3.select("#graph2").graphviz().renderDot(`

      digraph g {
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
    `);
    </script>


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

.. raw:: html

    <div id="graph3"></div>
    <script>
    d3.select("#graph3").graphviz().renderDot(`

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

.. raw:: html

    <div id="graph4"></div>
    <script>
    d3.select("#graph4").graphviz().renderDot(`

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
    `);
    </script>
 
----

.. raw:: html

    <div id="graph50"></div>
    <script>
    d3.select("#graph50").graphviz().renderDot(`

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
    `);
    </script>
 
----

.. raw:: html

    <div id="graph70"></div>
    <script>
    d3.select("#graph70").graphviz().renderDot(`

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
    `);
    </script>
 
----

.. raw:: html

    <div id="graph80"></div>
    <script>
    d3.select("#graph80").graphviz().renderDot(`

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
    `);
    </script>
 
----

.. raw:: html

    <div id="graph90"></div>
    <script>
    d3.select("#graph90").graphviz().renderDot(`

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
    `);
    </script>
 
----

.. raw:: html

    <div id="graph110"></div>
    <script>
    d3.select("#graph110").graphviz().renderDot(`

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
    `);
    </script>
 
----

.. raw:: html

    <div id="graph120"></div>
    <script>
    d3.select("#graph120").graphviz().renderDot(`

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
    `);
    </script>
 
----

.. raw:: html

    <div id="graph130"></div>
    <script>
    d3.select("#graph130").graphviz().renderDot(`

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
    `);
    </script>

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
