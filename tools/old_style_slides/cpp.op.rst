.. role:: raw-html(raw)
   :format: html

.. prezento:: Advanced Programming (C++)
   :skip-help: true
   :css: ./assets/style.css
   :substep: true
   :slide-numbers: true
   :skip-help: true
   :data-width: 1024
   :data-height: 768

.. slido:: Advanced Programming (C++)

    Operator Overloading

.. slido::

    Ahmad Yoosofan

    University of Kashan

    http://yoosofan.github.io/course/cpp.html

.. slido:: ComplexCls(I)
   :class: t2c

    .. include:: cpp/src/mycomplex/100580_copy_constructor.cpp
        :code: cpp
        :number-lines:
        :class: ltr
        :start-line: 2
        :end-line: 30

    .. include:: cpp/src/mycomplex/100580_copy_constructor.cpp
        :code: cpp
        :number-lines:
        :class: ltr
        :start-line: 30
        :end-line: 67

.. slido:: ComplexCls(II)
   :class: t2c

    .. include:: cpp/src/op/1022.cpp
        :code: cpp
        :number-lines:
        :class: ltr
        :start-line: 2
        :end-line: 29

    .. include:: cpp/src/op/1022.cpp
        :code: cpp
        :number-lines:
        :class: ltr
        :start-line: 29
        :end-line: 67

.. slido:: ComplexCls(III)
   :class: t2c

    .. include:: cpp/src/op/1024.cpp
        :code: cpp
        :number-lines:
        :class: ltr
        :start-line: 2
        :end-line: 29

    .. include:: cpp/src/op/1024.cpp
        :code: cpp
        :number-lines:
        :class: ltr
        :start-line: 29
        :end-line: 67

.. slido:: ComplexCls(IV) / Operator +
   :class: t2c

    .. include:: cpp/src/op/1026.cpp
        :code: cpp
        :number-lines:
        :class: ltr
        :start-line: 3
        :end-line: 29

    .. container::

      .. include:: cpp/src/op/1026.cpp
          :code: cpp
          :number-lines: 27
          :class: ltr
          :start-line: 29
          :end-line: 67

      .. code:: console

        4+ i 4
        4+ i 4
        4+ i 4
        8+ i 8
        12+ i 12

.. slido:: ComplexCls(V) / Operator +
   :class: t2c

    .. include:: cpp/src/op/1036.cpp
        :code: cpp
        :number-lines:
        :class: ltr
        :start-line: 3
        :end-line: 22

    .. include:: cpp/src/op/1036.cpp
        :code: cpp
        :number-lines: 20
        :class: ltr
        :start-line: 22
        :end-line: 67

.. slido:: ComplexCls(VI) / Operator + (Error)
   :class: t2c

    .. include:: cpp/src/op/1046.cpp
        :code: cpp
        :number-lines: 4
        :class: ltr
        :start-line: 3
        :end-line: 30

    .. container::

      .. include:: cpp/src/op/1046.cpp
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

.. slido:: ComplexCls(VII) / Operator +
   :class: t2c

    .. include:: cpp/src/op/1056.cpp
        :code: cpp
        :number-lines: 4
        :class: ltr
        :start-line: 3
        :end-line: 28

    .. container::

      .. include:: cpp/src/op/1056.cpp
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

.. slido:: ComplexCls(VIII) / Operator + - *
   :class: t2c

    .. include:: cpp/src/op/1066.cpp
        :code: cpp
        :number-lines: 4
        :class: ltr
        :start-line: 3
        :end-line: 28

    .. include:: cpp/src/op/1066.cpp
        :code: cpp
        :number-lines: 32
        :class: ltr
        :start-line: 28
        :end-line: 67

.. slido:: ComplexCls(VIII) / Operator + - * =
   :class: t2c

    .. include:: cpp/src/op/1076.cpp
        :code: cpp
        :number-lines: 4
        :class: ltr
        :start-line: 3
        :end-line: 28

    .. include:: cpp/src/op/1076.cpp
        :code: cpp
        :number-lines: 26
        :class: ltr
        :start-line: 28
        :end-line: 67

.. slido:: ComplexCls(VIII) / Operator + - * = []
   :class: t2c

    .. :


    .. include:: cpp/src/op/1086.cpp
        :code: cpp
        :number-lines: 4
        :class: ltr
        :start-line: 3
        :end-line: 32

    .. include:: cpp/src/op/1086.cpp
        :code: cpp
        :number-lines: 30
        :class: ltr
        :start-line: 33
        :end-line: 67

.. slido:: ComplexCls(VIII) / Operator + - * = []
   :class: t2c

    .. :


    .. include:: cpp/src/op/1088.cpp
        :code: cpp
        :number-lines: 4
        :class: ltr
        :start-line: 3
        :end-line: 29

    .. include:: cpp/src/op/1088.cpp
        :code: cpp
        :number-lines: 29
        :class: ltr
        :start-line: 29
        :end-line: 67

.. slido:: ComplexCls(VIII) / Operator + - * =
   :class: t2c

    .. :


    .. include:: cpp/src/op/1090.cpp
        :code: cpp
        :number-lines: 4
        :class: ltr
        :start-line: 3
        :end-line: 34

    .. include:: cpp/src/op/1090.cpp
        :code: cpp
        :number-lines: 34
        :class: ltr
        :start-line: 34
        :end-line: 67

.. slido:: c = complexCls(2) + a
   :class: t2c

    .. include:: cpp/src/op/1095.cpp
        :code: cpp
        :number-lines: 4
        :class: ltr
        :start-line: 3
        :end-line: 26

    .. include:: cpp/src/op/1095.cpp
        :code: cpp
        :number-lines: 29
        :class: ltr
        :start-line: 26
        :end-line: 65

.. slido:: ComplexCls(IX) / friend
   :class: t2c

    .. :


    .. include:: cpp/src/op/1091.cpp
        :code: cpp
        :number-lines: 4
        :class: ltr
        :start-line: 3
        :end-line: 34

    .. include:: cpp/src/op/1091.cpp
        :code: cpp
        :number-lines: 34
        :class: ltr
        :start-line: 34
        :end-line: 67

.. slido:: ComplexCls(X) / Operator ==  != !
   :class: t2c

    .. :


    .. include:: cpp/src/op/1100.cpp
        :code: cpp
        :number-lines: 4
        :class: ltr
        :start-line: 3
        :end-line: 37

    .. include:: cpp/src/op/1100.cpp
        :code: cpp
        :number-lines: 35
        :class: ltr
        :start-line: 37
        :end-line: 78

.. slido:: ComplexCls(VIII) / Operator ++ --
   :class: t2c

    .. include:: cpp/src/op/1110.cpp
        :code: cpp
        :number-lines: 30
        :class: ltr
        :start-line: 30
        :end-line: 57

    .. include:: cpp/src/op/1110.cpp
        :code: cpp
        :number-lines: 57
        :class: ltr
        :start-line: 57
        :end-line: 89

.. slido:: ComplexCls(VIII) / << >>
   :class: t2c

    .. include:: cpp/src/op/1130.cpp
        :code: cpp
        :number-lines: 4
        :class: ltr
        :start-line: 4
        :end-line: 18

    .. include:: cpp/src/op/1130.cpp
        :code: cpp
        :number-lines: 57
        :class: ltr
        :start-line: 57
        :end-line: 74

.. slido:: ComplexCls(VIII) /  ( )
   :class: t2c

    .. include:: cpp/src/op/1140.cpp
        :code: cpp
        :number-lines: 30
        :class: ltr
        :start-line: 30
        :end-line: 57

    .. include:: cpp/src/op/1140.cpp
        :code: cpp
        :number-lines: 57
        :class: ltr
        :start-line: 57
        :end-line: 89

.. slido:: ComplexCls(VIII) /
   :class: t2c

    .. include:: cpp/src/op/1150.cpp
        :code: cpp
        :number-lines: 30
        :class: ltr
        :start-line: 30
        :end-line: 57

    .. include:: cpp/src/op/1150.cpp
        :code: cpp
        :number-lines: 57
        :class: ltr
        :start-line: 57
        :end-line: 89

.. slido:: MyArray /  =
   :class: t2c

    .. include:: cpp/src/op/1240.cpp
        :code: cpp
        :number-lines: 0
        :class: ltr
        :start-line: 0
        :end-line: 25

    .. include:: cpp/src/op/1240.cpp
        :code: cpp
        :number-lines: 25
        :class: ltr
        :start-line: 25
        :end-line: 89

.. slido:: MyArray /  = Error
   :class: t2c

    .. include:: cpp/src/op/1250.cpp
        :code: cpp
        :number-lines: 0
        :class: ltr
        :start-line: 0
        :end-line: 25

    .. include:: cpp/src/op/1250.cpp
        :code: cpp
        :number-lines: 25
        :class: ltr
        :start-line: 25
        :end-line: 89

.. slido:: MyArray /  =
   :class: t2c

    .. include:: cpp/src/op/1260.cpp
        :code: cpp
        :number-lines: 30
        :class: ltr
        :start-line: 3
        :end-line: 30

    .. include:: cpp/src/op/1260.cpp
        :code: cpp
        :number-lines: 32
        :class: ltr
        :start-line: 30
        :end-line: 89

.. slido:: MyArray /  =
   :class: t2c

    .. include:: cpp/src/op/1270.cpp
        :code: cpp
        :number-lines: 3
        :class: ltr
        :start-line: 3
        :end-line: 30

    .. include:: cpp/src/op/1270.cpp
        :code: cpp
        :number-lines: 33
        :class: ltr
        :start-line: 30
        :end-line: 89

    ---

    END
