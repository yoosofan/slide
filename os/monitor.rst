:data-transition-duration: 1000
:skip-help: true
:css: style.css
:substep: true

.. title: Monitor (By Ahmad Yoosofan)

:slide-numbers: true

.. role:: ltr
    :class: ltr

----


Monitor
===================================================
.. image:: img/process_synchronization/monitor.png

----

Dining-Philosophers
============================
.. image:: img/process_synchronization/An_illustration_of_the_dining_philosophers_problem_small_wikipedia.png

----

.. include:: src/ps/dining_philosopher_monitor_7.cpp
    :code: cpp
    :number-lines:

----

.. include:: src/ps/dining_philosopher_monitor_10.cpp
    :code: cpp
    :number-lines:

----

.. include:: src/ps/dining_philosopher_monitor_11_1.cpp
    :code: cpp
    :number-lines:

----


.. include:: src/ps/dining_philosopher_monitor_11_3.cpp
    :code: cpp
    :number-lines:

----

.. include:: src/ps/dining_philosopher_monitor_11_4.cpp
    :code: cpp
    :number-lines:

----

.. include:: src/ps/dining_philosopher_monitor_11_5.cpp
    :code: cpp
    :number-lines:

----

.. include:: src/ps/dining_philosopher_monitor_11_6.cpp
    :code: cpp
    :number-lines:

----

.. include:: src/ps/dining_philosopher_monitor_11.cpp
    :code: cpp
    :number-lines:

----

.. include:: src/ps/dining_philosopher_monitor_12_1.cpp
    :code: cpp
    :number-lines:

----

.. include:: src/ps/dining_philosopher_monitor_12_2.cpp
    :code: cpp
    :number-lines:

----

.. include:: src/ps/dining_philosopher_monitor_12_3.cpp
    :code: cpp
    :number-lines:

----

.. include:: src/ps/dining_philosopher_monitor_12_4.cpp
    :code: cpp
    :number-lines:

----

.. include:: src/ps/dining_philosopher_monitor_12_5.cpp
    :code: cpp
    :number-lines:

----

.. include:: src/ps/dining_philosopher_monitor_12.cpp
    :code: cpp
    :number-lines:

----

.. include:: src/ps/dining_philosopher_monitor_13.cpp
    :code: cpp
    :number-lines:

----

.. include:: src/ps/dining_philosopher_monitor_original.cpp
    :code: cpp
    :number-lines:

----

.. image:: img/process_synchronization/dining_philosohoer_original_from_silbershatz.png


----

.. include:: src/ps/dining_philosopher_monitor_20.cpp
    :code: cpp
    :number-lines:

----

.. include:: src/ps/monitor_implementation_by_semaphore.cpp
    :code: cpp
    :number-lines:

----

Producer & Consumer
==================================
.. include:: src/ps/bounded_buffer_monitor.cpp
    :code: cpp
    :number-lines:

----

Monitor with notify
==========================
.. include:: src/ps/bounded_buffer_by_notify_monitor.cpp
    :code: cpp
    :number-lines:

----

Monitor with priority
==========================
.. include:: src/ps/dining_philosopher_monitor_20_priority.cpp
    :code: cpp
    :number-lines:

----

Send And Receive
==========================
* Send
* Receive

Syntax
-------------------------
* send(process: process_id, message: string)
* receive(process: process_id, varmessage: string)

#. block
#. non-block

----

Message Passing
==========================
Two fundamental communication & synchronization

Shared memory
------------------
* Efficient, familiar
* Not always available
* Potentially insecure

Message passing
----------------------
* Awkward, less standardized
* Extensible to communication in distributed systems

----

.. image:: img/process_synchronization/message_passing_send.png

----

.. image:: img/process_synchronization/message_box_receive.png

----

.. image:: img/process_synchronization/message_all.png

----


.. image:: img/process_synchronization/message_indirect.png

----

.. image:: img/process_synchronization/message_format.png

----

.. include:: src/ps/mutual_exclusion_by_message.cpp
    :code: cpp
    :number-lines:

----

.. include:: src/ps/mutual_exclusion_by_message2.cpp
    :code: cpp
    :number-lines:

----

.. include:: src/ps/pcbmessage.cpp
    :code: cpp
    :number-lines:

----

.. include:: src/ps/pcbmessage_limited_message.cpp
    :code: cpp
    :number-lines:

----

Some tools
==============

MPI & MPICH
------------
* https://en.wikipedia.org/wiki/Message_Passing_Interface
* https://mpitutorial.com/
* https://mpich.org
* https://www.cs.usfca.edu/~peter/ppmpi/
* http://wgropp.cs.illinois.edu/bib/talks/tdata/2004/mpi-half-day-public.pdf
* https://princetonuniversity.github.io/PUbootcamp/sessions/parallel-programming/Intro_PP_bootcamp_2018.pdf
* https://github.com/mpi4py/mpi4py

PVM
-------------
* https://www.mcs.anl.gov/research/projects/mpi/tutorial/mpiintro/ppframe.htm
* https://www.csm.ornl.gov/pvm/pvm_home.html

----


References:
==================================================

* `<https://stackoverflow.com/questions/18550370/calculate-the-effective-access-time>`_
* `<http://os-book.com/>`_
* https://en.wikipedia.org/wiki/Paging
* http://cse.unl.edu/~goddard/Courses/CSCE351/Lectures/Lecture3.pdf

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


