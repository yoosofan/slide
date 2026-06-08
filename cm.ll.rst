.. prezento:: CM - Ll
   :css: ./assets/style.css

.. slido:: LL

    **Syntax Analysis(LL)**

    Ahmad Yoosofan

    Compiler course

    https://yoosofan.github.io/course/compiler.html

.. slido:: Reduce Function Calls
   :class: t2c

    #. A → a B
    #. B → b A
    #. B → a

    .. container:: step

      * a a

      .. class:: step

      #. A
      #. ⇒ a B
      #. ⇒ a a

    .. container:: step

      * a a $

      .. class:: step

      #. A $
      #. ⇒ a B $
      #. ⇒ a a $

    .. container:: step

      * a b a a $

      .. class:: step

      #. A $  ⇒ a B $
      #. ⇒ a B $ ⇒ a b A $
      #. ⇒ a b a B $  ⇒ a b a a $

    .. container:: step

      * a a $

      .. class:: step

      #. A $ [ a a $]
      #. ⇒ a B $ [a a $]
      #. ⇒ B $ [a $]
      #. ⇒ B $ [a $]
      #. ⇒ a $ [a $]
      #. ⇒  $ [ $]

    .. container:: step

      * a b a a $

      .. class:: step

      #. A $ [abaa$]
      #. a B $,  [abaa$]
      #. B $,  [baa$]
      #. b A $ , [baa$]
      #. A $, [aa$]
      #. a B $, [aa$]
      #. B $, [a$]
      #. a $, [a$]
      #. $, [$]

.. slido:: First sets
   :class: t2c

    .. container::

      #. A → a B
      #. B → b A
      #. B → a

      .. class:: step

      #. first( A ) = {a}
      #. first( B ) = {a , b}

    .. csv-table::
      :header-rows: 1
      :class: step smallerelementwithfullborder equal-col

      "  ",   a  , b     , $
      A   , A → a B ,       ,
      B   , B → a   , B → b A  ,

    .. csv-table::
      :header-rows: 1
      :class: step smallerelementwithfullborder equal-col

      "  ",   a  , b     , $
      A   , a B ,       ,
      B   , a   , b A  ,

    .. csv-table::
      :header-rows: 1
      :class: step smallerelementwithfullborder equal-col

      "  ",   a  , b     , $
      A   , 1 ,       ,
      B   , 3   , 2  ,

.. slido:: Parsing(I)
   :class: t2c

    .. container::

      #. A → a B
      #. B → b A
      #. B → a

      * first( A ) = {a}
      * first( B ) = {a , b}

      .. csv-table::
        :header-rows: 1
        :class: have-border

        "  ",   a  , b     , $
        A   ,  a B ,       ,
        B   ,  a   ,  b A  ,

    .. container:: step

      * a a $

      #. A $
      #. ⇒ a B $
      #. ⇒ a a $

      .. class:: step

      #. .a a $ [ A $ ]
      #. .a a $ [ a B $ ]
      #. .a $ [ B $ ]
      #. .a $ [ a $ ]
      #. .$ [ $ ]
      #. accept

.. slido:: Parsing(II)
   :class: t2c

    .. container::

      #. A → a B
      #. B → b A
      #. B → a

      * first( A ) = {a}
      * first( B ) = {a , b}

    .. csv-table::
      :header-rows: 1
      :class: have-border

      "  ",   a  , b     , $
      A   ,  a B ,       ,
      B   ,  a   ,  b A  ,

    .. container:: step

      * a b a a $

      .. class:: step

      #. A $
      #. ⇒ a B $
      #. ⇒ a B $
      #. ⇒ a b A $
      #. ⇒ a b a B $
      #. ⇒ a b a a $

    .. class:: step

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

.. slido:: Parsing(III)
   :class: t2c

    .. container::

      #. A → a B
      #. B → b A
      #. B → a

      * first( A ) = {a}
      * first( B ) = {a , b}

    .. csv-table::
      :header-rows: 1
      :class: have-border

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
       A   $ ,   a b a a $   , A → a B
       a B $ ,   a b a a $   , Remove a
       B $   ,   b a a $     , B → b A
       b A $ ,   b a a $     , Remove b
       A   $ ,     a a $     , A → a B
       a B $ ,     a a $     , Remove a
       B   $ ,     a $       , B → a
       a   $ ,     a $       , Remove a
           $ ,       $       , accept

.. slido:: Parsing(IV)
   :class: t2c

    .. csv-table::
      :header-rows: 1
      :class: smallerelementwithfullborder equal-col

      "  ",   a  , b     , $
      A   ,  a B ,       ,
      B   ,  a   ,  b A  ,

    .. container:: step

        b

        .. csv-table::
          :header-rows: 1
          :class: smallerelementwithfullborder equal-col step

          Stack ,  input        , action
           A  $ ,   b $   , Reject

        .. class:: step

        #. a b a b
        #. a b b b

    .. csv-table::
      :header-rows: 1
      :class: smallerelementwithfullborder equal-col step

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
      :class: smallerelementwithfullborder equal-col step

      Stack  ,  input        , action
       A $   ,  a b b b $    ,  A → a B
       a B $ ,  a b b b $    , Remove a
       B $   ,   b b b $     , B → b A
       b A$  ,   b b b $     , Remove b
       A$    ,     b b $     ,  Reject

.. slido:: Parsing(V)
   :class: t2c

    .. container::

      #. A → a B
      #. B → b A
      #. B →  λ

      .. class:: step

        first

        * first( A ) = {a}
        * first( B ) = {b , λ}

    .. container:: step

        .. csv-table::
          :header-rows: 1
          :class: smallerelementwithfullborder equal-col

          "  ",   a  , b     , $
          A   ,  a B ,       ,
          B   ,      ,  b A  ,

        .. class:: step

        input = a b a $


    .. csv-table::
      :header-rows: 1
      :class: step smallerelementwithfullborder equal-col

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
      :class: step smallerelementwithfullborder equal-col

      "  ",   a  , b     , $
      A   ,  a B ,       ,
      B   ,      ,  b A  ,  λ

.. slido:: Parsing(VI)
   :class: t2c

    .. container::

      #. A → a B
      #. B → b A
      #. B →  λ

      * first( A ) = {a}
      * first( B ) = {b , λ}

    .. container::

        .. csv-table::
          :header-rows: 1
          :class: step smallerelementwithfullborder equal-col

          "  ",   a  , b     , $
          A   ,  a B ,       ,
          B   ,   λ  ,  b A  , λ

        .. class:: step

        input = a a $

    .. csv-table::
      :header-rows: 1
      :class: step smallerelementwithfullborder equal-col

      Stack , input   , action
      A   $ , a a $ , A → a B
      a B $ , a a $ , Remove a
      B   $ , a   $ , B → λ
          $ , a   $ , Reject

    .. class:: step

    * Putting B → λ on that cell was incorrect
    * Removing B → λ from a is better
    * Finding more rules in future (follow set)

    .. csv-table::
      :header-rows: 1
      :class: step smallerelementwithfullborder equal-col

      "  ",   a  , b     , $
      A   ,  a B ,       ,
      B   ,      ,  b A  ,  λ

    .. csv-table::
      :header-rows: 1
      :class: step smallerelementwithfullborder equal-col

      Stack , input   , action
      A   $ , a a $ , A → a B
      a B $ , a a $ , Remove a
      B   $ , a   $ , Reject

.. slido:: Follow Set(I)
   :class: t2c

    .. container::

      #. A → a B
      #. B → b A
      #. B →  λ

      * first( A ) = {a}
      * first( B ) = {b , λ}

    .. container::

      .. csv-table::
        :header-rows: 1
        :class: smallerelementwithfullborder equal-col

        "  ",   a  , b     , $
        A   ,  a B ,       ,
        B   ,      ,  b A  , λ

      .. class:: step

      input = a b a $

    .. yographviz::
        :class: step

        digraph aba{
            rankdir=TB;
            node [shape=circle];
            A  [label="A"];
            A0 [label="a"];
            B  [label="B"];
            B0 [label="b"];
            A1 [label="A"];
            a1 [label="a"];
            B1 [label="B", color=red];

            A  -> A0
            B  -> B0
            A  -> B
            B  -> A1
            A1 -> a1
            A1 -> B1
        }


    .. container::

      .. class:: step

      #. follow( A ) = {$}
      #. follow( B ) = {$}

      .. csv-table::
        :header-rows: 1
        :class: step smallerelementwithfullborder equal-col

        Stack , input   , action
        A   $ , a a $ , A → a B
        a B $ , a a $ , Remove a
        B   $ , a   $ , Reject

.. slido:: Incorrect Calculator Grammar(I)
   :class: t2c

    .. container::

      #. E → T + E | T
      #. T → F * T | F
      #. F → ( E ) | a

      Some text books use *id* instead of *a*

    .. container:: step

      Remove Left Factor

      .. class:: step

      #. E  → T E'
      #. E' → + E | λ
      #. T  → F T'
      #. T' → * T |  λ
      #. F  → ( E ) |  a

    .. class:: step

    #. first(T) ⊂ first(E) [ E → T  E' ]
    #. first(F) ⊂ first(T) [ T → F T' ]
    #. first(F) = { a, ( } [ F → ( E ) | a ]
    #. first(E) = first(T) = first(F)
    #. first(E') = { + , λ} [ E' → + E' | λ ]
    #. first(T') = { * , λ} [ T' → * T' | λ ]

    .. csv-table::
      :header-rows: 1
      :class: step smallerelementwithfullborder equal-col

      " ",   a  ,  `+`     ,   `*`   ,   (    ,   )    ,   $
      E  , T E' ,          ,         ,  T E'  ,        ,
      E' ,      ,  `+` E   ,         ,        ,        ,
      T  , F T' ,          ,         ,  F T'  ,        ,
      T' ,      ,          , `*` T   ,        ,        ,
      F  ,   a  ,          ,         , ( E )  ,        ,

.. slido:: Adding λ to table
   :class: t2c

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
      :class: smallerelementwithfullborder equal-col step

      " ",   a  ,  `+`     ,   `*`   ,   (    ,   )    ,   $
      E  , T E' ,          ,         , T E'   ,        ,
      E' ,  λ   ,  `+` E   ,    λ    ,    λ   ,   λ    ,  λ
      T  , F T' ,          ,         , F T'   ,        ,
      T' ,  λ   ,   λ      , `*` T ,     λ  ,  λ     , λ
      F  ,   a  ,          ,         , ( E )  ,        ,

.. slido:: Parsing `a+a*a$` for right place of λ in LL(1) Table
   :class: t2c

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
        :class: step smallerelementwithfullborder equal-col

        " ",   a  ,  `+`     ,   `*`   ,   (    ,   )    , $
        E  , T E' ,          ,         ,  T E'  ,        ,
        E' ,      ,  `+` E   ,         ,        ,        , λ
        T  , F T' ,          ,         ,  F T'  ,        ,
        T' ,      ,    λ     , `*` T   ,        ,        , λ
        F  ,   a  ,          ,         , ( E )  ,        ,

    .. csv-table::
      :header-rows: 1
      :class: smallerelementwithfullborder equal-col step

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
      T' E'       $ , `*` a     $ , T' → * T
      `*` T E'    $ , `*` a    $ , Remove *
      T  E'       $ , a         $ , T → F T'
      F T'  E'    $ , a         $ , F → a
      a T' E'     $ , a         $ , Remove a
      T' E'       $ ,           $ , T' → λ
      E'          $ ,           $ , E' → λ
                  $ ,           $ , accept

.. slido:: Parsing `(a+a)$` for right place of λ in LL(1) Table
   :class: t2c

    .. container::

      #. E  → T E'
      #. E' → + E | λ
      #. T  → F T'
      #. T' → * T | λ
      #. F  → ( E ) | a

      .. csv-table::
        :header-rows: 1
        :class: step smallerelementwithfullborder equal-col

        " ",   a  ,  `+`     ,   `*`   ,   (    ,   )    , $
        E  , T E' ,          ,         ,  T E'  ,        ,
        E' ,  λ   ,  `+` E   ,         ,        ,   λ    , λ
        T  , F T' ,          ,         ,  F T'  ,        ,
        T' ,   λ  ,    λ     , `*` T   ,        ,   λ    , λ
        F  ,   a  ,          ,         , ( E )  ,        ,

      .. csv-table::
        :header-rows: 1
        :class: smallerelementwithfullborder equal-col step

        Stack            ,  input      , action
        E               $, ( a + a ) $ , E → T E'
        T E'            $, ( a + a ) $ , T → F T'
        F T' E'         $, ( a + a ) $ , F → ( E )
        ( E ) T' E'     $, ( a + a ) $ , Remove (
        E ) T' E'       $,   a + a ) $ , E → T E'

    .. csv-table::
      :header-rows: 1
      :class: smallerelementwithfullborder equal-col step

      Stack            ,  input      , action
      T E' ) T' E'    $,   a + a ) $ , T → F T'
      F T' E' ) T' E' $,   a + a ) $ , F → a
      a T' E' ) T' E' $,   a + a ) $ , Remove a
      T' E' ) T' E'   $,   `+` a ) $ , T' → λ
      E' ) T' E'      $,   `+` a ) $ , T' → λ
      `+` E ) T' E'   $, `+` a )   $ , Remove +
      E ) T' E'       $,       a ) $ , E → T E'
      T E' ) T' E'    $,       a ) $ , T → F T'
      F T' E' ) T' E' $,       a ) $ , F → a
      a T' E' ) T' E' $,       a ) $ , Remove a
      T' E' ) T' E'   $,         ) $ , T' → λ
      E' ) T' E'      $,         ) $ , E' → λ
      ) T' E'         $,         ) $ , Remove )
      T' E'           $,           $ , T' → λ
      E'              $,           $ , E' → λ
                      $,           $ , Accept

.. slido:: First set

    .. class:: step

    #. If X → λ is a production rule then λ ∈ first(X)
    #. If :math:`X → Y_1 Y_2 .... Y_n` is a production rule then
        #. first(:math:`Y_1`) ⊂ first(X)
        #. first(:math:`Y_2`) ⊂ first(X) if λ ∈ first(:math:`Y_1`) or :math:`Y_1 ⇒^* λ`
        #. first(:math:`Y_3`) ⊂ first(X) if λ ∈ first(:math:`Y_1`) and λ ∈ first(:math:`Y_2`)
        #. first(:math:`Y_i`) ⊂ first(X) if λ ∈ first(:math:`Y_j`) for j = 1, 2, 3, i-1
        #. λ ∈ first(X) if λ ∈ first(:math:`Y_i`) for i = 1, 2, 3, n or :math:`X ⇒^* λ`

.. slido:: Follow Set(II)

    .. class:: step

    #. If S is start symbol then $ ∈ follow(S)
    #. If X → α Y then follow(X) ⊂ follow(Y)
    #. If X → :math:`Y_1 Y_2 Y_3 Y_4 ..... Y_n` is a production rule then
        #. (first(:math:`Y_3`) - {λ} ) ⊂ follow(:math:`Y_2`)
            * if M → α A a β is a production rule then a ∈ follow(A)
        #. If λ ∈ first(:math:`Y_3`) then (first(:math:`Y_4`) - {λ} ) ⊂ follow(:math:`Y_2`)
            * or (first(:math:`Y_3`) ∪ first(:math:`Y_4`) - {λ} ) ⊂ follow(:math:`Y_2`)
        #. If λ ∈ first(:math:`Y_j`) for j = 3,4, ....., i-1  then (first(:math:`Y_i`) - {λ} ) ⊂ follow(:math:`Y_2`)
        #. If λ ∈ first(:math:`Y_j`) for j = 3,4, ....., n then follow(X) ⊂ follow(:math:`Y_2`)

.. slido:: Incorrect Calculator Grammar(I)
   :class: t2c

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

.. slido:: Follow Set(III)
   :class: t2c

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

    .. container:: step

          Follow sets

          .. class:: step

          * follow(E) = { $ , ) }
          * follow(E')= { $ , ) }
          * follow(T) = { + , $, ) }
          * follow(T')= { + , $, ) }
          * follow(F) = { * , +, $, ) }

.. slido:: Using Follow set(I)
   :class: t2c

    * follow(E) = { $ , ) }
    * follow(E')= { $ , ) }
    * follow(T) = { + , $, ) }
    * follow(T')= { + , $, ) }
    * follow(F) = { * , +, $, ) }

    .. csv-table::
      :header-rows: 1
      :class: step smallerelementwithfullborder equal-col

      " ",   a  ,  `+`     ,   `*`   ,   (    ,   )    ,   $
      E  , T E' ,          ,         ,  T E'  ,        ,
      E' ,      ,  `+` E   ,         ,        ,        ,
      T  , F T' ,          ,         ,  F T'  ,        ,
      T' ,      ,          , `*` T   ,        ,        ,
      F  ,   a  ,          ,         , ( E )  ,        ,

    .. csv-table::
      :header-rows: 1
      :class: step smallerelementwithfullborder equal-col

      " ",   a  ,  `+`     ,   `*`   ,   (    ,   )    ,   $
      E  , T E' ,          ,         ,  T E'  ,        ,
      E' ,      ,  `+` E   ,         ,        ,    λ   ,   λ
      T  , F T' ,          ,         ,  F T'  ,        ,
      T' ,      ,   λ      , `*` T   ,        ,    λ   ,   λ
      F  ,   a  ,          ,         , ( E )  ,        ,

    .. csv-table::
      :header-rows: 1
      :class: step smallerelementwithfullborder equal-col

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

.. slido:: Simple Calculator(I)
   :class: t2c

    #. E → E + T
    #. E → E - T
    #. E → T
    #. T → T * F
    #. T → T / F
    #. T → F
    #. F → a
    #. F → (E)

    .. class:: step

      #. first(E)
      #. = First(T)
      #. = first(F)
      #. = { a , ( }


    .. class:: step

      #. follow(E) = { $ , + , - , ) }
      #. follow(T) = { $ , + , - , ) , * , / }
      #. follow(F) = { $ , + , - , ) , * , / }

    .. csv-table::
      :header-rows: 1
      :class: step have-border

      "  ", a                  , `+` , `-` , `*` , `/` ,      (              , ) , $
      E   , E + T | E - T | T  ,     ,     ,     ,     ,   E + T | E - T | T ,   ,
      T   , T * F | T / F | F  ,     ,     ,     ,     , T * F | T / F | F   ,   ,
      F   , a                  ,     ,     ,     ,     , ( E )               ,   ,

.. slido:: Simple Calculator(II)
   :class: t2c

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

    .. class:: step

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

.. slido:: From First Sets to a Table
   :class: t2c

    #. E  → T E'
    #. E' → + T E' | - T E' | λ
    #. T  → F T'
    #. T'  → * F T' | / F T' | λ
    #. F → a | (E)

    * First(E) = First(T) = First(F) = {a, ( }
    * First(E') = {`+`, `-`, λ}
    * First(T') = {`*`, `/`, λ}

    .. csv-table::
      :header-rows: 1
      :class: step have-border

      "  ", a     , `+`       , `-` , `*` , `/` , (  , ) , $
      E   ,  T E' ,           ,        ,        ,         ,  T E'  ,        ,
      E'  ,       , "`+` T E'", `-` T E' ,        ,         ,        ,       ,
      T   ,  F T' ,           ,        ,        ,         , F T'   ,        ,
      T'  ,       ,           ,      , `*` F T' ,  `/` F T' ,        ,       ,
      F   , a     ,           ,        ,        ,         , ( E )  ,        ,

.. slido:: Parsing(I)
   :class: t2c

    .. container::

      #. First(E) = First(T) = First(F) = {a, ( }
      #. First(E') = {`+`, `-`, λ}
      #. First(T') = {`*`, `/`, λ}

      .. csv-table::
        :header-rows: 1
        :class: have-border

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

.. slido:: Parsing(II)
   :class: t2c

    .. container::

      #. First(E) = First(T) = First(F) = {a, ( }
      #. First(E') = {`+`, `-`, λ}
      #. First(T') = {`*`, `/`, λ}

      .. csv-table::
        :header-rows: 1
        :class: have-border

        "  ", a , `+` , `-` , `*` , `/` , (  , ) , $
        E   ,  T E' ,           ,        ,        ,         ,  T E'  ,        ,
        E'  ,       ,  `+` T E'   , `-` T E' ,        ,         ,        ,       ,
        T   ,  F T' ,           ,        ,        ,         , F T'   ,        ,
        T'  ,       ,         ,      , `*` F T' ,  `/` F T' ,        ,       , λ
        F   , a     ,           ,        ,        ,         , ( E )  ,        ,

    .. class:: step

    #. a $ { 435.43 }
    #. .a $ [ T E' ]
    #. .a $ [ F T' E' ]
    #. .a $ [ a T' E' ]
    #. .$   [ T' E' ]
    #. .$   [ λ E' ]
    #. .$   [ E' ]
    #. ? ? ?

.. slido:: Parsing(III)
   :class: t2c

    .. container::

      #. First(E) = First(T) = First(F) = {a, ( }
      #. First(E') = {`+`, `-`, λ}
      #. First(T') = {`*`, `/`, λ}

      .. csv-table::
        :header-rows: 1
        :class: have-border

        "  ", a , `+` , `-` , `*` , `/` , (  , ) , $
        E   ,  T E' ,           ,        ,        ,         ,  T E'  ,        ,
        E'  ,       ,  `+` T E'   , `-` T E' ,        ,         ,        ,       ,  λ
        T   ,  F T' ,           ,        ,        ,         , F T'   ,        ,
        T'  ,       ,         ,      , `*` F T' ,  `/` F T' ,        ,       , λ
        F   , a     ,           ,        ,        ,         , ( E )  ,        ,

    .. class:: step

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

.. slido:: Use LL Table for Parsing
   :class: t2c

    .. container::

      #. First(E) = First(T) = First(F) = {a, ( }
      #. First(E') = {`+`, `-`, λ}
      #. First(T') = {`*`, `/`, λ}

      .. csv-table::
        :header-rows: 1
        :class: have-border

        "  ", a , `+` , `-` , `*` , `/` , (  , ) , $
        E   ,  T E' ,           ,        ,        ,         ,  T E'  ,        ,
        E'  ,       ,  `+` T E'   , `-` T E' ,        ,         ,        ,       ,
        T   ,  F T' ,           ,        ,        ,         , F T'   ,        ,
        T'  ,       ,         ,      , `*` F T' ,  `/` F T' ,        ,       ,
        F   , a     ,           ,        ,        ,         , ( E )  ,        ,

    .. class:: step

    #. a + a * a $ [435.43 + 376.1 * 94.2]
    #. .a + a * a $ [ T E' ]
    #. .a + a * a $ [ F T' E' ]
    #. .a + a * a $ [ a T' E' ]
    #. .+ a * a $   [ T' E' ]
    #. .+ a * a $   [ T' E' ]

.. slido::
   :class: n2c

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

.. slido::
   :class: n2c

    .. csv-table::
      :header-rows: 1
      :class: have-border

      "  ",   a   ,     `+`   ,   `-`    ,   `*`    ,   `/`     ,   (    ,   ) ,  $
      E   ,  TE'  ,           ,          ,          ,           ,  TE'   ,     ,
      E'  ,       ,  `+` TE'  , `-` TE'  ,          ,           ,        ,   λ ,  λ
      T   ,  FT'  ,           ,          ,          ,           , FT'    ,     ,
      T'  ,       ,     λ     ,    λ     , `*` FT'  ,  `/` FT'  ,        ,   λ ,  λ
      F   ,   a   ,           ,          ,          ,           , ( E )  ,     ,

    .. csv-table::
      :header-rows: 1
      :class: smallerelementwithfullborder equal-col

      Stack             ,  input        , action
      E                $, .( a + a ) a$ , E → T E'
      T E'             $, .( a + a ) a$ , T → F T'
      F T' E'          $, .( a + a ) a$ , F → ( E )
      ( E ) T' E'      $, .( a + a ) a$ , Remove (
      E ) T' E'        $, .  a + a ) a$ , E → T E'
      T E' ) T' E'     $, .  a + a ) a$ , T → F T'
      F T' E' ) T' E'  $, .  a + a ) a$ , F → a
      a T' E' ) T' E'  $, .  a + a ) a$ , Remove a
      T' E' ) T' E'    $, .  + a ) a  $ , T' → λ
      E' ) T' E'       $, .  + a ) a  $ , E' → + T E'
      `+` T E' ) T' E' $, .  + a ) a  $ , Remove +
      T E' ) T' E'     $, .  a ) a    $ , T → F T'
      F T' E' ) T' E'  $, .  a ) a    $ , F → a
      a T' E' ) T' E'  $, .  a ) a    $ , Remove a
      T' E' ) T' E'    $, .  ) a      $ , T' → λ
      E' ) T' E'       $, .  ) a      $ , E' → λ
      ) T' E'          $, .  ) a      $ , Remove )


      T' E'          $, .  a       $ , T' → λ
       E'            $, .  a       $ , E' → λ
                     $, .  a       $ , Reject

.. slido::
   :class: n2c

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
      :class: have-border

      "  ",   a   ,     `+`   ,   `-`    ,   `*`    ,   `/`     ,   (    ,   ) ,  $
      E   ,  TE'  ,           ,          ,          ,           ,  TE'  ,     ,
      E'  ,       ,  `+TE'` , `-TE'` ,          ,           ,        ,   λ ,  λ
      T   ,  `FT'` ,           ,          ,          ,           , FT'   ,     ,
      T'  ,       ,     λ     ,    λ     , `*FT'` ,  `/FT'` ,        ,   λ ,  λ
      F   ,   a   ,           ,          ,          ,           , `(E)`  ,     ,

.. slido:: S → i(r) S  | i(r) S e S | o
   :class: n2c

    .. container::

      * Eliminate Left Factor

      #. S → i(r) S A | o
      #. A → e S | λ

      * first(S)  = {i, o} , first(A)  = {e, λ}
      * follow(S) = {$, e} , follow(A) = {$, e}

    .. csv-table::
      :header-rows: 1
      :class: have-border:w

      "  ",   i          , r ,   e       ,   o  ,  (    ,   ) ,  $
      S   ,  `i(r)SA` ,   ,           ,  o   ,       ,     ,
      A   ,              ,   , `eS/λ`   ,      ,       ,     ,  λ

.. slido::

    End

    .. comments:


        https://www.csd.uwo.ca/~mmorenom/CS447/Lectures/Syntax.html/node8.html

        https://www.researchgate.net/publication/2367776_An_Introduction_to_Compilers?enrichId=rgreq-3d6589b36b650b1be61ea0ce1b1b7805-XXX&enrichSource=Y292ZXJQYWdlOzIzNjc3NzY7QVM6OTg4Mjk0MzcyNDMzOTVAMTQwMDU3NDE4MjE5Ng%3D%3D&el=1_x_2&_esc=publicationCoverPdf

        https://www.tutorialspoint.com/compiler_design/compiler_design_syntax_analysis.htm
