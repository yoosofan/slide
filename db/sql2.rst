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

SQL 2

University of Kashan

----

:class: t2c

Aggregation Functions
=======================
.. container::

    .. class:: rtl-h2

      جمع همهٔ عرضه‌ها(qty) را بیابید.


    .. code:: sql

      select sum(qty) as sqt
      from   sp
      ;

    ..  csv-table::
      :header-rows: 1
      :class: smallerelementwithfullborder

      sqt
      1600

..  csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder

  sn,  pn,  qty
  S1,  P1,  300
  S1,  P5,  100
  S2,  P1,  300
  S2,  P2,  400
  S4,  P2,  200
  S4,  P4,  300

----

:class: t2c

.. class:: rtl-h1

    جمع عرضه‌های عرضه کنندهٔ s2 را بیابید.

.. container::

    .. code:: sql

      select sum(qty) as sqt
      from   sp
      where sp.sn = 'S2'
      ;

    ..  csv-table::
      :header-rows: 1
      :class: smallerelementwithfullborder

      sqt
      700

..  csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder

  sn,  pn,  qty
  S1,  P1,  300
  S1,  P5,  100
  S2,  P1,  300
  S2,  P2,  400
  S4,  P2,  200
  S4,  P4,  300

.. :


    .. class:: rtl-h2

    جمع وزن قطعات را بیابید.

    .. code:: sql

      select sum(weight) as asw
      from p
      ;

    ..  csv-table::
      :header-rows: 1
      :class: smallerelementwithfullborder

      asw
      91


----

:class: t2c

.. class:: rtl-h1

  جمع وزن قطعات متفاوتی را بیابید که عرضه‌کننده‌ای در شهر پاریس آنها را عرضه کرده باشد(۱).

.. code:: sql
  :class: substep
  :number-lines:

  select sum(weight) as swg
  from p
  where exists (
      select *
      from sp natural join s
      where p.pn = sp.pn and s.city = 'Paris'
    )
  ;

..  csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder

  swg
  29

.. code:: sql
  :class: substep
  :number-lines:

  select sum(weight) as swg
  from (p natural join sp)
    join s using(sn)
  where s.city = 'Paris'
  ;

..  csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder

  swg
  46

----


:class: t2c

.. class:: rtl-h1

  جمع وزن قطعات متفاوتی را بیابید که عرضه‌کننده‌ای در شهر پاریس آنها را عرضه کرده باشد(۲).

.. code:: sql
  :class: substep
   :number-lines:

  select sum(weight) as swg
  from p
  where exists(
    select *
    from s
    where s.city = 'Paris' and exists(
      select *
      from sp
      where sp.sn = s.sn and sp.pn = p.pn
    )
  );

..  csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder

  swg
  29


----

:class: t2c

.. class:: rtl-h1

  جمع وزن قطعات  متفاوتی را بیابید که عرضه‌کننده‌ای در شهر پاریس آنها را عرضه کرده باشد(۳).

.. code:: sql
  :class: substep

  select sum(weight) as swg
  from p
  where exists (
      select *
      from sp natural join s
      where p.pn = sp.pn and s.city = 'Paris'
    )
  ;

..  csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder

  swg
  29

.. code:: sql
  :class: substep

  select sum(weight) as swg
  from (p natural join sp)
    join s using(sn)
  where s.city = 'Paris'
  ;

..  csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder

  swg
  46

.. code:: sql
  :class: substep

  select pn, weight, sn, s.city
  from (p natural join sp)
    join s using(sn)
  where s.city = 'Paris'
  ;

..  csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder

  pn, weight, sn, city
  P1, 12,     S2, Paris
  P2, 17,     S2, Paris
  P2, 17,     S3, Paris



----

:id: sum-sample-weight-paris-id
:class: t2c

.. class:: rtl-h1

  جمع وزن قطعات متفاوتی را بیابید که عرضه‌کننده‌ای در شهر پاریس آنها را عرضه کرده باشد(۴).

.. code:: sql
  :class: substep

  select sum(weight) as swg
  from p
  where exists (
      select *
      from sp natural join s
      where p.pn = sp.pn and s.city = 'Paris'
    )
  ;

..  csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder

  swg
  29

.. code:: sql
  :class: substep

  select sum(distinct weight) as swg
  from (p natural join sp)
    join s using(sn)
  where s.city = 'Paris'
  ;

..  csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder

  swg
  29

.. class:: substep rtl

  آیا این راه حل آخری با distinct درست است؟

.. class:: substep

  `راه حل دیگر <#/query-inside-from-id>`_

----

:class: t2c

.. class:: rtl-h1

  جمع وزن قطعات متفاوتی را بیابید که عرضه‌کننده‌ای در شهر پاریس آنها را عرضه کرده باشد(۵).


.. code:: sql
  :class: substep

  select swg
  from (
    select distinct pn, sum(weight) as swg
    from (p natural join sp)
      join s using(sn)
    where s.city = 'Paris'
  )
  ;


..  csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder

  swg
  46

.. code:: sql
  :class: substep

  select sum(weight) as swg
  from (
    select distinct pn, weight
    from (p natural join sp)
        join s using(sn)
    where s.city = 'Paris'
  )
  ;

..  csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder

  swg
  29

----

:class: t2c

.. class:: rtl-h1

  جمع وزنی قطعات عرضه‌شده به تعداد qty را بیابید که عرضه‌کننده‌ای در شهر پاریس آنها را عرضه کرده باشد.

.. code:: sql
  :class: substep

  select sum(qty * weight) as swg
  from (p natural join sp)
    join s using(sn)
  where s.city = 'Paris'
  ;

..  csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder

  swg
  13800

.. code:: sql
  :class: substep

  select pn, qty, weight
  from (p natural join sp)
    join s using(sn)
  where s.city = 'Paris'
  ;

..  csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder

  pn, qty,  weight
  p1, 300,  12
  p2, 400,  17
  p2, 200,  17

----

Average
================
.. class:: rtl-h2

میانگین وزن قطعه‌ها را بیابید

.. code:: sql

  select avg(weight) as awg
  from p
  ;

.. class:: rtl-h2

میانگین مقدار عرضه‌ها(qty) را بیابید

.. code:: sql
  :class: substep

  select avg(qty) as sqt
  from   sp
  ;

----

:class: t2c

.. class:: rtl-h1

  میانگین وزن قطعات را در شهر پاریس بیابید

.. code:: sql
  :class: substep

  select avg(weight) as awg
  from p
  where city='Paris'
  ;

..  csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder

    awg
    14.5

----

.. class:: rtl-h1

میانگین مقدار عرضه‌های(qty) عرضه‌کنندگان شهر پاریس را بیابید

.. code:: sql

  select avg(qty) as paqt
  from s natural join sp
  where s.city = 'Paris'
  ;

----

Count
=======
.. class:: rtl-h2

تعداد قطعات را بیابید

.. code:: sql

  select count(pn) as awg
  from p
  ;

..  csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder

  awg
  8


.. code:: sql

  select count(weight) as awg
  from p
  ;

..  csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder

  awg
  6

----

Count(*)
==========
.. class:: rtl-h2

تعداد قطعات را بیابید

.. code:: sql

  select count(*) as awg
  from p
  ;

..  csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder

  awg
  8

.. code:: sql

  select count(city) as ccy
  from p
  ;

..  csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder

  ccy
  8

.. code:: sql

  select count(*) as sqt
  from   sp;

    -- همهٔ رکوردها را می‌شمارد به فیلد خاصی مربوط نیست.

..  csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder

  sqt
  12

----

:class: t2c

count(distinct)
==================
.. class:: rtl-h1

تعداد شهرهای قطعات را بیابید

.. code:: sql

  select count(distinct city) as ccy
  from p
  ;

..  csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder

  ccy
  3

.. code:: sql
  :class: substep

  select city
  from p
  ;

..  csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder

  city
  Oslo
  London
  Paris
  London
  London
  Paris

----

:class: t2c

.. class:: rtl-h1

تعداد عرضه‌کنندگانی را بیابید که قطعه‌ای عرضه کرده باشند

.. code:: sql
  :class: substep

  select count(distinct sn) as sqt
  from sp;
  -- شماره‌های تکراری را نمی‌شمارد

..  csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder

  sqt
  4

.. code:: sql
  :class: substep

  select distinct sn
  from sp;

..  csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder

  sn
  S1
  S2
  S3
  S4

----

:class: t2c

.. class:: rtl-h1

تعداد عرضه‌کنندگانی را بیابید که قطعهٔ قرمزی را به تعداد عرضه(qty) بیشتر از ۵ عرضه کرده باشند.

.. code:: sql
  :class: substep

  select count(distinct sn) as scc
  from sp natural join p
  where qty > 5 and
    p.color = 'Red'
  ;

..  csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder

  scc
  3

----

:class: t2c

.. class:: rtl-h1

تعداد عرضه‌کنندگانی را بیابید که دست کم مقدار یکی از عرضه‌های آنها بیشتر از ۵ باشد و عرضه‌ای از قطعه‌ای به رنگ قرمز نیز داشته باشند(۱).

.. code:: sql
  :class: substep

  select count(*) as csn
  from (
      select sn
      from sp
      where qty > 5
    intersect
      select sn
      from sp join p using (pn)
      where p.color = 'Red'
  );

.. code:: sql
  :class: substep

  select count(*) as csn -- May have error
  from (
        select sname
        from s natural join sp
        where qty > 5
      intersect
        select sname
        from s natural join sp
          join p using (pn)
        where p.color = 'Red'
    )
  ;

----

:class: t2c

.. class:: rtl-h1

تعداد عرضه‌کنندگانی را بیابید که دست کم مقدار یکی از عرضه‌های آنها بیشتر از ۵ باشد و عرضه‌ای از قطعه‌ای به رنگ قرمز نیز داشته باشند(۲).

.. code:: sql
  :class: substep

  select count(sn) as csn
  from s
  where exists(
      select *
      from sp
      where sp.sn = s.sn
            and sp.qty > 5
    ) and exists(
      select *
      from sp natural join p
      where s.sn = sp.sn and
        p.color = 'Red'
    )
  ;

..  csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder

  csn
  3

----

Min
=====
.. class:: rtl-h2

کمترین وزن قطعه را بیابید

.. code:: sql

  select min(weight) as wgt
  from   p
  ;
  --- کمترین

----

max
============
.. class:: rtl-h2

بیشترین وزن قطعه را بیابید

.. code:: sql

  select max(weight) as wgt
  from   p
  ;
  --- بیشترین
  --- به اینها تابع تجمعی گفته می‌شود. aggregation function

----

:class: t2c

group by
=============
.. class:: rtl-h1

  شماره و مجموع عرضه‌های عرضه‌کنندگانی را بیابید که قطعه‌ای عرضه کرده‌اند.

.. container::

  .. code:: sql

    select sn, sum(qty) as sqt
    from   sp
    group by sn
    ;


  .. class:: substep rtl-h2

  * بر پایهٔ شمارهٔ عرضه کننده دسته‌بندی می‌کند
  * سپس برای هر دسته
  * شمارهٔ آن عرضه کننده (که با آن گروه‌بندی انجام شده است)

..  csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder

  sn, sqt
  s1, 1300
  s2, 700
  s3, 200
  s4, 900
  s6, 350

----

:class: t2c

.. class:: rtl-h1

  شماره و مجموع عرضه‌های قطعاتی را بیابید که عرضه شده باشند.

.. code:: sql
  :class: substep
  :number-lines:

  select pn, sum(qty) as sqt
  from   sp
  group by pn
  ;

.. csv-table::
    :header-rows: 1
    :class: substep smallerelementwithfullborder

    pn,sqt
    p1,600
    p2,1350
    p3,400
    p4,500
    p5,500
    p6,100

----

:class: t2c

.. class:: rtl-h1

  شمارهٔ قطعات با وزن بیشتر از ۱۲ را همراه با جمع عرضه‌های هر کدام بیابید

.. container::

  .. code:: sql
    :class: substep

    select pn, sum(qty) as sqt
    from sp join p using(pn)
    where weight > 12
    group by pn
    ;

  .. class:: substep rtl-h2

  نخست شرط where اعمال می‌شود سپس بر روی رکوردهای باقیمانده دسته‌بندی انجام می‌شود.

..  csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder

    pn, sqt
    p2, 1350
    p3, 400
    p4, 500
    p6, 100

----

:class: t2c

.. class:: rtl-h1

شمارهٔ قطعات با وزن بیشتر از ۱۲ را همراه با جمع عرضه‌های هر کدام بیابید به شرطی که بیشتر از دو عرضه کننده آنها را عرضه کرده باشند

.. code:: sql
  :number-lines:

  select pn, sum(qty) as sqt
  from sp join p using(pn)
  where weight>12
  group by pn
  having count(sn)>2
  ;

.. class:: substep rtl-h2

مانند پیشین با این تفاوت که گروه‌هایی برگردانده می‌شوند که شرط having را نیز داشته باشند.

..  csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder

    pn, sqt
    p2, 1350

.. :

    .. code:: sql
      :number-lines:

      select pname
      from sp join p using(pn)
      where exists(
        select *
        from sp as T
        where T.sn <> sp.sn and
          T.pn = sp.pn and exists(
            select *
            from sp as T2
            where T.sn <> sp.sn and
              T2.sn <> sp.sn and
              T2.pn = sp.pn
          )
      )

----

:class: t2c

.. class:: rtl-h1

  گام به گام

.. code:: sql

  select pn, qty as sqt
  from sp join p using(pn)
  where weight>12
  ;


..  csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder

  pn, sn, qty
  p1, s1, 300
  p1, s2, 300


..  csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder

  pn, sn, qty
  p2, s1, 200
  p2, s2, 400
  p2, s3, 200
  p2, s4, 200
  p2, s6, 350

.. container::

  ..  csv-table::
    :header-rows: 1
    :class: substep smallerelementwithfullborder

    pn, sn, qty
    p3, s1, 400

  .

  ..  csv-table::
    :header-rows: 1
    :class: substep smallerelementwithfullborder

    pn, sn, qty
    p6, s1, 100


..  csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder

  pn, sn, qty
  p4, s1, 200
  p4, s4, 300

..  csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder

  pn, sn, qty
  p5, s1, 100
  p5, s4, 400

----

:class: t2c

.. class:: rtl-h1

  نام قطعاتی را بیابید که بیشتر از دو عرضه کننده آنها را عرضه کرده باشند

.. code:: sql
  :number-lines:

  select distinct pname
  from sp join p using(pn)
  where exists(
    select *
    from sp as T
    where T.sn <> sp.sn and
      T.pn = sp.pn and exists(
        select *
        from sp as T2
        where T.sn <> sp.sn and
          T2.sn <> sp.sn and
          T2.sn <> T.sn and
          T2.pn = sp.pn
      )
  )

.. code:: sql
  :number-lines:

  select distinct pname
  from p natural join (
    select pn
    from sp join p using(pn)
    group by pn
    having count(sn) > 2
  );

  -- Second solution
  select distinct pname
  from p join sp using(pn) join
    sp as T1 using(pn) join
    sp as T2 using(pn)
  where T1.sn <> sp.sn and
    T2.sn <> sp.sn and
    T2.sn <> T1.sn;

----

:class: t2c

.. class:: rtl-h1

  نام شهرهای قطعاتی را بیابید که عرضه‌کننده‌ای با وضعیت بیشتر از ۱۰ نیز آنها را عرضه کرده باشد و جمع عرضه‌های هر کدام از آن شهرهای قطعه‌ها بیشتر از ۲۰ باشد(۱)

.. code:: sql
  :class: substep
  :number-lines:

  select city
  from p
  ;

.. code:: sql
  :class: substep
  :number-lines:

  select p.city as pcity
  from p join sp using(pn)
    join s using(sn)
  where status > 10
  ;

.. code:: sql
  :class: substep
  :number-lines:

  select p.city as pcity --wrong
  from p join sp using(pn)
    join s using(sn)
  where status > 10
  group by p.city
  having sum(qty) > 20
  ;

.. code:: sql
  :class: substep
  :number-lines:

  select p.city as pcity
  from p
  where exists(
    select *
    from sp join s using(sn)
    where p.pn = sp.pn and
      status > 10
  )
  ;


----

:class: t2c

.. class:: rtl-h1

  نام شهرهای قطعاتی را بیابید که عرضه‌کننده‌ای با وضعیت بیشتر از ۱۰ نیز آنها را عرضه کرده باشد و جمع عرضه‌های هر کدام از آن شهرهای قطعه‌ها بیشتر از ۲۰ باشد(۲)


.. :

    .. code:: sql
      :class: substep
      :number-lines:

      select p.city as pcity
      from p
      where exists(
        select *
        from sp join s using(sn)
        where p.pn = sp.pn and
          status > 10
      ) and exists(
        select p.city
        from sp
        where sp.pn = p.pn
        group by p.city
        having sum(qty) > 20
      )
      ;

.. code:: sql
  :class: substep
  :number-lines:

  select p.city as pcity
  from p natural join sp
  where exists(
    select *
    from s
    where s.sn = sp.sn and
      status > 10
  )
  group by p.city
  having sum(qty) > 20
  ;

----

:class: t2c


.. class:: rtl-h1

  نام شهرهای قطعاتی را بیابید که عرضه‌کننده‌ای با وضعیت بیشتر از ۱۰ نیز آنها را عرضه کرده باشد و جمع عرضه‌های هر کدام از آن شهرهای قطعه‌ها بیشتر از ۲۰ باشد
.. code:: sql
  :class: substep
  :number-lines:

  select p.city
  from p join sp using(pn)
  where exists (
      select *
      from s
      where s.sn = sp.sn and status > 10
    )
  group by p.city
  having sum(qty) > 20
  ;

..  csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder


    city
    London
    Oslo
    Paris

.. code:: sql
  :class: substep
  :number-lines:

  select p.city  --- نادرست
  from s natural join sp
    join p using(pn)
  where status > 10
  group by p.city
  having sum(qty) > 20
  ;

  select city -- نادرست
  from sp natural join p
  group by pn
  having status >10 and sum(qty) > 20
  ;

.. code:: sql
  :class: substep
  :number-lines:

  select p.city
  from p join sp using(pn)
  where exists (
      select *
      from (s natural join sp) as T
      where T.pn = p.pn and status > 10
    )
  group by p.city
  having sum(qty) > 20
  ;


----

:class: t2c

.. class:: rtl-h1

  نام شهرهای قطعاتی را بیابید که فقط عرضه‌کنندگان با وضعیت بیشتر از ۱۰  آنها را عرضه کرده باشند و جمع عرضه‌های هر کدام از آن شهرهای قطعه‌ها بیشتر از ۲۰ باشد

.. code:: sql
  :class: substep
  :number-lines:

  select p.city
  from s natural join sp
    join p using(pn)
  where status > 10
  group by p.city
  having sum(qty) > 20
  ;

..  csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder


    city
    London
    Oslo
    Paris

.. code:: sql
  :class: substep
  :number-lines:

  select p.city
  from sp join p using(pn) natural join
    (
      select sn
      from s
      where status > 10
    )
  group by p.city
  having sum(qty) > 20
  ;

----

:class: t2c

.. class:: rtl-h1

  نام پروژه‌هایی را بیابید که عرضه‌کننده‌ای با وضعیت بیشتر از ۲۰ نیز آنها را عرضه کرده باشند و جمع وزنی عرضه‌های هر کدام از آن پروژه‌ها بیشتر از ۱۰۰ باشد(I)

.. code:: sql
  :class: substep
  :number-lines:

  select jname
  from spj join j using(jn)
    join p using(pn)
  where exists (
      select *
      from s
      where s.sn = spj.sn and
        s.status > 20
    )
  group by jn
  having(sum(weight*qty)>100)
  ;

.. code:: sql
  :class: substep
  :number-lines:

  select jname
  from j natural join (
    select jn
    from spj join j using(jn)
      join p using(pn)
    where exists (
        select *
        from s
        where s.sn = spj.sn and
          s.status > 20
      )
    group by jn
    having(sum(weight*qty)>100)
  )
  ;


----

:class: t2c

.. class:: rtl-h1

  نام پروژه‌هایی را بیابید که عرضه‌کننده‌ای با وضعیت بیشتر از ۲۰ نیز آنها را عرضه کرده باشند و جمع وزنی عرضه‌های هر کدام از آن پروژه‌ها بیشتر از ۱۰۰ باشد(II)

.. code:: sql
  :class: substep
  :number-lines:

  select jname
  from j natural join (
    select jn
    from spj join j using(jn)
      join p using(pn)
    where exists (
        select *
        from s
        where s.sn = spj.sn and
          s.status > 20
      )
    group by jn
    having(sum(weight*qty)>100)
  );

----

:class: t2c

.. class:: rtl-h1

  شمارهٔ قطعات با وزن بیشتر از ۱۲ را همراه با جمع عرضه‌های هر کدام بیابید که بیشتر از دو عرضه کننده آنها را عرضه کرده باشند

.. code:: sql
  :class: substep
  :number-lines:

  select pn, sum(qty)
  from sp natural join p
  where p.weight > 12
  group by pn
  having count(sn)>2
  ;

.. code:: sql
  :class: substep
  :number-lines:

  select pn, sum(qty) -- same result
  from sp natural join p
  where p.weight > 12
  group by pn
  having count(distinct sn)>2
  ;

.. code:: sql
  :class: substep
  :number-lines:

  select pn, sum(qty) -- wrong
  from spj natural join p
  where p.weight > 12
  group by pn
  having count(sn)>2
  ;

.. code:: sql
  :class: substep
  :number-lines:

  select pn, sum(qty)
  from spj natural join p
  where p.weight > 12
  group by pn
  having count(distinct sn)>2
  ;

----

:class: t2c

.. class:: .rtl-h1

نام شهرهای قطعاتی را بیابید که عرضه‌کننده‌ای با وضعیت بیشتر از ده ، دست کم یکی از قطعات درون آن شهرها را عرضه کرده باشد و مجموع عرضه‌های قطعه‌های آن شهرها بیشتر از ۲۰ باشد به شرطی که تعداد قطعات در آن شهر قطعه بیشتر از دو باشد(I).

.. container::

  .. code:: sql
    :class: substep
    :number-lines:

    select p.city -- wrong answer
    from p join sp using(pn)
      join s using(sn)
    where s.status > 10
    group by p.city
    having sum(qty) > 20 and
      count(distinct pn) > 2
    ;

  .. code:: sql
    :class: substep
    :number-lines:

    SELECT p.city  -- wrong answer
    FROM p NATURAL JOIN sp
    WHERE EXISTS(
      SELECT * FROM s NATURAL JOIN sp
      WHERE s.sn=sp.sn AND p.city=s.city
        AND s.status > 10
      )
    GROUP by pn
    HAVING count(pn)>2 and sum(qty)>20
    ;

.. code:: sql
  :class: substep
  :number-lines:

  select p.city -- wrong answer
  from p join sp using(pn)
  where exists(
      select *
      from s -- Mohammad Javad Akbari
      where status > 10 and
        s.sn = sp.sn
    )
  group by p.city
  having sum(qty) > 20 and
    count(pn) > 2
  ;

----

:class: t2c

.. class:: .rtl-h1

نام شهرهای قطعاتی را بیابید که عرضه‌کننده‌ای با وضعیت بیشتر از ده ، دست کم یکی از قطعات درون آن شهرها را عرضه کرده باشد و مجموع عرضه‌های قطعه‌های آن شهرها بیشتر از ۲۰ باشد به شرطی که تعداد قطعات در آن شهر قطعه بیشتر از دو باشد(II).

.. code:: sql
  :class: substep
  :number-lines:

  select p.city
  from p join sp using(pn)
  where exists(
      select *
      from s
      where status > 10 and
        s.sn = sp.sn
    )
  group by p.city
  having sum(qty) > 20 and
    count(distinct pn) > 2
  ;

.. code:: sql
  :class: substep
  :number-lines:

  select p.city
  from p join sp using(pn)
  where exists(
      select *
      from s
      where status > 10 and
        s.sn = sp.sn
    ) and exists(
      select *
      from p as p2
      where p.city = p2.city and
        p.pn <> p2.pn
    )
  group by p.city
  having sum(qty) > 20
  ;

.. :

    ----

    نام شهرهای قطعاتی را بیابید که عرضه‌کننده‌ای با وضعیت بیشتر از ده یکی از قطعات درون آن شهرها را عرضه کرده باشد و مجموع عرضه‌های قطعه‌های آن شهرها بیشتر از ۲۰ باشد به شرطی که تعداد قطعات در آن شهر قطعه بیشتر از دو باشد.
    =============================================================================================================================================================================================================================================================================================
    نادرست

    .. code:: sql
      :number-lines:

      select p.city  -- wrong answer
      from p join spj using(pn) join s using(sn)
      where s.status > 10
      group by p.city
      having sum(qty) > 20 and count(distinct pn) > 2
      ;

    .. code:: sql
      :class: substep
      :number-lines:

      select p.city
      from p join sp using(pn)
      where exists(
          select *
          from s natural join (sp as T)
          where status > 10 and
            s.sn = T.sn
        )
      group p.city
      having sum(qty) > 20 and
        count(distinct pn) > 2
      ;


----

:class: t2c

.. class:: .rtl-h1

نام شهرهای قطعاتی را بیابید که عرضه‌کننده‌ای با وضعیت بیشتر از ده ، دست کم یکی از قطعات درون آن شهرها را عرضه کرده باشد و مجموع عرضه‌های قطعه‌های آن شهرها بیشتر از ۲۰ باشد به شرطی که تعداد قطعات در آن شهر قطعه بیشتر از دو باشد(III).

.. code:: sql
  :class: substep
  :number-lines:

  select p.city
  from p join sp using(pn)
  where exists(
      select *
      from s
      where status > 10 and
        s.sn = sp.sn
    )
  group by p.city
  having sum(qty) > 20 and
    count(distinct pn) > 2
  ;


.. code:: sql
  :class: substep
  :number-lines:

  select p.city
  from p join sp using(pn)
  where exists(
      select *
      from s
      where status > 10 and
        s.sn = sp.sn
    ) and exists(
      select *
      from p as p2, p as p3
      where p.city = p2.city and
        p.pn <> p2.pn and p.city = p3.city
        and p.pn <> p3.pn and p2.pn <> p3.pn
    )
  group by p.city
  having sum(qty) > 20
  ;

----

:class: t2c

.. class:: rtl-h1

  نام پروژه‌هایی را بیابید که عرضه‌کننده‌ای با وضعیت بیشتر از ۲۰ برای آن پروژه‌ها عرضه کرده باشد و مجموع وزن قطعات عرضه شده برای آن نام پروژه (یا پروژه‌ها) بیشتر از ۱۰۰ باشد

.. class:: substep rtl-h2

دقت کنید مجموع وزن قطعات باید تعداد  در وزن ضرب شود

.. code:: sql
  :class: substep
  :number-lines:

  select jname
  from spj join j on
    spj.jn = j.jn join
    p using(pn)
  where exists(
      select *
      from s
      where s.sn = spj.sn
        and s.status > 20
    )
  group by jname
  having(sum(weight*qty)>100)
  ;

----

:class: t2c

.. class:: rtl-h1

  نام پروژه‌هایی را بیابید که عرضه‌کننده‌ای با وضعیت بیشتر از ۲۰ برای آن پروژه‌ها عرضه کرده باشد و مجموع وزن قطعات عرضه شده برای آن پروژه (و نه همراه با هم‌نام‌هایش) بیشتر از ۱۰۰ باشد

.. code:: sql
  :class: substep
  :number-lines:

  select jname
  from spj join j on
    spj.jn = j.jn join
    p using(pn)
  where exists(
      select *
      from s
      where s.sn = spj.sn
        and s.status > 20
    )
  group by jn
  having(sum(weight*qty)>100)
  ;

.. code:: sql
  :class: substep
  :number-lines:

  select jname
  from j natural join (
    select jn
      from spj join j on
        spj.jn = j.jn join
        p using(pn)
      where exists(
          select *
          from s
          where s.sn = spj.sn
            and s.status > 20
        )
      group by jn
      having(sum(weight*qty)>100)
    )
  ;

----

:class: t2c

.. class:: rtl-h1

  دسته‌بندی در یک گروه

.. code:: sql
  :number-lines:

  -- Totally wrong
  select pn, count(distinct pn)
  from p natural join sp
  group by pname
  -- having count(distinct pn) > 1
  ;

.. code:: sql
  :number-lines:

  select pname, count(sn)
  from p natural join sp
  group by pn
  -- having count(distinct pn) > 1
  ;

----

:id: query-inside-from-id
:class: t2c

.. class:: rtl-h1

جمع وزن قطعه‌هایی را بیابید که دستِ‌کم عرضه کننده‌ای از پاریس نیز آنها را عرضه کرده باشد.

.. code:: sql
  :class: substep
  :number-lines:

  select sum(weight) as swg
  from (p natural join sp)
    join s using(sn)
  where s.city = 'Paris'
  ;

..  csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder

  swg
  46

.. code:: sql
  :class: substep
  :number-lines:

  select pn, weight, sn, s.city
  from (p natural join sp)
    join s using(sn)
  where s.city = 'Paris'
  ;

..  csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder

  pn, weight, sn, city
  P1, 12,     S2, Paris
  P2, 17,     S2, Paris
  P2, 17,     S3, Paris

.. code:: sql
  :class: substep
  :number-lines:

  select sum(weight) as swg
  from (
      select distinct pn, weight
      from (p natural join sp)
        join s using(sn)
      where s.city = 'Paris'
    )
  ;

.. container::

    ..  csv-table::
      :header-rows: 1
      :class: substep smallerelementwithfullborder

      swg
      29

.. :

    distinct does not help

----

:class: t2c

.. class:: rtl-h1

جمع وزن قطعه‌هایی را بیابید که دستِ‌کم عرضه کننده‌ای از پاریس نیز آنها را عرضه کرده باشد.

.. code:: sql
  :class: substep
  :number-lines:

  select sum(weight) as swg
  from p natural join sp
  where exists(
      select *
      from s
      where s.sn = sp.sn and
        s.city = 'Paris'
    )
  ;

..  csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder

  swg
  46

.. code:: sql
  :class: substep
  :number-lines:

  select sum(weight) as swg
  from (
      select distinct pn, weight
      from (p natural join sp)
        join s using(sn)
      where s.city = 'Paris'
    )
  ;

..  csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder

  swg
  29

.. class:: substep

  `بحث اصلی <#/sum-sample-weight-paris-id>`_

.. :

    distinct does not help

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
=================
.. class:: rtl-h1

شماره و وزن قطعاتی را بیابید که وزن آنها از میانگین وزن همهٔ قطعات بیشتر است.

.. code:: sql
  :class: substep

  select pn, weight
  from p
  where weight > (
      select avg(weight)
      from p
    )
  ;

.. csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder

  pn, weight
  p2, 17
  p3, 17
  p6, 19

----

:class: t2c

Scalar value(II)
======================
.. class:: rtl-h1

شماره و وزن قطعاتی را بیابید که کمترین وزن را داشته باشند.

.. code:: sql
  :class: substep

  select pn, weight
  from p
  where weight = (
      select min(weight)
      from p
  );

.. csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder

  pn, weight
  p1, 12
  p5, 12

.. code:: sql
  :class: substep

  select pn, weight
  from p  -- Wrong
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

----

:class: t2c

Scalar value(V)
=================
.. code:: sql
  :class: substep
  :number-lines:

  select pn, 1 as qt
  from p
  where city = 'Paris'
  ;

.. csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder

  pn, qt
  P2, 1
  P5, 1
  P8, 1

----

:class: t2c

.. class:: rtl-h1

شمارهٔ همهٔ قطعات را همراه با جمع تعداد عرضه‌های (qty) آن قطعات بیابید(۱).

.. code:: sql
  :class: substep

  select pn, sum(qty) as sqty
  from sp
  group by pn;

  -- wrong

.. csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder

  pn, sqty
  p1, 600
  p2, 1350
  p3, 400
  p4, 500
  p5, 500
  p6, 100


----

:class: t2c

.. class:: rtl-h1

شمارهٔ همهٔ قطعات را همراه با جمع تعداد عرضه‌های (qty) آن قطعات بیابید(۲).

.. code:: sql
  :class: substep

  select pn, (
      select sum(qty)
      from sp
      where p.pn = sp.pn
    ) as sqty
  from p ;

.. csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder

  pn, sqty
  p1, 600
  p2, 1350
  p3, 400
  p4, 500
  p5, 500
  p6, 100
  p7,
  p8,

----

:class: t2c

.. class:: rtl-h1

شمارهٔ همهٔ قطعات را همراه با جمع وضعیت عرضه‌کنندگان درون شهر آن قطعات به همراه شهر قطعه بیابید که به ترتیب نزولی وزن قطعه نشان داده شده باشند.

.. container::

    .. code:: sql
        :class: substep
        :number-lines:

        select pn,
           (select sum(status)
            from s
            where s.city = p.city
           ) as sum_status,
           city
        from p
        order by weight desc ;

    .. code:: sql
        :class: substep
        :number-lines:

        select pn, sum(status) , p.city
        from p natural join sp natural join s
        order by weight desc; -- wrong

    .. code:: sql
        :class: substep
        :number-lines:

        select pn, sum(status) , p.city
        from p join s using(city)
        order by weight desc; -- wrong

.. csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder


    pn, sum_status, city
    p6, 40,   London
    p2, 40,   Paris
    p3,   ,   Oslo
    p4, 40,   London
    p1, 40,   London
    p5, 40,   Paris
    p7, 40,   London
    p8, 40,   Paris

----

:class: t2c

.. class:: rtl-h1

شمارهٔ همهٔ قطعات را همراه جمع تعداد عرضه‌های آنها بیابید.


.. code:: sql
    :class: substep
    :number-lines:

    select pn, sum(qty) as sqty
    from p natural join sp
    group by pn; -- wrong

.. code:: sql
    :class: substep

    select pn, (
        select sum(qty)
        from sp
        where sp.pn = p.pn
      ) as sqty
    from p;

.. csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder

  pn, sqty
  p1, 600
  p2, 1350
  p3, 400
  p4, 500
  p5, 500
  p6, 100

.. csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder

  pn, sqty
  p1, 600
  p2, 1350
  p3, 400
  p4, 500
  p5, 500
  p6, 100
  p7,
  p8,

----

:class: t2c

Left Outer Join(I)
======================
.. container::

  .. code:: sql
      :class: substep

      select pn, sum(qty) as sqty
      from p natural left outer join sp
      group by pn;

  .. code:: sql
      :class: substep

      select pn, sum(qty) as sqty
      from p left outer join sp using(pn)
      group by pn;

.. csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder

  pn, sqty
  p1, 600
  p2, 1350
  p3, 400
  p4, 500
  p5, 500
  p6, 100
  p7,
  p8,

----

:class: t2c

Left Outer Join(II)
=======================
.. code:: sql
    :class: substep

    select p.pn, sum(qty) as sqty
    from p left outer join sp on p.pn = sp.pn
    group by p.pn;


.. code:: sql
    :class: substep
    :number-lines:

    select pn, (
        select sum(qty)
        from sp
        where sp.pn = p.pn
      ) as sqty
    from p;


----

:class: t2c

.. class:: rtl-h1

نام شهرهای همهٔ قطعاتی را بیابید که عرضه‌کننده‌ای با وضعیت بیشتر از ده ، دست کم یکی از قطعات درون آن شهرها را عرضه کرده باشد و مجموع عرضه‌های قطعه‌های آن شهرها بیشتر از ۲۰ باشد به شرطی که تعداد قطعات در آن شهر قطعه بیشتر از دو باشد.

.. code:: sql
  :class: substep
  :number-lines:

  select p.city
  from p left outer join sp using(pn)
  where exists(
      select *
      from s
      where status > 10 and
        s.sn = sp.sn
    )
  group by p.city
  having sum(qty) > 20 and
    count(distinct pn) > 2
  ;

----

:class: t2c

Full Outer Join(I)
====================
.. code:: sql
    :class: substep

    select pn, sum(qty) as sqty
    from p natural full outer join sp
    group by pn;

.. code:: sql
    :class: substep

    select pn, sum(qty) as sqty
    from p full outer join sp using(pn)
    group by pn;

.. code:: sql
    :class: substep

    select p.pn, sum(qty) as sqty
    from p full outer join sp on p.pn = sp.pn
    group by p.pn;

.. code:: sql
    :class: substep

    select distinct p.city, s.city
    from p natural left outecd inr join s;


----

:class: t2c

Full Outer Join(II)
====================
.. code:: sql

    select distinct p.city, s.city
    from p natural full outer join s;

.. code:: sql

    select distinct p.city, s.city
    from p, s; -- very different result

----

:class: t2c

.. class:: rtl-h1

  نام همهٔ شهرهای عرضه کنندگان را در کنار نام شهر قطعاتی که همشهری آنها هستند بنویسید و اگر قطعه‌ای همشهری آن عرضه کننده نبود نام شهر عرضه کننده همراه با null بیاید(I)

.. code:: sql
    :class: substep

    select s.city, p.city
    from s left outer join p using(city);

.. code:: sql
    :class: substep

    select  p.city, s.city --wrong
    from p full outer join s on p.city = s.city;

.. code:: sql
    :class: substep

    select  p.city, s.city --wrong
    from p full outer join s using(city);

.. code:: sql
    :class: substep

    select  p.city, s.city --wrong
    from p natural full outer join s;

.. code:: sql
    :class: substep

    select  p.city, s.city
    from p natural right outer join s;

.. code:: sql
    :class: substep

    select  p.city, s.city --wrong
    from p natural left outer join s;

----

:class: t2c

.. class:: rtl-h1

  نام همهٔ شهرهای عرضه کنندگان را در کنار نام شهر قطعاتی که همشهری آنها هستند بنویسید و اگر قطعه‌ای همشهری آن عرضه کننده نبود نام شهر عرضه کننده همراه با null بیاید(II)

.. container::

    .. code:: sql
      :class: substep

      select s.city as scity, p.city as pcity
      from s left outer join p using(city);

    .. code:: sql
      :class: substep

      select s.city as scity, p.city as pcity
      from s, p --  wrong


.. csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder

  scity ,  pcity
  London, London
  London, London
  London, London
  London, London
  Paris ,  Paris
  Paris ,  Paris
  Paris ,  Paris
  Paris ,  Paris
  Paris ,  Paris
  Paris ,  Paris
  London, London
  London, London
  London, London
  London, London
  Athens,
  کاشان ,

----

:class: t2c

is null / is not null
==========================
.. code:: sql

    select pname
    from p
    where weight is null;

.. code:: sql

    select sname
    from s
    where status is not null;

----

:class: t2c

Scalar value(III)
======================
.. class:: rtl-h1

شماره و وزن قطعاتی را بیابید که کمترین وزن را داشته باشند(I).

.. code:: sql
  :class: substep
  :number-lines:

  select pn, weight -- wrong
  from p
  order by weight asc
  limit 1
  ;

.. csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder

  pn, weight
  p7,

.. code:: sql
  :class: substep
  :number-lines:

  select pn, weight -- wrong
  from p
  where weight is not null
  order by weight asc
  limit 1
  ;

.. csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder

  pn, weight
  p1, 12


----

:class: t2c

Scalar value(IV)
====================
.. class:: rtl-h1

شماره و وزن قطعاتی را بیابید که کمترین وزن را داشته باشند(II).

.. code:: sql
  :number-lines:

  select pn, weight -- wrong
  from p
  where weight is not null
  order by weight asc
  limit 1
  ;

.. csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder

  pn, weight
  p1, 12

.. code:: sql
  :class: substep
  :number-lines:

  select pn, weight
  from p
  where weight = (
      select weight
      from p
      where weight is not null
      order by weight asc
      limit 1
    )
  ;

.. csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder

  pn, weight
  p1, 12
  p5, 12


----

:class: t2c

Scalar value(IV)
====================
.. class:: rtl-h1

شماره و وزن قطعاتی را بیابید که کمترین وزن را داشته باشند(III).

.. code:: sql
  :number-lines:

  select pn, weight
  from p
  where weight = (
      select weight
      from p
      where weight is not null
      order by weight asc
      limit 1
    )
  ;

.. csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder

  pn, weight
  p1, 12
  p5, 12

.. code:: sql
  :number-lines:

  select pn, weight
  from p
  where weight = (
      select min(weight)
      from p
    )
  ;

.. csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder

  pn, weight
  p1, 12
  p5, 12

----

:class: t2c

.. class:: rtl-h1

    نام قطعات و شمارهٔ عرضه‌کنندگان همشهری آن قطعات را بیابید. نیازی نیست آن عرضه کننده آن قطعه را عرضه کرده باشد.

.. container::

  .. code:: sql
      :class: substep

      select pname, sn
      from p natural join (select city, sn from s);

  .. code:: sql
      :class: substep

      select pname, sn
      from p natural join s;

.. csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder

  pname, sn
  Nut,   s1
  Nut,   s4
  Bolt,  s2
  Bolt,  s3
  Screw, s1
  Screw, s4
  Cam,   s2
  Cam,   s3
  Cog,   s1
  Cog,   s4
  Nut,   s1
  Nut,   s4
  Bolt,  s2
  Bolt,  s3

----

:class: t2c

.. class:: rtl-h1

    نام پروژه‌هایی را بیابید که عرضه‌کننده‌ای با وضعیت بیشتر از ۲۰ برای آن پروژه‌ها عرضه کرده باشد و مجموع وزن قطعات عرضه شده برای آن پروژه بیشتر از ۱۰۰ باشد. دقت کنید مجموع وزن قطعات باید qty در weight ضرب شود.

.. code:: sql
  :class: substep

  select jname -- نادرست
  from spj join j using(jn) join s
    using(sn) join p using(pn)
  where s.status > 20
  group by jn
  having(sum(weight * qty) > 100)

.. code:: sql
  :class: substep

  select jname  -- نادرست
  from j join spj using(jn) join s
    using(sn) join P using(pn)
  where status > 20
  group by pn
  having sum(qty * weight) > 100;

.. code:: sql
  :class: substep

  select jname -- درست
  from p join spj using(pn) join
    j using(jn)
  where exits(
    select *
    from s natural join (spj as T)
    where T.jn=j.jn and status > 20
  )
  group by jn
  having (weight*qty)>100

.. code:: sql
  :class: substep

  select jname -- درست
  from j natural join (
    select jn
    from p join spj using(pn) join
      j using(jn)
    where exists(
      select *
      from s natural join spj as T
      where T.jn=j.jn and status > 20
    )
    group by jn
    having (weight*qty)>100 );

----

:class: t2c

.. class:: rtl-h1

    نام شهرهای قطعاتی را بیابید که عرضه‌کننده‌ای با وضعیت بیشتر از ده یکی از قطعات درون آن شهرها را عرضه کرده باشد و مجموع عرضه‌های قطعه‌های آن شهرها بیشتر از ۲۰ باشد به شرطی که تعداد قطعات در آن شهر قطعه بیشتر از دو باشد.

.. code:: sql
    :class: substep

    select p.city
    from p join sp using(pn) join s using(sn)
    where s.status > 10
    group by p.city
    having sum(qty) > 20 and count(distinct pn) > 2;

.. class:: rtl substep

    پاسخ نادرست


.. code:: sql
    :class: substep

    select p.city
    from p join sp using(pn)
    where exists(
      select *
      from s
      where s.status > 10 and s.sn = sp.sn
    )
    group by p.city
    having sum(qty) > 20 and count(distinct pn) > 2;


.. class:: rtl substep

    پاسخ درست


----

:class: t2c

.. class:: rtl-h1

  شمارهٔ قطعات با وزن بیشتر از ۱۲ را همراه با جمع عرضه‌های هر کدام بیابید که بیشتر از دو عرضه کننده آنها را عرضه کرده باشند.

.. code:: sql
    :class: substep

    select pn, sum(qty)
    from sp natural join p
    where p.weight > 12
    group by pn
    having count(sn)>2;

----

.. class:: rtl-h1

  شمارهٔ قطعات با وزن بیشتر از ۱۲ را همراه با جمع عرضه‌های هر کدام بیابید.

.. code:: sql

  select pn, sum(qty)
  from sp natural join p
  where p.weight > 12
  group by pn

----

END
