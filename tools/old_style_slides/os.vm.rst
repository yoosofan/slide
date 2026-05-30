.. role:: ltr
    :class: ltr

.. role:: rtl
    :class: rtl

.. prezento:: Operating Systems - Virtual Memory  (By Ahmad Yoosofan)
   :skip-help: true
   :css: ./assets/style.css
   :substep: true
   :data-width: 1024
   :data-height: 768
   :slide-numbers: true

.. slido:: Operating Systems

    Virtual Memory

.. slido::

    Ahmad Yoosofan

    University of Kashan

.. slido:: Virtual Memory

    .. image:: os/img/memory/memory_virtual_memory_general.png
       :align: center
       :height: 500px

.. slido::

    .. image:: os/img/memory/virtual_memory_concept.png
       :align: center
       :height: 500px

.. slido:: Virtual Memory Addressing

    .. image:: os/img/memory/virtual_memory_addressing.png
       :align: center

.. slido::

    .. image:: os/img/memory/memory_virtual_with_TLB.png
       :align: center
       :height: 550px

.. slido::

    .. image:: os/img/memory/memory_virtual_valid_invalid.png
       :align: center
       :height: 550px

.. slido::

    .. image:: os/img/memory/memory_virtual_handling_page_fault.png
       :align: center
       :height: 550px

.. slido::

    .. image:: os/img/memory/memory_virtual_Operation_of_Paging_and_Translation_Lookaside_Buffer.png
       :align: center
       :height: 550px

.. slido:: Effective Access Time of Virtual Memory

    .. class:: substep

        * effective access time = (1 − p) × ma + p × page fault time.
        * effective access time = (1 − p) × (200) + p (8 milliseconds) = (1 − p) × 200 + p × 8,000,000 = 200 + 7,999,800 × p
        * 220 > 200 + 7,999,800 × p,
        * 20 > 7,999,800 × p,
        * p < 0.0000025

.. slido:: Allocation of frames

    .. class:: substep

    * On demand
    * prepaging

.. slido::

    .. class:: rtl-h1

        روش‌های تخصیص تعداد قاب به هر فرآیند

    .. class:: substep rtl-h3

        * مجموعهٔ مقیم برای هر فرآیند.

            *  تعداد ثابت fixed-allocation
            *  تعداد متغیر  variable-allocation

        * بخش کردن قاب‌ها میان فرآیندها

            *  تعداد برابر
            *  تعداد به نسبت اندازهٔ فرآیند

        * چگونگی برگزیدن یک قاب برای تخصیص به یک فرآیند

            *  تخصیص محلی
            *  تخصیص سراسری

.. slido::

    .. class:: rtl-h1

        سیاست‌های پاک کردن

    .. class:: substep rtl-h3

        *  پاک کردن درخواستی demand cleaning
        *  پیش پاک کردن precleaning

.. slido:: Page Replacement

    .. image:: os/img/memory/memory_virtual_need4replacement.png
       :align: center
       :height: 540px

.. slido::

    .. image:: os/img/memory/memory_virtual_page_replacement.png
       :align: center
       :width: 700px

.. slido:: Frame Allocation

    .. class:: substep

    * frame-allocation algorithm and a page-replacement algorithm.
    * reference string.
    * 0100, 0432, 0101, 0612, 0102, 0103, 0104, 0101, 0611, 0102, 0103, 0104, 0101, 0610, 0102, 0103, 0104, 0101, 0609, 0102, 0105
    * At 100 bytes per page, this sequence is reduced to the following reference
    * string:
    * 1, 4, 1, 6, 1, 6, 1, 6, 1, 6, 1

    .. class:: substep rtl-h3

    *  تعداد خطای نبود صفحه بسته به تعداد قاب‌های تخصیص داده شده

.. slido::

    .. image:: os/img/memory/memory_virtual_page_fault_per_frame_allocated.png
        :align: center
        :width: 750px

.. slido:: FIFO

    .. image:: os/img/memory/memory_virtual_page_replacement_FIFO.png
       :align: center
       :width: 700px

.. slido:: Belady’s anomaly

    .. image:: os/img/memory/memory_virtual_page_replacement_FIFO_Blady_anomaly.png
       :align: center
       :width: 700px

.. slido:: Optimal

    .. image:: os/img/memory/memory_virtual_page_replacement_Optimal.png
       :align: center
       :width: 700px

.. slido:: Not Recently Used Page(NRU)

    .. image:: os/img/memory/memory_virtual_page_replacement_LRU.png
       :align: center
       :width: 700px

    NRU vs LRU

.. slido:: Least Recently Used(LRU)

    How to Impolement LRU

.. slido::

    * counters
    * stacks

    LFU

.. slido::

    Least Frequently Used

    MFU

.. slido::

    Most Frequently Used

    page-replacement algorithm is based on the argument that the page with the smallest count was probably just brought in and has yet to be used

.. slido:: Use of a stack to record the most recent page references

    .. image:: os/img/memory/memory_virtual_page_replacement_LRU_stack.png
       :align: center
       :width: 700px

.. slido:: Second chance (clock)

    Simplest implementation of NRU and LRU by using one bit

.. slido::

    * access bit,
    * reference bit, or
    * use bit

    Some called this NRU

.. slido::

    * as an approximation to LRU, select one of the pages that has not been used recently (as opposed to identifying exactly which one has not been used for the longest amount of time)
    * keep one bit called the "used bit" or "reference bit", where 1 => used recently and 0 => not used recently
    * variants of this scheme are used in many operating systems, including UNIX and MacIntosh
    * most variations use a scan pointer and go through the page frames one by one, in some order, looking for a page that has not been used recently.

.. slido::

    .. image:: os/img/memory/memory_virtual_page_replacement_second_chance.png
       :align: center
       :height: 550px

.. slido:: Modefied Clock

    Enhanced Second Chance

.. slido::

    By the usage of

    * modify bit or
    * dirty bit

    ("modify bit", "use bit" or "access bit")

    .. class:: substep

        * Form 1
            #. Search for (0, 0)
            #. Search for (1, 0) and access bit = 0
            #. goto 1
        * Form 2
            #. Search for (0, 0)
            #. Search for (1, 0) and access bit = 0
            #. Search for (0, 0)
            #. Search for (1, 0)

.. slido:: PAGE BUFFERING

    .. image:: os/img/memory/page_buffer.png
      :width: 800px

.. slido:: Thrashing

    .. image:: os/img/memory/memory_virtual_thrashing.png
       :align: center

    .. code:: asm

      mov A, B

.. slido:: Principle of Locality(Locality of Reference)

    .. image:: os/img/memory/memory_virtual_locality_principle.png
      :align: center
      :height: 500px

.. slido:: Working Set Model

    .. image:: os/img/memory/memory_virtual_thrashing_working_set_model.png
       :align: center
       :width: 800px

.. slido::

    .. image:: os/img/memory/memory_virtual_thrashing_working_set_model_example.png
       :align: center
       :width: 800px

.. slido::

    .. image:: os/img/memory/memory_virtual_thrashing_working_set_model_graph.png
       :align: center
       :width: 800px

.. slido::

    .. class:: rtl-h1

        روش شناسایی کوبیدگی به کمک فراوانی خطای نبود صفحه


    page-fault frequency ( PFF )

    .. image:: os/img/memory/memory_virtual_thrashing_page_fault_frequency.png
       :align: center
       :width: 800px

.. slido::

    .. class:: rtl-h1

        روش‌های رویارویی با کوبیدگی پس از شناسایی آن

    .. class:: substep rtl

       *  معلق کردن تعدادی فرآیند برگزیده شده
       * نپذیرفتن فرآیند جدید

.. slido::

    .. class:: rtl-h1

        پرونده‌های نگاشت شده به حافظه (Memory-Mapped Files)

    .. image:: os/img/memory/memory_virtual_memory_mapped_files.png
       :align: center
       :width: 650px

.. slido::

    .. class:: rtl-h1

      ورودی و خروجی‌های نگاشت شده به حافظه

    (I/O-Mapped Files)

    .. class:: substep

    #. Graphic card
    #. Network

.. slido::

    .. class:: rtl-h1

      قفل کردن برخی صفحه‌ها

    Lock pages

.. slido:: Copy-on-Write

    .. image:: os/img/memory/memory_virtual_copy_on_write_before.png
       :align: center
       :width: 750px

.. slido::

    .. image:: os/img/memory/memory_virtual_copy_on_write_after.png
       :align: center
       :width: 750px

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

.. slido:: References(II)

    * http://images.bit-tech.net/content_images/2007/11/the_secrets_of_pc_memory_part_1/hei.png
    * https://answers.microsoft.com/en-us/windows/forum/windows_10-performance/physical-and-virtual-memory-in-windows-10/e36fb5bc-9ac8-49af-951c-e7d39b979938
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

.. slido:: References(III)

    * https://examradar.com/nru-not-recently-used-page-replacement-algorithm-questions-answers/
    * https://japp.io/algorithms/page-replacement/lfu-page-replacement-algorithm-program-in-c-c/
    * https://www.kernel.org/doc/
    * https://codex.cs.yale.edu/avi/os-book/
