Advanced Programming Language(C++)
==================================

.. csv-table::
    :header-rows: 1

    File Name,    html,                                                              Description
    c2cpp.rst,    `c2cpp <https://yoosofan.github.io/slide/cpp/c2cpp/>`_,            From C to C++
    in.rst,       `in <https://yoosofan.github.io/slide/cpp/in/>`_,                  Inheritance
    tc.rst,       `tc <https://yoosofan.github.io/slide/cpp/tc/>`_,                  Template Class
    file.rst,     `file <https://yoosofan.github.io/slide/cpp/file/>`_,              File

----

How to create html from readme.rst

.. code:: sh

    rst2html5.py readme.rst index.html --stylesheet=../tools/farsi.css


.. :

    https://stackoverflow.com/a/15402972/886607

    find src/ -iname "*.cpp" -type f -exec sed -i 's/(void)/()/g' {} \;

