CREATE FUNCTION somefunc() RETURNS integer AS $$
<< outerblock >>
DECLARE
  quantity integer := 30;
BEGIN
  RAISE NOTICE 'Quantity here is %', quantity; -- Prints 30
  quantity := 50;
  --
  -- Create a subblock
  --
  DECLARE
    quantity integer := 80;
  BEGIN
    RAISE NOTICE 'Quantity here is %', quantity; -- Prints 80
    RAISE NOTICE 'Outer quantity here is %', outerblock.quantity;
  END;
  RAISE NOTICE 'Quantity here is %', quantity;
  -- Prints 50
  -- Prints 50
  RETURN quantity;
END;
$$ LANGUAGE plpgsql;

/*
DROP FUNCTION IF EXISTS somefunc();


http://stackoverflow.com/questions/30782925/postgresql-how-to-drop-function-if-exists-without-specifying-parameters

*/
