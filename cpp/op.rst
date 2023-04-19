:data-transition-duration: 1000
:skip-help: true
:css: ./style.css ./cpp.css
:substep: true
:slide-numbers: true
:skip-help: true

.. title: Advanced Programming (C++)

.. role:: raw-html(raw)
   :format: html

Advanced Programming (C++)
==============================
Operator Overloading
-----------------------------
Ahmad Yoosofan

University of Kashan

http://yoosofan.github.io/course/cpp.html

----

:class: t2c

ComplexCls(I)
=====================
.. include:: src/mycomplex/100580_copy_constructor.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 2
    :end-line: 30

.. include:: src/mycomplex/100580_copy_constructor.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 30
    :end-line: 67

----

:class: t2c

ComplexCls(II)
=====================
.. include:: src/op/1022.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 2
    :end-line: 29

.. include:: src/op/1022.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 29
    :end-line: 67


----

:class: t2c

ComplexCls(III)
=====================
.. include:: src/op/1024.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 2
    :end-line: 29

.. include:: src/op/1024.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 29
    :end-line: 67


----

:class: t2c

ComplexCls(IV) / Operator +
===============================
.. include:: src/op/1026.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 0
    :end-line: 29

.. container::

  .. include:: src/op/1026.cpp
      :code: cpp
      :number-lines: 29
      :class: ltr
      :start-line: 29
      :end-line: 67

  .. code:: console
  
    4+ i 4
    4+ i 4
    4+ i 4
    8+ i 8
    12+ i 12

----

:class: t2c

ComplexCls(V) / Operator +
===============================
.. include:: src/op/1036.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 0
    :end-line: 22

.. include:: src/op/1036.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 22
    :end-line: 67

----

:class: t2c

ComplexCls(VI) / Operator + (Error)
=========================================
.. include:: src/op/1046.cpp
    :code: cpp
    :number-lines: 4
    :class: ltr
    :start-line: 3
    :end-line: 30

.. container::

  .. include:: src/op/1046.cpp
      :code: cpp
      :number-lines: 31
      :class: ltr
      :start-line: 30
      :end-line: 67

  .. code:: console
  
    In function ‘void f1()’:
    1046.cpp:33:9: error: no match for ‘operator+’
     (operand types are ‘complexCls’ and ‘int’)
       33 |   c = a + 2;
          |       ~ ^ ~
          |       |   |
          |       |   int
          |       complexCls
    1046.cpp:17:14: note: candidate:
     ‘complexCls complexCls::operator+(c

-----

:class: t2c

ComplexCls(VII) / Operator + 
=========================================
.. include:: src/op/1056.cpp
    :code: cpp
    :number-lines: 4
    :class: ltr
    :start-line: 3
    :end-line: 28

.. container::

  .. include:: src/op/1056.cpp
      :code: cpp
      :number-lines: 32
      :class: ltr
      :start-line: 28
      :end-line: 67

  .. code:: console

    g++ src/op/1056.cpp 
    slide$ ./a.out
    4+ i 3
    4+ i 4
 
-----

:class: t2c

ComplexCls(VIII) / Operator + - *
=========================================
.. include:: src/op/1066.cpp
    :code: cpp
    :number-lines: 4
    :class: ltr
    :start-line: 3
    :end-line: 28

.. include:: src/op/1066.cpp
    :code: cpp
    :number-lines: 32
    :class: ltr
    :start-line: 28
    :end-line: 67

-----

:class: t2c

ComplexCls(VIII) / Operator + - * =
==================================================
.. include:: src/op/1076.cpp
    :code: cpp
    :number-lines: 4
    :class: ltr
    :start-line: 3
    :end-line: 28

.. include:: src/op/1076.cpp
    :code: cpp
    :number-lines: 32
    :class: ltr
    :start-line: 28
    :end-line: 67


-----

:class: t2c

ComplexCls(VIII) / Operator + - * = []
==================================================
.. include:: src/op/1086.cpp
    :code: cpp
    :number-lines: 4
    :class: ltr
    :start-line: 3
    :end-line: 30

.. include:: src/op/1086.cpp
    :code: cpp
    :number-lines: 30
    :class: ltr
    :start-line: 30
    :end-line: 67

-----

:class: t2c

ComplexCls(VIII) / Operator + - * = []
==================================================
.. include:: src/op/1088.cpp
    :code: cpp
    :number-lines: 4
    :class: ltr
    :start-line: 3
    :end-line: 29

.. include:: src/op/1088.cpp
    :code: cpp
    :number-lines: 29
    :class: ltr
    :start-line: 29
    :end-line: 67


-----

:class: t2c

ComplexCls(VIII) / Operator + - * =
==================================================
.. include:: src/op/1090.cpp
    :code: cpp
    :number-lines: 4
    :class: ltr
    :start-line: 3
    :end-line: 34

.. include:: src/op/1090.cpp
    :code: cpp
    :number-lines: 34
    :class: ltr
    :start-line: 34
    :end-line: 67

-----

:class: t2c

ComplexCls(IX) / friend 
==================================================
.. include:: src/op/1091.cpp
    :code: cpp
    :number-lines: 4
    :class: ltr
    :start-line: 3
    :end-line: 34

.. include:: src/op/1091.cpp
    :code: cpp
    :number-lines: 34
    :class: ltr
    :start-line: 34
    :end-line: 67


-----

:class: t2c

ComplexCls(X) / Operator ==  != !
==================================================
.. include:: src/op/1100.cpp
    :code: cpp
    :number-lines: 4
    :class: ltr
    :start-line: 3
    :end-line: 37

.. include:: src/op/1100.cpp
    :code: cpp
    :number-lines: 37
    :class: ltr
    :start-line: 37
    :end-line: 78

-----

:class: t2c

ComplexCls(VIII) / Operator ++ --
==================================================
.. include:: src/op/1110.cpp
    :code: cpp
    :number-lines: 30
    :class: ltr
    :start-line: 30
    :end-line: 57

.. include:: src/op/1110.cpp
    :code: cpp
    :number-lines: 57
    :class: ltr
    :start-line: 57
    :end-line: 89


-----

:class: t2c

ComplexCls(VIII) / Operator ++ --
==================================================
.. include:: src/op/1130.cpp
    :code: cpp
    :number-lines: 30
    :class: ltr
    :start-line: 30
    :end-line: 57

.. include:: src/op/1130.cpp
    :code: cpp
    :number-lines: 57
    :class: ltr
    :start-line: 57
    :end-line: 89


---

END

