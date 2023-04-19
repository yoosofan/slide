:data-transition-duration: 1000
:skip-help: true
:css: ./style.css
:substep: true
:slide-numbers: true

.. role:: ltr
    :class: ltr


----

Introduction
===================
Ahmad Yoosofan

Compiler course

University of Kashan


https://yoosofan.github.io/course/compiler.html

.. :

    ----

    Machine Language
    ===================
    Assembly Language
    --------------------


    ----

    Why Learning Compiler(I)
    =========================
    One of the Most important Software in computer
    -------------------------------------------------
    * Sophisticated Applications cannot be written in Assembly
    * The software engineering could not be created if there was no compiler

----

Compiler Usage
=================
.. class:: rtl substep

* به عنوان کاربر کامپایلر بهتر است ابزار را بشناسیم. پس بهتر می‌توانیم از آن کمک بگیریم
* تئوری همراه با عملی نیاز است.
* یک پروژه متفاوت است
* نرم‌افزار کامپایلر یکی از مهم‌ترین نرم‌افزارهای کامپیوتر هست و هر نرم‌افزاری به کار می‌برید عملا با کامپایلری تولید  شده است.
* به کارگیری سخت‌افزارهای جدید توانایی‌های دستورهای جدید پردازنده‌ها کاملا وابسته به کامپایلر است. شرکت سخت‌افزاری کامپایلر
    * https://www.intel.com/content/www/us/en/developer/tools/oneapi/fortran-compiler.html#gs.oshpmh
    * https://www.intel.com/content/www/us/en/develop/documentation/cpp-compiler-developer-guide-and-reference/top.html
    * https://developer.amd.com/amd-aocc
    * https://developer.amd.com/spack/amd-optimized-c-cpp-compiler
    * https://developer.amd.com/x86-open64-compiler-suite
    * https://developer.nvidia.com/hpc-compilers
    * https://developer.nvidia.com/cuda-llvm-compiler
    * https://docs.nvidia.com/cuda/cuda-compiler-driver-nvcc/index.html

.. :

    خب استاد اگر کامپایلر نباشه قدرت برنامه نویسی ما هم محدود میشه درسته ؟ برای همین اگر کامپایلر های مثل الان نبودن نمیتونستیم چنین برنامه های بزرگی رو حتی تولید کنیم


----

Compiler History
====================
.. class:: substep

* Ada Lovelace
    * https://en.wikipedia.org/wiki/Ada_Lovelace
    * https://www.britannica.com/story/ada-lovelace-the-first-computer-programmer
* Konrad Zuse
    * https://en.wikipedia.org/wiki/Plankalk%C3%BCl
    * https://en.wikipedia.org/wiki/Konrad_Zuse
    * https://people.idsia.ch/~juergen/zuse.html
    * https://www.computer.org/profiles/konrad-zuse
*  Fortran (Formula Translation)


.. :

    https://clrhome.org/asm/
    https://www.asm80.com/onepage/asmz80.html
    https://k1.spdns.de/Develop/Projects/zasm/Distributions/
    https://github.com/Megatokio/zasm
    https://github.com/Megatokio/Libraries
    https://k1.spdns.de/cgi-bin/zasm.cgi
    codevision
    https://www.microchip.com/forums/m432115.aspx
    https://sites.pitt.edu/~rick/
    https://zxn.ru
    https://www.avrfreaks.net/forum/disassemble-hex-file-txt-file-and-reassemble-hex
    https://developer.arm.com/documentation/dui0801/g/Writing-A32-T32-Assembly-Language/Load-immediate-values-using-MOV-and-MVN
    https://www.keil.com/download/
    https://riscv.org/wp-content/uploads/2017/05/riscv-spec-v2.2.pdf
    https://www.cs.cornell.edu/courses/cs3410/2019sp/riscv/interpreter/
    https://iosgods.com/topic/30299-android-armasm-to-hex-converter-online/
    https://gchq.github.io/CyberChef/?recipe=Disassemble_x86()
    https://onlinedisassembler.com
    http://shell-storm.org/online/Online-Assembler-and-Disassembler/?inst=section+.data%0D%0A++++msg+db+"Hello+world%21"%2C+0ah%0D%0A%0D%0Asection+.text%0D%0A++++global+_start%0D%0A%0D%0A_start%3A%0D%0A++++mov+rax%2C+1%0D%0A++++mov+rdi%2C+1%0D%0A++++mov+rsi%2C+msg%0D%0A++++mov+rdx%2C+13%0D%0A++++syscall%0D%0A++++mov+rax%2C+60%0D%0A++++mov+rdi%2C+0%0D%0A++++syscall&arch=x86-32&as_format=inline#assembly
    https://armconverter.com
    https://onecompiler.com/assembly
    https://www.tutorialspoint.com/compile_assembly_online.php
    https://defuse.ca/online-x86-assembler.htm#disassembly
    https://www.mycompiler.io/new/asm-x86_64
    https://www.tutorialspoint.com/assembly_programming/assembly_introduction.htm
    https://en.wikipedia.org/wiki/Assembly_language
    online z80 assembler to hex

    online assembler to hex
    assembly assembler online


    https://en.wikipedia.org/wiki/Fortran
    https://upload.wikimedia.org/wikipedia/commons/f/f3/Motorola_6800_Assembly_Language.png
    https://en.wikipedia.org/wiki/Assembly_language
    https://en.wikipedia.org/wiki/History_of_programming_languages
    https://en.wikipedia.org/wiki/Plankalkül

----

.. class:: rtl substep

* خانه سرد است
* خانه گرم است
* خ ا ن ه گ ر م  ا س ت
* خانه گرم است
* او به خانه می‌رفت.
* او به خانه میرفت.
* او به خانه می رفت.

----

تحلیل‌گر لغوی
=======================

.. code:: asm

    mov A,B
    mov B,C

    mov A,B\nmov B,C

    mov
    A
    ,
    B
    \n


* Lexical Analyser
* Tokenizer (token)

.. code:: cpp

    A = B + 4

----

.. code:: cpp

    A = B 4;

    A = B + ;

    if(A <= B)

    If
    (
    A
    <=
    B
    )

    White space

    ‘ ‘ ‘\t’ ‘\n’

    \n

----

Syntax Analyser
=======================
Parser
-----------
.. class:: rtl substep

* تجریه کننده
* تحلیل‌گر نحوی
* او خانه را خورد.
* او به خانه رفتم

----

Semantic Analysis
========================
تحلیل‌گر معنایی
-------------------------
.. class:: rtl

* او خانه را خورد.

.. code:: cpp

  count ++;

.. code:: cpp

  f1(2);

.. code:: cpp

  int a = 2;
  double x=4, y;
  ......
  y=a+x;

.. code:: cpp

  y=double(a)+x;

----


کامپایلر
=========
.. class:: substep rtl

* تحلیل‌گر لغوی
* تحلیل‌گر نحوی
* تحلیل‌گر معنایی
* تولید کد میانی
* بهینه‌سازی کد میانی
* تولید کد اسمبلی
* بهینه‌سازی کد اسمبلی
* تولید زبان ماشین

----

.. image:: img/sa/frontend_backend15.png

.. image:: img/sa/frontend_backend22.png

.. :

  https://files.adacore.com/gnat-book/node5.htm
  https://www.tutorialspoint.com/compiler_design/compiler_design_architecture.htm
  https://slideplayer.com/slide/7333212/
  https://slideplayer.com/slide/7333212/


----

مفسر
===========
.. class:: substep rtl

* تحلیل‌گر لغوی
* تحلیل‌گر نحوی
* تحلیل‌گر معنایی
* تولید کد میانی
* بهینه‌سازی کد میانی
* اجرا کننده کد میانی

----

END

