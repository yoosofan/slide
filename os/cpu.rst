:data-transition-duration: 1
:skip-help: true
:css: style.css cpu.css
:js: test1.js
:substep: true
:slide-numbers: true
:skip-help: true

.. title: Operating Systems: CPU Scheduling

.. role:: raw-html(raw)
   :format: html

.. |nbsp| unicode:: 0xA0 

.. :

   :trim:

----

Operating Systems: CPU Scheduling
===============================================
Ahmad Yoosofan
-----------------------------
https://yoosofan.github.io

University of Kashan

----

:class: t2c

CPU Burst / Service Time
==============================
.. class:: substep

* cpu utilization by multiprogramming
* cpu - I/O cycle of a process
* cpu : burst time, service time
* I/O : or other blocking events like memory request

.. image:: img/cpu/burst.png
  :scale: 80%

----

CPU Schedular
================
Short Term Schedular
----------------------
.. class:: substep

* ready queue
* Dispatcher

.. image:: img/in/process_state_chart.png

----

Time Unit Concept
==================
* Millisecond
* Nanosecond
* ?

----

Scheduling type
====================
* nonpreemptive
* preemptive

----

:class: t2c

Processes Table
==========================
.. csv-table::
  :header: process, service(Burst) time

  :math:`p_0`, 3
  :math:`p_1`, 2
  :math:`p_2`, 1
  :math:`p_3`, 2

.. csv-table::
  :header: process, service time, arrival time
  :class: substep

  :math:`p_0`, 3, 0
  :math:`p_1`, 2, 0
  :math:`p_2`, 1, 3
  :math:`p_3`, 2, 5


----

:id: cpu-test2-id

First-Come, First-Served (FCFS)
==================================
.. csv-table::
  :header: process, service time, arrival time

  :math:`p_0`, 2, 0
  :math:`p_1`, 1 ,0
  :math:`p_2`, 2, 3
  :math:`p_3`, 1, 4

.. container:: yoo-gantt-chart

    .. class:: withborder 

    * 
    * :math:`P_0`
    * 
    * :math:`P_1`
    * 
    * :math:`P_2`
    * 
    * :math:`P_3`
    * 

    .. class:: yoo-x-numbers

    * 0
    * 
    * 2
    * 
    * 3
    * 
    * 5
    * 
    * 6

.. class:: substep

*  t = 0: ready queue(q) = [:math:`p_0`, :math:`p_1`]
*  t = 2: q = [:math:`p_1`]
*  t = 3: q = [:math:`p_2`]
*  t = 5: q = [:math:`p_3`]

----

.. csv-table:: cpu
  :class: yoo-gantt-chart-set-width-based-on-data

  :raw-html:`&nbsp;&nbsp;` :math:`P_0` :raw-html:`&nbsp;&nbsp;`, ,:raw-html:`&nbsp;` :math:`P_1` :raw-html:`&nbsp;`, ,:raw-html:`&nbsp;&nbsp;` :math:`P_2` :raw-html:`&nbsp;&nbsp;`, , :raw-html:`&nbsp;` :math:`P_3` :raw-html:`&nbsp;`,
  0, , 2, , 3, , 5, , 6 

.. csv-table:: cpu
  :class: yoo-gantt-chart-set-width-based-on-data

  |nbsp| |nbsp| :math:`P_0` |nbsp| |nbsp|, ,|nbsp| :math:`P_1` |nbsp|, ,|nbsp| |nbsp| :math:`P_2` |nbsp| |nbsp|, , |nbsp| :math:`P_3` |nbsp|,
  0, , 2, , 3, , 5, , 6 

----

:id: cpu-average-waiting-id

Average Waiting Time
==================================
.. csv-table::
  :header: process, service time, arrival time

  :math:`p_0`, 2, 0
  :math:`p_1`, 1 ,0
  :math:`p_2`, 2, 3
  :math:`p_3`, 1, 4

.. container:: yoo-gantt-chart  substep

  .. class:: withborder 

  * 
  * :math:`P_0`
  * 
  * :math:`P_1`
  * 
  * :math:`P_2`
  * 
  * :math:`P_3`
  * 

  .. class:: yoo-x-numbers

  * 0
  * 
  * 2
  * 
  * 3
  * 
  * 5
  * 
  * 6

.. class:: substep

*  :math:`P_0` waiting time: 0
*  :math:`P_1` waiting time: 2
*  :math:`P_2` waiting time: (3-3) = 0
*  :math:`P_3` waiting time: (5-4) = 1
*  *Average Waiting Time*: :math:`\frac{0 + 2 + 0 + 1}{4} = \frac{3}{4} = 0.75`
 
----

:id: FCFS-Convoy-effect-id

.. :

  short process behind long process

FCFS - Convoy effect
=========================
.. csv-table::
  :header: process, service time, arrival time

  :math:`p_0`, 4, 0
  :math:`p_1`, 6 ,0
  :math:`p_2`, 1, 3
  :math:`p_3`, 3, 4



.. container:: yoo-gantt-chart 

    .. class:: withborder 

    * 
    * :math:`P_0`
    * 
    * :math:`P_1`
    * 
    * :math:`P_2`
    * 
    * :math:`P_3`
    * 

    .. class:: yoo-x-numbers

    * 0
    * 
    * 4
    * 
    * 10
    * 
    * 11
    * 
    * 14

    .. class:: substep

        *Average Waiting Time 1*: :math:`\frac{0 + (4-0) + (10-3) + (11-4)}{4} = \frac{17}{4} = 3\frac{1}{4} = 3.25`

        *Rearange*

    .. class:: withborder substep

    * 
    * :math:`P_0`
    * 
    * :math:`P_2`
    * 
    * :math:`P_3`
    * 
    * :math:`P_1`
    * 

    .. class:: yoo-x-numbers

    * 0
    * 
    * 4
    * 
    * 5
    * 
    * 8
    * 
    * 14

    .. class:: substep

    *Average Waiting Time 2*: :math:`\frac{0 + (4-3) + (5-4) + 8}{4} = \frac{10}{4} = 2\frac{2}{4} = 1.5`

.. class:: substep

* *Average Waiting Time* 1: 3.25
* *Average Waiting Time* 2: 1.5
* 1: FCFS
* 2: Shortest Job First(SJF) or Shortest Process Next(SPN)

----

:id: sjf-spn-id

SJF/SPN
=========================
.. csv-table::
  :header: process, service time, arrival time

  :math:`p_0`, 6, 0
  :math:`p_1`, 4, 0
  :math:`p_2`, 1, 3
  :math:`p_3`, 3, 4


.. container:: yoo-gantt-chart 

    .. class:: withborder substep

    * 
    * :math:`P_1`
    * 
    * :math:`P_2`
    * 
    * :math:`P_3`
    * 
    * :math:`P_0`
    * 

    .. class:: yoo-x-numbers

    * 0
    * 
    * 4
    * 
    * 5
    * 
    * 8
    * 
    * 14

    .. class:: substep

    *Average Waiting Time*: :math:`\frac{0 + (4-3) + (5-4) + 8}{4} = \frac{10}{4} = 2\frac{2}{4} = 1.5`

.. class:: substep

* Starvation
* Nonpreemptive

----

:id: srt-id

Shortest Remaining Time(SRT), preemptive SJF
================================================
.. csv-table::
  :header: process, service time, arrival time

  :math:`p_0`, 4, 0
  :math:`p_1`, 6 ,0
  :math:`p_2`, 1, 1
  :math:`p_3`, 3, 2

.. container:: yoo-gantt-chart 

    .. class:: withborder 

    * 
    * :math:`P_0`
    * 
    * :math:`P_1`
    * 
    * :math:`P_2`
    * 
    * :math:`P_3`
    * 

    .. class:: yoo-x-numbers

    * 0
    * 
    * 4
    * 
    * 10
    * 
    * 11
    * 
    * 14

    .. class:: substep

        *Average Waiting Time 1*: :math:`\frac{0 + (4-0) + (10-3) + (11-4)}{4} = \frac{17}{4} = 3\frac{1}{4} = 3.25`

        *Rearange*

    .. class:: withborder substep

    * 
    * :math:`P_0`
    * 
    * :math:`P_2`
    * 
    * :math:`P_3`
    * 
    * :math:`P_1`
    * 

    .. class:: yoo-x-numbers

    * 0
    * 
    * 4
    * 
    * 5
    * 
    * 8
    * 
    * 14

    .. class:: substep

    *Average Waiting Time 2*: :math:`\frac{0 + (4-3) + (5-4) + 8}{4} = \frac{10}{4} = 2\frac{2}{4} = 1.5`


.. class:: substep

* *Average Waiting Time* 1: 3.25
* *Average Waiting Time* 2: 1.5
* 1: FCFS
* 2: Shortest Job First(SJF) or Shortest Process Next(SPN)

----

.. class:: substep

* :raw-html:`<h2>` Scheduling Criteria :raw-html:`</h2>`
    * *CPU utilization* : keep the CPU as busy as possible
    * *Throughput* : number of processes that complete their execution per time unit
    * *Turnaround time* : amount of time to execute a particular process
    * *Waiting time* : amount of time a process has been waiting in the ready queue
    * *Response time* : amount of time it takes from when a request was submitted until the first response is produced, not output (for time-sharing environment)
*  :raw-html:`<h2>` Optimization Criteria  :raw-html:`</h2>`
    * Max CPU utilization
    * Max throughput
    * Min turnaround time
    * Min waiting time
    * Min response time

.. :

  * p0 :raw-html:`&nbsp&nbsp&nbsp` p1  p2
  * 0 :raw-html:`&nbsp&nbsp&nbsp&nbsp` 1 :raw-html:`&nbsp&nbsp` 2

