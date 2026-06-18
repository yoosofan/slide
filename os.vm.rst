.. role:: ltr
    :class: ltr

.. role:: rtl
    :class: rtl

.. |nbsp| unicode:: 0xA0

.. prezento:: Operating Systems - Virtual Memory  (By Ahmad Yoosofan)
   :css: ./assets/style.css

.. slido:: Operating Systems - Virtual Memory - Ahmad Yoosofan
   :class: t2c

    * https://yoosofan.github.io/
    * https://yoosofan.github.io/slide/os.vm.presentation.html
    * https://yoosofan.github.io/slide/os.vm.rst
    * https://github.com/yoosofan/slide/blob/main/os.vm.rst
    * https://yoosofan.github.io/course/os.html
    * https://yoosofan.github.io/slide/os.vm.concise4pdf.html

    .. image:: os/img/memory/memory_virtual_memory_general.png
       :align: center

    .. image: os/img/memory/virtual_memory_concept.png
       :align: center
       :class: step

.. slido:: Virtual Memory Addressing


    .. image:: os/img/memory/memory_virtual_valid_invalid.png
       :align: center
       :class: step

.. slido:: Page Fault

    .. image:: os/img/memory/memory_virtual_handling_page_fault.png
       :align: center

    .. image: os/img/memory/memory_virtual_Operation_of_Paging_and_Translation_Lookaside_Buffer.png
       :align: center
       :class: step

.. slido:: Effective Access Time of Virtual Memory
   :class: t2c

    .. class:: step

    * effective access time =
    * (1 − p) × ma + p × page fault time.
    * EAT RAM = 200 nanosecond
    * Page fault time = 8  milliseconds
    * (1 − p) × 200 + p × 8,000,000
    * 200 + 7,999,800 × p
    * 220 > 200 + 7,999,800 × p,
    * 20 > 7,999,800 × p,
    * p < 0.0000025

    .. image:: os/img/memory/memory_virtual_with_TLB.png
        :align: center
        :scale: 120%

.. slido:: Allocation of frames
   :class: t2c

    .. class:: step rtl

        * مجموعهٔ مقیم برای هر فرآیند.

            *  تعداد ثابت fixed-allocation
            *  تعداد متغیر  variable-allocation

        * بخش کردن قاب‌ها میان فرآیندها

            *  تعداد برابر
            *  تعداد به نسبت اندازهٔ فرآیند

        * چگونگی برگزیدن یک قاب برای تخصیص به یک فرآیند

            *  تخصیص محلی
            *  تخصیص سراسری

    .. class:: step

        * **Allocation Policies**

            * On demand
            * prepaging

        * **Cleaning Policies**
            *  demand cleaning
            *  precleaning

.. slido:: Page Replacement

    .. image: os/img/memory/memory_virtual_need4replacement.png
       :align: center

    .. image:: os/img/memory/memory_virtual_page_replacement.png
       :align: center
       :class: step

.. slido:: Frame Allocation
   :class: t2c

    .. container::

        .. class:: step

        * frame allocation algorithm
        * page replacement algorithm
        * reference string of pages
        * 1, 4, 1, 6, 1, 6, 1, 6, 1, 6, 1

        .. class:: step rtl-h3

        *  تعداد خطای نبود صفحه بسته به تعداد قاب‌های تخصیص داده شده

    .. image:: os/img/memory/memory_virtual_page_fault_per_frame_allocated.png
        :align: center
        :class: step

.. slido:: FIFO

    .. image:: os/img/memory/memory_virtual_page_replacement_FIFO.png
       :align: center

    .. container:: step

        .. class:: h2

        Belady’s anomaly

        .. image:: os/img/memory/memory_virtual_page_replacement_FIFO_Blady_anomaly.png
           :align: center
           :class: step

.. slido:: Optimal
   :class: t2c

    .. container::

        .. image:: os/img/memory/memory_virtual_page_replacement_Optimal.png
           :align: center

        .. container:: step

            .. class:: h2

                Not Recently Used Page(NRU)

            .. image:: os/img/memory/memory_virtual_page_replacement_LRU.png
               :align: center

    .. container::

        .. class:: step

            * NRU vs LRU
            * Least Recently Used(LRU)
            * How to Impolement LRU
                * counters
                * stacks
            * LFU
            * Least Frequently Used
            * MFU
            * Most Frequently Used


        .. :

            page-replacement algorithm is based on the argument that the page with the smallest count was probably just brought in and has yet to be used

.. slido:: Second chance (clock)
   :class: t2c

    .. container::

        * NRU and LRU by using one bit
        * access bit, reference bit, or use bit
        * Some called this NRU

        .. image:: os/img/memory/memory_paging_typical_page_table_entry.jpg
            :align: center
            :class: step
            :scale: 80%

        .. grafo::

            digraph ClockSecondChance {
            // Use a circular layout engine (circo or neato with -Gstart=) when rendering:
            // dot -Kcirco -Tpng -o clock.png clock.dot
            graph [layout=circo, overlap=false];
            node [shape=oval, style=rounded, fontsize=10, fontname="Helvetica"];
            edge [arrowhead=none];

            // Clock face (frames). Each node shows "Frame n\nR:x"
            f0 [label="F0\nR=0", width=0.9, height=0.9];
            f1 [label="F1\nR=1", width=0.9, height=0.9];
            f2 [label="F2\nR=1", width=0.9, height=0.9];
            f3 [label="F3\nR=0", width=0.9, height=0.9];
            f4 [label="F4\nR=1", width=0.9, height=0.9];
            f5 [label="F5\nR=0", width=0.9, height=0.9];
            f6 [label="F6\nR=0", width=0.9, height=0.9];
            f7 [label="F7\nR=1", width=0.9, height=0.9];

            // Connect in a ring (clockwise)
            f0 -> f1; f1 -> f2; f2 -> f3; f3 -> f4;
            f4 -> f5; f5 -> f6; f6 -> f7; f7 -> f0;

            // Optional central hub to draw a clock-hand to current candidate
            center [label="", shape=circle, width=0.1, style=invis];

            // Clock hand (thicker, directed) pointing to the next candidate (change target as needed)
            hand [label="clock\nhand", shape=plaintext];
            hand -> f2 [color=black, penwidth=3, arrowhead=open];

            // Keep layout tidy: place center near nodes (in some renderers center isn't necessary)
            center -> f0 [style=invis];
            }


    .. :

        * as an approximation to LRU, select one of the pages that has not been used recently (as opposed to identifying exactly which one has not been used for the longest amount of time)
        * keep one bit called the "used bit" or "reference bit", where 1 => used recently and 0 => not used recently
        * variants of this scheme are used in many operating systems, including UNIX and MacIntosh
        * most variations use a scan pointer and go through the page frames one by one, in some order, looking for a page that has not been used recently.

    .. image:: os/img/memory/memory_virtual_page_replacement_second_chance.png
       :align: center

.. slido:: Modefied Clock - Enhanced Second Chance
   :class: t2c

    .. class:: step

        * **Reference Bit (R)**
            * Automatically set to ``1`` by hardware
            * when the page is read or written.
        * **Modify/Dirty Bit (M)**
            * Automatically set to ``1`` by hardware
            * when the page content is modified.
        * **(Reference Bit, Modify Bit)**
        * **(R, M)**

        1. R=0, M=0 : not recently used, clean).
        2. R=0, M=1 : require write-back
        3. R=1, M=0 : clear R
        4. R=1, M=1 : R=0, M=1

        * This algorithm accesses the frame, right?
        * Doesn't the R bit change to 1 **automatically**?
        * Think about it!!
        * Look at the YIC models and its changes
        * Read the comments of this slide in its rst file.
        * However, it is about something else.

    .. :

        1. **(0, 0):** Neither recently used nor modified
        2. **(0, 1):** Not recently used, but modified.
        3. **(1, 0):** Strip of its reference bit if passed
        4. **(1, 1):** (0, 1)

        The Two-Pass Logic

        The clock hand performs a single rotation (or partial rotation), but it operates as a two-pass scan to find a victim.

            Pass 1 (The "Soft" Scan): The hand looks for the "best" page (0,0) or (0,1). If it finds a page with R=1, it clears it to 0 as it passes. It does not replace anything in this pass. It is essentially "demoting" pages so they become candidates for replacement in the next pass.

            Pass 2 (The "Hard" Scan): If the hand completes a full rotation without finding a (0,0) or (0,1), it performs a second pass. Since it cleared all R bits in the first pass, it will now find the pages it previously demoted (now (0,0) or (0,1)) and select one for replacement.

        To answer your specific point:
        Yes, the algorithm searches the frames at most twice (two passes). It clears the R bits during the first pass to prepare the frames for the second pass.


.. slido:: Page Buffering History & Architecture
   :class: t2cs

    .. class:: step

    * Problems
        .. class:: step

        * Choosing correct victim
        * Writing dirty page to disk
    * **Page Buffering Solution**
        .. class:: step

        * Reserve free pages
        * from VAX/VMS to all modern kernels
    * **Free Frame Pool**
        .. class:: step

        * unallocated frames
        * victim pages

            .. class:: step

            #. Unmodified
            #. Modified

    .. class:: step

    + **Modified Frame Pool**
        * list of dirty frames in memory
        * Written to disk in bulk asynchronously
        * batch I/O rather than on-demand.
    + **Page Fault** in Modified Pool
    + **Soft Page Fault**
    + Can be added to FIFO,Clock, etc.

    .. grafo::
       :align: center
       :class: step

        digraph PageBuffering {
            rankdir=LR;
            fontname="Helvetica";
            bgcolor="transparent";

            node [shape=box, style="filled,rounded", fillcolor="#f5f5f5", fontname="Helvetica-Bold", width=1.6, height=0.8];

            // Primary structures
            victim  [label="Victim Page\n(Chosen for Eviction)", fillcolor="#ffe0b2", color="#fb8c00"];
            free    [label="Free Frame Pool\n(Clean Pages)", fillcolor="#c8e6c9", color="#4caf50", penwidth=2];
            dirty   [label="Modified Frame Pool\n(Dirty Pages)", fillcolor="#ffccbc", color="#ff5722", penwidth=2];
            disk    [label="Secondary Storage\n(Disk Swap / Files)", shape=cylinder, fillcolor="#e0e0e0"];

            // Routing logic
            victim -> free [label=" If Clean ", fontname="Courier", fontsize=11, color="#4caf50"];
            victim -> dirty [label=" If Dirty ", fontname="Courier", fontsize=11, color="#ff5722"];

            dirty -> disk [label=" Asynchronous\nBatch Write ", fontname="Courier", fontsize=11, style=dashed, color="#757575"];
            disk -> free [label=" Cleared &\nRecycled ", fontname="Courier", fontsize=11, color="#757575"];

            // The Soft Fault Recovery path
            rescue [shape=plaintext, label="⚡ Soft Fault\n(Instant Rescue)", fontcolor="#0288d1", fontname="Helvetica-Bold"];
            rescue -> dirty [color="#0288d1", style=bold, dir=back, arrowtail=normal];
        }

    .. komento:

        * **Teaching Point:** Emphasize that the "Modified Frame Pool" effectively turns random write requests into sequential batch writes, heavily optimizing disk throughput.
        * Note the "Soft Fault" path—remind students that this serves as a safety net or cache before the page is written out and destroyed.


    .. :

        Historically, standard page replacement algorithms (like FIFO or LRU) suffered a severe performance penalty when a selected "victim" page was dirty:

        * **The Traditional Bottleneck:** The faulting process had to block and wait while the dirty page was actively written to disk *before* the new page could be read into that same frame.
        * **The Page Buffering Solution:** Pioneered extensively in systems like VAX/VMS and later refined in modern kernels, **Page Buffering** decouples page eviction from disk I/O by maintaining pools of readily available physical frames.

        .. class:: substep

            Instead of discarding frames entirely, the system reallocates them into two logical system caches:

            1. **Free Frame Pool:** A list of clean, unallocated frames. Faults are read into these immediately without waiting for an eviction clean-up.
            2. **Modified Frame Pool:** A list of dirty frames. These are kept in memory and written to disk in bulk asynchronously (batch I/O) rather than on-demand.


        The system continuously cycles frames through pools.
        If a process faults for a page that is still sitting in the Modified Pool before it hits disk,
        it can be rescued instantly without any disk access (a *soft page fault*).

.. slido:: Page Buffering in Action

    .. image:: os/img/memory/page_buffer.png
       :class: center
       :scale: 180%

    .. class:: step

    https://docs.google.com/spreadsheets/d/1WtKolLTw4UJijHHwvhO9yqOotsLl91838vSZ00m4xwc/edit?gid=0#gid=0

.. slido:: Thrashing
   :class: t2c

    .. image:: os/img/memory/memory_virtual_thrashing.png
       :align: center

    .. code:: asm
       :class: step

        mov A, B

        ; How many frames does it access?
        ; What is the maximum?
        ; What is the minimum?

.. slido:: Principle of Locality(Cache Memory & Locality in os.mem.rst)
   :class: t2c

    * **The Principle of Locality**
    * Programs do not access memory completely at random
    * They cluster around specific addresses.
    * **Temporal Locality**
        * loop variables
        * function parameters
        * variable sum
    * **Spatial Locality**
        * sequential array traversal
        * a[i+1] after a[i]
        * streaming instructions

    .. image:: os/img/memory/memory_virtual_locality_principle.png
       :align: center

    .. include:: os/src/memory_virtual_effect_of_array_programming_row.cpp
       :code: cpp
       :number-lines:

    .. include:: os/src/memory_virtual_effect_of_array_programming_column.cpp
       :code: cpp
       :number-lines:


.. slido:: Working Set Model

    .. image:: os/img/memory/memory_virtual_thrashing_working_set_model.png
       :align: center

    .. container:: step

        .. image:: os/img/memory/memory_virtual_thrashing_working_set_model_example.png
           :align: center
           :class: step
           :scale: 80%

.. slido:: Page Fault Frequency (PFF)

    .. image:: os/img/memory/memory_virtual_thrashing_page_fault_frequency.png
       :align: center
       :width: 800px

    .. class:: rtl-h2 step

        روش‌های رویارویی با کوبیدگی پس از شناسایی آن

    .. class:: step rtl

       *  معلق کردن تعدادی فرآیند برگزیده شده
       * نپذیرفتن فرآیند جدید

.. slido:: Memory and I/O Mapped Files
   :class: t2c

    .. image:: os/img/memory/memory_virtual_memory_mapped_files.png
       :align: center

    .. class:: step

        #. Graphic card
        #. Network

        * **Lock pages**

.. slido:: Copy-on-Write
   :class: t2c

    .. image:: os/img/memory/memory_virtual_copy_on_write_before.png
       :align: center

    .. container:: step

        .. image:: os/img/memory/memory_virtual_copy_on_write_after.png
           :align: center

.. slido:: References(I)

    * http://os-book.com/
    * Sean K. Barker (https://tildesites.bowdoin.edu/~sbarker/)
        * https://tildesites.bowdoin.edu/~sbarker/teaching/courses/os/14spring/slides/lec12.pdf
        * https://tildesites.bowdoin.edu/~sbarker/teaching/courses/os/14spring/lectures.html
    * http://blog.cs.miami.edu/burt/2012/10/31/virtual-memory-pages-and-page-frames/
    * https://www.javatpoint.com/os-segmented-paging
    * https://www.geeksforgeeks.org/difference-between-internal-and-external-fragmentation/
    * https://binaryterms.com/contiguous-memory-allocation-in-operating-system.html
    * https://github.com/mor1/ia-operating-systems/wiki/06-Virtual-Addressing
    * https://github.com/mor1/ia-operating-systems
    * https://slideplayer.com/slide/7084682/

    * http://images.bit-tech.net/content_images/2007/11/the_secrets_of_pc_memory_part_1/hei.png
    * https://answers.microsoft.com/en-us/windows/forum/windows_10-performance/physical-and-virtual-memory-in-windows-10/e36fb5bc-9ac8-49af-951c-e7d39b979938
    * Gemini AI, Chatgpt, duck.ai

.. slido:: References(III)

    * https://upload.wikimedia.org/wikipedia/commons/c/c2/Write-back_with_write-allocation.svg
    * https://www.byclb.com/TR/Tutorials/dsp_advanced/ch1_1_dosyalar/image025.jpg
    * https://en.wikipedia.org/wiki/File:Cache,hierarchy-example.svg
    * https://tutorialspoint.dev/image/Translation.png
    * https://www.cs.princeton.edu/courses/archive/spr11/cos217/lectures/18MemoryMgmt.pdf
    * http://harmanani.github.io/classes/csc320/Notes/ch05.pdf
    * https://www.cs.princeton.edu/courses/archive/spr11/cos217/lectures/18MemoryMgmt.pdf
    * https://www.mvorganizing.org/what-is-principle-of-locality-in-operating-system/
    * https://en.wikipedia.org/wiki/Locality_of_reference
    * http://www2.cs.uregina.ca/~hamilton/courses/330/notes/memory/page_replacement.html
    * https://prepinsta.com/operating-systems/page-replacement-algorithms/least-recently-used-lru-algorithm/
    * https://examradar.com/nru-not-recently-used-page-replacement-algorithm-questions-answers/
    * https://japp.io/algorithms/page-replacement/lfu-page-replacement-algorithm-program-in-c-c/
    * https://www.kernel.org/doc/
    * https://codex.cs.yale.edu/avi/os-book/
