.. role:: ltr
    :class: ltr

.. role:: rtl
    :class: rtl

.. |nbsp| unicode:: 0xA0

.. role:: raw-html(raw)
   :format: html


.. prezento:: Operating Systems - Paging  (By Ahmad Yoosofan)
   :css: ./assets/style.css

.. slido:: Operating Systems - Memory Management - Paging (Ahmad Yoosofan)
   :class: t3c substep

    .. container::

        .. class:: substep

        * https://yoosofan.github.io/
        * https://github.com/yoosofan/slide/blob/main/os.paging.rst
        * https://yoosofan.github.io/slide/os.paging.presentation.html
        * https://yoosofan.github.io/slide/os.paging.rst
        * https://yoosofan.github.io/slide/os.paging.concise4pdf.html
        * https://yoosofan.github.io/course/os.html

        .. image:: os/img/memory/paging_model.png
           :align: center
           :scale: 120%
           :class: substep

    ..  container::

        .. class:: substep

        * **Paging** is a **non-contiguous**
        * Physical memory into **Frames**.
        * Logical memory (process) into **Pages**.
        * Page size = Frame size.
        * **Page Table**
        * Track free frames
        * Process with *N* pages need *N* free frames
        * No external fragmentation
        * Better memory utilization

    .. image:: os/img/memory/paging_example_32_bytes_memory.png
       :align: center
       :scale: 170%


    .. :


           Grok AI
            * **Paging** is a **non-contiguous** memory allocation technique.
            * Physical memory is divided into fixed-size blocks called **Frames**.
            * Logical memory (process) is divided into fixed-size blocks called **Pages**.
            * Page size = Frame size.
            * Goal: Eliminate **external fragmentation**.

            **Advantage over Fixed/Variable Partitioning:**
            - No external fragmentation
            - Better memory utilization

            Gemini Ai

            * Physical memory is divided into fixed-sized blocks called **Frames**.
            * Logical memory is divided into blocks of the same size called **Pages**.
            * The Operating System keeps track of all free frames.
            * To run a program of size *N* pages, the OS must find *N* free frames and load the program.
            * Paging eliminates **External Fragmentation** entirely.
            * Requires a **Page Table** to translate logical addresses to physical addresses.

.. slido::
   :class: n2c

    .. container::

        .. class:: substep

        * ( c ) free space { [ 7 - 14 ] }

            .. csv-table::
               :class: substep

                A0, A1, A2, A3
                0 , 1 , 2 , 3

            .. csv-table::
               :class: substep

                B0, B1, B2
                4 , 5 , 6

        * ( e ) free space { [ 4 - 6 ] , [ 11 - 14 ] }

            .. csv-table::
               :class: substep

                A0, A1, A2, A3
                0 , 1 , 2 , 3

            .. csv-table::
               :class: substep

                C0, C1, C2, C3
                7 , 8 , 9 , 10

        * ( f ) free space { [ 11 - 14 ] }

            .. csv-table::
               :class: substep

                A0, A1, A2, A3
                0 , 1 , 2 , 3

            .. csv-table::
               :class: substep

                C0, C1, C2, C3
                7 , 8 , 9 , 10

            .. csv-table::
               :class: substep

                D0, D1, D2, D3, D4
                4 , 5 , 6 , 11, 12

    .. image:: os/img/memory/memory_paging_process.png
       :align: center
       :scale: 95%

.. slido:: Paging Hardware
   :class: t2c

    .. class:: substep

    #. CPU generates **Logical Address** (virtual address)
    #. Logical Address is divided into: **Page Number (p)** + **Offset (d)**
        * **Page Number (p)**: Used as an index into a page table. The page table contains the base address of each page in physical memory.
        * **Page Offset (d)**: Combined with the base address to define the exact physical memory address.
    #. Page Table maps **logical page** → **physical frame**
    #. Final **Physical Address** = Frame Number + Offset
    #. If the logical address space is :math:`2^m` and page size is :math:`2^n` bytes:
    #. Page offset (d) = *n* bits
    #. Page number (p) = *m - n* bits
    #. Number of bits of Addrress  related to Maximum supported memory by this computer(cpu and motherboard)
    #. Number of bits of Addrress  =  log2(Maximum supported memory)
    #. If max supported memory = 32 words then number of bits needed for addrress ?
    #. 32 = 2 ^ 5, :math:`n = log_2(m)` , m is number of bytes or words
    #. 5 = log2(32)
    #. if p = 2, d = 3 then the size of each frame or page is ?
    #. 2 ^ 3 = 8
    #. Maximum number of Frames?
    #. 2 ^ 2  = 4

    .. container::

        .. image:: os/img/memory/page_number_offset.png
           :align: center
           :scale: 130%

        .. image:: os/img/memory/paging_hardware.png
           :align: center
           :scale: 130%

        .. image:: os/img/memory/memory_paging_logical_address_to_physical_address_detail.png
           :align: center

.. slido:: Logical Address to Physical Address and PTBR

    .. yographviz::
      :align: right
      :width: 1700px

      digraph PagingHW { /* thanks to Gemini AI */
          rankdir=LR;
          node [shape=box, fontname="Helvetica", style=filled, fillcolor="#f9f9f9"];
          edge [fontname="Helvetica", fontsize=11, color="#444444"];

          CPU [shape=ellipse, fillcolor="#dcedc1"];
          Logical [shape=record, label="Logical Address | { <p> Page (p) | <d> Offset (d) }", fillcolor="#ffcda3"];
          PageTable [shape=record, label="Page Table | ... | <entry> Frame (f) | ... ", fillcolor="#a8e6cf"];
          Physical [shape=record, label="Physical Address | { <f> Frame (f) | <d> Offset (d) }", fillcolor="#ffd3b6"];
          Memory [shape=cylinder, label="Physical\nMemory", fillcolor="#dcedc1"];

          CPU -> Logical [label=" Generates"];
          Logical:p -> PageTable:entry [label=" Index"];
          PageTable:entry -> Physical:f [label=" Base Address"];
          Logical:d -> Physical:d [label=" Exact Copy"];
          Physical -> Memory [label=" Accesses"];
      }

    .. image:: os/img/memory/memory_paging_address_translation.png
       :align: center
       :class: substep
       :scale: 145%


.. slido:: Computer with 16 words
   :class: t2c

    .. csv-table::
       :header-rows: 1

        |nbsp|,|nbsp|,|nbsp|,|nbsp|,|nbsp|,|nbsp|,|nbsp|,|nbsp|, |nbsp|,|nbsp|,|nbsp|,|nbsp|,|nbsp|,|nbsp|,|nbsp|,|nbsp|
        0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15
        "0000","0001 ","0010 ","0011 ","0100 ","0101 ","0110","0111","1000","1001","1010 ","1011","1100","1101","1110 ","1111"

    .. csv-table::
       :header-rows: 1

        P0_0,P0_1,P0_2,P0_3
        0,1,2,3
        "00 ","01 ","10 ","11 "

    .. csv-table::
       :header-rows: 1

        "00 ","01 ","10 ","11 "
        0,1,2,3


    .. csv-table::
       :header-rows: 1

        "00 ","01 ","10 ","11 "
        4,5,6,7


    .. :

       :class: t2c

        #. Draw Memory Bytes
        #. d = 2
        #. Draw Memory Frames
        #. some First Frames for os
        #. Put a process into Memory (not continuous or in order)
        #. Fill page table
        #. Convert a Logical Addfress to Physical Address
        #. Put another process into Memory

.. slido:: Process and Page Table
   :class: t2c

    .. image:: os/img/memory/page_table_in_a_frame.png

    .. image:: os/img/memory/page_table_in_a_frame2.png

.. slido:: Parts of Address Register in Paging


    * Frame 4k then number_bits(d) == 12
    * Frame 1k then number_bits(d) == 10
    * Frame 16k then number_bits(d) == 14

    Maximux memory supported by cpu

    * 1 MB ==> number_of_bit(Address register) == 20
        * Frame 4k ==> d == 12 and p == 8
        * Frame 1k ==> d == 10 and p == 10 // wrong?



.. slido:: A computer with 32 Bytes of Memory and 8 Bytes Page Size

    d = 3, p = 2

    p0 11 bytes


    .. class:: rtl-h1

        یک کامپیوتر با حافظهٔ ۱۲۸ بایتی و صفحه‌های ۸ بایتی

    .. image:: os/img/memory/memory_paging_typical_page_table_entry.jpg
       :align: center


.. slido:: PTBR

    .. image:: os/img/memory/paging_hardware_with_TLB_ptbr.png
       :align: center
       :height: 550px

.. slido:: TLB (Translation Lookaside Buffer)

    .. image:: os/img/memory/paging_hardware_with_TLB.png
       :align: center

    .. :

        * A specialized hardware cache used exclusively for memory management.
        * It caches recent virtual-to-physical address translations from the page tables.
        * A TLB miss forces a slow "page table walk" through physical RAM.

.. slido:: Flowchart of TLB miss

    .. image:: os/img/memory/paging_hardware_TLB_miss.png
       :align: center
       :height: 550px

.. slido:: Paging Memory Access

    .. image:: os/img/memory/memory_paging_page_table_and_cache.jpg
       :align: center

.. slido:: Page Sharing

    .. image:: os/img/memory/memory_paging_share_pages.png
       :align: center
       :height: 500px

.. slido::

    .. image:: os/img/memory/paging_sharing_code.png
       :align: center

.. slido:: Memory Hierarchy

    .. image:: os/img/memory/memory_hierarchy.png
       :align: center

.. slido:: Memory Access

    .. image:: os/img/memory/memory_effect_of_cache.png
       :align: center

.. slido:: Effective Access Time

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

.. slido::

    .. class:: rtl-h2

        زمان دسترسی مؤثر را برای پردازنده‌ای با حافظهٔ صفحه‌بندی شده حساب کنید اگر زمان دسترسی به حافظهٔ نهان جدول صفحه برابر ۱ نانو ثانیه باشد و زمان دسترسی به حافظهٔ نهان ۵ نانوثانیه باشد و زمان دسترسی به حافظه برابر ۱۰۰ نانوثانیه باشد و ضریب اصابت حافظهٔ نهان جدول صفحه برابر با ۹۵ درصد و ضریب اصابت به حافظهٔ نهان ۹۰ درصد باشد.

    .. class:: substep

    * :math:`t_t` = 1,  :math:`t_c` = 5, :math:`t_m` = 100, :math:`h_t` = 0.95, :math:`h_c` = 0.90

    .. math::
        :class: substep

        EAT = table +  memory

        table =  h_t * t_t + ( 1 - h_t ) * ( t_t + t_m )

        table = 0.95 * 1 + 0.05 * (1 + 100) = 0.95 + 5.05 = 6

        memory = h_c * t_c + ( 1 - h_c ) * ( t_m + t_c )

        memory = 0.90 * 5 + 0.1 * (5 + 100) = 4.5 + 10.5 = 15

        EAT = 6 + 15 = 21ns

.. slido::

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

.. slido:: Memory Protection

    .. image:: os/img/memory/paging_valid_invalid.png
       :align: center

.. slido:: References(I)

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
    * http://images.bit-tech.net/content_images/2007/11/the_secrets_of_pc_memory_part_1/hei.png
    * https://upload.wikimedia.org/wikipedia/commons/c/c2/Write-back_with_write-allocation.svg
    * https://www.byclb.com/TR/Tutorials/dsp_advanced/ch1_1_dosyalar/image025.jpg
    * https://en.wikipedia.org/wiki/File:Cache,hierarchy-example.svg
    * https://tutorialspoint.dev/image/Translation.png
    * https://www.cs.princeton.edu/courses/archive/spr11/cos217/lectures/18MemoryMgmt.pdf
    * http://harmanani.github.io/classes/csc320/Notes/ch05.pdf
    * https://www.cs.princeton.edu/courses/archive/spr11/cos217/lectures/18MemoryMgmt.pdf
    * https://www.kernel.org/doc/
    * https://www.gatevidyalay.com/translation-lookaside-buffer-tlb-paging/
    * `Paging-using-TLB-1.png <https://www.gatevidyalay.com/wp-content/uploads/2018/11/Translating-Logical-Address-into-Physical-Address-Diagram-Paging-using-TLB-1.png>`_
    * https://www.gatevidyalay.com/translation-lookaside-buffer-tlb-paging/
    * https://codex.cs.yale.edu/avi/os-book/
