:data-transition-duration: 1000
:data-max-scale: 5
:data-width: 1024 
:data-height: 768
:skip-help: true
:css: ./style.css
:substep: true
:slide-numbers: true

.. :

  :js: ./temporary03454-images9877/tex-mml-chtml.js

----

LL
==============================
Syntax Analysis(LL)
----------------------
Ahmad Yoosofan

Compiler course

University of Kashan

https://yoosofan.github.io/course/compiler.html

----

:class: t2c

Reduce Function Calls
==========================================
#. A → a B
#. B → b A
#. B → a

.. container:: substep

  * a a

  .. class:: substep

  #. A
  #. ⇒ a B
  #. ⇒ a a

.. container:: substep

  * a a $

  .. class:: substep

  #. A $
  #. ⇒ a B $
  #. ⇒ a a $

.. container:: substep

  * a b a a $

  .. class:: substep

  #. A $  ⇒ a B $
  #. ⇒ a B $ ⇒ a b A $
  #. ⇒ a b a B $  ⇒ a b a a $

.. container:: substep

  * a a $

  .. class:: substep

  #. A $ [ a a $]
  #. ⇒ a B $ [a a $]
  #. ⇒ B $ [a $]
  #. ⇒ B $ [a $]
  #. ⇒ a $ [a $]
  #. ⇒  $ [ $]

.. container:: substep

  * a b a a $

  .. class:: substep

  #. A $ [abaa$]
  #. a B $,  [abaa$]
  #. B $,  [baa$]
  #. b A $ , [baa$]
  #. A $, [aa$]
  #. a B $, [aa$]
  #. B $, [a$]
  #. a $, [a$]
  #. $, [$]

----

:class: t2c

First sets
==========================================
.. container::

  #. A → a B
  #. B → b A
  #. B → a

  .. class:: substep

  #. first( A ) = {a}
  #. first( B ) = {a , b}

.. csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder equal-col

  "  ",   a  , b     , $
  A   , A → a B ,       ,
  B   , B → a   , B → b A  ,

.. csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder equal-col

  "  ",   a  , b     , $
  A   , a B ,       ,
  B   , a   , b A  ,

.. csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder equal-col

  "  ",   a  , b     , $
  A   , 1 ,       ,
  B   , 3   , 2  ,

----

:class: t2c

Parsing(I)
==========================================
.. container::

  #. A → a B
  #. B → b A
  #. B → a

  * first( A ) = {a}
  * first( B ) = {a , b}

  .. csv-table::
    :header-rows: 1
    :class: smallerelementwithfullborder equal-col

    "  ",   a  , b     , $
    A   ,  a B ,       ,
    B   ,  a   ,  b A  ,

.. container:: substep

  * a a $

  #. A $
  #. ⇒ a B $
  #. ⇒ a a $

  .. class:: substep

  #. .a a $ [ A $ ]
  #. .a a $ [ a B $ ]
  #. .a $ [ B $ ]
  #. .a $ [ a $ ]
  #. .$ [ $ ]
  #. accept

----

:class: t2c

Parsing(II)
==========================================
.. container::

  #. A → a B
  #. B → b A
  #. B → a

  * first( A ) = {a}
  * first( B ) = {a , b}

.. csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder equal-col

  "  ",   a  , b     , $
  A   ,  a B ,       ,
  B   ,  a   ,  b A  ,

.. container:: substep

  * a b a a $

  .. class:: substep

  #. A $
  #. ⇒ a B $
  #. ⇒ a B $
  #. ⇒ a b A $
  #. ⇒ a b a B $
  #. ⇒ a b a a $

.. class:: substep

#. .a b a a $ [ A $ ]
#. .a b a a $ [ a B $ ]
#. .b a a $ [ B $ ]
#. .b a a $ [ b A $ ]
#. .a a $ [ A $ ]
#. .a a $ [ a B $ ]
#. .a $ [ B $ ]
#. .a $ [ a $ ]
#. .$ [ $ ]
#. accept

.. :

  A →  a B
  B →  b A
  B →  a
  B →  b
  
  
  
  Left factoring
  A →  a B
  B →  a

  B →  b A
  B →  b

  Left factoring
  A →  a B
  B →  a

  B →  b L
  L →  A
  L →  λ 

  Left factoring
  A →  a B
  B →  a
  B →  b L
  L →  A
  L →  λ 

  first(A) = {a}
  first(B) = {a, b}
  first(L) = {a, λ}

----

:class: t2c

Parsing(III)
==========================================
.. container::

  #. A → a B
  #. B → b A
  #. B → a

  * first( A ) = {a}
  * first( B ) = {a , b}

.. csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder equal-col

  "  ",   a  , b     , $
  A   ,  a B ,       ,
  B   ,  a   ,  b A  ,

#. A $
#. ⇒ a B $
#. ⇒ a b A $
#. ⇒ a b a B $
#. ⇒ a b a a $

.. csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder equal-col

  Stack  ,  input        , action
   $ A   ,   a b a a $   , A → a B
   $ B a ,   a b a a $   , Remove a
   $ B   ,   b a a $     , B → b A
   $ A b ,   b a a $     , Remove b
   $ A   ,     a a $     , A → a B
   $ B a ,     a a $     , Remove a
   $ B   ,     a $       , B → a
   $ a   ,     a $       , Remove a
   $     ,       $       , accept

----

:class: t2c

Parsing(IV)
==========================================
.. csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder equal-col

  "  ",   a  , b     , $
  A   ,  a B ,       ,
  B   ,  a   ,  b A  ,

.. csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder equal-col

  Stack ,  input        , action
   A  $ ,   b $   , Reject

.. csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder equal-col

  Stack  ,  input        , action
   A $   ,  a b a b $    ,  A → a B
   a B $ ,  a b a b $    , Remove a
   B $   ,   b a b $     , B → b A
   b A$  ,   b a b $     , Remove b
   A$    ,     a b $     ,  A → a B
   a B$  ,     a b $     ,  Remove a
   B$    ,      b $      ,  B → b A
   bA$   ,      b $      ,  Remove b
   A$    ,      $        ,  Reject

.. csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder equal-col

  Stack  ,  input        , action
   A $   ,  a b b b $    ,  A → a B
   a B $ ,  a b b b $    , Remove a
   B $   ,   b b b $     , B → b A
   b A$  ,   b b b $     , Remove b
   A$    ,     b b $     ,  Reject

----

:class: t2c

Parsing(V)
==========================================
.. container::

  #. A → a B
  #. B → b A
  #. B →  λ

  .. class:: substep

    first

    * first( A ) = {a}
    * first( B ) = {b , λ}

.. csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder equal-col

  "  ",   a  , b     , $
  A   ,  a B ,       ,
  B   ,      ,  b A  ,

.. csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder equal-col

  Stack ,  input        , action
  A   $ ,   a b a $    , A → a B
  a B $ ,   a b a  $   , Remove a
  B   $ ,   b a  $     , B → b A
  b A $ ,   b a  $     , Remove b
  A   $ ,     a  $     , A → a B
  a B $ ,     a  $     , Remove a
  B   $ ,      $       , B → λ
      $ ,      $       , accept

.. csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder equal-col

  "  ",   a  , b     , $
  A   ,  a B ,       ,
  B   ,      ,  b A  ,  λ

----

:class: t2c

Parsing(VI)
==========================================
.. container::

  #. A → a B
  #. B → b A
  #. B →  λ

  * first( A ) = {a}
  * first( B ) = {b , λ}

.. csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder equal-col

  "  ",   a  , b     , $
  A   ,  a B ,       ,
  B   ,   λ  ,  b A  , λ

.. csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder equal-col

  Stack , input   , action
  A   $ , a a $ , A → a B
  a B $ , a a $ , Remove a
  B   $ , a   $ , B → λ
      $ , a   $ , Reject

.. class:: substep

* B → λ was wrong
* Removing B → λ from a is better
* Finding more rules in future (follow set)

.. csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder equal-col

  "  ",   a  , b     , $
  A   ,  a B ,       ,
  B   ,      ,  b A  ,  λ

.. csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder equal-col

  Stack , input   , action
  A   $ , a a $ , A → a B
  a B $ , a a $ , Remove a
  B   $ , a   $ , Reject

----

:class: t2c

Parsing(VII)
==========================================
.. container::

  #. A → a B
  #. B → b A
  #. B →  λ

  * first( A ) = {a}
  * first( B ) = {b , λ}

  #. follow( A ) = {$}
  #. follow( B ) = {$}

.. csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder equal-col

  "  ",   a  , b     , $
  A   ,  a B ,       ,
  B   ,      ,  b A  , λ

.. csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder equal-col

  Stack , input   , action
  A   $ , a a $ , A → a B
  a B $ , a a $ , Remove a
  B   $ , a   $ , Reject

----

:class: t2c

Wrong Calculator Grammar(I)
==========================================
.. container::

  #. E → T + E | T
  #. T → F * T | F
  #. F → ( E ) | a

  Some text books use *id* instead of *a*

.. container:: substep

  Remove Left Factor

  .. class:: substep

  #. E  → T E'
  #. E' → + E | λ
  #. T  → F T'
  #. T' → * T |  λ
  #. F  → ( E ) |  a

.. class:: substep

#. first(E)
#. = first(T)=first(F)
#. = { a, ( }
#. first(E') = { + ,  λ}
#. first(T') = { * ,  λ}

.. csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder equal-col

  " ",   a  ,  `+`     ,   `*`   ,   (    ,   )    ,   $
  E  , T E' ,          ,         ,  T E'  ,        ,
  E' ,      ,  `+` E   ,         ,        ,        ,
  T  , F T' ,          ,         ,  F T'  ,        ,
  T' ,      ,          , `*` T   ,        ,        ,
  F  ,   a  ,          ,         , ( E )  ,        ,

----

:class: t2c

Adding λ to table
==========================================
#. E → T + E | T
#. T → F * T | F
#. F → ( E ) | a

.. container::

  Remove Left Factor

  #. E  → T E'
  #. E' → + E | λ
  #. T  → F T'
  #. T' → * T |  λ
  #. F  → ( E ) |  a

#. first(E)
#. = first(T)=first(F)
#. = { a, ( }
#. first(E') = { + ,  λ}
#. first(T') = { * ,  λ}
#. first(F)  = { a , ( }

.. csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder equal-col

  " ",   a  ,  `+`     ,   `*`   ,   (    ,   )    ,   $
  E  , T E' ,          ,         , T E'   ,        ,
  E' ,  λ   ,  `+` E   ,    λ    ,    λ   ,   λ    ,  λ
  T  , F T' ,          ,         , F T'   ,        ,
  T' ,  λ   ,   λ      , `*` T ,     λ  ,  λ     , λ
  F  ,   a  ,          ,         , ( E )  ,        ,

----

:class: t2c

Wrong Calculator Grammar(II)
==========================================
.. container::

  #. E  → T E'
  #. E' → + E 
  #. E' → λ
  #. T  → F T'
  #. T' → * T
  #. T' → λ
  #. F  → ( E )
  #. F  →  a

  * first(E) = first(T) = first(F) = { a, ( }
  * first(E')  = { + ,  λ }
  * first(T')  = { * ,  λ }
  * follow(E)  = { $ , ) }
  * follow(E') = { $ , ) }
  * follow(T)  = { + , $ , ) }
  * follow(T') = { + , $ , ) }
  * follow(F)  = { * , + , $ , ) }

  .. csv-table::
    :header-rows: 1
    :class: substep smallerelementwithfullborder equal-col

    " ",   a  ,  `+`     ,   `*`   ,   (    ,   )    , $
    E  , T E' ,          ,         ,  T E'  ,        ,
    E' ,      ,  `+` E   ,         ,        ,    λ   , λ
    T  , F T' ,          ,         ,  F T'  ,        ,
    T' ,      ,    λ     , `*` T   ,        ,    λ   , λ
    F  ,   a  ,          ,         , ( E )  ,        ,

.. csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder equal-col

  Stack       ,  input      , action
  E           $ , a + a * a $ , E → T E'
  T E'        $ , a + a * a $ , T → F T'
  F T' E'     $ , a + a * a $ , F → a
  a T' E'     $ , a + a * a $ , Remove a
  T' E'       $ , `+` a * a $ , T' → λ
  E'          $ , `+` a * a $ , E' → + E
  `+` E       $ , `+` a * a $ , Remove +
  E           $ , a * a     $ , E → T E'
  T E'        $ , a * a     $ , T → F T'
  F T' E'     $ , a * a     $ , F → a
  a T' E'     $ , a * a     $ , Remove a
  T' E'       $ , `*` a       $ , T' → * T 
  `*` T E'      $ , `*` a       $ , Remove * 
  T  E'       $ , a         $ , T → F T' 
  F T'  E'    $ , a         $ , F → a
  a T' E'     $ , a         $ , Remove a
  T' E'       $ ,           $ , T' → λ
  E'          $ ,           $ , E' → λ
              $ ,           $ , accept

----

First set
==========================
.. class:: substep

#. If X → λ is a production rule then λ ∈ first(X)
#. If :math:`X → Y_1 Y_2 .... Y_n` is a production rule then
    #. first(:math:`Y_1`) ⊂ first(X)
    #. first(:math:`Y_2`) ⊂ first(X) if λ ∈ first(:math:`Y_1`) or :math:`Y_1 ⇒^* λ` 
    #. first(:math:`Y_3`) ⊂ first(X) if λ ∈ first(:math:`Y_1`) and λ ∈ first(:math:`Y_2`) 
    #. first(:math:`Y_i`) ⊂ first(X) if λ ∈ first(:math:`Y_j`) for j = 1, 2, 3, i-1 
    #. λ ∈ first(X) if λ ∈ first(:math:`Y_i`) for i = 1, 2, 3, n or :math:`X ⇒^* λ` 

----

Follow set
===============
.. class:: substep

#. If S is start symbol then $ ∈ follow(S)
#. If X → α Y then follow(X) ⊂ follow(Y)
#. If X → :math:`Y_1 Y_2 Y_3 Y_4 ..... Y_n` is a production rule then
    #. (first(:math:`Y_3`) - {λ} ) ⊂ follow(:math:`Y_2`)
        * if M → α A a β is a production rule then a ∈ follow(A)   
    #. If λ ∈ first(:math:`Y_3`) then (first(:math:`Y_4`) - {λ} ) ⊂ follow(:math:`Y_2`)
        * or (first(:math:`Y_3`) ∪ first(:math:`Y_4`) - {λ} ) ⊂ follow(:math:`Y_2`)
    #. If λ ∈ first(:math:`Y_j`) for j = 3,4, ....., i-1  then (first(:math:`Y_i`) - {λ} ) ⊂ follow(:math:`Y_2`)
    #. If λ ∈ first(:math:`Y_j`) for j = 3,4, ....., n then follow(X) ⊂ follow(:math:`Y_2`)

----

:class: t2c

Wrong Calculator Grammar(I)
==========================================
.. container::

  #. E → T + E | T
  #. T → F * T | F
  #. F → ( E ) | a

  Remove Left Factor

  #. E  → T E'
  #. E' → + E | λ
  #. T  → F T'
  #. T' → * T |  λ
  #. F  → ( E ) |  a

.. container::

    #. first(E)
    #.  = first(T)=first(F)
    #. = { a, ( }
    #. first(E') = { + ,  λ}
    #. first(T') = { * ,  λ}
    
----

:class: t2c

Follow set(II)
===============
#. If [ S ] is start symbol then [ $ ∈ follow(S) ]
#. If [ X → α Y ] then [ follow(X) ⊂ follow(Y) ]
#. If [ X → :math:`Y_1 Y_2 Y_3 Y_4 ..... Y_n` ] is a production rule then
    #. [ (first(:math:`Y_3`) - {λ} ) ⊂ follow(:math:`Y_2`) ]
    #. If [ λ ∈ first(:math:`Y_3`) ] then [ (first(:math:`Y_4`) - {λ} ) ⊂ follow(:math:`Y_2`) ]
    #. If [ λ ∈ first(:math:`Y_j`) for j = 3,4, ....., i-1 ] then [ (first(:math:`Y_i`) - {λ} ) ⊂ follow(:math:`Y_2`) ]
    #. If [ λ ∈ first(:math:`Y_j`) for j = 3,4, ....., n ] then [ follow(X) ⊂ follow(:math:`Y_2`) ]

.. container::

  Production Rules

  #. E  → T E'
  #. E' → + E
  #. E' → λ
  #. T  → F T'
  #. T' → * T 
  #. T' → λ
  #. F  → ( E )
  #. F  → a

.. container:: substep

    Follow sets

    .. class:: substep

    * follow(E) = { $ , ) }
    * follow(E')= { $ , ) }
    * follow(T) = { + , $, ) }
    * follow(T')= { + , $, ) }
    * follow(F) = { * , +, $, ) }

----

:class: t2c

Using Follow set(I)
=====================
* follow(E) = { $ , ) }
* follow(E')= { $ , ) }
* follow(T) = { + , $, ) }
* follow(T')= { + , $, ) }
* follow(F) = { * , +, $, ) }

.. csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder equal-col

  " ",   a  ,  `+`     ,   `*`   ,   (    ,   )    ,   $
  E  , T E' ,          ,         ,  T E'  ,        ,
  E' ,      ,  `+` E   ,         ,        ,        ,
  T  , F T' ,          ,         ,  F T'  ,        ,
  T' ,      ,          , `*` T   ,        ,        ,
  F  ,   a  ,          ,         , ( E )  ,        ,

.. csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder equal-col

  " ",   a  ,  `+`     ,   `*`   ,   (    ,   )    ,   $
  E  , T E' ,          ,         ,  T E'  ,        ,
  E' ,      ,  `+` E   ,         ,        ,    λ   ,   λ
  T  , F T' ,          ,         ,  F T'  ,        ,
  T' ,      ,   λ      , `*` T   ,        ,    λ   ,   λ
  F  ,   a  ,          ,         , ( E )  ,        ,

.. csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder equal-col

  Stack   ,  input        , action
  E      $,   a + a $     , E → F T'
  F T'   $,   a + a $     , F → a
  a T'   $,   b a a $     , B → b A
  b A    $,   b a a $     , Remove b
  A      $,     a a $     , A → a B
  a B    $,     a a $     , Remove a
  B      $,     a $       , B → a
   a     $,     a $       , Remove a
         $,       $       , accept

----

:class: t2c

Simple Calculator(I)
==========================================
#. E → E + T
#. E → E - T
#. E → T
#. T → T * F
#. T → T / F 
#. T → F
#. F → a
#. F → (E)

.. class:: substep

  #. first(E) 
  #. = First(T)
  #. = first(F)
  #. = { a , ( }


.. class:: substep

  #. follow(E) = { $ , + , - , ) }
  #. follow(T) = { $ , + , - , ) , * , / } 
  #. follow(F) = { $ , + , - , ) , * , / } 

.. csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder equal-col

  "  ", a                  , `+` , `-` , `*` , `/` ,      (              , ) , $
  E   , E + T | E - T | T  ,     ,     ,     ,     ,   E + T | E - T | T ,   ,
  T   , T * F | T / F | F  ,     ,     ,     ,     , T * F | T / F | F   ,   ,
  F   , a                  ,     ,     ,     ,     , ( E )               ,   ,

----

:class: t2c

Simple Calculator(I)
==========================================
.. container::

  #. E → E + T | E - T | T
  #. T → T * F | T / F | F
  #. F → a | (E)

  Convert to

  #. E  → T E'
  #. E' → + T E' | - T E' | λ
  #. T  → F T'
  #. T'  → * F T' | / F T' | λ
  #. F → a | (E)

.. class:: substep

#. First(E)
    #. = First( T E' )
    #. = First(T)
    #. = First(FT')
    #. = First(F)
    #. = {a, ( }
#. First(E')
    #. = First(`+` T E')
    #. ∪
    #. First(`-` T E')
    #. ∪
    #. First( λ )
    #. = {`+`, `-`, λ}
#. First(T')
    #. = First(`*` F T')
    #. ∪
    #. First(`/` F T')
    #. ∪
    #. First(λ)
    #. = {`*`, `/`, λ}

----

:class: t2c

From First Sets to a Table
==========================================
#. E  → T E'
#. E' → + T E' | - T E' | λ
#. T  → F T'
#. T'  → * F T' | / F T' | λ
#. F → a | (E)

#. First(E) = First(T) = First(F) = {a, ( }
#. First(E') = {`+`, `-`, λ}
#. First(T') = {`*`, `/`, λ}

-

.. csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder equal-col

  "  ", a , `+` , `-` , `*` , `/` , (  , ) , $
  E   ,  T E' ,           ,        ,        ,         ,  T E'  ,        ,
  E'  ,       ,  `+` T E'   , `-` T E' ,        ,         ,        ,       ,
  T   ,  F T' ,           ,        ,        ,         , F T'   ,        ,
  T'  ,       ,         ,      , `*` F T' ,  `/` F T' ,        ,       ,
  F   , a     ,           ,        ,        ,         , ( E )  ,        ,

----

:class: t2c

Parsing(I)
==========================================
.. container::

  #. First(E) = First(T) = First(F) = {a, ( }
  #. First(E') = {`+`, `-`, λ}
  #. First(T') = {`*`, `/`, λ}

  .. csv-table::
    :header-rows: 1
    :class: smallerelementwithfullborder equal-col

    "  ", a , `+` , `-` , `*` , `/` , (  , ) , $
    E   ,  T E' ,           ,        ,        ,         ,  T E'  ,        ,
    E'  ,       ,  `+` T E'   , `-` T E' ,        ,         ,        ,       ,
    T   ,  F T' ,           ,        ,        ,         , F T'   ,        ,
    T'  ,       ,         ,      , `*` F T' ,  `/` F T' ,        ,       ,
    F   , a     ,           ,        ,        ,         , ( E )  ,        ,


#. a $ { 435.43 }
#. .a $ [ T E' ]
#. .a $ [ F T' E' ]
#. .a $ [ a T' E' ]
#. .$   [ T' E' ]
#. ? ? ?

----

:class: t2c

Parsing(II)
==========================================
.. container::

  #. First(E) = First(T) = First(F) = {a, ( }
  #. First(E') = {`+`, `-`, λ}
  #. First(T') = {`*`, `/`, λ}

  .. csv-table::
    :header-rows: 1
    :class: smallerelementwithfullborder equal-col

    "  ", a , `+` , `-` , `*` , `/` , (  , ) , $
    E   ,  T E' ,           ,        ,        ,         ,  T E'  ,        ,
    E'  ,       ,  `+` T E'   , `-` T E' ,        ,         ,        ,       ,
    T   ,  F T' ,           ,        ,        ,         , F T'   ,        ,
    T'  ,       ,         ,      , `*` F T' ,  `/` F T' ,        ,       , λ
    F   , a     ,           ,        ,        ,         , ( E )  ,        ,

.. class:: substep

#. a $ { 435.43 }
#. .a $ [ T E' ]
#. .a $ [ F T' E' ]
#. .a $ [ a T' E' ]
#. .$   [ T' E' ]
#. .$   [ λ E' ]
#. .$   [ E' ]
#. ? ? ?

----

:class: t2c

Parsing(III)
==========================================
.. container::

  #. First(E) = First(T) = First(F) = {a, ( }
  #. First(E') = {`+`, `-`, λ}
  #. First(T') = {`*`, `/`, λ}

  .. csv-table::
    :header-rows: 1
    :class: smallerelementwithfullborder equal-col

    "  ", a , `+` , `-` , `*` , `/` , (  , ) , $
    E   ,  T E' ,           ,        ,        ,         ,  T E'  ,        ,
    E'  ,       ,  `+` T E'   , `-` T E' ,        ,         ,        ,       ,  λ
    T   ,  F T' ,           ,        ,        ,         , F T'   ,        ,
    T'  ,       ,         ,      , `*` F T' ,  `/` F T' ,        ,       , λ
    F   , a     ,           ,        ,        ,         , ( E )  ,        ,

.. class:: substep

#. a $ { 435.43 }
#. .a $ [ T E' ]
#. .a $ [ F T' E' ]
#. .a $ [ a T' E' ]
#. .$   [ T' E' ]
#. .$   [ λ E' ]
#. .$   [ E' ]
#. .$   [ λ ]
#. .$   [  ]
#. accept

----

:class: t2c

Use LL Table for Parsing
==========================================
.. container::

  #. First(E) = First(T) = First(F) = {a, ( }
  #. First(E') = {`+`, `-`, λ}
  #. First(T') = {`*`, `/`, λ}

  .. csv-table::
    :header-rows: 1
    :class: smallerelementwithfullborder equal-col

    "  ", a , `+` , `-` , `*` , `/` , (  , ) , $
    E   ,  T E' ,           ,        ,        ,         ,  T E'  ,        ,
    E'  ,       ,  `+` T E'   , `-` T E' ,        ,         ,        ,       ,
    T   ,  F T' ,           ,        ,        ,         , F T'   ,        ,
    T'  ,       ,         ,      , `*` F T' ,  `/` F T' ,        ,       ,
    F   , a     ,           ,        ,        ,         , ( E )  ,        ,

.. class:: substep

#. a + a * a $ [435.43 + 376.1 * 94.2]
#. .a + a * a $ [ T E' ]
#. .a + a * a $ [ F T' E' ]
#. .a + a * a $ [ a T' E' ]
#. .+ a * a $   [ T' E' ]
#. .+ a * a $   [ T' E' ]

----

:class: t2c

.. csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder equal-col

  "  ",   a   ,     `+`   ,   `-`    ,   `*`    ,   `/`     ,   (    ,   ) ,  $
  E   ,  T E' ,           ,          ,          ,           ,  T E'  ,     ,
  E'  ,       ,  `+` T E' , `-` T E' ,          ,           ,        ,   λ ,  λ
  T   ,  F T' ,           ,          ,          ,           , F T'   ,     ,
  T'  ,       ,     λ     ,    λ     , `*` F T' ,  `/` F T' ,        ,   λ ,  λ
  F   ,   a   ,           ,          ,          ,           , ( E )  ,     ,

.. csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder equal-col

  Stack         ,  input       , action
  E           $ , .a - a / a $ , E → T E'
  T E'        $ , .a - a / a $ , T → F T'
  F T' E'     $ , .a - a / a $ , F → a
  a T' E'     $ , .a - a / a $ , Remove a
  T' E'       $ , . -  a / a $ , T' → λ
  E'          $ , . -  a / a $ , E' → - T E'
  `-` T E'    $ , . -  a / a $ , Remove -
  T E'        $ , . a / a    $ , T → F T'
  F T' E'     $ , . a / a    $ , F → a
  a T' E'     $ , . a / a    $ , Remove a
  T' E'       $ , . / a      $ , T' → / F T'
  / F T' E'   $ , . / a      $ , Remove / 
  F T' E'     $ , . a        $ ,  F → a
  a T' E'     $ , . a        $ ,  Remove a
  T' E'       $ , .          $ ,  T' → λ
  E'          $ , .          $ ,  E' → λ
              $ , .          $ ,  accept


----

:class: t2c

.. csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder equal-col

  "  ",   a   ,     `+`   ,   `-`    ,   `*`    ,   `/`     ,   (    ,   ) ,  $
  E   ,  T E' ,           ,          ,          ,           ,  T E'  ,     ,
  E'  ,       ,  `+` T E' , `-` T E' ,          ,           ,        ,   λ ,  λ
  T   ,  F T' ,           ,          ,          ,           , F T'   ,     ,
  T'  ,       ,     λ     ,    λ     , `*` F T' ,  `/` F T' ,        ,   λ ,  λ
  F   ,   a   ,           ,          ,          ,           , ( E )  ,     ,

.. csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder equal-col

  Stack             ,  input       , action
  E               $ , .( a + a ) a   $ , E → T E'
  T E'            $ , .( a + a ) a   $ , T → F T'
  F T' E'         $ , .( a + a ) a   $ , F → ( E )
  ( E ) T' E'     $ , .( a + a ) a   $ , Remove (
  E ) T' E'       $ , .  a + a ) a   $ , E → T E' 
  T E' ) T' E'    $ , .  a + a ) a   $ , T → F T' 
  F T' E' ) T' E' $ , .  a + a ) a   $ , F → a 
  a T' E' ) T' E' $ , .  a + a ) a   $ , Remove a
  T' E' ) T' E'   $ , .  + a ) a     $ , T' → λ
  E' ) T' E'      $ , .  + a ) a     $ , E' → + T E' 
  + T E' ) T' E'  $ , .  + a ) a     $ , Remove + 
  T E' ) T' E'    $ , .  a ) a       $ , T → F T' 
  F T' E' ) T' E' $ , .  a ) a       $ , F → a 
  a T' E' ) T' E' $ , .  a ) a       $ , Remove a
  T' E' ) T' E'   $ , .  ) a         $ , T' → λ
  E' ) T' E'      $ , .  ) a         $ , E' → λ
  ) T' E'         $ , .  ) a         $ , Remove )



  T' E'           $ , .  a           $ , T' → λ
   E'             $ , .  a           $ , E' → λ
                  $ , .  a           $ , Reject

----

:class: t2c

#. E  → T E'
#. E' → + T E'
#. E' → - T E' 
#. E' →  λ
#. T  → F T'
#. T' → * F T' 
#. T' → / F T' 
#. T' →  λ
#. F  → a
#. F  → ( E )

* First(E) = First(T) = First(F) = {a, ( }
* First(E') = {`+`, `-`, λ}
* First(T') = {`*`, `/`, λ}

* Follow(E)  = {) , $ }
* Follow(E') = Follow(E) = {) , $}
* Follow(T) = {First(E')-{λ}} ∪ Follow(E)
   ∪ follow(E') = {`+`, `-`, ), $}
* Follow(T') = Follow(T) =
   { `*`, `/`, `+`, `-`, $}
* Follow(F) = {First(T')-{λ}} ∪ Follow(T')
   = {`*`, `/`} ∪ { `*`, `/`, `+`, `-`, $}
   = { `*`, `/`, `+`, `-`, $}

`.`

.. csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder equal-col

  "  ",   a   ,     `+`   ,   `-`    ,   `*`    ,   `/`     ,   (    ,   ) ,  $
  E   ,  T E' ,           ,          ,          ,           ,  T E'  ,     ,
  E'  ,       ,  `+` T E' , `-` T E' ,          ,           ,        ,   λ ,  λ
  T   ,  F T' ,           ,          ,          ,           , F T'   ,     ,
  T'  ,       ,     λ     ,    λ     , `*` F T' ,  `/` F T' ,        ,   λ ,  λ
  F   ,   a   ,           ,          ,          ,           , ( E )  ,     ,

----

#. S → i(r) S  | i(r) S e S | o

* Eliminate Left Factor

#. S → i(r) S A | o
#. A → e S | λ

* first(S)  = {i, o} , first(A)  = {e, λ}
* follow(S) = {$, e} , follow(A) = {$, e}

.. csv-table::
  :header-rows: 1
  :class: substep smallerelementwithfullborder equal-col

  "  ",   i          , r ,   e       ,   o  ,  (    ,   ) ,  $
  S   ,  i ( r ) S A ,   ,           ,  o   ,       ,     ,
  A   ,              ,   , e S / λ   ,      ,       ,     ,  λ  

----

End

.. comments:

    rst2html syn.rst syn.html
    hovercraft syn.rst

    https://www.csd.uwo.ca/~mmorenom/CS447/Lectures/Syntax.html/node8.html

    https://www.researchgate.net/publication/2367776_An_Introduction_to_Compilers?enrichId=rgreq-3d6589b36b650b1be61ea0ce1b1b7805-XXX&enrichSource=Y292ZXJQYWdlOzIzNjc3NzY7QVM6OTg4Mjk0MzcyNDMzOTVAMTQwMDU3NDE4MjE5Ng%3D%3D&el=1_x_2&_esc=publicationCoverPdf

    https://www.tutorialspoint.com/compiler_design/compiler_design_syntax_analysis.htm

