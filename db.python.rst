.. role:: raw-html(raw)
   :format: html

.. prezento:: SQLite and python
   :css: ./assets/style.css

.. slido:: Database - Application - python

    Ahmad Yoosofan

    University of Kashan

.. slido:: Simple Application(I)
   :class: t2c

    .. include:: db/src/python-sqlite/sp220.py
        :code: python
        :number-lines:
        :class: step

    .. :

        https://docs.python.org/3/library/sqlite3.html#sqlite-and-python-types

    .. include:: db/src/python-sqlite/sp240.py
        :code: python
        :number-lines:
        :class: step

.. slido:: Cursor(II)
   :class: t3c

    .. include:: db/src/python-sqlite/sp250.py
        :code: python
        :number-lines:
        :class: step

    .. include:: db/src/python-sqlite/sp260.py
        :code: python
        :number-lines:
        :class: step

    .. code:: console
      :number-lines:

      python3 sp260.py 

      r1:  <class 'sqlite3.Cursor'>
      r2: <class 'sqlite3.Cursor'>
      r1:  <class 'tuple'>
      r2: <class 'tuple'>
      S
      ('P1', 'Nut', 'Red', 12, 'London')
      ('P2', 'Bolt', 'Green', 17, 'Paris')
      ('P3', 'Screw', 'Blue', 17, 'Oslo')
      ('P4', 'Screw', 'Red', 14, 'London')
      ('P5', 'Cam', 'Blue', 12, 'Paris')
      ('P6', 'Cog', 'Red', 19, 'London')
      P

    .. :

        :start-line: 3
        :end-line: 18

.. slido:: Traverse Fields
   :class: t2c

    .. include:: db/src/python-sqlite/sp280.py
        :code: python
        :number-lines:
        :class: step

    .. code:: console
      :number-lines:
      :class: step

      python3 sp280.py 

      S
      S1 ;  Smith ;  20 ;  London ;  
      S2 ;  Jones ;  10 ;  Paris ;  
      S3 ;  Blake ;  30 ;  Paris ;  
      S4 ;  Clark ;  20 ;  London ;  
      S5 ;  Adams ;  30 ;  Athens ;  
      S6 ;  Ali ;  40 ;  کاشان ;  
      P
      ('P1', 'Nut', 'Red', 12, 'London')
      ('P2', 'Bolt', 'Green', 17, 'Paris')
      ('P3', 'Screw', 'Blue', 17, 'Oslo')
      ('P4', 'Screw', 'Red', 14, 'London')
      ('P5', 'Cam', 'Blue', 12, 'Paris')
      ('P6', 'Cog', 'Red', 19, 'London')

.. slido:: Fetch
   :class: t2c

    .. include:: db/src/python-sqlite/sp290.py
        :code: python
        :number-lines:
        :class: step

    .. code:: console
      :number-lines:
      :class: step

      python3 sp280.py 

      S
      ('S1', 'Smith', 20, 'London')
      ('S2', 'Jones', 10, 'Paris')
      ('S3', 'Blake', 30, 'Paris')
      ('S4', 'Clark', 20, 'London')
      ('S5', 'Adams', 30, 'Athens')
      ('S6', 'Ali', 40, 'کاشان')
      P
      ('P1', 'Nut', 'Red', 12, 'London')
      ('P2', 'Bolt', 'Green', 17, 'Paris')
      ('P3', 'Screw', 'Blue', 17, 'Oslo')

.. slido:: Manipulate Tables(I)
   :class: t2c

    .. include:: db/src/python-sqlite/310.py
        :code: python
        :number-lines:
        :class: ltr

.. slido:: Manipulate Tables(II)
   :class: t2c

    .. include:: db/src/python-sqlite/320.py
        :code: python
        :number-lines:
        :class: ltr

.. slido:: Two Connection
   :class: t2c

    .. include:: db/src/python-sqlite/330.py
        :code: python
        :number-lines:
        :class: ltr

    .. :

        :start-line: 3
        :end-line: 18

.. slido:: DELETE
   :class: t2c

    .. include:: db/src/python-sqlite/340.py
        :code: python
        :number-lines:
        :class: ltr

.. slido:: A program(I)
   :class: t2c

    .. include:: db/src/python-sqlite/sp420_add.py
        :code: python
        :number-lines:
        :class: ltr
        :start-line: 1
        :end-line: 26

.. slido:: A program(II)
   :class: t2c

    .. include:: db/src/python-sqlite/sp420_add.py
        :code: python
        :number-lines: 26
        :class: ltr
        :start-line: 26
        :end-line: 60


    .. :

        :start-line: 
        :end-line: 18

.. slido:: PostgreSQL and Python

    .. include:: db/src/python-postgresql/110.py
        :code: python
        :number-lines:
        :class: ltr

.. slido::

    .. include:: db/src/python-postgresql/115.py
        :code: python
        :number-lines:
        :class: ltr

.. slido::

    .. include:: db/src/python-postgresql/118.py
        :code: python
        :number-lines:
        :class: ltr

.. slido::

    .. include:: db/src/python-postgresql/119.py
        :code: python
        :number-lines:
        :class: ltr

.. slido::

    .. include:: db/src/python-postgresql/120.py
        :code: python
        :number-lines:
        :class: ltr

.. slido::

    .. include:: db/src/python-postgresql/125.py
        :code: python
        :number-lines:
        :class: ltr

.. slido::

    .. include:: db/src/python-postgresql/130.py
        :code: python
        :number-lines:
        :class: ltr

.. slido::

    .. include:: db/src/python-postgresql/140.py
        :code: python
        :number-lines:
        :class: ltr

.. slido::

    .. include:: db/src/python-postgresql/150.py
        :code: python
        :number-lines:
        :class: ltr

.. slido::

    .. include:: db/src/python-postgresql/155.py
        :code: python
        :number-lines:
        :class: ltr

.. slido::

    .. include:: db/src/python-postgresql/157.py
        :code: python
        :number-lines:
        :class: ltr

.. slido::

    .. include:: db/src/python-postgresql/160.py
        :code: python
        :number-lines:
        :class: ltr

.. slido::

    .. include:: db/src/python-postgresql/170.py
        :code: python
        :number-lines:
        :class: ltr

.. slido::

    .. include:: db/src/python-postgresql/155.py
        :code: python
        :number-lines:
        :class: ltr

.. slido::

    .. include:: db/src/python-postgresql/180.py
        :code: python
        :number-lines:
        :class: ltr

.. slido::

    .. include:: db/src/python-postgresql/190.py
        :code: python
        :number-lines:
        :class: ltr

.. slido::

    .. include:: db/src/python-postgresql/200.py
        :code: python
        :number-lines:
        :class: ltr
