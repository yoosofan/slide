========================
کامپایلر، ماشین حساب
========================


احمد یوسفان 

دانشگاه کاشان

تحلیل‌گر نحوی Lexical Analyser , parser
======================================================
برای تحلیلی نحوی باید قاعده‌های زبان را رعایت کنیم

نخست باید دستور زبان را بنویسیم

برای نوشتن دستور زبان باید قاعده‌ای را به کار ببریم

دستور زبان پیشنهادی

.. class:: ltr

  E
  
.. include:: src/rd/calculator/cpp/simple.calc.wrong.grammar.cpp  
  :code: cpp
  :number-lines:

https://en.wikipedia.org/wiki/Recursive_descent_parser

http://math.hws.edu/javanotes/c9/s5.html

https://gist.github.com/DmitrySoshnikov/e2c3a793636dc03f2200

https://www.engr.mun.ca/~theo/Misc/exp_parsing.htm



نمودار ماشین حساب
======================================================

.. class:: ltr

   .. image:: img/recursive.descendant.method/calculator/calculator.svg
      :height: 20em
      :width:  20em
      :align:  center

-----------------------------------------------------------------------------------

برنامه ماشین حساب 01
======================================================

.. include:: src/rd/calculator/python/sc01.py
   :code: python
   :number-lines:

-----------------------------------------------------------------------------------

برنامه ماشین حساب ۰۲
======================================================

.. include:: src/rd/calculator/python/sc02.py
   :code: python
   :number-lines:

-----------------------------------------------------------------------------------

برنامه ماشین حساب ۱
======================================================

.. include:: src/rd/calculator/python/simple_calculator_1.py
   :code: python
   :number-lines:

برنامه ماشین حساب ۱.۱
======================================================
.. include:: src/rd/calculator/python/sc04.py
   :code: python
   :number-lines:

-----------------------------------------------------------------------------------

برنامه ماشین حساب ۲
======================================================
.. include:: src/rd/calculator/python/simple_calculator_2.py
   :code: python
   :number-lines:

-----------------------------------------------------------------------------------

برنامه ماشین حساب ۳
======================================================
.. include:: src/rd/calculator/python/simple_calculator.3.py
   :code: python
   :number-lines:

-----------------------------------------------------------------------------------

برنامه ماشین حساب ۱ زبان C 
======================================================
.. include:: src/rd/calculator/cpp/simple_calculator_1.cpp
   :code: cpp
   :number-lines:


-----------------------------------------------------------------------------------


برنامه ماشین حساب ۲ زبان C 
======================================================
.. include:: src/rd/calculator/cpp/simple_calculator_2.cpp
   :code: cpp
   :number-lines:

-----------------------------------------------------------------------------------

.. contents::  فهرست مطالب


.. comment:

  rst2s5.py calculator_recursive_descendant.rst calculator_recursive_descendant.html -d -t --section-numbering --stylesheet=farsi.css,html4css1.css 
  rst2html.py calculator_recursive_descendant.rst 22calculator_recursive_descendant.html --stylesheet=../../tools/farsi.css,html4css1.css 
