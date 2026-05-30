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

    .. |nbsp| unicode:: 0xA0

    From C to C++

.. slido::

    Ahmad Yoosofan

    University of Kashan

    http://yoosofan.github.io/course/cpp.html

.. slido:: Methods of Learning a Programming Languange

    .. IGNORED_UNIMPLEMENTED: note::

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

.. slido:: Converting C code to C++
   :class: t2c

    #. Rename .c file to .cpp
    #. <stdio.h> to <cstdio>
        * stdio.h  → cstdio
        * math.h   → cmath
        * stdlib.h → cstdlib
        * string.h → csting
        * ctype.h  → cctype

    * `Wikipedia <https://en.wikipedia.org/wiki/C_standard_library>`_
    * `cppreference <https://en.cppreference.com/w/c/header>`_
    * Add the follwing line after includes
        * :code:`using namespace std;`
    * Compile using C++ compiler like g++

.. slido::
   :class: t2c

    code1.c

    code1.cpp

    .. include:: cpp/src/c2cpp01_stdio.c
        :code: c
        :number-lines:

    .. include:: cpp/src/c2cpp01_stdio.cpp
        :code: cpp
        :number-lines:

.. slido::
   :class: t2c

    c2cpp01_stdlib.c

    c2cpp01_stdlib.cpp

    .. include:: cpp/src/c2cpp01_stdlib.c
        :code: c
        :number-lines:

    .. include:: cpp/src/c2cpp01_stdlib.cpp
        :code: cpp
        :number-lines:

.. slido::
   :class: t2c

    c2cpp02_functions.c

    c2cpp02_functions.cpp

    .. include:: cpp/src/c2cpp02_functions.c
        :code: c
        :number-lines:
        :start-line: 0
        :end-line: 27


    .. include:: cpp/src/c2cpp02_functions.cpp
        :code: cpp
        :number-lines:
        :start-line: 0
        :end-line: 27

.. slido::
   :class: t2c

    c2cpp02_functions.c

    c2cpp02_functions.cpp

    .. include:: cpp/src/c2cpp02_functions.c
        :code: c
        :number-lines: 27
        :start-line: 26

    .. include:: cpp/src/c2cpp02_functions.cpp
        :code: cpp
        :number-lines: 27
        :start-line: 26

.. slido:: No return 0 and void
   :class: t2c

    .. include:: cpp/src/c2cpp02_functions_style.cpp
        :code: c
        :number-lines:
        :start-line: 0
        :end-line: 24


    .. include:: cpp/src/c2cpp02_functions_style.cpp
        :code: cpp
        :number-lines: 25
        :start-line: 24
        :end-line: 47

.. slido:: Online Compilers and tools

    * `<http://www.tutorialspoint.com/compile_c_online.php>`_
    * `<http://cpp.sh/>`_
    * https://godbolt.org , https://github.com/compiler-explorer
    * https://cppinsights.io
    * `<http://codepad.org/>`_
    * `<https://www.jdoodle.com/c-online-compiler>`_
    * `<http://ideone.com>`_
    * `<https://www.codechef.com/ide>`_
    * `<http://webcompiler.cloudapp.net/>`_
    * https://onecompiler.com/cpp
    * `<https://codepad.remoteinterview.io/GladnessUrgentCactusCostume>`_
    * `<http://www.onlinecompiler.net/>`_
    * `<http://getprogramcode.com/compiler/compile-c-programs-online.html>`_
    * `<http://coliru.stacked-crooked.com/>`_
    * `<https://ide.geeksforgeeks.org/>`_
    * `<https://www.onlinegdb.com/online_c++_compiler>`_
    * `<https://www.remoteinterview.io/online-c-compiler>`_
    * `<http://www.compileonline.com/compile_c_online.php>`_
    * `<https://www.codechef.com/ide>`_
    * `<https://www.beta.browxy.com/>`_
    * `<compiler.run>`_
    * https://www.programiz.com/cpp-programming/online-compiler/

.. slido:: Compilers
   :class: t2c

    * `gcc <http://gcc.gnu.org>`_
       * windows
           * `mingw <https://www.mingw-w64.org/downloads/>`_
           * `doku <http://win-builds.org/doku.php>`_
           * `msys2 <https://www.msys2.org/#installation>`_
       * Linux
       * Android
           * `Termux <https://play.google.com/store/apps/details?id=com.termux&hl=en&pli=1>`_


    * `clang <https://clang.llvm.org/>`_
    * `visualstudio <https://visualstudio.microsoft.com/downloads/>`_
    * `Other Tools <https://isocpp.org/get-started>`_


    .. code:: sh
        :number-lines:

        cd folder_of_code
        g++ code1.cpp
        ./a.out

        g++ code1.cpp -o code1.o
        ./code1.o

        # Termux

        pkg install gcc
        pkg install g++

.. slido:: Editors and IDE
   :class: t2c

    * `geany <http://www.geany.org>`_
    * vi
        * `Lazyvim <https://lazyvim.github.io>`_
        * `nvchad <https://nvchad.com>`_
    * `mc <https://midnight-commander.org/>`_
    * `kate <http://kate-editor.org>`_
    * `visualstudio <https://code.visualstudio.com/download>`_
    * `notepad++ <http://www.notepad-plus-plus.org>`_

    #. `Zed <https://zed.dev>`_
    #. `Dev-Cpp <https://www.embarcadero.com/free-tools/dev-cpp>`_
    #. `codeblocks <http://www.codeblocks.org>`_
    #. `Qt Creator <http://qt-project.org>`_
    #. `kdevelop <https://apps.kde.org/kdevelop/>`_
    #. `cbuilder <http://www.embarcadero.com/products/cbuilder>`_
    #. `CLion <https://www.jetbrains.com/clion/>`_
    #. `Visual Studio Express <http://www.microsoft.com/visualstudio/eng/products/visual-studio-express-products>`_
    #. `xcode <https://developer.apple.com/xcode/>`_

    .. :

        *  `Ch http://www.softintegration.com
        *  `DevCpp: http://www.bloodshed.net/devcpp.html
        #. `orwelldevcpp <http://sourceforge.net/projects/orwelldevcpp>`_

.. slido:: Other Tools

    * `git <https://git-scm.com/>`_
    * https://gitlab.com/yoosofan_course/Farsi_gitlab_guide

        .. code:: sh
            :number-lines:

            git config --global user.name "نام و نام خانوادگی شما"
            git config --global user.email "رایانامه‌ی شما"

        * https://github.com/yoosofan/slide

        .. code:: sh

            git clone https://github.com/yoosofan/slide.git

        .. code:: sh

            cd slide
            git pull origin main

    * https://portableapps.com

.. slido:: Standard Library

    * https://en.wikipedia.org/wiki/C_standard_library
    * https://www.tutorialspoint.com/c_standard_library/index.htm
    * https://en.wikibooks.org/wiki/C_Programming/Standard_libraries
    * https://en.cppreference.com/w/c/header

    C++

.. slido::

    * https://en.wikipedia.org/wiki/C%2B%2B_Standard_Library
    * https://en.wikipedia.org/wiki/C%2B%2B
    * https://en.wikipedia.org/wiki/C%2B%2B_Standard_Library
    * https://www.programiz.com/cpp-programming/library-function
    * https://en.cppreference.com/w/cpp/header
    * https://www.tutorialspoint.com/cpp_standard_library/index.htm

.. slido:: Initialization and Assignment
   :class: t2c

    .. include:: cpp/src/c2cpp04_variable.c
        :code: cpp
        :number-lines:

    .. include:: cpp/src/c2cpp04_variable.cpp
        :code: cpp
        :number-lines:

.. slido:: const instead of define
   :class: t2c

    .. include:: cpp/src/c2cpp04_variable02.c
        :code: cpp
        :number-lines:
        :end-line: 20

    .. include:: cpp/src/c2cpp04_variable02.c
        :code: cpp
        :number-lines: 20
        :start-line: 20

.. slido:: Cin & cout

    .. include:: cpp/src/c2cpp04_cout.cpp
        :code: cpp
        :number-lines:
        :class: ltr

.. slido::

    .. include:: cpp/src/c2cpp04_cout_std.cpp
        :code: cpp
        :number-lines:
        :class: ltr

.. slido::
   :class: t2c

    Struct name C

    Struct name C++

    .. include:: cpp/src/c2cpp22_struct01.c
        :code: cpp
        :number-lines: 2
        :start-line: 1
        :end-line: 28

    .. include:: cpp/src/c2cpp22_struct01.cpp
        :code: cpp
        :number-lines: 2
        :start-line: 3
        :end-line: 28

.. slido::
   :class: t2c

    .. include:: cpp/src/c2cpp22_struct02.c
        :code: cpp
        :number-lines: 2
        :start-line: 2
        :end-line: 28

    .. include:: cpp/src/c2cpp22_struct02.cpp
        :code: cpp
        :number-lines: 3
        :start-line: 3
        :end-line: 29

.. slido::
   :class: t2c

    .. include:: cpp/src/c2cpp22_struct02.c
        :code: cpp
        :number-lines: 28
        :start-line: 28
        :end-line: 58

    .. include:: cpp/src/c2cpp22_struct02.cpp
        :code: cpp
        :number-lines: 29
        :start-line: 29
        :end-line: 60

.. slido::
   :class: t2c

    struct c

    struct cpp

    .. include:: cpp/src/c2cpp22_struct02.c
        :code: cpp
        :number-lines:
        :class: ltr
        :start-line: 28

    .. include:: cpp/src/c2cpp22_struct02.cpp
        :code: cpp
        :number-lines:
        :class: ltr
        :start-line: 28

.. slido::
   :class: t2c

    simple cout (print_date)

    multiple output (print_date)

    .. include:: cpp/src/cout12_multiple_output.cpp
        :code: cpp
        :number-lines:
        :class: ltr

    .. include:: cpp/src/cout14_multiple_output.cpp
        :code: cpp
        :number-lines:
        :class: ltr

.. slido::
   :class: t2c

    simple cout (print_date)

    multiple output (print_date)

    .. include:: cpp/src/cout14_multiple_output.cpp
        :code: cpp
        :number-lines:
        :class: ltr

    .. include:: cpp/src/cout16_multiple_output.cpp
        :code: cpp
        :number-lines:
        :class: ltr

.. slido::
   :class: t2c

    `\\n`

    endl

    .. include:: cpp/src/cout16_multiple_output.cpp
        :code: cpp
        :number-lines:
        :class: ltr

    .. include:: cpp/src/cout18_endl.cpp
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

.. slido::
   :class: t2c

    different name

    function signature

    .. include:: cpp/src/c2cpp42_function_signature02.cpp
        :code: cpp
        :number-lines:
        :class: ltr
        :start-line: 0
        :end-line: 29

    .. include:: cpp/src/c2cpp42_function_signature04.cpp
        :code: cpp
        :number-lines:
        :class: ltr
        :start-line: 0
        :end-line: 29

.. slido::
   :class: t2c

    Same signature

    Error

    .. include:: cpp/src/c2cpp42_function_signature06_error.cpp
        :code: cpp
        :number-lines:
        :class: ltr
        :start-line: 0
        :end-line: 29

    .. include:: cpp/src/c2cpp42_function_signature06_error.txt
        :code: console
        :number-lines:
        :class: ltr
        :start-line: 0
        :end-line: 29

.. slido:: function default values
   :class: t2c

    .. code:: cpp
        :number-lines:

        void point(int x = 3, int y = 4);

        point(1,2); // calls point(1,2)
        point(1);   // calls point(1,4)
        point();    // calls point(3,4)

    .. code:: cpp
        :number-lines:

        int sum(int x, int y, int z=0, int w=0)
        {return (x + y + z + w);}

        int main(){
          cout << sum(10, 15) << endl;
          cout << sum(10, 15, 25) << endl;
          cout << sum(10, 15, 25, 30) << endl;
        }

    .. :

        * https://en.cppreference.com/w/cpp/language/default_arguments
        * https://www.geeksforgeeks.org/default-arguments-c/

.. slido:: Errors Default value for parameters(I)

    .. include:: cpp/src/c2cpp53_function_default_value.cpp
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

.. slido:: Errors Default value for parameters(II)

    .. include:: cpp/src/c2cpp55_function_default_value.cpp
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

.. slido:: Obeject Oriented, Encapsulation(I)

    * Functions in Struct
    * Object Oriented Programming
    * Methods (Functions in struct)

.. slido::

    .. list-table::

      * - .. include:: src/student/student122.cpp
            :code: cpp
            :number-lines: 3
            :class: ltr
            :start-line: 2

        - |nbsp|

        - .. include:: src/student/student124.cpp
            :code: cpp
            :number-lines: 3
            :class: ltr
            :start-line: 2
            :end-line: 49

.. slido:: Encapsulation(II)
   :class: t2c

    .. include:: cpp/src/struct_method204.cpp
        :code: cpp
        :number-lines: 3
        :class: ltr
        :start-line: 2
        :end-line: 28

    .. include:: cpp/src/struct_method208.cpp
        :code: cpp
        :number-lines: 3
        :class: ltr
        :start-line: 2
        :end-line: 28

.. slido:: Encapsulation(III)
   :class: t2c

    .. include:: cpp/src/struct_method214.cpp
        :code: cpp
        :number-lines: 3
        :class: ltr
        :start-line: 2
        :end-line: 30

    .. include:: cpp/src/struct_method218.cpp
        :code: cpp
        :number-lines: 3
        :class: ltr
        :start-line: 2
        :end-line: 30

.. slido:: Encapsulation(IV)
   :class: t2c

    .. include:: cpp/src/mycomplex/00_one_file/complexCls01.cpp
        :code: cpp
        :number-lines: 3
        :start-line: 2
        :end-line: 30

    .. include:: cpp/src/mycomplex/00_one_file/complexCls02.cpp
        :code: cpp
        :number-lines: 3
        :start-line: 2
        :end-line: 30

.. slido:: Attribute Default Value(I)
   :class: t2c

    .. include:: cpp/src/mycomplex/00_one_file/complexCls02.21.cpp
        :code: cpp
        :number-lines: 3
        :start-line: 2
        :end-line: 34

    .. include:: cpp/src/mycomplex/00_one_file/complexCls02.22.cpp
        :code: cpp
        :number-lines: 3
        :class: ltr
        :start-line: 2
        :end-line: 34

.. slido:: Attribute Default Value(II)
   :class: t2c

    .. include:: cpp/src/struct_method208.cpp
        :code: cpp
        :number-lines: 3
        :start-line: 2
        :end-line: 28

    .. include:: cpp/src/struct_method210.cpp
        :code: cpp
        :number-lines: 3
        :start-line: 2
        :end-line: 28

.. slido:: Attribute Default Value(III)
   :class: t2c

    .. include:: cpp/src/struct_method222.cpp
        :code: cpp
        :number-lines: 2
        :class: ltr
        :start-line: 1
        :end-line: 34

    .. include:: cpp/src/struct_method224.cpp
        :code: cpp
        :number-lines: 2
        :class: ltr
        :start-line: 1
        :end-line: 34

.. slido:: MyArray Struct(I)
   :class: t2c

    .. include:: cpp/src/myArray/100400.cpp
        :code: cpp
        :number-lines:

    .. include:: cpp/src/myArray/100410.cpp
        :code: cpp
        :number-lines:

.. slido:: MyArray Struct(II)
   :class: t2c

    .. include:: cpp/src/myArray/100420.cpp
      :code: cpp
      :number-lines:
      :class: ltr

    .. include:: cpp/src/myArray/100422.cpp
      :code: cpp
      :number-lines:
      :class: ltr

.. slido:: MyArray Struct(III) - Error
   :class: t2c

    .. include:: cpp/src/myArray/100420.cpp
      :code: cpp
      :number-lines:
      :class: ltr

    .. include:: cpp/src/myArray/100423.22.cpp
      :code: cpp
      :number-lines:
      :class: ltr substep

    .. class:: substep

    * Check Array Bounds

.. slido:: Error in Action

    .. include:: cpp/src/myArray/100423.33.cpp
      :code: cpp
      :number-lines:
      :class: ltr

.. slido:: Order of properties and methods is irrelevant in struct
   :class: t2c

    .. include:: cpp/src/myArray/100423.22.cpp
      :code: cpp
      :number-lines:
      :class: ltr

    .. include:: cpp/src/myArray/100423.44.cpp
      :code: cpp
      :number-lines:
      :class: ltr

.. slido:: MyArray Struct(IV) Const(I)
   :class: t2c

    .. include:: cpp/src/myArray/100423.22.cpp
      :code: cpp
      :number-lines:
      :class: ltr

    .. include:: cpp/src/myArray/100424.cpp
      :code: cpp
      :number-lines:
      :class: ltr

.. slido:: MyArray Struct(V) Const(II)
   :class: t2c

    .. include:: cpp/src/myArray/100424.cpp
      :code: cpp
      :number-lines:
      :class: ltr

    .. include:: cpp/src/myArray/100426.22.cpp
      :code: cpp
      :number-lines:
      :class: ltr

    ---

    END
