:data-transition-duration: 1000
:skip-help: true
:css: ./style.css
:substep: true
:slide-numbers: true
:data-width: 1024
:data-height: 768


.. title: Databse System, relations (By Ahmad Yoosofan)

:slide-numbers: true

.. role:: raw-html(raw)
   :format: html

.. |nbsp| unicode:: 0xA0

.. role:: rtl
    :class: rtl

----

Database Course
==================
Ahmad Yoosofan

University of Kashan

Relational Calculus
---------------------

----

:class: t2c

First-Order Logic (Predicates and Quantifiers)
==============================================

.. code:: sh
  :number-lines:

    Calculation on tuples instead of relations

    { px ∈ P | px.city = 'kashan'}

    ∀ forall

    ∃ exists

    ∀ a, b ∈ R | a+b = b + a

    ∃ a ∈ R ,  ∀ b ∈ R | a * b  = b

    a = 1

    ∀x p(x) ≡ ~∃x ~p(x)


.. code:: sh
 :number-lines:

  RANGEOVER sx RANGES over S;

  RANGEOVER sy RANGES over S;

  RANGEOVER px RANGES over P;

  RANGEOVER py RANGES over P;

  RANGEOVER spx RANGES over SP;

  RANGEOVER spy RANGES over SP;

.. notes:

    https://nuprl-web.cs.cornell.edu/MathLibrary/LogicalInvestigations/all_exists.html

    https://www.geeksforgeeks.org/engineering-mathematics/mathematic-logic-predicates-quantifiers/

    https://en.wikipedia.org/wiki/First-order_logic

    https://en.wikipedia.org/wiki/Existential_quantification

----

:class: t2c

.. code:: sql
  :number-lines:

    px where px.city = 'kashan'

    sx where sx.city = 'kashan'

    sx where sx.status > 1

    sx.sname where sx.sn = 's2'

    sx.sname, sx.staus where sx.status > 100

.. code:: sql
  :number-lines:

    sx.sn, sx.sname

    spx.sn, spx.pn

    spx.sn, spy.pn

نام قطعات را بیابید.

    px.pname

نام عرضه‌کنندگان را بیابید

    sx.sname

----

:class: t2c

.. class:: rtl-h1

نام قطعاتی را بیابید که وزن‌شان بیشتر از ۲۰ باشد

.. code:: sql
  :class: substep

  1. px

.. code:: sql
  :class: substep

  3. px.pname

.. code:: sql
  :class: substep

  3. px.pname where

.. code:: sql
  :class: substep

  4.  px.pname where px.weight > 20

----

:class: t2c

.. class:: rtl-h1

نام قطعاتی را بیابید که وزن‌شان بیشتر از ۲۰ باشد و در شهر کاشان باشند.


.. code:: sql
  :class: substep

  1. px

.. code:: sql
  :class: substep

  2. px.pname

.. code:: sql
  :class: substep

  3. px.pname where

.. code:: sql
  :class: substep

  4. px.pname where px.weight > 20

.. code:: sql
  :class: substep

  5. px.pname where px.weight > 20 and

.. code:: sql
  :class: substep

  6. px.pname where px.weight > 20 and
      px.city = 'kashan'

----

:class: t2c

.. class:: rtl-h1

نام قطعات قرمز رنگ با وزن بیشتر از ۱۲ را بیابید

.. code:: sql
  :class: substep

  1. px.pname

.. code:: sql
  :class: substep

  2. px.pname where

.. code:: sql
  :class: substep

  3. px.pname where px.weight > 12

.. code:: sql
  :class: substep

  4. px.pname where px.weight > 12 and

.. code:: sql
  :class: substep

  5. px.pname where px.weight > 12 and
      px.color = "red"

----

.. class:: rtl-h1

نام و شمارهٔ قطعاتی را بیابید که وزن بیشتر از ۲۰ داشته باشند.

.. class:: substep

    #. px.pname
    #. px.pname, px.pn
    #. px.pname, px.pn where px.weight > 20
    #. {px.pname, px.pn} where px.weight > 20

----

.. class:: rtl-h1

نام عرضه‌کنندگانی را بیابید که وضعیت بیشتر از ۱۰ داشته باشند.

.. class:: substep

    #. sx.sname
    #. sx.sname where
    #. sx.sname where sx.status > 10

----

.. class:: rtl-h1

زوج شمارهٔ عرضه‌کنندگانی را بیابید که در یک شهر باشند.

.. class:: substep

    #. sx.sn
    #. sx.sn, sy.sn
    #. {sx.sn, sy.sn}
    #. {sx.sn, sy.sn as sn1}
    #. {sx.sn, sy.sn as sn1} where
    #. {sx.sn, sy.sn as sn1} where sx.city = sy.city
    #. {sx.sn, sy.sn as sn1} where sx.city = sy.city and
    #. {sx.sn, sy.sn as sn1} where sx.city = sy.city and sx.sn < sy.sn

----

.. class:: rtl-h1

نام شهر قطعاتی را بیابید که عرضه شده باشند.

.. class:: substep

  * px
  * px.city
  * px.city where
  * px.city where exists spx
  * px.city where exists spx(px.pn = spx.pn)

----

.. class:: rtl-h1

نام قطعات عرضه شده را بیابید

.. class:: substep

  #. px.pname
  #. px.pname where
  #. px.pname where exists spx
  #. px.pname where exists spx (spx.pn = px.pn)

.. class:: substep

  #. px.pname where spx.pn = px.pn

  #.  Error

  #. px.pname where forall spx (spx.pn = px.pn)

.. class:: rtl-h2 substep

نام قطعه‌ای را بیابید که همهٔ عرضه‌ها فقط از آن قطعه باشد.

----

:class: t2c

.. class:: rtl-h1

نام شهرهای عرضه‌کنندگانی را بیابید که قطعهٔ با شمارهٔ p2 را عرضه کرده باشند.

.. class:: substep

  * sx.city
  * sx.city where
  * sx.city where exists spx (
      * spx.sn = sx.sn
      * and
      * spx.pn = 'p2'
      * )

  * sx.city where exists spx(
      spx.sn = sx.sn and
          spx.pn = 'p2')

  * Problem?

.. container:: substep

    .. code:: sql

        sx.city where exists spx (
          spx.sn = sx.sn
        ) and exists px (px.pn = 'P2')

    .. code:: sql

      sx.city where exists spx (
        spx.sn = sx.sn
      )  and exists spy (spy.pn = 'P2')


    .. code:: sql

       sx.city where exists spx (
         spx.sn = sx.sn and
         spx.pn = 'p2'
        )

----

:class: t2c

.. class:: rtl-h1

زوج شمارهٔ عرضه‌کنندگانی را بیابید که در یک شهر باشند و قطعه یا قطعه‌هایی عرضه کرده باشند.


.. code:: sql
   :class: substep

      {sx.sn, sy.sn as sn2}

.. code:: sql
   :class: substep

      {sx.sn, sy.sn as sn2} where
      sx.city = sy.city

.. code:: sql
   :class: substep

      {sx.sn, sy.sn as sn2} where
      sx.city = sy.city and
      sx.sn < sy.sn

.. code:: sql
   :class: substep

      {sx.sn, sy.sn as sn2} where
      sx.city = sy.city and
      sx.sn < sy.sn and

.. code:: sql
   :class: substep

      {sx.sn, sy.sn as sn2} where
      sx.city = sy.city and
      sx.sn < sy.sn and
      exists spx(sx.sn = spx.sn)

.. code:: sql
   :class: substep

      {sx.sn, sy.sn as sn2} where
      sx.city = sy.city and
      sx.sn < sy.sn and
      exists spx(sx.sn = spx.sn)
      and

.. code:: sql
   :class: substep

      {sx.sn, sy.sn as sn2} where
      sx.city = sy.city and
      sx.sn < sy.sn and
      exists spx(sx.sn = spx.sn)
      and exists spy

.. code:: sql
   :class: substep

      {sx.sn, sy.sn as sn2} where
      sx.city = sy.city and
      sx.sn < sy.sn and
      exists spx(sx.sn = spx.sn)
      and exists spy(
      sy.sn = spy.sn
      )

.. :

    wrong answers

    {sx.sn, sy.sn as sn2} where sx.city = sy.city and sx.sn < sy.sn and exists spx(sx.sn = spx.sn and sy.sn = spx.sn)

----

:class: t2c

.. class:: rtl-h1

نام عرضه‌کنندگانی را بیابید که دست کم یک قطعهٔ قرمز عرضه کرده باشند.

.. code:: sql
   :class: substep

   sx.sname

.. code:: sql
   :class: substep

   sx.sname where

.. code:: sql
   :class: substep


    sx.sname where exists spx(
      sx.sn=spx.sn and

.. code:: sql
   :class: substep

   sx.sname where exists spx(
    sx.sn=spx.sn and exists px(

.. code:: sql
   :class: substep

   sx.sname where exists spx(
    sx.sn=spx.sn and exists px(
      px.pn=spx.pn

.. code:: sql
   :class: substep

   sx.sname where exists spx(
    sx.sn=spx.sn and exists px(
      px.pn=spx.pn and

.. code:: sql
   :class: substep

   sx.sname where exists spx(
    sx.sn=spx.sn and exists px(
      px.pn=spx.pn and
        px.color = "red"
    )
   )

.. code:: sql
   :class: substep

   sx.sname where exists px(
    px.color = "red" and
    exists spx(px.pn=spx.pn
      and sx.sn=spx.sn
    )
   )


.. class: rtl substep

  پاسخ نادرست

  1. sx.sname where exists spx(sx.sn=spx.sn) and exists px(px.pn=spx.pn and px.color = 'red’)
  2. sx.sname where exists spx(sx.sn=spx.sn) and exists px(exists spx(px.pn=spx.pn and px.color = 'red’))
  3. sx.sname where exists spx(sx.sn=spx.sn and px.pn=spx.pn and px.color = 'red’)

----

:class: t2c

.. class:: rtl-h1

زوج شمارهٔ عرضه‌کنندگانی را بیابید که در یک شهر باشند و دست کم یکی از آن دو عرضه کننده، قطعه یا قطعه‌هایی را عرضه کرده باشند.

.. csv-table::
  :header-rows: 1
  :class: substep  smallerelementwithfullborder

  SN,SNAME,STATUS,CITY
  S1,Smith,20,Paris
  S2,Jones,10,Paris

.. csv-table::
  :header-rows: 1
  :class: substep  smallerelementwithfullborder

  SN,PN,qty
  S2,P1,20

.. code:: sql
  :class: substep

  {sx.sn, sy.sn as sn2} where sx.city = sy.city and
    sx.sn <> sy.sn and (exists spx(sx.sn = spx.sn))

.. csv-table::
  :header-rows: 1
  :class: substep  smallerelementwithfullborder

  sn,sn2
  s2,s1

.. code:: sql
  :class: substep

  {sx.sn, sy.sn as sn2} where sx.city = sy.city and
    sx.sn < sy.sn and exists spx(sx.sn = spx.sn)

.. csv-table::
  :header-rows: 1
  :class: substep  smallerelementwithfullborder

  sn,sn2
  ,

.. code:: sql
  :class: substep

  {sx.sn, sy.sn as sn2} where sx.city = sy.city and
   sx.sn < sy.sn and (exists spx(sx.sn = spx.sn) or
   exists spy(sy.sn = spy.sn))

.. csv-table::
  :header-rows: 1
  :class: substep  smallerelementwithfullborder

  sn,sn2
  s1,s2

.. code:: sql
  :class: substep

  {sx.sn, sy.sn as sn2} where sx.city = sy.city and
   sx.sn < sy.sn and exists spx(sx.sn = spx.sn or sy.sn = spx.sn)

----

:class: t2c

.. class:: rtl-h1

زوج شمارهٔ عرضه‌کنندگانی را بیابید که در یک شهر باشند و هر دو عرضه کننده، قطعه یا قطعه‌هایی را عرضه کرده باشند.

هر دو عرضه کرده باشند (راه حل اشتباه)

`.`

.. code:: sql
  :class: substep

  -- راه حل نادرست
  {sx.sn, sy.sn as sn2} where sx.city = sy.city and
   sx.sn < sy.sn and exists spx(sx.sn = spx.sn and sy.sn = spx.sn)

`.`

.. code:: sql
  :class: substep

  -- راه حل درست
  {sx.sn, sy.sn as sn2} where sx.city = sy.city and
   sx.sn < sy.sn and (exists spx(sx.sn = spx.sn) and
   exists spy(sy.sn = spy.sn))


`.`

.. code:: sql
  :class: substep

  -- راه حل درست
  {sx.sn, sy.sn as sn2} where sx.city = sy.city and
   sx.sn < sy.sn and (exists spx(sx.sn = spx.sn) and
   exists spx(sy.sn = spx.sn))

----

:class: t2c

.. class:: rtl-h1

نام عرضه‌کنندگانی را بیابید که همهٔ قطعه‌ها را عرضه کرده باشند(I).

.. code:: sql
  :class: substep

  -- نادرست
  sx.sname where forall spx(sx.sn=spx.sn)

.. code:: sql
  :class: substep

  -- نادرست
  sx.sname where forall spx(sx.sn != spx.sn)


.. code:: sql
  :class: substep

  sx.sname where forall px(

.. code:: sql
  :class: substep

  -- نادرست
  sx.sname where forall px(
    px.pn=spx.pn
  )  sx.sn=spx.sn


----

:class: t2c

.. class:: rtl-h1

نام عرضه‌کنندگانی را بیابید که همهٔ قطعه‌ها را عرضه کرده باشند(II).

.. code:: sql
  :class: substep

  sx.sname where forall px(
    exists spx(

.. code:: sql
  :class: substep

  sx.sname where forall px(
    exists spx(
      spx.pn=px.pn and


.. code:: sql
  :class: substep

  sx.sname where forall px(
    exists spx(
      spx.pn=px.pn and sx.sn=spx.sn
    )

.. code:: sql
  :class: substep

  sx.sname where not exists px(
    not exists spx(
      spx.pn=px.pn and sx.sn=spx.sn
    )
  )

.. code:: sql
  :class: substep

  sx.sname where forall px( -- ??
    not exists spx(
      spx.pn <> px.pn or sx.sn <> spx.sn
    )

.. code:: sql
  :class: substep

  -- نادرست
  sx.sname where forall px(
    sx.sn=spx.sn and
    exists spx( spx.pn=px.pn)
  )

.. code:: sql
  :class: substep

  -- نادرست
  sx.sname where exists spx(
    sx.sn=spx.sn and
    forall px(spx.pn=px.pn)
  )

.. code:: sql
  :class: substep

  -- نادرست
  sx.sname where forall spx(
    exists px(
      spx.pn=px.pn and sx.sn=spx.sn
    )

----

:class: t2c

.. class:: rtl-h1

شماره قطعاتی را بیابید که هیچ عرضه کننده‌ای آنها را عرضه نکرده باشد.

.. code:: sql
  :class: substep

  px.pn where not exists spx (spx.pn = px.pn)

.. code:: sql
  :class: substep

  px.pn where forall spx(spx.pn<>px.pn)

.. class:: rtl substep

دستورهای اضافی

.. code:: sql
  :class: substep

  px.pn where not exists sx(
    exists spx(spx.sn=sx.sn and spx.pn=px.pn)
  )



.. code:: sql
  :class: substep

  --     نادرست
  px.pn where exists spx(spx.pn<>px.pn)

  spx.pn where not exists spx(spx.pn<>spx.pn)

  spx.pn where not exists spy(spx.pn<>spy.pn)

  px.pn where not exists sx(exists spx(sx.sn=spx.sn))

----

:class: t2c

.. class:: rtl-h1

نام قطعاتی را بیابید که اگر عرضه‌کننده‌ای قطعهٔ p3 را عرضه کرده‌اند آن قطعه را نیز عرضه کرده باشند.

.. code:: sql
    :class: substep

     px.pname where not exists spx(
       spx.pn = 'p3' and not exists spy(
         spy.sn = spx.sn and spy.pn = px.pn
       )
    )

.. code:: sql
    :class: substep

    px.pname where forall spx(
      spx.pn <> 'p3' or exists spy(
        spy.sn = spx.sn and spy.pn = px.pn
      )
    )

.. class:: rtl-h2 substep

نام قطعاتی که برای‌شان وجود نداشته باشد عرضه‌ای که آن عرضه برای قطعهٔ p3 باشد و وجود نداشته باشد عرضهٔ دیگری از همان عرضه کننده که قطعهٔ آن همین قطعهٔ مورد نظر ما نباشد.

`.`

.. code:: sql
    :class: substep

    -- نادرست
    px.pname where forall spx(
      spx.pn = 'p3' or not exists spy(
        spy.sn = spx.sn and spy.pn = px.pn
      )
    )

----

:class: t2c

.. class:: rtl-h1

نام قطعاتی را بیابید که اگر عرضه‌کننده‌ای قطعهٔ p3 را عرضه کرده باشد آن قطعه را نیز عرضه کرده باشند. پاسخ‌های نادرست(I)

..  :

    نام قطعاتی را بیابید که اگر عرضه‌کننده‌ای قطعهٔ p3 را عرضه کرده باشد فقط آن قطعه را نیز عرضه کرده باشند. پاسخ‌های نادرست(I)


    نام قطعات عرضه شده‌ای را بیابید که همهٔ عرضه‌کنندگانِ آن قطعات قطعهٔ p3 را هم حتماً عرضه کرده‌اند و اگر هیچ عرضه‌ای از p3 نبود جواب باید خالی باشد. پاسخ‌های نادرست(I)


.. code:: sql
  :number-lines:

    px.pname where exists spx(
      spx.pn = 'p3' and
      exists spy( spy.pn = px.pn
        and spy.sn = spx.sn
      )
    )

.. code:: sql
  :number-lines:

    px.pname where forall spx(
      spx.pn='p3' and forall Spy(
        Spy.sn=Spx.sn and
        spy.pn <> 'p3' and exists px(
          px.pn=Spy.pn
        )
      )
    )

.. code:: sql
  :number-lines:

    px.pname where exists spx(
      Spx.pn='p3' and exists spy(
        spy.sn=Spx.sn and
        spy.pn<>'p3' and exists px(
          px.pn=spy.pn
        )
      )
    )

----

:class: t2c

.. class:: rtl-h1

نام قطعاتی را بیابید که اگر عرضه‌کننده‌ای قطعهٔ p3 را عرضه کرده‌اند آن قطعه را نیز عرضه کرده باشند. پاسخ‌های نادرست(II)

.. code:: sql
  :number-lines:

    px.pname where forall spx(
      spx.pn = 'p3' or exists spy(
        spy.sn = spx.sn and
        spy.pn = px.pn
      )
    )

.. code:: sql
  :number-lines:

    px.pname where forall spx(
      spx.pn = 'p3' and exists spy(
        spy.pn = spx.pn and
        spy.pn = px.pn
      )
    )

.. code:: sql
  :number-lines:

    px.pname where forall spx(
      spx.pn = 'p3' or exists spy(
        spy.pn = spx.pn and
        spy.sn = spx.sn
      )
    )

.. :

    ----

    .. class:: rtl-h1

        نام قطعاتی را بیابید که اگر عرضه‌کننده‌ای قطعهٔ p3 را عرضه کرده باشد آن قطعه را نیز عرضه کرده باشند. پاسخ‌های نادرست(I)


        نام قطعاتی را بیابید که اگر عرضه‌کننده‌ای قطعهٔ p3 را عرضه کرده باشد فقط آن قطعه را نیز عرضه کرده باشند. پاسخ‌های نادرست(I)


        نام قطعات عرضه شده‌ای را بیابید که همهٔ عرضه‌کنندگانِ آن قطعات قطعهٔ p3 را هم حتماً عرضه کرده‌اند و اگر هیچ عرضه‌ای از p3 نبود جواب باید خالی باشد. پاسخ‌های نادرست(I)


        نام قطعاتی را بیابید که فقط عرضه‌کنندگانی که قطعهٔ p3 را عرضه کرده‌اند آن قطعه را نیز عرضه کرده باشند.

----

:class: t2c

.. class:: rtl-h1

نام قطعاتی را بیابید که در همهٔ پروژه‌ها به کار گرفته شده باشند.


* S(sn_,sname,status,city) ,
* P(pn_,pname,color,weight,city) ,
* J(jn_,jname,budget,city)
* SPJ(sn_, pn_, jn_, qty)

.. container:: rtl-h2 substep

    نام قطعاتی را بیابید که برای همهٔ پروژه‌ها عرضه‌ای از آن قطعه وجود داشته باشد.

    نام قطعاتی را بیابید که پروژه‌ای وجود نداشته باشد که عرضه‌ای از آن قطعه برای آن پروژه وجود نداشته باشد.

.. code:: sql
    :class: substep
    :number-lines:

    px.pname where forall jx(
      exists spjx(
        spjx.jn = jx.jn and
        px.pn = spjx.pn
      )
    )

.. code:: sql
    :class: substep
    :number-lines:

    px.pname where not exists jx(
      not exist spjx(
        spjx.jn = jx.jn and
        px.pn = spjx.pn
      )
    )

.. code:: sql
    :class: substep
    :number-lines:

    px.pname where forall jx(
      exists spjx(
        spjx.jn = jx.jn and
        px.pn = spjx.pn
      )
    ) and exists spjx(
        spjx.px = px.pn
    )

----

:class: t2c

.. class:: rtl-h1

    نام قطعاتی را بیابید که فقط در یک پروژه به کار رفته باشند.

.. code:: sql
    :class: substep
    :number-lines:

    px.pname where exists jx(
      not exists spjx(
        spjx.jn = jx.jn and
        px.pn = spjx.pn
      )
    )

.. code:: sql
    :class: substep
    :number-lines:

    px.pname where exists spjx(
      px.pn = spjx.pn and not
      exists spjy(
        spjx.jn = spjy.jn
      )
    )

.. code:: sql
    :class: substep
    :number-lines:

    px.pname where exists spjx(
      px.pn = spjx.pn and not
      exists spjy(spjx.jn <> spjy.jn
        and spjy.pn = px.pn
      )
    )

----

:class: t2c

.. class:: rtl-h1

نام قطعاتی را بیابید که در همهٔ پروژه‌ها به کار گرفته شده باشند. پاسخ‌های نادرست

.. code:: sql
    :class: substep
    :number-lines:

    px.pname where forall spjx
    (spjx.pn = px.pn)

.. code:: sql
    :class: substep
    :number-lines:

    px.pname where forall spjx(
      exists (
        spjx.pn=px.pn and
        px.pn=spjx.pn
      )
    )

.. code:: sql
    :class: substep
    :number-lines:

    px.pname where not exists spjx(
      spjx.pn=px.pn and not exists
      spjy( spjy.pn=spjx.pn and
        spjy.pn=px.pn
      )
    )

.. code:: sql
    :class: substep
    :number-lines:

    px.pname where forall px(
      exists spj(spj.pn = px.pn)
    )

----

:class: t2c

.. class:: rtl-h1

    نام نویسندگانی را بیابید که همهٔ کتاب‌های‌شان را در این کتابخانه به امانت گرفته باشند.۱


* book( bn_ , title, category, fpd, author )
* member( mn_ , name , category, bn)
* borrow( bn_ , mn_ , nd , rdt, ret)

.. class:: rtl substep

      پاسخ‌های نادرست

.. code:: sql
    :class: substep
    :number-lines:

    bookx.author where forall bookx(
      exists borrowx(
        bookx.bn = borrowx.bn
      )
    )


.. code:: sql
    :class: substep
    :number-lines:

    bookx.author where not exists
    memberx(
      memberx.bn=bookx.bn and
      not exists borrowx(
        borrowx.bn=memberx.bn and
        borrowx.bn=bookx.bn
      )
    )

----

:class: t2c

.. class:: rtl-h1

    نام نویسندگانی را بیابید که همهٔ کتاب‌های‌شان را در این کتابخانه به امانت گرفته باشند.۲

.. code:: sql
    :class: substep

      -- پاسخ‌های نادرست
    bookx.author where forall booky(
      bookx.author=booky.author and
      exists borrowx(
        borrowx.bn=bookx.bn
      )
    )

.. class:: rtl-h2 substep

    پاسخ‌های درست

.. code:: sql
    :class: substep
    :number-lines:

    bookx.author where not exists booky(
      booky.author = bookx.author and
      not exists borrowx(
        borrowx.bn = booky.bn
      )
    )

.. code:: sql
    :class: substep
    :number-lines:

    bookx.author where forall booky(
      bookx.author <> booky.author or
      exists borrowx(
        borrowx.bn = booky.bn
      )
    )

----

References
==============
* .. [abs.gov.au] https://www.abs.gov.au/websitedbs/a3121120.nsf/home/statistical+language+-+quantitative+and+qualitative+data
* .. [questionpro] https://www.questionpro.com/blog/quantitative-data/

*  https://www.ntu.edu.sg/home/ehchua/programming/sql/Relational_Database_Design.html
*  https://dev.to/lmolivera/everything-you-need-to-know-about-relational-databases-3ejl
*  https://relational.fit.cvut.cz
*  https://dzone.com/refcardz/from-relational-to-graph-a-developers-guide?chapter=1
*  https://www.ibm.com/support/knowledgecenter/zh/SSWU4L/Data/imc_Data/Data_q_a_watson_assistant/Relational_Tables371.html
*  https://vincentarelbundock.github.io/Rdatasets/datasets.html
*  https://docs.oracle.com/cd/E15276_01/doc.20/e13677/dialogs_data_modeling.htm
*  http://www.acc.umu.se/~cthulhu/postgreSQL/tutorial/sql608.htm
*  https://fmhelp.filemaker.com/help/18/fmp/en/index.html#page/FMP_Help/planning-databases.html
*  https://en.wikipedia.org/wiki/Relational_database
*  https://web.csulb.edu/colleges/coe/cecs/dbdesign/dbdesign.php?page=manymany.php
*  `A video of C.J.Date <https://www.youtube.com/watch?v=qx0F7TfA8CI>`_

----

END
======

.. ::

    زوج شمارهٔ عرضه‌کنندگانی را بیابید که در یک شهر باشند و دست کم یکی از آن دو عرضه کننده، قطعه یا قطعه‌هایی عرضه کرده باشند.
    {sx.sn as sn1 , sy.sn as sn2} where sx.city = sy.city and sx.sn < sy.sn and ( exists spx( sx.sn = spx.sn ) or exists spy( sy.sn = spy.sn))

    شکل نادرست پاسخ
    {sx.sn as sn1 , sy.sn as sn2} where sx.city = sy.city and sx.sn < sy.sn and ( exists spx( spx.sn=sx.sn or spx.sn=sy.sn) )

    نام عرضه‌کنندگانی را بیابید که دست کم یک قطعهٔ قرمز عرضه کرده باشند.
    sx.sname where exists spx( sx.sn = spx.sn and exists px( px.pn = spx.pn and px.color = 'red’)

    زوج شمارهٔ عرضه‌کنندگانی را بیابید که در یک شهر باشند و قطعه یا قطعه‌هایی عرضه کرده باشند.
    {sx.sn as sn1 , sy.sn as sn2} where sx.city = sy.city and sx.sn < sy.sn and exists spx( sx.sn = spx.sn ) and exists spy( sy.sn = spy.sn)

    {sx.sn as sn1 , sy.sn as sn2} where sx.city = sy.city and sx.sn < sy.sn and exists spx( sx.sn = spx.sn and exists spy( sy.sn = spy.sn) )

    زوج شمارهٔ عرضه‌کنندگانی را بیابید که در یک شهر باشند.
    {sx.sn as sn1 , sy.sn as sn2} where sx.city = sy.city and sx.sn < sy.sn

    (p1, p2)
    (p2, p1)

    نام شهرهای عرضه‌کنندگانی را بیابید که قطعهٔ با شمارهٔ p2 را عرضه کرده باشند.

    sx.city where exists spx ( spx.sn = sx.sn and spx.pn = 'p2’)



    Relational Calculus
    حساب رابطه‌ای

    ranageover sx over s
    ranageover sy over s
    ranageover sz over s

    ranageover px over p
    ranageover py over p
    ranageover pz over p

    ranageover spx over sp
    ranageover spy over sp
    ranageover spz over sp

    sm

    sx.sname
    px.pname

    sx.sname where sx.status > 10
    px.pname, px.pn where p.weight > 20

    px.pname where px.weight > 12 and color = 'red’

    px.pname where exists spx ( spx.sn = px.pn )

    نام شهرهای عرضه‌کنندگانی را بیابید که قطعهٔ با شمارهٔ p2 را عرضه کرده باشند.

    sx.city where exists spx ( spx.sn = sx.sn and spx.pn = 'p2’


    { px ∈ P | px.city = 'kashan'}
    ∀ forall
    ∃ exists
    ∀ a, b ∈ R | a+b = b + a
    ∃ a ∈ R ,  ∀ b ∈ R | a * b  = b
    a = 1

    ∀x p(x) == ~∃x ~p(x)


..  _شماره جنس:  #

..  _شماره فاکتور فروش: #

..  _نام خریدار: #

.. _product_id:
.. _product_name:
.. _stock:
.. _quantity:
.. _customer_id:
.. _customer_name:
.. _sn:
.. _pn:
.. _jn:
.. _bn:
.. _mn:
.. _ddt:
.. _isbn:
.. _SSN:
.. _DN:
.. _DeptName:
.. _ProjName:
.. _en:


.. _ID:
.. _dept_name:
.. _course_id:
.. _building:
.. _room_number:
.. _sec_id:
.. _semester:
.. _year:
.. _s_ID:
.. _i_ID:
.. _time_slot_id:
.. _day:
.. _start_time:
.. _prereq_id:


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




    نام قطعاتی را بیابید که دست کم یک عرضه کننده از عرضه‌کنندگانی که قطعهٔ p3 را عرضه کرده‌اند آن قطعه را نیز عرضه کرده باشند.

    px.pname where exists spx (spx.pn = px.pn and exists spy( spy.pn = 'p3’ and spy.sn = spx.sn)

    نام عرضه‌کنندگانی را بیابید که قطعهٔ p2 را عرضه نکرده باشند.

    sx.sname where not exists spx ( spx.sn = sx.sn and spx.pn = 'p2’)

    sx.sname where not exists spx(sx.sn=spx.sn and exists px( Spx.pn=px.pn And px.pn="p2"))

    شماره قطعاتی را بیابید که هیچ عرضه کننده‌ای عرضه نکرده باشد.

    px.pn where not exists spx (spx.pn = px.pn)

    شمارهٔ قطعاتی را بیابید که همهٔ عرضه کنندگان آنها را عرضه کرده باشند.

    px.pn where forall sx ( exists spx(spx.sn = sx.sn and spx.pn = px.pn))

    px where not exists sx ( not exists spx(spx.sn = sx.sn and spx.pn = px.pn))
    جواب نادرست است
    px.pn where not exists spx(spx.pn = px.pn and not exists sx(sx.sn = spx.sn))

    عرضه‌کنندگانی را بیابید که همهٔ قطعه‌ها را عرضه کرده باشند.
    sx where forall px ( exists spx (spx.pn = px.pn and sx.sn = spx.sn) )


    sx where not exists px ( not exists spx (spx.pn = px.pn and sx.sn = spx.sn) )

    ∀x p(x) == ~∃x ~p(x)


    نام عرضه‌کنندگانی را بیابید که همهٔ قطعه‌ها را عرضه کرده باشند.
    sx.sname where forall px ( exists spx (spx.pn = px.pn and sx.sn = spx.sn)


    sx.sname where not exists px ( not exists spx (spx.pn = px.pn and sx.sn = spx.sn)


    زوج شمارهٔ عرضه‌کنندگانی را بیابید که در یک شهر باشند و دست کم یکی از آن دو عرضه کننده، قطعه یا قطعه‌هایی عرضه کرده باشند.
    {sx.sn as sn1 , sy.sn as sn2} where sx.city = sy.city and sx.sn < sy.sn and ( exists spx( sx.sn = spx.sn ) or exists spy( sy.sn = spy.sn))

    شکل نادرست پاسخ
    {sx.sn as sn1 , sy.sn as sn2} where sx.city = sy.city and sx.sn < sy.sn and ( exists spx( spx.sn=sx.sn or spx.sn=sy.sn) )

    نام عرضه‌کنندگانی را بیابید که دست کم یک قطعهٔ قرمز عرضه کرده باشند.
    sx.sname where exists spx( sx.sn = spx.sn and exists px( px.pn = spx.pn and px.color = 'red’)

    زوج شمارهٔ عرضه‌کنندگانی را بیابید که در یک شهر باشند و قطعه یا قطعه‌هایی عرضه کرده باشند.
    {sx.sn as sn1 , sy.sn as sn2} where sx.city = sy.city and sx.sn < sy.sn and exists spx( sx.sn = spx.sn ) and exists spy( sy.sn = spy.sn)

    {sx.sn as sn1 , sy.sn as sn2} where sx.city = sy.city and sx.sn < sy.sn and exists spx( sx.sn = spx.sn and exists spy( sy.sn = spy.sn) )

    زوج شمارهٔ عرضه‌کنندگانی را بیابید که در یک شهر باشند.
    {sx.sn as sn1 , sy.sn as sn2} where sx.city = sy.city and sx.sn < sy.sn

    (p1, p2)
    (p2, p1)

    نام شهرهای عرضه‌کنندگانی را بیابید که قطعهٔ با شمارهٔ p2 را عرضه کرده باشند.

    sx.city where exists spx ( spx.sn = sx.sn and spx.pn = 'p2’)



    sx.sname where sx.status > 10
    px.pname, px.pn where p.weight > 20

    px.pname where px.weight > 12 and color = 'red’

    px.pname where exists spx ( spx.sn = px.pn )

    نام شهرهای عرضه‌کنندگانی را بیابید که قطعهٔ با شمارهٔ p2 را عرضه کرده باشند.

    sx.city where exists spx ( spx.sn = sx.sn and spx.pn = 'p2’


    { px ∈ P | px.city = 'kashan'}
    ∀ forall
    ∃ exists
    ∀ a, b ∈ R | a+b = b + a
    ∃ a ∈ R ,  ∀ b ∈ R | a * b  = b
    a = 1

    ∀x p(x) == ~∃x ~p(x)


    create table student {
     “شماره دانشجویی"   varchar(20) primary key,
    “نام"   varchar(20),
    “نام خانوادگی"  varchar(20),
    “استان"  varchar(20),
    "شهر”  varchar(20),
    “خیابان" varchar(20),
    “کوچه"  varchar(20) not null,
    “پلاک"    varchar(20),
    “کدپستی" varchar(20) not null
    )



    null

    “null”
    0

    Data Sub Language (DSL) -- SQL , Relational Algebra,


    DSL:
    DDL (Data Definition Language)
    DML (Data Manipulation Language)
    DCL (Data Control Language)

    instructor where not (dept_name = "Physics" and salary > 1000)
    >=
    <=
    /=
    <>
    !=

    Instructor {id, name, salary}

    (s times { sp rename s# as sn}) where sn = s#
    s join sp

    (( s rename city as scity) times p) where city = city

    s join p
    city

    s join (p rename city as pcity}
    s times p


    S {s#}
    P {p#}
    Sp  {s#, p#}

      * P(pn_, pname, color, weight, city)
      * S(sn_, sname, status, city)
      * SP(sn_, pn_, qty)
    {sn}
    {pn}
    دانشجو
    شمارهٔ دانشجویی
    نام
    نام خانوادگی
    نام پدر
    نشانی
    شمارهٔ ملی

    ابرکلیدها
    {شماره دانشجویی} کلید نامزد - کلید اصلی - قید جامعیت، شرط یکپارچگی  Integrity Constraint در اینجا الزام به وجود مقدار برای کلید اصلی برای چندتایی‌های موجود
    {شماره دانشجویی، نام}
    {شماره دانشجویی، نام خانوادگی}
    ….
    {نام، نام خانوادگی، نام پدر، شماره ملی}
    {شمارهٔ ملی} کلید نامزد
    {شمارهٔ ملی، شماره دانشجویی} کلید نامزد نیست*

    درس
    {شمارهٔ درس} کلید اصلی
    نام درس

    درس-دانشجو
    {شمارهٔ دانشجویی، شمارهٔ درس} کلید اصلی
    نمره نهایی

    فیلد یا ویژگی اضافی گذاشتید که یکتا باشد و کلید اصلی قرار بدهید اشتباه بزرگی است.




    بیمارستان:
    پرسنل:
    نام - فامیل - کد ملی - ...
    نوع(دکتر - پرستار - تمیزکار - ...)
    درآمد

    اتاق:
    کد
    نوع(اتاق عمل - بستری - ...)
    در حال استفاده است یا خیر
    کد شخص که استفاده میکند دکتر یا بیمار

    بیماران:
    نام - فامیل - کد ملی - ...
     تعداد روز بستری
    وضعیت
    امضا بیمار یا همراهان


    امور مالی:
    نوع (واریز - پرداخت)
    کد گیرنده
    کد فرستنده
    کد پیگیری پرداخت
    موضوع
    توضیحات


    عملیات ها:
    نوع(بستری شدن-مرخص شدن - عمل شدن)
    کد بیمار
    کد دکتر مربوطه
    تاریخ و ساعت




    امیر حسین موسوی
    می توان یک جدول اطلاعات تکمیلی برای بیمار در نظر گرفت که هر کدام از ردیف های آن مربوط به یک بیمار باشد و چنین اطلاعاتی مانند اطلاعات تکمیلی را در آن ذخیره کرد




    Product Table: (product_id, product_name, stock,Product_ Price,Product_category)

       Customer Table: ( customer_id, customer_name,Customer_Age,Customer_Phone_Number,Customer_Date_of_Birth )


      Sales Table: ( product_id, customer_id , quantity,Total_price,List_Number)
    factors(Sells_factors,buy_factors)

    تامین_کننده(نام_شرکت،شماره_تماس، ادرس)
    محصولات_خریداری شده(نام تامین کننده، تعداد)



    book_id
    -----------
    book name
    book writer
    count
    category id

    member_id
    --------------
    member name
    member date joined
    member expire date

    category_id
    ----------
    category name

    Receipt_id
    --------------
    member id
    book id

    users(user_num,username,password);
    users_info(user_num,name,phone,Email,address);
    users_finance(user_num,account_num,bank,cash,debt);
    project_registered(project_num,buyer_num,field_num,cost,date);
    project_in_progress(project_num,freelancer_num,cost,finish_date);
    project_finished(project_num,date,cost);
    factor(project_num,user_num,date,amount);
    deposit(user_num,date,amount);

    محبی‌نیا
    محصول : ای دی - رنگ - جنس - اسم - موجودی -

    مشتری : ای دی - نام - ایمیل - آدرس

    فروش : ای دی - ای دی مشتری - تعداد - تاریخ فروش - پیشنهاد تخفیف ها

    فیلد های ابی در اصل باعث راحتی در جست و جو محصولات و مشتری ها می شوند و سر ستون ما هستند.


    رحمانی
     پایانه مسافربری

    جدول اتوبوس ( آیدی اتوبوس ، آیدی راننده ، مدل اتوبوس ، تعداد صندلی )

    جدول راننده ( آیدی راننده ، نام راننده ، شماره تلفن راننده )

    جدول مسافر ( آیدی مسافر ، نام مسافر ، شماره ملی مسافر ، شماره تلفن مسافر )

    جدول صندلی (آیدی صندلی ،  مدل صندلی(vip,تاشو،معمولی)  ، شماره صندلی )

    جدول بلیط ( آیدی اتوبوس ، آیدی مسافر ، مبدا ، مقصد ، زمان حرکت ، قیمت ، آیدی  صندلی ، آیدی مسئول )

    جدول مسئول فروش بلیط ( آیدی مسئول ، نام مسئول ، شماره تلفن مسئول )

    جدول ورود و خروج ( آیدی اتوبوس ، زمان خروج ، مقصد ، زمان ورود)



    انتشارات:اسم انشارات , ایدی انتشارات
    ژانر:ایدی ژانر , نام ژانر ,ژانر های مرتبط
    کتاب:ایدی کتاب, موضوع , تعداد صفحات , زمان انتشار ,ایدی انشارات ,درجه سنی ,ژانر ,نام نویسنده
    نویسنده: ایدی نویسنده,نام  ,نام خانوادگی
    نمونه پایگاه داده ارتباط میان نویسنده و کتاب با انتشارات ازین اطلاعات میتوان برای دسته بندی راحت تره نویسنده ها و کتاب ها برای انتشارات استفاده کرد.



    پایگاه داده مربوط به تاکسی تلفنی:
    صاحب خودرو:نام و نام خانوادگی ،ادرس،کد ملی،شماره موبایل
    خودرو:پلاک،صاحب خودرو،نوع خودرو،رنگ ،کد خودرو در اژانس
    سرویس دهی:کد خودرو ،کد مشتری،هزینه ،کد سرویس ،تاریخ
    مشتری:نام و نام خانوادگی،ادرس،کد مشتری،ساعت


    Schema
    Table Schema

    Database Schema


    s + b + c * d


    rst2html.py relational_algebra.rst relational_algebra.html --stylesheet=style.css,html4css1.css
