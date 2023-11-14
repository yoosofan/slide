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

Install hovercraft
==================
pip3 install hovercraft

----

Run servers
===========
* Open a terminal (console or command prompt)
* Run the following command
    .. code:: console
    
        python3 -m http.server 8002
        
* Open another terminal
* Run the following command with specified rst file of a slide
    .. code:: console
    
        hovercraft html.rst

Misc
=====
Reaseons to learn web design basics
------------------------------------

خوبی‌های نوشتن وب به صورت دستی
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
#. شخصی سازی
#. سرعت
#. اشکال‌زدایی
#. امنیت بسته به میزان مورد نیاز
#. ادامه نیافتن توسعهٔ ابزار و احتمالا پشتیبانی نشدن از روش‌های به کار گرفته شده در ابزار
#. بهم ریختن افزونه‌ها یا حتی کارکرد متداول با توجه به روزرسانی ابزار اصلی

تفاوت چندانی نمی‌کند
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
#. سئو

خوبی‌های به کارگیری ابزارهای آماده مانند wordpress و همانند آن
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
#. سرعت توسعه بیشتر اولیه
#. بسته به نوع ابزار تعداد زیاد قالب‌های آماده

