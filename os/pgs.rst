:data-transition-duration: 1000
:skip-help: true
:css: ./style.css ./memory.css
:substep: true
:data-width: 1024

.. title: Operating Systems - Memory paging, segmentation and more (By Ahmad Yoosofan)

:slide-numbers: true

.. role:: ltr
    :class: ltr

.. role:: rtl
    :class: rtl

Operating Systems
==============================
Two and more level paging, segmentation and more
-------------------------------------------------
Ahmad Yoosofan

University of Kashan

----

Frame Size(I)
=============
.. class:: rtl-h2

    کوچک یا بزرگ بودن اندازهٔ صفحه‌ها (همان قاب‌های حافظه) بر روی موضوع‌های گوناگونی اثر دارد


.. class:: substep

    1

    * Max memory supported : 64 byte = 2 ^ 6
    * frame size = page table 2 byte
    * 2 ^ 6 / 2 ^1 = 2 ^ 5 = 32
    * ?

.. class:: substep

    2

    * Max memory supported : 64 byte = 2 ^ 6
    * frame size = page table 4 byte
    * 2^6 / 2^2 = 2^4 = 16
    * ?

.. class:: substep

    3

    * Max memory supported : 64 byte = 2 ^ 6
    * frame size = page table 8 byte
    * 2^6 / 2^3 = 2^3 = 8
    * ? , Maximum Number of Processes

----

Frame Size(II)
==============
.. class:: substep

    1

    * 32 bit address
    * 1024 size of frame?
    * 32 - 10 = 22
    * 2^22 Frame
    * 2^22 page table entry
    * Problem ?

.. class:: substep

    2

    * 32 bit address
    * 2^20 size of frame?
    * 32 - 20 = 12
    * 2^12 = 4096 Frame
    * ? , Maximum Number of Processes

----

.. class:: rtl-h1

    صفحه‌بندی دو سطحی

.. image:: img/memory/paging_two_level.png
   :align: center

.. :

    access time


----

.. class:: rtl-h1

    آدرس‌دهی در صفحه‌بندی دو سطحی

.. image:: img/memory/paging_address_translation_32bit.png
   :align: center

.. image:: img/memory/paging_two_level_32bit_address.png
   :align: center

----

.. image:: img/memory/memory_paging_Address_Translation_in_a_Two_Level_Paging_System.png
   :align: center
   :scale: 90%

----

.. image:: img/memory/memory_paging_Two_Level_Hierarchical_Page_Table.png
   :align: center

----


.. class:: rtl-h1

    صفحه‌بندی دو سطحی ۶۴ بیتی

.. image:: img/memory/paging_two_level_64bit.png
   :align: center

----

.. class:: rtl-h1

    صفحه‌بندی سه سطحی ۶۴ بیتی

.. image:: img/memory/paging_three_level_64bit_address.png
   :align: center

----

.. class:: rtl-h1

    صفحه‌بندی با جدول صفحهٔ معکوس

.. image:: img/memory/inverted_page_table.png
   :align: center

----

.. class:: rtl-h1

    صفحه‌بندی با جدول صفحهٔ معکوس با تابع درهم‌سازی


.. image:: img/memory/memory_paging_Inverted_Page_Table_Structure.png
   :align: center

----

Windows 10 Inverted Page Table on Intel Itanium 64 bit platform
====================================================================================
.. image:: img/memory/Physical_and_Virtual_Memory_in_Windows_10_64bit_processors_inverted_page_table.png
    :width: 780px

----

.. class:: rtl-h1

  قطعه‌بندی (segmentation)

.. image:: img/memory/memory_segmentation_logical_address.png
   :align: center
   :height: 500px

----

.. image:: img/memory/memory_segmentation_example.png
   :align: center
   :width: 600px

----

.. image:: img/memory/memory_segmentation_hardware.png
   :align: center
   :width: 650px

----

.. image:: img/memory/memory_segmentation_logical2physical_address.png
   :align: center
   :height: 420px

----

.. class:: rtl-h1

  اشتراک گذاری در قطعه‌بندی

Sharing segments

----

.. class:: rtl-h1

  ترکیب قطعه‌بندی و صفحه‌بندی

.. class:: rtl-h2

مانند صفحه‌بندی دو سطحی با این تفاوت که در سطح یکم قطعه‌بندی انجام می‌شود و در سطح دوم صفحه‌بندی انجام می‌شود.

.. image:: img/memory/segmentation_paging.png
  :width: 500px

----

.. image:: img/memory/segmentation_paging_details.png
  :width: 580px

.. :

  https://www.javatpoint.com/os-segmented-paging

----

.. image:: img/memory/memory_management_techniques.png
   :align: center
   :width: 500px

----

.. class:: rtl-h1

  ساختار حافظهٔ قطعه‌بندی شده در پردازنده‌های اینتل ۳۲ بیتی (IA32)

.. image:: img/memory/memory_real_hardware_example_IA-32_segmentation_logical2physical.png
   :align: center
   :width: 700px

.. :

  https://en.wikipedia.org/wiki/Intel_8086

----

.. image:: img/memory/memory_real_hardware_example_IA-32_segmentation.png
   :align: center

----

IA32 intel
=====================
.. class:: rtl
    :class: substep

    *  بیشترین حافظه‌ای که می‌تواند پشتیبانی کند: 4GB
    *  بیشترین تعداد قطعه در یک فرآیند: 16KB
    *  بیشترین تعداد قطعهٔ اختصاصی برای یک فرآیند: 8KB برای دسترسی این بخش local descriptor table ( LDT ) به کار برده می‌شود.
    *  بیشترین تعداد قطعهٔ اشتراکی برای یک فرآیند با دیگر فرآیندها: 8KB برای دسترسی به این بخش global descriptor table ( GDT ) به کار برده می‌شود.

.. class:: substep

  .. csv-table:: بخش انتخاب کنندهٔ واحد قطعه‌بندی
     :header: `شمارهٔ قطعه`, `اختصاصی یا اشتراکی`, `حفاظت`
     :class: ltr substep

      13, 1, 2

----

.. class:: rtl-h1

  ساختار حافظهٔ صفحه‌بندی شده در پردازنده‌های اینتل ۳۲ بیتی (IA32)

.. csv-table:: صفحه‌بندی ۴ کیلوبایتی
   :header:    `جدولِ صفحهٔ یکم`, `جدولِ صفحهٔ دوم`, `جابجایی`
   :class: ltr

    ۱۰, ۱۰, ۱۲

.. csv-table:: صفحه‌بندی ۴ مگابایتی
   :header:  `جدولِ صفحه`, `جابجایی`
   :class: ltr

    ۱۰, ۲۲

----

.. image:: img/memory/memory_real_hardware_example_IA-32_paging_4KB.png
   :align: center
   :width: 560px

----

.. image:: img/memory/memory_real_hardware_example_IA-32_paging_4KB_page_address_extension.png
   :align: center
   :width: 750px

----

.. image:: img/memory/memory_real_hardware_example_x86_64_4KB_page_size_32_bit_pae_paging.png
   :align: center
   :width: 700px


----

.. class:: rtl-h1

  ساختار حافظه در پردازنده‌های «اِ اِم دی» ۶۴ بیتی (AMD64 یا `x86_64` )

.. image:: img/memory/memory_real_hardware_example_x86_64_4KB_page_size.png
   :align: center
   :width: 650px

----

.. class:: rtl-h1

  ساختار حافظه در پردازنده‌های «آرم» ۳۲ بیتی (ARM32)

.. image:: img/memory/memory_real_hardware_example_ARM32.png
   :align: center
   :width: 700px

----

Page Translation for 4MB and 4KB Page Sizes
========================================================================
.. image:: img/memory/Page_Translation_for_4MB_and_4KB_Page_Sizes.gif
   :align: center
   :height: 450px

----

Linux Memory Mangement
==========================
.. image:: img/memory/Linux_64bit_processors_page_table.png

----

.. class:: rtl-h1

  ساختار حافظهٔ قطعه‌بندی شده در پردازنده‌های اینتل ۳۲ بیتی (IA32)

.. image:: img/memory/memory_real_hardware_example_IA-32_segmentation_logical2physical.png
   :align: center
   :width: 700px

.. :

  https://en.wikipedia.org/wiki/Intel_8086

----

.. image:: img/memory/memory_real_hardware_example_IA-32_segmentation.png
   :align: center

----

IA32 intel
=====================
.. class:: rtl
    :class: substep

    *  بیشترین حافظه‌ای که می‌تواند پشتیبانی کند: 4GB
    *  بیشترین تعداد قطعه در یک فرآیند: 16KB
    *  بیشترین تعداد قطعهٔ اختصاصی برای یک فرآیند: 8KB برای دسترسی این بخش local descriptor table ( LDT ) به کار برده می‌شود.
    *  بیشترین تعداد قطعهٔ اشتراکی برای یک فرآیند با دیگر فرآیندها: 8KB برای دسترسی به این بخش global descriptor table ( GDT ) به کار برده می‌شود.

.. class:: substep

  .. csv-table:: بخش انتخاب کنندهٔ واحد قطعه‌بندی
     :header: `شمارهٔ قطعه`, `اختصاصی یا اشتراکی`, `حفاظت`
     :class: ltr substep

      13, 1, 2

----

.. class:: rtl-h1

  ساختار حافظهٔ صفحه‌بندی شده در پردازنده‌های اینتل ۳۲ بیتی (IA32)

.. csv-table:: صفحه‌بندی ۴ کیلوبایتی
   :header:    `جدولِ صفحهٔ یکم`, `جدولِ صفحهٔ دوم`, `جابجایی`
   :class: ltr

    ۱۰, ۱۰, ۱۲

.. csv-table:: صفحه‌بندی ۴ مگابایتی
   :header:  `جدولِ صفحه`, `جابجایی`
   :class: ltr

    ۱۰, ۲۲

----

.. image:: img/memory/memory_real_hardware_example_IA-32_paging_4KB.png
   :align: center
   :width: 560px

----

.. image:: img/memory/memory_real_hardware_example_IA-32_paging_4KB_page_address_extension.png
   :align: center
   :width: 750px

----

.. image:: img/memory/memory_real_hardware_example_x86_64_4KB_page_size_32_bit_pae_paging.png
   :align: center
   :width: 700px


----

.. class:: rtl-h1

  ساختار حافظه در پردازنده‌های «اِ اِم دی» ۶۴ بیتی (AMD64 یا `x86_64` )

.. image:: img/memory/memory_real_hardware_example_x86_64_4KB_page_size.png
   :align: center
   :width: 650px

----

.. class:: rtl-h1

  ساختار حافظه در پردازنده‌های «آرم» ۳۲ بیتی (ARM32)

.. image:: img/memory/memory_real_hardware_example_ARM32.png
   :align: center
   :width: 700px

----

Page Translation for 4MB and 4KB Page Sizes
========================================================================
.. image:: img/memory/Page_Translation_for_4MB_and_4KB_Page_Sizes.gif
   :align: center
   :height: 450px


----

Linux Memory Mangement
==========================
.. image:: img/memory/Linux_64bit_processors_page_table.png

----

References(I)
==================================================
* http://os-book.com
* Sean K. Barker (https://tildesites.bowdoin.edu/~sbarker/)
* https://en.wikipedia.org/wiki/Page_(computer_memory)
* http://blog.cs.miami.edu/burt/2012/10/31/virtual-memory-pages-and-page-frames/
* https://www.tldp.org/LDP/tlk/mm/memory.html
* https://www.geeksforgeeks.org/operating-system-paging/
* https://samypesse.gitbooks.io/how-to-create-an-operating-system/Chapter-8/
* https://www.cse.iitb.ac.in/~mythili/teaching/cs347_autumn2016/notes/07-memory.pdf
* https://www.kernel.org/doc/html/latest/admin-guide/mm/index.html
* https://www.javatpoint.com/os-segmented-paging
* https://www.geeksforgeeks.org/difference-between-internal-and-external-fragmentation/
* https://web.fe.up.pt/~arestivo/presentation/os-memory/#15
* https://binaryterms.com/contiguous-memory-allocation-in-operating-system.html
* https://github.com/mor1/ia-operating-systems/wiki/06-Virtual-Addressing
* https://github.com/mor1/ia-operating-systems
* https://www.faceprep.in/operating-systems/operating-systems-fragmentation-and-compaction/
* https://slideplayer.com/slide/7084682/

----

References(II)
==================================================
* https://www.cs.uic.edu/~jbell/CourseNotes/OperatingSystems/images/Chapter1/1_4_StorageDeviceHierarchy.jpg
* http://images.bit-tech.net/content_images/2007/11/the_secrets_of_pc_memory_part_1/hei.png
* https://answers.microsoft.com/en-us/windows/forum/windows_10-performance/physical-and-virtual-memory-in-windows-10/e36fb5bc-9ac8-49af-951c-e7d39b979938
* https://upload.wikimedia.org/wikipedia/commons/c/c2/Write-back_with_write-allocation.svg
* https://www.byclb.com/TR/Tutorials/dsp_advanced/ch1_1_dosyalar/image025.jpg
* https://tutorialspoint.dev/computer-science/operating-systems/operating-systems-segmentation
* https://tutorialspoint.dev/image/segmentation.png
* https://tutorialspoint.dev/image/Translation.png
* https://www.cs.princeton.edu/courses/archive/spr11/cos217/lectures/18MemoryMgmt.pdf
* http://harmanani.github.io/classes/csc320/Notes/ch05.pdf
* https://www.cs.princeton.edu/courses/archive/spr11/cos217/lectures/18MemoryMgmt.pdf

----

References(III)
==================================================
* https://answers.microsoft.com/en-us/windows/forum/all/physical-and-virtual-memory-in-windows-10/e36fb5bc-9ac8-49af-951c-e7d39b979938
* https://answers.microsoft.com/en-us/windows/forum/windows_10-performance/physical-and-virtual-memory-in-windows-10/e36fb5bc-9ac8-49af-951c-e7d39b979938
* https://www.geeksforgeeks.org/inverted-page-table-in-operating-system/
* https://www.kernel.org/doc/
* https://www.kernel.org/doc/gorman/html/understand/understand006.html
* https://www.kernel.org/doc/gorman/html/understand/understand-html006.png
* https://connormcgarr.github.io/paging/
* https://www.amd.com/system/files/TechDocs/24593.pdf
* http://www.rcollins.org/ddj/May96/
* https://commons.wikimedia.org/wiki/File:Intel_D945GCCR_Socket_775.png
* https://codex.cs.yale.edu/avi/os-book/

.. comments:


  * operating systems paging kernel

    Physical and Virtual Memory in Windows 10
    ===============================================
    https://answers.microsoft.com/en-us/windows/forum/windows_10-performance/physical-and-virtual-memory-in-windows-10/e36fb5bc-9ac8-49af-951c-e7d39b979938


    Android and IOS virtual memory
    https://discussions.apple.com/thread/2732434
    https://www.androidauthority.com/virtual-memory-explained-3143201/
