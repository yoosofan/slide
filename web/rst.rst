:data-transition-duration: 1000
:skip-help: true
:css: assets/style.css
:substep: true

.. title: rst (By Ahmad Yoosofan)

:slide-numbers: true

.. role:: ltr
    :class: ltr

.. role:: rtl
    :class: rtl

.. role:: raw-html(raw)
   :format: html

Restructured Text
======================
Ahmad Yoosofan

http://yoosofan.github.io/

Search "Ahmad Yoosofan"

----

Why do we need another language?
=====================================
#. Simpler to write
#. Less keywords
#. More readable
#. Simply convertable to other formats
#. Less coding
#. Simpler to combine with other tools
#. Can be used instead of simple text reports

.. :

  html, programming code
  vs
  office and other visual tools

  Lightweight markup language
  https://en.wikipedia.org/wiki/Lightweight_markup_language


----

Install Python
===================
Download and Install Python from https://www.python.org/downloads/

#. Debian/Ubuntu based Linux
    .. code:: sh

        $ sudo apt-get install python3 python3-pip
#. Windows: After download and install, make sure it's in your path
    #. ``Control Panel > System > Advanced System Settings > Advanced Tab > Environment Variables...``
#. Android: Use termux command line
    #. https://f-droid.org/en/packages/com.termux
    #. Install python
        .. code::

            apt install python3
#. IOS
    #. http://omz-software.com/pythonista/index.html
    #. https://pyto.app

----

Install docutils or sphinx
===============================
#. Update pip
    .. code:: sh

        $ python3 -m pip install --upgrade pip

#. Install docutils
    .. code:: sh

        $ pip3 install docutils --upgrade
        # or
        $ python3 -m pip install docutils --upgrade

#. Or install Pygments and sphinx
    .. code:: sh

        $ pip3 install pygments sphinx --upgrade
        # or
        $ python3 -m pip install pygments sphinx --upgrade

----

How to run
================
.. code:: sh

  $ rst2html git.rst git.html

  # or

  $ rst2html.py git.txt git.html

  # or

  $ python tools/rst2html.py FAQ.txt FAQ.html  # (Windows)

* https://docutils.sourceforge.io/README.html
* https://pypi.org/project/docutils/#files
* https://sourceforge.net/projects/docutils/

----

Inline Markup
===================
..  csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder

  Plain text,Typical result
  ``*emphasis*``, *emphasis*
  ``**strong emphasis**``, **strong emphasis**
  ```interpreted text```, The rendering and meaning of interpreted text is domain- or application-dependent.
  ````inline literal````, ``inline literal``

----

Link(I)
==========
#. Any simple http/https/ftp converts to link
    #. https://yoosofan.github.io
#. If you want to use another text for the linke use ` `text <link>`_`
    * ```yoosofan <https://yoosofan.github.io>```
    * `yoosofan <https://yoosofan.github.io>`_
#. Link to external hyperlink
    .. code:: rst

        External hyperlinks, like Python_.

        Other texts
        ...

        .. _Python: https://www.python.org/


    External hyperlinks, like Python_.

    Other texts
    ``....``

    .. _Python: https://www.python.org/


----

Link(II)
==========
#. Internal Hyperlink Targets
    .. code:: rst

        Internal cross-references, like example_.

        This is an example cross-reference target.

        .. _example:

    Internal cross-references, like example_.

    This is an example cross-reference target.

    .. _example:

#. Phrase reference
    .. code:: rst

        Internal cross-references, like `This example`_.

        This is an example cross-reference target.

        .. _`This example`:

    Internal cross-references, like `This example`_.

    This is an example cross-reference target.

    .. _`This example`:

----

Link(III)
==========
#. Indirect Hyperlink Targets
    .. code:: rst

        Python_ is `my favourite
        programming language`__.
        .. _Python: https://www.python.org/

        __ Python_

    Python_ is `my favourite
    programming language`__.
    .. _Python: https://www.python.org/

    __ Python_

#. Implicit Hyperlink Targets
    .. code:: rst

        Titles are targets, too
        -------------------------
        Implicit references, like `Titles are
        targets, too`_.

Titles are targets, too
--------------------------
Implicit references, like `Titles are
targets, too`_.

----

Escaping with Backslashes
============================
.. code:: rst

  *escape* ``with`` "\"

  \*escape* \``with`` "\\"


*escape* ``with`` "\"

\*escape* \``with`` "\\"

----

Unordered List
================
.. code:: rst

  - This is item 1. A blank line before the first
    and last items is required.
  - This is item 2

  - Item 3: blank lines between items are optional.
  - Item 4: Bullets are "-", "*" or "+".
    Continuing text must be aligned after the bullet
    and whitespace.
  - This list item contains nested items

    - Nested items must be indented to the same
      level

- This is item 1. A blank line before the first
  and last items is required.
- This is item 2

- Item 3: blank lines between items are optional.
- Item 4: Bullets are "-", "*" or "+".
  Continuing text must be aligned after the bullet
  and whitespace.
- This list item contains nested items

  - Nested items must be indented to the same
    level

#. \* can be used instead of -

----

Ordered List
================
.. code:: rst

  1. This is the first item
  2. This is the second item
  3. Enumerators are arabic numbers,
     single letters, or roman numerals
  #. List items should be sequentially
     numbered, but need not start at 1
     (although not all formatters will
     honour the first index).
  #. This item is auto-enumerated

1. This is the first item
2. This is the second item
3. Enumerators are arabic numbers,
   single letters, or roman numerals
#. List items should be sequentially
   numbered, but need not start at 1
   (although not all formatters will
   honour the first index).
#. This item is auto-enumerated

----

Section Structure
=====================
.. code:: rst

    Title
    -------

    Titles are underlined (or over- and underlined) with
    a nonalphanumeric character at least as long as the
    text.

    A lone top-level section is lifted up to be the
    document's title.

    Any non-alphanumeric character can be used, but
    Python convention is:

    * ``#`` with overline, for parts
    * ``*`` with overline, for chapters
    * ``=``, for sections
    * ``-``, for subsections
    * ``^``, for subsubsections
    * ``"``, for paragraphs


Title
-------
.. class:: ltr

  Titles are underlined (or over- and underlined) with
  a nonalphanumeric character at least as long as the
  text.

  A lone top-level section is lifted up to be the
  document's title.

  Any non-alphanumeric character can be used, but
  Python convention is:

  * ``#`` with overline, for parts
  * ``*`` with overline, for chapters
  * ``=``, for sections
  * ``-``, for subsections
  * ``^``, for subsubsections
  * ``"``, for paragraphs

----

Headers
==========
.. code:: rst
  :number-lines:

  ##################
  Title
  ##################

  Chapter
  ################

  Section
  ****************

  Subsection
  ================

  Subsubsection
  ----------------

----

Blocks(I)
===========
.. code:: rst

    This is a paragraph.

    Paragraphs line up at their left edges, and are
    normally separated by blank lines.

.. class:: ltr

  This is a paragraph.

  Paragraphs line up at their left edges, and are
  normally separated by blank lines.

----

Blocks(II)
===============
.. code:: rst

    A paragraph containing only two colons indicates
    the following indented or quoted text is a literal
    block or quoted text is a literal block.

    ::

      Whitespace, newlines, blank lines, and  all kinds of
      markup (like *this* or \this) is preserved here.

    You can also tack the ``::`` at the end of a
    paragraph::

       It's very convenient to use this form.

    Per-line quoting can also be used for unindented
    blocks::

    > Useful for quotes from email and
    > for Haskell literate programming.

.. class:: ltr

  A paragraph containing only two colons indicates
  the following indented or quoted text is a literal
  block or quoted text is a literal block.

  ::

    Whitespace, newlines, blank lines, and  all kinds of
    markup (like *this* or \this) is preserved here.

  You can also tack the ``::`` at the end of a
  paragraph::

     It's very convenient to use this form.

  Per-line quoting can also be used for unindented
  blocks::

  > Useful for quotes from email and
  > for Haskell literate programming.

----

Block(III)
==============
.. code:: rst

    what
      Definition lists associate a term with
      a definition.

    how
      The term is a one-line phrase, and the
      definition is one or more paragraphs or
      body elements, indented relative to the
      term. Blank lines are not allowed
      between term and definition.

----

Image
========
.. code:: rst

  .. image:: picture.jpg
     :height: 100px
     :width: 200 px
     :alt: alternate text
     :align: right

  .. image:: picture.jpg
    :scale: 50 %
    :alt: alternate text
    :align: right

----

:class: t2c

Code(I)
========
.. code:: rst

  ..  code:: cpp

    while( busy == true )
      ;
    busy = true ; // Entry

    //Critical Section: CS

    busy = false ; // Exit

..  code:: cpp

  while( busy == true )
    ;
  busy = true ; // Entry

  //Critical Section: CS

  busy = false ; // Exit

----

:class: t2c

Code(II)
============
.. code:: rst

  .. code:: python
    :number-lines:

    import threading

    def f1():
      print("In f1")

    def f2():
      print("In f2");

    if __name__ == "__main__":
      th1 = threading.Thread(target=f1)
      th2 = threading.Thread(target=f2)
      print("main")
      th1.start();
      print("After f1")
      th2.start();
      print("After f2")


.. code:: python
  :number-lines:

  import threading

  def f1():
    print("In f1")

  def f2():
    print("In f2");

  if __name__ == "__main__":
    th1 = threading.Thread(target=f1)
    th2 = threading.Thread(target=f2)
    print("main")
    th1.start();
    print("After f1")
    th2.start();
    print("After f2")

----

Code(III)
============
.. code:: rst

  .. code:: javascript
      :number-lines:

      fetch(
          'http://domain/service',
          { method: 'GET' }
        )
        .then( response => response.json() )
        .then( json => console.log(json) )
        .catch( error => console.error('error:', error) );

.. code:: javascript
    :number-lines:

    fetch(
        'http://domain/service',
        { method: 'GET' }
      )
      .then( response => response.json() )
      .then( json => console.log(json) )
      .catch( error => console.error('error:', error) );


----

Code(IV)
==========
.. code:: rst

  .. code:: xml
      :number-lines:

      <employees>
        <employee>
          <firstName>John</firstName> <lastName>Doe</lastName>
        </employee>
        <employee>
          <firstName>Anna</firstName> <lastName>Smith</lastName>
        </employee>
        <employee>
          <firstName>Peter</firstName> <lastName>Jones</lastName>
        </employee>
      </employees>

.. code:: xml
    :number-lines:

    <employees>
      <employee>
        <firstName>John</firstName> <lastName>Doe</lastName>
      </employee>
      <employee>
        <firstName>Anna</firstName> <lastName>Smith</lastName>
      </employee>
      <employee>
        <firstName>Peter</firstName> <lastName>Jones</lastName>
      </employee>
    </employees>

----

:class: t2c

Code(V) - pygments
========================
* https://pygments.org
* https://pygments.org/languages/
* https://github.com/pygments/pygments

----

:class: t2c

include Code
======================
.. code:: rst

  .. include:: src/rst/code22.cpp
      :code: cpp
      :number-lines:
      :start-line: 2
      :end-line: 18

.. include:: src/rst/code22.cpp
    :code: cpp
    :number-lines:
    :start-line: 2
    :end-line: 18

.. code:: rst

  .. include:: src/rst/code22.cpp
      :code: cpp
      :number-lines: 18
      :start-line: 18

.. include:: src/rst/code22.cpp
    :code: cpp
    :number-lines: 18
    :start-line: 18

----

:class: t2c

Raw
========
.. code:: rst

    .. raw:: html

       <hr width=50 size=10>

.. code:: rst

    .. raw:: latex

       \setlength{\parindent}{0pt}

.. code:: rst

    ..  raw:: html
        :file: src/header.html


----

:class: t2c

Simple Table(I)
===================
.. code:: rst

    +-------+-------+
    | A     | not A |
    +-------+-------+
    | False | True  |
    +-------+-------+
    | True  | False |
    +-------+-------+

.. class:: smallerelementwithfullborder

+-------+-------+
| A     | not A |
+-------+-------+
| False | True  |
+-------+-------+
| True  | False |
+-------+-------+

----

Simple Table(II)
===================
.. code:: rst

    +------------------------+------------+----------+----------+
    | Header row, column 1   | Header 2   | Header 3 | Header 4 |
    | (header rows optional) |            |          |          |
    +========================+============+==========+==========+
    | body row 1, column 1   | column 2   | column 3 | column 4 |
    +------------------------+------------+----------+----------+
    | body row 2             | Cells may span columns.          |
    +------------------------+------------+---------------------+
    | body row 3             | Cells may  | - Table cells       |
    +------------------------+ span rows. | - contain           |
    | body row 4             |            | - body elements.    |
    +------------------------+------------+---------------------+

.. class:: smallerelementwithfullborder

+------------------------+------------+----------+----------+
| Header row, column 1   | Header 2   | Header 3 | Header 4 |
| (header rows optional) |            |          |          |
+========================+============+==========+==========+
| body row 1, column 1   | column 2   | column 3 | column 4 |
+------------------------+------------+----------+----------+
| body row 2             | Cells may span columns.          |
+------------------------+------------+---------------------+
| body row 3             | Cells may  | - Table cells       |
+------------------------+ span rows. | - contain           |
| body row 4             |            | - body elements.    |
+------------------------+------------+---------------------+

----

:class: t2c

Simple Table(III)
===================
.. code:: rst

    =====  =====  ======
       Inputs     Output
    ------------  ------
      A      B    A or B
    =====  =====  ======
    False  False  False
    True   False  True
    False  True   True
    True   True   True
    =====  =====  ======

.. class:: smallerelementwithfullborder

=====  =====  ======
   Inputs     Output
------------  ------
  A      B    A or B
=====  =====  ======
False  False  False
True   False  True
False  True   True
True   True   True
=====  =====  ======

----

List Table
==============
.. code:: rst

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

----

Class(I)
==================
css

.. code:: css

    .rtl {direction:rtl;text-align:right;font-family:Nazli;font-size:large;}
    .ltr {direction:ltr;text-align:left;}


.. code:: rst

    .. class:: ltr

        This is an English text


.. class:: ltr

    This is an English text


.. code:: rst

    .. class:: rtl

        متن فارسی


.. class:: rtl

    متن فارسی

.. code:: sh

  rst2html.py reStructuredText.rst reStructuredText.html --stylesheet=farsi.css,html4css1.css

----

Class(II)
==================
.. code:: rst

  .. list-table:: فهرست کارهای انجام شده برای پشتیبانی
     :header-rows: 1
     :widths: 10 20 20
     :class: tableheaderwithgraybackground rtl smallerelementwithfullborder

     * - تاریخ
       - مشکل
       - توضیح
     * - ۱۳۹۹/۷/۶
       - اعمال داده هاي جديد كاليبراسيون مخازن در نرم افزار کنترل تولید
       - داده های جدید اعمال گردیده و در نرم افزار در حال استفاده می‌باشد
     * - ۱۳۹۹/۸/۳
       - رفع اشكال از گزارش توليد روزانه در نرم افزار كنترل توليد
       - پس از تغییرات کلی در گزارش دیگر درست شد.
     * - ۱۳۹۹/۸/۲۹
       - خوانده نشدن داده‌های DCS
       - مشکل بررسی و برطرف شد

.. list-table:: فهرست کارهای انجام شده برای پشتیبانی
   :header-rows: 1
   :widths: 10 20 20
   :class: tableheaderwithgraybackground rtl smallerelementwithfullborder

   * - تاریخ
     - مشکل
     - توضیح
   * - ۱۳۹۹/۷/۶
     - اعمال داده هاي جديد كاليبراسيون مخازن در نرم افزار کنترل تولید
     - داده های جدید اعمال گردیده و در نرم افزار در حال استفاده می‌باشد
   * - ۱۳۹۹/۸/۳
     - رفع اشكال از گزارش توليد روزانه در نرم افزار كنترل توليد
     - پس از تغییرات کلی در گزارش دیگر درست شد.
   * - ۱۳۹۹/۸/۲۹
     - خوانده نشدن داده‌های DCS
     - مشکل بررسی و برطرف شد

----

CSV Table(I)
===============
.. code:: rst

    ..  csv-table:: جدول فاکتور - خریدار
        :header: `شماره فاکتور فروش`_,`نام خریدار`_, نشانی خریدار,دیگر اطلاعات خریدار
        :class: tableheaderwithgraybackground smallerelementwithfullborder
        :align: center


        1,Ali,Street1,other
        4,Kamran,street2,other
        5,Hamid,street3,other
        2,Koroush,street1,other
        4,Kamran,street2,other

    ..  _شماره فاکتور فروش: #

    ..  _نام خریدار: #

..  csv-table:: جدول فاکتور - خریدار
    :header: `شماره فاکتور فروش`_,`نام خریدار`_, نشانی خریدار,دیگر اطلاعات خریدار
    :class: tableheaderwithgraybackground smallerelementwithfullborder
    :align: center

    1,Ali,Street1,other
    4,Kamran,street2,other
    5,Hamid,street3,other
    2,Koroush,street1,other
    4,Kamran,street2,other

..  _شماره فاکتور فروش: #

..  _نام خریدار: #

----

:class: t2c

CSV Table(II)
===============
.. code:: rst

    ..  csv-table:: SJF (SPN)
      :header: P1 , P2,  P4, P3 , P2 , P1
      :widths: 10, 25 , 20, 30 , 35 , 5

      0  ,  2 , 7  , 11 , 17 , 24

.. container::

  ..  csv-table:: SJF (SPN)
    :header: P1 , P2,  P4, P3 , P2 , P1
    :widths: 10, 25 , 20, 30 , 35 , 5
    :class: smallerelementwithfullborder

    0  ,  2 , 7  , 11 , 17 , 24

.. code:: rst

    ..  csv-table::
      :header-rows: 1
      :class: smallerelementwithfullborder

      pname, gweight
      Nut,  12000
      Bolt, 17000
      Screw,  17000
      Screw,  14000
      Cam,  12000
      Cog,  19000

..  csv-table::
  :header-rows: 1
  :class: smallerelementwithfullborder

  pname, gweight
  Nut,  12000
  Bolt, 17000
  Screw,  17000
  Screw,  14000
  Cam,  12000
  Cog,  19000


----

CSV Table(III)
===============
.. code:: rst

    .. csv-table:: Table Title
       :file: CSV file path and name
       :widths: 30, 70
       :header-rows: 1

csv file structure
-----------------------
#. https://datatracker.ietf.org/doc/html/rfc4180
#. https://en.wikipedia.org/wiki/Comma-separated_values
#. https://docs.fileformat.com/spreadsheet/csv/
#. https://www.computerhope.com/issues/ch001356.htm
#. https://www.efilecabinet.com/what-is-a-csv/
#. https://support.staffbase.com/hc/en-us/articles/360007108391-CSV-File-Examples

sample files
-----------------
https://people.sc.fsu.edu/~jburkardt/data/csv/csv.html

----

CSV Table(IV)
===============
.. code:: rst
  :number-lines:

  .. csv-table:: Table Title
    :class: smallerelementwithfullborder

    John,Doe,120 jefferson st.,Riverside, NJ, 08075
    Jack,McGinnis,220 hobo Av.,Phila, PA,09119
    "John ""Da Man""",Repici,120 Jefferson St.,Riverside, NJ,08075
    Stephen,Tyler,"7452 Terrace ""At the Plaza"" road",SomeTown,SD, 91234
    ,Blankman,,SomeTown, SD, 00298
    "Joan ""the bone"", Anne",Jet,"9th, at Terrace plc",Desert City,CO,00123

.. csv-table:: Table Title
  :class: smallerelementwithfullborder

  John,Doe,120 jefferson st.,Riverside, NJ, 08075
  Jack,McGinnis,220 hobo Av.,Phila, PA,09119
  "John ""Da Man""",Repici,120 Jefferson St.,Riverside, NJ,08075
  Stephen,Tyler,"7452 Terrace ""At the Plaza"" road",SomeTown,SD, 91234
  ,Blankman,,SomeTown, SD, 00298
  "Joan ""the bone"", Anne",Jet,"9th, at Terrace plc",Desert City,CO,00123

https://people.sc.fsu.edu/~jburkardt/data/csv/addresses.csv

----

Check csv file and errors
================================
* https://csvlint.io/
* https://pypi.org/project/cutplace/

csv file structure
---------------------
* https://datatracker.ietf.org/doc/html/rfc4180
* https://en.wikipedia.org/wiki/Comma-separated_values

----

Rules for creating CSV files
=================================
https://www.thoughtspot.com/blog/6-rules-creating-valid-csv-files

* Separate data fields with a delimiter, usually a comma. This should be a single character. If you do not want to use a comma, you should choose something like a tab or a pipe (|) character.
* Keep each record on a separate line. Each record must start on its own line, but a single record can span multiple lines.
* Do not follow the last record in a file with a carriage return.
* In the first line of the file, include a header with a list of the column names in the file. This is optional, but strongly recommended; it allows the file to be self-documenting.
* Make sure the header list is delimited in the same way as the rest of the file. This helps guard against the data fields being transposed in the data when it is loaded, which can lead to getting wrong answers when you query the data.
* Remember that the enclosing character (typically double quotes) must be used when required, such as when the delimiter appears in a field.
* For more detail on these rules, you can look at Wikipedia and RFC 4180 (the Request for Comments document in the CSV specification).

Check csv file and errors
------------------------------
https://csvlint.io/
https://pypi.org/project/cutplace/

----

:class: t2c

Substitution References and Definitions
===========================================
.. code:: rst

  .. list-table::
     :header-rows: 1
     :widths: 10 50 10
     :class: smallerelementwithfullborder

     * - |kashanuimg1|
       - |nbsp|
       - تاریخ: ۱۴۰۰/۹/۱۶
     * - |nbsp|
       - another_file.rst
       - |nbsp|

  .. |kashanuimg1| image:: img/kashanu.png

  .. |nbsp| unicode:: 0xA0
     :trim:


.. list-table::
   :header-rows: 1
   :widths: 10 50 10
   :class: smallerelementwithfullborder

   * - |kashanuimg1|
     - |nbsp|
     - تاریخ: ۱۴۰۰/۹/۱۶
   * - |nbsp|
     - another_file.rst
     - |nbsp|

.. |kashanuimg1| image:: img/kashanu.png

.. |nbsp| unicode:: 0xA0
   :trim:

.. code:: rst

  .. class:: ltr smallerelementwithfullborder

    +-----+-------------------------+--------+-----+
    | P0  | P1 |nbsp| |nbsp| |nbsp| |    P2        |
    +=====+=========================+========+=====+
    | 0   | 1                       | 4      | 6   |
    +-----+-------------------------+--------+-----+


.. class:: ltr smallerelementwithfullborder

  +-----+-------------------------+--------+-----+
  | P0  | P1 |nbsp| |nbsp| |nbsp| |    P2        |
  +=====+=========================+========+=====+
  | 0   | 1                       | 4      | 6   |
  +-----+-------------------------+--------+-----+

----

:class: t2c

Math(I)
========
.. code:: rst

  .. math::
    :class: ltr

    EAT = table +  memory

    table =  h_t * t_t + ( 1 - h_t ) * ( t_t + t_m )

    memory = h_c * t_c + ( 1 - h_c ) * ( t_m + t_c )

.. container::

  .. math::
    :class: ltr

    EAT = table +  memory

    table =  h_t * t_t + ( 1 - h_t ) * ( t_t + t_m )

    memory = h_c * t_c + ( 1 - h_c ) * ( t_m + t_c )


.. code:: rst

    .. math::

        n_{\mathrm{offset}} = \sum_{k=0}^{N-1} s_k n_k

.. math::

    n_{\mathrm{offset}} = \sum_{k=0}^{N-1} s_k n_k

.. code:: rst

    .. math::

        n_{\mathrm{offset}} = \int_{k=0}^{N-1} s_k n_k

.. math::

    n_{\mathrm{offset}} = \intw_{k=0}^{N-1} s_k n_k


----

:class: t2c

Math(II)
========
.. code:: latex

  \binom{n}{m}=\binom{n-1}{m}+
  \binom{n-1}{m-1},
  \quad \binom{n}{0}=1,
  \quad \binom{n}{n}=1

  \exp(x) &= 1 + f\frac{x}{1!} + \frac{x^2}{2!}+
  \frac{x^3}{3!}+ ... + \frac{x^n}{n!}

  \forall x \in X, \quad \exists y \leq \epsilon

  \lim\limits_{x \to \infty} \exp(-x) = 0

  \sqrt[n]{1+x+x^2+x^3+\dots+x^n}

  M = \begin{bmatrix}
  \frac{5}{6} & \frac{1}{6} & 0         \\[0.3em]
  \frac{5}{6} & 0           & \frac{1}{6}\\[0.3em]
  0           & \frac{5}{6} & \frac{1}{6}
  \end{bmatrix}

.. container::

  .. math::

    \binom{n}{m}=\binom{n-1}{m}+\binom{n-1}{m-1},\binom{n}{0}=1,\binom{n}{n}=1

    \exp(x) &= 1 + f\frac{x}{1!} + \frac{x^2}{2!}+
    \frac{x^3}{3!}+ ... + \frac{x^n}{n!}

    \forall x \in X, \quad \exists y \leq \epsilon

    \lim\limits_{x \to \infty} \exp(-x) = 0

    \sqrt[n]{1+x+x^2+x^3+\dots+x^n}

    M = \begin{bmatrix}
    \frac{5}{6} & \frac{1}{6} & 0         \\[0.3em]
    \frac{5}{6} & 0           & \frac{1}{6}\\[0.3em]
    0           & \frac{5}{6} & \frac{1}{6}
    \end{bmatrix}

https://www.mathjax.org

https://en.wikibooks.org/wiki/LaTeX/

.. :

  https://docutils.sourceforge.io/docs/ref/rst/mathematics.html


  ----

  Math(III)
  ===========
  .. code:: latex

      \draw[help lines] (0,0) grid (2,3);
      \draw[step=0.5, gray, very thin] (-1.4,-1.4) grid (1.4,1.4);
      \draw (0,0) parabola (1,1.5) parabola[bend at end] (2,0);
      \draw (0,0) sin (1,1) cos (2,0) sin (3,-1) cos (4,0) sin (5,1);

  .. container::

    .. math::

        \usepackage(tikz);

        \draw[help lines] (0,0) grid (2,3);
        \draw[step=0.5, gray, very thin] (-1.4,-1.4) grid (1.4,1.4);
        \draw (0,0) parabola (1,1.5) parabola[bend at end] (2,0);
        \draw (0,0) sin (1,1) cos (2,0) sin (3,-1) cos (4,0) sin (5,1);


----

Inner instructions(I)
========================
.. code:: rst

    +-----------------------+-----------------------+
    | Symbol                | Meaning               |
    +=======================+=======================+
    | .. image:: tent.png   | Campground            |
    +-----------------------+-----------------------+
    | .. image:: waves.png  | Lake                  |
    +-----------------------+-----------------------+
    | .. image:: peak.png   | Mountain              |
    +-----------------------+-----------------------+

    .. list-table::
       :header-rows: 1
       :widths: 10 50 10
       :class: table-without-border-class

       * - |kashanuimg1|
         - |nbsp|
         - تاریخ: ۱۴۰۰/۹/۱۶
       * - |nbsp|
         - .. include:: another_file.rst
         - |nbsp|

----

:class: t2c

Inner instructions(II)
========================
.. code:: rst

    .. list-table::

        * - .. csv-table::
              :header-rows: 1
              :class: smallerelementwithfullborder

              pn, sn
              p1, s3
              p1, s4

          - ``.``

          - .. csv-table::
              :header-rows: 1
              :class: smallerelementwithfullborder

              pn, sn
              p4, s3
              p4, s5
              p4, s6

          - ``.``

          - .. csv-table::
              :header-rows: 1
              :class: smallerelementwithfullborder

              pn, sn
              p7, s2
              p7, s3

.. list-table::

    * - .. csv-table::
          :header-rows: 1
          :class: smallerelementwithfullborder

          pn, sn
          p1, s3
          p1, s4

      - ``.``

      - .. csv-table::
          :header-rows: 1
          :class: smallerelementwithfullborder

          pn, sn
          p4, s3
          p4, s5
          p4, s6

      - ``.``

      - .. csv-table::
          :header-rows: 1
          :class: smallerelementwithfullborder

          pn, sn
          p7, s2
          p7, s3

----

Field Lists
==============
.. code:: rst

    :Date: 2001-08-16
    :Version: 1
    :Authors: - Me
              - Myself
              - I
    :Indentation: Since the field marker may be quite long, the second
       and subsequent lines of the field body do not have to line up
       with the first line, but they must be indented relative to the
       field name marker, and they must line up with each other.

.. code:: rst

    +--------------------+----------------------+
    | ":" field name ":" | field body           |
    +-------+------------+                      |
            | (body elements)+                  |
            +-----------------------------------+

----

Other Specifications
=======================
.. code:: rst

  .. |date| date::
  .. |time| date:: %H:%M

  .. |FullTime| date:: %Y/%m/%d %H:%M

  ..  section-numbering::

  .. role:: python(code)
     :language: python

  .. role:: cpp(code)
     :language: cpp


  .. contents:: فهرست مطالب
     :depth: 7

----

Applications
===============
#. Simple Reports
#. Sophisticated Reports
    #. `sphinx <https://www.sphinx-doc.org>`_ , readthedocs.io
    #. https://docs.readthedocs.io/en/stable/intro/getting-started-with-sphinx.html
#. Static Web Site Generators
    * `Nikola <https://getnikola.com/>`_
    * `Pelican <getpelican.com>`_ , https://docs.getpelican.com, https://github.com/getpelican/pelican,
    * https://jamstack.org/generators/
#. Slides
    * `hovercraft <https://github.com/regebro/hovercraft>`_ , https://hovercraft.readthedocs.io/en/latest/introduction.html
    * https://pypi.org/project/hovercraft/


Simplicity is not weakness
------------------------------

----

Referenes
===============
* https://docutils.sourceforge.io/docs/ref/rst/directives.html
* http://docutils.sourceforge.net/docs/ref/rst/restructuredtext.html
* https://docutils.sourceforge.io/docs/ref/rst/mathematics.html
* `<http://docutils.sourceforge.net/docs/ref/rst/restructuredtext.txt>`_
* http://www.sphinx-doc.org/en/master/usage/restructuredtext/basics.html
* https://github.com/ralsina/rst-cheatsheet/blob/master/rst-cheatsheet.rst
* https://thomas-cokelaer.info/tutorials/sphinx/rest_syntax.html
* http://openalea.gforge.inria.fr/doc/openalea/doc/_build/html/source/sphinx/rest_syntax.html#citations
* `<http://rest-sphinx-memo.readthedocs.org/en/latest/ReST.html>`_
* `Markdown and reStructuredText <https://gist.github.com/dupuy/1855764>`_
* http://docutils.sourceforge.net/docs/ref/rst/
* `another useful resource <http://www.math.uiuc.edu/~gfrancis/illimath/windows/aszgard_mini/movpy-2.0.0-py2.4.4/manuals/docutils/ref/rst/directives.html>`_
* `From Python <https://docs.python.org/devguide/documenting.html>`_
* `FAQ <http://docutils.sourceforge.net/FAQ.html>`_
* `Restructured Text (reST) and Sphinx CheatSheet <http://openalea.gforge.inria.fr/doc/openalea/doc/_build/html/source/sphinx/rest_syntax.html>`_
* `<http://www.siafoo.net/help/reST>`_
* https://build-me-the-docs-please.readthedocs.io/en/latest/index.html
* https://docutils.sourceforge.io/docs/user/rst/quickstart.html

----

END