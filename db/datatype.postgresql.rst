.. meta::
   :http-equiv=Content-Language: fa

..  section-numbering::

================================================
پایگاه داده : نوع‌های پایه
================================================

احمد یوسفان

دانشگاه کاشان


Basic data types
======================================================

====================  ====================  ====================  ====================
CHARACTER(n)          VARCHAR(n)            CHARACTER VARYING(n)  BINARY(n)
BOOLEAN               VARBINARY(n)          BINARY VARYING(n)     INTEGER(p)
SMALLINT              INTEGER               BIGINT                DECIMAL(p,s)
NUMERIC(p,s)          FLOAT(p)              REAL                  FLOAT
DOUBLE PRECISION      DATE                  TIME                  TIMESTAMP
INTERVAL              ARRAY                 MULTISET              XML
====================  ====================  ====================  ====================

PostgreSQL data types
======================================================

`<http://www.postgresql.org/docs/9.1/static/datatype.html>`_

=====================================   ==================  ===========================================================
Name                                    Aliases             Description
=====================================   ==================  ===========================================================
bigint                                  int8                signed eight-byte integer
bigserial                               serial8             autoincrementing eight-byte integer
bit [ (n) ]                                                 fixed-length bit string
bit varying [ (n) ]                                         varbit  variable-length bit string
boolean                                 bool                logical Boolean (true/false)
box                                                         rectangular box on a plane
bytea                                                       binary data ("byte array")
character varying [ (n) ]               varchar [ (n) ]     variable-length character string
character [ (n) ]                       char [ (n) ]        fixed-length character string
cidr                                                        IPv4 or IPv6 network address
circle                                                      circle on a plane
date                                                        calendar date (year, month, day)
double precision                        float8              double precision floating-point number (8 bytes)
inet                                                        IPv4 or IPv6 host address
integer                                 int, int4           signed four-byte integer
interval [fields] [(p)]                 time span
line                                                        infinite line on a plane
lseg                                                        line segment on a plane
macaddr                                                     MAC (Media Access Control) address
money                                                       currency amount
numeric [ (p, s) ]                      decimal [(p, s)]    exact numeric of selectable precision
path                                                        geometric path on a plane
point                                                       geometric point on a plane
polygon                                                     closed geometric path on a plane
real                                    float4              single precision floating-point number (4 bytes)
smallint                                int2                signed two-byte integer
serial                                  serial4             autoincrementing four-byte integer
text                                                        variable-length character string
time [(p)] [without time zone]                              time of day (no time zone)
time [(p)] with time zone               timetz              time of day, including time zone
timestamp [(p)] [without time zone]                         date and time (no time zone)
timestamp [(p)] with time zone          timestamptz         date and time, including time zone
tsquery                                                     text search query
tsvector                                                    text search document
txid_snapshot                                               user-level transaction ID snapshot
uuid                                                        universally unique identifier
xml                                                         XML data
=====================================   ==================  ===========================================================

Numeric types
------------------------------------------------------


================  =============  ==================================   ========================================================================================
Name              Storage Size   Description                          Range
================  =============  ==================================   ========================================================================================
smallint          2 bytes        small-range integer                  -32768 to +32767
integer           4 bytes        typical choice for integer           -2147483648 to +2147483647
bigint            8 bytes        large-range integer                  -9223372036854775808 to 9223372036854775807
decimal           variable       user-specified precision, exact      up to 131072 digits before the decimal point; up to 16383 digits after the decimal point
numeric           variable       user-specified precision, exact      up to 131072 digits before the decimal point; up to 16383 digits after the decimal point
real              4 bytes        variable-precision, inexact          6 decimal digits precision
double precision  8 bytes        variable-precision, inexact          15 decimal digits precision
serial            4 bytes        autoincrementing integer             1 to 2147483647
bigserial         8 bytes        large autoincrementing integer       1 to 9223372036854775807
================  =============  ==================================   ========================================================================================

Monetary Types
------------------------------------------------------

=====  =================   ===============       =========================================================
Name   Storage Size        Description           Range
=====  =================   ===============       =========================================================
money  8 bytes             currency amount       -92233720368547758.08 to +92233720368547758.07
=====  =================   ===============       =========================================================


Character Types
------------------------------------------------------

================================  ===========================
Name                              Description
================================  ===========================
character varying(n), varchar(n)  variable-length with limit
character(n), char(n)             fixed-length, blank padded
text                              variable unlimited length
================================  ===========================

Binary Data Types
------------------------------------------------------



========  ==========================================  ==============================
Name      Storage Size                                Description
========  ==========================================  ==============================
bytea     1 or 4 bytes plus the actual binary string  variable-length binary string
========  ==========================================  ==============================


Date/Time Types
------------------------------------------------------


========================================  =============   ==================================  ================  ===============   ==========================
Name                                      Storage Size    Description                         Low Value         High Value        Resolution
========================================  =============   ==================================  ================  ===============   ==========================
timestamp [ (p) ] [ without time zone ]   8 bytes         both date and time (no time zone)   4713 BC           294276 AD         1 microsecond / 14 digits
timestamp [ (p) ] with time zone          8 bytes         both date and time, with time zone  4713 BC           294276 AD         1 microsecond / 14 digits
date                                      4 bytes         date (no time of day)               4713 BC           5874897 AD        1 day
time [ (p) ] [ without time zone ]        8 bytes         time of day (no date)               00:00:00          24:00:00          1 microsecond / 14 digits
time [ (p) ] with time zone               12 bytes        times of day only, with time zone   00:00:00+1459     24:00:00-1459     1 microsecond / 14 digits
interval [ fields ] [ (p) ]               16 bytes        time interval                       -178000000 years  178000000 years   1 microsecond / 14 digits
========================================  =============   ==================================  ================  ===============   ==========================


TIMESTAMP '2004-10-19 10:23:54'


TIMESTAMP '2004-10-19 10:23:54+02'


TIMESTAMP WITH TIME ZONE '2004-10-19 10:23:54+02'

Date Input
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

================  ========================================================================================
Example           Description
================  ========================================================================================
1999-01-08        ISO 8601; January 8 in any mode (recommended format)
January 8, 1999   unambiguous in any datestyle input mode
1/8/1999          January 8 in MDY mode; August 1 in DMY mode
1/18/1999         January 18 in MDY mode; rejected in other modes
01/02/03          January 2, 2003 in MDY mode; February 1, 2003 in DMY mode; February 3, 2001 in YMD mode
1999-Jan-08       January 8 in any mode
Jan-08-1999       January 8 in any mode
08-Jan-1999       January 8 in any mode
99-Jan-08         January 8 in YMD mode, else error
08-Jan-99         January 8, except error in YMD mode
Jan-08-99         January 8, except error in YMD mode
19990108          ISO 8601; January 8, 1999 in any mode
990108            ISO 8601; January 8, 1999 in any mode
1999.008          year and day of year
J2451187          Julian day
January 8, 99 BC  year 99 BC
================  ========================================================================================


Time Input
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

====================================  ========================================
Example                               Description
====================================  ========================================
04:05:06.789                          ISO 8601
04:05:06                              ISO 8601
04:05                                 ISO 8601
040506                                ISO 8601
04:05 AM                              same as 04:05; AM does not affect value
04:05 PM                              same as 16:05; input hour must be <= 12
04:05:06.789-8                        ISO 8601
04:05:06-08:00                        ISO 8601
04:05-08:00                           ISO 8601
040506-08                             ISO 8601
04:05:06 PST                          time zone specified by abbreviation
2003-04-12 04:05:06 America/New_York  time zone specified by full name
====================================  ========================================

Time Zone Input
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

================  ========================================
Example           Description
================  ========================================
PST               Abbreviation (for Pacific Standard Time)
America/New_York  Full time zone name
PST8PDT           POSIX-style time zone specification
-8:00             ISO-8601 offset for PST
-800              ISO-8601 offset for PST
-8                ISO-8601 offset for PST
zulu              Military abbreviation for UTC
z                 Short form of zulu
================  ========================================

Time Stamps
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

*  1999-01-08 04:05:06
*  1999-01-08 04:05:06 -8:00
*  January 8 04:05:06 1999 PST
*  TIMESTAMP '2004-10-19 10:23:54'
*  TIMESTAMP '2004-10-19 10:23:54+02'
*  TIMESTAMP WITH TIME ZONE '2004-10-19 10:23:54+02'


Special Date/Time Inputs
^^^^^^^^^^^^^^^^^^^^^^^^^^^

============  =====================   ==============================================
Input String  Valid Types             Description
============  =====================   ==============================================
epoch         date, timestamp         1970-01-01 00:00:00+00 (Unix system time zero)
infinity      date, timestamp         later than all other time stamps
-infinity     date, timestamp         earlier than all other time stamps
now           date, time, timestamp   current transaction's start time
today         date, timestamp         midnight today
tomorrow      date, timestamp         midnight tomorrow
yesterday     date, timestamp         midnight yesterday
allballs      time                    00:00:00.00 UTC
============  =====================   ==============================================

Date/Time Output Styles
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

===================  =====================  ============================
Style Specification  Description            Example
===================  =====================  ============================
ISO                  ISO 8601/SQL standard  1997-12-17 07:37:16-08
SQL                  traditional style      12/17/1997 07:37:16.00 PST
POSTGRES             original style         Wed Dec 17 07:37:16 1997 PST
German               regional style         17.12.1997 07:37:16.00 PST
===================  =====================  ============================

Date Order Conventions
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

=================  ==============  ============================
datestyle Setting  Input Ordering  Example Output
=================  ==============  ============================
SQL, DMY           day/month/year  17/12/1997 15:37:16.00 CET
SQL, MDY           month/day/year  12/17/1997 07:37:16.00 PST
Postgres, DMY      day/month/year  Wed 17 Dec 07:37:16 1997 PST
=================  ==============  ============================

ISO 8601 Interval Unit Abbreviations
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

============  ==========================
Abbreviation  Meaning
============  ==========================
Y             Years
M             Months (in the date part)
W             Weeks
D             Days
H             Hours
M             Minutes (in the time part)
S             Seconds
============  ==========================

Interval Input
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

====================  ====================================================================================================================
Example               Description
====================  ====================================================================================================================
1-2                   SQL standard format: 1 year 2 months
3 4:05:06             SQL standard format: 3 days 4 hours 5 minutes 6 seconds
1 year 2 months       3 days 4 hours 5 minutes 6 seconds  Traditional Postgres format: 1 year 2 months 3 days 4 hours 5 minutes 6 seconds
P1Y2M3DT4H5M6S        ISO 8601 "format with designators": same meaning as above
P0001-02-03T04:05:06  ISO 8601 "alternative format": same meaning as above
====================  ====================================================================================================================

Interval Output Style Examples
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

===================  ===================  ==============================  =================================================
Style Specification  Year-Month Interval  Day-Time Interval               Mixed Interval
===================  ===================  ==============================  =================================================
sql_standard         1-2                  3 4:05:06                       -1-2 +3 -4:05:06
postgres             1 year 2 mons        3 days 04:05:06                 -1 year -2 mons +3 days -04:05:06
postgres_verbose     @ 1 year 2 mons      @ 3 days 4 hours 5 mins 6 secs  @ 1 year 2 mons -3 days 4 hours 5 mins 6 secs ago
iso_8601             P1Y2M                P3DT4H5M6S                      P-1Y-2M3DT-4H-5M-6S
===================  ===================  ==============================  =================================================


Boolean Type
------------------------------------------------------


Boolean Data Type
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

=======  ============  ======================
Name     Storage Size  Description
=======  ============  ======================
boolean  1 byte        state of true or false
=======  ============  ======================

======  =======
TRUE    FALSE
======  =======
't'     'f'
'true'  'false'
'y'     'n'
'yes'   'no'
'on'    'off'
'1'     '0'
======  =======

References
======================================================

*  http://www.postgresql.org/docs/9.0/static/sql-createtype.html
*  http://www.postgresql.org/docs/9.1/static/datatype-enum.html
*  http://www.postgresql.org/docs/9.1/static/datatype-geometric.html
*  http://www.postgresql.org/docs/9.1/static/datatype-net-types.html
*  http://www.postgresql.org/docs/9.1/static/datatype-bit.html
*  http://www.postgresql.org/docs/9.1/static/datatype-textsearch.html
*  http://www.postgresql.org/docs/9.1/static/datatype-uuid.html
*  http://www.postgresql.org/docs/9.1/static/datatype-xml.html
*  http://www.postgresql.org/docs/9.1/static/arrays.html
*  http://www.postgresql.org/docs/9.1/static/rowtypes.html
*  http://www.postgresql.org/docs/9.1/static/datatype-oid.html
*  http://www.postgresql.org/docs/9.1/static/datatype-pseudo.html
*  http://www.postgresql.org/docs/9.1/static/sql-createtable.html
*  https://en.wikipedia.org/wiki/SQL#Data_types
*  http://www.informit.com/library/content.aspx?b=STY_Sql_24hours&seqNum=11
*  http://www.techonthenet.com/sql/datatypes.php
*  http://www.w3schools.com/SQL/sql_datatypes_general.asp
*  http://www.w3schools.com/sql/sql_datatypes_general.asp
*  https://en.wikipedia.org/wiki/SQL
*  http://www.informit.com/library/content.aspx?b=STY_Sql_24hours&seqNum=19
*  https://msdn.microsoft.com/en-us/library/ms378878%28v=sql.110%29.aspx



شهرهایی را به دست آورید که عرضه کنندگان آن شهرها بیشتر از ۱۰۰ باشد

نام و مجموعه عرضه‌های قطعه‌ها را به دست آورید


نام شهر قطعه‌هایی به دست آورید که بیشتر از دو عرضه کننده آنها را عرضه کننده، آنها را عرضه کرده باشد

نام قطعه‌هایی را به دست آورید که در بیشتر از دو شهر عرضه شده باشند

نام و مجموع وزن قطعه‌هایی را به دست آورید که در بیشتر از دو شهر عرضه شده باشند

شماره و نام عرضه کنندگانی را به دست آورید که مچموع عرضه آنها بیشتر از ۵۰ و بیشتر


شهرهایی را به دست آورید که عرضه کنندگان آن شهرها بیشتر از ۱۰۰ باشد

نام و مجموعه عرضه‌های قطعه‌ها را به دست آورید


نام شهر قطعه‌هایی به دست آورید که بیشتر از دو عرضه کننده آنها را عرضه کننده، آنها را عرضه کرده باشد

نام قطعه‌هایی را به دست آورید که در بیشتر از دو شهر عرضه شده باشند

نام و مجموع وزن قطعه‌هایی را به دست آورید که در بیشتر از دو شهر عرضه شده باشند

شماره و نام عرضه کنندگانی را به دست آورید که مچموع عرضه آنها بیشتر از ۵۰ و بیشتر

.. contents:: فهرست مطالب
   :depth: 2
   

.. comment:

  rst2s5.py rsts5.txt rsts5.html -d -t --section-numbering --stylesheet=farsi.css,html4css1.css
  rst2html  datatype.postgresql.rst   datatype.postgresql.html --stylesheet=../../tools/farsi.css,html4css1.css


