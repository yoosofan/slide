DROP FUNCTION IF EXISTS somefunc(VARCHAR(10));

CREATE FUNCTION somefunc(nm1 VARCHAR(10)) RETURNS INTEGER AS $ABC$
<< outerblock >>
DECLARE
  quantity integer := 30;
BEGIN
  -- RAISE NOTICE 'Quantity here is %', quantity; -- Prints 30
  SELECT status INTO quantity FROM s WHERE sn=nm1;
  quantity := quantity *50;
  /*
  -- Create a subblock
  --
  RAISE NOTICE 'Quantity here is %', quantity;*/
  RETURN quantity;
END;
$ABC$ LANGUAGE plpgsql;

/*
DROP FUNCTION IF EXISTS somefunc();


http://stackoverflow.com/questions/30782925/postgresql-how-to-drop-function-if-exists-without-specifying-parameters

*/
