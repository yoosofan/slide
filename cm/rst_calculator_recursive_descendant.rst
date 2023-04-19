:data-transition-duration: 1000
:skip-help: true
:css: hovercraft_style.css
:substep: true

.. title: Compiler (By Ahmad Yoosofan)

:slide-numbers: true

.. role:: ltr
    :class: ltr

.. role:: rtl
    :class: rtl

Compiler
===================================================
Parsing Methods

Recursive Descendant Method I

Ahmad Yoosofan

University of Kashan

----

Special State Diagram For A Grammar
==========================================
E → a + E | a
-----------------------
.. class:: substep

    A diagram for E
    
    .. image:: image/recursive.descendant.method/calculator/wrong_grammar_simple.png
        :align: center

    
    It is a wrong grammar but it is useful for learning

----

.. image:: image/recursive.descendant.method/calculator/wrong_grammar_simple.png
    :align: center

.. include:: src/recursive.descendant.method/calculator/python/wrong_grammar1_simple_calculator_1.py
    :code: python
    :number-lines:

----

Convert it to Calculator
==============================
.. include:: src/recursive.descendant.method/calculator/python/wrong_grammar1_simple_calculator_2.py

    :code: python
    :number-lines:

----

NonRecursive I
===============================

.. image:: image/recursive.descendant.method/calculator/wrong_grammar_simple.png
    :align: center

.. class:: substep

    .. image:: image/recursive.descendant.method/calculator/wrong_grammar_simple_no_recursive.png
        :align: center

----

NonRecursive II
===============================
.. image:: image/recursive.descendant.method/calculator/wrong_grammar_simple_no_recursive.png
    :align: center

.. class:: substep

    .. image:: image/recursive.descendant.method/calculator/wrong_grammar_simple_no_recursive2.png
        :align: center

----


.. note:

    https://pypi.org/project/hovercraft/
    https://github.com/regebro/hovercraft/issues/214
    
    .. image:: img/memory_precess_addressing_parts.png
       :align: center
    https://www.w3schools.com/js/js_json_xml.asp
    https://developer.mozilla.org/en-US/docs/Web/API/Window/sessionStorage
    https://stackoverflow.com/questions/26337969/how-to-decode-an-email-attachment-received-as-a-base64-text
    https://en.wikipedia.org/wiki/Base64
    https://ietf.org/
    https://superuser.com/questions/213563/how-can-i-extract-an-attachment-from-the-email-body-encoded-as-base64
    https://en.wikipedia.org/wiki/JSON
    https://www.w3schools.com/js/js_json_intro.asp
    https://www.w3schools.com/js/js_ajax_intro.asp
    https://www.ecma-international.org/publications/standards/Ecma-262.htm
    https://en.wikipedia.org/wiki/JSON
    https://www.w3schools.com/js/js_json_intro.asp    
    https://bob.ippoli.to/archives/2005/12/05/remote-json-jsonp/
    https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/JSON
    https://jsoneditoronline.org/
    https://www.quora.com/How-do-I-send-a-person-details-and-several-images-via-JSON-in-Android
    https://dotnetcoretutorials.com/2018/07/21/uploading-images-in-a-pure-json-api/
    https://stackoverflow.com/questions/34485420/how-do-you-put-an-image-file-in-a-json-object
    

