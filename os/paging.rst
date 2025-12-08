:data-transition-duration: 1000
:skip-help: true
:css: ./style.css ./memory.css
:substep: true
:data-width: 1024
:data-height: 768

.. title: Operating Systems - Paging  (By Ahmad Yoosofan)

:slide-numbers: true

.. role:: ltr
    :class: ltr

.. role:: rtl
    :class: rtl

Operating Systems
==============================
Paging
-------
Ahmad Yoosofan

University of Kashan

----

.. class:: rtl-h1

    شکل سادهٔ صفحه‌بندی

.. image:: img/memory/paging_model.png
   :align: center

----

.. :

    ----

    .. image:: img/memory/memory_paging_model_address.png
       :align: center

    ----

    .. image:: img/memory/memory_paging_from_disk.png
       :align: center
       :scale: 70%

    ----

    سخت‌افزار صفحه‌بندی

.. image:: img/memory/paging_hardware.png
   :align: center
   :height: 300px

.. class:: substep

  #. Number of bits of Addrress  related to Maximum supported memory by this computer(cpu and motherboard)
  #. Number of bits of Addrress  =  log2(Maximum supported memory)
  #. If max supported memory = 32 words then number of bits needed for addrress ?
  #. 32 = 2 ^ 5, :math:`n = log_2(m)` , m is number of bytes or words
  #. 5 = log2(32)
  #. if p = 2, d = 3 then the size of each frame or page is ?
  #. 2 ^ 3 = 8
  #. Maximum number of Frames?
  #. 2 ^ 2  = 4

----

.. class:: rtl-h1

    بخش‌بندی ثبات آدرس در حافظهٔ صفحه‌بندی شده

.. image:: img/memory/page_number_offset.png
   :align: center

* Frame 4k then number_bits(d) == 12
* Frame 1k then number_bits(d) == 10
* Frame 16k then number_bits(d) == 14

Maximux memory supported by cpu
------------------------------------
* 1 MB ==> number_of_bit(Address register) == 20
    * Frame 4k ==> d == 12 and p == 8
    * Frame 1k ==> d == 10 and p == 10 // wrong?

----

:class: t2c

.. :

  .. class:: rtl-h1

      یک کامپیوتر با ۳۲ بایت حافظه و صفحه‌های چهار بایتی

Consider a computer with maximum 16 words
==========================================
#. Draw Memory Bytes
#. d = 2
#. Draw Memory Frames
#. some First Frames for os
#. Put a process into Memory (not continuous or in order)
#. Fill page table
#. Convert a Logical Addfress to Physical Address
#. Put another process into Memory

.. container::

  ..  csv-table::
    :header-rows: 1
    :class: smallerelementwithfullborder

    "0000","0001 ","0010 ","0011 ","0100 ","0101 ","0110","0111","1000","1001","1010 ","1011","1100","1101","1110 ","1111"
    0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15

  .

  ..  csv-table::
    :header-rows: 1
    :class: smallerelementwithfullborder

    "00 ","01 ","10 ","11 "
    0,1,2,3

  00

  ..  csv-table::
    :header-rows: 1
    :class: smallerelementwithfullborder

    "00 ","01 ","10 ","11 "
    4,5,6,7

  01

  ..  csv-table::
    :header-rows: 1
    :class: smallerelementwithfullborder

    "00 ","01 ","10 ","11 "
    8,9,10,11

  10

  ..  csv-table::
    :header-rows: 1
    :class: smallerelementwithfullborder

    "00 ","01 ","10 ","11 "
    12,13,14,15

  11

----

.. class:: rtl-h1

    یک کامپیوتر با حافظهٔ ۳۲ بایت و اندازه‌های قاب  ۸ بایتی و یک فرآیند

d = 3, p = 2

p0 11 bytes


---

.. class:: rtl-h1

    یک کامپیوتر با حافظهٔ ۱۲۸ بایتی و صفحه‌های ۸ بایتی

---

.. image:: img/memory/memory_paging_typical_page_table_entry.jpg
   :align: center

----

.. class:: rtl-h1

    یک حافظهٔ ۳۲ بایتی با صفحه‌های ۴ بایتی

.. image:: img/memory/paging_example_32_bytes_memory.png
   :align: center

----

.. class:: rtl-h1

    تغییرات فضاهای آزاد پیش و پس از تخصیص حافظه به یک فرآیند

.. image:: img/memory/paging_free_frames_before_after.png
   :align: center

----

.. class:: rtl-h1

    تغییرات حافظه برای چند فرآیند

.. image:: img/memory/memory_paging_process.png
   :align: center

----

.. image:: img/memory/memory_paging_process_page_tables.png
   :align: center

----

.. class:: rtl-h1

    تبدیل آدرس منطقی به آدرس فیزیکی در حافظهٔ صفحه‌بندی شده

.. image:: img/memory/memory_paging_logical_address_to_physical_address.png
   :align: center

----

.. image:: img/memory/memory_paging_logical_address_to_physical_address_detail.png
   :align: center

----

Address Translation
========================
.. image:: img/memory/memory_paging_address_translation.png
   :align: center

----

:class: t2c

Process and Page Table
============================
.. image:: img/memory/page_table_in_a_frame.png

.. image:: img/memory/page_table_in_a_frame2.png

----

PTBR
=======
.. image:: img/memory/paging_hardware_with_TLB_ptbr.png
   :align: center
   :height: 550px

----

TLB
======
.. image:: img/memory/paging_hardware_with_TLB.png
   :align: center

----

Flowchart of TLB miss
=========================
.. image:: img/memory/paging_hardware_TLB_miss.png
   :align: center
   :height: 550px

----

Paging Memory Access
=====================
.. image:: img/memory/memory_paging_page_table_and_cache.jpg
   :align: center

----

.. class:: rtl-h1

    اشتراک گذاری در حافظهٔ صفحه‌بندی شده

.. image:: img/memory/memory_paging_share_pages.png
   :align: center
   :height: 500px

----

.. image:: img/memory/paging_sharing_code.png
   :align: center

----

.. class:: rtl-h1

    سلسه مراتب حافظه

.. image:: img/memory/memory_hierarchy.png
   :align: center

----

Memory Access
================
.. image:: img/memory/memory_effect_of_cache.png
   :align: center

----

Effective Access Time
=========================
* :math:`t_t` (access Time of TLB) : :rtl:`زمان دسترسی به حافظه‌ی نهان جدول صفحه`
* :math:`t_c` (access Time of Cache): :rtl:`زمان دسترسی به حافظه‌ی نهان`
* :math:`t_m` (access Time of Memory): :rtl:`زمان دسترسی به حافظه‌ی اصلی`
* :math:`h_t` (Hit ratio of TLB): :rtl:`ضریب اصابت به حافظه‌ی نهان جدول صفحه`
* :math:`h_c` (Hit ratio of Cache): :rtl:`ضریب اصابت به حافظه‌ی نهان`

.. math::

  EAT = table +  memory

  table =  h_t * t_t + ( 1 - h_t ) * ( t_t + t_m )

  memory = h_c * t_c + ( 1 - h_c ) * ( t_c + t_m )

  EAT =  h_t * t_t + ( 1 - h_t ) * ( t_t + t_m ) + h_c * t_c + ( 1 - h_c ) * ( t_c + t_m )

----

.. class:: rtl-h2

    زمان دسترسی مؤثر را برای پردازنده‌ای با حافظهٔ صفحه‌بندی شده حساب کنید اگر زمان دسترسی به حافظهٔ نهان جدول صفحه برابر ۱ نانو ثانیه باشد و زمان دسترسی به حافظهٔ نهان ۵ نانوثانیه باشد و زمان دسترسی به حافظه برابر ۱۰۰ نانوثانیه باشد و ضریب اصابت حافظهٔ نهان جدول صفحه برابر با ۹۵ درصد و ضریب اصابت به حافظهٔ نهان ۹۰ درصد باشد.


* :math:`t_t` = 1,  :math:`t_c` = 5, :math:`t_m` = 100, :math:`h_t` = 0.95, :math:`h_c` = 0.90

.. math::

    EAT = table +  memory

    table =  h_t * t_t + ( 1 - h_t ) * ( t_t + t_m )

    table = 0.95 * 1 + 0.05 * (1 + 100) = 0.95 + 5.05 = 6

    memory = h_c * t_c + ( 1 - h_c ) * ( t_m + t_c )

    memory = 0.90 * 5 + 0.1 * (5 + 100) = 4.5 + 10.5 = 15

    EAT = 6 + 15 = 21ns

----

.. class:: rtl-h1

زمان دسترسی مؤثر = `زمان دسترسی به جدول صفحه + زمان دسترسی به حافظه`

.. class:: rtl-h2

    با فرض برابر بودن نسبت‌های اصابت و زمان‌های یکسان برای دسترسی به حافظهٔ نهان  و حافظهٔ TLB خواهیم داشت

.. math::
  :class: ltr

  EAT = 2 * (h * t_c + ( 1 - h ) * ( t_c + t_m ))


.. math::

   EAT = 2 * ( h_c * t_c + (1-h_c) * (t_m + t_c) )

   EAT = 2 * ( h_c * t_c + t_m + t_c - h_c * t_m - h_c * t_c )

   EAT = 2 * ( t_c + (1 - h_c) * t_m )

----

.. class:: rtl-h1

    حفاظت از حافظهٔ صفحه‌بندی شده

.. image:: img/memory/paging_valid_invalid.png
   :align: center

----

References(I)
==================================================
* http://os-book.com
* https://en.wikipedia.org/wiki/Paging
* Sean K. Barker (https://tildesites.bowdoin.edu/~sbarker/)
* https://en.wikipedia.org/wiki/Page_(computer_memory)
* http://blog.cs.miami.edu/burt/2012/10/31/virtual-memory-pages-and-page-frames/
* https://www.tldp.org/LDP/tlk/mm/memory.html
* https://www.geeksforgeeks.org/operating-system-paging/
* https://samypesse.gitbooks.io/how-to-create-an-operating-system/Chapter-8/
* https://www.cse.iitb.ac.in/~mythili/teaching/cs347_autumn2016/notes/07-memory.pdf
* https://www.kernel.org/doc/html/latest/admin-guide/mm/index.html
* https://web.fe.up.pt/~arestivo/presentation/os-memory/#15
* https://github.com/mor1/ia-operating-systems
* https://slideplayer.com/slide/7084682/

----

References(II)
==================================================
* http://images.bit-tech.net/content_images/2007/11/the_secrets_of_pc_memory_part_1/hei.png
* https://upload.wikimedia.org/wikipedia/commons/c/c2/Write-back_with_write-allocation.svg
* https://www.byclb.com/TR/Tutorials/dsp_advanced/ch1_1_dosyalar/image025.jpg
* https://en.wikipedia.org/wiki/File:Cache,hierarchy-example.svg
* https://tutorialspoint.dev/image/Translation.png
* https://www.cs.princeton.edu/courses/archive/spr11/cos217/lectures/18MemoryMgmt.pdf
* http://harmanani.github.io/classes/csc320/Notes/ch05.pdf
* https://www.cs.princeton.edu/courses/archive/spr11/cos217/lectures/18MemoryMgmt.pdf

----

References(III)
==================================================
* https://www.kernel.org/doc/
* https://www.gatevidyalay.com/wp-content/uploads/2018/11/Translating-Logical-Address-into-Physical-Address-Diagram-Paging-using-TLB-1.png
* https://www.gatevidyalay.com/translation-lookaside-buffer-tlb-paging/
* https://www.gatevidyalay.com/wp-content/uploads/2018/11/Translating-Logical-Address-into-Physical-Address-Diagram-Paging-using-TLB-1.png

----

References(IV)
==================================================
* https://www.gatevidyalay.com/translation-lookaside-buffer-tlb-paging/
* https://codex.cs.yale.edu/avi/os-book/

