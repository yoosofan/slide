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
    RETURN (substring(lmy_str1 FROM 1 FOR 4) || '-' || substring(lmy_str1 FROM 5 FOR 2) )::varchar(10);
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


/*
DROP FUNCTION IF EXISTS get_shamsi_date(TIMESTAMP) ;
CREATE FUNCTION get_shamsi_date(TIMESTAMP) 
RETURNS VARCHAR(8) AS $$ 
DECLARE retVal VARCHAR(8);
BEGIN
  SELECT jtime."year"||jtime."month"||jtime."day" INTO retVal
  FROM jtime 
  WHERE CAST($1 AS DATE) =CAST(jtime."time"  AS DATE);
  --RAISE NOTICE 'retVal',retVal;
  RETURN retVal;
END;
$$ LANGUAGE plpgsql
RETURNS NULL ON NULL INPUT;

-- SELECT * FROM get_shamsi_date(CAST(transaction_timestamp() AS TIMESTAMP));
-- SELECT * FROM date_trunc('day',transaction_timestamp());
-- SELECT * FROM transaction_timestamp()::date;

CREATE FUNCTION get_density_of_a_day(TIMESTAMP t1) RETURNS DOUBLE PRECISION AS $$
BEGIN
  
END;
$$  LANGUAGE plpgsql
RETURNS NULL ON NULL INPUT;
*/
-- =====================================

/*
select "jtime"."time", t1.density 
from "jtime" , tank_density t1
where t1.start_date<="jtime"."time‍" and not exists 
      (select * from tank_density t2 where t2.start_date<="jtime"."time" and t1.start_date<t2.start_date);


select jt.time, t1.density 
from jtime as jt , tank_density t1
where t1.start_date<=jt.time and not exists 
      (select * from tank_density t2 where t2.start_date<=jt.time and t1.start_date<t2.start_date);

ERROR:  column  does not exist HINT:  Perhaps you meant to reference the column 
production_control/db/readdb/db2csv.py

-- ==============================
select json_build_object( 'x', this_table.mass_or_energy, 'y', round(sum("ارسال بین واحدی"))) 
from daily_pc_view as this_table join mass_or_energy_type 
                                  on this_table.mass_or_energy=mass_or_energy_type.mass_or_energy
where "ارسال بین واحدی" is not null 
      and mass_or_energy_type."type" in ('محصول','محصول اصلی')
group by this_table.mass_or_energy 
order by round(sum("ارسال بین واحدی"));

-- ==============================
with temporary_query as (
  select 'x', this_table.mass_or_energy, 'y', round(sum("ارسال بین واحدی")) as computed_sum
  from daily_pc_view as this_table join mass_or_energy_type 
                                    on this_table.mass_or_energy=mass_or_energy_type.mass_or_energy
  where "ارسال بین واحدی" is not null 
        and mass_or_energy_type."type" in ('محصول','محصول اصلی')
  group by this_table.mass_or_energy 
)
select json_build_object( 'x', mass_or_energy, 'y', computed_sum) 
from temporary_query
order by computed_sum;

-- ==============================
select json_build_object( 'x', this_table.mass_or_energy, 'y', computed_sum)
from daily_pc_view as this_table join mass_or_energy_type 
                                  on this_table.mass_or_energy=mass_or_energy_type.mass_or_energy
where "ارسال بین واحدی" is not null 
      and mass_or_energy_type."type" in ('محصول','محصول اصلی')
group by this_table.mass_or_energy 
order by round(sum("ارسال بین واحدی")) as computed_sum;
*/

CREATE OR REPLACE FUNCTION column_from_daily_pc_view(timee INTEGER, moe VARCHAR(30), column_name VARCHAR(30))
RETURNS FLOAT AS $val$
DECLARE
	val FLOAT;
BEGIN
   EXECUTE 'SELECT "' || column_name || '" AS value FROM daily_pc_view WHERE mass_or_energy = ''' || moe || ''' AND time = '|| timee INTO val;
   RETURN val;
END;
$val$ LANGUAGE plpgsql;

-- ==============================

CREATE OR REPLACE FUNCTION perform_price_formulas(mah INTEGER)
  RETURNS RECORD AS $$
DECLARE
  formula          price_formula%ROWTYPE;
  fob_price        product_food_or_other_price%ROWTYPE;
  real_price       DOUBLE PRECISION;
  ret_val          RECORD;
  mass_or_energies VARCHAR(30) [];
BEGIN
  FOR formula IN SELECT *
                 FROM price_formula
  LOOP
    SELECT *
    FROM product_food_or_other_price
    WHERE month = mah
          AND product_food_or_other = formula.second_product_or_food
          AND price_type = 'قیمت FOB'
    INTO fob_price;

    IF fob_price IS NULL
    THEN
      -- Add this mass or energy to array to show error message
      mass_or_energies = array_append(mass_or_energies, formula.second_product_or_food);
      CONTINUE;
    END IF;

    BEGIN
      -- Calculate the price
      real_price = fob_price.price * formula.slope + formula.y_intercept;
      -- Insert the price into product_food_or_other_price relation
      INSERT INTO product_food_or_other_price
      VALUES (mah, formula.product_or_food, 'قیمت واقعی', real_price);
      -- If the price exists update it
      EXCEPTION WHEN unique_violation
      THEN
        UPDATE product_food_or_other_price
        SET price = real_price
        WHERE month = mah
              AND product_food_or_other = formula.product_or_food
              AND price_type = 'قیمت واقعی';

    END;
  END LOOP;

  SELECT
    0                                                    AS "errno",
    format('فرمول با موفقیت برای ماه %s اعمال شد.', mah) AS "errmsg"
  INTO ret_val;

  IF array_length(mass_or_energies, 1) != 0
  THEN
    ret_val.errno = 1;
    -- Remove duplicate values from array
    SELECT ARRAY(SELECT DISTINCT UNNEST(mass_or_energies)
                 ORDER BY 1)
    INTO mass_or_energies;
    -- Concat values in array
    ret_val.errmsg = format('قیمت FOB برای %s در ماه %s یافت نشد',
                            array_to_string(mass_or_energies, ' و '), mah);
  END IF;

  RETURN ret_val;
END
$$ LANGUAGE plpgsql
RETURNS NULL ON NULL INPUT;
