:data-transition-duration: 1000
:skip-help: true
:css: ./style.css
:substep: true
:slide-numbers: true

.. role:: ltr
    :class: ltr

.. role:: rtl
    :class: rtl

----

Database Course
==================
Entity Relation Model
---------------------------
Ahmad Yoosofan

University of Kashan


.. :

  ## https://graphviz.org/Gallery/undirected/ER.html

  graph ER {
    fontname="Helvetica,Arial,sans-serif"
    node [fontname="Helvetica,Arial,sans-serif"]
    edge [fontname="Helvetica,Arial,sans-serif"]
    layout=neato
    node [shape=box]; course; institute; student;
    node [shape=ellipse]; {node [label="name"] name0; name1; name2;}
      code; grade; number;
    node [shape=diamond,style=filled,color=lightgrey]; "C-I"; "S-C"; "S-I";

    name0 -- course;
    code -- course;
    course -- "C-I" [label="n",len=1.00];
    "C-I" -- institute [label="1",len=1.00];
    institute -- name1;
    institute -- "S-I" [label="1",len=1.00];
    "S-I" -- student [label="n",len=1.00];
    student -- grade;
    student -- name2;
    student -- number;
    student -- "S-C" [label="m",len=1.00];
    "S-C" -- course [label="n",len=1.00];

    label = "\n\nEntity Relation Diagram\ndrawn by NEATO";
    fontsize=20;
  }

----

create table
================
.. code:: sql

  create table s (
     sn      char(10) primary key,
     sname   char(30),
     status  int  default 0,
     city    char(20)
  );


DSL(Data Sub Language)
-------------------------
SQL (Structured Query Language)

* DDL: Data Definition Language
* DML: Data Manipluation Language
* DCL: Data Control Language

DDL: create table

----

Tools
========
Online
-----------
#. https://sql.js.org/examples/GUI/
#. https://sql.js.org/#/
#. https://www.sqlitetutorial.net/
#. https://sqliteonline.com/
#. `<https://extendsclass.com/sqlite-browser.html#>`_
#. https://inloop.github.io/sqlite-viewer/
#. https://github.com/inloop/sqlite-viewer
#. https://github.com/sql-js/sql.js
#. https://sql.js.org/#/
#. http://sqlfiddle.com/
#. https://github.com/coleifer/sqlite-web
#. https://sqlitestudio.pl/
#. https://www.onworks.net/programs/sqlite-online?amp=0
#. https://www.heidisql.com/#featurelist
#. https://sqlzoo.net/

Install
--------
* https://sqlitebrowser.org/

----

.. code:: sql

  create table s (
     sn      char(10) primary key,
     sname   char(30),
     status  int  default 0,
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
     qty   int default 0,
     primary key (sn, pn)
  );

----

Problems
======================================================
..  class:: rtl

   *  نام عرضه کنندگانی را به دست آورید که همه‌ی قطعه‌های همشهری خود را عرضه می‌کنند.
   *  نام عرضه کنندگانی را به دست آورید که فقط قطعه‌های همشهری خود را عرضه می‌کنند.
   *  نام عرضه کنندگانی را به دست آورید که فقط قطعه‌های با وزن کمتر از ۱۰۰ زا عرضه می‌کنند.
   *  مجموع وزن قطعه‌هایی را به دست آورید که عرضه شده‌اند.
   *  نام شهرها و مجموع وزن قطعه‌های آن شهرهایی را به دست آورید که همه‌ی عرضه کنندگان درون آن شهرها آن قطعه‌ها را عرضه کرده باشند.
   *  نام زوج شهرهای عرضه کنندگان و قطعه‌هایی را به دست آورید که آن عرضه کننده آن قطعه را عرضه کرده است.
   *  نام زوج شهرهای عرضه کنندگان و قطعه‌هایی را به دست آورید که آن عرضه کننده آن قطعه را عرضه کرده است. زوج‌های تکراری در این راه حل نباید وجود داشته باشد. دقت کنید که دو زوج (الف ، ب) و (ب ، الف) متفاوت هستند.


.. contents::  فهرست

.. comment:

  rst2s5.py rsts5.txt rsts5.html -d -t --section-numbering --stylesheet=farsi.css,html4css1.css
  rst2html  sql.samples.sql   sql.samples.html --stylesheet=myfarsi.css,html4css1.css

  https://intellipaat.com/blog/tutorial/sql-tutorial/like-and-between-operators-in-sql/#_sql_like
  https://beginner-sql-tutorial.com/sql-like-in-operators.htm
  sql between like
  https://lornajane.net/posts/2011/inner-vs-outer-joins-on-a-many-to-many-relationship
  https://www.w3schools.com/sql/default.asp

  insert into S(sn,sname,status,city) values('S1','Smith',20,'London');
  insert into S(sn,sname,status,city) values('S2','Jones',10,'Paris' );
  insert into S(sn,sname,status,city) values('S3','Blake',30,'Paris' )

----

speed up
===============
sql speed up select * instead of fields

* https://www.freelancer.com/articles/web-development/how-to-make-your-sql-queries-faster
* https://stackoverflow.com/questions/17354219/how-to-speed-up-sql-queries-indexes/17354616
* https://www.infoworld.com/article/3209665/sql-unleashed-17-ways-to-speed-your-sql-queries.html
* https://stackoverflow.com/questions/65512/which-is-faster-best-select-or-select-column1-colum2-column3-etc
* https://www.jdoodle.com/execute-sql-online/
* https://intellipaat.com/blog/tutorial/sql-tutorial/like-and-between-operators-in-sql/#_sql_like
* https://beginner-sql-tutorial.com/sql-like-in-operators.htm
* sql between like
* https://lornajane.net/posts/2011/inner-vs-outer-joins-on-a-many-to-many-relationship
* https://www.w3schools.com/sql/default.asp
