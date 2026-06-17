.. role:: rtl
    :class: rtl

.. role:: rtl
    :class: rtl

.. prezento:: Disk Management (By Ahmad Yoosofan)
   :css: ./assets/style.css

.. slido:: Operating System

    Disk management

    Ahmad Yoosofan

    Spring 2024

.. slido:: Disk structure

    .. image:: os/img/disk/disk_Moving_head_disk_mechanism.png
       :align: center

.. slido::

    .. image:: os/img/disk/one_layer_disk.png
       :align: center

    .. :

        https://www.javatpoint.com/coa-auxiliary-memory

.. slido:: Storrage Areaa Network(SAN)

    .. image:: os/img/disk/disk_Storage_area_network.png
       :align: center

.. slido:: File Management System

    File Access Methods

.. slido::

    * Sequential Access
    * Random Access

.. slido:: Simple Access Disk

    .. image:: os/img/disk/disk_Example_of_index_and_relative_files.png

.. slido:: Simple Disk Organization

    .. image:: os/img/disk/disk_A_typical_file_system_organization.png

.. slido:: One Level Structure of Folders

    .. image:: os/img/disk/disk_Single_level_directory.png

.. slido:: Two Level Structure of Folders

    .. image:: os/img/disk/disk_Two_level_directory_structure.png

.. slido:: Acyclic Graph based Folder Structure

    .. image:: os/img/disk/disk_Acyclic_graph_directory_structure.png

.. slido:: General Graph based Folder Structure

    .. image:: os/img/disk/disk_General_graph_directory.png

.. slido:: Multi Level File Structure

    .. image:: os/img/disk/disk_Layered_file_system.png

.. slido:: Simple Control Block of a File

    .. image:: os/img/disk/disk_A_typical_file_control_block.png

.. slido:: File struture in Main Memory

    .. image:: os/img/disk/disk_In_memory_file_system_structures_a_File_open_b_File_read.png

    * (a) open file
    * (b) close file

.. slido:: Schematic View of Virtual File System

    .. image:: os/img/disk/disk_Schematic_view_of_a_virtual_file_system.png

.. slido:: Allocation Files Methods

    .

.. slido:: Contiguous Block Allocation

    .. image:: os/img/disk/disk_Contiguous_allocation_of_disk_space.png
      :width: 600px

    * External Fragmentation
    * Adding Block to File
    * Speed

.. slido:: List Block Allocation

    .. image:: os/img/disk/disk_Linked_allocation_of_disk_space.png

.. slido:: FAT Structure

    .. image:: os/img/disk/disk_File_allocation_table.png

.. slido:: Index Based Block Allocation

    .. image:: os/img/disk/disk_Indexed_allocation_of_disk_space.png

.. slido:: Contiguous Index Based Block Allocation

    .. image:: os/img/disk/disk_Indexed_Allocation_with_Variable_Length_Portions.png

.. slido:: Contiguous List Allocation

    .. image:: os/img/disk/disk_free_Linked_space_list_on_disk.png

.. slido:: File Structure in Unix

    .. image:: os/img/disk/disk_The_UNIX_inode.png

.. slido:: RAM in DISK

    .. image:: os/img/disk/compuram-ssd-performancetest-en.jpg

    .. :

        https://www.compuram.de/blog/en/ram-upgrade-andor-ssd-drive-whats-the-benefit/
        https://en.wikipedia.org/wiki/Solid-state_drive

    .. :

      .. image:: os/img/disk/0fdaa514-25ae-494d-b4a6-4e1ca52633f1.jpg

    .. :

        internal ssd disk ram hierarchy
        https://www.utmel.com/blog/categories/memory%20chip/solid-state-drive-ssd-classification-and-architecture
        https://www.diskmfr.com/know-how-internal-structure-details-of-solid-state-drives/

.. slido::

    File Allocation Methods Comparison

.. slido::

    .. :

        .. image:: os/img/disk/disk_File_Allocation_Methods.png


    .. class:: smallerelementwithfullborder center

    +----------------------------------+--------------+--------------+--------------+-----------+
    | Method                           | Contiguous   | Chained      | Indexed                  |
    +==================================+==============+==============+==========================+
    | Preallocation?                   | Necessary    | Possible     | Possible                 |
    +----------------------------------+--------------+--------------+--------------+-----------+
    | Fixed or Variable Size Portions? | Variable     | Fixed blocks | Fixed blocks | Variable  |
    +----------------------------------+--------------+--------------+--------------+-----------+
    | Portion Size                     | Large        | Small        | Small        | Medium    |
    +----------------------------------+--------------+--------------+--------------+-----------+
    | Allocation Frequency             | Once         | Low To High  | High         | Low       |
    +----------------------------------+--------------+--------------+--------------+-----------+
    | Time to Allocate                 | Medium       | Long         | Short        | Medium    |
    +----------------------------------+--------------+--------------+--------------+-----------+
    | File Allocation Table Size       | One Entry    | One Entry    | Large        | Meduim    |
    +----------------------------------+--------------+--------------+--------------+-----------+

.. slido:: Free Space Management

    * How do we keep track free blocks on a disk?
    * A free-list is maintained.  When a new block is requested, we search this list to find one.
    * The following are commonly used techniques:
        * Bit Vector
        * Linked List
        * Linked List + Grouping
        * Linked List+Address+Count

    Bit Vector

.. slido::

    * Each block is represented by a bit in a table.
    * If a block is free, its corresponding bit is 1.
    * When a block is needed, the table is searched.
    * If the disk capacity is small, the whole bit vector can be stored in memory.
    * For a large disk, this bit vector will consume too much memory.
    * We could group a few blocks into a clusterand allocate "clusters".
    * Another possibility is the use of a " summary table ".

.. slido:: Input Output Structure

    *  https://en.wikipedia.org/wiki/I/O_scheduling
    *  https://computationstructures.org/lectures/interrupts/interrupts.html

.. slido:: Computer Bus

    .. image:: os/img/disk/IO_A_typical_PC_bus_structure.png

.. slido:: Hardware Ports

    .. image:: os/img/disk/IO_Device_I_O_port_locations_on_PCs_partial.png

.. slido:: Status of Disk Requests

    .. image:: os/img/disk/IO_Device_status_table.png
      :width: 950px

.. slido:: Linux Block I/O Stack

    .. image:: os/img/disk/Linux_block_IO_stack.jpg
       :width: 800px

    `informit <https://www.informit.com/articles/article.aspx?p=2995360>`_

.. slido:: Disk I/O OS Terminology

    .. image:: os/img/disk/disk_io_operating_system_terminology.jpg
       :width: 950px

    `informit <https://www.informit.com/articles/article.aspx?p=2995360>`_

.. slido:: Disk Arm Scheduling Algorithms

    .. image:: os/img/disk/hdd_platter.svg
       :width: 900px

    http://gudok.xyz/sspar/

.. slido:: Operations performed during random access

    .. image:: os/img/disk/hdd_random_operations.svg
       :width: 850px

    http://gudok.xyz/sspar/

    .. : related websites

      https://www.geeksforgeeks.org/difference-between-seek-time-and-rotational-latency-in-disk-scheduling/
      https://www.geeksforgeeks.org/hard-disk-drive-hdd-secondary-memory/
      https://www.programmersought.com/article/73491676920/

.. slido:: Important Disk Parameters

    .. image:: os/img/disk/disk_important_parameters.png

    * Seek Time
    * Rotational Latency
    * Transfer Time
    * Disk Access Time
    * Disk Response Time

.. slido:: Imporatnce of Track or Cylinder

    زمان پیگیرد یا زمان جستجو

    Seek time

    .. class:: rtl

      * درخواست‌های فرآیندها به بخش‌های مختلف دیسک اشاره می‌کند که مهم‌ترین پارامتر رفتن به سیلندر مورد نظر است.

      * پس سیستم عامل در پایین‌ترین سطح کار خود با دیسک  دنباله‌ای از درخواست‌های به سیلندرهای گوناگون را  زمان‌بندی می‌کند.

    98, 183, 37, 122, 14, 124, 65, 67

.. slido:: FCFS

    .. image:: os/img/disk/disk_FCFS_disk_scheduling.png

    .. :

      .. image:: os/img/disk/disk_FCFS_disk_1.png

.. slido:: SSTF

    .. image:: os/img/disk/disk_SSTF_disk_scheduling.png

.. slido:: SCAN

    .. image:: os/img/disk/disk_SCAN_disk_scheduling.png

.. slido:: C-SCAN

    .. image:: os/img/disk/disk_C_SCAN_disk_scheduling.png

    .. : Further Reading

      https://arxiv.org/pdf/1403.0334.pdf

.. slido:: LOOK

    .. image:: os/img/disk/LOOKllLOOK.png

.. slido:: C-LOOK

    .. image:: os/img/disk/c_look.png

    .. :

      https://www.gatevidyalay.com/look-algorithm-disk-scheduling-algorithms/

.. slido:: F-SCAN

    .

.. slido:: N-Step Scan

    .

.. slido:: چند الگوریتم زمان‌بندی دیسک

    .. image:: os/img/disk/disk_Disk_Scheduling_Algorithms2.png
        :width: 950px

.. slido:: نمونه‌ای از مقایسهٔ چند الگوریتم

    .. image:: os/img/disk/disk_Comparison_of_Disk_Scheduling_Algorithms2.png
        :width: 950px

.. slido:: انجام ورودی/خروجی‌ها

    .. image:: os/img/disk/IO_The_life_cycle_of_an_I_O_request.png
       :align: center
       :width: 900px

.. slido:: RAID

    .. image:: os/img/disk/disk_raid_levels.png
       :width: 990px

    .. :

        https://docs.okd.io/4.14/virt/virtual_machines/virtual_disks/virt-hot-plugging-virtual-disks.html
        hot pluggable cpu


        **RAID**
        raid supported motherboards levels comparison
        https://en.wikipedia.org/wiki/Standard_RAID_levels
        raid levels table
        https://www.techtarget.com/searchstorage/answer/RAID-types-and-benefits-explained



        Error Detection
        checksum

        Error Correction
        https://en.wikipedia.org/wiki/Hamming_code

.. slido::

    .. comments:

        hovercraft disk.slide.rst
        hovercraft disk.slide.rst disk.slide/
        rst2html.py disk.slide.rst disk.slide.html --stylesheet=../../tools/farsi.css,html4css1.css
        https://www.geeksforgeeks.org/disk-scheduling-algorithms/
        http://www.csl.mtu.edu/cs4411.choi/www/Resource/chap11.pdf

        https://www.slideshare.net/J.T.A.JONES/disk-scheduling
        img/disk/disk-scheduling-general-view.png


        https://www.geeksforgeeks.org/transforming-of-i-o-requests-to-hardware-operations/
        https://medium.com/@bundetcom/understanding-disk-scheduling-947f67f2b160
        pyq.ravindrababuravula.com/topic/?tp=Disk-Scheduling
        https://www.gatevidyalay.com/look-algorithm-disk-scheduling-algorithms/
        https://www.gatevidyalay.com/disk-scheduling-disk-scheduling-algorithms/
        https://www.gatevidyalay.com/sstf-algorithm-disk-scheduling-algorithms/
        https://www.gatevidyalay.com/scan-algorithm-disk-scheduling-algorithms/
        https://www.gatevidyalay.com/c-scan-disk-scheduling-disk-scheduling/
        https://www.gatevidyalay.com/disk-scheduling-disk-scheduling-algorithms/
        https://www.javatpoint.com/os-look-and-c-look-scheduling
        https://www.geeksforgeeks.org/look-disk-scheduling-algorithm/
        nixchun.pixnet.net/blog/post/7989498
        https://www.gatevidyalay.com/look-algorithm-disk-scheduling-algorithms/
        https://www.geeksforgeeks.org/disk-scheduling-algorithms/
        https://prepinsta.com/operating-systems/disk-scheduling-algorithms/
        http://www.cs.iit.edu/~cs561/cs450/disksched/disksched.html
