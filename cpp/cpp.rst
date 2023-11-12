:data-transition-duration: 1000
:data-width: 1024
:css: ./style.css ../css/cpp.css
:skip-help: true
:substep: true
:slide-numbers: true
:skip-help: true

.. title: Advanced Programming (C++)

.. role:: raw-html(raw)
   :format: html

Advanced Programming (C++)
==============================
Ahmad Yoosofan

University of Kashan

http://yoosofan.github.io/course/cpp.html

----

Methods of Learning a Programming Languange
==============================================
.. note::

    5 items

.. class:: substep

* Just using tools, packages, libraries, prepared functions, prepared classes, and objects.
    #. Using simplified data type with a lot of overhead like vector, string, anf etc.
    #. algorithm
    #. Using other libraries without knowing how they develop
    #. Always searching for new tools, language, packages, etc.
    #. Consider most language similar
    #. More tools, packages, languages, and alike means a better programmer
    #. Shallow understanding of the concept of each language and its basis
* Deeply learn the foundation of the language of the essential aspect of a language
    #. Step by Step learning of the language by writing programs
    #. Using basis to make new tools instead of using other tools
    #. Preparing for writing more sophisticated programs
    #. Deep understanding of each tool/package/library/etc.
    #. Learning and using the best tool based on the application requirement

----

Converting C code to C++
=============================
#. Rename .c file to .cpp
#. Change <stdio.h> to <cstdio> (c standard library)
    * stdio.h  → cstdio
    * math.h   → cmath
    * stdlib.h → cstdlib
    * string.h → csting
    * ctype.h  → cctype
    * https://en.wikipedia.org/wiki/C_standard_library
    * https://en.cppreference.com/w/c/header
#. Add the line the follwing line after includes
    * :code:`using namespace std;`
#. Compile using C++ compiler like g++

----

:id: c2cpp01-id

code1.c

code1.cpp

.. include:: src/c2cpp01_stdio.c
    :code: c
    :number-lines:
    :class: ltr


.. include:: src/c2cpp01_stdio.cpp
    :code: cpp
    :number-lines:
    :class: ltr

----

:class: grid-2col-class

c2cpp01_stdlib.c

c2cpp01_stdlib.cpp

.. include:: src/c2cpp01_stdlib.c
    :code: c
    :number-lines:
    :class: ltr


.. include:: src/c2cpp01_stdlib.cpp
    :code: cpp
    :number-lines:
    :class: ltr

----

:class: grid-2col-class

c2cpp02_functions.c

c2cpp02_functions.cpp

.. include:: src/c2cpp02_functions.c
    :code: c
    :number-lines:
    :class: ltr


.. include:: src/c2cpp02_functions.cpp
    :code: cpp
    :number-lines:
    :class: ltr

----

:class: grid-2col-class

.. include:: src/c2cpp02_functions_style.cpp
    :code: c
    :number-lines:
    :class: ltr
    :start-line: 0
    :end-line: 32


.. include:: src/c2cpp02_functions_style.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 32
    :end-line: 65

----

Online Compilers and tools
==============================
* `<http://www.tutorialspoint.com/compile_c_online.php>`_
* `<http://cpp.sh/>`_
* https://godbolt.org , https://github.com/compiler-explorer
* https://cppinsights.io
* `<http://codepad.org/>`_
* `<https://www.jdoodle.com/c-online-compiler>`_
* `<http://ideone.com>`_
* `<https://www.codechef.com/ide>`_
* `<http://webcompiler.cloudapp.net/>`_
* `<https://codepad.remoteinterview.io/GladnessUrgentCactusCostume>`_
* `<http://www.onlinecompiler.net/>`_
* `<http://getprogramcode.com/compiler/compile-c-programs-online.html>`_
* `<http://coliru.stacked-crooked.com/>`_
* `<https://ide.geeksforgeeks.org/>`_
* `<https://www.onlinegdb.com/online_c_compiler>`_
* `<https://www.remoteinterview.io/online-c-compiler>`_
* `<http://www.compileonline.com/compile_c_online.php>`_
* `<https://www.codechef.com/ide>`_
* `<https://www.beta.browxy.com/>`_
* `<compiler.run>`_

----

Compilers
=============
*  gcc(g++): http://gcc.gnu.org
    * windows:
        * https://www.mingw-w64.org/downloads/
        * http://win-builds.org/doku.php
*  `clang <https://clang.llvm.org/>`_
*  https://visualstudio.microsoft.com/downloads/

Compile and run
-------------------
.. code:: sh

    cd folder_of_code
    g++ code1.cpp
    ./a.out

.. code:: sh

    cd folder_of_code
    g++ code1.cpp -o code1.o
    ./code1.o

----

Editors
============
*  geany: http://www.geany.org
*  notepad++ http://www.notepad-plus-plus.org
*  kate http://kate-editor.org
*  https://code.visualstudio.com/download

----

IDE
====
*  orwelldevcpp: http://sourceforge.net/projects/orwelldevcpp
*  codeblocks: http://www.codeblocks.org
*  Ch: http://www.softintegration.com
*  Qt Creator: http://qt-project.org
*  kdevelop https://apps.kde.org/kdevelop/
*  cbuilder: http://www.embarcadero.com/products/cbuilder
*  DevCpp: http://www.bloodshed.net/devcpp.html
*  Visual Studio Express: http://www.microsoft.com/visualstudio/eng/products/visual-studio-express-products
*  xcode: https://developer.apple.com/xcode/

----

Standard Library
=====================
* https://en.wikipedia.org/wiki/C_standard_library
* https://www.tutorialspoint.com/c_standard_library/index.htm
* https://en.wikibooks.org/wiki/C_Programming/Standard_libraries
* https://en.cppreference.com/w/c/header

C++
-----
* https://en.wikipedia.org/wiki/C%2B%2B_Standard_Library
* https://en.wikipedia.org/wiki/C%2B%2B
* https://en.wikipedia.org/wiki/C%2B%2B_Standard_Library
* https://www.programiz.com/cpp-programming/library-function
* https://en.cppreference.com/w/cpp/header
* https://www.tutorialspoint.com/cpp_standard_library/index.htm

----

:id: c2cpp-variable-id

Variable declaration

cout and cin

.. include:: src/c2cpp04_variable.cpp
    :code: cpp
    :number-lines:
    :class: ltr

.. include:: src/c2cpp04_cout.cpp
    :code: cpp
    :number-lines:
    :class: ltr

----

.. include:: src/c2cpp04_cout_std.cpp
    :code: cpp
    :number-lines:
    :class: ltr

----

:id: struct-name01-id

Struct name C

Struct name C++

.. include:: src/c2cpp22_struct01.c
    :code: cpp
    :number-lines:
    :class: ltr

.. include:: src/c2cpp22_struct01.cpp
    :code: cpp
    :number-lines:
    :class: ltr

----

:id: c2cpp22-struct02-id

struct c

struct cpp

.. include:: src/c2cpp22_struct02.c
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 0
    :end-line: 28

.. include:: src/c2cpp22_struct02.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 0
    :end-line: 28

----

:id: c2cpp22-struct02-01-id

struct c

struct cpp

.. include:: src/c2cpp22_struct02.c
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 28

.. include:: src/c2cpp22_struct02.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 28

----

:id: cout14-multiple-output-id

simple cout (print_date)

multiple output (print_date)

.. include:: src/cout12_multiple_output.cpp
    :code: cpp
    :number-lines:
    :class: ltr

.. include:: src/cout14_multiple_output.cpp
    :code: cpp
    :number-lines:
    :class: ltr

----

:id: cout16-multiple-output-id

simple cout (print_date)

multiple output (print_date)

.. include:: src/cout14_multiple_output.cpp
    :code: cpp
    :number-lines:
    :class: ltr

.. include:: src/cout16_multiple_output.cpp
    :code: cpp
    :number-lines:
    :class: ltr

----

:id: cout18-multiple-output-id

`\\n`

endl

.. include:: src/cout16_multiple_output.cpp
    :code: cpp
    :number-lines:
    :class: ltr

.. include:: src/cout18_endl.cpp
    :code: cpp
    :number-lines:
    :class: ltr

.. :

  `endl vs \n <https://www.geeksforgeeks.org/endl-vs-n-in-cpp/>`_


  Although they both seem to do the same thing, there is a subtle difference between them.

  cout << endl  : Inserts a new line and flushes the stream

  cout << "\n"  : Only inserts a new line.

  Therefore,
  cout << endl;
  can be said equivalent to
  cout << ‘\n’ << flush;
  So cout << “\n” seems performance wise better than cout << endl; unless flushing of stream is required.
  Some other differences between endl and \n are:

      endl is manipulator while \n is character.
      endl doesn’t occupy any memory whereas \n is character so It occupy 1 byte memory.
      \n being a character can be stored in a string(will still convey its specific meaning of line break) while endl is a keyword and would not specify any meaning when stored in a string.
      We cannot write endl in between double quotation while we can write \n in between double quotation like
      cout<<“\n”; it is right but cout<<“endl”; is wrong.
      We can use \n both in C and C++ but, endl is only supported by C++ and not the C language.

  Reference:
  http://stackoverflow.com/questions/213907/c-stdendl-vs-n


.. :

  `Cin-Cout vs Scanf-Printf <https://www.geeksforgeeks.org/cincout-vs-scanfprintf/>`_

  \n

  endl


----

:id: c2cpp42-function-signature02-id

different name

function signature

.. include:: src/c2cpp42_function_signature02.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 0
    :end-line: 29

.. include:: src/c2cpp42_function_signature04.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 0
    :end-line: 29

----

:id: c2cpp42-function-signature06-id

Same signature

Error

.. include:: src/c2cpp42_function_signature06_error.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 0
    :end-line: 29

.. include:: src/c2cpp42_function_signature06_error.txt
    :code: console
    :number-lines:
    :class: ltr
    :start-line: 0
    :end-line: 29

----

function default values
=========================
.. code:: cpp

    void point(int x = 3, int y = 4);

    point(1,2); // calls point(1,2)
    point(1);   // calls point(1,4)
    point();    // calls point(3,4)

.. code:: cpp

    int sum(int x, int y, int z=0, int w=0)
    {
        return (x + y + z + w);
    }

    /* Driver program to test above function*/
    int main()
    {
        cout << sum(10, 15) << endl;
        cout << sum(10, 15, 25) << endl;
        cout << sum(10, 15, 25, 30) << endl;
    }


* https://en.cppreference.com/w/cpp/language/default_arguments
* https://www.geeksforgeeks.org/default-arguments-c/

-----

Errors Default value for parameters(I)
===========================================
.. include:: src/c2cpp53_function_default_value.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 0
    :end-line: 29

.. code:: console
   :class: output

      4:36: error: default argument missing for parameter 4 of ‘int sum(int, int, int, int)’
      4 | int sum(int x, int y, int z=0, int w){
      |                                ~~~~^
      4:27: note: ...following parameter 3 which has a default argument
      4 | int sum(int x, int y, int z=0, int w){
      |                       ~~~~^~~
 
-----

Errors Default value for parameters(II)
===========================================
.. include:: src/c2cpp55_function_default_value.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 0
    :end-line: 29

.. code:: console
   :class: output
   :number-lines:

    10:21: error: call of overloaded ‘sum(int, int)’ is ambiguous
       10 |   cout << sum(10, 15) << endl;
          |                     ^
    3:5: note: candidate: ‘int sum(int, int, int, int)’
        3 | int sum(int x, int y, int z=0, int w=0){
          |     ^~~
    6:5: note: candidate: ‘int sum(int, int)’
        6 | int sum(int x, int y){
          |     ^~~

-----

Encapsulation(I)
==================
* Functions in Struct
* The Most Important Step on Learning Object Oriented Programming
* The Most Important Object Oriented Programming Principle
* Method (Functions in struct)

.. list-table::

  * - .. include:: src/student/student122.cpp
        :code: cpp
        :number-lines: 2
        :class: ltr
        :start-line: 2
        :end-line: 28

    - .. include:: src/student/student124.cpp
        :code: cpp
        :number-lines: 2
        :class: ltr
        :start-line: 2
        :end-line: 28

----

:class: t2c

Encapsulation(II)
====================================
.. include:: src/struct_method204.cpp
    :code: cpp
    :number-lines: 3
    :class: ltr
    :start-line: 2  
    :end-line: 28

.. include:: src/struct_method208.cpp
    :code: cpp
    :number-lines: 3
    :class: ltr
    :start-line: 2
    :end-line: 28


-----

:class: t2c

Encapsulation Struct(III)
===========================
.. include:: src/struct_method214.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 0
    :end-line: 30

.. include:: src/struct_method218.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 0
    :end-line: 30

----

:class: t2c

Encapsulation(IV)
===========================
.. include:: src/mycomplex/00_one_file/complexCls01.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 0
    :end-line: 30

.. include:: src/mycomplex/00_one_file/complexCls02.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 0
    :end-line: 30

----

:class: t2c

Attribute Default Value(I)
=========================================================
.. include:: src/mycomplex/00_one_file/complexCls02.21.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 0
    :end-line: 34

.. include:: src/mycomplex/00_one_file/complexCls02.22.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 0
    :end-line: 34

----

:class: t2c

Attribute Default Value(II)
====================================
.. include:: src/struct_method208.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 0
    :end-line: 28

.. include:: src/struct_method210.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 0
    :end-line: 28

----

:class: t2c

Attribute Default Value(III)
==============================
.. include:: src/struct_method222.cpp
    :code: cpp
    :number-lines: 2
    :class: ltr
    :start-line: 1
    :end-line: 34

.. include:: src/struct_method224.cpp
    :code: cpp
    :number-lines: 2
    :class: ltr
    :start-line: 1
    :end-line: 34

----

:class: t2c

MyArray Struct(I)
===================
.. include:: src/myArray/100400.cpp
    :code: cpp
    :number-lines:

.. include:: src/myArray/100410.cpp
    :code: cpp
    :number-lines:

----

:class: t2c

MyArray Struct(II)
===================
.. include:: src/myArray/100420.cpp
  :code: cpp
  :number-lines:
  :class: ltr

.. include:: src/myArray/100422.cpp
  :code: cpp
  :number-lines:
  :class: ltr

----

:class: t2c

MyArray Struct(III) - Error
================================
.. include:: src/myArray/100420.cpp
  :code: cpp
  :number-lines:
  :class: ltr

.. include:: src/myArray/100423.22.cpp
  :code: cpp
  :number-lines:
  :class: ltr substep

.. class:: substep

* Check Array Bounds

----

Error in Action
====================
.. include:: src/myArray/100423.33.cpp
  :code: cpp
  :number-lines:
  :class: ltr


----

:class: t2c

Order of properties and methods is irrelevant in struct
==============================================================
.. include:: src/myArray/100423.22.cpp
  :code: cpp
  :number-lines:
  :class: ltr

.. include:: src/myArray/100423.44.cpp
  :code: cpp
  :number-lines:
  :class: ltr


----

:class: t2c

MyArray Struct(IV) Const(I)
===============================
.. include:: src/myArray/100423.22.cpp
  :code: cpp
  :number-lines:
  :class: ltr

.. include:: src/myArray/100424.cpp
  :code: cpp
  :number-lines:
  :class: ltr

----

:class: t2c

MyArray Struct(V) Const(II)
===============================
.. include:: src/myArray/100424.cpp
  :code: cpp
  :number-lines:
  :class: ltr

.. include:: src/myArray/100426.22.cpp
  :code: cpp
  :number-lines:
  :class: ltr

----

:class: t2c

Constructor(I)
===========================
.. include:: src/mycomplex/00_one_file/complexCls0101.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 0
    :end-line: 30

.. include:: src/mycomplex/00_one_file/complexCls03.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 0
    :end-line: 30

----

Constructor(II)
=================
.. include:: src/myArray/100430.cpp
  :code: cpp
  :number-lines:

----

Constructor (III)
=================
.. include:: src/myArray/100432.cpp
  :code: cpp
  :number-lines:
  :class: ltr

----

Another way of writing for
===================================
.. include:: src/myArray/100442.cpp
  :code: cpp
  :number-lines:
  :class: ltr

----

Error !
=============
.. include:: src/myArray/100440.cpp
  :code: cpp
  :number-lines:
  :class: ltr
  :start-line: 3
  :end-line: 11

----

.. include:: src/myArray/100450.cpp
  :code: cpp
  :number-lines:
  :class: ltr

----

Const (III)
=============
.. include:: src/myArray/100460.cpp
  :code: cpp
  :number-lines:
  :class: ltr
  :start-line: 1
  :end-line: 12

----

Const (IV)
=============
.. include:: src/myArray/100470.cpp
  :code: cpp
  :number-lines:
  :class: ltr

----

Error
========
.. include:: src/myArray/100475.cpp
  :code: cpp
  :number-lines:
  :class: ltr
  :start-line: 1
  :end-line: 12

----

:class: t2c

static in Function
==================
.. include:: src/myArray/100478.cpp
  :code: cpp
  :number-lines:

.. code:: console

  myArray$ g++ 100478.cpp
  myArray$ ./a.out
  static_i: 0
  static_i: 1
  static_i: 2
  myArray$

----

:class: t2c

static in struct(I)
====================
.. include:: src/myArray/100479.cpp
  :code: cpp
  :number-lines:

.. code:: console

  slide$ g++ src/myArray/100479.cpp
  slide$ ./a.out
   n = 4   MAX: 100
  a[0] = 10
  a[1] = 12
  a[2] = 34
  a[3] = 54
   n = 4   MAX: 100
  a[0] = 10
  a[1] = 12
  a[2] = 34
  a[3] = 54
   n = 4   MAX: 100
  a[0] = 10
  a[1] = 94
  a[2] = 34
  a[3] = 54
  slide$

----

:class: t2c

static in struct(II)
====================
.. include:: src/myArray/100480.cpp
  :code: cpp
  :number-lines:

.. code:: console

  slide$ g++ src/myArray/100480.cpp
  ./a.out
  slide$ ./a.out
   n = 4   other_static: 20
  a[0] = 10
  a[1] = 12
  a[2] = 34
  a[3] = 54
   n = 4   other_static: 94
  a[0] = 10
  a[1] = 12
  a[2] = 34
  a[3] = 54
   n = 4   other_static: 94
  a[0] = 10
  a[1] = 94
  a[2] = 34
  a[3] = 54
  slide$

----

:class: t2c

static in struct(III) - Error
==============================
.. include:: src/myArray/100482.cpp
  :code: cpp
  :number-lines:

.. code:: console

  slide$ g++ src/myArray/100482.cpp

  src/myArray/100482.cpp:24:12: error:
    expected initializer before ‘.’ token
     24 | int myArray.other_static = 20 ;
        |

----

:class: t2c

static in struct(IV) - Error
===================================
.. include:: src/myArray/100484.cpp
  :code: cpp
  :number-lines:

.. code:: console

  slide$ g++ src/myArray/100484.cpp
  src/myArray/100484.cpp:5:14: error:
    ISO C++ forbids in-class initialization of
    non-const static member ‘myArray::other_static’
    5 |   static int other_static = 20;
      |              ^~~~~~~~~~~~

----

:class: t2c

Static Function in struct(I)
===================================
.. include:: src/myArray/100486.22.cpp
  :code: cpp
  :number-lines:

.. code:: console

  slide$ g++ src/myArray/100486.22.cpp
  slide$ ./a.out
  MAX: 100
  other_static: 20
   n = 4   other_static: 20
  a[0] = 10
  a[1] = 12
  a[2] = 34
  a[3] = 54
   n = 4   other_static: 94
  a[0] = 10
  a[1] = 12
  a[2] = 34
  a[3] = 54
   n = 4   other_static: 94
  a[0] = 10
  a[1] = 94
  a[2] = 34
  a[3] = 54
  MAX: 100
  other_static: 94
  slide$

----

:class: t2c

Reference (I)
================
.. include:: src/myArray/100490.cpp
  :code: cpp
  :number-lines:
  :class: ltr

.. include:: src/myArray/100490_output.txt
  :code: console
  :number-lines:
  :class: ltr

.. :

  :start-line: 4
  :end-line: 12

----

:class: t2c

Reference (II)
================
.. include:: src/myArray/100510.cpp
  :code: cpp
  :number-lines:
  :class: ltr

.. code:: console

  g++ 100510.cpp
  ./a.out
  In F3: Enter n : 7
  n: 7
  In F2: Enter n : 9
  n: 7
  In F4: Enter n : 3
  n: 3

----

:class: t2c

Reference (III)
================
.. include:: src/myArray/100515.cpp
  :code: cpp
  :number-lines:
  :class: ltr

.. code:: console

  In F3: Enter n : 3
  n: 3

----

:class: t2c

Reference (IV)
================
.. include:: src/myArray/100517_reference.cpp
  :code: cpp
  :number-lines:
  :class: ltr

.. code:: console

  g++ 100517_reference.cpp
  100517_reference.cpp: In function ‘int f3()’:
  100517_reference.cpp:13:12: error: cannot bind non-const lvalue reference of
  type ‘int&’ to an rvalue of type ‘int’
     13 |   int& k = 12;
        |            ^~

----

:class: t2c

Reference (V)
================
.. include:: src/myArray/100518_reference.cpp
  :code: cpp
  :number-lines:
  :class: ltr

.. code:: console

  In function ‘int f3()’:
  13:8:
  error: ‘k’ declared as reference but not initialized
     13 |   int& k;
        |

----

:class: t2c

Reference (VI)
================
.. include:: src/reference_swap01.cpp
  :code: cpp
  :number-lines:
  :class: ltr

.. code:: console

  ./a.out
  m: 2  n: 8
  m: 2  n: 8
  m: 8  n: 2

----

:class: t2c

Reference (VII) - Function Overloading Error
============================================
.. include:: src/reference_swap22.cpp
  :code: cpp
  :number-lines:
  :class: ltr

.. code:: console

  g++ reference_swap22.cpp
  reference_swap22.cpp: In function ‘void f1()’:
  reference_swap22.cpp:16:14: error: call of
  overloaded ‘mySwap(int&, int&)’ is ambiguous
     16 |   mySwap(m, n);
        |              ^
  reference_swap22.cpp:3:6: note: candidate:
  ‘void mySwap(int&, int&)’
      3 | void mySwap(int& a, int& b){
        |      ^~~~~~
  reference_swap22.cpp:8:6: note: candidate:
  ‘void mySwap(int, int)’
      8 | void mySwap(int a, int b){
        |      ^~~~~~
  reference_swap22.cpp:18:14: error: call of
  overloaded ‘mySwap(int&, int&)’ is ambiguous
     18 |   mySwap(m, n);
        |              ^
  reference_swap22.cpp:3:6: note: candidate:
  ‘void mySwap(int&, int&)’
      3 | void mySwap(int& a, int& b){
        |      ^~~~~~
  reference_swap22.cpp:8:6: note: candidate:
  ‘void mySwap(int, int)’
      8 | void mySwap(int a, int b){
        |      ^~~~~~

----

:class: t2c

Reference (VIII)
================
.. include:: src/reference_swap33.cpp
  :code: cpp
  :number-lines:
  :class: ltr

.. code:: console

  ./a.out
  In function ‘void f1()’:
  13:13: error: cannot bind non-const lvalue 
    reference of type ‘int&’ to an 
    rvalue of type ‘int’
     13 |   mySwap(m, 33);
        |             ^~
  3:26: note:   initializing argument 2 of 
    ‘void mySwap(int&, int&)’
      3 | void mySwap(int& a, int& b){
        |                     ~~~~~^

----

lvalue & rvalue
=====================
.. code:: cpp
  :number-lines:

  int ar[10] = {2, 3, 4};
  int a = 2, b = 3 , c = 5;
  a = a + 2;
  /* t = a + 2
    a = t
  */
  a = a + b + c + 2;
  /*
    t1 = a + b
    t2 = t1  + c
    t3 = t2 + 2
    a = t3
  */
  a += a + 2;
  // a = a + a + 2
  // a + 2 += a // Error
  // (a + 2) = (a + 2) + a // Error
  // (a+2) = 2 Error
  // a+2 = 2 Error
  int* p = &a;
  *p = 4; // a = 4;
  p = ar;  // p = &ar[0]
  *(p + 2) = 34; // p[2] = 34; ar[2] = 34;
  p[3] = 76;



----

:class: t2c

Const Reference(I)
===================
.. include:: src/complex02.32.cpp
  :code: cpp
  :number-lines:
  :class: ltr

.. include:: src/complex02.36.cpp
  :code: cpp
  :number-lines:
  :class: ltr

----

:class: t2c

Const Reference(II) Error
=========================
.. include:: src/complex02.38.cpp
  :code: cpp
  :number-lines:
  :class: ltr
  :start-line: 0
  :end-line: 25

.. container::

  .. include:: src/complex02.38.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 25
    :end-line: 38

  .. code:: console

    g++ 8.cpp
    In function ‘void f2(const complexCls&)’:
    28:12: error: passing ‘const complexCls’
    as ‘this’ argument discards
    qualifiers [-fpermissive]
       28 |   c1.print();
          |            ^
    11:8: note: in call to
    ‘void complexCls::print()’
       11 |   void print(void){
          |        ^~~~~
    29:21: error: passing ‘const complexCls’ as
    ‘this’ argument discards
    qualifiers [-fpermissive]
       29 |   cout << c1.getImg() << endl;
          |                     ^
    note: in call to
    ‘double complexCls::getImg()’
        8 |   double getImg(void){return img;}
          |          ^~~~~~


----

:class: t2c

Const Member Function
========================
.. include:: src/complex02.39.22.cpp
  :code: cpp
  :number-lines:
  :class: ltr
  :start-line: 0
  :end-line: 30

.. container::

  .. include:: src/complex02.39.22.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 30
    :end-line: 38

  .. code:: console

    ./a.out
    (13,0)
    (13,17)
    (13,17)
    17

----

:class: t2c

Const Member Function
========================
.. include:: src/myArray/100612_refrence_not_copy.cpp
  :code: cpp
  :number-lines:
  :class: ltr
  :start-line: 0
  :end-line: 30

.. include:: src/myArray/100613_refrence_not_copy.cpp
  :code: cpp
  :number-lines:
  :class: ltr
  :start-line: 0
  :end-line: 38

----

:class: t2c

Const Reference(III) - Error
===============================
.. include:: src/complex02.42.cpp
  :code: cpp
  :number-lines:
  :class: ltr

.. code:: console

  g++ 42.cpp
  error: cannot bind
  non-const lvalue reference of type ‘double&’
  to an rvalue of type ‘double’
      5 |   void set(double& r=0, double& i=0)
        |                      ^
  error: cannot bind
  non-const lvalue reference of type ‘double&’
  to an rvalue of type ‘double’
      5 |   void set(double& r=0, double& i=0)
        |                                   ^
  In function ‘void f1(complexCls&)’:
  22:12: error: cannot bind non-const
  lvalue reference of type ‘double&’
  to an rvalue of type ‘double’
     22 |   c1.setRe(a);
        |            ^
  note:   initializing argument 1
  of ‘void complexCls::setRe(double&)’
      9 |   void setRe(double& r){re = r;}
        |              ~~~~~~~~^
  error: cannot bind non-const
  lvalue reference of type ‘double&’
  to an rvalue of type ‘double’
     24 |   c1.set(a, b);
        |          ^
  note:   initializing argument 1
  of ‘void complexCls::set(double&, double&)’
      5 |   void set(double& r=0, double& i=0)
        |            ~~~~~~~~^~~

----

:class: t2c

Const Reference(IV)
=====================
.. include:: src/complex02.42.cpp
  :code: cpp
  :number-lines:
  :class: ltr

.. include:: src/complex02.46.cpp
  :code: cpp
  :number-lines:
  :class: ltr

----

:class: t2c

Const Reference(V)
=====================
.. include:: src/complex02.46.cpp
  :code: cpp
  :number-lines:
  :class: ltr

.. include:: src/complex02.52.cpp
  :code: cpp
  :number-lines:
  :class: ltr

----

:class: t2c

Const Reference(VI)
=====================
.. include:: src/complex02.52.cpp
  :code: cpp
  :number-lines:
  :class: ltr

.. include:: src/complex02.56.cpp
  :code: cpp
  :number-lines:
  :class: ltr

----

Function Parameter Default Value(I)
======================================
.. include:: src/myArray/100520.cpp
  :code: cpp
  :number-lines:
  :class: ltr
  :start-line: 2
  :end-line: 13

Output
----------
.. code:: sh

  k: 5   f2(5): n : 5
  5
  f2()n : 5
  5

----

II
-------------------------------------
.. include:: src/myArray/100530.cpp
  :code: cpp
  :number-lines:
  :class: ltr
  :start-line: 2
  :end-line: 13

output

.. code:: sh

  ./a.out
  k: 5   f2(5): n: 5   z: 6
  5
  f2()n: 5   z: 6
  5

----

III (Error)
-------------------------------------
.. include:: src/myArray/100540.cpp
  :code: cpp
  :number-lines:
  :class: ltr
  :start-line: 2

----

IV
========
.. include:: src/myArray/100550.cpp
  :code: cpp
  :number-lines:
  :class: ltr
  :start-line: 2

.. code:: console

  ./a.out
  f2(k, 8)
  n: 5   z: 8
  n: 5
  f2(5): n: 3  z: 6
  n: 3

----

.. include:: src/myArray/100610.cpp
  :code: cpp
  :number-lines:
  :class: ltr
  :start-line: 2

----

.. include:: src/myArray/100620.cpp
  :code: cpp
  :number-lines:
  :class: ltr
  :start-line: 2

.. code:: console

  ./a.out
   n = 4
  a[0] = 10
  a[1] = 12
  a[2] = 34
  a[3] = 54

----

.. include:: src/myArray/100630.cpp
  :code: cpp
  :number-lines:
  :class: ltr
  :start-line: 2

----

.. include:: src/myArray/100640.cpp
  :code: cpp
  :number-lines:
  :class: ltr
  :start-line: 2

----

.. include:: src/myArray/100650.cpp
  :code: cpp
  :number-lines:
  :class: ltr
  :start-line: 2

----

.. include:: src/myArray/100660.cpp
  :code: cpp
  :number-lines:
  :class: ltr
  :start-line: 2

----

.. include:: src/myArray/100710.cpp
  :code: cpp
  :number-lines:
  :class: ltr
  :start-line: 2

----

.. include:: src/myArray/100740.cpp
  :code: cpp
  :number-lines:
  :class: ltr
  :start-line: 2

----

:class: t2c

Pointer
==========
.. include:: src/myArray/100810.cpp
  :code: cpp
  :number-lines:
  :class: ltr
  :start-line: 2

.. include:: src/myArray/100814.cpp
  :code: cpp
  :number-lines:
  :class: ltr
  :start-line: 2

----

:class: t2c

auto(I)
========
.. include:: src/myArray/100820.cpp
  :code: cpp
  :number-lines:

.. include:: src/myArray/100840.cpp
  :code: cpp
  :number-lines:

----

:class: t2c

auto(II)
===========
.. include:: src/myArray/100830.cpp
  :code: cpp
  :number-lines:

.. include:: src/myArray/100850.cpp
  :code: cpp
  :number-lines:

.. :

  function parameter
  type of
  auto x1 = "ss";

----

:class: t2c

auto(III)
=============
.. include:: src/myArray/100860.cpp
  :code: cpp
  :number-lines:

.. include:: src/myArray/100870.cpp
  :code: cpp
  :number-lines:

----

:class: t2c

More on Dynamic Memory(I)
=============================
.. include:: src/myArray/100880.cpp
  :code: cpp
  :number-lines:

.. include:: src/myArray/100890.cpp
  :code: cpp
  :number-lines:
  :class: substep

----

:class: t2c

Pointer and Reference
===========================
.. include:: src/myArray/100904.24.cpp
  :code: cpp
  :number-lines:
  :start-line: 0
  :end-line: 28

.. include:: src/myArray/100910.cpp
  :code: cpp
  :number-lines:
  :start-line: 8
  :end-line: 38

.. :

  c++ pointer reference
  https://www.geeksforgeeks.org/reference-to-a-pointer-in-c-with-examples-and-applications/
  https://www.geeksforgeeks.org/pointers-vs-references-cpp/
  https://www.tutorialspoint.com/what-is-difference-between-a-pointer-and-reference-parameter-in-cplusplus
  https://www3.ntu.edu.sg/home/ehchua/programming/cpp/cp4_PointerReference.html

----

Copy constructor
=====================
.. code:: cpp
  :number-lines:

  myComplex a(2, 3);
  myComplex b=a;
  myComplex c(a);
  myComplex d=4;

.. include:: src/mycomplex/100580_copy_constructor.cpp
  :code: cpp
  :number-lines:
  :start-line: 2
  :end-line: 17

----

:class: t2c

Copy constructor(II)
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

Destructor(I)
===========================
.. include:: src/myArray/102120.cpp
  :code: cpp
  :number-lines:
  :start-line: 2
  :end-line: 28

.. include:: src/myArray/102120.cpp
  :code: cpp
  :number-lines:
  :start-line: 28
  :end-line: 58

----

:class: t2c

Destructor(II)
===========================
.. include:: src/myArray/102140.cpp
  :code: cpp
  :number-lines:
  :start-line: 2
  :end-line: 31

.. include:: src/myArray/102140.cpp
  :code: cpp
  :number-lines:
  :start-line: 31
  :end-line: 60

----

:class: t2c

Destructor(III)
===========================
.. include:: src/myArray/102150.cpp
  :code: cpp
  :number-lines:
  :start-line: 2
  :end-line: 31

.. include:: src/myArray/102150.cpp
  :code: cpp
  :number-lines:
  :start-line: 31
  :end-line: 64

----

:class: t2c

Destructor(IV)
===========================
.. include:: src/myArray/102154.cpp
  :code: cpp
  :number-lines:
  :start-line: 2
  :end-line: 31

.. include:: src/myArray/102154.cpp
  :code: cpp
  :number-lines:
  :start-line: 31
  :end-line: 64

----

.. :

  this
  static function

:class: t2c

Destructor(V)
===========================
.. include:: src/myArray/102222.cpp
  :code: cpp
  :number-lines:
  :start-line: 2
  :end-line: 28

.. include:: src/myArray/102222.cpp
  :code: cpp
  :number-lines:
  :start-line: 28
  :end-line: 64

----

:class: t2c

.. :

    Destructor(VI)
    ===========================

.. include:: src/myArray/102234.cpp
  :code: cpp
  :number-lines:
  :start-line: 2
  :end-line: 34

.. include:: src/myArray/102234.cpp
  :code: cpp
  :number-lines:
  :start-line: 34
  :end-line: 72

----

:class: t2c

Destructor(VII)
===========================
.. include:: src/myArray/102244.cpp
  :code: cpp
  :number-lines:
  :start-line: 2
  :end-line: 33

.. include:: src/myArray/102244.cpp
  :code: cpp
  :number-lines:
  :start-line: 33
  :end-line: 69

----

:class: t2c

ComplexCls(XI)
===========================
.. include:: src/mycomplex/100560.cpp
    :code: cpp
    :number-lines:
    :start-line: 0
    :end-line: 28

.. include:: src/mycomplex/100560.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 28
    :end-line: 60

----

:class: t2c

Implicit Conversion (double to complexCls)
==========================================================
.. include:: src/mycomplex/100562.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 2
    :end-line: 30

.. include:: src/mycomplex/100562.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 30
    :end-line: 60

----

:class: t2c

.. :

    ComplexCls(XIII) - const
    =========================

.. include:: src/mycomplex/100565.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 2
    :end-line: 31

.. include:: src/mycomplex/100565.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 31
    :end-line: 62

----

:class: t2c

ComplexCls(XIV) - Destructor
==============================
.. include:: src/mycomplex/100565.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 2
    :end-line:  31

.. include:: src/mycomplex/100565.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 31
    :end-line: 65

----

:class: t2c

ComplexCls(XV) - Reference (VIII)
===================================
.. include:: src/mycomplex/100566.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 0
    :end-line: 28

.. include:: src/mycomplex/100566.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 28
    :end-line: 58

----

:class: t2c

Copy constructor(VI) - Error
===============================
.. include:: src/myArray/102110.cpp
  :code: cpp
  :number-lines:
  :start-line: 0
  :end-line: 25

.. include:: src/myArray/102110.cpp
  :code: cpp
  :number-lines:
  :start-line: 25
  :end-line: 50

.. :

  ----

  :class: two-column-yoosofan

  .. include:: src/mycomplex/100567.cpp
      :code: cpp
      :number-lines:
      :class: ltr
      :start-line: 0
      :end-line: 28

  .. include:: src/mycomplex/100567.cpp
      :code: cpp
      :number-lines:
      :class: ltr
      :start-line: 28
      :end-line: 58

----

:class: t2c

ComplexCls(XVI) - Error
===============================
.. include:: src/mycomplex/100569.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 2
    :end-line: 29

.. include:: src/mycomplex/100569.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 29
    :end-line: 60

----

Error
==========
.. code:: sh

  g++ 100569.cpp
  100569.cpp: In function ‘void f1()’:
  100569.cpp:45:13: error: cannot bind non-const lvalue reference of type
    ‘myComplex&’ to an rvalue of type ‘myComplex’
     45 |   c = a.add(2);
        |             ^
  100569.cpp:6:3: note:   after user-defined conversion:
    ‘myComplex::myComplex(double, double)’
      6 |   myComplex(const double a = 0,
        |   ^~~~~~~~~
  100569.cpp:23:28: note:   initializing argument 1 of ‘
    myComplex myComplex::add(myComplex&)’
     23 |   myComplex add(myComplex& a){
        |                 ~~~~~~~~~~~^


----

:class: two-column-yoosofan

.. include:: src/mycomplex/100567.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 2
    :end-line: 34

.. include:: src/mycomplex/100567.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 34
    :end-line: 66

----

:class: t2c

Constructor Default/Delete
================================
.. include:: src/mycomplex/00_one_file/complexCls0500.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 0
    :end-line: 30


.. include:: src/mycomplex/00_one_file/complexCls05010.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 2
    :end-line: 32

----

:class: t2c

Constructor Error
===========================
.. include:: src/mycomplex/00_one_file/complexCls0501.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 0
    :end-line: 30

.. include:: src/mycomplex/00_one_file/complexCls0502.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 0
    :end-line: 30

----

:class: t2c

Constructor Default/Delete - Default Value
=========================================================
.. include:: src/mycomplex/00_one_file/complexCls0503.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 0
    :end-line: 30

.. include:: src/mycomplex/00_one_file/complexCls0505.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 0
    :end-line: 30

----

:class: t2c

ComplexCls(XVII)
===========================
.. include:: src/mycomplex/00_one_file/complexCls0503.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 0
    :end-line: 30

.. include:: src/mycomplex/00_one_file/complexCls0504.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 0
    :end-line: 30

----

:class: t2c

ComplexCls(XVIII)
===========================
.. include:: src/mycomplex/00_one_file/complexCls06.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 0
    :end-line: 30

.. include:: src/mycomplex/00_one_file/complexCls00601.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 0
    :end-line: 35

----

:class: t2c

ComplexCls(XVIII-1)
===========================
.. include:: src/mycomplex/00_one_file/complexCls00601.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 0
    :end-line: 35

.. include:: src/mycomplex/00_one_file/complexCls00602.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 0
    :end-line: 35

----

:class: t2c

ComplexCls(XIX)
===========================
.. include:: src/mycomplex/00_one_file/complexCls07.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 0
    :end-line: 30

----

.. include:: src/mycomplex/00_one_file/complexCls08.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 0
    :end-line: 30

----

:class: t2c

ComplexCls(XX)
===========================
.. include:: src/mycomplex/00_one_file/complexCls09.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 2
    :end-line: 38

----

.. include:: src/mycomplex/00_one_file/complexCls10.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 2
    :end-line: 38

----

:class: t2c

ComplexCls(XXI)
===========================
.. include:: src/mycomplex/00_one_file/complexCls11.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 2
    :end-line: 32

.. include:: src/mycomplex/00_one_file/complexCls11.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 32
    :end-line: 77

----

:class: t2c

ComplexCls(XXII) - Error
===========================
.. include:: src/mycomplex/00_one_file/complexCls12.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 0
    :end-line: 28

.. include:: src/mycomplex/00_one_file/complexCls12.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 28
    :end-line: 65

----

:class: t2c

ComplexCls(XXIII)
===========================
.. include:: src/mycomplex/00_one_file/complexCls1201.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 2
    :end-line: 35

----

.. include:: src/mycomplex/00_one_file/complexCls1202.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 2
    :end-line: 35

----

:class: t2c

ComplexCls(XXIV)
===========================
.. include:: src/mycomplex/00_one_file/complexCls13.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 2
    :end-line: 35

.. include:: src/mycomplex/00_one_file/complexCls1301.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 2
    :end-line: 35

----

:class: t2c

ComplexCls(XXV)
===========================
.. include:: src/mycomplex/00_one_file/complexCls14.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 2
    :end-line: 28

.. include:: src/mycomplex/00_one_file/complexCls14.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 28
    :end-line: 70

----

:class: t2c

ComplexCls(XXVI)
===========================
.. include:: src/mycomplex/00_one_file/complexCls1401.cpp
  :code: cpp
  :number-lines:
  :class: ltr
  :start-line: 2
  :end-line: 35

.. code:: console
  :number-lines:
  :class: substep

  constructor: (2,4)
  (2,4)
  destructor: (2,4)
  constructor: (1,0)
  constructor: (3,5)
  (1,0)
  (1,0)
  (1,0)
  (3,5)
  (3,5)
  (3,5)
  destructor: (3,5)
  destructor: (1,0)

----

:class: t2c

ComplexCls(XXVII)
===========================
.. include:: src/mycomplex/00_one_file/complexCls15.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 2
    :end-line: 29

.. include:: src/mycomplex/00_one_file/complexCls15.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 29
    :end-line: 60

----

:class: t2c

ComplexCls(XXVII-1)
===========================
.. include:: src/mycomplex/00_one_file/complexCls15.01.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 2
    :end-line: 24

.. include:: src/mycomplex/00_one_file/complexCls15.01.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 24
    :end-line: 48 


----

:class: t2c

ComplexCls(XXVIII)
===========================
.. include:: src/mycomplex/00_one_file/complexCls16.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 2
    :end-line: 29

.. include:: src/mycomplex/00_one_file/complexCls16.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 29
    :end-line: 60

----

:class: t2c

ComplexCls(XXIX)
===========================
.. include:: src/mycomplex/00_one_file/complexCls17.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 2
    :end-line: 30

.. include:: src/mycomplex/00_one_file/complexCls17.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 30
    :end-line: 60

----

:class: t2c

ComplexCls(XXX)
===========================
.. include:: src/mycomplex/00_one_file/complexCls18.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 2
    :end-line: 30

.. include:: src/mycomplex/00_one_file/complexCls18.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 30
    :end-line: 60

----

:class: t2c

ComplexCls and copy constructor
===============================
.. include:: src/mycomplex/00_one_file/complexCls18_10.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 2
    :end-line: 30

.. include:: src/mycomplex/00_one_file/complexCls18_10.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 30
    :end-line: 60


----

:class: t2c

ComplexCls(XXXI)
===========================
.. include:: src/mycomplex/00_one_file/complexCls19.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 2
    :end-line: 31

.. include:: src/mycomplex/00_one_file/complexCls19.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 31
    :end-line: 60

----

:class: t2c

Explicit Constructor(I)
=========================
.. include:: src/mycomplex/100575_explicit.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 2
    :end-line: 31

.. include:: src/mycomplex/100575_explicit.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 31
    :end-line: 67

----

:class: t2c

Explicit Constructor(II) - Error
==================================
.. include:: src/mycomplex/100576_explicit.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 0
    :end-line: 27

.. include:: src/mycomplex/100576_explicit.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 27
    :end-line: 60

.. :

  https://www.geeksforgeeks.org/g-fact-93/

----

Explicit Constructor(III) - Error Output
================================================
.. code:: sh

    100576_explicit.cpp: In function ‘int main()’:
    100576_explicit.cpp:42:17: error: conversion from ‘int’ to
      non-scalar type ‘myComplex’ requested
       42 |   myComplex d = 4;
          |                 ^
    100576_explicit.cpp:44:13: error: cannot convert ‘int’ to
        ‘const myComplex&’
       44 |   c = a.add(2);
          |             ^
          |             |
          |             int
    100576_explicit.cpp:21:34: note: initializing argument 1 of
      ‘myComplex myComplex::add(const myComplex&)’
       21 |   myComplex add(const myComplex& a){
          |                 ~~~~~~~~~~~~~~~~~^

----

:class: t2c

MyArray(I)
=========================
.. include:: src/myArray/102050.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 2
    :end-line: 36

.. include:: src/myArray/102050.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 36
    :end-line: 80

----

:class: t2c

MyArray(II) - Error
=========================
.. include:: src/myArray/102070.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 0
    :end-line: 30

.. include:: src/myArray/102070.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 30
    :end-line: 65

----

MyArray(III) - Error Output
============================
.. code:: sh

  g++ 102070.cpp
  102070.cpp: In function ‘int main()’:
  102070.cpp:55:19: error: invalid conversion from ‘int’ to ‘const double*’ [-fpermissive]
     55 |   myArray k(2), r=3;
        |                   ^
        |                   |
        |                   int
  102070.cpp:20:25: note:   initializing argument 1 of ‘myArray::myArray(const double*, int)’
     20 |   myArray(const double *ma = nullptr,
        |           ~~~~~~~~~~~~~~^~~~~~~~~~~~
  102070.cpp:56:21: error: invalid conversion from ‘int’ to ‘const double*’ [-fpermissive]
     56 |   myArray p = d.add(2);//p=d+2;
        |                     ^
        |                     |
        |                     int
  102070.cpp:20:25: note:   initializing argument 1 of ‘myArray::myArray(const double*, int)’
     20 |   myArray(const double *ma = nullptr,
        |           ~~~~~~~~~~~~~~^~~~~~~~~~~~

----

:class: t2c

MyArray(II-1) - Error
=========================
.. include:: src/myArray/102072.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 0
    :end-line: 30

.. include:: src/myArray/102072.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 30
    :end-line: 65

----

MyArray(III-1) - Error Output
==============================
.. code:: sh

    In function ‘int main()’:
    102072.cpp:57:19: error: 
      conversion from ‘int’ to non-scalar type 
      ‘myArray’ requested
       57 |   myArray k(2), r=3;
          |                   ^
    102072.cpp:58:21: error: 
      cannot convert ‘int’ to ‘myArray’
       58 |   myArray p = d.add(2);//p=d+2;
          |                     ^
          |                     |
          |                     int
    102072.cpp:33:23: note:   
      initializing argument 1 of 
      ‘myArray myArray::add(myArray)’
       33 |   myArray add(myArray b){
          |               ~~~~~~~~^

----

:class: t2c

MyArray(II) - Error
=========================
.. include:: src/myArray/102075.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 0
    :end-line: 30

.. include:: src/myArray/102075.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 30
    :end-line: 65

----

.. code:: sh

  In function ‘int main()’:
  :56:19: error: conversion from ‘int’ to non-scalar type ‘myArray’ requested
     56 |   myArray k(2), r=3;
        |                   ^
  :57:21: error: cannot convert ‘int’ to ‘myArray’
     57 |   myArray p = d.add(2);//p=d+2;
        |                     ^
        |                     |
        |                     int
  :32:23: note:   initializing argument 1 of ‘myArray myArray::add(myArray)’
     32 |   myArray add(myArray b){
        |               ~~~~~~~~^

----

:class: t2c

MyArray(IV)
=========================
.. include:: src/myArray/102080.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 2
    :end-line: 36

.. include:: src/myArray/102080.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 36
    :end-line: 75

----

:class: t2c

MyArray(V)
=========================
.. include:: src/myArray/102110.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 0
    :end-line: 24

.. include:: src/myArray/102110.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 24
    :end-line: 72

----

:class: t2c

MyArray(VI) Error
=========================
.. include:: src/myArray/102120.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 1
    :end-line: 27

.. include:: src/myArray/102120.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 27
    :end-line: 55

----

:class: t2c

MyArray(VII) - Error
=========================
.. include:: src/myArray/102130.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 2
    :end-line: 31

.. include:: src/myArray/102130.cpp
    :code: cpp
    :number-lines: 31
    :class: ltr
    :start-line: 31
    :end-line: 77

----

MyArray(VIII) - Error Output
=================================
.. code:: sh

  a[1600] = 2.51318e+88
  a[1601] = 6.87111e+246
  a[1602] = 3.99261e+252
  a[1603] = 1.32333e+213
  a[1604] = 1.71872e+161
  a[1605] = 3.89028e-80
  a[1606] = 1.92058e+261
  a[1607] = 6.85742e+246
  a[1608] = 7.47833e+247
  a[1609] = 2.11262e+35
  a[1610] = 9.52812e+150
  a[1611] = 4.85361e+252
  a[1612] = 9.57077e+175
  a[1613] = 3.47844e-81
  a[1614] = 1.041e-306
  a[1615] = 2.1188e+88
  a[1616] = 2.78638e+93
  a[1617] = 8.34036e+62
  a[1618] = 7.38302e+54
  a[1619] = 2.51234e+93
  a[1620] = 8.38167e+251
  a[1621] = 3.64204e+174
  a[1622] = 5.28556e+180
  a[1623] = 4.00964e+78
  a[1624] = 2.78638e+93
  a[1625] = 1.85996e+106
  a[1626] = 1.72352e+45
  a[1627] = 1.06738e-307
  a[1628] = 1.82089e-306
  a[1629] = 0
  Segmentation fault (core dumped)

----

:class: t2c

MyArray(IX)
=========================
.. include:: src/myArray/102135.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 2
    :end-line: 29

.. include:: src/myArray/102135.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 29
    :end-line: 63

----

:class: t2c

MyArray(X)
=========================
.. include:: src/myArray/102140.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 2
    :end-line: 34

.. include:: src/myArray/102140.cpp
    :code: cpp
    :number-lines:
    :class: ltr
    :start-line: 34
    :end-line: 67

----

:class: t2c

MyArray(XI) - Copy Constructor(IV)
=====================================
.. include:: src/myArray/102150.cpp
    :code: cpp
    :number-lines: 2
    :class: ltr
    :start-line: 2
    :end-line: 31

.. include:: src/myArray/102150.cpp
    :code: cpp
    :number-lines: 31
    :class: ltr
    :start-line: 31

----

:class: t2c

Friend Function(I)
=========================
.. include:: src/myArray/102300.cpp
    :code: cpp
    :number-lines: 2
    :class: ltr
    :start-line: 2
    :end-line: 36

.. include:: src/myArray/102300.cpp
    :code: cpp
    :number-lines: 36
    :class: ltr
    :start-line: 36

----

:class: t2c

Friend Function(II)
=========================
.. include:: src/myArray/102310.cpp
    :code: cpp
    :number-lines: 2
    :class: ltr
    :start-line: 2
    :end-line: 36

.. include:: src/myArray/102310.cpp
    :code: cpp
    :number-lines: 36
    :class: ltr
    :start-line: 36

----

:class: t2c

Friend Class
=========================
.. include:: src/student/10222student.cpp
    :code: cpp
    :number-lines: 2
    :class: ltr
    :start-line: 2
    :end-line: 33

.. include:: src/student/10222student.cpp
    :code: cpp
    :number-lines: 33
    :class: ltr
    :start-line: 33

----

:class: t2c

Dynamic Memory in Class(I)
============================
.. include:: src/student/10230student.cpp
    :code: cpp
    :number-lines: 2
    :class: ltr
    :start-line: 2
    :end-line: 25

.. include:: src/student/10230student.cpp
    :code: cpp
    :number-lines: 25
    :class: ltr
    :start-line: 25

----

:class: t2c

Dynamic Memory in Class(II)
==============================
.. include:: src/student/10232student.cpp
    :code: cpp
    :number-lines: 2
    :class: ltr
    :start-line: 2
    :end-line: 26

.. include:: src/student/10232student.cpp
    :code: cpp
    :number-lines: 26
    :class: ltr
    :start-line: 26

----

:class: t2c

Multidimensional Dynamic Array
================================
.. include:: src/102555multidimensional.dynamic.array.cpp
    :code: cpp
    :number-lines: 2
    :class: ltr
    :start-line: 2
    :end-line: 22

.. include:: src/102555multidimensional.dynamic.array.cpp
    :code: cpp
    :number-lines: 22
    :class: ltr
    :start-line: 22

-----

Four Pillars of OOP
=====================
* Encapsulation
* Abstraction
* Polymorphism
* Inheritence

.. image:: ../img/oop_4_pillars.png
   :align: center

.. :

  Encapsulation
  ---------------
  Encapsulation is the idea of wrapping together data and function within one unit. The idea is to hide the initial state of the objects and to bind everything in a solid pack [#blockgeekspythonblockchain]_.

  Abstraction
  ----------------
  Abstraction means that a user can use the program without getting into the complications behind it.

  Think of a car.

  When you drive a car, all that you care about is putting your key in and maneuvering the vehicle in a way that you don’t hit anything else. You don’t care about how the engines work and how the ignition is burning your fuel.

  Inheritance
  -------------
  Inheritance is one of the most important properties of OOPs.

  Inheritance allows an object or a class to based upon another object or a class and retain some of its implementation. In most class-based object-oriented languages, an object created through inheritance acquires most of the properties and behaviors of the parent object

  Polymorphism
  -----------------
  Polymorphism is the property by which an operator in the language can have more than one properties. The most famous example of this is “+”. Not only is it used as the mathematical addition operator, but it can also be used to combine two strings into one as well. This is called concatenation.

  Eg. if we add two strings “Block” + “Geeks” the result will be “BlockGeeks”.

----

* reference
* static
* new /delete
* pointers
* struct copy
* Array value
* Function const arguments


----

END
