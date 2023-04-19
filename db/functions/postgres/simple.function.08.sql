-- =====================================
-- create functions

--DROP FUNCTION IF EXISTS get_year(INTEGER) ;
CREATE OR REPLACE FUNCTION get_year(INTEGER)
RETURNS INTEGER AS $$
BEGIN
  RETURN ( $1 / 10000);
END;
$$ LANGUAGE plpgsql
RETURNS NULL ON NULL INPUT;

--DROP FUNCTION IF EXISTS get_month(INTEGER) ;
CREATE OR REPLACE FUNCTION get_month(INTEGER)
RETURNS INTEGER AS $$
BEGIN
  RETURN ( $1 / 100 ) % 100 ;
END;
$$ LANGUAGE plpgsql
RETURNS NULL ON NULL INPUT;


--DROP FUNCTION IF EXISTS get_day(INTEGER);
CREATE OR REPLACE FUNCTION get_day(INTEGER)
RETURNS INTEGER AS $$
BEGIN
  RETURN $1  % 100 ;
END;
$$ LANGUAGE plpgsql
RETURNS NULL ON NULL INPUT;

--DROP FUNCTION IF EXISTS get_year_and_month(INTEGER) ;
CREATE OR REPLACE FUNCTION get_year_and_month(INTEGER)
RETURNS INTEGER AS $$
BEGIN
  RETURN ( $1 / 100);
END;
$$ LANGUAGE plpgsql
RETURNS NULL ON NULL INPUT;

--DROP FUNCTION IF EXISTS convert_int_date_to_varchar10(integer) ;
CREATE OR REPLACE FUNCTION convert_int_date_to_varchar10(integer)
RETURNS VARCHAR(10) AS $BODY$
BEGIN
  RETURN ( substring($1::text FROM 1 FOR 4) || '-' || substring($1::text FROM 5 FOR 2) || '-' || substring($1::text FROM 7 FOR 2) )::varchar(10);
END;
$BODY$ LANGUAGE plpgsql
RETURNS NULL ON NULL INPUT;


-- DROP FUNCTION IF EXISTS uniform_text_jdatei4search(text) ;
CREATE OR REPLACE FUNCTION uniform_text_jdatei4search(text)
RETURNS VARCHAR(10) AS $BODY$
DECLARE
  lmy_str1 varchar(10);
BEGIN
  lmy_str1 := substring($1 from '^[0-9]+') ;
  IF character_length(lmy_str1)=8 THEN
    RETURN (substring(lmy_str1 FROM 1 FOR 4) || '-' || substring(lmy_str1 FROM 5 FOR 2) || '-' || substring(lmy_str1 FROM 7 FOR 2) )::varchar(10);
  ELSEIF character_length(lmy_str1)=6 THEN
    RETURN (substring(lmy_str1 FROM 1 FOR 2) || '-' || substring(lmy_str1 FROM 3 FOR 2) || '-' || substring(lmy_str1 FROM 5 FOR 2) )::varchar(10);
  END IF;
END;
$BODY$ LANGUAGE plpgsql
RETURNS NULL ON NULL INPUT;

-- DROP FUNCTION IF EXISTS return_part_of_composit_idate(text,integer) ;
CREATE OR REPLACE FUNCTION return_part_of_composit_idate(text,integer)
RETURNS TEXT AS $BODY$
DECLARE
  lmy_astr1 TEXT ARRAY;
BEGIN
  lmy_astr1 := regexp_split_to_array($1 ,'\$\@') ;
  --RAISE NOTICE 'values are %', lmy_astr1[1];
  RETURN lmy_astr1[$2];
END;
$BODY$ LANGUAGE plpgsql
RETURNS NULL ON NULL INPUT;

-- DROP FUNCTION IF EXISTS is_leap_year(INTEGER) ;
CREATE OR REPLACE FUNCTION is_leap_year(INTEGER)
RETURNS INTEGER AS $$
DECLARE
  p INTEGER;
  leap INTEGER;
BEGIN
  p := ( ( $1 + 2346 ) % 2820 ) % 128 ;
  IF p = 5 OR p = 9 OR p = 13 OR p = 17 OR p = 21 OR p = 25 OR p = 29 OR
     p = 34 OR p = 38 OR p = 42  OR p = 46 OR p = 50 OR p = 54 OR p = 58 OR
     p = 62 OR p = 67 OR p = 71 OR p = 75  OR p = 79 OR p = 83 OR
     p = 87 OR p = 91 OR p = 95 OR p = 100 OR p = 104 OR p = 108 OR
     p = 112 OR p = 116 OR p = 120 OR p = 124 THEN
    leap := 1;
  ELSE
    leap := 0;
  END IF;
  RETURN leap ;
END;
$$ LANGUAGE plpgsql
RETURNS NULL ON NULL INPUT;

-- DROP FUNCTION IF EXISTS get_day_of_year(INTEGER) ;
CREATE OR REPLACE FUNCTION get_day_of_year(INTEGER)
RETURNS INTEGER AS $$
DECLARE
  day_tab INTEGER [][] := '{{0,31,31,31,31,31,31,30,30,30,30,30,29},{0,31,31,31,31,31,31,30,30,30,30,30,30}}';
  p INTEGER;
  leap INTEGER;
BEGIN
	p := ( ( ( $1 / 10000) + 2346 ) % 2820 ) % 128 ;
	IF p = 5 OR p = 9 OR p = 13 OR p = 17 OR p = 21 OR p = 25 OR p = 29 OR
	   p = 34 OR p = 38 OR p = 42  OR p = 46 OR p = 50 OR p = 54 OR p = 58 OR
	   p = 62 OR p = 67 OR p = 71 OR p = 75  OR p = 79 OR p = 83 OR
	   p = 87 OR p = 91 OR p = 95 OR p = 100 OR p = 104 OR p = 108 OR
	   p = 112 OR p = 116 OR p = 120 OR p = 124 THEN
		leap := 2;
	ELSE
		leap := 1;
	END IF;
	p :=0;
	FOR i IN 2..(( $1 / 100 ) % 100) LOOP
		p := p + day_tab[leap][i];
	END LOOP;
	p := p + $1  % 100 ;
	RETURN p ;
END;
$$ LANGUAGE plpgsql
RETURNS NULL ON NULL INPUT;
