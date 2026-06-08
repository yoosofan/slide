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
   :class: t3c step

    .. container::

        .. class:: step

        * https://yoosofan.github.io/
        * https://github.com/yoosofan/slide/blob/main/os.paging.rst
        * https://yoosofan.github.io/slide/os.paging.presentation.html
        * https://yoosofan.github.io/slide/os.paging.rst
        * https://yoosofan.github.io/slide/os.paging.concise4pdf.html
        * https://yoosofan.github.io/course/os.html

        .. image:: os/img/memory/paging_model.png
           :align: center
           :scale: 120%
           :class: step

    ..  container::

        .. class:: step

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

        .. class:: step

        * ( c ) free space { [ 7 - 14 ] }

            .. csv-table::

                A0, A1, A2, A3
                0 , 1 , 2 , 3

            .. csv-table::

                B0, B1, B2
                4 , 5 , 6

        * ( e ) free space { [ 4 - 6 ] , [ 11 - 14 ] }

            .. csv-table::

                A0, A1, A2, A3
                0 , 1 , 2 , 3

            .. csv-table::

                C0, C1, C2, C3
                7 , 8 , 9 , 10

        * ( f ) free space { [ 11 - 14 ] }

            .. csv-table::

                A0, A1, A2, A3
                0 , 1 , 2 , 3

            .. csv-table::

                C0, C1, C2, C3
                7 , 8 , 9 , 10

            .. csv-table::

                D0, D1, D2, D3, D4
                4 , 5 , 6 , 11, 12

    .. image:: os/img/memory/memory_paging_process.png
       :align: center
       :scale: 95%

.. slido:: Paging Hardware
   :class: t2c

    .. class:: step

    #. CPU generates **Logical Address** (virtual address)
    #. Logical Address is divided into: **Page Number (p)** + **Offset (d)**
        * **Page Number (p)**: Used as an index into a page table. The page table contains the base address of each page in physical memory.
        * **Page Offset (d)**: Combined with the base address to define the exact physical memory address.
    #. Page Table maps **logical page** → **physical frame**
    #. Final **Physical Address** = Frame Number + Offset
    #. If the logical address space is :math:`2^m` and page size is :math:`2^n` bytes:
    #. Page offset (d) = *n* bits
    #. Page number (p) = *m - n* bits
    #. Number of bits of Address  related to Maximum supported memory by this computer(cpu and motherboard)
    #. Number of bits of Address  =  log2(Maximum supported memory)
    #. If max supported memory = 32 words then number of bits needed for address?
    #. 32 = 2 ^ 5, :math:`n = log_2(m)` , m is number of bytes or words
    #. 5 = log2(32)
    #. if p = 2, d = 3 then the size of each frame or page is?
    #. 2 ^ 3 = 8
    #. Maximum number of Frames?
    #. Maximum number of precesses

    .. container::

        .. image:: os/img/memory/page_number_offset.png
           :align: center
           :scale: 130%

        .. image:: os/img/memory/paging_hardware.png
           :align: center
           :scale: 130%

        .. image:: os/img/memory/memory_paging_logical_address_to_physical_address_detail.png
           :align: center

.. slido:: Page-Table Base Register (PTBR)
   :class: ts2c

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
       :class: step
       :scale: 145%

    .. class:: step

    * **PTBR** holds the **starting address** of the current process's page table.
    * Changed on every context switch.
    * Used by MMU to locate the page table in memory.

.. slido:: Step by Step Sample
   :class: t2c

    .. csv-table:: Memory with only OS before adding a process
       :header-rows: 1
       :class: step full-border

        OS, OS, OS, |nbsp|, |nbsp|, |nbsp|, |nbsp|, |nbsp|, |nbsp|, |nbsp|, |nbsp|, |nbsp|, |nbsp|, |nbsp|, |nbsp|, |nbsp|
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
        "0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010 ","1011","1100","1101","1110","1111"

    .. csv-table:: Process P0
       :header-rows: 1
       :class: step full-border

        A     ,    B  ,    C  ,    D  ,    E  , F
        P0_0  , P0_0  , P0_0  , P0_0  , P0_1  , P0_1
        0     ,    1  ,    2  ,    3  ,    4  , 5
        "0000", "0001", "0010", "0011", "0100", "0101"

    .. csv-table:: Adding Process P0 to Memory
       :header-rows: 1
       :class: step full-border

        OS    ,    OS,    OS,|nbsp|,     E,     F,|nbsp|,|nbsp|,  T_P0,  T_P0,  T_P0,  T_P0,     A,     B,      C, D
        OS    ,    OS,    OS,|nbsp|,  P0_1,  P0_1,|nbsp|,|nbsp|,  "11",  "01",|nbsp|,|nbsp|,  P0_0,  P0_0,   P0_0, P0_0
        "0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"

    .. csv-table:: Page Table of P0
       :header-rows: 1
       :class: step full-border

        "P0_0", "P0_1", |nbsp|, |nbsp|
        "11", "01", "00", "00"
        "00", "01", "10", "11"

    .. csv-table:: Page Table of P0
       :header-rows: 1
       :class: step full-border

        "11", "01", "00", "00"
        "00", "01", "10", "11"

    .. class:: step

    * Logical Address of C = "0010" = "00" "10"
    * Page Address    = "00"
    * Page Table Cell Index "00" is "11"
    * Physical Address= concatenation("00", "10")
    * Physical Address= "00" "10" = "0010"

    .. class:: step

    #. Logical Address of F = "0101" = "01" "01"
    #. Page Address    = "01"
    #. Page Table Cell Index "01" is "01"
    #. Physical Address= concatenation("01", "01")
    #. Physical Address= "01" "01" = "0101"

    .. class:: step

    * 32 words(bytes) memory
    * number of bits in address?
    * number of bits in address=5
    * Draw Memory Frames, First Frames of OS
    * Put a process into Memory, Fill page table
    * Convert a Logical Address to Physical Address
    * Put another process into Memory

.. slido:: Parts of Address Register in Paging
   :class: t2c

    .. class:: step

    * Page size = 4 KB → **d** uses **12 bits**
    * Page size = 8 KB → **d** uses **13 bits**
    * Frame 4k then number_bits(d) == 12
    * Frame 1k then number_bits(d) == 10
    * Frame 16k then number_bits(d) == 14
    * Maximux memory supported by cpu
    * 1 MB ==> number_of_bit(Address register) == 20
    * Frame 4k ==> d == 12 and p == 8

    .. class:: step

    #. Frame Size and Limitations
    #. Page size is defined by the hardware architecture (always a power of 2).
    #. Typical sizes range from 4 KB to 8 KB (modern systems also support "Huge Pages" up to 1 GB).
    #. **The Trade-off: Internal Fragmentation**
       * Process size rarely perfectly aligns with page boundaries.
       * The last page allocated may not be completely full.
    #. Page size = 4,096 bytes (4 KB). Process size = 72,766 bytes.
    #. Requires: 17 full pages + 3,134 bytes in the 18th page.
    #. **Waste:** 4,096 - 3,134 = 962 bytes of internal fragmentation.

    .. class:: step

    * **The Performance Bottleneck:**
    * Every data or instruction access requires **two memory accesses**:
       #. One access for the page table entry.
       #. One access for the actual data/instruction.
    * *Solution:* A special, fast-lookup hardware cache called a Translation Look-aside Buffer (TLB).

.. slido:: Translation Look-aside Buffer (TLB)
   :class: t2c

    .. image:: os/img/memory/paging_hardware_with_TLB.png
       :align: center
       :scale: 140%

    .. image:: os/img/memory/paging_hardware_with_TLB_ptbr.png
       :align: center
       :class: step
       :scale: 120%

    * High-speed **hardware cache** for recent page table entries.
    * Contains (Page Number → Frame Number) mappings.
    * Greatly improves performance.

    .. class:: step

    * **Parallel Search:** All keys (page numbers) are compared simultaneously.
    * **TLB Hit**: Fast address translation
    * **TLB Miss**: Must walk page table in memory

    .. :

        * **TLB Hit:** If the page number is found in the TLB, the frame number is returned immediately.
        * **TLB Miss:** If not found, the OS must access the page table in main memory, then load the new entry into the TLB for future use.

        * A specialized hardware cache used exclusively for memory management.
        * It caches recent virtual-to-physical address translations from the page tables.
        * A TLB miss forces a slow "page table walk" through physical RAM.

.. slido:: Flowchart of TLB miss
   :class: t2c

    .. image:: os/img/memory/paging_hardware_TLB_miss.png
       :align: center
       :scale: 120%

    .. image:: os/img/memory/memory_paging_page_table_and_cache.jpg
       :align: center
       :scale: 160%
       :class: step

.. slido:: Effective Access Time (EAT)
   :class: t2c

    .. class:: step

    * :math:`t_t` : access Time of TLB)
    * :math:`t_c` : access Time of Cache
    * :math:`t_m` : access Time of Memory
    * :math:`h_t` : Hit ratio of TLB
    * :math:`h_c` : Hit ratio of Cache

    .. class:: step

    #. EAT = table +  memory
    #. :math:`table =  h_t * t_t + ( 1 - h_t ) * ( t_t + t_m )`
    #. :math:`memory = h_c * t_c + ( 1 - h_c ) * ( t_c + t_m )`

    .. container:: step

        * EAT = :math:`h_t * t_t + ( 1 - h_t ) * ( t_t + t_m ) + h_c * t_c + ( 1 - h_c ) * ( t_c + t_m )`

        .. class:: rtl-h1 step

            زمان دسترسی مؤثر = `زمان دسترسی به جدول صفحه + زمان دسترسی به حافظه`

        .. class:: rtl-h2 step

            زمان دسترسی مؤثر را برای پردازنده‌ای با حافظهٔ صفحه‌بندی شده حساب کنید اگر زمان دسترسی به حافظهٔ نهان جدول صفحه برابر ۱ نانو ثانیه باشد و زمان دسترسی به حافظهٔ نهان ۵ نانوثانیه باشد و زمان دسترسی به حافظه برابر ۱۰۰ نانوثانیه باشد و ضریب اصابت حافظهٔ نهان جدول صفحه برابر با ۹۵ درصد و ضریب اصابت به حافظهٔ نهان ۹۰ درصد باشد.

    .. class:: step

    * :math:`t_t` = 1,  :math:`t_c` = 5, :math:`t_m` = 100, :math:`h_t` = 0.95, :math:`h_c` = 0.90
    * EAT = table +  memory
    * table  = :math:`h_t * t_t + ( 1 - h_t ) * ( t_t + t_m )`
    * table  = :math:`0.95 * 1 + 0.05 * (1 + 100) = 0.95 + 5.05 = 6`
    * memory = :math:`h_c * t_c + ( 1 - h_c ) * ( t_m + t_c )`
    * memory = :math:`0.90 * 5 + 0.1 * (5 + 100) = 4.5 + 10.5 = 15`
    * EAT = 6 + 15 = 21ns

    .. container::

        .. class:: rtl-h2 step

                با فرض برابر بودن نسبت‌های اصابت و زمان‌های یکسان برای دسترسی به حافظهٔ نهان  و حافظهٔ TLB خواهیم داشت

        .. class:: step

        * EAT = :math:`2 * (h * t_c + ( 1 - h ) * ( t_c + t_m ))`
        * EAT = :math:`2 * (h_c * t_c + t_m + t_c - h_c * t_m - h_c * t_c )`
        * EAT = :math:`2 * (t_c + (1 - h_c) * t_m )`

    .. class:: step

    * :math:`t_m = 100ns` , :math:`t_c = 20ns` , :math:`h_c = 80\%`:
    * :math:`EAT = 2 * (20 + 0.20 * 100)`
    * :math:`EAT = 80`


    .. class:: step

    * If we only consider TLB and remove cache
    * EAT = :math:`(t_m + t_t) * h_t + (2 * t_m + t_t) * (1 - h_t)`
    * EAT = :math:`(100 + 20) * 0.8 + (2 * 100 + 20) * 0.2`
    * :math:`EAT = 96 + 44 = 140 ns`
    * *(The system experiences a 40% slowdown compared to direct memory access due to a 20% miss penalty).*

.. slido:: Memory Protection
   :class: t2c step

    .. container::

        .. class:: step

        #. **PTLR (Page-Table Length Register):** Indicates the size of the page table to prevent out-of-bounds access.
        #. **Valid/Invalid** bit.
            * **Valid** = page is in memory and accessible.
            * **Invalid** = page not in memory or access violation → Trap to OS.

        .. class:: step

        * **Access Rights:** Define if a page is Read-only, Read-write, or Execute-only.
        * Any violation causes a hardware trap to the OS.

        .. csv-table::
            :header: "Page", "Frame", "Status"
            :class: step

            "0", "4", "v"
            "1", "7", "v"
            "2", "-", "i"
            "3", "-", "i"

        .. image:: os/img/memory/memory_paging_typical_page_table_entry.jpg
            :align: center
            :class: step

    .. image:: os/img/memory/paging_valid_invalid.png
       :align: center
       :scale: 150%

.. slido:: Page Sharing
   :class: t2c

    .. image:: os/img/memory/memory_paging_share_pages.png
       :align: center

    .. image:: os/img/memory/paging_sharing_code.png
       :align: center
       :class: step
       :scale: 130%

    .. class:: step

        * **Shared Code:**
        * One copy of read-only (reentrant) code can be shared among multiple processes.
        * Examples: Text editors, compilers, standard C libraries (libc).
        * Shared code must appear in the *exact same location* in the logical address space of all processes utilizing it.
        * Reduces memory usage.

    .. class:: step

        * **Private Code and Data:**
        * Each process keeps a separate, private copy of its specific code and data.
        * The pages for private code and data can appear anywhere in the logical address space.

    .. :

        .. slido:: Process and Page Table
        :class: t2c

            .. image:: os/img/memory/page_table_in_a_frame.png

            .. image:: os/img/memory/page_table_in_a_frame2.png


.. slido:: Frame Size & Single-Level Paging Limitations
   :class: t2c

    .. class:: step

    * **The Size Problem:** Modern operating systems support large logical address spaces (e.g., 32-bit or 64-bit).
    * Consider a 32-bit logical address space with a 4 KB (:math:`2^{12}`) page size:
       * Number of entries = :math:`2^{32} / 2^{12} = 2^{20}` (1 Million entries).
    * If each page table entry is 4 bytes, the page table size is **4 MB**.
    * *Every running process* needs its own 4 MB page table stored in contiguous physical memory!
    * This massive overhead necessitates advanced page table architectures (which we will explore next).

    .. class:: step

    * Frame size is a **power of 2** (typically 4KB, 8KB, ...)
    * **Smaller page size** → more pages → **larger page table**
    * **Larger page size** → more **internal fragmentation**
    * **Trade-off:**
    * Small pages → Low internal fragmentation, High overhead (page table)
    * Large pages → High internal fragmentation, Smaller page table
    * 1 MB ==> number_of_bit(Address register) == 20
        * Frame 4k ==> d == 12 and p == 8
        * Frame 1k ==> d == 10 and p == 10 // wrong?


.. slido:: Advantages & Disadvantages of Paging
    :class: t2c

    .. class:: step

    * No **external fragmentation**
    * Easy to implement **memory protection**
    * Supports **page sharing**
    * Simple address translation (with TLB)

    .. class:: step

    * **Internal fragmentation** (last page of process)
    * **Page table overhead** (especially for large processes)
    * Two memory accesses per reference (mitigated by TLB)

.. slido:: References
    :class: t2c

    * http://os-book.com
    * https://en.wikipedia.org/wiki/Paging
    * https://en.wikipedia.org/wiki/Page_(computer_memory)
    * https://upload.wikimedia.org/wikipedia/commons/c/c2/Write-back_with_write-allocation.svg
    * https://en.wikipedia.org/wiki/File:Cache,hierarchy-example.svg
    * Sean K. Barker (https://tildesites.bowdoin.edu/~sbarker/)
    * http://blog.cs.miami.edu/burt/2012/10/31/virtual-memory-pages-and-page-frames/
    * https://www.tldp.org/LDP/tlk/mm/memory.html
    * https://www.geeksforgeeks.org/operating-system-paging/
    * https://samypesse.gitbooks.io/how-to-create-an-operating-system/Chapter-8/
    * https://www.cse.iitb.ac.in/~mythili/teaching/cs347_autumn2016/notes/07-memory.pdf

    + https://www.kernel.org/doc/
    + https://web.fe.up.pt/~arestivo/presentation/os-memory/#15
    + https://github.com/mor1/ia-operating-systems
    + https://slideplayer.com/slide/7084682/
    + http://images.bit-tech.net/content_images/2007/11/the_secrets_of_pc_memory_part_1/hei.png
    + https://www.byclb.com/TR/Tutorials/dsp_advanced/ch1_1_dosyalar/image025.jpg
    + https://tutorialspoint.dev/image/Translation.png
    + https://www.cs.princeton.edu/courses/archive/spr11/cos217/lectures/18MemoryMgmt.pdf
    + http://harmanani.github.io/classes/csc320/Notes/ch05.pdf
    + https://www.gatevidyalay.com/translation-lookaside-buffer-tlb-paging/
    + `Paging-using-TLB-1.png <https://www.gatevidyalay.com/wp-content/uploads/2018/11/Translating-Logical-Address-into-Physical-Address-Diagram-Paging-using-TLB-1.png>`_
    + https://www.gatevidyalay.com/translation-lookaside-buffer-tlb-paging/
