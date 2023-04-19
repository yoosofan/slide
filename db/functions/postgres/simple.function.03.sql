DROP FUNCTION IF EXISTS somefunc03(VARCHAR(10),nm2 VARCHAR(10), o1 OUT INTEGER);

CREATE FUNCTION somefunc03(nm1 VARCHAR(10),nm2 VARCHAR(10), o1 OUT INTEGER) 
 AS $$
DECLARE
  quantity integer := 30;
BEGIN
  SELECT qty INTO quantity FROM sp WHERE sn=nm1 and pn=nm2;
  -- RAISE NOTICE 'Quantity here is %', quantity;
  o1:=quantity;
END;
$$ LANGUAGE plpgsql;

/*
DROP FUNCTION IF EXISTS somefunc();


http://stackoverflow.com/questions/30782925/postgresql-how-to-drop-function-if-exists-without-specifying-parameters

*/
