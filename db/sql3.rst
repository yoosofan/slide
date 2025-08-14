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

SQL 3

University of Kashan

----

:class: t2c

Update(I)
===========
.. code:: sql

    update P
    set weight = null
    where pn='P6';


.. code:: sql

    update s
    set status = status * 2
    where city = 'London';

.. code:: sql

    update employees
    set email = LOWER(
        firstname || "." || lastname || "@chinookcorp.com"
    );

.. code:: sql

    update employees
    set lastname = 'Smith'
    where employeeid = 3;

----

:class: t2c

Update(II)
===========
.. code:: sql

  update tableA
  set B = 'abcd',
    C = case
      when C = 'abc' then 'abcd'
      else C
    end
  where column = 1;

  -- https://stackoverflow.com/a/17081004/886607
  update s
  set
    status = case
      when city = 'london' then status * 2
      else status
    end

.. code:: sql
  :class: substep

  update s
  set
    status = case
    when city = 'London' then status * 2
    when city = 'Paris'  then status * 3
    else status
  end

.. code:: sql
  :class: substep

  update s
  set
    status = case
      when city = 'London' then status / 4
      when city = 'Paris'  then status / 3
      else status
    end

----

Condition on delete
======================
.. code:: sql
  :class: substep

    delete from sp
    where qty < (
        select avg(qty)
        from sp
      )
    ;

----

.. code:: sql

  update student S
  set tot_cred = (
    select sum(credits)
    from takes, course
    where takes.course_id = course.course_id
      and S.ID= takes.ID and
      takes.grade <> 'F' and
      takes.grade is not null
  );

.. code:: sql

  case
    when sum(credits) is not null then sum(credits)
    else 0
  end

.. :

  https://www.db-book.com/slides-dir/PDF-dir/ch3.pdf

----

:class: t2c

with(I)
=======
.. code:: sql

  select pn, pname
  from p, (
      select avg(weight) as averagev
      from p
    ) as temp
  where p.weight > temp.averagev
  ;

.. code:: sql

  select pn, pname
  from p
  where p.weight > (
      select avg(weight)
      from p
    )
  ;

.. code:: sql

  with temp (averagev) as(
    select avg(weight)
    from p
  )
  select pn, pname
  from p, temp
  where p.weight > averagev
  ;

----

:class: t2c

with(II)
=========
.. code:: sql

  select pn
  from (
      select avg(weight) as averagev
      from p
    ) as temp1, (
      select pn, sum(qty) as total
      from sp
      group by pn
    ) as temp2
  where temp2.total > temp1.averagev
  ;

.. code:: sql

  with temp1(averagev) as(
      select avg(weight)
      from p
    ),
    temp2(pn, total) as(
      select pn, sum(qty)
      from sp
      group by pn
    )
  select pn
  from temp1, temp2
  where temp2.total > temp1.averagev
  ;

----

:class: t2c

with(III)
=========
.. code:: sql

  with dept_total (dept_name, value) as(
      select dept_name, sum(salary)
      from instructor
      group by dept_name
    ),
    dept_total_avg(value) as(
      select avg(value)
      from dept_total
    )
  select dept_name
  from dept_total, dept_total_avg
  where dept_total.value > dept_total_avg.value

----

With Diagram
============
.. raw:: html

    <svg class="rrdiagram" version="1.1" xmlns:xlink="http://www.w3.org/1999/xlink" xmlns="http://www.w3.org/2000/svg" width="453" height="78" viewBox="0 0 453 78"><path class="connector" d="M0 50h15m50 0h30m88 0h20m-123 0q5 0 5 5v8q0 5 5 5h98q5 0 5-5v-8q0-5 5-5m5 0h30m-5 0q-5 0-5-5v-19q0-5 5-5h85m24 0h86q5 0 5 5v19q0 5-5 5m-5 0h35"></path><polygon points="0,57 5,50 0,43" ></polygon><rect class="literal" x="15" y="34" width="50" height="24" rx="7"></rect><text class="text" x="25" y="50">WITH</text><rect class="literal" x="95" y="34" width="88" height="24" rx="7"></rect><text class="text" x="105" y="50">RECURSIVE</text><rect class="literal" x="313" y="5" width="24" height="24" rx="7"></rect><text class="text" x="323" y="21">,</text><a xlink:href="#common-table-expression"><rect class="rule" x="233" y="34" width="185" height="24"></rect><text class="text" x="243" y="50">common_table_expression</text></a><polygon points="449,57 453,57 453,43 449,43" ></polygon></svg>

.. raw:: html

    <svg class="rrdiagram" version="1.1" xmlns:xlink="http://www.w3.org/1999/xlink" xmlns="http://www.w3.org/2000/svg" width="608" height="179" viewBox="0 0 608 179"><path class="connector" d="M0 50h15m81 0h30m25 0h30m-5 0q-5 0-5-5v-19q0-5 5-5h46m24 0h46q5 0 5 5v19q0 5-5 5m-5 0h30m25 0h20m-251 0q5 0 5 5v8q0 5 5 5h226q5 0 5-5v-8q0-5 5-5m5 0h10m36 0h10m25 0h30m58 0h27m-95 24q0 5 5 5h5m60 0h10q5 0 5-5m-85 29q0 5 5 5h5m56 0h14q5 0 5-5m-85 29q0 5 5 5h5m65 0h5q5 0 5-5m-90-82q5 0 5 5v106q0 5 5 5h5m60 0h10q5 0 5-5v-106q0-5 5-5m5 0h10m25 0h15"></path><polygon points="0,57 5,50 0,43" style="fill:black;stroke-width:0"></polygon><a xlink:href="../../../syntax_resources/grammar_diagrams#cte-name"><rect class="rule" x="15" y="34" width="81" height="24"></rect><text class="text" x="25" y="50">cte_name</text></a><rect class="literal" x="126" y="34" width="25" height="24" rx="7"></rect><text class="text" x="136" y="50">(</text><rect class="literal" x="222" y="5" width="24" height="24" rx="7"></rect><text class="text" x="232" y="21">,</text><a xlink:href="../../../syntax_resources/grammar_diagrams#column-name"><rect class="rule" x="181" y="34" width="106" height="24"></rect><text class="text" x="191" y="50">column_name</text></a><rect class="literal" x="317" y="34" width="25" height="24" rx="7"></rect><text class="text" x="327" y="50">)</text><rect class="literal" x="372" y="34" width="36" height="24" rx="7"></rect><text class="text" x="382" y="50">AS</text><rect class="literal" x="418" y="34" width="25" height="24" rx="7"></rect><text class="text" x="428" y="50">(</text><a xlink:href="../../../syntax_resources/grammar_diagrams#select"><rect class="rule" x="473" y="34" width="58" height="24"></rect><text class="text" x="483" y="50">select</text></a><a xlink:href="../../../syntax_resources/grammar_diagrams#values"><rect class="rule" x="473" y="63" width="60" height="24"></rect><text class="text" x="483" y="79">values</text></a><a xlink:href="../../../syntax_resources/grammar_diagrams#insert"><rect class="rule" x="473" y="92" width="56" height="24"></rect><text class="text" x="483" y="108">insert</text></a><a xlink:href="../../../syntax_resources/grammar_diagrams#update"><rect class="rule" x="473" y="121" width="65" height="24"></rect><text class="text" x="483" y="137">update</text></a><a xlink:href="../../../syntax_resources/grammar_diagrams#delete"><rect class="rule" x="473" y="150" width="60" height="24"></rect><text class="text" x="483" y="166">delete</text></a><rect class="literal" x="568" y="34" width="25" height="24" rx="7"></rect><text class="text" x="578" y="50">)</text><polygon points="604,57 608,57 608,43 604,43" style="fill:black;stroke-width:0"></polygon></svg>

.. :

    https://docs.yugabyte.com/preview/api/ysql/the-sql-language/with-clause/with-clause-syntax-semantics/

----

:class: t2c

Unknown
=========
* 3 = 2 => FALSE
* 3 = 3 => TRUE
* NULL = 3 => UNKNOWN
* 3 = NULL => UNKNOWN
* NULL = NULL => UNKNOWN
* NULL <> 1 => UNKNOWN
* NULL > 1 => UNKNOWN

.. code:: sql

  select * -- always empty
  from p
  where weight = null
  ;

  select *
  from p
  where weight is null
  ;

  select *
  from p
  where weight > 13 or city = 'Paris'
  ;



.. code:: sql

    expression IS TRUE
    expression IS NOT TRUE
    expression IS FALSE
    expression IS NOT FALSE
    expression IS UNKNOWN
    expression IS NOT UNKNOWN

.. :

  https://modern-sql.com/concept/three-valued-logic
  https://www.postgresqltutorial.com/postgresql-nullif/

----

Three-valued logic
=======================
* Boolean logic
* Kleene and Priest logics

(F: false; U: unknown; T: true)

.. container:: yoo-grid-auto-flow-column

  .. table::
    :class: smallerelementwithfullborder

    +-----+-----+
    |  A  | ~A  |
    +=====+=====+
    |  F  |  T  |
    +-----+-----+
    |  T  |  F  |
    +-----+-----+
    |  U  |  U  |
    +-----+-----+

  .. table::
    :class: smallerelementwithfullborder

    +-----------+-----------------+
    |           |          B      |
    | A and B   +-----+-----+-----+
    |           |  T  |  F  |  U  |
    +=====+=====+=====+=====+=====+
    |     |  T  |  T  |  F  |  U  |
    |     +-----+-----+-----+-----+
    |  A  |  F  |  F  |  F  |  F  |
    |     +-----+-----+-----+-----+
    |     |  U  |  U  |  F  |  U  |
    +-----+-----+-----+-----+-----+

  .. table::
    :class: smallerelementwithfullborder

    +-----------+-----------------+
    |           |          B      |
    |  A or B   +-----+-----+-----+
    |           |  T  |  F  |  U  |
    +=====+=====+=====+=====+=====+
    |     |  T  |  T  |  T  |  T  |
    |     +-----+-----+-----+-----+
    |  A  |  F  |  T  |  F  |  U  |
    |     +-----+-----+-----+-----+
    |     |  U  |  T  |  U  |  U  |
    +-----+-----+-----+-----+-----+

.. :

  https://www.w3schools.com/sql/sql_isnull.asp
  https://en.wikipedia.org/wiki/Three-valued_logic
  https://modern-sql.com/concept/three-valued-logic

----

.. code:: sql
    :number-lines:

    select *
    from List_of_tables
    where (conditions) is unknown;

.. code:: sql
    :class: substep
    :number-lines:

    select *
    from List_of_tables
    where (conditions) is not unknown;

.. code:: sql
    :class: substep
    :number-lines:

    select *
    from List_of_tables
    where not ( (conditions) is not unknown);

.. code:: sql
    :class: substep
    :number-lines:

    select *
    from List_of_tables
    where ( (conditions) is not unknown) is not unknown;

.. class:: substep

    Always True

----

"is not unknown" , "is unknown"
=================================
.. class:: substep

#. Always True or False
#. It cannot be "unknown"
#. The meaning of "null" and "unknown" is different
#. The usages of "null" and "unknown" is different


----

The final result of an uknown condition is False
================================================
.. class:: substep rtl-h1

    نام قطعاتی را بیابید که وزن بیشتر از ۱۷ دارند.

.. code:: sql
    :class: substep
    :number-lines:

    select pname
    from p
    where weight > 17;


----

:class: t2c

.. class:: rtl-h1

    نام قطعاتی را بیابید که وزن آنها بیشتر از ۱۸ است و عرضه‌کننده‌ای در شهر پاریس آنها را عرضه کرده است.

.. code:: sql
    :class: substep
    :number-lines:

    select pname
    from p join sp using(pn) join s using(sn)
    where weight > 17 and city = 'Paris';

.. code:: sql
    :class: substep
    :number-lines:

    select pname
    from p join sp using(pn) and s using(sn)
    where weight is not null and weight > 17 and city = 'Paris';

----

.. class:: rtl-h1

    نام قطعاتی را بیابید که وزن آنها بیشتر از ۱۸ است یا وزنی ندارند و عرضه‌کننده‌ای در شهر پاریس آنها را عرضه کرده است.

.. code:: sql
    :class: substep
    :number-lines:

    select pname
    from p join sp using(pn) and s using(sn)
    where (weight is not null or weight > 17) and city = 'Paris';

----

.. class:: rtl-h1

    نام قطعاتی را بیابید که وزن آنها بیشتر از ۱۸ است یا وزنی ندارند و عرضه‌کننده‌ای در شهر پاریس آنها را عرضه کرده است ولی اگر شهر عرضه کننده وارد نشده باشد وزن آن بیشتر از ۳۴ باشد.


.. code:: sql
    :class: substep
    :number-lines:

    select pname -- incorrect
    from p
    where weight > 17;

----

.. code:: sql

  select n, d
  from t
  where n / nullif(d, 0) > 1
  ; -- returns the first value,
  -- unless it's equal to the second
  -- in which case it returns NULL.
  -- It is equivalent to this CASE statement:
  -- CASE WHEN A <> B OR B IS NULL THEN A END
  -- The NULLIF() function returns NULL
  -- if two expressions are equal, otherwise
  -- it returns the first expression.

----

.. :

   https://www.postgresql.org/docs/current/functions-conditional.html
   https://stackoverflow.com/q/6220956/886607
   https://www.w3schools.com/sql/func_sqlserver_nullif.asp
   https://www.geeksforgeeks.org/postgresql-nullif-function/
   https://neon.tech/postgresql/postgresql-tutorial/postgresql-nullif

.. code:: sql

   SELECT(
     SUM (CASE WHEN gender = 1 THEN 1 ELSE 0 END) /
       SUM (CASE WHEN gender = 2 THEN 1 ELSE 0 END)
   ) * 100 AS "Male/Female ratio"
   FROM members;


   -- ERROR:  division by zero
   -- The reason is that the number of females is zero now.
   -- To prevent this division by zero error, you can use
   -- the NULLIF function as follows:

    SELECT (
        SUM (CASE WHEN gender = 1 THEN 1 ELSE 0 END) /
          NULLIF (
           SUM (CASE WHEN gender = 2 THEN 1 ELSE 0 END),
           0
        )
      ) * 100 AS "Male/Female ratio"
    FROM members;

----

.. :

    COALESCE(value [, ...])

    https://www.postgresql.org/docs/current/functions-conditional.html
    The COALESCE function returns the first of its arguments that is not null. Null is returned only if all arguments are null. It is often used to substitute a default value for null values when data is retrieved for display, for example:

    SELECT COALESCE(description, short_description, '(none)') ...

    This returns description if it is not null, otherwise short_description if it is not null, otherwise (none).

    The arguments must all be convertible to a common data type, which will be the type of the result (see Section 10.5 for details).

    Like a CASE expression, COALESCE only evaluates the arguments that are needed to determine the result; that is, arguments to the right of the first non-null argument are not evaluated. This SQL-standard function provides capabilities similar to NVL and IFNULL, which are used in some other database systems.

    NULLIF(value1, value2)

    The NULLIF function returns a null value if value1 equals value2; otherwise it returns value1. This can be used to perform the inverse operation of the COALESCE example given above:

    SELECT NULLIF(value, '(none)') ...

    In this example, if value is (none), null is returned, otherwise the value of value is returned.

    The two arguments must be of comparable types. To be specific, they are compared exactly as if you had written value1 = value2, so there must be a suitable = operator available.

    The result has the same type as the first argument — but there is a subtlety. What is actually returned is the first argument of the implied = operator, and in some cases that will have been promoted to match the second argument's type. For example, NULLIF(1, 2.2) yields numeric, because there is no integer = numeric operator, only numeric = numeric.


    https://stackoverflow.com/a/2214531/886607
    SELECT CASE WHEN field IS NULL THEN 'Empty' ELSE field END AS field_alias
    SELECT coalesce(field, 'Empty') AS field_alias

.. code:: sql

    SELECT product, (price - COALESCE(discount, 0)) AS net_price
    FROM items;

.. code:: sql

    SELECT product, (
    price - CASE WHEN discount IS NULL THEN 0 ELSE discount END
      ) AS net_price
    FROM items;

.. code:: sql

  SELECT CASE i WHEN NULL THEN 'Is Null'  -- This will never be returned
    WHEN    0 THEN 'Is Zero'  -- This will be returned when i = 0
    WHEN    1 THEN 'Is One'   -- This will be returned when i = 1
    END
  FROM t;

----

.. class:: rtl-h1

    نام همهٔ قطعات را همراه با جمع عرضه‌های آنها بیابید در صورتی که وزن قطعه بیشتر از ۲۰ باشد یا این که وزنی نداشته باشد برای این قطعه‌ها جمع عرضه در نظر گرفته شود وگرنه مانند قطعه‌های عرضه نشده، جمع عرضه‌های آنها صفر در نظر گرفته شود.

.. code:: sql
    :class: substep
    :number-lines:

    select pname
    from p join sp using(pn) join s using(sn)
    where weight > 17 and ;


----

.. class:: rtl-h1

    نام قطعاتی را بیابید که وزن آنها بیشتر از ۱۸ باشد و عرضه‌کننده‌ای با وضعیت بیشتر از ۲۰ آنها را عرضه کرده باشد.

.. code:: sql
    :class: substep
    :number-lines:

    select pname
    from p join sp using(pn) join s using(sn)
    where weight > 17 and ;

----

Only Conditions with Known Values
=================================
Pr : is a large combinations of conditions
------------------------------------------
.. code:: sql
    :class: substep
    :number-lines:

    ((pr) is not unknown) and pr ;

.. code:: sql
    :class: substep
    :number-lines:

    select *
    from List_of_tables
    where (conditions) is not unknown;

----

Check
=======
.. code:: sql

  CREATE TABLE t (
    a NUMERIC CHECK (a >= 0),
    b NUMERIC CHECK (b >= 0),
    CHECK ( a + b <= 10 )
  );

.. :

  https://modern-sql.com/concept/three-valued-logic

----

.. code:: sql
  :number-lines:

  create database sp2;

  create table s (
    sn      char(10) primary key,
    sname   char(30) not null,
    status  int default 10  check(status >= 10),
    city    char(20) default 'Shiraz'
  );

  create table p (
    pn     char(10) primary key,
    pname  char(30) not null,
    color  char(20),
    weight numeric(9, 2) check(weight > 2 and weight < 90000),
    city   char(20)
  );

  create table sp (
     sn    char(10) references s on update cascade on delete cascade,
     pn    char(10) references p on update cascade on delete cascade,
     qty   int default 1 check(qty > 0),
     primary key (sn, pn)
  );

.. :

    The follwing links has also schema and data of database

    https://github.com/vrajmohan/pgsql-sample-data/blob/master/date_spj.sql
    https://github.com/vrajmohan/pgsql-sample-data

----

Foreign Key Error
====================
.. code:: sql
  :number-lines:

  create table "Department"(
    "DN" integer default 0 primary key,
    "DeptName" varchar(30) default '',
    "MgrSSN" varchar(20) REFERENCES "Employee"("SSN")
  );
  create table "Employee"(
    "SSN" varchar(20) primary key,
    "name" varchar(40) not null,
    "salary" numeric(15,2) default 0,
    "Dn" integer default 0 REFERENCES "Department"("DN")
  );

  insert into "Department"("DN", "DeptName", "MgrSSN")
      values(1, 'computer', '');
  insert into "Department"("DN", "DeptName", "MgrSSN")
      values(2, 'Chemistry', '');


.. code:: sh

  -- SQLite
  Result: FOREIGN KEY constraint failed
  At line 14:
  insert into "Department"("DN", "DeptName", "MgrSSN")
      values(1, 'computer', '');

.. :

  pragma foreign_keys=off;

----

Foreign Key Error(PostgreSQL)
==================================
.. code:: sql

  create table "Department"(
    "DN" integer default 0 primary key,
    "DeptName" varchar(30) default '',
    "MgrSSN" varchar(20) REFERENCES "Employee"("SSN")
  );

.. code:: sh

  ERROR:  relation "Employee" does not exist

.. code:: sql

  create table "Employee"(
    "SSN" varchar(20) primary key,
    "name" varchar(40) not null,
    "salary" numeric(15,2) default 0,
    "Dn" integer default 0 REFERENCES "Department"("DN")
  );

.. code:: sh

  ERROR:  relation "Department" does not exist

----

.. code:: sql

  create table "Department"(
    "DN" integer default 0 primary key,
    "DeptName" varchar(30) default '',
    "MgrSSN" varchar(20)
  );

  create table "Employee"(
    "SSN" varchar(20) primary key,
    "name" varchar(40) not null,
    "salary" numeric(15,2) default 0,
    "Dn" integer default 0
  );

.. code:: sql

  insert into "Department"("DN", "DeptName", "MgrSSN")
    values(1, 'computer', '');
  insert into "Department"("DN", "DeptName", "MgrSSN")
    values(2, 'Chemistry', '');

  insert into "Employee"("SSN", "name", "salary", "Dn")
    values('e2', 'kamran', 1200, 1);

  insert into "Employee"("SSN", "name", "salary", "Dn")
    values('e10', 'ali', 1200, 2);

----

.. code:: sql

  update "Department" set "MgrSSN"='e2' where "DN"=1;
  update "Department" set "MgrSSN"='e10' where "DN"=2;

  alter table "Department" add constraint "departmentManager" foreign key("MgrSSN")
    references "Employee"("SSN") on update cascade on delete no action;

  update "Employee" set "Dn"=1 where "SSN"='e2';
  update "Employee" set "Dn"=2 where "SSN"='e10';

  alter table "Employee" add constraint "employeeDepartment" foreign key("Dn")
    references "Department"("DN") on update cascade on delete no action;
  -- set default
  -- set null

.. :

  -- ~ insert into "Employee"("SSN", "name", "salary", "Dn")
    -- ~ values('e21', 'arman', 1300, 5);
  -- ~ ERROR:  insert or update on table "Employee" violates foreign key constraint "employeeDepartment"
  -- ~ DETAIL:  Key (Dn)=(5) is not present in table "Department".

----

SQLite is incomplete
=======================
.. code:: sql

  create table tte1(
    myid integer default 0 primary key,
    salary numeric(14,2) check(salary >= 100),
    name1 varchar(20) not null,
    dept2 integer references "Department"("DN"),
    fee   numeric(14, 2) default 10, --check(salary - fee > 80)
    check(salary - fee > 80)
  );

  insert into tte1(myid, salary, name1, dept2, fee)
    values(31, 1200, 'هوشنگ', 1, 200);

.. code:: sh

  Result: FOREIGN KEY constraint failed
  At line 10:
  insert into tte1(myid, salary, name1, dept2, fee)
      values(31, 1200, 'هوشنگ', 1, 200);

----

Same Sample in PostgreSQL
===========================
.. code:: sql

  create table tte1(
    myid integer default 0 primary key,
    salary numeric(14,2) check(salary >= 100),
    name1 varchar(20) not null,
    dept2 integer references "Department"("DN"),
    fee   numeric(14, 2) default 10, --check(salary - fee > 80)
    check(salary - fee > 80)
  );

  insert into tte1(myid, salary, name1, dept2, fee)
    values(31, 1200, 'هوشنگ', 1, 200);

.. code:: sh

  INSERT 0 1

----

.. code:: sql

  create table "Department"(
    "DN" integer default 0 primary key,
    "DeptName" varchar(30) default '',
    "MgrSSN" varchar(20)
  );

  create table "Employee"(
    "SSN" varchar(20) primary key,
    "name" varchar(40) not null,
    "salary" numeric(15,2) default 0,
    "Dn" integer default 0
  );


.. code:: sql

  insert into "Department"("DN", "DeptName", "MgrSSN")
    values(1, 'computer', '');
  insert into "Department"("DN", "DeptName", "MgrSSN")
    values(2, 'Chemistry', '32');

  alter table "Department" add constraint "departmentManager" foreign key("MgrSSN")
    references "Employee"("SSN") on update cascade on delete no action;


.. code:: sh

  ERROR:  insert or update on table "Department" violates foreign key constraint "departmentManager"
  DETAIL:  Key (MgrSSN)=(32) is not present in table "Employee".

----

no action, restrict, set null, set default or cascade
=====================================================================
#. no action
#. restrict
#. set null
#. set default
#. cascade

.. :

  https://sqlite.org/foreignkeys.html
  https://www.sqlitetutorial.net/sqlite-foreign-key/
  #. **no action**: Configuring "no action" means just that: when a parent key is modified or deleted from the database, no special action is taken.
  #. **restrict**: The "restrict" action means that the application is prohibited from deleting (for on delete restrict) or modifying (for on update restrict) a parent key when there exists one or more child keys mapped to it. The difference between the effect of a restrict action and normal foreign key constraint enforcement is that the restrict action processing happens as soon as the field is updated - not at the end of the current statement as it would with an immediate constraint, or at the end of the current transaction as it would with a deferred constraint. Even if the foreign key constraint it is attached to is deferred, configuring a restrict action causes SQLite to return an error immediately if a parent key with dependent child keys is deleted or modified.
  #. **set null**: If the configured action is "set null", then when a parent key is deleted (for on delete set null) or modified (for on update set null), the child key columns of all rows in the child table that mapped to the parent key are set to contain SQL null values.
  #. **set default**: The "set default" actions are similar to "set null", except that each of the child key columns is set to contain the columns default value instead of null. Refer to the create table documentation for details on how default values are assigned to table columns.
  #. **cascade**: A "cascade" action propagates the delete or update operation on the parent key to each dependent child key. For an "on delete cascade" action, this means that each row in the child table that was associated with the deleted parent row is also deleted. For an "on update cascade" action, it means that the values stored in each dependent child key are modified to match the new parent key values.

----

Constraint(I)
==============
* Primary key
* not null (No field part of primary key can be null)
* foreign keys
* unique


----

pragma foreign_keys
====================
.. code:: sql

    pragma foreign_keys=off;

    pragma foreign_keys=on;

    pragma foreign_keys=off;
    insert into "spj"("sn", "pn", "jn", "qty") values('S7', 'P1', 'J1', 123);
    delete from "SPJ" where "sn" = 'S7';
    pragma foreign_keys=on;
    insert into "spj"("sn", "pn", "jn", "qty") values('S7', 'P1', 'J1', 123);
    Error:
      Help: foreign key constraint failed

.. :

    https://www.sqlitetutorial.net/sqlite-primary-key/
    https://www.sqlbook.com/sql/drop-table-if-exists/
    https://www.tutorialspoint.com/sql/sql-foreign-key.htm

----

SQLite uses the following terminology
==========================================
#. The parent table is the table that a foreign key constraint refers to.
#. The child table is the table that a foreign key constraint is applied to and the table that contains the references clause.
#. The parent key is the column or set of columns in the parent table that the foreign key constraint refers to.
#. The child key is the column or set of columns in the child table

.. :

    The parent table in the example in this section is the artist table. Some books and articles refer to this as the referenced table, which is arguably more correct, but tends to lead to confusion.

    The example in this section uses the track table as the child table. Other books and articles refer to this as the referencing table.

    This is normally, but not always, the primary key of the parent table. The parent key must be a named column or columns in the parent table, not the rowid.

    that are constrained by the foreign key constraint and which hold the references clause.

    https://sqlite.org/foreignkeys.html

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

:class: t2c

All
=====
.. class:: rtl-h1

نام قطعاتی را بیابید که وزن آن قطعه‌ها از وزن همهٔ قطعه‌های درون شهر پاریس بیشتر باشد

.. code:: sql

  select T.pname
  from p as T
  where not exists(
      select *
      from p
      where city = 'Paris' and
        p.weight >= T.weight
  );

.. code:: sql

  select pname
  from p
  where weight > all(
      select weight
      from p
      where city='Paris'
    )
  ;

----

:class: t2c

Some
====
.. class:: rtl-h1

  نام قطعاتی را بیابید که وزن آن قطعه‌ها از دست کم وزن یک قطعه درون شهر پاریس بیشتر باشد

.. code:: sql

  select T.pname
  from p as T
  where exists(
      select *
      from p
      where city = 'Paris' and
        T.weight > p.weight
    )
  ;


.. code:: sql

  select pname
  from p
  where weight > some (
      select weight
      from p
      where city = 'Paris'
    )
  ;

----

:class: t2c

IN
===
.. class:: rtl-h1

نام قطعاتی را بیابید که عرضه‌کننده‌ای همشهری آن قطعه‌ها باشد

.. code:: sql

  select pname
  from p
  where city in (
      select city
      from s
    )
  ;

.. class:: rtl-h2

کوشش کنید با exists این پرس‌وجو را حل کنید.

.. code:: sql

  select pname
  from p
  where exists (
      select *
      from s
      where p.city = s.city
    )
  ;

----

:class: t2c

.. class:: rtl-h1

  نام قطعاتی را بیابید که هیچ عرضه‌کننده‌ای در شهر آن قطعات نباشد

.. code:: sql
  :class: substep

  select pname
  from p
  where city not in (
      select city
      from s
    )
  ;

.. class:: substep rtl-h2

کوشش کنید با exists این پرس‌وجو را حل کنید.

.. code:: sql
  :class: substep

  select pname
  from p
  where not exists (
      select *
      from s
      where p.city = s.city
    )
  ;

----

.. class:: rtl-h1

نام قطعاتی را بیابید که هیچ عرضه کنندهٔ همشهری‌شان آنها را عرضه نکرده باشد.

.. code:: sql
  :class: substep

  select pname
  from p
  where city, pn not in (
      select city, pn
      from s natural join sp
    )
  ;

.. class:: substep rtl-h2

کوشش کنید با exists این پرس‌وجو را حل کنید.

.. code:: sql
  :class: substep

  select pname
  from p
  where not exists(
      select *
      from s natural join sp
      where s.city = p.city
        and sp.pn = p.pn
    )
  ;

----

:class: t2c

.. class:: rtl-h1

    نام قطعاتی را بیابید که هیچ عرضه کنندهٔ همشهری‌شان هیچ قطعه‌ای را عرضه نکرده باشد.

    نام قطعاتی را بیابید که عرضه کننده‌ای در شهرشان نباشد که قطعه‌ای عرضه کرده باشد.

.. code:: sql
  :class: substep

  select pname
  from p
  where city not in (
      select city
      from s natural join sp
    )
  ;

.. class:: substep rtl-h2

کوشش کنید با exists این پرس‌وجو را حل کنید.

.. code:: sql
  :class: substep

  select pname
  from p
  where not exist(
      select *
      from s natural join sp
      where s.city = p.city
    )
  ;


----

:class: t2c

.. class:: rtl-h1

نام قطعاتی را بیابید که هیچ عرضه کنندهٔ همشهری‌شان هیچ قطعه‌ای را عرضه نکرده باشد.


.. code:: sql
  :class: substep

  select pname  from p
  where city not in (
      select city
      from s
      where sn not in
      (select sn from sp)
    );

.. code:: sql
  :class: substep

  select pname from p
  where city in (
      select city
      from s
      where sn not in
      (select sn from sp)
    );

.. code:: sql
  :class: substep

  select pname from p
  where city not in (
      select city from s
      where sn in
      (select sn from sp)
    );

----

:class: t2c

.. class:: rtl-h1

نام قطعاتی را بیابید که وزن آنها از قطعه‌ای در شهر کاشان بزرگ‌تر باشد.

.. code:: sql
  :class: substep

  select pname
  from p
  where weight > some (
      select weight
      from p
      where city = 'Kashan'
    )
  ;

.. code:: sql
  :class: substep

  select pname
  from p as T
  where exist(
      select *
      from p
      where p.city = 'Kashan'
        and T.weight > p.weight
    )
  ;

----

:class: t2c

.. class:: rtl-h1

شمارهٔ قطعاتی را بیابید که در شهر آنها عرضه کننده‌ای با وضعیت بزرگ‌تر از ۶ وجود داشته باشد.

.. code:: sql
  :class: substep

  select pn
  from p
  where city in (
      select city
      from s
      where status > 6
    );

.. code:: sql
  :class: substep

  select pn
  from p
  where city = some(
      select city
      from s
      where status > 6
    );

.. code:: sql
  :class: substep

  select pn
  from p
  where city = ( -- Error
      select city
      from s
      where status > 6
    );

.. code:: sql
  :class: substep

  select city
  from s
  where status > 6;
  -- result has more
  -- than a row

.. code:: sql
  :class: substep

  select pn
  from p join s using(city)
  where status > 6;

----

:class: t2c

order by
===========
.. class:: rtl-h1

نام و وضعیت عرضه کنندگان را به صورت صعودی بر پایهٔ وضعیت آنها بیابید.

.. code:: sql

  select sname, status
  from s
  order by status ;

.. code:: sql

  select sname, status
  from s
  order by status asc;

..  csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder

  sname,  status
  Jones, 10
  Smith, 20
  Clark, 20
  Blake, 30
  Adams, 30
  Ali,   40

----

order by ..... desc
========================
.. class:: rtl-h2

نام و وضعیت عرضه کنندگان را به صورت نزولی بر پایهٔ وضعیت آنها بیابید.

.. code:: sql

  select sname, status
  from s
  order by status desc;

..  csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder

  sname,  status
  sname,  status
  Ali,  40
  Blake,  30
  Adams,  30
  Smith,  20
  Clark,  20
  Jones,  10

----

.. code:: sql

    create table mytemp(
      name varchar(20) not null,
      ssn  bigint primary key
      );

    insert into mytemp(ssn) values(20);
    --- Help: not null constraint failed: mytemp.name

.. code:: sql

    alter table mytemp add last_name varchar(20);

    insert into mytemp(ssn, name) values(20, "ali");

.. code:: sql

    select *
    from mytemp;

----

:class: t2c

.. class:: rtl-h1

شمارهٔ عرضه‌کنندگانی را بیابید که جمع وزن قطعه‌هایی که عرضه می‌کنند بیشتر از ۱۱ هزار باشد

.. code:: sql

    select sn
    from spj join p using(pn)
    group by sn
    having sum(weight * qty) > 11000;

.. code:: sql

    select sn
    from s
    where 11000 < ( select sum(weight * qty)
                 from p natural join spj
                 where spj.sn = s.sn
               );

.. ::

  -- https://www.sqlitetutorial.net/sqlite-union/
  -- https://www.sqlitetutorial.net

  -- https://www.sqlitetutorial.net/sqlite-subquery/

  .. code:: sql

    select trackid,
           name,
           albumid
    from tracks
    where albumid = (
       select albumid
       from albums
       where title = 'Let There Be Rock'
    );

    alter table p drop factory_name;

-----

:class: t2c

.. class:: rtl-h1

شماره و نام عرضه کنندگان را بیابید. اگر وضعیت عرضه‌کننده بزرگتر از ۲۰ بود کنار مشخصات عرضه کننده کلمهٔ big و در غیر این صورت کلمهٔ small بگذارید.

.. code:: sql
    :class: substep

    select sn, sname, case
        when status > 20 then 'big'
        else 'small'
        end size_of_supplier
    from s;

-----

:class: t2c

.. code:: sql

    select pn
    from p
    where city = (
        select city
        from s
        where status>6
    );

.. code:: sql

    select pn
    from p
    where city in (
        select city
        from s
        where status>6
    );

----


:class: t2c

.. code:: sql

  select pn,
     (select sum(status)
      from s
      where s.city=p.city
     ),
     city
  from p
  order by weight desc;

.. code:: sql

    select pn,
       (select sum(status)
        from s
        where s.city=p.city
       ) as sum_status,
       city
    from p
    order by weight desc ;

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


----

:class: t2c

Unique condition
=================
.. code:: sql

    select pn
    from p
    where unique(
      select *
      from sp
      where sp.pn = p.pn
    )
    ;
    -- not implemented in PostgreSQL

.. code:: sql

    select pn
    from p
    where not unique(
      select *
      from sp
      where sp.pn = p.pn
    )
    ;
    -- not implemented in PostgreSQL

----


:class: t2c

.. class:: rtl-h1

  نام شهرهایی را به دست آورید که عرضه کننده‌ای با وضعیت بیشتر از ۱۰۰۰ داشته باشند

.. code:: sql
    :class: substep

    select distinct city
    from   s
    where exists
         ( select * from s as T
           where T.city=s.city and T.status>1000
         )


..  code:: sql
    :class: substep

    select distinct city
    from   s
    where s.status>1000

----


:class: t2c

.. class:: rtl-h1

  نام شهرهایی را به دست آورید که همهٔ عرضه کنندگان آن شهرها وضعیت بیشتر از ۱۰۰۰ داشته باشند

.. code:: sql
    :class: substep

    select distinct city
    from   s
    where not exists
         ( select * from s as T
           where T.city=s.city and T.status<1000
         );

.. code:: sql
    :class: substep

    select city
    from   s
    except
    select city
    from   s
    where s.status<=1000

----

ENUM TYPE
=============
.. code:: sql

    create type Type_of_Menu as enum ('soft_menu', 'vertical_menu', 'horizontal_menu',
        'reports', 'report_with_submenu', 'report_in_submenu'
    );

    create table menu_access(
      menu_type Type_of_Menu,
      name char(256),
      visible boolean,
      primary key (menu_type, name)
    )

----

Check constraint
===================
.. code:: sql

  create type valid_colors as enum ('red', 'green', 'blue');

  create table t (
      color VALID_COLORS
  );

The following does not work

.. code:: sql

  select from t where color like 'bl%';

.. code:: sql

  create table t (
      colors text check (colors in ('red', 'green', 'blue'))
  );

.. :

    All native string or numeric operators work.

    https://stackoverflow.com/a/10984951

----

lateral
=============
.. code:: sql

    select pn, sn, p.city, t.city
    from p, LATERAL (select sn, s.city from s where s.city = p.city) as t;

.. code:: sql

    select pn, sn, p.city, t.city -- Error
    from p, (select sn, s.city from s where s.city = p.city) as t;

.. code:: sh

    Error invalid reference to FROM-clause entry for table "p"
    LINE 2: ... from p, (select sn, s.city from s where s.city = p.city) as...
                                                                 ^
    HINT: There is an entry for table "p", but it cannot be referenced
    from this part of the query.

.. code:: sql

    select pn, sn, p.city, s.city
    from p, s
    where s.city = p.city;

.. code:: sql

    select pn, sn, p.city, s.city
    from p natural join s;

----

.. code:: sql

  with psk as (select city from p natural join s)
    select * from psk;

  with psk as (select city, weight, pn, sn from p natural join s)
    select * from psk
    where weight < (select avg(weight) from p);

  with psk as (select city, weight, pn, sn from p natural join s)
    , jsk as (select city, sn, jn, status from s NATURAL join j)
    select psk.city, psk.weight, psk.sn, psk.pn, jsk.jn from psk, jsk
    where weight < (select avg(weight) from p) and
      jsk.city = psk.city;

----

.. code:: sql

  -- Error
  select psk.city, psk.weight, psk.sn, psk.pn, jsk.jn
  from (select city, weight, pn, sn from p natural join s) as psk
    , (select city, sn, jn, status from s NATURAL join j) as jsk
  where weight < (select avg(weight) from psk) and
    jsk.city = psk.city;

----

Vacuum
===========
.. code:: sql

    vacuum;

    vacuum full;

auto_vaccum
---------------
.. code:: sql

    pragma auto_vacuum = full;
    pragma auto_vacuum = incremental;
    pragma auto_vacuum = none;

vacuum with an into clause
-------------------------------
.. code::sql

    vacuum schema-name into filename;

    vacuum main into '/home/ahmad/course/db/sqlite/spj_backup.db';

.. :

  https://www.sqlitetutorial.net/sqlite-vacuum/

----

View
======
.. code:: sql

  create view kashan_p as(
    select *
    from p
    where city = 'Kashan'
  );

.. image:: img/create_view_postgresql.png
  :width: 740px

----

:class: t2c

Sample View
============
.. code:: sql

  create table student
    (ID     varchar(5),
     name     varchar(20) not null,
     dept_name    varchar(20),
     tot_cred   numeric(3,0) check (tot_cred >= 0),
     primary key (ID),
     foreign key (dept_name)
      references department (dept_name)
      on delete set null
    );

.. code:: sql

  update student S
  set tot_cred = (
    select sum(credits)
    from takes, course
    where takes.course_id = course.course_id
      and S.ID= takes.ID and
      takes.grade <> 'F' and
      takes.grade is not null
  );

.. code:: sql

  create table student
    (ID     varchar(5),
     name     varchar(20) not null,
     dept_name    varchar(20),
     primary key (ID),
     foreign key (dept_name)
      references department (dept_name)
      on delete set null
    );

.. code:: sql

  create view student_total as (
    select ID, name, dept_name, (
        select sum(credits)
        from takes, course
        where takes.course_id = course.course_id
          and student.ID= takes.ID and
          takes.grade <> 'F' and
          takes.grade is not null
    ) as total_cred
    from student
  );

----

.. code:: sql

  ALTER VIEW kashan_p RENAME TO kashan_parts;
  DROP VIEW [ IF EXISTS ] kashan_parts;

.. code:: sql

  drop view if exists m2;
  drop view if exists m1;

  create view m1 as
    select sn, city
    from s
    where status > 8
    ;

  create view m2 as
    select sn, pn
    from m1 natural join p
    ;

----

view
=======
* select is fine
* insert, update, delete is problematic
* unless it depends only on one table almost
* Speed of execution

.. code:: sql

    CREATE [ OR REPLACE ] [ TEMP | TEMPORARY ] [ RECURSIVE ] VIEW name [ ( column_name [, ...] ) ]
        [ WITH ( view_option_name [= view_option_value] [, ... ] ) ]
        AS query
        [ WITH [ CASCADED | LOCAL ] CHECK OPTION ]

.. code:: sql

    CREATE VIEW employee_department_info AS
    SELECT e.employee_id, e.first_name, e.last_name, d.department_name
    FROM employees e
    JOIN departments d ON e.department_id = d.department_id;

.. :

    https://www.geeksforgeeks.org/sql-create-view-statement/

----

MATERIALIZED VIEW
=====================
.. code:: sql

  CREATE MATERIALIZED VIEW table_name
      [ (column_name [, ...] ) ]
      [ WITH ( storage_parameter [= value] [, ... ] ) ]
      [ TABLESPACE tablespace_name ]
      AS query
      [ WITH [ NO ] DATA ]

----

.. code:: sql

  ALTER MATERIALIZED VIEW [ IF EXISTS ] name
      action [, ... ]
  ALTER MATERIALIZED VIEW [ IF EXISTS ] name
      RENAME [ COLUMN ] column_name TO new_column_name
  ALTER MATERIALIZED VIEW [ IF EXISTS ] name
      RENAME TO new_name
  ALTER MATERIALIZED VIEW [ IF EXISTS ] name
      SET SCHEMA new_schema

  where action is one of:

      ALTER [ COLUMN ] column_name SET STATISTICS integer
      ALTER [ COLUMN ] column_name SET ( attribute_option = value [, ... ] )
      ALTER [ COLUMN ] column_name RESET ( attribute_option [, ... ] )
      ALTER [ COLUMN ] column_name SET STORAGE { PLAIN | EXTERNAL | EXTENDED | MAIN }
      CLUSTER ON index_name
      SET WITHOUT CLUSTER
      SET ( storage_parameter = value [, ... ] )
      RESET ( storage_parameter [, ... ] )
      OWNER TO new_owner
      SET TABLESPACE new_tablespace

----

.. code:: sql

    create materialized view "pscity" ("sn", "pn", "city") AS
        select "sn", "pn", "p"."city"
        from "s" join "p" on "s"."city" = "p"."city";

    drop materialized view "pscity";


.. code:: sql

  REFRESH MATERIALIZED VIEW name
    [ WITH [ NO ] DATA ]

  REFRESH MATERIALIZED VIEW order_summary;

  REFRESH MATERIALIZED VIEW annual_statistics_basis WITH NO DATA;

.. code:: sql

  create materialized view student_total as (
    select ID, name, dept_name, (
        select sum(credits)
        from takes, course
        where takes.course_id = course.course_id
          and student.ID= takes.ID and
          takes.grade <> 'F' and
          takes.grade is not null
    ) as total_cred
    from student
  );

.. code:: sql

  REFRESH MATERIALIZED VIEW student_total;

----

:class: t2c

Recursive query
=====================
.. code:: sql

  create table course
    (course_id    varchar(8),
     title      varchar(50),
     dept_name    varchar(20),
     credits    numeric(2,0)
       check (credits > 0),
     primary key (course_id),
     foreign key (dept_name)
       references department
       (dept_name)
       on delete set null
    );

.. code:: sql

  create table prereq
    (course_id    varchar(8),
     prereq_id    varchar(8),
     primary key (course_id, prereq_id),
     foreign key (course_id) references course (course_id)
      on delete cascade,
     foreign key (prereq_id) references course (course_id)
    );

.

.. code:: sql

    with recursive rec_prereq(course_id, prereq_id) as (
          select course_id, prereq_id
          from prereq
        union
          select rec_prereq.course_id, prereq.prereq_id,
          from rec_rereq, prereq
          where rec_prereq.prereq_id = prereq.course_id
        )
      select ∗
      from rec_prereq;

----

:class: t2c

General Recursive Form
=======================
.. code:: sql

    with recursive r(c1, c2, ...) as (
        -- Non-recursive term.
        (
          select ...
        )

        union [all]

        -- Recursive term. Notice the
        -- so-called recursive
        -- self-reference to r.
        (
          select ... from r ...
        )
      )
    select ... from r ...;

.. code:: sql

    with recursive r(n) as (
    -- Non-recursive term.
        (
          values(1)
        )
        union all
        -- Recursive term.
        (
          select n + 1
          from r
          where n < 5
        )
      )
    select n from r order by n;

    -- n 1 2 3 4 5

.. :

  https://docs.yugabyte.com/preview/api/ysql/the-sql-language/with-clause/recursive-cte/

  It shows that you can use the RECURSIVE keyword only immediately after the keyword WITH and that, therefore only the first CTE in a WITH clause can be a recursive CTE. These restrictions are illustrated in the immediately following sections Maximum one recursive CTE and The recursive CTE must be first in the clause.
  Maximum one recursive CTE

  The attempt to define more than one recursive CTE within a particular WITH clause causes a generic 42601 syntax error. You can work around this restriction by pushing it down by one level of nesting, thus:




  CTE  (common table expression)
  The recursive CTE

  https://docs.yugabyte.com/preview/api/ysql/the-sql-language/

  The WITH clause

  The WITH clause (sometimes known as the common table expression) can be used as part of a SELECT statement, an INSERT statement, an UPDATE statement, or a DELETE statement. For this reason, the functionality is described in a dedicated section

----

Maximum one recursive CTE (Common Table Expression)
===================================================
.. code:: sql

    with a1(n) as (select 42),
      a2(n) as (
        with recursive r(n) as (
            values(1)
            union all
            select n + 1
            from r
            where n < 5
        )
        select n from r
      ), a3(n) as (select 99)(
        select n from a1
        union all
        select n from a2
        union all
        select n from a3
      )
      order by n desc;

    --- n,  99  42  5  4  3  2  1

.. :

  https://docs.yugabyte.com/preview/api/ysql/the-sql-language/with-clause/recursive-cte/
  https://docs.yugabyte.com/preview/api/ysql/the-sql-language/with-clause/
  https://docs.yugabyte.com/preview/api/ysql/the-sql-language/
  https://www.mssqltips.com/sqlservertip/1520/recursive-queries-using-common-table-expressions-cte-in-sql-server/
  https://www.kodyaz.com/t-sql/sql-server-recursive-query-with-recursive-cte.aspx
  https://www.dwhpro.com/teradata-recursive-queries/

  sql "with recursive" query s p sp

----

END

.. :

    ----

    .. code:: sql

        insert into SPJ(sn, pn, jn, qty) values('S1', 'P1','J1', 300);
        insert into SPJ(sn, pn, jn, qty) values('S1', 'P2', 'J1', 200);
        insert into SPJ(sn, pn, jn, qty) values('S1', 'P3', 'J1', 400);
        insert into SPJ(sn, pn, jn, qty) values('S1', 'P4', 'J2', 200);
        insert into SPJ(sn, pn, jn, qty) values('S1', 'P5', 'J2', 100);
        insert into SPJ(sn, pn, jn, qty) values('S1', 'P6', 'J2', 100);
        insert into SPJ(sn, pn, jn, qty) values('S2', 'P1', 'J3', 300);
        insert into SPJ(sn, pn, jn, qty) values('S2', 'P2', 'J3', 400);
        insert into SPJ(sn, pn, jn, qty) values('S3', 'P2', 'J3', 200);
        insert into SPJ(sn, pn, jn, qty) values('S4', 'P2', 'J3', 200);
        insert into SPJ(sn, pn, jn, qty) values('S4', 'P4', 'J3', 300);
        insert into SPJ(sn, pn, jn, qty) values('S4', 'P5', 'J3', 400);

        delete from "P" where "pn" = 'P6';
        Help: foreign key constraint failed

        update "SPJ"
        set "jn" = 'J8'
        where "pn" = 'P6';
        Help: foreign key constraint failed


    ----

    .. code:: sql

        create table SPJ (
          sn    char(10),
          pn    char(10),
          jn    char(10),
          qty   int default 0,
          primary key (sn, pn ,jn)
          foreign key("sn") references "S"("sn") on delete cascade,
          foreign key("pn") references "P"("pn") On delete cascade,
          foreign key("jn") references "J"("jn") on Delete cascade
        );

        insert into SPJ(sn, pn, jn, qty) values('S1', 'P1','J1', 300);
        insert into SPJ(sn, pn, jn, qty) values('S1', 'P2', 'J1', 200);
        insert into SPJ(sn, pn, jn, qty) values('S1', 'P3', 'J1', 400);
        insert into SPJ(sn, pn, jn, qty) values('S1', 'P4', 'J2', 200);
        insert into SPJ(sn, pn, jn, qty) values('S1', 'P5', 'J2', 100);
        insert into SPJ(sn, pn, jn, qty) values('S1', 'P6', 'J2', 100);
        insert into SPJ(sn, pn, jn, qty) values('S2', 'P1', 'J3', 300);
        insert into SPJ(sn, pn, jn, qty) values('S2', 'P2', 'J3', 400);
        insert into SPJ(sn, pn, jn, qty) values('S3', 'P2', 'J3', 200);
        insert into SPJ(sn, pn, jn, qty) values('S4', 'P2', 'J3', 200);
        insert into SPJ(sn, pn, jn, qty) values('S4', 'P4', 'J3', 300);
        insert into SPJ(sn, pn, jn, qty) values('S4', 'P5', 'J3', 400);

    ----

    .. code:: sql

        create table SPJ (
          sn    char(10),
          pn    char(10),
          jn    char(10),
          qty   int default 0,
          primary key (sn, pn ,jn)
          foreign key("sn") references "S"("sn") on delete cascade on update cascade,
          foreign key("pn") references "P"("pn") On delete cascade on update cascade,
          foreign key("jn") references "J"("jn") on delete cascade on update cascade,
        );


        delete from "P" where "pn" = 'P6';

        drop table spj;

    ----

    .. code:: sql

        create table SPJ (
          sn    char(10),
          pn    char(10),
          jn    char(10),
          qty   int default 0,
          primary key (sn, pn ,jn)
          foreign key("sn") references "S"("sn") on delete cascade on update cascade,
          foreign key("pn") references "P"("pn") On delete cascade on update cascade,
          foreign key("jn") references "J"("jn") on Delete cascade on update cascade
        );


        insert into SPJ(sn, pn, jn, qty) values('S1', 'P1','J1', 300);
        insert into SPJ(sn, pn, jn, qty) values('S1', 'P2', 'J1', 200);
        insert into SPJ(sn, pn, jn, qty) values('S1', 'P3', 'J1', 400);
        insert into SPJ(sn, pn, jn, qty) values('S1', 'P4', 'J2', 200);
        insert into SPJ(sn, pn, jn, qty) values('S1', 'P5', 'J2', 100);
        insert into SPJ(sn, pn, jn, qty) values('S1', 'P6', 'J2', 100);
        insert into SPJ(sn, pn, jn, qty) values('S2', 'P1', 'J3', 300);
        insert into SPJ(sn, pn, jn, qty) values('S2', 'P2', 'J3', 400);
        insert into SPJ(sn, pn, jn, qty) values('S3', 'P2', 'J3', 200);
        insert into SPJ(sn, pn, jn, qty) values('S4', 'P2', 'J3', 200);
        insert into SPJ(sn, pn, jn, qty) values('S4', 'P4', 'J3', 300);
        insert into SPJ(sn, pn, jn, qty) values('S4', 'P5', 'J3', 400);

    ----

    .. code:: sql

        update P
        set "pn" = 'P8'
        where "pn" = 'P6';

        select distinct pn from p;

        select distinct pn from p;

        select distinct pn from spj;

    ----

    .. code:: sql

        update table P
        set "pn" = 'P6'
        where "pn" = 'P8';

        drop table if exists spj;

        create table SPJ (
          sn    char(10),
          pn    char(10),
          jn    char(10),
          qty   int default 0,
          primary key (sn, pn ,jn)
          foreign key("sn") references "S"("sn") on delete set null on update cascade,
          foreign key("pn") references "P"("pn") On delete set null on update cascade,
          foreign key("jn") references "J"("jn") on Delete set null on update cascade
        );

    ----

    .. code:: sql

        insert into SPJ(sn, pn, jn, qty) values('S1', 'P1','J1', 300);
        insert into SPJ(sn, pn, jn, qty) values('S1', 'P2', 'J1', 200);
        insert into SPJ(sn, pn, jn, qty) values('S1', 'P3', 'J1', 400);
        insert into SPJ(sn, pn, jn, qty) values('S1', 'P4', 'J2', 200);
        insert into SPJ(sn, pn, jn, qty) values('S1', 'P5', 'J2', 100);
        insert into SPJ(sn, pn, jn, qty) values('S1', 'P6', 'J2', 100);
        insert into SPJ(sn, pn, jn, qty) values('S2', 'P1', 'J3', 300);
        insert into SPJ(sn, pn, jn, qty) values('S2', 'P2', 'J3', 400);
        insert into SPJ(sn, pn, jn, qty) values('S3', 'P2', 'J3', 200);
        insert into SPJ(sn, pn, jn, qty) values('S4', 'P2', 'J3', 200);
        insert into SPJ(sn, pn, jn, qty) values('S4', 'P4', 'J3', 300);
        insert into SPJ(sn, pn, jn, qty) values('S4', 'P5', 'J3', 400);

    ----

    .. code:: sql

        create table SPJ (
          sn    char(10) references S,
          pn    char(10) references P,
          jn    char(10) references J,
          qty   int default 0,
          primary key (sn, pn ,jn)
        );

        drop table spj;

        create table SPJ (
          sn    char(10),
          pn    char(10),
          jn    char(10),
          qty   int default 0,
          primary key (sn, pn ,jn)
          foreign key("sn") references "S"("sn"),
          foreign key("pn") references "P"("pn"),
          foreign key("jn") references "J"("jn")
        );

    DBMSs
    -----
    Search keywords:
    Sample databases for PostgreSQL

    https://github.com/morenoh149/postgresDBSamples
    https://wiki.postgresql.org/wiki/Sample_Databases
    https://opentextbc.ca/dbdesign01/back-matter/appendix-d-sql-lab-with-solution/


    SQL
    ^^^
    MySQL Sample Databases
    https://www3.ntu.edu.sg/home/ehchua/programming/sql/SampleDatabases.html


    .. code:: sql

      CREATE VIEW film_list
      AS
      SELECT
        film.film_id AS FID,
        film.title AS title,
        film.description AS description,
        category.name AS category,
        film.rental_rate AS price,
        film.length AS length,
        film.rating AS rating,
        GROUP_CONCAT(CONCAT(actor.first_name, _utf8' ', actor.last_name) SEPARATOR ', ') AS actors
      FROM category
        LEFT JOIN film_category ON category.category_id = film_category.category_id
        LEFT JOIN film ON film_category.film_id = film.film_id
        JOIN film_actor ON film.film_id = film_actor.film_id
        JOIN actor ON film_actor.actor_id = actor.actor_id
      GROUP BY film.film_id;


      -- Change the MySQL statement delimiter to // as it crashes with procedure's delimiter ';'
      DELIMITER //

      CREATE PROCEDURE rewards_report (
         IN min_monthly_purchases TINYINT UNSIGNED,              -- min number of purchases
         IN min_dollar_amount_purchased DECIMAL(10,2) UNSIGNED,  -- min dollar amount purchased
         OUT count_rewardees INT                                 -- number of customers to be rewarded
      )
      LANGUAGE SQL
      NOT DETERMINISTIC
      READS SQL DATA
      SQL SECURITY DEFINER
      COMMENT 'Provides a customizable report on best customers'

      proc: BEGIN
         DECLARE last_month_start DATE;
         DECLARE last_month_end DATE;

         /* Some sanity checks... */
         IF min_monthly_purchases = 0 THEN
            SELECT 'Minimum monthly purchases parameter must be > 0';
            LEAVE proc;
         END IF;
         IF min_dollar_amount_purchased = 0.00 THEN
            SELECT 'Minimum monthly dollar amount purchased parameter must be > $0.00';
            LEAVE proc;
         END IF;

         /* Determine start and end time periods */
         SET last_month_start = DATE_SUB(CURRENT_DATE(), INTERVAL 1 MONTH);
         SET last_month_start = STR_TO_DATE(
                                   CONCAT(YEAR(last_month_start), '-', MONTH(last_month_start), '-01'),
                                   '%Y-%m-%d');
         SET last_month_end = LAST_DAY(last_month_start);

         /* Create a temporary storage area for Customer IDs */
         CREATE TEMPORARY TABLE tmpCustomer (customer_id SMALLINT UNSIGNED NOT NULL PRIMARY KEY);

         /* Find all customers meeting the monthly purchase requirements */
         INSERT INTO tmpCustomer (customer_id)
           SELECT p.customer_id
           FROM payment AS p
           WHERE DATE(p.payment_date) BETWEEN last_month_start AND last_month_end
           GROUP BY customer_id
           HAVING
             SUM(p.amount) > min_dollar_amount_purchased
             AND COUNT(customer_id) > min_monthly_purchases;

         /* Populate OUT parameter with count of found customers */
         SELECT COUNT(*) FROM tmpCustomer INTO count_rewardees;

         /* Output ALL customer information of matching rewardees.
            Customize output as needed. */
         SELECT c.*
           FROM tmpCustomer AS t
           INNER JOIN customer AS c ON t.customer_id = c.customer_id;

         /* Clean up */
         DROP TABLE tmpCustomer;
      END //

      -- Change the MySQL delimiter back to ';'
      DELIMITER ;




      DELIMITER $$
      CREATE FUNCTION inventory_in_stock(p_inventory_id INT) RETURNS BOOLEAN
      READS SQL DATA
      BEGIN
         DECLARE v_rentals INT;
         DECLARE v_out     INT;

         # AN ITEM IS IN-STOCK IF THERE ARE EITHER NO ROWS IN THE rental TABLE
         # FOR THE ITEM OR ALL ROWS HAVE return_date POPULATED
         SELECT COUNT(*) INTO v_rentals
         FROM rental
         WHERE inventory_id = p_inventory_id;

         IF v_rentals = 0 THEN
            RETURN TRUE;
         END IF;

         SELECT COUNT(rental_id) INTO v_out
         FROM inventory LEFT JOIN rental USING(inventory_id)
         WHERE inventory.inventory_id = p_inventory_id AND rental.return_date IS NULL;

         IF v_out > 0 THEN
            RETURN FALSE;
         ELSE
            RETURN TRUE;
         END IF;
      END $$
      DELIMITER ;


    other books
    -----------


    https://opentextbc.ca/dbdesign01/front-matter/about-the-book/
    Database Design – 2nd Edition

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
