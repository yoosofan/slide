`فارسی`_


===============================================
Ahmad Yoosofan Slides for some Computer Courses
===============================================


List of courses and slides
==========================
.. csv-table::
    :header-rows: 1

    folder, course name
    `cm <https://github.com/yoosofan/slide/tree/main/cm>`_  ,  Compiler Design
    `cpp <https://github.com/yoosofan/slide/tree/main/cpp>`_, Advanced Programming: cpp based
    `db <https://github.com/yoosofan/slide/tree/main/db>`_  ,  Fundamental of Database Systems Concepts
    `os <https://github.com/yoosofan/slide/tree/main/os>`_  ,  Operating Systems
    `web <https://github.com/yoosofan/slide/tree/main/web>`_, Front-end Web Development Fundations and related topics

For each rst slide files in the above courses, there is a html folder by the same name.

For example, for `os/mem.rst` file almost always, there is a folder by the
name `os/mem/` .
By opening index.html on that folder (`os/mem/index.html`), the slides can be shown.

To download a folder from GitHub, navigate to your desired repository,
select the folder you want to download from GitHub, copy the URL, navigate to
https://download-directory.github.io/ and paste the URL into the text box, 
and hit enter.

For example do download the following folder
https://github.com/yoosofan/slide/tree/main/os/ps
just copy it the the box in the following URL
https://download-directory.github.io/
The zip file of the whole folder will be downloaded.

But sometimes the related html folder is outdated and should be genereted by
`Prezentprogramo <https://github.com/yoosofan/prezentprogramo>`_ .
And for changing slides, the rst files should be changed, then
html folder can be created by
`Prezentprogramo <https://github.com/yoosofan/prezentprogramo>`_ .

There are other situations that using
`Prezentprogramo <https://github.com/yoosofan/prezentprogramo>`_
is prefereable. Therefore, learning how to use
`Prezentprogramo <https://github.com/yoosofan/prezentprogramo>`_ .
would be useful.

Use Prezentprogramo to view presentations
=========================================
Install `Prezentprogramo <https://github.com/yoosofan/prezentprogramo>`_

Run a simple slide
------------------
.. code:: sh

  cd os
  prezentprogramo cpu.rst

It will automatically open browser if it is possible.
If the browser did not open then run your browser
and type the following link in your browser

http://127.0.0.1:8000

.. _فارسی :

.. class:: rtl-h1

فارسی

.. class:: rtl

اینجا را فارسی می‌نویسم

.. class:: ltr

rst2html5.py readme.rst index.html --stylesheet=tools/farsi.css