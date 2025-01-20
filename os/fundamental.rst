.. meta::
   :http-equiv=Content-Language: fa

..  section-numbering::

.. role:: ltr
    :class: ltr

===================================================
مبانی اولیه سیستم عامل
===================================================

یک رایانه ساده
========================================================================================

وقفه

cpu interrupt diagram
https://www.researchgate.net/figure/Flowchart-of-Executing-Interrupt-Instruction_fig1_327053482
http://users.ece.utexas.edu/~valvano/Volume1/E-Book/C12_Interrupts.htm
https://www.eeeguide.com/polling-and-interrupts/
http://www.science.unitn.it/~fiorella/guidelinux/tlk/node81.html
https://doc.micrium.com/display/os305/Handling+CPU+Interrupts
https://tldp.org/LDP/tlk/dd/interrupts.html


----

کاری که انجام می‌دهیم این است که فرض می‌کنیم با رایانهٔ بسیار ساده‌ای با کمترین دستگاه‌های ورودی و خروجی ممکن، چگونه می‌توان به تابع‌های کتابخانه‌ای دسترسی داشت چگونه فرآیندها ساخته می‌شوند و اجرا می‌شوند تا گام به گام به نیازها آشنا شویم و نکتهٔ خیلی مهم‌تر این که بهتر بدانیم چه بخشی سخت افرازی است و چه بخشی نرم‌افزاری است. 
دقیق‌تر بنویس چه چیزی را متوجه نمی‌شوی و همان را بپرس نه این که کلی بنویس
در چند جلسهٔ آینده به مباحثی می‌رسیم که دقیقا در همهٔ کتاب‌های دست کم چهار دههٔ گذشته در زمینهٔ سیستم عامل گفته شده است و به سادگی می‌توانید صدها اسلاید و توضیح برای آن روی اینترنت بیابید و آن قدر مباحث جا افتاده‌ای هستند که تقریبا نمی‌شود تغییر چندانی در آن انجام داد و باید همان‌ها را گفت و حتی برخی از آنها را خواهم خواست تا خودتان پیش از درس دادن بروید و بنویسید و در همان جلسه‌ای که بناست توضیح داده شود بیاورید تا فقط اشکال‌های‌تان برطرف شود زیرا تنوعی به آن نمی‌توان داد و پیاده سازی اغلب بخش‌هایی که در این درس گفته می‌شود بسیار زمان‌بر است و نیاز به کد نویسی بسیار دقیق‌تری دارد برای نمونه می توانید ساده ترین boot loader های متن باز را بیابید و بررسی کنید آیا می‌توانید به سادگی از طرز کار دقیق آنها سر در بیاورید چه رسد به این که بازنویسی کنید. البته این کار برای‌تان شدنی است ولی گمان نکنم برای‌تان ارزش داشته باشد مگر این که بخواهید لینوس توروالدو شوید که تازه ایشان هم فقط بخشی از هستهٔ اولیهٔ لینوکس را بر پایهٔ کد آمادهٔ minix‌ آماده کرده است و لینوکس امروزی هیچ شباهتی با آنچه ایشان نوشت ندارد.
بنابراین با دنبال کردن بحث‌ها به جایی می‌رسیم که متوجه می‌شوید هر کدام بحث‌هایی که در ادامهٔ درس خواهد آمد دقیقا چرا نیاز است بررسی شود و چرا این قدر دردسر ساز است و گرنه درس تبدیل به تعدادی فرمول و روش می‌شود که فقط برای تست زدن یا حل کردن مسائل متداول به شکل کورکورانه به درد بخورد تبدیل می‌شود و هیچ نیازی را از زندگی کامپیوتری شما حتی در حد آگاهی ساده برآورده نمی‌کند.

----

cpu instruction set bsa

* https://home.adelphi.edu/~siegfried/cs371/371l10.pdf
* https://www.geeksforgeeks.org/computer-organization-basic-computer-instructions/

Simple computer hardware
--------------------------
Build an 8-bit computer from scratch
https://eater.net/8bit/kits
If you’re interested in following along with my 8-bit breadboard computer videos and building your own, I’ve assembled kits that include all of the components I used in the videos, including the Arduino nano (used to program the LED and control EEPROMs) and a 5 volt power supply. It’s a challenging but extremely rewarding project.

8-bit computer update
https://www.youtube.com/watch?v=HyznrdDSSGM

Programming my 8-bit breadboard computer
https://www.youtube.com/watch?v=9PPrrSyubG0

Stepping through a program on the 8-bit breadboard computer
https://www.youtube.com/watch?v=35zLnS3fXeA

Build an 8-bit computer from scratch
https://eater.net/8bit/clock

Programming my 8-bit breadboard computer
https://www.youtube.com/watch?v=9PPrrSyubG0

https://www.youtube.com/c/BenEater/videos

Programming Fibonacci on a breadboard computer
https://www.youtube.com/watch?v=a73ZXDJtU48

Comparing C to machine language
https://www.youtube.com/watch?v=yOyaJXpAYZQ

Old computers in action
-----------------------------
The IBM 1401 compiles and runs FORTRAN II
https://www.youtube.com/watch?v=uFQ3sajIdaM

https://youtu.be/_j544ELauus
1958 FACOM 128B Japanese Relay Computer, still working!

Simple computer simulation
-----------------------------
https://github.com/jeaniehandler/OS
https://github.com/Naheel-Azawy/Simple-Computer-Simulator
https://web.njit.edu/~carpinel/Applets.html
http://www.science.smith.edu/dftwiki/index.php/IBooks
http://www.science.smith.edu/dftwiki/index.php/Simple_Computer_Simulator_Instruction-Set
http://euler.vcsu.edu/curt.hill/Computer.html


بخش‌های درونی یک فرآیند در حالت کلی
-----------------------------------------------------------------------------------------------------
.. image:: img/memory/memory_precess_addressing_parts.png
   :align: center


http://www.sharetechnote.com/html/DE_Modeling_Example_ElectricCircuit.html
http://faculty.bard.edu/belk/math213s14/ApplicationsOfDifferentialEquations.pdf
https://www.mathtutordvd.com/members/Applications_of_Differential_Equations_Circuits_Part_1.cfm
https://en.wikipedia.org/wiki/Differential_equation
https://www2.humusoft.cz/www/papers/tcb10/065_liska.pdf



مشخص شدن آدرس‌های حافظهٔ یک فرایند از زمان نوشته شدن برنامه تا زمان اجرای فرآیند
-----------------------------------------------------------------------------------------------------

.. image:: img/memory/memory_program_address_binding.png
   :align: center

.. image:: img/memory/memory_linking_loading_scenario.png
   :align: center
   :scale: 90%


address binding, loader
-----------------------------------------------------------------------------------------------------

.. image:: img/memory/memory_address_binding_loader.png
   :align: center
   :scale: 90%


address binding, linker
-----------------------------------------------------------------------------------------------------

.. image:: img/memory/memory_address_binding_linker.png
   :align: center
   :scale: 90%


address binding, absolute and relocate loader
-----------------------------------------------------------------------------------------------------
.. image:: img/memory/memory_absolute_relocate_loader.png
   :align: center
   :scale: 90%


چگونگی کارکرد پیوند زدن تابع‌ها از پرونده‌های گوناگون
-----------------------------------------------------------------------------------------------------

.. image:: img/memory/memory_linking_function.png
   :align: center


تخصیص حافظهٔ پیوسته به فرآیندها
===================================================
بخش‌بندی ثابت حافظه
-------------------------------------------------------------------------------------------------------------
.. image:: img/memory/memory_fixed_partitioning.png
   :align: center


تخصیص حافظه به فرآیندها در حالت بخش‌بندی ثابت حافظه
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. image:: img/memory/memory_fixed_allocation.png
   :align: center


تکه تکه شدن (پراکندگی) داخلی حافظه Internal Memory Fragmentation
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

به کارگیری حافظهٔ نسبی برای نگهداری مکان چندین فرآیند در حافظه
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. image:: img/memory/base_limit_register.png
   :align: center

حفاظت از حافظه به کمک ثبات‌های پایه و حد
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. image:: img/memory/hardware_address_protection.png
   :align: center

بخش‌بندی پویای حافظه
------------------------------------------------------------------------------------------
شمارندهٔ برنامه و فرآیندهای درون حافظه
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^


.. image:: img/memory/memory_management_pc.png
   :align: center

ارتباط میان آدرس فیزیکی و آدرس منطقی در آدرس دهی نسبی به کمکِ واحد مدیریت حافظه (MMU)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. image:: img/memory/relocation_register_mmu.png
   :align: center



حافظهٔ فرآیندها در سیستم عامل CTSS
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. image:: img/memory/memory_of_CTSS.png
   :align: center


اثر به کارگیری حافظهٔ پویا
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. image:: img/memory/memory_effect_of_dynamic_partitioning.png
   :align: center


برگزیدن فضای آزاد برای فرآیند تازه وارد
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

*  اولین برازش(First Fit)
*  بهترین برازش(Best Fit)
*  بدترین برازش(Worst Fit)
*  درپی برازش (برازش بعدی Next Fit)



.. image:: img/memory/memory_select_part_for_allocation.png
   :align: center




تکه تکه شدن (پراکندگی یا پارگی) خارجی External Fragmentation
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^


حافظهٔ پویای رفاقتی Buddy system
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. image:: img/memory/memory_buddy_system1.png
   :align: center



.. image:: img/memory/memory_buddy_system2.png
   :align: center
   :scale: 90%

الگوریتم اجرا


.. image:: img/memory/memory_buddy_system3.png
   :align: center

تمرین:
چرا صفحه‌بندی دو سطحی و بیشتر نیازمندیم؟

References:
==================================================

* `<https://stackoverflow.com/questions/18550370/calculate-the-effective-access-time>`_
* `<http://os-book.com/>`_
* https://en.wikipedia.org/wiki/Paging

.. comments:

    * `<https://en.wikipedia.org/wiki/Page_(computer_memory)>`_
    * http://blog.cs.miami.edu/burt/2012/10/31/virtual-memory-pages-and-page-frames/
    * `<https://www.tldp.org/LDP/tlk/mm/memory.html>`_
    * https://www.geeksforgeeks.org/operating-system-paging/
    * https://samypesse.gitbooks.io/how-to-create-an-operating-system/Chapter-8/
    * https://www.cse.iitb.ac.in/~mythili/teaching/cs347_autumn2016/notes/07-memory.pdf
    * https://www.kernel.org/doc/html/latest/admin-guide/mm/index.html
    * operating systems paging kernel

.. comments:

   rst2html.py memory.rst memory.html --stylesheet=../../tools/farsi.css,html4css1.css


