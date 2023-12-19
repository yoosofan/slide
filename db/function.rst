:data-transition-duration: 1000
:skip-help: true
:css: style.css
:substep: true
:slide-numbers: true

----

Function in SQL
===================================================
PostgreSQL
--------------

Ahmad Yoosofan

Database course

University of Kashan, Spring 2021

-----

:class: t2c

sample 1
============
.. code:: sql
  :number-lines:

  CREATE FUNCTION f_typetest01(INTEGER)
  RETURNS bool
  AS
  'SELECT TRUE'
  LANGUAGE sql;

.. code:: sql
  :class: substep
  :number-lines:

  CREATE OR REPLACE FUNCTION f_typetest01(INTEGER)
    RETURNS bool
    AS
    'SELECT TRUE'
    LANGUAGE sql;

.. code:: sql
  :class: substep

  select f_typetest01(12);

.. code:: sh
  :class: substep

  f_typetest01
  --------------
  t
  (1 row)

.. code:: sql
  :class: substep

  select *
  from f_typetest01(12)
  ;

.. code:: sh
  :class: substep

  f_typetest01
  --------------
  t
  (1 row)

.. :

  https://stackoverflow.com/a/24771122/886607

-----

Sample 2
============
.. code:: sql
    :number-lines:

    CREATE OR REPLACE FUNCTION myf(d1 VARCHAR) RETURNS INTEGER
    AS
    $$
    SELECT MAX(qty) FROM sp WHERE sn=d1;
    $$ LANGUAGE SQL;

.. code:: sql

  select myf('S1')
  ;

.. code:: sh

   myf
  -----
   400
  (1 row)

----

Sample 3
===========
.. code:: sql
    :number-lines:

    DROP FUNCTION IF EXISTS test03();
    CREATE FUNCTION test03() RETURNS INTEGER AS $ABC$
    DECLARE
      quantity integer := 30;
      q2 integer := 30;
    BEGIN
      -- RAISE NOTICE 'Quantity here is %', quantity; -- Prints 30
      SELECT max(qty) into q2 from sp;
      RETURN q2;
    END;
    $ABC$ LANGUAGE plpgsql;

----

Function parts
=================
.. code:: sql
    :number-lines:

    DROP FUNCTION IF EXISTS somefunc(VARCHAR(10));

    CREATE FUNCTION somefunc(nm1 VARCHAR(10)) RETURNS INTEGER AS $ABC$
    DECLARE
      quantity integer := 30;
    BEGIN
      -- RAISE NOTICE 'Quantity here is %', quantity; -- Prints 30
      SELECT status INTO quantity FROM s WHERE sn=nm1;
      quantity := quantity * 50;
      /*
      -- Create a subblock
      --
      RAISE NOTICE 'Quantity here is %', quantity;*/
      RETURN quantity;
    END;
    $ABC$ LANGUAGE plpgsql;

.. code:: sql

  select somefunc('S1')
  ;

.. code:: sh

  somefunc
  ----------
  1000
  (1 row)

----

.. code:: sql
    :number-lines:

    DROP FUNCTION IF EXISTS somefunc2(VARCHAR(10),nm2 VARCHAR(10));

    CREATE FUNCTION somefunc2(nm1 VARCHAR(10), nm2 VARCHAR(10))
    RETURNS INTEGER AS $$
    DECLARE
      quantity integer := 30;
    BEGIN
      SELECT qty INTO quantity FROM sp WHERE sn=nm1 and pn=nm2;
      RAISE NOTICE 'Quantity here is %', quantity;
      RETURN quantity;
    END;
    $$ LANGUAGE plpgsql;

----

.. code:: sql
    :number-lines:

    CREATE OR REPLACE FUNCTION somefunc03(nm1 CHAR(10), nm2 CHAR(10),
       o1 OUT INTEGER)
     AS $$
    DECLARE
      quantity integer := 30;
    BEGIN
      SELECT qty INTO quantity FROM sp WHERE sn=nm1 and pn=nm2;
      -- RAISE NOTICE 'Quantity here is %', quantity;
      o1 := quantity;
    END;
    $$ LANGUAGE plpgsql;

----

.. code:: sql
    :number-lines:

    CREATE OR REPLACE FUNCTION test03() RETURNS INTEGER AS $ABC$
    DECLARE
      quantity INTEGER := 30;
      q2  INTEGER  := 30;
      snp CHAR(10) := 'S1';
      pnp CHAR(10) := 'P1';
    BEGIN
      -- RAISE NOTICE 'Quantity here is %', quantity; -- Prints 30
      SELECT somefunc03(snp, pnp, q2);
      RETURN q2;
    END;
    $ABC$ LANGUAGE plpgsql;

----

.. code:: sql
    :number-lines:

    DROP FUNCTION somefunc04(nm1 VARCHAR(10)) ;
    CREATE FUNCTION somefunc04(nm1 VARCHAR(10))
    RETURNS SETOF sp AS $$
    BEGIN
      IF nm1='S1' THEN
        RETURN QUERY SELECT * FROM sp WHERE sn='S2';
      ELSE
        RETURN QUERY SELECT * FROM sp WHERE sn=nm1 ;
      END IF;
    END;
    $$ LANGUAGE plpgsql;

----

.. code:: sql
    :number-lines:

    DROP FUNCTION somefunc05(nm1 VARCHAR(10),nm2 VARCHAR(10));
    CREATE FUNCTION somefunc05(nm1 VARCHAR(10),nm2 VARCHAR(10))
    RETURNS SETOF sp AS $$
    DECLARE
      i INTEGER :=0;
    BEGIN
      LOOP
        CASE i
          WHEN 1 THEN
            RETURN QUERY SELECT * from sp where sn='S2';
          WHEN 2 THEN
            RETURN QUERY SELECT * FROM sp WHERE sn='S3';
          ELSE
            RETURN QUERY (SELECT * FROM sp WHERE pn=nm2);
        END CASE;
        i:=i+1;
        EXIT WHEN i>2;
      END LOOP;
    END;
    $$ LANGUAGE plpgsql;

.. code:: sql

  select somefunc05('S1', 'P1');

.. code:: sh

  somefunc05            
  ---------------------------------
   ("S1        ","P1        ",300)
   ("S2        ","P1        ",300)
   ("S2        ","P1        ",300)
   ("S2        ","P2        ",400)
   ("S3        ","P2        ",200)
  (5 rows)

----

.. code:: sql
    :number-lines:

    DROP FUNCTION somefunc05_3(nm2 VARCHAR(10));
    CREATE FUNCTION somefunc05_3(nm2 VARCHAR(10))
    RETURNS SETOF sp AS $$
    DECLARE
      i INTEGER :=0;
    BEGIN
      --RETURN QUERY SELECT * from sp where sn='S2';
      RETURN QUERY SELECT * FROM sp WHERE sn='S3';
    END;
    $$ LANGUAGE plpgsql;

.. code:: sh

    sp=# select somefunc05('S1','P1');

               somefunc05
    ---------------------------------
     ("S1        ","P1        ",300)
     ("S2        ","P1        ",300)
     ("S2        ","P1        ",300)
     ("S2        ","P2        ",400)
     ("S3        ","P2        ",200)
    (5 rows)

----

.. code:: sql
    :number-lines:

    DROP FUNCTION somefunc05_4(nm2 VARCHAR(10));
    CREATE FUNCTION somefunc05_4(nm2 VARCHAR(10))
    RETURNS SETOF sp AS $$
    DECLARE
      i INTEGER :=0;
    BEGIN
      --RETURN QUERY SELECT * from sp where sn='S2';
      --RETURN QUERY SELECT * FROM sp WHERE sn='S3';
      RETURN QUERY (SELECT * FROM sp WHERE pn=nm2);
    END;
    $$ LANGUAGE plpgsql;


.. code:: sh

    sp=# select somefunc05('S1','P1');
               somefunc05
    ---------------------------------
     ("S1        ","P1        ",300)
     ("S2        ","P1        ",300)
     ("S2        ","P1        ",300)
     ("S2        ","P2        ",400)
     ("S3        ","P2        ",200)
    (5 rows)

----

.. code:: sql
    :number-lines:

    DROP FUNCTION somefunc05_5(nm2 VARCHAR(10));
    CREATE FUNCTION somefunc05_5(nm2 VARCHAR(10))
    RETURNS SETOF sp AS $$
    DECLARE
      i INTEGER :=0;
    BEGIN
      RETURN QUERY SELECT * from sp where sn='S2';
      RETURN QUERY SELECT * FROM sp WHERE sn='S3';
      RETURN QUERY SELECT * FROM sp WHERE pn=nm2;
    END;
    $$ LANGUAGE plpgsql;

.. code:: sh

    sp=# select somefunc05('S1','P1');
               somefunc05
    ---------------------------------
     ("S1        ","P1        ",300)
     ("S2        ","P1        ",300)
     ("S2        ","P1        ",300)
     ("S2        ","P2        ",400)
     ("S3        ","P2        ",200)
    (5 rows)


----

.. code:: sql
    :number-lines:

    DROP FUNCTION sf06() ;
    CREATE FUNCTION sf06()
    RETURNS SETOF sp AS $$
    DECLARE
      i INTEGER :=0;
      r sp%rowtype;
    BEGIN
      FOR r IN SELECT * FROM sp LOOP
        CASE i
          WHEN 1 THEN
            RETURN NEXT r;
          WHEN 2 THEN
            RETURN NEXT r;
          ELSE
            RETURN NEXT r;
        END CASE;
        i:=i+1;
        EXIT WHEN i>2;
      END LOOP;
    END;
    $$ LANGUAGE plpgsql;

.. code:: sh

    sp=# \i simple.function.06.sql
    CREATE FUNCTION
    sp=# select * from sf06('S1','P1');
        sno     |    pno     | qty
    ------------+------------+-----
     S1         | P1         | 300
     S1         | P2         | 200
     S1         | P3         | 400
    (3 rows)

----

:class: t2c

Simple Functions 1
====================
.. code:: sql
    :number-lines:

    CREATE OR REPLACE 
    FUNCTION get_year(INTEGER)
    RETURNS INTEGER AS $$
    BEGIN
      RETURN ( $1 / 10000);
    END;
    $$ LANGUAGE plpgsql
    RETURNS NULL ON NULL INPUT;

.. code:: sql
    :number-lines:

    CREATE OR REPLACE 
    FUNCTION get_month(INTEGER)
    RETURNS INTEGER AS $$
    BEGIN
      RETURN ( $1 / 100 ) % 100;
    END;
    $$ LANGUAGE plpgsql
    RETURNS NULL ON NULL INPUT;

.. code:: sql
    :number-lines:

    CREATE OR REPLACE 
    FUNCTION get_day(INTEGER)
    RETURNS INTEGER AS $$
    BEGIN
      RETURN $1  % 100 ;
    END;
    $$ LANGUAGE plpgsql
    RETURNS NULL ON NULL INPUT;

.. code:: sql
    :number-lines:

    CREATE OR REPLACE FUNCTION 
    get_year_and_month(INTEGER)
    RETURNS INTEGER AS $$
    BEGIN
      RETURN ( $1 / 100);
    END;
    $$ LANGUAGE plpgsql
    RETURNS NULL ON NULL INPUT;

----


.. code:: sql
    :number-lines:

    CREATE OR REPLACE FUNCTION convert_int_date_to_varchar10(integer)
    RETURNS VARCHAR(10) AS $BODY$
    BEGIN
      RETURN ( substring($1::text FROM 1 FOR 4) || '-' ||
        substring($1::text FROM 5 FOR 2) || '-' ||
        substring($1::text FROM 7 FOR 2) )::varchar(10);
    END;
    $BODY$ LANGUAGE plpgsql
    RETURNS NULL ON NULL INPUT;

----

.. code:: sql
    :number-lines:

    CREATE OR REPLACE FUNCTION uniform_text_jdatei4search(text)
    RETURNS VARCHAR(10) AS $BODY$
    DECLARE
      lmy_str1 varchar(10);
    BEGIN
      lmy_str1 := substring($1 from '^[0-9]+') ;
      IF character_length(lmy_str1)=8 THEN
        RETURN (substring(lmy_str1 FROM 1 FOR 4) || '-' ||
            substring(lmy_str1 FROM 5 FOR 2) || '-' ||
            substring(lmy_str1 FROM 7 FOR 2) )::varchar(10);
      ELSEIF character_length(lmy_str1)=6 THEN
        RETURN (substring(lmy_str1 FROM 1 FOR 4) || '-' ||
            substring(lmy_str1 FROM 5 FOR 2) )::varchar(10);
      END IF;
    END;
    $BODY$ LANGUAGE plpgsql
    RETURNS NULL ON NULL INPUT;

----

.. code:: sql
    :number-lines:

    CREATE OR REPLACE FUNCTION composit_idate(text,integer)
    RETURNS TEXT AS $BODY$
    DECLARE
      lmy_astr1 TEXT ARRAY;
    BEGIN
      lmy_astr1 := regexp_split_to_array($1 ,'\$\@') ;
      --RAISE NOTICE 'values are %', lmy_astr1[1];
      RETURN lmy_astr1[$2];
    END;
    $BODY$ LANGUAGE plpgsql
    RETURNS NULL ON NULL INPUT;

----

.. code:: sql
    :number-lines:

    CREATE OR REPLACE FUNCTION is_leap_year(INTEGER)
    RETURNS INTEGER AS $$
    DECLARE
      p INTEGER;
      leap INTEGER;
    BEGIN
      p := ( ( $1 + 2346 ) % 2820 ) % 128 ;
      IF p = 5 OR p = 9 OR p = 13 OR p = 17 OR p = 21 OR p = 25 OR p = 29 OR
         p = 34 OR p = 38 OR p = 42  OR p = 46 OR p = 50 OR p = 54 OR p = 58 OR
         p = 62 OR p = 67 OR p = 71 OR p = 75  OR p = 79 OR p = 83 OR
         p = 87 OR p = 91 OR p = 95 OR p = 100 OR p = 104 OR p = 108 OR
         p = 112 OR p = 116 OR p = 120 OR p = 124 THEN
        leap := 1;
      ELSE
        leap := 0;
      END IF;
      RETURN leap ;
    END;
    $$ LANGUAGE plpgsql
    RETURNS NULL ON NULL INPUT;

----

Related
==============

* http://www.postgresql.org/docs/9.5/static/sql-createfunction.html
* http://stackoverflow.com/questions/30782925/postgresql-how-to-drop-function-if-exists-without-specifying-parameters
* http://stackoverflow.com/questions/30782925/postgresql-how-to-drop-function-if-exists-without-specifying-parameters
* https://github.com/malimome/pgsql-jalalical/blob/master/install/pdate.source
* https://gist.github.com/ilius
* https://stackoverflow.com/questions/52436973/postgresql-does-postgresql-support-persian-calendar


.. comments:

    rst2html function.rst function.html --stylesheet=farsi.css,html4css1.css

    postgresql function example
    http://www.postgresqltutorial.com/postgresql-create-function/
    https://www.postgresql.org/docs/9.1/sql-createfunction.html
    https://www.tutorialspoint.com/postgresql/postgresql_functions.htm
    https://severalnines.com/database-blog/postgresql-triggers-and-stored-function-basics
    https://www.javatpoint.com/postgresql-functions
    https://www.javatpoint.com/postgresql-trigger
    https://joeconway.com/presentations/function_basics.pdf


