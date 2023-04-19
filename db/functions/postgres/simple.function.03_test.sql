DROP FUNCTION IF EXISTS test03();
CREATE FUNCTION test03() RETURNS INTEGER AS $ABC$
DECLARE
  quantity integer := 30;
  q2  integer  := 30;
  snp varchar(10) := 'S1';
  pnp varchar(10) := 'P1';
BEGIN
  -- RAISE NOTICE 'Quantity here is %', quantity; -- Prints 30
  SELECT somefunc03(snp,pnp,q2);
  RETURN q2;
END;
$ABC$ LANGUAGE plpgsql;

/*
DROP FUNCTION IF EXISTS somefunc();


http://stackoverflow.com/questions/30782925/postgresql-how-to-drop-function-if-exists-without-specifying-parameters

*/
