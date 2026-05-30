.. role:: ltr
    :class: ltr

.. prezento:: Monitor (By Ahmad Yoosofan)
   :skip-help: true
   :css: assets/style.css
   :substep: true
   :slide-numbers: true

.. slido::
   :skip-help: true
   :css: style.css
   :substep: true

    .. title: Monitor (By Ahmad Yoosofan)

    :slide-numbers: true

    .. role:: ltr
        :class: ltr

.. slido:: Monitor

    .. image:: os/img/ps/monitor.png

.. slido:: Dining-Philosophers

    .. image:: os/img/ps/An_illustration_of_the_dining_philosophers_problem_small_wikipedia.png

.. slido::

    .. include:: os/src/ps/dining_philosopher_monitor_7.cpp
        :code: cpp
        :number-lines:

.. slido::

    .. include:: os/src/ps/dining_philosopher_monitor_10.cpp
        :code: cpp
        :number-lines:

.. slido::

    .. include:: os/src/ps/dining_philosopher_monitor_11_1.cpp
        :code: cpp
        :number-lines:

.. slido::

    .. include:: os/src/ps/dining_philosopher_monitor_11_3.cpp
        :code: cpp
        :number-lines:

.. slido::

    .. include:: os/src/ps/dining_philosopher_monitor_11_4.cpp
        :code: cpp
        :number-lines:

.. slido::

    .. include:: os/src/ps/dining_philosopher_monitor_11_5.cpp
        :code: cpp
        :number-lines:

.. slido::

    .. include:: os/src/ps/dining_philosopher_monitor_11_6.cpp
        :code: cpp
        :number-lines:

.. slido::

    .. include:: os/src/ps/dining_philosopher_monitor_11.cpp
        :code: cpp
        :number-lines:

.. slido::

    .. include:: os/src/ps/dining_philosopher_monitor_12_1.cpp
        :code: cpp
        :number-lines:

.. slido::

    .. include:: os/src/ps/dining_philosopher_monitor_12_2.cpp
        :code: cpp
        :number-lines:

.. slido::

    .. include:: os/src/ps/dining_philosopher_monitor_12_3.cpp
        :code: cpp
        :number-lines:

.. slido::

    .. include:: os/src/ps/dining_philosopher_monitor_12_4.cpp
        :code: cpp
        :number-lines:

.. slido::

    .. include:: os/src/ps/dining_philosopher_monitor_12_5.cpp
        :code: cpp
        :number-lines:

.. slido::

    .. include:: os/src/ps/dining_philosopher_monitor_12.cpp
        :code: cpp
        :number-lines:

.. slido::

    .. include:: os/src/ps/dining_philosopher_monitor_13.cpp
        :code: cpp
        :number-lines:

.. slido::

    .. include:: os/src/ps/dining_philosopher_monitor_original.cpp
        :code: cpp
        :number-lines:

.. slido::

    .. image:: os/img/ps/dining_philosohoer_original_from_silbershatz.png

.. slido::

    .. include:: os/src/ps/dining_philosopher_monitor_20.cpp
        :code: cpp
        :number-lines:

.. slido::

    .. include:: os/src/ps/monitor_implementation_by_semaphore.cpp
        :code: cpp
        :number-lines:

.. slido:: Producer & Consumer

    .. include:: os/src/ps/bounded_buffer_monitor.cpp
        :code: cpp
        :number-lines:

.. slido:: Monitor with notify

    .. include:: os/src/ps/bounded_buffer_by_notify_monitor.cpp
        :code: cpp
        :number-lines:

.. slido:: Monitor with priority

    .. include:: os/src/ps/dining_philosopher_monitor_20_priority.cpp
        :code: cpp
        :number-lines:

.. slido:: Send And Receive

    * Send
    * Receive

    Syntax

.. slido::

    * send(process: process_id, message: string)
    * receive(process: process_id, varmessage: string)

    #. block
    #. non-block

.. slido:: Message Passing

    Two fundamental communication & synchronization

    Shared memory

.. slido::

    * Efficient, familiar
    * Not always available
    * Potentially insecure

    Message passing

.. slido::

    * Awkward, less standardized
    * Extensible to communication in distributed systems

.. slido::

    .. image:: os/img/ps/message_passing_send.png

.. slido::

    .. image:: os/img/ps/message_box_receive.png

.. slido::

    .. image:: os/img/ps/message_all.png

.. slido::

    .. image:: os/img/ps/message_indirect.png

.. slido::

    .. image:: os/img/ps/message_format.png

.. slido::

    .. include:: os/src/ps/mutual_exclusion_by_message.cpp
        :code: cpp
        :number-lines:

.. slido::

    .. include:: os/src/ps/mutual_exclusion_by_message2.cpp
        :code: cpp
        :number-lines:

.. slido::

    .. include:: os/src/ps/pcbmessage.cpp
        :code: cpp
        :number-lines:

.. slido::

    .. include:: os/src/ps/pcbmessage_limited_message.cpp
        :code: cpp
        :number-lines:

.. slido:: Some tools

    MPI & MPICH

.. slido::

    * https://en.wikipedia.org/wiki/Message_Passing_Interface
    * https://mpitutorial.com/
    * https://mpich.org
    * https://www.cs.usfca.edu/~peter/ppmpi/
    * http://wgropp.cs.illinois.edu/bib/talks/tdata/2004/mpi-half-day-public.pdf
    * https://princetonuniversity.github.io/PUbootcamp/sessions/parallel-programming/Intro_PP_bootcamp_2018.pdf
    * https://github.com/mpi4py/mpi4py

    PVM

.. slido::

    * https://www.mcs.anl.gov/research/projects/mpi/tutorial/mpiintro/ppframe.htm
    * https://www.csm.ornl.gov/pvm/pvm_home.html

.. slido:: References:

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
