:data-transition-duration: 1000
:skip-help: true
:css: assets/hovercraft.css assets/css.css
:substep: true

.. title: HTML (By Ahmad Yoosofan)

:slide-numbers: true

.. role:: ltr
    :class: ltr

.. role:: rtl
    :class: rtl

Cascade Style Sheet (CSS)
==========================
Ahmad Yoosofan

http://yoosofan.github.io/

Search "Ahmad Yoosofan"

----

Inline Style
===============
.. code:: html

    <div style="color:red;">

----

:class: simple-html01-class

.. include:: src/css/css210.html
    :code: html
    :number-lines:

.. raw:: html

   <iframe src="http://127.0.0.1:8002/src/css/css210.html" title="description" class="output-of-html">
   </iframe>

----

learn css
=============
* https://developer.mozilla.org/en-US/docs/Learn/Getting_started_with_the_web/CSS_basics
* https://developer.mozilla.org/en-US/docs/Web/CSS
* https://web.dev/learn/css/box-model/
* https://www.w3schools.com/css/
* https://developer.mozilla.org/en-US/docs/Learn/CSS
* https://www.smashingmagazine.com/2019/01/how-to-learn-css/
* https://learnlayout.com/no-layout.html

internal vs external css
----------------------------
* https://www.bitdegree.org/learn/style-html#:~:text=The%20internal%20CSS%20is%20for,to%20link%20HTML%20to%20CSS.
* https://www.hostpapa.com/knowledgebase/understanding-inline-internal-external-css-styles/
* https://www.hostinger.vn/huong-dan/khac-biet-giua-inline-external-va-internal-style-css/
* https://stackoverflow.com/questions/553074/internal-vs-external-css

----

Internal Style
==================
.. code:: html

    <head>
    <style type="text/css">
      p {
        color: red;
      }
    </style>
    </head>

----

:class: t2c

Simple Tag Selector
=========================
.. include:: src/css/css220.html
    :code: html
    :number-lines:

.. raw:: html

   <iframe src="http://127.0.0.1:8002/src/css/css220.html" title="description" class="output-of-html">
   </iframe>

----

Selector(I)
================
Tag selector
---------------
.. code:: html

  <style>
    h1 {
      background-color: grey;
      color: white;
    }
    p {
      color: silver;
    }
  <style>

----

:class: t2c

Selector(I) Sample
======================
.. include:: src/css/css230.html
    :code: html
    :number-lines:

.. raw:: html

   <iframe src="http://127.0.0.1:8002/src/css/css230.html" title="description" class="output-of-html">
   </iframe>

----

.. image:: img/css/css-declaration-small.png

.. :

  https://developer.mozilla.org/en-US/docs/Learn/Getting_started_with_the_web/CSS_basics

----

Colors(I)
==============
By name
--------------
* https://htmlcolorcodes.com/
* https://www.w3schools.com/cssref/css_colors.asp
* https://www.w3schools.com/css/css_colors.asp
* https://developer.mozilla.org/en-US/docs/Web/CSS/color_value
* https://www.w3schools.com/colors/colors_picker.asp
* https://www.w3.org/wiki/CSS/Properties/color/keywords
* https://www.geeksforgeeks.org/css-color-property/

----

Selector(II)
================
Id selector
---------------
.. code:: html

  <style>
     #text-background-color{
      background-color: grey;
      color: white;
    }
    #text-color {
      color: silver;
    }
  <style>

----

:class: t2c

Selector(II) Sample
======================
.. include:: src/css/css240.html
    :code: html
    :number-lines:

.. raw:: html

   <iframe src="http://127.0.0.1:8002/src/css/css240.html" title="description" class="output-of-html">
   </iframe>

----

Naming conventions (BEM)
===========================
* http://getbem.com/
* http://getbem.com/naming/
* http://bdavidxyz.com/blog/how-to-name-css-classes/
* https://www.freecodecamp.org/news/css-naming-conventions-that-will-save-you-hours-of-debugging-35cea737d849/
* https://zellwk.com/blog/css-architecture-1/
* https://zellwk.com/blog/css-architecture-2/

----

Selector(III)
================
class selector
---------------
.. code:: html

  <style>
     .background-grey{
      background-color: grey;
      color: white;
    }
    .color-silver{
      color: silver;
    }
  <style>

----

:class: t2c

Selector(III) Sample
======================
.. include:: src/css/css250.html
    :code: html
    :number-lines:

.. raw:: html

   <iframe src="http://127.0.0.1:8002/src/css/css250.html" title="description" class="output-of-html">
   </iframe>

----

External CSS
================
.. code:: html

  <link rel="stylesheet" type="text/css" href="mystyle.css" />

  <link rel="stylesheet" href="secondstyle.css" />


----

Box Model(I)
=============
.. image:: img/css/boxmodel.png
  :width: 500px
  :height: 400px

----

width, height
====================
.. code:: css

  width: 230px;
  height: 340px;

----

border
===========
.. code:: css

  border: 2px;
  border-color: blue;
  border-style: solid;

.. raw:: html

  <div style="border:2px; border-color: blue;border-style: solid; margin:4px;">
    border:2px;
  </div>

.. code:: css

  border-width: 4px;
  border-color: blue;
  border-style: dashed;

.. raw:: html

  <div style="border-width:4px; border-color:blue;border-style:dashed; margin:4px;">
    border-width:4px;
  </div>

.. code:: css

  border: 4px blue dashed;

.. raw:: html

  <div style="border:4px blue dashed; margin:4px;">
    border-width:4px;
  </div>

----

border-style
===============
.. raw:: html

  <div style="border-width: 6px; border-color: blue; border-style: dashed; padding:4px;margin:8px;">
    dashed
  </div>
  <div style="border-width: 6px; border-color: blue; border-style: solid; padding:4px;margin:8px;">
    solid
  </div>
  <div style="border-width: 6px; border-color: blue; border-style: dotted; padding:4px;margin:8px;">
    dotted
  </div>
  <div style="border-width: 6px; border-color: blue; border-style: double; padding:4px;margin:8px;">
    double
  </div>
  <div style="border-width: 6px; border-color: blue; border-style: ridge; padding:4px;margin:8px;">
    ridge
  </div>
  <div style="border-width: 6px; border-color: blue; border-style: outset; padding:4px;margin:8px;">
    outset
  </div>
  <div style="border-width: 6px; border-color: blue; border-style: inset; padding:4px;margin:8px;">
    inset
  </div>
  <div style="border-width: 6px; border-color: blue; border-style: none; padding:4px;margin:8px;">
    none
  </div>
  <div style="border-width: 6px; border-color: blue; border-style: groove; padding:4px;margin:8px;">
    groove
  </div>

----

:id: border-top-bottom-id

.. code:: css
  :number-lines:

  border-width: 2px;
  border-style: solid;
  padding: 4px;
  margin: 8px;
  border-color: blue;

  border-top-color: rgb(170, 50, 220, .6);
  border-right-color: green;
  border-bottom-color: red;
  border-left-color: yellow;

  border-color: rgb(170, 50, 220, .6) green red yellow

.. class:: substep

  border-top-color: rgb(170, 50, 220, .6);

  border-right-color: green;

  border-bottom-color: red;

  border-left-color: yellow;

  border-color: rgb(170, 50, 220, .6) green red yellow;

.. :

  https://developer.mozilla.org/en-US/docs/Web/CSS/border-bottom-color

----

:id: border-top-right-bottom-style-id

Shorthand Style Order(I)
=========================
.. class:: substep

  border-top-style: double;

  border-right-style: dashed;

  border-bottom-style: dotted;

  border-left-style: none;

  border-style: double dashed dotted none;

.. class:: substep

* top
* right
* bottom
* left
* clockwise

----

:id: border-style-combine-II-id

Shorthand Style Order(II)
============================
.. class:: substep

  border-style: double;

  border-style: double dotted;

  border-style: double dotted none;

  border-style: double groove dotted solid; border-width:10px;

.. class:: substep

* When one value is specified, it applies the same style to all four sides.
* When two values are specified, the first style applies to the top and bottom, the second to the left and right.
* When three values are specified, the first style applies to the top, the second to the left and right, the third to the bottom.
* When four values are specified, the styles apply to the top, right, bottom, and left in that order (clockwise).

.. :

  https://developer.mozilla.org/en-US/docs/Web/CSS/border-style
  https://developer.mozilla.org/en-US/docs/Web/CSS/Shorthand_properties
  https://developer.mozilla.org/en-US/docs/Web/CSS/border-bottom
  https://developer.mozilla.org/en-US/docs/Web/CSS/border
  https://developer.mozilla.org/en-US/docs/Web/CSS/border-color
  https://developer.mozilla.org/en-US/docs/Web/CSS/border-width

----

:class: grid-2col-class
:id: padding-id

Padding(14px)
=================
.. class:: substep

  padding: 10px;

  padding: 8px;

  padding: 6px;

  padding: 4px;

  padding: 2px;

  padding-top: 2px;

  padding-right: 2px;

  padding-bottom: 2px;

  padding-left: 2px;

  padding-left: 10px;

  padding: 2px 8px;

  padding: 2px 8px 14px;

  padding: 2px 8px 14px 20px;

----

:class: grid-2col-class
:id: margin14px-id

margin(14px)
=================
.. class:: substep

  margin: 10px;

  margin: 8px;

  margin: 6px;

  margin: 4px;

  margin: 2px;

  margin-top: 2px;

  margin-right: 2px;

  margin-bottom: -20px;

  margin-left: 2px;

  margin: 2px 8px;

  margin: 2px 8px 14px;

  margin: 2px 8px 14px 20px;

.. :

  https://developer.mozilla.org/en-US/docs/Web/CSS/Shorthand_properties

----

Selector(IV): Selecting multiple element
=========================================
.. class:: substep

* sample
    .. code:: css

        h1, head, foot, .heading-element{
          background-color: lightgrey;
        }
* If any selector is invalid the whole rule will be ignored
    .. code:: css
        :number-lines:

        h2{
          color:red;
          background-color:blue;
        }
        h3{
          color:red,
          background-color:blue;
        }
    .. code:: css
        :number-lines:

        h2, h3{
          color:red,
          background-color:blue;
        }

.. :

    https://developer.mozilla.org/en-US/docs/Learn/CSS/Building_blocks/Selectors

----

:class: t2c

Selector(V): Combinator(I)
===========================
.. code:: css
  :number-lines:
  :class: substep

  /*Descendant combinator */
  main div {
    background-color: white;
  }

  footer div a {
    background-color: lightgrey;
  }

.. code:: html
  :class: substep

  <main>
    <div>
      sdfsd
      <div>
        56t56
      </div>
      34543
    </div>
    23423
  </main>
  <footer>
    <div>
      <a href="#"> dd <a>
      <div>
        <a href="#"> dd <a>
      </div>
        <a href="#"> dd <a>
    </div>
  </footer>

.. code:: css
  :number-lines:
  :class: substep

  /*Child combinator*/
  main > div {
    background-color: white;
  }

  footer > div > a {
    background-color: lightgrey;
  }

----

:class: t2c

.. include:: src/css/css320_combinator.html
    :code: html
    :number-lines:

.. raw:: html

   <iframe src="http://127.0.0.1:8002/src/css/css320_combinator.html" title="description" class="output-of-html">
   </iframe>


----

:id: selector-vi-combinator-ii

Selector(VI): Combinator(II)
=============================
Adjacent sibling combinator
-------------------------------
.. code:: html
  :number-lines:

  <main>
    <h1>Introduction</h1>
    <p>In this book we are ... </p>
    <p>This new approch lead us ... </p>
    <p>However, we must consider ... </p>
  </main>

.. code:: css
  :class: substep
  :number-lines:

  p { padding-left: 24px;}
  h1 + p {
    padding-left: 4px;
  }

.. raw:: html

  <main>
    <h1>Introduction</h1>
    <p>In this book we are ... </p>
    <p>This new approch lead us ... </p>
    <p>However, we must consider ... </p>
  </main>

.. :

  https://www.w3.org/TR/CSS/#css
  https://developer.mozilla.org/en-US/docs/Learn/CSS/Building_blocks/Selectors/Combinators

----

:id: selector-vii-combinator-iii

Selector(VII): Combinator(III)
===============================
General sibling combinator
-------------------------------
.. code:: html
  :number-lines:

  <main>
    <h1>Introduction</h1>
    <p>In this book we are ... </p>
    <div>This new approch lead us ... </div>
    <p>However, we must consider ... </p>
  </main>

.. code:: css
  :class: substep
  :number-lines:
  
  main {background-color: green;}
  main p {padding-left: 24px; background-color:red;}
  main h1 ~ p {background-color: blue;}
  main h1 + p {padding-left: 4px; background-color:pink;}

.. raw:: html

  <main id="selector-vii-combinator-iii-main-223">
    <h1>Introduction</h1>
    <p>In this book we are ... </p>
    <div>This new approch lead us ... </div>
    <p>However, we must consider ... </p>
  </main>

----

Selector(VIII): Compounding multiple ID selectors
========================================================
.. code:: html
  :number-lines:

  <div id="border-top-bottom-id">
    <p> div1 p1 </p>
    <p> div1 p2 </p>
    <p> div1 p3 </p>
  </div>

.. code:: css
  :number-lines:

  div#border-top-bottom-id p{
    border-top-color: rgb(170, 50, 220, .6);
  }

.. code:: html
  :number-lines:

  <div>
    <div id="border-top-bottom-id">
      <p> div1 p1 </p>
      <p> div1 p2 </p>
      <p> div1 p3 </p>
    </div>
    <div>
      <p> div2 p1 </p>
      <p> div2 p2 </p>
      <p> div2 p3 </p>
    </div>
  </div>

.. code:: css
  :number-lines:

  div #border-top-bottom-id p{
    border-top-color: rgb(170, 50, 220, .6);
  }

----

Selector(IX): Compounding multiple class selectors
======================================================
.. code:: html
  :number-lines:

  <div class="border-top-bottom-id">
    <p> div1 p1 </p>
    <p> div1 p2 </p>
    <p> div1 p3 </p>
  </div>

.. code:: css
  :number-lines:

  div.border-top-bottom-id p{
    border-top-color: rgb(170, 50, 220, .6);
  }

.. code:: html
  :number-lines:

  <div>
    <div class="border-top-bottom-id">
      <p> div1 p1 </p>
      <p> div1 p2 </p>
      <p> div1 p3 </p>
    </div>
    <div>
      <p> div2 p1 </p>
      <p> div2 p2 </p>
      <p> div2 p3 </p>
    </div>
  </div>

.. code:: css
  :number-lines:

  div .border-top-bottom-id p{
    border-top-color: rgb(170, 50, 220, .6);
  }

----

Selector(X): Universal selectors
====================================================
.. code:: html
  :number-lines:

  <div class="border-top-bottom-id">
    <p> div1 p1 </p>
    <p> div1 p2 </p>
    <p> div1 p3 </p>
  </div>

.. code:: css
  :number-lines:

  * {
    color: green;
  }

  *.warning {
    color: red;
  }

  .floating {
    color: blue;
  }

  /* automatically clear the next sibling after a floating element */
  .floating + * {
    color: yellow;
  }

https://developer.mozilla.org/en-US/docs/Web/CSS/Universal_selectors

.. :

  multiple class

----

Selector(XI): Attribute selectors(I)
====================================================
.. code:: css
  :number-lines:

  /* <a> elements with a title  attribute */
  a[title] {  /*   <a href="#" title="a" >a</a> */
    color: purple;
  }
  /* <a> elements with an href  matching "https://example.org" */
  /* <a href="https://example.org" title="a" >a</a>*/
  a[href="https://example.org"] {
    color: green;
  }
  /* <a> elements whose class attribute contains the word "logo" */
  /* <a href="#" class="first second logo" >a</a> */
  a[class~="logo"] {
    padding: 2px;
  }
  /* <a href="#" class="mylogo34" >a</a> */
  a[class*="logo"] {
    padding: 2px;
  }

#. [attr]
#. [attr  = value]: attr whose value is exactly value
#. [attr ~= value]: attr whose value is a whitespace-separated list of words, one of which is exactly value.
#. [attr ``|=`` value]: attr whose value can be exactly value or can begin with value immediately followed by a hyphen, - (U+002D). It is often used for language subcode matches.
#. [attr ^= value]: attr whose value is prefixed (preceded) by value.
#. [attr $= value]: attr whose value is suffixed (followed) by value.
#. [attr ``*=`` value]: attr whose value contains at least one occurrence of value within the string.

.. :

  * [attr operator value i]: Adding an i (or I) before the closing bracket causes the value to be compared case-insensitively (for characters within the ASCII range).
  * [attr operator value s]: Adding an s (or S) before the closing bracket causes the value to be compared case-sensitively (for characters within the ASCII range).

----

:id: selector-attribute-iii-id

Selector(XII): Attribute selectors(II)
====================================================
.. code:: css
  :number-lines:

  a {color: blue;}
  /* Internal links, beginning with "#" */
  a[href^="#"] { background-color: gold;}
  /* Links with "example" anywhere in the URL */
  a[href*="example"] {background-color: silver;}
  /* Links with "insensitive" anywhere in the URL, regardless of capitalization */
  a[href*="insensitive" i] {color: cyan;}
  /* Links with "cAsE" anywhere in the URL, with matching capitalization */
  a[href*="cAsE" s] {color: pink;}
  /* Links that end in ".org" */
  a[href$=".org"] {color: red;}
  /* Links that start with "https" and end in ".org" */
  a[href^="https"][href$=".org"] {color: green;}

.. code:: html
  :number-lines:

  <ul>
    <li><a href="#internal">Internal link</a></li>
    <li><a href="http://example.com">Example link</a></li>
    <li><a href="#InSensitive">Insensitive internal link</a></li>
    <li><a href="http://example.org">Example org link</a></li>
    <li><a href="https://example.org">Example https org link</a></li>
  </ul>

.. raw:: html

  <ul id="sample-view">
    <li><a href="#internal">Internal link</a></li>
    <li><a href="http://example.com">Example link</a></li>
    <li><a href="#InSensitive">Insensitive internal link</a></li>
    <li><a href="http://example.org">Example org link</a></li>
    <li><a href="https://example.org">Example https org link</a></li>
  </ul>

https://developer.mozilla.org/en-US/docs/Web/CSS/Attribute_selectors

----

:id: selector-attribute-iiii-id

Selector(XIII): Attribute selectors(III)
====================================================
.. code:: css
  :number-lines:

  /* All divs with a `lang` attribute are bold. */
  div[lang] {font-weight: bold;}
  /* All divs without a `lang` attribute are italicized. */
  div:not([lang]) {font-style: italic;}
  /* All divs in US English are blue. */
  div[lang~="en-us"] {color: blue;}
  /* All divs in Portuguese are green. */
  div[lang="pt"] {color: green;}
  /* All divs in Chinese are red, whether simplified (zh-CN) or traditional (zh-TW). */
  div[lang|="zh"] {color: red;}
  /* All divs with a Traditional Chinese `data-lang` are purple.
     Note: You could also use hyphenated attributes without double quotes */

.. code:: html

  <div lang="en-us en-gb en-au en-nz">Hello World!</div>
  <div lang="pt">Olá Mundo!</div>
  <div lang="zh-CN">世界您好！</div>
  <div lang="zh-TW">世界您好！</div>

.. raw:: html

  <main id="selector-attribute-iiii-sample">
    <div lang="en-us en-gb en-au en-nz">Hello World!</div>
    <div lang="pt">Olá Mundo!</div>
    <div lang="zh-CN">世界您好！</div>
    <div lang="zh-TW">世界您好！</div>
  </main>

https://developer.mozilla.org/en-US/docs/Web/CSS/Attribute_selectors

----

:id: font-size-id

Font Size
====================================================
.. code:: css
  :number-lines:

  font-size: xx-small;
  font-size: x-small;
  font-size: small;
  font-size: medium;
  font-size: large;
  font-size: x-large;
  font-size: xx-large;
  font-size: xxx-large;

  /* <relative-size> values */
  font-size: smaller;
  font-size: larger;

  /* <length> values */
  font-size: 12px;
  font-size: 0.8em;

.. code:: css
  :number-lines:

  #div1 {
    font-size: 62.5%; /* font-size 1em = 10px on default browser settings */
  }
  #div1 > span {
    font-size: 1.6em;
  }

.. code:: html

  <div id="div1">
    Outer <span>inner</span>
  </div>

.. raw:: html

  <div id="div1">
   Outer <span>inner</span> outer
  </div>

----

:id: font-family-I-id

Font Family
==============
.. code:: css
  :number-lines:

  .serif{font-family: Times, "Times New Roman", Georgia, serif;}
  .sansserif{font-family: Verdana, Arial, Helvetica, sans-serif;}
  .monospace{font-family: "Lucida Console", Courier, monospace;}
  .cursive{font-family: cursive;}
  .fantasy{font-family: fantasy;}
  .emoji{font-family: emoji;}
  .math {font-family: math;}
  .fangsong {font-family: fangsong;}
  .nazli{font-family: Nazli;}

#. This is an example of a serif font.
#. This is an example of a sans-serif font.
#. This is an example of a monospace font.
#. This is an example of a cursive font.
#. This is an example of a fantasy font.
#. This is an example of a math font.
#. This is an example of an emoji font.
#. This is an example of a fangsong font.
#. This is an example of a Nazli font.

----

:id: font-style-id

Font Style/weight
===================
.. code:: css
  :number-lines:

  li.normal{font-style: normal;}
  li.italic{font-style: italic;}
  li.oblique{font-style: oblique;}
  li.oblique10deg{font-style: oblique 10deg;}

  li.normal-weight {font-weight:normal ;}
  li.bold   {font-weight:bold   ;}
  li.bolder {font-weight:bolder ;}
  li.lighter{font-weight:lighter;}
  li.wgt100 {font-weight:100;}
  li.wgt200 {font-weight:200;}
  li.wgt300 {font-weight:300;}
  li.wgt400 {font-weight:400;}
  li.wgt500 {font-weight:500;}
  li.wgt600 {font-weight:600;}
  li.wgt700 {font-weight:700;}
  li.wgt800 {font-weight:800;}
  li.wgt900 {font-weight:900;}
  li.inherit{font-weight:inherit;}
  li.initial{font-weight:initial;}
  li.unset  {font-weight:unset  ;}


.. raw:: html

  <ol class="ol-font-style1">
    <li class="normal">       Normal Text(400)  </li>
    <li class="italic">       Italic Text       </li>
    <li class="oblique">      Oblique Text      </li>
    <li class="oblique10deg"> Oblique 10deg Text</li>
    <li class="normal-weight">Normal Text(400)  </li>
    <li class="bold">         Bold Text(700)    </li>
    <li class="bolder">       Bolder Text       </li>
    <li class="lighter">      lighter Text      </li>
    <li class="wgt100">       Weight 100 Text   </li>
    <li class="wgt200">       Weight 200 Text   </li>
    <li class="wgt300">       Weight 300 Text   </li>
    <li class="wgt400">       Weight 400 Text   </li>
    <li class="wgt500">       Weight 500 Text   </li>
    <li class="wgt600">       Weight 600 Text   </li>
    <li class="wgt700">       Weight 700 Text   </li>
    <li class="wgt800">       Weight 800 Text   </li>
    <li class="wgt900">       Weight 900 Text   </li>
    <li class="inherit">      Inherit Text      </li>
    <li class="initial">      Initial Text      </li>
    <li class="unset">        Unset Text        </li>
  </ol>

.. :

  .document > div ol > li{list-style-type: persian;}

----

:id: font-variant-lineh-height-id
:class: t2c

Font Variant, Line Height, and Text Transform
=============================================
.. container::

  .. code:: css
    :number-lines:

    li.normal-variant{font-variant:normal;}
    li.smallcaps-variant{font-variant:smallcaps;}
    li.initial-variant{font-variant:initial;}
    li.inherit-variant{font-variant:inherit;}

    li.lngh-normal{line-height:normal;}
    li.lnhg2{line-height:2;}
    li.lnhg50percent{line-height:50%;}

    li.txtr-none{text-transform:none;}
    li.txtr-capitalize{text-transform:capitalize;}
    li.txtr-uppercase{text-transform:uppercase;}
    li.txtr-lowercase{text-transform:lowercase;}

  .. code:: html

    <ol>
      <li class="normal-variant">Normal Variant Text</li>
      <li class="smallcaps-variant"> Smallcaps vaiant Text       </li>
      <li class="initial-variant">Initial Variant Text      </li>
      <li class="inherit-variant">Inherit Variant Text</li>

      <li class="lngh-normal">Line Height Normal Text</li>
      <li class="lngh2">Line Height 2Text</li>
      <li class="lngh50percent">Line Height 50% Text</li>

      <li class="txtr-none">Text Transform None</li>
      <li class="txtr-capitalize">text transform capitalize</li>
      <li class="txtr-uppercase">Text Transform Uppercase</li>
      <li class="txtr-lowercase">Text Transform Lowercase</li>
    </ol>

.. raw:: html

  <article class="result"><ol>
    <li class="normal-variant">Normal Variant Text</li>
    <li class="smallcaps-variant"> Smallcaps vaiant Text       </li>
    <li class="initial-variant">Initial Variant Text      </li>
    <li class="inherit-variant">Inherit Variant Text</li>

    <li class="lngh-normal">Line Height Normal Text</li>
    <li class="lngh2">Line Height 2Text</li>
    <li class="lngh50percent">Line Height 50% Text</li>

    <li class="txtr-none">Text Transform None</li>
    <li class="txtr-capitalize">Text Transform Capitalize</li>
    <li class="txtr-uppercase">Text Transform Uppercase</li>
    <li class="txtr-lowercase">Text Transform Lowercase</li>
  </article></ol>

.. :

  ----

  :class: t2c

  Font Property / Text Decoration
  ================================
  .. code:: css

    .test{}

  .. raw:: html

    <li></li>

----

Web fonts
============
.. code:: css
  :number-lines:

  @font-face {
    font-family: "myFont";
    src: url("myFont.woff2");
  }

  html {
    font-family: "myFont", "Bitstream Vera Serif", serif;
  }

.. code:: css
  :number-lines:

  @font-face {
    font-family: 'zantrokeregular';
    src: url('fonts/zantroke-webfont.woff2') format('woff2'),
         url('fonts/zantroke-webfont.woff') format('woff');
    font-weight: normal;
    font-style: normal;
  }


#. `Google fonts <https://fonts.google.com/>`_ , `fontsquirrel.com <https://www.fontsquirrel.com/>`_
#. `dafont.com <https://www.dafont.com/>`_ , `everythingfonts.com <https://everythingfonts.com/>`_
#. `fonts.com <https://www.fonts.com/>`_ , `linotype.com <https://www.linotype.com/>`_
#. `myfonts.com <https://www.myfonts.com/>`_ , `monotype.com <https://www.monotype.com/>`_
#. `exljbris.com <https://www.exljbris.com/>`_ , `fonts.google.com <https://fonts.google.com/>`_
#. `Noto <https://fonts.google.com/noto/fonts>`_

.. :

  https://charpa.ir/fonts/Farsi_numerals/English%20to%20Farsi%20numbers%20help.pdf
  https://charpa.ir/fonts/Farsi_numerals/Farsi_numerals.png
  https://charpa.ir/fonts/

  @font-face {
      font-family: 'IranSansWebFaNum';
      src: url('IRANSansWeb(FaNum).woff2') format('woff');
  }

----

Google fonts
==============
.. code:: css
  :number-lines:

  @import url('https://fonts.googleapis.com/css?family=Open+Sans&display=swap');
  @import url('https://fonts.googleapis.com/css?family=Muli&display=swap');
  @import url('https://fonts.googleapis.com/css?family=Quicksand&display=swap');
  body{
    font-family: 'Muli', sans-serif;
    font-weight: 400;
    line-height: 1.58;
    letter-spacing: -.003em;
    font-size: 20px;
    padding: 70px;
  }
  h1{
    font-family: 'Quicksand', sans-serif;
    font-weight: 700;
    font-style: normal;
    font-size: 38px;
    line-height: 1.15;
    letter-spacing: -.02em;
  }

The older solution
---------------------
.. code:: html
  :number-lines:

  <head>
    <link href="https://fonts.googleapis.com/css?family=Dosis&display=swap" rel="stylesheet">
    <style>
      h1{font-family: 'Dosis', sans-serif; color: #777777; text-align: center;}
    </style>
  </head>

.. :

  https://www.w3docs.com/snippets/css/how-to-import-google-fonts-in-css-file.html

  Why You Should STOP Using Google Fonts (And How to Self-Host Your Own Web Fonts)
  https://odysee.com/@ericnmurphy:9/why-you-should-stop-using-google-fonts:f

----

Persian Fonts
==============
#. `myfonts <https://www.myfonts.com/tags/Persian>`_ , `Alfba <https://alefba.us/free-arabic-persian-farsi-urdu-kurdish-fonts/>`_
#. `font store <https://github.com/font-store>`_ , `IranNastaliq <https://github.com/font-store/font-IranNastaliq/tree/master/WebFonts>`_ `Other link <https://github.com/farsi-fonts/iran-nastaliq>`_
#. `Behdad <https://github.com/font-store/BehdadFont/tree/master/dist>`_  , `rastikerdar <https://rastikerdar.github.io/>`_
#. `Wudooh <https://github.com/basshelal/Wudooh/tree/master/src/fonts>`_ , `Font collection(1) <https://github.com/mrlco/persian-web-fonts/tree/master/fonts>`_
#. https://charpa.ir/fonts/
#. `Font collection(2) <https://pixelboy.ir/1320/collection-persian-web-font/>`_ , `Font collection(3-old fonts) <https://github.com/AliMD/1fonts/tree/gh-pages/fonts>`_
#. `Font collection(3) <https://standard-persian-fonts.netlify.app/>`_ , `Arabic google fonts <https://fonts.google.com/?subset=arabic>`_
#. `Lalezar <https://github.com/BornaIz/Lalezar>`_ , `Old farsiweb fonts <https://persian-computing.org/archives/Sharif-FarsiWeb-Inc/Persian_fonts.html>`_
#. `fontiran.com <https://fontiran.com/>`_ , `Yekan <https://github.com/ParsMizban/Yekan-Font>`_

.. code:: css
  :number-lines:

  @font-face { /* Webfont: Yekan */
    font-family: 'Yekan';
    src:url('Yekan.eot'); /* IE9 Compat Modes */
    src:url('Yekan.eot?#iefix') format('embedded-opentype'), /* IE6-IE8 */
        url('Yekan.woff2') format('woff2'), /* Modern Browsers */
        url('Yekan.woff') format('woff'), /* Modern Browsers */
        url('Yekan.otf') format('opentype'), /* Open Type Font */
        url('Yekan.ttf') format('truetype'); /* Safari, Android, iOS */
    font-weight: normal;  font-style: normal;
    text-rendering: optimizeLegibility;  font-display: auto;
  }

.. :

  https://github.com/rastikerdar

----

:id: selector-nth-of-type-id
:class: t2c

Selector() :nth-of-type()/:nth-of-last-type()
==============================================
.. container::

  .. code:: css
    :number-lines:

    /*p:nth-of-type(odd){color:red;}*/
    p:nth-of-type(2n+1){color: red;}
    /*p:nth-of-type(even){color:blue;}*/
    p:nth-of-type(2n){color: blue;}
    p:nth-of-type(1){font-weight: bold;}
    /* :last-of-type */
    p:nth-of-type(-n+2){background-color: lightblue;}
    p:nth-last-of-type(1){font-size:2rem;}
    p.fancy:nth-of-type(2n+1){text-decoration: underline;}


  .. code:: html

    <article class="result">
      <div>This element isn't counted.</div>
      <p>1st paragraph.</p>
      <p class="fancy">2nd paragraph.</p>
      <div>This element isn't counted.</div>
      <p class="fancy">3rd paragraph.</p>
      <p>4th paragraph.</p>
      <p>last of type.</p>
    </article>

.. raw:: html

  <article class="result">
    <div>This element isn't counted.</div>
    <p>1st paragraph.</p>
    <p class="fancy">2nd paragraph.</p>
    <div>This element isn't counted.</div>
    <p class="fancy">3rd paragraph.</p>
    <p>4th paragraph.</p>
    <p>last of type.</p>
  </article>

.. :

  https://www.w3.org/wiki/CSS/Selectors/pseudo-classes/:nth-of-type
  https://developer.mozilla.org/en-US/docs/Web/CSS/:nth-last-of-type
  https://css-tricks.com/almanac/selectors/n/nth-of-type/

  /*This will match the 3rd paragraph as
  * it will match elements which are 2n+1
  * AND have a class of fancy.
  * The second paragraph has a class of
  * fancy but is not matched as it is not
  * :nth-of-type(2n+1) */
  p.fancy:nth-of-type(2n+1)
  {text-decoration: underline;}


----

:id: selector-nth-child-id
:class: t2c

Selector() :nth-child()
==========================
.. container::

  .. code:: css
    :number-lines:

    article{background:lightsteelblue;}
    article :nth-child(even){background:magenta;}
    article .one li:nth-child(-n+3){background:SandyBrown;}
    article .two li:nth-child(1){background:green;}
    article .two .pickme:nth-child(odd){background:Beige;}

  .. code:: html
    :number-lines:

    <article class="result">
      <ol class="one">
        <li>child--41</li>
        <li class="pickme">.pickme1</li>
        <li>child--42</li>
        <li class="pickme">.pickme2</li>
        <li class="pickme">.pickme3</li>
        <li>child--43</li>
      </ol>
      <p>p1</p>
      <p>p2</p>
      <p>p3</p>
      <ol class="two">
        <li>child--44</li>
        <li class="pickme">.pickme6</li>
        <li class="pickme">.pickme7</li>
        <li>child--46</li>
        <li class="pickme">.pickme9</li>
      </ol>
    </article>

.. raw:: html

    <article class="result">
      <ol class="one">
        <li>child--41</li>
        <li class="pickme">.pickme1</li>
        <li>child--42</li>
        <li class="pickme">.pickme2</li>
        <li class="pickme">.pickme3</li>
        <li>child--43</li>
      </ol>
      <p>p1</p>
      <p>p2</p>
      <p>p3</p>
      <ol class="two">
        <li>child--44</li>
        <li class="pickme">.pickme6</li>
        <li class="pickme">.pickme7</li>
        <li>child--46</li>
        <li class="pickme">.pickme9</li>
      </ol>
    </article>

.. :

  https://css-tricks.com/almanac/selectors/n/nth-child/

----

:class: t2c

CSS Selectors pseudo classes
==================================
.. class:: substep

#. `Structural pseudo-classes   <https://www.w3.org/wiki/CSS/Selectors#Structural_pseudo-classes>`_
    #. `:root                   <https://www.w3.org/wiki/CSS/Selectors/pseudo-classes/:root>`_
    #. `:nth-child              <https://www.w3.org/wiki/CSS/Selectors/pseudo-classes/:nth-child>`_
    #. `:nth-last-child         <https://www.w3.org/wiki/CSS/Selectors/pseudo-classes/:nth-last-child>`_
    #. `:nth-of-type            <https://www.w3.org/wiki/CSS/Selectors/pseudo-classes/:nth-of-type>`_
    #. `:nth-last-of-type       <https://www.w3.org/wiki/CSS/Selectors/pseudo-classes/:nth-last-of-type>`_
    #. `:first-child            <https://www.w3.org/wiki/CSS/Selectors/pseudo-classes/:first-child>`_
    #. `:last-child             <https://www.w3.org/wiki/CSS/Selectors/pseudo-classes/:last-child>`_
    #. `:first-of-type          <https://www.w3.org/wiki/CSS/Selectors/pseudo-classes/:first-of-type>`_
    #. `:last-of-type           <https://www.w3.org/wiki/CSS/Selectors/pseudo-classes/:last-of-type>`_
    #. `:only-child             <https://www.w3.org/wiki/CSS/Selectors/pseudo-classes/:only-child>`_
    #. `:only-of-type           <https://www.w3.org/wiki/CSS/Selectors/pseudo-classes/:only-of-type>`_
    #. `:empty                  <https://www.w3.org/wiki/CSS/Selectors/pseudo-classes/:empty>`_
#. `The negation pseudo-classes <https://www.w3.org/wiki/CSS/Selectors#The_negation_pseudo-classes>`_
    #. `:not                    <https://www.w3.org/wiki/CSS/Selectors/pseudo-classes/:not>`_

.. class:: substep

1. `Dynamic pseudo-classes <https://www.w3.org/wiki/CSS/Selectors#Dynamic_pseudo-classes>`_
    #. `:link    <https://www.w3.org/wiki/CSS/Selectors/pseudo-classes/:link>`_
    #. `:visited <https://www.w3.org/wiki/CSS/Selectors/pseudo-classes/:visited>`_
    #. `:hover   <https://www.w3.org/wiki/CSS/Selectors/pseudo-classes/:hover>`_
    #. `:active  <https://www.w3.org/wiki/CSS/Selectors/pseudo-classes/:active>`_
    #. `:focus   <https://www.w3.org/wiki/CSS/Selectors/pseudo-classes/:focus>`_
#. `The target pseudo-classes <https://www.w3.org/wiki/CSS/Selectors#The_target_pseudo-class>`_
    #. `:target <https://www.w3.org/wiki/CSS/Selectors/pseudo-classes/:target>`_
#. `The language pseudo-classes <https://www.w3.org/wiki/CSS/Selectors#The_language_pseudo-class>`_
    #. `:lang <https://www.w3.org/wiki/CSS/Selectors/pseudo-classes/:lang>`_
#. `The UI element states pseudo-classes <https://www.w3.org/wiki/CSS/Selectors#The_UI_element_states_pseudo-classes>`_
    #. `:enabled  <https://www.w3.org/wiki/CSS/Selectors/pseudo-classes/:enabled>`_
    #. `:disabled <https://www.w3.org/wiki/CSS/Selectors/pseudo-classes/:disabled>`_
    #. `:checked  <https://www.w3.org/wiki/CSS/Selectors/pseudo-classes/:checked>`_

.. class:: substep

https://www.w3.org/wiki/CSS/Selectors

.. :

  https://developer.mozilla.org/en-US/docs/Learn/CSS/Building_blocks/Selectors/Pseudo-classes_and_pseudo-elements#what_is_a_pseudo-class
  https://www.webdesignerdepot.com/2016/10/20-essential-css-tricks-every-designer-should-know/
  http://galjot.si/combining-css-selectors

----

:class: t2c

Media(I)
==================
.. code:: css
  :number-lines:

  @media print {
    body { font-size: 10pt; }
  }

  @media screen {
    body { font-size: 13px; }
  }

  @media screen, print {
    body { line-height: 1.2; }
  }

  @media only screen
    and (min-width: 320px)
    and (max-width: 480px)
    and (resolution: 150dpi) {
      body { line-height: 1.4; }
  }

.. code:: css
  :number-lines:

  @media screen and (min-width: 900px) {
    article {
      padding: 1rem 3rem;
    }
  }

  @media only screen and (max-width: 600px) {
    body {
      background-color: lightblue;
    }
  }

  @media screen and (max-width: 600px) {
    div.example {
      display: none;
    }
  }

.. container::

  Media Types

  #. all
  #. print
  #. screen

.. container::

  Logical Operators

  #. and
  #. not
  #. only
  #. ,

----

Media(II)
==================
.. code:: html
  :number-lines:

  <link rel="stylesheet" media="screen" href="screen_style.css" />
  <link rel="stylesheet" media="print" href="print_style.css" />

  <link rel="stylesheet" media="screen and (max-width: 600px)" href="smallscreen.css" />
  <link rel="stylesheet" media="screen and (min-width: 600px)" href="widescreen.css" />

  <style media="all and (max-width: 500px)">
    p {
      background-color: yellow;
      color: blue;
    }
  </style>

  <!-- Served to all users -->
  <link rel="stylesheet" href="all.css" media="all" />
  <!-- Served to screens that are at least 20em wide -->
  <link rel="stylesheet" href="small.css" media="(min-width: 20em)" />
  <!-- Served to screens that are at least 64em wide -->
  <link rel="stylesheet" href="medium.css" media="(min-width: 64em)" />
  <!-- Served to screens that are at least 90em wide -->
  <link rel="stylesheet" href="large.css" media="(min-width: 90em)" />
  <!-- Served to screens that are at least 120em wide -->
  <link rel="stylesheet" href="extra-large.css" media="(min-width: 120em)" />
  <!-- Served to print media, like printers -->
  <link rel="stylesheet" href="print.css" media="print" />

----

Media
========
.. code:: css
  :number-lines:

  @media (height > 600px) {
    body { line-height: 1.4; }
  }

  @media (400px <= width <= 700px) {
    body { line-height: 1.4; }
  }

  /* Nested within another conditional at-rule */
  @supports (display: grid) {
    @media screen and (min-width: 900px) {
      article {
        display: grid;
      }
    }
  }

  @media (min-width: 20em), not all and (min-height: 40em) {
    @media not all and (pointer: none) { ... }
    @media screen and ( (min-width: 50em) and (orientation: landscape) ), print and ( not (color) ) { ... }
  }

.. :

  https://css-tricks.com/a-complete-guide-to-css-media-queries/
  https://drafts.csswg.org/mediaqueries/
  https://css-tricks.com/a-complete-guide-to-css-media-queries/

----

Media features / color
========================
.. code:: css
  :number-lines:

  /* color  */

  p {
    color: black;
  }

  /* Any color device */
  @media (color) {
    p {
      color: red;
    }
  }

  /* Any color device with at least 8 bits per color component */
  @media (min-color: 8) {
    p {
      color: #24ba13;
    }
  }

  /* https://developer.mozilla.org/en-US/docs/Web/CSS/@media/monochrome */

  p {
    display: none;
  }

----

Media features / monochrome
===============================
.. code:: css
  :number-lines:

  /* Any monochrome device */
  @media (monochrome) {
    p.mono {
      display: block;
      color: #333;
    }
  }

  /* Any non-monochrome device */
  @media (monochrome: 0) {
    p.no-mono {
      display: block;
      color: #ee3636;
    }
  }

----

Media features / oreintation
====================================
.. code:: css
  :number-lines:

  /* https://developer.mozilla.org/en-US/docs/Web/CSS/@media/orientation */
  body {
    display: flex;
  }

  div {
    background: yellow;
  }

  @media (orientation: landscape) {
    body {
      flex-direction: row;
    }
  }

  @media (orientation: portrait) {
    body {
      flex-direction: column;
    }
  }

----

Media features / resolution
====================================
.. code:: css
  :number-lines:

  /* https://developer.mozilla.org/en-US/docs/Web/CSS/@media/resolution */
  /* Exact resolution */
  @media (resolution: 150dpi) {
    p {
      color: red;
    }
  }

  /* Minimum resolution */
  @media (min-resolution: 72dpi) {
    p {
      text-decoration: underline;
    }
  }

  /* Maximum resolution */
  @media (max-resolution: 300dpi) {
    p {
      background: yellow;
    }
  }

----

Media features
=====================
.. code:: css
  :number-lines:

  @media (min-width: 30em) and (orientation: landscape) { ... }
  @media screen and (min-width: 30em) and (orientation: landscape) { ... }
  @media (min-height: 680px), screen and (orientation: portrait) { ... }

  @media not all and (monochrome) { ... }
  @media not (all and (monochrome)) { ... }

  @media not screen and (color), print and (color) { ... }
  @media (not (screen and (color))), print and (color) { ... }

  @media (min-width: 30em) and (max-width: 50em) { ... }
  @media (30em <= width <= 50em ) { ... }

  @media (not (color)) or (hover) { ... }


----

import
========
.. code:: css
  :number-lines:

  @import 'custom.css';
  @import url("chrome://communicator/skin/");

  @import url("fineprint.css") print;
  @import url("bluish.css") print, screen;
  @import "common.css" screen;
  @import url('landscape.css') screen and (orientation: landscape);
  @import url("narrow.css") supports(display: flex) screen and (max-width: 400px);


----

:class: t2c

Layer
==========
.. container ::

  .. code:: css
    :number-lines:

    /* utilitis.css */
    @layer utilities {
      .padding-sm {
        padding: .5rem;
      }

      .padding-lg {
        padding: .8rem;
      }
    }

  .. code:: css
    :number-lines:

    /* Another CSS */
    @import 'utilities.css' layer(utilities);

.. code:: css
  :number-lines:

  /*  Nesting Layers */

  @layer framework {
    @layer layout {

    }
  }

  @layer framework.layout {
    p {
      margin-block: 1rem;
    }
  }


.. code:: css
  :number-lines:

  /* Anonymous Layer */

  @layer {
    p {
      margin-block: 1rem;
    }
  }

----

:class: t2c

Layer simple Example
=======================
.. include:: src/css/css3242.html
    :code: html
    :number-lines:

.. raw:: html

  <iframe src="http://127.0.0.1:8002/src/css/css3242.html" title="description" class="output-of-html" height="200">
   </iframe>

----

:class: t2c

Assigning rules to existing layers
=======================================
.. code:: css
  :number-lines:

  @layer base, special;

  @layer special {
    .item {
      color: rebeccapurple;
    }
  }

  @layer base {
    .item {
      color: green;
      border: 5px solid green;
      font-size: 1.3em;
      padding: .5em;
    }
  }

.. :

  https://developer.mozilla.org/en-US/docs/Web/CSS/@layer

----

import
=============
.. code:: css
  :number-lines:

  @import url(headings.css) layer(default);
  @import url(links.css) layer(default);

  @layer default {
    audio[controls] {
      display: block;
    }
  }

  @import url;
  @import url list-of-media-queries;
  @import url supports( supports-query );
  @import url supports( supports-query ) list-of-media-queries;
  @import url layer;
  @import url layer( layer-name );
  @import url layer( layer-name ) list-of-media-queries;
  @import url layer( layer-name ) supports( supports-query ) list-of-media-queries;

----

Variables
===============
.. code:: css
  :number-lines:

  :root{ --background-color-of-header: #2B2E2F;}

  body{
    margin: 0;
    padding: 0;
    background-color:var(--background-color-of-header);
  }

.. code:: css
  :number-lines:

  body {
    --bg-color: white;
    --text-color: black;

    background-color: var(--bg-color);
    color: var(--text-color);
  }

  @media screen and (prefers-color-scheme: dark) {
    body {
      --bg-color: black;
      --text-color: white;
    }
  }

.. :

  https://css-tricks.com/a-complete-guide-to-css-media-queries/

----

Background -
================
.. code:: css
  :number-lines:

  #wrapper {
    width: auto;
    margin: auto;
    text-align: left;
    background-image: url(./img/small-logo.png);
    background-position: left 5px;
    background-repeat: no-repeat;
    min-height: 400px;
  }

.. :

  https://www.smashingmagazine.com/2010/07/how-to-use-css3-media-queries-to-create-a-mobile-version-of-your-website/

  Having created my stylesheet and uploading it I wanted to check how it worked in a real target device. In the iPhone I discovered that the site still loaded zoomed out rather than zooming in on my nice readable single column. A quick search on the Safari developer website gave me my answer - to add a meta tag to the head of the website setting the width of the viewport to the device width.

  <meta name="viewport" content="width=device-width" />
  https://drafts.csswg.org/mediaqueries/#media-types

----

:id: dir-rtl-id

Support CSS
=================================
https://caniuse.com/css-grid

.. image:: img/css_grid_support.png
  :width: 950px

----

CSSdb
=======
What’s next for CSS?
------------------------
cssdb is a comprehensive list of CSS features and their positions in the process of becoming implemented web standards.

https://cssdb.org/

----

CSS Tools
=============
PostCSS
-----------
A tool for transforming CSS with JavaScript

* https://github.com/postcss/postcss
* https://www.postcss.parts/
* https://github.com/postcss/postcss
* https://github.com/postcss/postcss/blob/main/docs/plugins.md

Other Tools
----------------
* `7 ways to deal with CSS <https://odysee.com/@fireship:6/7-ways-to-deal-with-css:3>`_

----

.. include:: src/grid220.html
    :code: html
    :number-lines:

.. raw:: html

   <iframe src="http://127.0.0.1:8002/src/grid220.html" title="description" class="output-of-html" height="200">
   </iframe>

#. https://grid.layoutit.com/
#. https://gridbyexample.com/examples/
#. https://css-tricks.com/snippets/css/complete-guide-grid/
#. https://www.w3schools.com/cssref/pr_grid-template-rows.asp


----

.. include:: src/grid222.html
    :code: html
    :number-lines:

.. raw:: html

   <iframe src="http://127.0.0.1:8002/src/grid222.html" title="description" class="output-of-html">
   </iframe>

----

:id: grid224-id

.. include:: src/grid224.html
    :code: html
    :number-lines:

.. raw:: html

   <iframe src="http://127.0.0.1:8002/src/grid224.html" title="description" class="output-of-html" height="460">
   </iframe>

----

:id: dir-ltr-id

Direction (dir : ltr)
=================================
.. code:: html

  <!DOCTYPE html>
  <html dir="ltr">

.. code:: css

    display: none !important;

----

web browser engine
=====================
webkit
----------
https://webkit.org/
* Safari
* Mail
* App Store
* Apps on macOS, iOS, and Linux.

Blink
-------
* Chrome(28)
* Microsoft Edge(79)
* Opera(15+)
* Vivaldi
* Brave
* Amazon Silk
* Other Chromium-based

chromium
https://www.chromium.org/Home

Gecko
-------
Gecko is a browser engine developed by Mozilla. It is used in the Firefox browser, the Thunderbird email client, and many other projects.

Other
-------
https://en.wikipedia.org/wiki/Browser_engine
https://en.wikipedia.org/wiki/Comparison_of_browser_engines

----

Improve Responsiveness with flex-wrap in CSS
================================================
* https://www.digitalocean.com/community/tutorials/css-improve-responsiveness-flex-wrap
* https://codepen.io/jsarachan/pen/XeaZLR
* https://www.geeksforgeeks.org/advance-css-layout-with-flexbox/
* https://github.com/afonsopacifer/awesome-flexbox

----

More on flexbox
=====================
* https://alligator.io/css/
* https://flexbox.webflow.com/
* https://www.vojtechruzicka.com/css-flexbox/
* https://www.oreilly.com/library/view/flexbox-in-css/9781491981474/ch04.html
* https://cssreference.io/flexbox/
* https://jstutorial.medium.com/the-complete-css-flex-box-tutorial-d17971950bdc

----

Testing Css flexbox
========================
* https://flexbox.help/
* https://www.cssmine.com/ebook/flexbox-examples

----

CSS Only Magic
=================
* https://codepen.io/_fbrz/pen/vlrnd
* https://codepen.io/johnmotyljr/pen/cDpEH
* https://codepen.io/neoberg/details/istyp
* https://codepen.io/_fbrz/pen/whxbF

----

SCSS
========
* https://codepen.io/ste-vg/pen/oKYjKV
* https://codepen.io/davidkpiano/pen/wBGjMr
* https://codepen.io/davidkpiano/pen/aqNZxX

----

Less
=======
* https://codepen.io/ste-vg/pen/oKYjKV

----

Importing the font
======================
.. :

  First, you have to make sure, your site has that font in case the average user who vistits your site doesn't have it.

Option 1 - Import from external provider
----------------------------------------------
.. :

  You can import the whole font file and and settings from an external font host like Google Fonts. Just place this code to your HTML to import it externally:

.. code:: html

  <link rel="stylesheet" type="text/css"
    href="http://fonts.googleapis.com/css?family=Ubuntu:regular,bold&subset=Latin">

Option 2 - Store it in your server
-----------------------------------------
.. :

  You could just download then upload the font files to your server then import them via @font-face in your CSS. In this example the place of your font file will be http://example.com/fonts/ubuntu.woff.

.. code:: css

  @font-face {
    font-family: 'Ubuntu';
    font-style: normal;
    font-weight: 400;
    src: local('Ubuntu'), url(http://example.com/fonts/ubuntu.woff) format('woff');
  }

Using the font

Then you have to specify where do you want to use that font. Just add Ubuntu to your font-family list:

.. code:: css

    body {
        font-family: Ubuntu, "times new roman", times, roman, serif;
    }

This example code will give the Ubuntu Font for every text in your HTML page if it is avilable.

https://stackoverflow.com/a/20818596/886607

https://askubuntu.com/questions/16556/embed-ubuntu-font-on-any-web-page

https://askubuntu.com/questions/16556/embed-ubuntu-font-on-any-web-page/18455#18455

https://developer.mozilla.org/en-US/docs/Web/CSS/font-family

https://www.cssfontstack.com/monospace

----

CSS print
==========

.. code:: css

      @media screen {
         p.bodyText {font-family:verdana, arial, sans-serif;}
      }

      @media print {
         p.bodyText {font-family:georgia, times, serif;}
      }
      @media screen, print {
         p.bodyText {font-size:10pt}
      }

or

.. code:: css
    :class: substep

    @import url(print-style.css) print;

.. ::

  https://www.tutorialspoint.com/css/css_printing.htm
  http://edutechwiki.unige.ch/en/CSS_for_print_tutorial

----


.. code:: html

    <link rel="stylesheet" href="main.css" />
    <link rel="stylesheet" media="print" href="print.css" />

The print.css styles will be applied in addition to screen styles when the page is printed.

.. code:: html

    /* main.css */
    body {
      margin: 2em;
      color: #fff;
      background-color: #000;
    }

    /* override styles when printing */
    @media print {

      body {
        margin: 0;
        color: #000;
        background-color: #fff;
      }

    }

----


.. code:: html

    <!--These styles styles are only for screens as set by the media value-->
    <link rel="stylesheet" href="css/main.css" media="screen">

    <!--These styles styles are only for print as set by the media value-->
    <link rel="stylesheet" href="css/print.css" media="print">

.. ::

    https://stackoverflow.com/a/12773239

.. code:: css

    /* main.css */

    /* on-screen styles */
    @media screen {

      body {
        margin: 2em;
        color: #fff;
        background-color: #000;
      }

    }

    /* print styles */
    @media print {

      body {
        margin: 0;
        color: #000;
        background-color: #fff;
      }

    }

.. ::

    https://www.sitepoint.com/css-printer-friendly-pages/

----

Remove Unnecessary Sections
=============================
A4 or letter

.. code:: css

    /* print.css */
    header, footer, aside, nav, form, iframe, .menu, .hero, .adslot {
      display: none;
    }

.. code:: css

    display: none !important;

Printer Styling
------------------
.. class:: substep

    * ensure you use dark text on a white background
    * consider using a serif font, which may be easier to read
    * adjust the text size to 12pt or higher
    * modify paddings and margins where necessary. Standard cm, mm, or in units may be more practical.
    * Use Borders Instead of Background Colors


----

Remove or Invert Images
==============================================
.. code:: css

    /* print.css */
    * {
      background-image: none !important;
    }

    img, svg {
      display: none !important;
    }

    img.print, svg.print {
      display: block;
      max-width: 100%;
    }

----

Add Supplementary Content(I)
=============================
* ::before
* ::after

.. code:: css

    /* print.css */
    a::after {
      content: " (" attr(href) ")";
    }

.. code:: css

    /* print.css */
    main::after {
      content: "Copyright site.com";
      display: block;
      text-align: center;
    }

----

Add Supplementary Content(II)
==============================
.. code:: html

    <p class="print">
      Article printed at 1:23pm 5 September 2020.
      Please see https://site.com/page for the latest version.
    </p>

.. code::css

    /* hidden on-screen */
    .print {
      display: none;
    }

    @media print {

      /* visible when printed */
      .print {
        display: block;
      }

    }

----

Hyperlinks
==============
.. code:: css

    @media print {
      a {
        text-decoration: underline;
      }
    }

.. code:: css
    :class: substep

    a:after {
       content: " (" attr(href) ") ";
       font-size: 80%;
    }

----

.. code:: css
    :class: substep

    #page-content a[href^="http"]:after {
      content: " (" attr(href) ")";
      font-size: 80%;
    }

.. code:: css
    :class: substep

    a[href^="http://"]:after, a[href^="ftp://"]:after {
      content: " (" attr(href) ")";
      color: blue;
      font-size: small;
    }

----

@Page Rule
=============
.. code:: css

    /* Default left, right, top, bottom margin is 2cm */
    @page { margin: 2cm }

    /* First page, 10 cm margin on top */
    @page :first {
      margin-top: 10cm;
    }

    /* Left pages, a wider margin on the left */
    @page :left {
      margin-left: 3cm;
      margin-right: 2cm;
    }

    @page :right {
      margin-left: 2cm;
      margin-right: 3cm;
    }

    @page :blank {
      @top-center { content: "This page is intentionally left blank" }
    }

.. ::

    https://www.w3.org/TR/css-page-3/#page-size

----

Page Margin Boxes
======================
.. code:: css

    @page {
      @top-center {
        content: "Vojtech Ruzicka's Programming Blog";
      }
      @top-right-corner {
        content: url(logo.png);
      }
      @bottom-right {
        content: "Page " counter(page)
      }
    }

----

.. code:: css

    @page {
      @top-center {
        content: "Vojtech Ruzicka's Programming Blog";
        font-family: sans-serif;
        font-weight: bold;
        font-size: 2em;
      }
    }

----

Chapter Number
==================
.. code:: css

    body {counter-reset: chapter;}
    div.chapter {counter-increment: chapter;}
    @page {
      margin: 10%;
      @top-center { content: "Chapter" counter(chapter) }
    }


----

Page size
============
.. code:: css
    :class: substep

    @page {
    size: A4 landscape;
    }

.. code:: css
    :class: substep

    /* style sheet for "A4" printing */
    @media print and (width: 21cm) and (height: 29.7cm) {
      @page {
         margin: 3cm;
      }
     }

    /* style sheet for "letter" printing */
    @media print and (width: 8.5in) and (height: 11in) {
      @page {
      margin: 1in;
      }
    }

.. ::

    https://www.w3.org/TR/css-page-3/#page-size

----

Page Breaks
============
* break-before
* break-after

Values
--------
*   auto: the default — a break is permitted but not forced
*   avoid: avoid a break on the page, column or region
*   avoid-page: avoid a page break
*   page: force a page break
*   always: an alias of page
*   left: force page breaks so the next is a left page
*   right: force page breaks so the next is a right page

.. code::css

    /* print.css */
    h1 {
      break-before: always;
    }


----

.. code:: css

    /* print.css */
    table, img, svg {
      break-inside: avoid;
    }

    pre {
      break-inside: avoid-page;
    }

    h1, h2, h3 {
      break-after: avoid-page;
    }

    h2 {
      break-before: page;
    }

----

The widows property specifies the minimum number of lines in a block that must be shown at the top of a page. Imagine a block with five lines of text. The browser wants to make a page break after line four so the last line appears at the top of the next page. Setting widows: 3; breaks on or before line two so at least three lines carry over to the next page.

The orphans property is similar to widows except it controls the minimum number of lines to show at the bottom of a page.

The box-decoration-break property controls element borders across pages. When an element with a border has an inner page break:

* slice: the default, splits the layout. The top border is shown on the first page and the bottom border is shown on the second page.
* clone: replicates the margin, padding, and border. All four borders are shown on both pages.

----

Paragraph splitting
=========================
Orphans: When a paragraph gets split over two pages, orphans property defines how many lines at a minimum should be kept on the first page.

.. code:: css

    p {
      orphans: 4;
    }

Widows:
This is very similar to orphans. It is the minimal number of lines, which should be on the second page when a paragraph is split on two pages.

.. code:: css

    p {
      widows: 5;
    }

----

@page
=======
.. code:: css

    /* print.css */
    /* target all pages */
    @page {
      margin: 2cm;
    }

    /* target the first page only */
    @page :first {
      margin-top: 6cm;
    }

    /* target left (even-numbered) pages only */
    @page :left {
      margin-right: 4cm;
    }

    /* target right (odd-numbered) pages only */
    @page :right {
      margin-left: 4cm;
    }

----

Be aware that page break control is little more than a suggestion to the browser. There’s no guarantee a break will be forced or avoided because layout is restricted to the confines of the paper.

----

Another sample
===============
.. code:: css

    body {
      font-family: Georgia, serif;
      background: none;
      color: black;
    }
    #page {
      width: 100%;
      margin: 0; padding: 0;
      background: none;
    }
    #header, #menu-bar, #sidebar, h2#postcomment, form#commentform, #footer {
      display: none;
    }
    .entry a:after {
      content: " [" attr(href) "] ";
    }
    #printed-article {
      border: 1px solid #666;
      padding: 10px;
    }

----

CSS3 Multiple columns
============================
.. code:: css

    body {
         column-count: 2;
         column-gap: 2em;
         column-rule: thin solid black;
     }

    /* This would create an h1 title that spans across the page */
    h1 {
      column-span: all
      break-before: column;
      break-inside: avoid-column;
      break-after: avoid-column;
    }

.. ::

    http://edutechwiki.unige.ch/en/CSS_for_print_tutorial

----

.. code:: html

    <link rel="stylesheet" href="just-so-stories.css" type="text/css">
    <link rel="stylesheet" href="just-so-stories-print.css" type="text/css" media="print">
    .........
    <p class="noprint"><a href="#copyright">Copyright information</a></p>
    .........
    <h2 class="noprint">Copyright Information</h2>


.. code:: css

    h1, h2 {
        page-break-after: avoid;
        page-break-before: always;
    }

    p {
          orphans:3;
          widows:3;
    }

    .noprint, pre.copyright {
         display:none;
     }

.. ::

    http://edutechwiki.unige.ch/en/CSS_for_print_tutorial

----

Printing Pains
===============
* printer-friendly style sheets can be retro-fitted to any site
* most printer styling will work in the majority of browsers
* print styles will not affect or break existing functionality
* the development costs are minimal.

.. class:: substep

  1. Make the type as readable as possible
  2. Use as much of the page as possible
  3. Default styling ain’t bad for print
  4. Remove the extra stuff (Removing unnecessary content)
  5. Display the URLs in the body content
  6. Include a thank-you note
  7. Optional: Page breaks

----

References
==============
#. https://developer.mozilla.org
#. https://drafts.csswg.org
#. https://www.freecodecamp.org
#. https://www.w3.org/TR/
#. https://css-tricks.com
#. https://developers.google.com/web
#. https://www.w3schools.com
#. https://www.khanacademy.org/computing/computer-programming


.. ::

  img/css/webbrowser_css_rendering.svg
  https://developer.mozilla.org/en-US/docs/Learn/CSS/First_steps/How_CSS_works

  https://learncssgrid.com
  https://developer.mozilla.org/en-US/docs/Web/CSS/CSS_Grid_Layout/Basic_Concepts_of_Grid_Layout
  https://developer.mozilla.org/en-US/docs/Web/CSS/CSS_Grid_Layout
  https://css-tricks.com/snippets/css/complete-guide-grid/
  https://www.freecodecamp.org/learn/responsive-web-design/css-grid/
  https://www.cssgrid.cc/css-grid-guide.html
  https://gridbyexample.com/examples/
  https://www.w3.org/TR/css-grid-1/
  https://developer.mozilla.org/en-US/docs/Web/CSS/CSS_Grid_Layout/Box_Alignment_in_CSS_Grid_Layout
  https://developer.mozilla.org/en-US/docs/Learn/CSS/CSS_layout/Grids
  https://css-tricks.com/dont-overthink-flexbox-grids/
  https://scotch.io/tutorials/a-visual-guide-to-css3-flexbox-properties
  https://responsivedesign.is/articles/creating-the-periodic-table-with-grid-css/
  https://developer.mozilla.org/en-US/docs/Web/CSS/CSS_Grid_Layout/Basic_Concepts_of_Grid_Layout
  https://www.w3schools.com/css/css_templates.asp
  https://cssgrid-generator.netlify.app/
  https://css-tricks.com/snippets/css/complete-guide-grid/
  https://twitter.com/bdc/
  https://developers.google.com/web
  https://developer.mozilla.org/en-US/docs/Learn
  https://www.khanacademy.org/computing/computer-programming

  https://www.w3schools.com/css/css_grid.asp
  https://www.w3schools.com/css/css_grid_container.asp
  https://www.w3schools.com/css/css_grid_item.asp
  https://www.w3schools.com/css/css_templates.asp

  https://learncssgrid.com/
  https://webflow.com/blog/web-design-courses
  https://ebooks.webflow.com/

  https://css-tricks.com/snippets/css/complete-guide-grid/
  https://developer.mozilla.org/en-US/docs/Web/CSS/CSS_Grid_Layout/Box_Alignment_in_CSS_Grid_Layout


  2022/05/05 23:19:54
  -------------------------
  https://www.w3schools.com/css/
  https://www.w3schools.com/cssref/css_ref_aural.asp

  CSS media
  https://www.w3schools.com/cssref/css3_pr_mediaquery.asp
  https://www.w3schools.com/css/css_rwd_mediaqueries.asp
  https://www.w3schools.com/css/css3_mediaqueries_ex.asp
  https://drafts.csswg.org/mediaqueries/
  https://www.quirksmode.org/mobile/viewports.html
  https://developer.mozilla.org/en-US/docs/Glossary/Layout_viewport
  https://w3c.github.io/manifest/#the-display-mode-media-feature
  https://www.w3docs.com/learn-css/media.html
  https://css-tricks.com/a-complete-guide-to-css-media-queries/
  https://www.w3schools.com/cssref/css_ref_aural.asp
  https://www.w3.org/TR/css-speech-1/#aural-box-model
  https://www.w3schools.com/cssref/default.asp


  http://sd.blackball.lv/library/CSS3_Foundations_2013.pdf
  https://www.wiley.com/en-us/CSS3+Foundations-p-9781118356548
  https://github.com/IanLunn?tab=repositories
  https://ianlunn.co.uk/portfolio/css3-foundations
