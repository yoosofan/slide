:data-transition-duration: 1000
:skip-help: true
:css: style.css
:substep: true
:slide-numbers: true

----

Triggers
=============
PostgreSQL
--------------

Ahmad Yoosofan

Database course

University of Kashan, Spring 2020

----

Uses for triggers
======================
*    Enforce business rules
*    Validate input data
*    Generate a unique value for a newly-inserted row in a different file.
*    Write to other files for audit trail purposes
*    Query from other files for cross-referencing purposes
*    Access system functions
*    Replicate data to different files to achieve data consistency

----

:data-rotate: 90


Benefits of using triggers in business
===========================================
*   Faster application development. Because the database stores triggers, you do not have to code the trigger actions into each database application.
*   Global enforcement of business rules. Define a trigger once and then reuse it for any application that uses the database.
*   Easier maintenance. If a business policy changes, you need to change only the corresponding trigger program instead of each application program.
*   Improve performance in client/server environment. All rules run on the server before the result returns.

----

:data-y: r1000

Synopsis
===============
.. code:: sql
    :number-lines:
    
    CREATE [ CONSTRAINT ] TRIGGER name { BEFORE | AFTER | INSTEAD OF }
        { event [ OR ... ] }    ON table_name
        [ FROM referenced_table_name ]
        [ NOT DEFERRABLE | [ DEFERRABLE ]
            [ INITIALLY IMMEDIATE | INITIALLY DEFERRED ]
        ]
        [ REFERENCING { { OLD | NEW } TABLE [ AS ]
            transition_relation_name } [ ... ]
        ]
        [ FOR [ EACH ] { ROW | STATEMENT } ]
        [ WHEN ( condition ) ]
        EXECUTE { FUNCTION | PROCEDURE } function_name ( arguments )

where *event* can be one of:
-------------------------------
*   INSERT
*   UPDATE [ OF column_name [, ... ] ]
*   DELETE
*   TRUNCATE

----

:data-y: r1000


.. class:: smallerelementwithfullborder

    .. csv-table::
        :header: "When", "Event", "Row-level", "Statement-level"

        "BEFORE", "INSERT/UPDATE/DELETE", "Tables and foreign tables", "Tables, views, and foreign tables"
        "BEFORE", "TRUNCATE", "—", "Tables"
        "AFTER", "INSERT/UPDATE/DELETE", "Tables and foreign tables", "Tables, views, and foreign tables"
        "AFTER", "TRUNCATE", "—", "Tables"
        "INSTEAD OF", "INSERT/UPDATE/DELETE", "Views", "—"
        "INSTEAD OF", "TRUNCATE", "—", "—"

----

:data-y: r1000

.. code:: sql
    :number-lines:
    
    CREATE OR REPLACE FUNCTION test()
      RETURNS trigger AS
    $$
    BEGIN
      INSERT INTO test_table(col1, col2, col3)
      VALUES(NEW.col1, NEW.col2, current_date);

      RETURN NEW;
    END;
    $$
    LANGUAGE 'plpgsql';

.. code:: sql
    :number-lines:

    CREATE TRIGGER test_trigger
      AFTER INSERT
      ON test_table
      FOR EACH ROW
      EXECUTE PROCEDURE test();

.. code:: sql
    :number-lines:
    
    INSERT INTO "test_table"("col1", "col2") VALUES("A", "B");

----

:data-rotate: 90

.. code:: sql
    :number-lines:
    
    CREATE OR REPLACE FUNCTION rec_insert()
    RETURNS trigger AS
    $$
    BEGIN
      INSERT INTO emp_log(emp_id,salary,edittime)
      VALUES(NEW.employee_id, NEW.salary, current_date);
      RETURN NEW;
    END;
    $$
    LANGUAGE 'plpgsql';

.. code:: sql
    :number-lines:
            
    CREATE TRIGGER ins_same_rec
      AFTER INSERT
      ON emp_details
      FOR EACH ROW
      EXECUTE PROCEDURE rec_insert();

.. code:: sql
    :number-lines:
    
    INSERT INTO emp_details VALUES(236, 'RABI', 'CHANDRA', 'RABI',
    '590.423.45700', '2013-01-12', 'AD_VP', 15000, .5);

----

:id: ThreeD
:data-y: r1200
:data-rotate-x: 180

.. code:: sql
    :number-lines:
    
    CREATE OR REPLACE FUNCTION befo_insert()
      RETURNS trigger AS $$
    BEGIN
    NEW.FIRST_NAME = LTRIM(NEW.FIRST_NAME);
    NEW.LAST_NAME = LTRIM(NEW.LAST_NAME);
    NEW.JOB_ID = UPPER(NEW.JOB_ID);
    RETURN NEW;
    END; $$ LANGUAGE 'plpgsql';

.. code:: sql
    :number-lines:
    
    CREATE TRIGGER che_val_befo_ins
      BEFORE INSERT
      ON emp_details
      FOR EACH ROW
      EXECUTE PROCEDURE befo_insert();

.. code:: sql
    :number-lines:
    
    INSERT INTO emp_details VALUES (334, ' Ana ', ' King', 'ANA',
    '690.432.45701', '2013-02-05', 'it_prog', 17000, .50);

----

:data-x: r800

.. code:: sql

    postgres=# SELECT * FROM student_mast;
     student_id |           name            | st_class
    ------------+---------------------------+----------
              1 | Steven King               |        7
              2 | Neena  Kochhar            |        8
              3 | Lex  De Haan              |        8
              4 | Alexander Hunold          |       10
    (4 rows)

* stu_log table has two columns user_id and description

----

.. code:: sql
    :number-lines:

    CREATE OR REPLACE FUNCTION aft_update()
      RETURNS trigger AS   $$
    BEGIN
    INSERT into stu_log VALUES (user, CONCAT('Update ',
             OLD.NAME,' Previous:',OLD.ST_CLASS,' Present: ',
             NEW.st_class));
    RETURN NEW;
    END; $$  LANGUAGE 'plpgsql';

.. code:: sql
    :number-lines:
    
    CREATE TRIGGER updt_log
      AFTER UPDATE
      ON student_mast
      FOR EACH ROW
      EXECUTE PROCEDURE aft_update();

.. code:: sql
    :number-lines:

    UPDATE STUDENT_MAST SET ST_CLASS = ST_CLASS + 1;

----

.. code:: sql

    postgres=# SELECT * FROM student_mast;
     student_id |           name            | st_class
    ------------+---------------------------+----------
              1 | Steven King               |        8
              2 | Neena  Kochhar            |        9
              3 | Lex  De Haan              |        9
              4 | Alexander Hunold          |       11
    (4 rows)

    postgres=# select * from stu_log;
    user_id |            description
    --------+---------------------------------------------------
    postgres| Update Steven King       Previous:7 Present 8
    postgres| Update Neena  Kochhar    Previous:8 Present 9
    postgres| Update Lex  De Haan      Previous:8 Present 9
    postgres| Update Alexander Hunold  Previous:10 Present 11
    (4 rows)

----

.. code:: sql
    :number-lines:
    
    CREATE OR REPLACE FUNCTION befo_update()
      RETURNS trigger AS $$
    BEGIN
    NEW.TOTAL = NEW.SUB1 + NEW.SUB2 + NEW.SUB3 + NEW.SUB4 + NEW.SUB5;
    NEW.PER_MARKS = NEW.TOTAL/5;
    IF NEW.PER_MARKS >=90 THEN
    NEW.GRADE = 'EXCELLENT';
    ELSEIF NEW.PER_MARKS>=75 AND NEW.PER_MARKS<90 THEN
    NEW.GRADE = 'VERY GOOD';
    ELSEIF NEW.PER_MARKS>=60 AND NEW.PER_MARKS<75 THEN
    NEW.GRADE = 'GOOD';
    ELSEIF NEW.PER_MARKS>=40 AND NEW.PER_MARKS<60 THEN
    NEW.GRADE = 'AVERAGE';
    ELSE
    NEW.GRADE = 'NOT PROMOTED';
    END IF;
    RETURN NEW;
    END;
    $$ LANGUAGE 'plpgsql';

.. code:: sql
    :number-lines:
    
    CREATE TRIGGER updt_marks
      BEFORE UPDATE
      ON student_marks
      FOR EACH ROW
      EXECUTE PROCEDURE befo_update();

.. code:: sql

    postgres=# SELECT * FROM STUDENT_MARKS;
     student_id |           name            | sub1 | sub2 | sub3 | sub4 | sub5 | total | per_marks |        grade
    ------------+---------------------------+------+------+------+------+------+-------+-----------+----------------------
              2 | Neena  Kochhar            |      |      |      |      |      |       |           |
              3 | Lex  De Haan              |      |      |      |      |      |       |           |
              4 | Alexander Hunold          |      |      |      |      |      |       |           |
              1 | Steven King               |   54 |   69 |   89 |   87 |   59 |   358 |        71 | GOOD
    (4 rows)

----

.. code:: sql
    :number-lines:
    
    CREATE OR REPLACE FUNCTION aft_delete()
      RETURNS trigger AS $$
    BEGIN
    INSERT into stu_log VALUES (user, CONCAT('Update Student Record ',
             OLD.NAME,' Class :',OLD.ST_CLASS,' -> Deleted on ',
             NOW()));
    RETURN NEW;
    END;  $$ LANGUAGE 'plpgsql';

.. code:: sql
    :number-lines:
    
    CREATE TRIGGER delete_stu
      AFTER DELETE
      ON student_mast
      FOR EACH ROW
      EXECUTE PROCEDURE aft_delete();

.. code:: sql

    postgres=# SELECT * FROM STUDENT_MAST;
     student_id |           name            | st_class
    ------------+---------------------------+----------
              2 | Neena  Kochhar            |        9
              3 | Lex  De Haan              |        9
              4 | Alexander Hunold          |       11
    (3 rows)

    postgres=# select * from stu_log;
              user_id          |                                             description
    ---------------------------+------------------------------------------------------------------------------------------------------
     postgres                  | Update Student Record Steven King               Previous Class :7 Present Class 8
     postgres                  | Update Student Record Neena  Kochhar            Previous Class :8 Present Class 9
     postgres                  | Update Student Record Lex  De Haan              Previous Class :8 Present Class 9
     postgres                  | Update Student Record Alexander Hunold          Previous Class :10 Present Class 11
     postgres                  | Update Student Record Steven King               Class :7 -> Deleted on 2014-09-16 16:30:35.093+05:30
    (5 rows)

----

.. code:: sql
    :number-lines:
    
    DROP TRIGGER [ IF EXISTS ] name ON table_name [ CASCADE | RESTRICT ]


.. code:: sql
    :number-lines:
    
    DROP TRIGGER delete_stu on student_mast;



----

.. list-table:: Frozen Delights!
   :widths: 15 10 30
   :header-rows: 1

   * - Treat
     - Quantity
     - Description
   * - Albatross
     - 2.99
     - On a stick!
   * - Crunchy Frog
     - 1.49
     - If we took the bones out, it wouldn't be
       crunchy, now would it?
   * - Gannet Ripple
     - 1.99
     - On a stick!


Related
==============

* https://w3resource.com/PostgreSQL/postgresql-triggers.php
* https://www.postgresql.org/docs/current/sql-createtrigger.html


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


