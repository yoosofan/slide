DROP FUNCTION IF EXISTS test03();

CREATE FUNCTION test03() RETURNS INTEGER AS $ABC$
DECLARE
  quantity integer := 30;
  q2 integer := 30;
BEGIN
  -- RAISE NOTICE 'Quantity here is %', quantity; -- Prints 30
  SELECT somefunc03('S1','P1',q2);
  RETURN q2;
END;
$ABC$ LANGUAGE plpgsql;

/*
DROP FUNCTION IF EXISTS somefunc();


http://stackoverflow.com/questions/30782925/postgresql-how-to-drop-function-if-exists-without-specifying-parameters

*/
