DROP FUNCTION IF EXISTS somefunc2(VARCHAR(10),nm2 VARCHAR(10));

CREATE FUNCTION somefunc2(nm1 VARCHAR(10),nm2 VARCHAR(10)) 
RETURNS INTEGER AS $$
DECLARE
  quantity integer := 30;
BEGIN
  SELECT qty INTO quantity FROM sp WHERE sn=nm1 and pn=nm2;
  RAISE NOTICE 'Quantity here is %', quantity;
  RETURN quantity;
END;
$$ LANGUAGE plpgsql;

/*
DROP FUNCTION IF EXISTS somefunc();


http://stackoverflow.com/questions/30782925/postgresql-how-to-drop-function-if-exists-without-specifying-parameters

*/
