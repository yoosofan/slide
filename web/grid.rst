:data-transition-duration: 1000
:skip-help: true
:css: assets/hovercraft.css assets/css.css grid.css
:substep: true

.. title: css layout grid (By Ahmad Yoosofan)

:slide-numbers: true

.. role:: ltr
    :class: ltr

.. role:: rtl
    :class: rtl

CSS Grid
==========================
Ahmad Yoosofan

http://yoosofan.github.io/

Search "Ahmad Yoosofan"

----

:class: t2c

Grid Container - display grid
=================================
.. include:: src/grid/grid220.html
    :code: html
    :number-lines:
    :start-line: 7
    :end-line: 14

.. include:: src/grid/grid220.css
    :code: html
    :number-lines:

.. raw:: html

   <iframe src="http://127.0.0.1:8002/src/grid/grid220.html" title="description" class="output-of-html">
   </iframe>

----

:class: t2c

Grid Container - display inline-grid
=====================================
.. include:: src/grid/grid230.html
    :code: html
    :number-lines:
    :start-line: 7
    :end-line: 14

.. include:: src/grid/grid230.css
    :code: html
    :number-lines:

.. raw:: html

   <iframe src="http://127.0.0.1:8002/src/grid/grid230.html" title="description" class="output-of-html">
   </iframe>

----


:class: t2c

Grid container
===============
.. container::

  .. code:: css

    .grid-container{
      display: grid;
      grid-template-columns: auto auto auto auto;
      grid-gap: 10px;
      background-color: #2196F3;
      padding: 10px;
    }

  .. code:: html

    <div class="grid-container">
      <div>1</div>
      <div>2</div>
      <div>3</div>  
      <div>4</div>
      <div>5</div>
      <div>6</div>  
      <div>7</div>
      <div>8</div>
    </div>

.. raw:: html

  <div class="grid-container">
    <div>1</div>
    <div>2</div>
    <div>3</div>  
    <div>4</div>
    <div>5</div>
    <div>6</div>  
    <div>7</div>
    <div>8</div>
  </div>



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
  file:///media/ahmad/yoosofan/yoosofanFiles/yoosofan/course/webd/css.rst
  file:///media/ahmad/yoosofan/yoosofanFiles/yoosofan/course/webd/assets/grid.css
  view-source:file:///media/ahmad/yoosofan/yoosofanFiles/yoosofan/course/webd/src/grid224.html
  http://127.0.0.1:8006/#/ps-desc-i-id
  file:///media/ahmad/yoosofan/yoosofanFiles/yoosofan/course/os/slide/ps.rst
  file:///media/ahmad/yoosofan/yoosofanFiles/yoosofan/course/os/slide/ps.css
  
  https://developer.mozilla.org/en-US/docs/Web/CSS/align-self
  https://developer.mozilla.org/en-US/docs/Web/CSS/CSS_Grid_Layout/Box_Alignment_in_CSS_Grid_Layout

  https://www.w3.org/TR/css-grid-1/
  https://developer.mozilla.org/en-US/docs/Web/CSS/CSS_Grid_Layout/Box_Alignment_in_CSS_Grid_Layout
  https://developer.mozilla.org/en-US/docs/Learn/CSS/CSS_layout/Grids
  https://css-tricks.com/dont-overthink-flexbox-grids/
  https://scotch.io/tutorials/a-visual-guide-to-css3-flexbox-properties
  https://responsivedesign.is/articles/creating-the-periodic-table-with-grid-css/
  https://developer.mozilla.org/en-US/docs/Web/CSS/CSS_Grid_Layout/Basic_Concepts_of_Grid_Layout
  https://www.cssgrid.cc/css-grid-guide.html
  https://www.freecodecamp.org/learn/responsive-web-design/css-grid/
  https://www.w3schools.com/css/css_templates.asp
  https://cssgrid-generator.netlify.app/
  https://css-tricks.com/snippets/css/complete-guide-grid/
  https://twitter.com/bdc/
  https://cssgrid-generator.netlify.app/
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



