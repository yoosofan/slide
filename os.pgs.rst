.. role:: ltr
    :class: ltr

.. role:: rtl
    :class: rtl

.. prezento:: Multi Level Paging and Segmentation (By Ahmad Yoosofan)
   :css: ./assets/style.css

.. slido:: Multi Level Paging and Segmentation

    Ahmad Yoosofan

    * https://yoosofan.github.io/
    * https://yoosofan.github.io/slide/os.pgs.presentation.html
    * https://yoosofan.github.io/slide/os.pgs.rst
    * https://github.com/yoosofan/slide/blob/main/os.pgs.rst
    * https://yoosofan.github.io/course/os.html
    * https://yoosofan.github.io/slide/os.pgs.concise4pdf.html

.. slido:: Frame Size(I)

    .. class:: rtl-h2

        کوچک یا بزرگ بودن اندازهٔ صفحه‌ها (همان قاب‌های حافظه) بر روی موضوع‌های گوناگونی اثر دارد


    .. class:: step

        1

        * Max memory supported : 64 byte = 2 ^ 6
        * frame size = page table 2 byte
        * 2 ^ 6 / 2 ^1 = 2 ^ 5 = 32
        * ?

    .. class:: step

        2

        * Max memory supported : 64 byte = 2 ^ 6
        * frame size = page table 4 byte
        * 2^6 / 2^2 = 2^4 = 16
        * ?

    .. class:: step

        3

        * Max memory supported : 64 byte = 2 ^ 6
        * frame size = page table 8 byte
        * 2^6 / 2^3 = 2^3 = 8
        * ? , Maximum Number of Processes

.. slido:: Frame Size(II)

    .. class:: step

        1

        * 32 bit address
        * 1024 size of frame?
        * 32 - 10 = 22
        * 2^22 Frame
        * 2^22 page table entry
        * Problem ?

    .. class:: step

        2

        * 32 bit address
        * 2^20 size of frame?
        * 32 - 20 = 12
        * 2^12 = 4096 Frame
        * ? , Maximum Number of Processes

.. slido:: Two Level Paging

    .. image:: os/img/memory/paging_two_level.png
       :align: center

    .. :

        access time

.. slido:: Addressing in 2 Level Paging

    .. image:: os/img/memory/paging_address_translation_32bit.png
       :align: center

    .. image:: os/img/memory/paging_two_level_32bit_address.png
       :align: center

.. slido:: Address_Translation

    .. image:: os/img/memory/memory_paging_Address_Translation_in_a_Two_Level_Paging_System.png
       :align: center
       :scale: 90%

.. slido:: Two_Level_Hierarchical_Page_Table

    .. image:: os/img/memory/memory_paging_Two_Level_Hierarchical_Page_Table.png
       :align: center

.. slido:: 64 bits two level paging

    .. image:: os/img/memory/paging_two_level_64bit.png
       :align: center

.. slido:: Three level Paging for 64 bits

    .. image:: os/img/memory/paging_three_level_64bit_address.png
       :align: center

.. slido:: Inverted Page Table

    .. image:: os/img/memory/inverted_page_table.png
       :align: center

.. slido:: Hash Function and Inverted Page Table

    .. image:: os/img/memory/memory_paging_Inverted_Page_Table_Structure.png
       :align: center

.. slido:: Windows 10 Inverted Page Table on Intel Itanium 64

    .. image:: os/img/memory/Physical_and_Virtual_Memory_in_Windows_10_64bit_processors_inverted_page_table.png
        :width: 780px

.. slido:: Segmentation

    .. image:: os/img/memory/memory_segmentation_logical_address.png
       :align: center
       :height: 500px

.. slido:: Example of Segmentation

    .. image:: os/img/memory/memory_segmentation_example.png
       :align: center
       :width: 600px

.. slido:: Segmentation Hardware

    .. image:: os/img/memory/memory_segmentation_hardware.png
       :align: center
       :width: 650px

.. slido:: Logical to Physical Address

    .. image:: os/img/memory/memory_segmentation_logical2physical_address.png
       :align: center
       :height: 420px

.. slido:: Sharing segments


.. slido::

    .. class:: rtl-h1

      ترکیب قطعه‌بندی و صفحه‌بندی

    .. class:: rtl-h2

    مانند صفحه‌بندی دو سطحی با این تفاوت که در سطح یکم قطعه‌بندی انجام می‌شود و در سطح دوم صفحه‌بندی انجام می‌شود.

    .. image:: os/img/memory/segmentation_paging.png
      :width: 500px

.. slido::

    .. image:: os/img/memory/segmentation_paging_details.png
      :width: 580px

    .. :

      https://www.javatpoint.com/os-segmented-paging

.. slido::

    .. image:: os/img/memory/memory_management_techniques.png
       :align: center
       :width: 500px

.. slido::

    .. class:: rtl-h1

      ساختار حافظهٔ قطعه‌بندی شده در پردازنده‌های اینتل ۳۲ بیتی (IA32)

    .. image:: os/img/memory/memory_real_hardware_example_IA-32_segmentation_logical2physical.png
       :align: center
       :width: 700px

    .. :

      https://en.wikipedia.org/wiki/Intel_8086

.. slido::

    .. image:: os/img/memory/memory_real_hardware_example_IA-32_segmentation.png
       :align: center

.. slido:: IA32 intel

    .. class:: rtl
        :class: step

        *  بیشترین حافظه‌ای که می‌تواند پشتیبانی کند: 4GB
        *  بیشترین تعداد قطعه در یک فرآیند: 16KB
        *  بیشترین تعداد قطعهٔ اختصاصی برای یک فرآیند: 8KB برای دسترسی این بخش local descriptor table ( LDT ) به کار برده می‌شود.
        *  بیشترین تعداد قطعهٔ اشتراکی برای یک فرآیند با دیگر فرآیندها: 8KB برای دسترسی به این بخش global descriptor table ( GDT ) به کار برده می‌شود.

    .. class:: step

      .. csv-table:: بخش انتخاب کنندهٔ واحد قطعه‌بندی
         :header: `شمارهٔ قطعه`, `اختصاصی یا اشتراکی`, `حفاظت`
         :class: ltr step

          13, 1, 2

.. slido::

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

.. slido::

    .. image:: os/img/memory/memory_real_hardware_example_IA-32_paging_4KB.png
       :align: center
       :width: 560px

.. slido::

    .. image:: os/img/memory/memory_real_hardware_example_IA-32_paging_4KB_page_address_extension.png
       :align: center
       :width: 750px

.. slido::

    .. image:: os/img/memory/memory_real_hardware_example_x86_64_4KB_page_size_32_bit_pae_paging.png
       :align: center
       :width: 700px

.. slido::

    .. class:: rtl-h1

      ساختار حافظه در پردازنده‌های «اِ اِم دی» ۶۴ بیتی (AMD64 یا `x86_64` )

    .. image:: os/img/memory/memory_real_hardware_example_x86_64_4KB_page_size.png
       :align: center
       :width: 650px

.. slido::

    .. class:: rtl-h1

      ساختار حافظه در پردازنده‌های «آرم» ۳۲ بیتی (ARM32)

    .. image:: os/img/memory/memory_real_hardware_example_ARM32.png
       :align: center
       :width: 700px

.. slido:: Page Translation for 4MB and 4KB Page Sizes

    .. image:: os/img/memory/Page_Translation_for_4MB_and_4KB_Page_Sizes.gif
       :align: center
       :height: 450px

.. slido:: Linux Memory Mangement

    .. image:: os/img/memory/Linux_64bit_processors_page_table.png

.. slido::

    .. class:: rtl-h1

      ساختار حافظهٔ قطعه‌بندی شده در پردازنده‌های اینتل ۳۲ بیتی (IA32)

    .. image:: os/img/memory/memory_real_hardware_example_IA-32_segmentation_logical2physical.png
       :align: center
       :width: 700px

    .. :

      https://en.wikipedia.org/wiki/Intel_8086

.. slido::

    .. image:: os/img/memory/memory_real_hardware_example_IA-32_segmentation.png
       :align: center

.. slido:: IA32 intel

    .. class:: rtl
        :class: step

        *  بیشترین حافظه‌ای که می‌تواند پشتیبانی کند: 4GB
        *  بیشترین تعداد قطعه در یک فرآیند: 16KB
        *  بیشترین تعداد قطعهٔ اختصاصی برای یک فرآیند: 8KB برای دسترسی این بخش local descriptor table ( LDT ) به کار برده می‌شود.
        *  بیشترین تعداد قطعهٔ اشتراکی برای یک فرآیند با دیگر فرآیندها: 8KB برای دسترسی به این بخش global descriptor table ( GDT ) به کار برده می‌شود.

    .. class:: step

      .. csv-table:: بخش انتخاب کنندهٔ واحد قطعه‌بندی
         :header: `شمارهٔ قطعه`, `اختصاصی یا اشتراکی`, `حفاظت`
         :class: ltr step

          13, 1, 2

.. slido::

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

.. slido::

    .. image:: os/img/memory/memory_real_hardware_example_IA-32_paging_4KB.png
       :align: center
       :width: 560px

.. slido::

    .. image:: os/img/memory/memory_real_hardware_example_IA-32_paging_4KB_page_address_extension.png
       :align: center
       :width: 750px

.. slido::

    .. image:: os/img/memory/memory_real_hardware_example_x86_64_4KB_page_size_32_bit_pae_paging.png
       :align: center
       :width: 700px

.. slido::

    .. class:: rtl-h1

      ساختار حافظه در پردازنده‌های «اِ اِم دی» ۶۴ بیتی (AMD64 یا `x86_64` )

    .. image:: os/img/memory/memory_real_hardware_example_x86_64_4KB_page_size.png
       :align: center
       :width: 650px

.. slido::

    .. class:: rtl-h1

      ساختار حافظه در پردازنده‌های «آرم» ۳۲ بیتی (ARM32)

    .. image:: os/img/memory/memory_real_hardware_example_ARM32.png
       :align: center
       :width: 700px

.. slido:: Page Translation for 4MB and 4KB Page Sizes

    .. image:: os/img/memory/Page_Translation_for_4MB_and_4KB_Page_Sizes.gif
       :align: center
       :height: 450px

.. slido:: Linux Memory Mangement

    .. image:: os/img/memory/Linux_64bit_processors_page_table.png

.. slido:: References(I)

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

.. slido:: References(II)

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

.. slido:: References(III)

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

        **Physical and Virtual Memory in Windows 10**
        https://answers.microsoft.com/en-us/windows/forum/windows_10-performance/physical-and-virtual-memory-in-windows-10/e36fb5bc-9ac8-49af-951c-e7d39b979938


        Android and IOS virtual memory
        https://discussions.apple.com/thread/2732434
        https://www.androidauthority.com/virtual-memory-explained-3143201/
