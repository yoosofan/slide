:data-transition-duration: 1000
:skip-help: true
:css: ./style.css
:substep: true
:slide-numbers: true
:data-width: 1024
:data-height: 768

.. role:: ltr
    :class: ltr

.. role:: rtl
    :class: rtl

.. |nbsp| unicode:: 0xA0
   :trim:

----

Database Course
==================
Ahmad Yoosofan

SQL 1

University of Kashan

https://yoosofan.github.io

https://yoosofan.github.io/slide/db/sql1/

----

:class: t2c

Database Schema of SP
=====================
.. code:: sql
    :number-lines:

    create table s (
        sn      char(10) primary key,
        sname   char(30),
        status  int  default(0),
        city    char(20)
    );

    create table p (
        pn     char(10) primary key,
        pname  char(30),
        color  char(20),
        weight NUMERIC(9, 2),
        city   char(20)
    );

    create table sp (
        sn    char(10) references s,
        pn    char(10) references p,
        qty   int default(0),
        primary key (sn, pn)
    );


.. yographviz::

   digraph S_P_SP { // Thanks to Gemini from Google
       // Layout direction: Left to Right
       rankdir=LR;

       // Global node and edge settings
       node [shape=none, fontname="Helvetica", fontsize=12];
       edge [fontname="Helvetica", fontsize=10, color="#555555"];

       // Table: Suppliers (s)
       s [label=<
           <table border="0" cellborder="1" cellspacing="0" cellpadding="5">
               <tr><td bgcolor="#e0f7fa" colspan="2"><b>s (Suppliers)</b></td></tr>
               <tr><td port="sn" bgcolor="#ffffff"><b>sn (PK)</b></td><td bgcolor="#ffffff">char(10)</td></tr>
               <tr><td port="sname" bgcolor="#ffffff">sname</td><td bgcolor="#ffffff">char(30)</td></tr>
               <tr><td port="status" bgcolor="#ffffff">status</td><td bgcolor="#ffffff">int</td></tr>
               <tr><td port="city" bgcolor="#ffffff">city</td><td bgcolor="#ffffff">char(20)</td></tr>
           </table>
       >];

       // Table: Shipments (sp)
       // Placed in the middle visually
       sp [label=<
           <table border="0" cellborder="1" cellspacing="0" cellpadding="5">
               <tr><td bgcolor="#fff9c4" colspan="2"><b>sp (Shipments)</b></td></tr>
               <tr><td port="sn" bgcolor="#ffffff"><b>sn (PK, FK)</b></td><td bgcolor="#ffffff">char(10)</td></tr>
               <tr><td port="pn" bgcolor="#ffffff"><b>pn (PK, FK)</b></td><td bgcolor="#ffffff">char(10)</td></tr>
               <tr><td port="qty" bgcolor="#ffffff">qty</td><td bgcolor="#ffffff">int</td></tr>
           </table>
       >];

       // Table: Parts (p)
       p [label=<
           <table border="0" cellborder="1" cellspacing="0" cellpadding="5">
               <tr><td bgcolor="#e8f5e9" colspan="2"><b>p (Parts)</b></td></tr>
               <tr><td port="pn" bgcolor="#ffffff"><b>pn (PK)</b></td><td bgcolor="#ffffff">char(10)</td></tr>
               <tr><td port="pname" bgcolor="#ffffff">pname</td><td bgcolor="#ffffff">char(30)</td></tr>
               <tr><td port="color" bgcolor="#ffffff">color</td><td bgcolor="#ffffff">char(20)</td></tr>
               <tr><td port="weight" bgcolor="#ffffff">weight</td><td bgcolor="#ffffff">numeric(9, 2)</td></tr>
               <tr><td port="city" bgcolor="#ffffff">city</td><td bgcolor="#ffffff">char(20)</td></tr>
           </table>
       >];

       // Foreign Key Relationships
       // The syntax node:port -> node:port connects the specific table rows

       sp:sn -> s:sn [label=" references", arrowtail=none, arrowhead=normal];
       sp:pn -> p:pn [label=" references", arrowtail=none, arrowhead=normal];
   }

----

:class: t2c

DSL(Data Sub Language)
======================
.. code:: sql
    :number-lines:

    insert into s(sn, sname,  status, city)
    values('s1', 'Smith', 20, 'London')
    ;

    insert into p(pn, pname, color, weight, city)
    values('p1','Nut'  ,'Red'  ,12.0,'London')
    ;

    insert into p(pn, pname, color, weight, city)
    values
      ('p2', 'Bolt' , 'Green', 17.0, 'Paris' ),
      ('p5', 'Cam'  , 'Blue' , 12.0, 'Paris' ),
      ('p6', 'Cog'  , 'Red'  , 19.0, 'London')
    ;

.. container::

    .. class:: substep

        .. code:: sql

            delete sp;

        .. code:: sql

            drop table sp;

        * DDL: Data Definition Language
        * DML: Data Manipluation Language
        * DCL: Data Control Language

        #. DDL: create, drop
        #. DML: insert, delete

.. code:: sql
    :number-lines:

    insert into s(sn, sname,  "status", city)
    values('s4', 'Clark', 20, 'London')
    ;
    insert into s(sname, status, city, sn)
    values('Adams', 30, 'Athens', 's5')
    ;
    insert into s
    values('s6', 'Ali', 40, 'کاشان')
    ;

----

:class: t2c

DBMS(Database Management System)
================================
.. container:: substep

    .. class:: substep

    * An application
    * RDBMS (Relational Datababase Management System)
    * SQL (Structured Query Language)
    * DB2, Oracle, PostgreSQL, MySQL, SqlServer, MariaDB
    * SQLite (Lack of DCL commands, each db on a file)

.. container:: substep

    *SQLite*

    .. class:: substep

    #. `SQLite <https://www.sqlite.org/download.html>`_
    #. `SQLite browser <https://sqlitebrowser.org/>`_
    #. `SQLite studio <https://sqlitestudio.pl/>`_
    #. `SQLite-web <https://github.com/coleifer/sqlite-web>`_
    #. `Database Viewer <https://github.com/Dyaland/DatabaseViewer>`_

.. container:: substep

    *Online*

    .. class:: substep

    #. `sql.js <https://sql.js.org/examples/GUI/>`_
    #. `sqlite online <https://sqliteonline.com/>`_
    #. `sqlite-browser <https://extendsclass.com/sqlite-browser.html#>`_
    #. `sqlite-viewer <https://inloop.github.io/sqlite-viewer/>`_
    #. `sqlfiddle <https://sqlfiddle.com/sqlite/online-compiler>`_

.. :

    #. https://sqlzoo.net/
    #. `tutorial <https://www.sqlitetutorial.net/>`_

----

:class: t2c

.. class:: rtl-h1

  نام قطعه‌ها را بیابید.

.. container::

  .. code:: sql

    select pname
    from p
    ;

  .. code:: sql

    p{pname};

..  csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder

  pname
  Nut
  Bolt
  Screw
  Screw
  Cam
  Cog
  Nut
  Bolt

----

:class: n2c

.. container::

    .. code:: sql
        :number-lines:

        select sname, status
        from s
        ;

    .. code:: sql
        :number-lines:

        s{sname, status};

        -- Relational Algebra


.. raw:: html

    <pre>
        ╭───────┬────────╮
        │ sname │ status │
        ╞═══════╪════════╡
        │ Smith │     20 │
        │ Jones │     10 │
        │ Blake │     30 │
        │ Clark │     20 │
        │ Adams │     30 │
        │ Ali   │     40 │
        ╰───────┴────────╯
    </pre>

.. code:: sql
    :number-lines:
    :class: substep

    select *
    from s;
    ;

.. container:: substep

    .. raw:: html

        <pre>
            ╭────┬───────┬────────┬────────╮
            │ sn │ sname │ status │  city  │
            ╞════╪═══════╪════════╪════════╡
            │ s1 │ Smith │     20 │ London │
            │ s2 │ Jones │     10 │ Paris  │
            │ s3 │ Blake │     30 │ Paris  │
            │ s4 │ Clark │     20 │ London │
            │ s5 │ Adams │     30 │ Athens │
            │ s6 │ Ali   │     40 │ کاشان  │
            ╰────┴───────┴────────┴────────╯
        </pre>


----

:class: t2c

as (rename)
==============
.. code:: sql
    :number-lines:

    select sname, status + 4
    from s;
    ;

.. raw:: html

    <pre>
        ╭───────┬────────────╮
        │ sname │ status + 4 │
        ╞═══════╪════════════╡
        │ Smith │         24 │
        │ Jones │         14 │
        │ Blake │         34 │
        │ Clark │         24 │
        │ Adams │         34 │
        │ Ali   │         44 │
        ╰───────┴────────────╯
    </pre>

.. code:: sql
    :number-lines:

    select sname, status + 4 as st4
    from s;
    ;

.. raw:: html

    <pre>
        ╭───────┬─────╮
        │ sname │ st4 │
        ╞═══════╪═════╡
        │ Smith │  24 │
        │ Jones │  14 │
        │ Blake │  34 │
        │ Clark │  24 │
        │ Adams │  34 │
        │ Ali   │  44 │
        ╰───────┴─────╯
    </pre>

----

:class: t2c

.. class:: rtl-h1

  نام قطعه‌ها و وزن آنها را بیابید.

.. container:: substep

  .. code:: sql

    select pname, weight
    from p
    ;

  .. code:: sql

    p{pname, weight} ;

..  csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder substep

  pname, weight
  Nut,  12
  Bolt, 17
  Screw,  17
  Screw,  14
  Cam,  12
  Cog,  19
  Nut,
  Bolt,

.. :

  Nut,  **NULL**
  Bolt, **NULL**

----

:class: t2c

NULL
=====
.. container::

    .. code:: sql
        :number-lines:

        insert into p(pn, pname, color, city)
        values('p7', 'Nut', 'Red', 'London')
        ;

    .. code:: sql
        :number-lines:
        :class: substep

        insert into p(pn, pname, color, weight, city)
        values('p8', 'Bolt', 'Green', null, 'Paris')
        ;


.. code:: sql
    :class: substep
    :number-lines:

    create table s (
     sn      char(10) primary key,
     sname   char(30) not null,
     status  int  default 0,
     city    char(20)
    );

.. class:: substep

    #. null
    #. not 'null'
    #. not 0
    #. not '0'
    #. not ''

.. class:: substep

    #. Do not know the value
    #. Not applicable
        * Address: city, street, alley, number

.. :

    https://www.ibm.com/support/knowledgecenter/en/SSEPEK_11.0.0/intro/src/tpc/db2z_joindatafromtables.html
    https://www.ibm.com/support/knowledgecenter/SSEPEK_11.0.0/intro/src/art/bkntjoin.gif

    برای حالتی که فیلدی در جدول مقدارهای null نیز داشته باشد و نتیجه‌های unknown بدهد در این صورت باید منطق سه گزاره‌ای را به کار ببریم تا نتیجهٔ نهایی را متوجه بشویم.

    نام قطعاتی را به دست آورید که نام شهر آنها کاشان باشد یا وزن آنها بیشتر از ۲۰ باشد.

    select pname
    from p
    where city='kashan' or wight>20;

    اگر دستور زیر را بنویسیم می‌تواند پاسخ دیگری را بدهد.

    select pname
    from p
    where (city in not null and city='kashan') or weight>20;

----

:class: t2c

.. class:: rtl-h1

نام قطعه‌ها و وزن آن‌ها را به گرم بیابید.

.. container:: substep

    .. code:: sql
        :number-lines:

        select pname, weight * 1000 as gweight
        from p
        ;

    NULL * 1000 → NULL

..  csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder substep

  pname, gweight
  Nut,  12000
  Bolt, 17000
  Screw,  17000
  Screw,  14000
  Cam,  12000
  Cog,  19000
  Nut,
  Bolt,

----

:class: t2c

Where
=====

.. container::

  .. code:: sql
    :number-lines:

    --   نام عرضه‌کنندگان شهر کاشان را بیابید.

    select sname
    from s
    where city = 'کاشان'
    ;

  .. code:: sql
    :class: substep

    -- (s where city = 'کاشان') {pname}

  .. code:: sql
    :class: substep

    select sname
    from s
    where city = 'Paris'
    ;

.. container:: substep

    ..  csv-table::
        :header-rows: 1
        :class: smallerelementwithfullborder

        sname
        Jones
        Blake

    * Arithmetic Operators
        * **`+ - * / %`**
    * Comparison Operators
        * **`= < > >= <= <>`**


----

:class: t2c

.. class:: rtl-h1

  شمارهٔ قطعه‌های عرضه شده را بیابید.

.. code:: sql
  :class: substep

  select pn
  from sp
  ;

..  csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder substep

  pn
  p1
  p2
  p3
  p4
  p5
  p6
  p1
  p2
  p2
  p2
  p4
  p5
  p2

----

:class: t2c

.. class:: rtl-h1

  نام قطعه‌های عرضه شده را بیابید.

.. container::

  .. code:: sql
    :class: substep

    select pname
    from p, sp
    where p.pn = sp.pn
    ;

  .. code:: sql
    :class: substep

    (
      (
         (
           p rename pn as ppn
         )
         times sp
      ) where ppn = pn
    ) {pname}

..  csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder substep

  pname
  Nut
  Bolt
  Screw
  Screw
  Cam
  Cog
  Nut
  Bolt
  Bolt
  Bolt
  Screw
  Cam
  Bolt

----

:class: t2c

join
=====
.. class:: rtl-h1

  نام قطعه‌های عرضه شده را بیابید.

.. code:: sql

  select pname
  from p natural join sp
  ;

.. code:: sql
  :class: substep

  (p join sp) {pname}

.. code:: sql
  :class: substep

  select pname
  from p join sp using(pn)
  ;

.. code:: sql
  :class: substep

  select pname
  from p join sp on p.pn=sp.pn
  ;

----

:class: t2c

.. class:: rtl-h1

  نام قطعه‌هایی را بیابید که در شهر آن قطعه‌ها عرضه کننده‌ای وجود داشته باشد

.. container:: substep

  .. code:: sql

    select pname
    from p join s using(city)
    ;

  .. code:: sql
    :class: substep

    select pname
    from p natural join s
    ;

  .. code:: sql
    :class: substep

    select distinct pname
    from p natural join s
    ;


.. raw:: html

    <pre>

        ╭───────╮
        │ pname │
        ╞═══════╡
        │ Nut   │
        │ Nut   │
        │ Bolt  │
        │ Bolt  │
        │ Screw │
        │ Screw │
        │ Cam   │
        │ Cam   │
        │ Cog   │
        │ Cog   │
        │ Nut   │
        │ Nut   │
        │ Bolt  │
        │ Bolt  │
        ╰───────╯
    </pre>

.. container:: substep

    .. raw:: html

        <pre>
            ╭───────╮
            │ pname │
            ╞═══════╡
            │ Nut   │
            │ Bolt  │
            │ Screw │
            │ Cam   │
            │ Cog   │
            ╰───────╯
        </pre>

..  csv-table:
  :header-rows: 1
  :class: smallerelementwithfullborder substep

  pname
  Nut
  Nut
  Bolt
  Bolt
  Screw
  Screw
  Cam
  Cam
  Cog
  Cog
  Nut
  Nut
  Bolt
  Bolt

    ----

    :class: t2c

    .. class:: rtl-h1

      اطلاعات عرضه‌کنندگان و قطعه‌هایی را که عرضه کرده‌اند، بیابید.

    .. code:: sql
      :class: substep

      select *
      from (p join sp using(pn))
        join s using(sn)
      ;

    ..  csv-table::
      :header-rows: 1
      :class: smallerelementwithfullborder substep

      pn, pname,  color,  weight, city, sn, qty,  sname,  status, city
      p1, Nut,  Red,  12, London, s1, 300,  Smith,  20, London
      p2, Bolt, Green,  17, Paris,  s1, 200,  Smith,  20, London
      p3, Screw,  Blue, 17, Oslo, s1, 400,  Smith,  20, London
      p4, Screw,  Red,  14, London, s1, 200,  Smith,  20, London
      p5, Cam,  Blue, 12, Paris,  s1, 100,  Smith,  20, London
      p6, Cog,  Red,  19, London, s1, 100,  Smith,  20, London
      p1, Nut,  Red,  12, London, s2, 300,  Jones,  10, Paris
      p2, Bolt, Green,  17, Paris,  s2, 400,  Jones,  10, Paris
      p2, Bolt, Green,  17, Paris,  s3, 200,  Blake,  30, Paris
      p2, Bolt, Green,  17, Paris,  s4, 200, Clark, 20, London
      p4, Screw,  Red,  14, London, s4, 300,  Clark,  20, London
      p5, Cam,  Blue, 12, Paris,  s4, 400,  Clark,  20, London
      p2, Bolt, Green,  17, Paris,  s6, 350,  Ali,  40, کاشان

----

:class: t2c

.. class:: rtl-h1

  نام قطعاتی را بیابید که عرضه‌کننده‌ای از شهر کاشان آنها را عرضه کرده باشد.

.. container::

  .. code:: sql
    :class: substep

    select pname
    from (p natural join sp)
      join s on s.sn=sp.sn
    where s.city = 'کاشان'
    ;


  .. code:: sql
    :class: substep

    select pname
    from (p natural join sp)
      join s using(sn)
    where s.city = 'کاشان'
    ;

..  csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder substep

  pname
  Bolt

.. :

    ----

    :class: t2c

    .. class:: rtl-h1

      نام قطعاتی را بیابید که وزن آنها بیشتر از ۲۰ است

    .. code:: sql
      :class: substep

      select pname
      from p
      where weight > 20
      ;

    ..  csv-table::
      :header-rows: 1
      :class: smallerelementwithfullborder substep

      pname
      ""

----

:class: t2c

SQLite (I)
==========
.. class:: substep

#. sqlite3
#. sqlite3 sp.sqlite
#. .exit or .quit
#. .help
#. .read sp.sql
#. .output sp2.sql
#. .dump
#. .output

.. class:: substep

#. .open sp.sqlite
#. .databases
#. .backup  FILE
#. .restore FILE
#. .system CMD
#. .system clear
#. .tables
#. .schema s

.. :

    .mode box
    .mode csv
    .mode column
    .mode markdown

    .. csv-table::
        :header-rows: 1
        :class: smallerelementwithfullborder substep

        Command,Description
        sqlite3,Open SQLite3 in interactive mode
        sqlite3 database.db,Open (or create) a database file
        .exit or .quit,Exit SQLite3
        .help,List all available SQLite3 dot commands
        .read file.sql, read and execute file.sql
        .dump ?TABLE?,Export database (or table) as SQL script

    .. csv-table::
        :header-rows: 1
        :class: smallerelementwithfullborder substep

        Command,Description
        .open database.db,Open (or create) a database file
        .databases,List attached databases
        .backup ?DB? FILE,Backup database to a file
        .restore ?DB? FILE,Restore database from a file
        .system CMD, run CMD command from operating system

    https://database.guide/an-overview-of-dot-commands-in-sqlite/
    https://stephentech.bearblog.dev/sqlite3-commands-cheat-sheet/
    https://www.sqlitetutorial.net

----

:class: t2c

Use Another name for a Table in Query
=========================================
.. container::

  .. code:: sql

    create table t (
      a int primary key,
      name char(20)
    );

    insert into t values (1, 'a'),(2, 'b');

  .. code:: sql

    select *
    from t, t as M;

..  csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder substep

  a,  name, a,  name
  1,  a,  1,  a
  1,  a,  2,  b
  2,  b,  1,  a
  2,  b,  2,  b

.. code:: sql
  :class: substep

  select t.name
  from t, t as M
  where t.a < M.a;

..  csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder substep

  name
  a

.. code:: sql
  :class: substep

  select *
  from t join t as M
    on t.a < M.a;

..  csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder substep

  a,  name, a,  name
  1,  a,  2,  b

----

:class: t2c

.. class:: rtl-h1

نام قطعاتی را بیابید که وزن آنها دست کم از وزن یک قطعهٔ دیگر بیشتر باشد نام تکراری در پاسخ نیاید.

.. class:: substep rtl-h2

    نام همهٔ قطعات را بیابید به جز قطعه‌ یا قطعه‌هایی که کمترین وزن را دارند


.. code:: sql
    :class: substep
    :number-lines:

    select T.pname
    from p as T
    ;

.. container::

    .. code:: sql
        :class: substep
        :number-lines:

        select T.pname
        from p as T, p
        where p.weight < T.weight
        ;

    .. code:: sql
        :class: substep
        :number-lines:

        select distinct T.pname
        from p as T, p
        where p.weight < T.weight
        ;

    .. code:: sql
        :class: substep
        :number-lines:

        select distinct T.pname
        from p as T join p on
          p.weight < T.weight
        ;

.. raw:: html

    <pre>
    ╭───────╮
    │ pname │
    ╞═══════╡
    │ Bolt  │
    │ Screw │
    │ Cog   │
    ╰───────╯
    </pre>

..  csv-table:
  :header-rows: 1
  :class: smallerelementwithfullborder substep

  pname
  Bolt
  Bolt
  Bolt
  Screw
  Screw
  Screw
  Screw
  Screw
  Cog
  Cog
  Cog
  Cog
  Cog

----

:class: t2c

.. class:: rtl-h1

نام قطعه‌های عرضه شده را همراه با نام عرضه‌کنندگان‌شان بیابید زوج نام تکراری در پاسخ نیاید.

.. container::

  .. code:: sql
    :class: substep

    select pname, sname
    from s, sp, p
    where s.sn = sp.sn and
      p.pn = sp.pn
    ;

  .. code:: sql
    :class: substep

    select distinct pname, sname
    from s natural join sp
      join p using(pn)
    ;

.. raw:: html

    <pre>
        ╭───────┬───────╮
        │ pname │ sname │
        ╞═══════╪═══════╡
        │ Nut   │ Smith │
        │ Bolt  │ Smith │
        │ Screw │ Smith │
        │ Cam   │ Smith │
        │ Cog   │ Smith │
        │ Nut   │ Jones │
        │ Bolt  │ Jones │
        │ Bolt  │ Blake │
        │ Bolt  │ Clark │
        │ Screw │ Clark │
        │ Cam   │ Clark │
        │ Bolt  │ Ali   │
        ╰───────┴───────╯
    </pre>

..  csv-table:
  :header-rows: 1
  :class: smallerelementwithfullborder substep

  pname,  sname
  Nut,  Smith
  Bolt, Smith
  Screw,  Smith
  Screw,  Smith
  Cam,  Smith
  Cog,  Smith
  Nut,  Jones
  Bolt, Jones
  Bolt, Blake
  Bolt, Clark
  Screw,  Clark
  Cam,  Clark
  Bolt, Ali

----

:class: t2c

.. class:: rtl-h1

  نام قطعاتی را بیابید که وزن‌شان دست کم از وزن یک قطعهٔ با رنگ قرمز کمتر باشد

.. container::

  .. code:: sql
    :class: substep

    select distinct T.pname
    from p as T, p
    where p.weight > T.weight
      and p.color='Red'
    ;

  .. code:: sql
    :class: substep

    select distinct T.pname
    from p as T join p on
      p.weight > T.weight
    where p.color='Red'
    ;

..  csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder substep

  pname
  Nut
  Bolt
  Screw
  Cam

.. code:: sql
  :class: substep

  select distinct p.pname
  from p as p1 join p on
    p1.weight > p.weight and
    p1.color = 'Red'
  ;

.. :

    ..  csv-table::
      :header-rows: 1
      :class: smallerelementwithfullborder substep

      pname
      Cog
      Screw


----

:class: t2c

LIKE
====
.. class:: rtl-h2

نام شهرهای قطعاتی را بیابید که با P آغاز شده باشد

.. code:: sql
  :class: substep

  select city
  from p
  where city like 'P%'
  ;

.. class:: rtl-h2 substep

نام قطعاتی را بیابید که کاراکتر دوم نام‌شان o باشد.

.. code:: sql
  :class: substep

  select pname
  from p
  where city like '_o%'
  ;

.. class:: rtl-h2 substep

نام شهر قطعاتی را بیابید که درون نام شهر آنها رشتهٔ is وجود داشته باشد

.. code:: sql
  :class: substep

  select city
  from p
  where city like '%is%'
  ;

.. class:: rtl-h2 substep

  نام قطعات و شهرهای آنها را بیابید که شهر آنها دست کم سه‌حرفی باشند و با رشتهٔ `_bn` آغاز شود.

.. code:: sql
  :class: substep

  select pname, city
  from p
  where city like 'bn\_%'
  ;

----

:class: t2c

escape
========
.. code:: sql

  select pname
  from p
  where city like 'P\_%' escape '\'
  ;

.. code:: sql
  :class: substep

  select pname
  from p
  where city like 'P!_%' escape '!'
  ;


.. code:: sql
  :class: substep

  select pname
  from p
  where city like 'P#_%' escape '#'
  ;

.. code:: sql
    :class: substep

    select pname
    from p
    where city like "an\_%" escape "\"
    ; -- "

----

:class: t2c

ORDER BY
========
.. class:: rtl-h2

نام قطعاتی را بیابید که در شهر پاریس باشند و پاسخ بر پایهٔ نام قطعه از کوچک به بزرگ مرتب شده باشد.


.. code:: sql

  select pname
  from p
  where city='Paris'
  order by pname
  ;

.. class:: rtl-h2 substep

نام و وزن قطعاتی را بیابید که در شهر پاریس هستند و پاسخ بر پایهٔ وزن قطعه از کوچک به بزرگ مرتب شده باشد

.. code:: sql
  :class: substep

  select pname, weight
  from p
  where city='Paris'
  order by weight
  ;

.. code:: sql
  :class: substep

  select pname, weight
  from p
  where city='Paris'
  order by weight asc
  ;

.. container:: substep

    .. raw:: html

        <pre>
            ╭───────┬────────╮
            │ pname │ weight │
            ╞═══════╪════════╡
            │ Bolt  │ NULL   │
            │ Cam   │     12 │
            │ Bolt  │     17 │
            ╰───────┴────────╯
        </pre>

----

:class: t2c


.. class:: rtl-h1

  نام و وزن قطعاتی را بیابید که در شهر پاریس هستند و پاسخ بر پایهٔ وزن قطعه از بزرگ به کوچک مرتب شده باشد

.. code:: sql
  :class: substep

  select pname, weight
  from p
  where city='Paris'
  order by weight desc
  ;


..  csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder substep

    pname,  weight
    Bolt, 17
    Cam,  12
    Bolt,

.. code:: sql
  :class: substep

  select pname, weight
  from p
  where city='Paris' and weight is not null
  order by weight desc
  ;

..  csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder substep

    pname,  weight
    Bolt, 17
    Cam,  12

----

:class: t2c

BETWEEN
=======
.. container::

    .. class:: rtl-h2

      نام و وزن قطعاتی را بیابید که وزن‌شان بین ۱۲ و ۱۴ باشد

    .. csv-table::
      :header-rows: 1
      :class: smallerelementwithfullborder, substep

      pname, weight
      Nut,12
      Screw,14
      Cam,12

.. container::

    .. code:: sql
      :class: substep

      select pname, weight
      from p
      where weight >= 12 and weight <= 14
      ;

    .. code:: sql
      :class: substep

      select pname, weight
      from p
      where weight between 12 and 14;

.. container::

    .. class:: rtl-h2 substep

      نام و وزن قطعاتی را بیابید که وزن‌شان بین ۱۲ و ۱۴ نباشد

    .. csv-table::
      :header-rows: 1
      :class: smallerelementwithfullborder, substep

      pname, weight
      Bolt,17
      Screw,17
      Cog,19

.. container::

    .. code:: sql
      :class: substep

      select pname, weight
      from p
      where not (weight >= 12 and weight <= 14)
      ;

    .. code:: sql
      :class: substep

      select pname, weight
      from p
      where weight not between 12 and 14
      ;

.. code:: sql
  :class: substep

  select pname, weight
  from p
  where weight < 12 or weight > 14
  ;


----

:class: t2c

.. :


.. class:: rtl-h1

  نام قطعاتی را بیاید که عرضه کننده‌ای در شهر آن قطعه‌ها آنها را عرضه کرده باشد

Record Comparison
------------------
.. code:: sql
  :class: substep

  select pname
  from p, s, sp
  where p.city = s.city and
    p.pn = sp.pn and
    s.sn = sp.sn
  ;

.. code:: sql
  :class: substep

  select pname
  from p, s, sp
  where (p.city, p.pn) = (s.city, sp.pn)
    and s.sn = sp.sn
  ;

.. code:: sql
  :class: substep

  select pname
  from p join s on
    p.city = s.city
    join sp on
    (p.pn, s.sn) = (sp.pn, sp.sn)
  ;


.. code:: sql
  :class: substep

  select pname
  from p natural join sp natural join s
  ;

.. csv-table:
  :header-rows: 1
  :class: smallerelementwithfullborder, substep

    pname
    Nut
    Screw
    Cog
    Bolt
    Bolt
    Screw

----

:class: t2c

Union
========
.. class:: rtl-h2

نام قطعاتی از شهر پاریس را بیابید که وزن آن‌ها بیشتر از ۱۲ است.

.. code:: sql
    :class: substep

    select distinct pname
    from p
    where city = 'Paris' or
      weight > 12;

.. code:: sql
    :class: substep

      select pname
      from p
      where city='Paris'
    union
      select pname
      from p
      where weight>12;

.. csv-table::
    :header-rows: 1
    :class: smallerelementwithfullborder, substep

    pname
    Bolt
    Cam
    Cog
    Screw

.. container::

  .. code:: sql
    :class: substep

      select pname
      from p
      where city = 'kashan'
    union all
      select pname
      from p
      where weight>10
     ;

.. csv-table::
    :header-rows: 1
    :class: smallerelementwithfullborder, substep

    pname
    Nut
    Bolt
    Screw
    Screw
    Cam
    Cog

----

:class: t2c

Style of Writing
=============================
.. code:: sql
  :class: substep

    select pname
    from p
    where city='Paris'
  union
    select pname
    from p
    where weight>12
  ;

.. code:: sql
  :class: substep

  select pname
  from p
  where city='kashan'
  union
  select pname
  from p
  where weight>10
  ;

.. code:: sql
  :class: substep

  select pname
  from p
  where city='kashan'

  union

  select pname
  from p
  where weight>10
  ;

----

:class: t3c

Intersect
===============
.. code:: sql
    :class: substep

      select pname
      from p
      where city='Paris'
    intersect
      select pname
      from p
      where weight>10
    ;

.. code:: sql
    :class: substep

    select distinct pname
    from p
    where city='Paris' and
      weight>10
    ;

.. csv-table::
    :header-rows: 1
    :class: smallerelementwithfullborder, substep

    pname
    Bolt
    Cam

.. code:: sql
    :class: substep

      select pname
      from p
      where city = 'Paris'
    intersect all -- sqlite error
      select pname
      from p
      where weight > 10
    ;

.. code:: sql
    :class: substep

    select pname
    from p
    where city='Paris' and
      weight>10
    ;


.. csv-table::
    :header-rows: 1
    :class: smallerelementwithfullborder, substep

    pname
    Bolt
    Cam

----

:class: t3c

Except
==========
.. code:: sql
    :class: substep

      select pname
      from p
      where city = 'Paris'
    except
      select pname
      from p
      where weight > 14
    ;

.. code:: sql
    :class: substep

    select distinct pname
    from p
    where city='Paris' and
      weight<=14
    ;

.. csv-table::
    :header-rows: 1
    :class: smallerelementwithfullborder, substep

    pname
    Cam

.. code:: sql
    :class: substep

    select pname
      from p
      where city='Paris'
    except all -- sqlite error
      select pname
      from p
      where weight>10
    ;

.. code:: sql
    :class: substep

    select pname
    from p
    where city='Paris' and
      weight<=14
    ;

.. csv-table::
    :header-rows: 1
    :class: smallerelementwithfullborder, substep

    pname
    Cam

----

:class: t2c

.. class:: rtl-h1

  نام شهرهای قطعاتی را بیابید که در آنها عرضه‌کننده‌ای وجود ندارد

.. code:: sql
  :class: substep

  select city
  from p
  except
  select city
  from s
  ;

.. csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder, substep

  city
  Oslo

----

:class: t2c

.. class:: rtl-h1

  شمارهٔ قطعات و شمارهٔ عرضه‌کنندگانی را بیابید که قطعات یاد شده را آن عرضه کنندگان عرضه نکرده باشند

.. code:: sql
    :class: substep
    :number-lines:

    select pn, sn
    from p, s
    except
    select pn, sn
    from sp;

.. code:: sql
    :class: substep
    :number-lines:

    select distinct p.pn, s.sn
    from p, s, sp         -- incorrect
    where (s.sn, p.pn) <> (sp.sn, sp.pn)
    ; -- s1, p2

.. code:: sql
    :class: substep
    :number-lines:

    select * from (
        select pn, sn
        from p, s
      except
        select pn, sn
        from sp
    ) order by pn,sn;

.. code:: sql
    :class: substep
    :number-lines:

    select distinct p.pn, s.sn
    from p, s, sp -- incorrect
    where (s.sn, p.pn) <> (sp.sn, sp.pn)
    order by sp.pn,sp.sn
    ; -- s1, p2

.. code:: sql
    :class: substep
    :number-lines:

    select pn,sn
    from sp order by pn,sn
    ; -- s1, p2

.. :

    src/output.of.queries.comparison.txt

    .. code:: sql
        :class: substep

          select p.pn, s.sn -- sp
          from p, s, sp
          where (s.sn, p.pn) <> (sp.sn, sp.pn)
        except
          select pn, sn
          from (
            select pn, sn from p, s
            except
            select pn, sn from sp
          );

----

:class: t2c

.. class:: rtl-h1

  نام قطعات و نام عرضه‌کنندگانی را بیابید که قطعات یاد شده را آن عرضه کنندگان عرضه نکرده باشند

.. container::

  .. code:: sql
    :class: substep


    select pname, sname  -- نادرست
    from p, s
    except
    select pname, sname
    from p natural join sp
      natural join s;

  .. code:: sql
    :class: substep

    select pname, sname from p, s
    except
    select pname, sname
    from s natural join sp
      join p using(pn);

  .. code:: sql
    :class: substep

    select sname , pname
    from (
      select pn, sn from p, s
      except
      select pn, sn from sp
      ) join p using (pn)
      join s using (sn);

.. list-table::

  * - .. csv-table::
        :header-rows: 1
        :class: smallerelementwithfullborder

        pname,  sname
        Bolt, Adams
        Cam,  Adams
        Cam,  Ali
        Cam,  Blake
        Cam,  Jones
        Cog,  Adams
        Cog,  Ali
        Cog,  Blake

    - |nbsp| |nbsp| |nbsp|

    - .. csv-table::
        :header-rows: 1
        :class: smallerelementwithfullborder

        pname,  sname
        Cog,  Clark
        Cog,  Jones
        Nut,  Adams
        Nut,  Ali
        Nut,  Blake
        Nut,  Clark
        Screw,  Adams
        Screw,  Ali
        Screw,  Blake
        Screw,  Jones

----

:class: t2c

.. class:: rtl-h1

  زوج نام عرضه‌کنندگانی را بیابید که در یک شهر باشند و پاسخ تکراری نداشته باشید

.. code:: sql
  :class: substep

  -- (1) نادرست
  select s.sname, T.sname
  from s, s as T
  where s.city = T.city
  ;

.. code:: sql
  :class: substep

  -- (2) نادرست
  select s.sname, T.sname
  from s, s as T
  where s.city = T.city and
    s.sn != T.sn
  ;

.. code:: sql
  :class: substep

  -- (3)
  select s.sname, T.sname
  from s, s as T
  where s.city = T.city and
    s.sn < T.sn
  ;

.. code:: sql
  :class: substep

  -- (4)
  select s.sname, T.sname
  from s as T join s using(city)
  where s.sn < T.sn
  ;

.. code:: sql
  :class: substep

  -- (5)
  select s.sname, T.sname
  from s as T join s on
    T.city = s.city and
    s.sn < T.sn
  ;

.. csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder

  sname,  sname
  Smith,  Clark
  Jones,  Blake

----

:class: t2c

LIMIT
=========
.. code:: sql

  select distinct city
  from p
  order by weight, city
  ;

..  csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder

  city
  London
  Oslo
  Paris

.. code:: sql

  select distinct city
  from p
  order by weight, city
  limit 2
  ;

..  csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder

  city
  London
  Oslo

----

:class: t2c

Scalar value(I)
======================
.. class:: rtl-h2

شماره و وزن قطعاتی را بیابید که کمترین وزن را داشته باشند.

.

.. code:: sql
  :number-lines:
  :class: substep

  select pn, weight  -- incorrect
  from p
  order by weight asc
  limit 1
  ;

.. csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder substep

  pn, weight
  P7, NULL

.. code:: sql
  :number-lines:
  :class: substep

  select pn, weight
  from p
  where weight is not null
  order by weight asc
  limit 1
  ;

.. csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder substep

  pn, weight
  p1, 12

.. code:: sql
  :number-lines:
  :class: substep

  select weight
  from p
  where weight is not null
  order by weight asc
  limit 1
  ;

.. csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder substep

  weight
  12

----

:class: t2c

.. class:: rtl-h1

شماره و وزن قطعاتی را بیابید که کمترین وزن را داشته باشند.

.. code:: sql
  :class: substep

  select pn, weight
  from p   -- incorrect
  where weight = (
      select weight
      from p
      order by weight asc
      limit 1
  );

.. code:: sql
  :class: substep

  select pn, weight
  from p
  where weight = (
      select weight
      from p
      where weight is not null
      order by weight asc
      limit 1
  );

.. code:: sql
  :class: substep
  :number-lines:

  select pn, 1 as qt
  from p
  where city = 'Paris'
  ;

.. container:: substep

    .. raw:: html

        <pre>
            ╭────┬────╮
            │ pn │ qt │
            ╞════╪════╡
            │ p2 │  1 │
            │ p5 │  1 │
            │ p8 │  1 │
            ╰────┴────╯
        </pre>

.. code:: sql
  :class: substep
  :number-lines:

  select pn,  (
      select weight
      from p
      where weight is not null
      order by weight asc
      limit 1
    ) as qt
  from p
  where city = 'Paris' ;

.. container:: substep

    .. raw:: html

        <pre>
            ╭────┬────╮
            │ pn │ qt │
            ╞════╪════╡
            │ p2 │ 12 │
            │ p5 │ 12 │
            │ p8 │ 12 │
            ╰────┴────╯
        </pre>

----

:class: t2c

Update(I)
===========
.. code:: sql

    update p
    set weight = weight + 15
    where city = 'Oslo'
    ;

.. code:: sql
    :class: substep

    update s
    set status = status * 2,
        city = 'kashan'
    where city = 'London'
    ;

.. code:: sql
    :class: substep

    update employees
    set email = LOWER(
        firstname || "." ||
        lastname || "@chinookcorp.com"
    );

.. code:: sql
    :class: substep

    update P
    set weight = null
    where pn='p6'
    ;

----

:class: t2c

Update(II)
===========
.. code:: sql

  update s
  set
    status = case
      when city = 'london' then status * 2
      else status
    end;

.. code:: sql
  :class: substep

  update s
  set
    status = case
    when city = 'London' then status * 2
    when city = 'Paris'  then status * 3
    else status
  end;

.. code:: sql
  :class: substep

  update s
  set
    status = case
      when city = 'London' then status / 4
      when city = 'Paris'  then status / 3
      else status
    end;

.. code:: sql
    :class: substep

    update s
    set city = 'kashan',
        status = case
          when status > 20 then 53
          else status
        end
    where sname = 'Smith'
    returning sn, sname;

.. :

    update s
    set city = 'kashan',
        status = case
          when status > 20 then 53
          else status
        end
    where sname = 'Smith'
    returning *;


    Technically, WHERE is optional. Practically, leaving it off is how junior engineers ruin their afternoon:

    https://stackoverflow.com/a/17081004/886607
    https://coddy.tech/docs/sqlite/update

----

:class: t2c

Update or Replace
=================
.. code:: sql
    :number-lines:

    CREATE TABLE users (
        id INTEGER PRIMARY KEY,
        email CHAR(20) UNIQUE,
        name CHAR(15)
    );

.. code:: sql
    :number-lines:
    :class: substep

    INSERT INTO users VALUES
        (1, 'ada@x.com', 'Ada'),
        (2, 'boris@x.com', 'Boris');

.. code:: sql
    :number-lines:
    :class: substep

    -- This would fail with a UNIQUE
    -- constraint violation:

    UPDATE users SET email = 'boris@x.com'
    WHERE id = 1;

.. code:: sql
    :number-lines:
    :class: substep

    -- OR REPLACE deletes the conflicting row,
    -- then performs the update.
    UPDATE OR REPLACE users
    SET email = 'boris@x.com'
    WHERE id = 1;

.. code:: sql
    :number-lines:
    :class: substep

    SELECT * FROM users;-

.. container:: substep

    .. raw:: html

        <pre>
            ╭────┬─────────────┬──────╮
            │ id │    email    │ name │
            ╞════╪═════════════╪══════╡
            │  1 │ boris@x.com │ ada  │
            ╰────┴─────────────┴──────╯
        </pre>

.. :

    https://coddy.tech/docs/sqlite/update

----

:class: t2c

Data Types
==========
.. class:: substep

* **Numeric**
    * TINYINT          , 1 byte
    * SMALLINT         , 2 bytes
    * INT              , 4 bytes
    * BIGINT           , 8 bytes
    * MONEY            , 8 bytes
    * FLOAT            , 1.79E+308
    * REAL             , 3.40E+38
    * DECIMAL(size, d) , 10^38
    * NUMERIC(size, d) , 10^38
    * DOUBLE(size, d)  ,  1.79E+308
* **Character and String**
    * CHAR     (n)
    * VARCHAR  (n)
    * TEXT
    * NCHAR    (n)
    * NVARCHAR (n)
    * NTEXT

.. class:: substep

* **Date and Time**
    * DATE     , YYYY-MM-DD
    * TIME     , HH:MI:SS
    * DATETIME , YYYY-MM-DD HH:MI:SS
    * TIMESTAMP, 1970-01-01 00:00:00
    * INTERVAL
* **Binary**
    * BINARY (n)
    * VARBINARY (n)
    * BLOB
* **Miscellaneous**
    * CLOB
    * BLOB
    * XML
    * CURSOR
    * TABLE
    * JSON (PostgreSQL jsonb)
    * BOOLEAN
    * ARRAY (PostgreSQL)

.. :

    https://www.digitalocean.com/community/tutorials/sql-data-types#choosing-the-right-sql-data-type

    * Storage Efficiency: Why use a BIGINT, which consumes 8 bytes of storage, for a column that will only ever hold numbers from 1 to 10? Choosing the smallest data type that safely accommodates your data range saves significant disk space, especially in large tables. This directly relates to the SQL data type size.
    * Performance: Smaller data types mean the database can read more data from memory or disk in a single operation, leading to faster queries. Correctly configured numeric types are also processed much faster than numbers stored as strings.
    * Data Integrity: Data types enforce rules on your data. A DATE column will reject a nonsensical value like 'Hello, World!', preventing corrupt data from entering your database. This is your first line of defense against application-level bugs. For more on data integrity, see how to use primary keys in SQL.

----

:class: t2c

SQLite Types
============
.. class:: substep

* Datatypes
    * NULL   :
    * INTEGER:  0 - 8 bytes
    * REAL   : 8-byte IEEE
    * TEXT   : UTF-8 or UTF-16
    * BLOB   :
* Boolean
    * 0 false
    * 1 true
* Date and Time
    * TEXT, YYYY-MM-DD HH:MM:SS.SSS
    * REAL, day numbers
    * INTEGER, timestamp
* Any
* Affinity
    #. INT → INTEGER
    #. CHAR, CLOB, TEXT → TEXT
    #. BLOB → BLOB
    #. REAL, FLOAT, DOUBLE → REAL
    #. Otherwise, NUMERIC.

.. container:: substep

    .. raw:: html

        <table border="1" cellpadding="5">
        <tbody><tr><th>Example Typenames From The<br>CREATE TABLE Statement<br>
                or CAST Expression
            </th><th>Resulting Affinity
            </th><th>Rule Used To Determine Affinity

        </th></tr><tr><td align="center" valign="top">
          INT,
          INTEGER,
          TINYINT,
          SMALLINT,
          MEDIUMINT,
          BIGINT<br>
          UNSIGNED BIG INT,
          INT2,
          INT8
        </td><td align="center">INTEGER
        </td><td align="center">1

        </td></tr><tr><td align="center" valign="top">
          CHARACTER(20),
          VARCHAR(255)<br>
          VARYING CHARACTER(255)<br>
          NCHAR(55),
          NATIVE CHARACTER(70)<br>
          NVARCHAR(100),
          TEXT,
          CLOB
        </td><td align="center">TEXT
        </td><td align="center">2

        </td></tr><tr><td align="center" valign="top">
          BLOB<br>
          <i>no datatype specified</i>
        </td><td align="center">BLOB
        </td><td align="center">3

        </td></tr><tr><td align="center" valign="top">
          REAL,
          DOUBLE<br>
          DOUBLE PRECISION,
          FLOAT
        </td><td align="center">REAL
        </td><td align="center">4

        </td></tr><tr><td align="center" valign="top">
        NUMERIC,
        DECIMAL(10,5),
        BOOLEAN<br>
        DATE,
        DATETIME
        </td><td align="center">NUMERIC
        </td><td align="center">5
        </td></tr></tbody></table>
.. :

    https://sqlite.org/datatype3.html

----

:class: t2c

Some Functions
==============
* math
    * acos(X)
    * acosh(X)
    * asin(X)
    * atanh(X)
    * ceil(X)ceiling(X)
    * cos(X)
    * exp(X)
    * floor(X)
    * ln(X)
    * log(X) log10(X)
    * log(B,X)
    * log2(X)
    * mod(X,Y)
    * pi()
    * pow(X,Y) power(X,Y)
    * sin(X)
    * sqrt(X)
    * tan(X)
    * trunc(X)

----

:class: t2c

Date and Time I
===============
* DATE(): YYYY-MM-DD
* TIME(): HH:MM:SS
* DATETIME(): YYYY-MM-DD HH:MM:SS
* JULIANDAY(): floating-point
* UNIXEPOCH(): seconds 1970-01-01
* STRFTIME():

.. code:: sql
    :number-lines:

    CREATE TABLE events (
        id INTEGER PRIMARY KEY,
        event_name TEXT NOT NULL,
        event_date TEXT NOT NULL
    );

    INSERT INTO events VALUES
      (1, 'Meeting', '2024-06-01 14:00:00'),
      (2, 'Conference', '2024-06-15 09:30:00');

.. code:: sql
    :number-lines:
    :class: substep

    CREATE TABLE events (
        id INTEGER PRIMARY KEY,
        event_name TEXT NOT NULL,
        event_timestamp INTEGER NOT NULL
    );

    INSERT INTO events VALUES
      (1, 'Meeting',
        strftime('%s', '2024-06-01 14:00:00')),
      (2, 'Conference',
        strftime('%s', '2024-06-15 09:30:00'));

.. code:: sql
    :number-lines:
    :class: substep

    SELECT event_name,
    datetime(event_timestamp,
      'unixepoch') AS event_date
    FROM events;

----

Date and Time II
================
.. code:: sql
    :number-lines:
    :class: substep

    SELECT date('2024-06-01', '+1 day') AS next_day,
           date('2024-06-01', '+1 month') AS next_month,
           date('2024-06-01', '-1 month') AS last_month;

.. code:: sql
    :number-lines:
    :class: substep

    SELECT (julianday('2024-06-15') - julianday('2024-06-01')) AS days_difference;

.. code:: sql
    :number-lines:
    :class: substep

    SELECT * FROM events
    WHERE event_date >= '2024-06-01' AND event_date < '2024-07-01';

.. code:: sql
    :number-lines:
    :class: substep

    SELECT datetime(1717231200, 'unixepoch') AS human_readable_date,
           strftime('%s', '2024-06-01 14:00:00') AS unix_epoch;

.. :

    https://database.guide/how-to-use-and-store-dates-in-sqlite/

----

:class: t2c

Check I
=======
.. code:: sql
  :number-lines:

  create table s (
    sn      char(10) primary key,
    sname   char(30) not null,
    status  int check(status >= 10),
    city    char(20) default 'Shiraz',
    unique(sname, city)
  );

.. code:: sql
  :number-lines:
  :class: substep

  create table sp (
     sn    char(10) references s,
     pn    char(10) references p,
     qty   int check(qty > 0),
     primary key (sn, pn)
  );

.. code:: sql
  :number-lines:
  :class: substep

  create table p (
    pn     char(10) primary key,
    pname  char(30) not null,
    color  char(20),
    weight numeric(9, 2)
        check(weight > 2 and weight < 90000),
    city   char(20)
  );

.. code:: sql
  :number-lines:
  :class: substep

  CREATE TABLE t (
    a NUMERIC CHECK (a >= 0),
    b NUMERIC CHECK (b >= 0),
    CHECK ( a + b <= 10 )
  );

.. :

    https://modern-sql.com/concept/three-valued-logic

    The follwing links has also schema and data of database

    https://github.com/vrajmohan/pgsql-sample-data/blob/master/date_spj.sql
    https://github.com/vrajmohan/pgsql-sample-data

    create table sp (
        sn    char(10) references s on update cascade on delete cascade,
        pn    char(10) references p on update cascade on delete cascade,
        qty   int default 1 check(qty > 0),
        primary key (sn, pn)
    );

----

:class: t2c

Check II
========
.. code:: sql

    CREATE TABLE people (
        id  INTEGER PRIMARY KEY,
        age INTEGER CHECK (age >= 0)
    );

    INSERT INTO people (age) VALUES
        (1,25), (2,NULL), (3,-5);

.. code:: sql

    CREATE TABLE employees (
        id       INTEGER PRIMARY KEY,
        name     CHAR(20) NOT NULL,
        salary   REAL NOT NULL,
        bonus    REAL NOT NULL DEFAULT 0,
        CONSTRAINT salary_positive CHECK (salary > 0),
        CONSTRAINT bonus_not_negative CHECK (bonus >= 0),
        CONSTRAINT bonus_not_huge CHECK (bonus <= salary)
    );

    INSERT INTO employees VALUES (1, 'Ada', 60000, 70000);


.. code:: sql

    CREATE TABLE users (
        id       INTEGER PRIMARY KEY,
        email    CHAR(20)
          CHECK(email LIKE '%_@_%.__%'),
        username CHAR(20)
          CHECK(length(username) BETWEEN 3 AND 20),
        country  CHAR(20)
          CHECK(country = upper(country))
    );

    INSERT INTO users VALUES
        (1, 'ada@example.com', 'ada', 'US'),
        (2, 'not-an-email', 'ada2', 'US'),
        (3, 'boris@x.io', 'b', 'US'),
        (4, 'cara@x.io', 'cara', 'us');

.. :

    Transaction(I)
    ==================
    حساب بانکی را در نظر بگیرید می‌خواهیم پولی را به حساب فرد دیگری بفرستیم. در ساده‌ترین حالت باید دو دستور به روز رسانی انحام شود.

    الف. از حساب من مقداری کم بشه

    ب. به حساب گیرنده واریز بشه

    پس دست کم دو دستور update

    .. code:: sql

      member( ssn_ , sname, balance)


    حساب بانکی را در نظر بگیرید می‌خواهیم پولی را به حساب فرد دیگری بفرستیم. در ساده‌ترین حالت باید دو دستور به روز رسانی انحام شود.
    الف. از حساب من مقداری کم بشه
    ب. به حساب گیرنده واریز بشه
    پس دست کم دو دستور update

    الف و ب دو دستور یا مجموعه دستورهای مجزای SQL  خواهند شد.

    insert into S(sn,sname,status,city) values('S1','Smith',20,'London');

    تراکنش دستور یا مجموعه دستورهایی هست که می‌خواهیم یا همه انجام شود یا هیچ کدام انجام نشود. transaction

    ----

----

:class: t2c

Transaction(I)
====================
.. code:: sql
    :number-lines:

    CREATE TABLE accounts (
        account_no INTEGER,
        balance DECIMAL DEFAULT 0,
        PRIMARY KEY(account_no),
          CHECK(balance >= 0)
    );

.. code:: sql
    :number-lines:
    :class: substep

    UPDATE accounts
     SET balance = balance - 1000
    WHERE account_no = 100;

    UPDATE accounts
     SET balance = balance + 1000
    WHERE account_no = 200;

.. code:: sql
    :number-lines:
    :class: substep

    BEGIN TRANSACTION;

    UPDATE accounts
     SET balance = balance - 1000
    WHERE account_no = 100;

    UPDATE accounts
     SET balance = balance + 1000
    WHERE account_no = 200;


    COMMIT;

.. code:: sql
    :number-lines:
    :class: substep

    BEGIN TRANSACTION;

    UPDATE accounts
     SET balance = balance - 1000
    WHERE account_no = 100;

    UPDATE accounts
     SET balance = balance + 1000
    WHERE account_no = 200;


    ROLLBACK;

----

:class: t2c

Transaction(II)
====================
.. code:: sql

  CREATE TABLE accounts (
    account_no INTEGER NOT NULL,
    balance DECIMAL NOT NULL DEFAULT 0,
    PRIMARY KEY(account_no),
               CHECK(balance >= 0)
  );

  CREATE TABLE account_changes (
    change_no INT NOT NULL PRIMARY KEY,
    account_no INTEGER NOT NULL,
    flag TEXT NOT NULL,
    amount DECIMAL NOT NULL,
    changed_at TEXT NOT NULL,
    foreign key (account_no)
        references accounts(account_no)
  );

.. code:: sql

  BEGIN TRANSACTION;

  UPDATE accounts
     SET balance = balance - 1000
  WHERE account_no = 100;

  UPDATE accounts
     SET balance = balance + 1000
  WHERE account_no = 200;

  INSERT INTO account_changes
  VALUES(10, 100,'-',1000,datetime('now'));

  INSERT INTO account_changes
  VALUES(11, 200,'+',1000,datetime('now'));

  COMMIT;

Auto commit
-----------

----

:class: t2c

Transaction(III)
================
.. code:: sql
    :number-lines:

    CREATE TABLE counter(n INTEGER);
    INSERT INTO counter VALUES (1);

    BEGIN;
    SELECT n FROM counter; -- 1
    UPDATE counter SET n = 99;
    SELECT n FROM counter;
    -- 99, your own write is visible
    COMMIT;

    SELECT n FROM counter;

.. container::

    .. class:: substep

    * BEGIN DEFERRED(default)
    * BEGIN IMMEDIATE
    * BEGIN EXCLUSIVE

    .. class:: substep

    #. DDL inside transactions works
    #. VACUUM cannot run inside a transaction
    #. A failed COMMIT is still a real failure
    #. Long transactions block writers

.. :

    https://coddy.tech/docs/sqlite/transactions

    Things That Trip People Up
    ---------------------------

    * BEGIN DEFERRED (the default) — no lock at all until you read or write. The write lock is acquired lazily, on the first write statement.
    * BEGIN IMMEDIATE — grab the write lock right away. Other connections can still read, but no other connection can start writing.
    * BEGIN EXCLUSIVE — like IMMEDIATE, plus no other connection can read either. In WAL mode this behaves the same as IMMEDIATE; the difference only matters in the older rollback journal mode.

    * DDL inside transactions works. CREATE TABLE, ALTER TABLE, even DROP TABLE can be rolled back. SQLite is unusual that way — many databases auto-commit DDL.
    * VACUUM cannot run inside a transaction. Neither can a few other maintenance commands. Run them in autocommit mode.
    * A failed COMMIT is still a real failure. If COMMIT returns SQLITE_BUSY (rare but possible), the transaction is not committed. Your code needs to handle that — usually by retrying.
    * Long transactions block writers. A transaction that stays open for minutes will block other writers for minutes. Open them late, commit them quickly.


----

:class: t2c

Savepoint
=========
.. code:: sql
    :number-lines:

    CREATE TABLE accounts
        (name TEXT, balance INTEGER);
    INSERT INTO accounts VALUES
        ('Ada', 100), ('Boris', 100);

    BEGIN;
      UPDATE accounts
      SET balance = balance - 30
      WHERE name = 'Ada';

      SAVEPOINT risky;
        UPDATE accounts
        SET balance = balance + 30
        WHERE name = 'Nobody';

      ROLLBACK TO risky;

      UPDATE accounts
      SET balance = balance + 30
      WHERE name = 'Boris';

    COMMIT;

    SELECT * FROM accounts;

.. container::

    .. code:: sql
        :number-lines:
        :class: substep

        CREATE TABLE log (msg TEXT);

        BEGIN;
          INSERT INTO log VALUES ('start');

          SAVEPOINT step1;
            INSERT INTO log VALUES ('step 1 done');
          RELEASE step1;

          SAVEPOINT step2;
            INSERT INTO log VALUES ('step 2 attempt');
          ROLLBACK TO step2;
            INSERT INTO log VALUES ('step 2 retry');
          RELEASE step2;
        COMMIT;

    .. class:: substep

    * COMMIT always commits the whole transaction
    * ROLLBACK (without TO) aborts everything
    * A savepoint stays open until released or rolled back through
    * Names aren't required to be unique

.. :

    https://coddy.tech/docs/sqlite/savepoints

.. :


    ----

    :claas: t2c

    Transaction(III)
    ====================
    .. code:: sql

      START TRANSACTION;
      BEGIN TRANSACTION;
      BEGIN WORK;
      BEGIN;
      START;

    .. code:: sql

      BEGIN;
        INSERT INTO table1 VALUES (1);
        SAVEPOINT my_savepoint;
        INSERT INTO table1 VALUES (2);
        ROLLBACK TO SAVEPOINT my_savepoint;
        INSERT INTO table1 VALUES (3);
      COMMIT;

    .. code:: sql

      BEGIN;
          INSERT INTO table1 VALUES (3);
          SAVEPOINT my_savepoint;
          INSERT INTO table1 VALUES (4);
          RELEASE SAVEPOINT my_savepoint;
      COMMIT;

    .. :

      https://www.postgresql.org/docs/current/sql-begin.html
      https://www.postgresql.org/docs/current/sql-savepoint.html


.. :

    Test For Auto-Commit Mode
    int sqlite3_get_autocommit(sqlite3*);
    The sqlite3_get_autocommit() interface returns non-zero or zero if the given database connection is or is not in autocommit mode, respectively. Autocommit mode is on by default. Autocommit mode is disabled by a BEGIN statement. Autocommit mode is re-enabled by a COMMIT or ROLLBACK.

    If certain kinds of errors occur on a statement within a multi-statement transaction (errors including SQLITE_FULL, SQLITE_IOERR, SQLITE_NOMEM, SQLITE_BUSY, and SQLITE_INTERRUPT) then the transaction might be rolled back automatically. The only way to find out whether SQLite automatically rolled back the transaction after an error is to use this function.

    If another thread changes the autocommit status of the database connection while this routine is running, then the return value is undefined.

    https://sqlite.org/c3ref/get_autocommit.html

    ----

    .. code:: sql

        create table accounts (
          account_no integer not null,
          balance DECIMAL not null default 0,
          primary key(account_no),
                     check(balance >= 0)
        );

        create table account_changes (
          change_no int not null primary key,
          account_no integer not null,
          flag text not null,
          amount DECIMAL not null,
          changed_at text not null
        );

    ----

    .. code:: sql

        insert into accounts (account_no,balance)
        values (100,20100);

        insert into accounts (account_no,balance)
        values (200,10100);
        select * from accounts;

        begin transaction;

        update accounts
           set balance = balance - 1000
         where account_no = 100;

        update accounts
           set balance = balance + 1000
         where account_no = 200;
        insert into account_changes(change_no, account_no,flag,amount,changed_at)
        values(10, 100,'-',1000,datetime('now'));

    .. code:: sql

        insert into account_changes(change_no, account_no,flag,amount,changed_at)
        values(11, 200,'+',1000,datetime('now'));

        COMMIT;

        select * from accounts;


        begin transaction;

        update accounts
           set balance = balance - 20000
         where account_no = 100;

    .. code:: sql

        insert into account_changes(account_no,flag,amount,changed_at)
        values(100,'-',20000,datetime('now'));


    .. :

      13990919

----

:class: t2c

Vacuum
===========
.. code:: sql

    vacuum;

    vacuum full;

.. code:: sql

    pragma auto_vacuum = full;
    pragma auto_vacuum = incremental;
    pragma auto_vacuum = none;

.. :

    https://www.sqlitetutorial.net/sqlite-vacuum/
    vacuum with an into clause
    -------------------------------
    .. code::sql

        vacuum schema-name into filename;

        vacuum main into 'spj_backup.db';

----

Alter Table
============
DDL
-----
.. code:: sql

  alter table sp add "comment" varchar(50);

  alter table sp drop "comment";

  alter table sp add "comment" varchar(50) default '';

.. image:: img/sql/alter_table_sqlite.png

----

Alter table Foreign key
================================
MySQL / SQL Server / Oracle / MS Access
-----------------------------------------------
.. code:: sql

    alter table Orders
    add constraint FK_PersonOrder
    foreign key (PersonID) references Persons(PersonID);

----

END

----

:class: t2c

Unique(I)
==========
.. code:: sql

    CREATE TABLE Persons (
        ID int NOT NULL UNIQUE,
        LastName varchar(255) NOT NULL,
        FirstName varchar(255),
        Age int
    );

.. code:: sql
    :class: substep

    CREATE TABLE Persons (
        ID int NOT NULL,
        LastName varchar(255) NOT NULL,
        FirstName varchar(255),
        Age int,
        UNIQUE (ID)
    );

.. code:: sql
    :class: substep

    CREATE TABLE Persons (
        ID int NOT NULL,
        LastName varchar(255) NOT NULL,
        FirstName varchar(255),
        Age int,
        CONSTRAINT UC_Person UNIQUE (ID,LastName)
    );

.. code:: sql
    :class: substep

    create table "student"(
      "SSN" varchar(20) unique not null,
      "name" varchar(40) not null,
      "student_number" bigint Primary key
      );

    insert into
      "student"("SSN", "name", "student_number")
    values
    ("38947389", "کامران خداپرستی", 973433),
    ("38472389", "کوروش پارسایی", 9632847),
    ("38947389", ")احمد یوسفان", 93802932);

----

:class: t2c

Unique(II)
===========
.. code:: sql

    create table contacts(
        contact_id integer primary key,
        first_name text,
        last_name text,
        email text not null UNIQUE
    );

.. code:: sql

    create table shapes(
      shape_id integer primary key,
      background_color text,
      foreground_color text,
      UNIQUE(background_color,foreground_color)
    );

.. :

  https://www.sqlitetutorial.net/sqlite-unique-constraint/

.. code:: sql

    ALTER TABLE Persons
    ADD UNIQUE (ID);

.. code:: sql

    ALTER TABLE Persons
    ADD CONSTRAINT UC_Person
      UNIQUE (ID,LastName);

.. code:: sql

    ALTER TABLE Persons
    DROP CONSTRAINT UC_Person;

----

:class: t2c

Unique(III)
=======================
.. code:: sql

    create table contacts (
      contact_id integer primary key,
      first_name text    not null,
      last_name  text    not null,
      email      text,
      phone      text    not null
        check (length(phone) >= 10)
    );

.. code:: sql
    :class: substep

    create table products (
      product_id   integer         primary key,
      product_name text            not null,
      list_price   DECIMAL (10, 2) not null,
      discount     DECIMAL (10, 2) not null
                                  default 0,
      check (list_price >= discount and
          discount >= 0 and
          list_price >= 0)
    );


.. :

  https://www.sqlitetutorial.net/sqlite-unique-constraint/
  https://www.w3schools.com/sql/sql_check.asp
