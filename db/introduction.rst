.. meta::
   :http-equiv=Content-Language: fa

..  section-numbering::


.. role:: ltr
    :class: ltr

###################################################################################################
Relational Model
###################################################################################################
***************************************************************************************************
Ahmad Yoosofan
***************************************************************************************************
https://en.wikipedia.org/wiki/Hierarchical_database_model
https://en.wikipedia.org/wiki/Network_model
https://en.wikipedia.org/wiki/Tree_structure
https://en.wikipedia.org/wiki/Relational_model

Data or Quantitative data
###################################################################################################
Quantitative data are measures of values or counts and are expressed as numbers.

Quantitative data are data about numeric variables (e.g. how many; how much; or how often).


Qualitative data are measures of 'types' and may be represented by a name, symbol, or a number code.

Qualitative data are data about categorical variables (e.g. what type) [abs.gov.au]_ .


Quantitative Data Examples
***************************************************************************************************
Listed below are some examples of quantitative data that can help understand exactly what this pertains [questionpro]_:

*  I updated my phone **6 times** in a quarter.
*  My teenager grew by **3 inches** last year.
*  **83 people** downloaded the latest mobile application.
*  My aunt lost **18 pounds** last year.
*  **150 respondents** were of the opinion that the new product feature will not be successful.
*  There will be **30% increase** in revenue with the inclusion of a new product.
*  **500 people** attended the seminar.
*  **54% people** prefer shopping online instead of going to the mall.
*  She has **10 holidays** in this year.
*  Product X costs **$1000**.

Advantages of Quantitative Data 
***************************************************************************************************
Some of advantages of quantitative data, are: [questionpro]_

*  Conduct in-depth research: Since quantitative data can be statistically analyzed, it is highly likely that the research will be detailed.
*  Minimum bias: There are instances in research, where personal bias is involved which leads to incorrect results. Due to the numerical nature of quantitative data, the personal bias is reduced to a great extent.
*  Accurate results: As the results obtained are objective in nature, they are extremely accurate.

Table
###################################################################################################

Field
***************************************************************************************************

Record
***************************************************************************************************


..  csv-table:: Sales DataBase
    :header-rows: 1

    product_id, product_name, stock, quantity, customer_id, customer_name
    10, Sugar, 20, 2, 32,"Ali"
    11, Salt, 100, 5, 32,"Ali"
    11, Salt, 100, 6, 33,"Reza"
    10, Sugar, 20, 3, 34,"Karim"

Types
###################################################################################################
Not exact types
***************************************************************************************************
product_id: positive number

product_name: string

stock: positive number

quantity: positive number

customer_id: positive number

customer_name: string


Types in mathematics
***************************************************************************************************

A video of C.J.Date
*************************
https://www.youtube.com/watch?v=qx0F7TfA8CI

نرمال سطح ۱
=====================================================

تبدیل شده به نرمال ۱
-------------------------------------------

..  csv-table:: جدول فروش یک فروشگاه
    :header: `شماره جنس`_,نام جنس,موجودی,`شماره فاکتور فروش`_,میزان فروش

    1,شکر,1000,1,12
    1,شکر,1000,4,14
    1,شکر,1000,5,5
    2,نمک,1500,2,10
    2,نمک,1500,4,20
    2,نمک,1500,5,30
    2,نمک,1500,3,40


کلید؟

ترکیب «شماره جنس» و «شماره فاکتور فروش» کلید را تشکیل می‌دهد.

روشن است که این جدول مشکل دارد و روشن این که باید دو جدول باشد ولی چه قانونی این را می‌گوید.

-----------------------------------------------------------

دو جدول پیشنهادی
-----------------------------------------------------------

..  csv-table:: جدول موجودی فروشگاه
    :header: `شماره جنس`_,نام جنس,موجودی

    1,شکر,1000
    2,نمک,1500





..  csv-table:: جدول فروش یک فروشگاه
    :header: `شماره جنس`_,`شماره فاکتور فروش`_,میزان فروش

    1,1,12
    1,4,14
    1,5,5
    2,2,10
    2,4,20
    2,5,30
    2,3,40

مشکل‌های جدول‌های پیشین چه بودند؟

ناهنجاری افزودن داده، حذف داده،‌به روز رسانی داده

قانون تقسیم چه می‌تواند باشد.

وابستگی تابعی
====================================

در جدول موجودی فروشگاه، شماره‌ی جنس تغیین کننده‌ی (determinant) دو ویژگی دیگر یعنی «نام جنس» و «موجودی» است. از طرف دیگر می‌توان گفت نام جنس و موجودی وابسته (dependant) به شماره‌ی جنس هستند.

به این نوع وابستگی، «وابستگی تابعی»(Functional Deppendancy) یا FD گفته می‌شود. وابستگی تابعی میان ویژگی‌های جدول برخاسته از تعریف و نوع ارتباط آنها با هم دیگر در جدول است و طراح پایگاه داده باید بتواند وابستگی‌های تابعی میان ویژگی‌های درون جدول‌های خود را بیابد.

بنابراین در هر جدول یک یا چند وابستگی تابعی وجود دارد. برای نمونه تعدادی از وابستگی‌های تابعی دو جدول بالا به قرار زیر است

*  در جدول موجودی فروشگاه

    *  شماره جنس ⭠ نام جنس
    *  شماره جنس ⭠ موجودی
    *  یا به صورت دیگر :  شماره جنس ⭠ {نام جنس ، موجودی}

*  در جدول فروش

    *  {شماره جنس ، شماره فاکتور} ⭠ میزان فروش

همان گونه که روشن است وابستگی‌ها به کلید هستند ولی وابستگی‌های دیگری نیز می‌تواند وجود داشته باشد.

ویژگی‌های ریاضی وابستگی تابعی
-------------------------------------------------------

به این ترتیب وابستگی تابعی می‌تواند به صورت یک عمل ریاضی تعریف شود و ویژگی‌های آن از دید ریاضی بر روی رابطه‌ها بررسی گردد.  بنابراین تعدادی اصل و تعدادی ویژگی و قضیه ار روی آن به دست می‌آید که در اینجا به بخشی از آن پرداخته می‌شود.

 اگر X ، Y و Z مجموعه‌هایی از ویژگی‌ها در یک رابطه‌ی R باشند برخی از قانون‌هایی که نتیجه می‌شود در ادامه نوشته شده است.

اصول آرمسترانگ

*  بازتابی بودن:  اگر Y زیر مجموعه‌ی X باشد آن‌گاه X ⭢ Y
*  بسط پذیری   :  اگر X ⭢ Y آن‌گاه XZ ⭢ YZ
*  تراگذری     :  اگر X ⭢ Y و Y ⭢ Z  آن‌گاه X ⭢ Z

قانون‌های زیر می‌تواند از روی سه قانون بالا به دست آید:

*  خود تعیینی : همواره داریم X ⭢ X
*  اجتماع     : اگر X ⭢ Y و X ⭢ Z آن‌گاه X ⭢ YZ
*  تجزیه      : اگر X ⭢ YZ آن‌گاه  X ⭢ Y و X ⭢ Z 
*  شبه تراگذری: اگر  X ⭢ Y و WY ⭢ Z آن‌گاه WX ⭢ Z
*  ترکیب      : اگر X ⭢ Y و Z ⭢ W آن‌گاه XZ ⭢ YW
*  اتحاد کلی  :  اگر X ⭢ Y و Z ⭢ W آن‌گاه X ⋃ (Z - Y) ⭢ YW

بستار وابستگی تابعی
------------------------------------------------------------

به مجموعه‌ی همه‌ی وابستگی‌های تابعی که می‌تواند از روی چند وابستگی تابعی به دست آید بستار آن وابستگی‌های تابعی گفته می‌شود. اگر F یک مجموعه وابستگی باشد :math:`{}^+F` مجموعه‌ی بستار F است.


برای نمونه اگر  در رابطه‌ی R ویژگی‌های A,B,C,D را به همراه قانون‌های وابستگی زیر داشته باشیم

..  class:: ltr

    1. A → B
    2. B → C
    3. AB → D

آن‌گاه قانون‌های زیر (بخشی از بستار این قانون‌ها) می‌تواند به دست آید:

..  class:: ltr


    a) A → A 
    b) A → AB
    c) A → ABD
    d) A → ABCD
    e) B → B
    f) B → BC
    g) A → D


مجموعه‌ی کاهش ناپذیر وابستگی‌ها
------------------------------------------------

در یک رابطه (جدول) به مجموعه‌ای از وابستگی‌های تابعی گفته می‌شود که کمینه باشد یا به عبارت دیگر هیچ کدام از قانون‌های وابستگی درون این مجموعه نتواند به شکلی از روی دیگر قانون‌ها به دست آید. مجموعه‌ای کاهش ناپذیر از وابستگی‌ها است اگر و فقط اگر سه قانون زیر را داشته باشد.

*  سمت راست(وابسته) هر وابستگی تابعی فقط یک ویژگی داشته باشد.
*  سمت چپ (تعیین کننده) هر وابستگی تابعی کاهش ناپذیر باشد. یعنی اگر سمت چپ یکی از قانون‌های وابستگی را کاهش دادیم حتما مجموعه‌ی بستار به دست آمده از آن تغییر کند(نه اینکه بتواند از قانون‌های دیگر به دست آید). به عبارت دیگر همه‌ی وابستگی‌ها باید کاهش ناپذیر چپ باشند. 
*  هیچ وابستگی تابعی نتواند بدون تغییر بستار از این مجموعه حذف شود.


نرمال سطح دوم
====================================

اگر ویژگی‌هایی به بخشی از کلید اصلی وابسته باشند به آن *وابستگی جزئی* گفته می‌شود. جدولی در سطح دوم نرمال است که درون آن وابستگی جزئی وجود نداشته باشد. یعنی هیچ قانون وابستگی که سمت چپ آن (تعیین کننده) آن بخشی از کلید باشد در وابستگی‌های آن جدول وجود نداشته باشد. به عبارت دیگر بخشی از کلید در سمت چپ هیچ وابستگی تابعی نباشد.

اکنون به جدول اولیه‌ی فروش دقت کنید. در این جدول کلید دو ویژگی شماره فاکتور و شماره جنس است در حالی که وابستگی تابعی شماره جنس ⭠ {نام جنس ، موجودی} را داریم که در سمت چپ آن (تعیین کننده آن) فقط بخشی از کلید اصلی است. ویژگی یا ويژگی‌هایی از جدول به بخشی از کلید اصلی وابسته هستند و بنابراین باید جدا شوند.

برای به دست آوردن فرم نرمال دوم باید همه‌ی وابستگی‌های جزئی را به دست آوریم و از آنها جدول‌های جداگانه ایجاد کنیم. دقت کنید که وابستگی‌های جزئی که در آنها سمت چپ (تعیین کننده) یکسان است باید با هم ترکیب شوند. 

در جدول مجموعه‌ی کاهش ناپذیر وابستگی‌های زیر را داریم

*  شماره جنس   ⭠ نام جنس
*  شماره جنس   ⭠ موجودی
*  {شماره جنس ، شماره فاکتور} ⭠ میزان فروش 

با ترکیب قانون‌هایی که تعیین کننده‌ی یکسان دارند دو قانون زیر به دست می‌آید.

*  شماره جنس ⭠ {نام جنس ، موجودی}
*  {شماره جنس ، شماره فاکتور} ⭠ میزان فروش

بنابراین باید جدول یاد شده را به دو جدول بشکنیم تا وابستگی جزئی درون آن نباشد.


نرمال سطح سوم
========================================================


..  csv-table:: جدول خریدار
    :header: `نام خریدار`_, کدپستی خریدار,شهر, خیابان, کوچه, پلاک

    Ali,    558633,Kashan,  Street1,alley1,23
    Kamran, 912133,Arsanjan,Street2,alley2,32
    Hamid,  234553,Kohdasht,Street3,alley3,21
    Koroush,494833,Mamasani,Street4,alley3,20
    Reza,   232444,Kazeron, Street5,alley6,12




وابستگی باواسطه
---------------------------------


نرمال BCNF
========================================================

۱. هر دانشجو ممکن است در چندین رشته تحصیل کند.

۲. برای هر رشته، یک دانشجو فقط یک استاد راهنما دارد

۳. در هر رشته چندین استاد راهنما وجود دارد

۴. هر استاد راهنما فقط در یک رشته راهنمایی می‌کند.

استاد راهنما ⭠ رشته

{شماره دانشجویی و رشته } ⭠ استاد راهنما


..  csv-table:: جدول راهنمایی
    :header: `شماره دانشجویی`_, `رشته`_, استاد راهنما

    123,کامپیوتر,یوسفان
    243,هنر, عرب بیگی
    342,مکانیک,عباسیان

یک مشکل مهم این جدول این است که در آن وابستگی مهم میان استاد راهنما و رشته نشان داده نشده است. روشن است که ساختار جدول‌ها بهتر است به گونه‌ای باشد که تا جایی که بشود بتواند شرایط واقعی را نشان دهد و وابستگی تابعی را نشان دهد.

شماره دانشجویی   و   استاد راهنما



..  csv-table:: جدول شماره دانشجویی - استاد راهنما
    :header: `شماره دانشجویی`_, `استاد راهنما`_

    123,یوسفان
    243, عرب بیگی
    342,عباسیان



رشته             و   استاد راهنما



..  csv-table:: جدول رشته - استاد راهنما
    :header: `استاد راهنما`_, رشته

    کامپیوتر,یوسفان
    هنر, عرب بیگی
    مکانیک,عباسیان


همه‌ی وابستگی‌ها در جدول فقط به کلید اصلی باشد.
-----------------------------------------------------------------


نرمال سطح چهارم
========================================================

فرض کنید در فروشگاهی امکان خرید گروهی نیز باشد یعنی یک گروه از خریداران با نام‌های گوناگون یک خرید را با هم انجام دهند و یک فاکتور برایشان صادر شود. برای نمونه اگر سه نفر از اعضا خانواده با هم برای خرید آمدند نام هر سه نفر در فاکتور خرید آورده شود در حالی که یک فاکتور برای جنس‌های درون آن زده شود. بنابراین قانون زیر نیز افزوده شود:

*برای یک فاکتور یک یا چند قلم جنس و یک یا چند خریدار می‌تواند وجود داشته باشد.*

با این فرض، جدول زیر برای فروش پیشنهاد شده است.

..  csv-table:: جدول فروش همراه خریدار
    :header: `شماره جنس`_,`شماره فاکتور فروش`_,میزان فروش,`نام خریدار`_

    1,1,12,Ali
    1,4,14,Kamran
    1,5,5,Hamid
    2,2,10,Koroush
    2,4,20,Kamran
    2,5,30,Hamid
    2,3,40,Reza
    1,5,5,Shahin
    2,5,30,Shahin

میزان فروش فقط به شماره‌ی جنس و شماره‌ی فاکتو بستگی دارد بنابراین جدول در نرمال سطح دوم نیست پس به دو جدول زیر شکسته می‌شود.


..  csv-table:: جدول فروش 
    :header: `شماره جنس`_,`شماره فاکتور فروش`_,میزان فروش

    1,1,12
    1,4,14
    1,5,5
    2,2,10
    2,4,20
    2,5,30
    2,3,40

..  csv-table:: جدول فروش همراه خریدار
    :header: `شماره جنس`_,`شماره فاکتور فروش`_,`نام خریدار`_

    1,1,Ali
    1,4,Kamran
    1,5,Hamid
    2,2,Koroush
    2,4,Kamran
    2,5,Hamid
    2,3,Reza
    1,5,Shahin
    2,5,Shahin

اکنون اگر این جدول را بدون توجه به دیگر جدول‌های نگاه کنیم روشن است که جدول خوبی نیست ولی تا نرمال BCNF مشکلی ندارد. روشن است که تکرار داده دارد در واقع نوعی گروه بندی یا عدم وابستگی میان آنها وجود دارد که باعث می‌شود بهتر ببینم به دو جدول زیر آن را بشکنیم بدون این که اطلاعاتی از دست برود.

..  csv-table:: جدول فروش: فاکتور - جنس
    :header: `شماره جنس`_,`شماره فاکتور فروش`_

    1,1
    1,4
    1,5
    2,2
    2,4
    2,5
    2,3


..  csv-table:: جدول فروش: فاکتور - خریدار
    :header: `شماره فاکتور فروش`_,`نام خریدار`_

    1,Ali
    4,Kamran
    5,Hamid
    2,Koroush
    4,Kamran
    5,Hamid
    3,Reza

مشخص است که با توجه به جدول فروش که از سه ستون شماره جنس، شماره فاکتور فروش و میزان فروش ساخته شده است دیگر نیازی به جدول فروش: فاکتور - جنس نیست و می‌تواند حذف شود و دو جدول زیر باقی بماند.

..  csv-table:: جدول فروش 
    :header: `شماره جنس`_,`شماره فاکتور فروش`_,میزان فروش

    1,1,12
    1,4,14
    1,5,5
    2,2,10
    2,4,20
    2,5,30
    2,3,40

..  csv-table:: جدول فروش: فاکتور - خریدار
    :header: `شماره فاکتور فروش`_,`نام خریدار`_

    1,Ali
    4,Kamran
    5,Hamid
    2,Koroush
    4,Kamran
    5,Hamid
    3,Reza

چرا این دو جدول همه‌ی اطلاعات مربوط به جدول پیشین را در بردارد؟

مهم‌ترین نکته این است که خریداران گوناگون در یک فاکتور فروش نمی‌توانند جنس‌های گوناگونی داشته باشند و همه‌ی جنس‌هایشان تکراری است.


نمونه نرمال سازی
========================================================

جدول فروش زیر را در نظر بگیرید:

..  csv-table:: جدول فروش همراه خریدار
    :header: `شماره جنس`_,`شماره فاکتور فروش`_,میزان فروش,`نام خریدار`_, نشانی خریدار,دیگر اطلاعات خریدار

    1,1,12,Ali,Street1,other
    1,4,14,Kamran,street2,other
    1,5,5,Hamid,street3,other
    2,2,10,Koroush,street1,other
    2,4,20,Kamran,street2,other
    2,5,30,Hamid,street3,other
    2,3,40,Reza,street2,other

باز هم این جدول دلچسب نیست و مشکل دارد. اولین مشکل این است که نرمال دوم نیست زیرا نام خریدار فقط به شماره فاکتور وابسته است بنابراین دو جدول زیر به دست می‌آید.

..  csv-table:: جدول فروش یک فروشگاه
    :header: `شماره جنس`_,`شماره فاکتور فروش`_,میزان فروش

    1,1,12
    1,4,14
    1,5,5
    2,2,10
    2,4,20
    2,5,30
    2,3,40




..  csv-table:: جدول فاکتور - خریدار
    :header: `شماره فاکتور فروش`_,`نام خریدار`_, نشانی خریدار,دیگر اطلاعات خریدار

    1,Ali,Street1,other
    4,Kamran,street2,other
    5,Hamid,street3,other
    2,Koroush,street1,other
    4,Kamran,street2,other
    5,Hamid,street3,other
    3,Reza,street2,other

باز هم این جدول مشکل دارد و به خوبی می‌توان این مشکلات را به ویژه زمانی که تعداد خریداران و فاکتورها افزایش یابد دید زیرا نشانی خریدار و دیگر اطلاعات خریدار بی‌جهت تکرار می‌شود. بنابراین جدول فاکتور-خریدار به دو جدول زیر شکسته می‌شود.



..  csv-table:: جدول فاکتور - خریدار
    :header: `شماره فاکتور فروش`_,`نام خریدار`_

    1,Ali
    4,Kamran
    5,Hamid
    2,Koroush
    4,Kamran
    5,Hamid
    3,Reza

..  csv-table:: جدول خریدار
    :header: `نام خریدار`_, نشانی خریدار,دیگر اطلاعات خریدار

    Ali,Street1,other
    Kamran,street2,other
    Hamid,street3,otherخ
    Koroush,street1,other
    Kamran,street2,other
    Hamid,street3,other
    Reza,street2,other



حفظ وابستگی‌ها و کنار هم گذاشتن ویژگی‌هایی که به هم وابسته هستند.


..  _شماره جنس:  #

..  _شماره فاکتور فروش: #

..  _نام خریدار: #

..  _شماره دانشجویی: #

..  _رشته: #

..  _استاد راهنما: #

.. [abs.gov.au] https://www.abs.gov.au/websitedbs/a3121120.nsf/home/statistical+language+-+quantitative+and+qualitative+data
.. [questionpro] https://www.questionpro.com/blog/quantitative-data/

*  https://en.wikipedia.org/wiki/Relational_model
*  https://www.tutorialspoint.com/dbms/relational_data_model.htm
*  https://www.guru99.com/relational-data-model-dbms.html
*  https://www.geeksforgeeks.org/tuple-relational-calculus-trc-in-dbms/
*  https://flaviocopes.com/relational-model/
*  https://en.wikipedia.org/wiki/Tuple_relational_calculus
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

.. comments:

   rst2html relational_model.rst relational_model.html --stylesheet=farsi.css,html4css1.css

   Database normalization (or normalisation) is the process of organizing the columns (attributes) and tables (relations) of a relational database to minimize data redundancy.
   https://en.wikipedia.org/wiki/Database_normalization

   rst2odt normalization.rst normalization.odt --stylesheet=test1.odt

  http://stackoverflow.com/questions/9084173/how-to-underline-text-in-restructuredtext#9092809
