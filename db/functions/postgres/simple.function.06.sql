DROP FUNCTION sf06() ;
CREATE FUNCTION sf06() 
RETURNS SETOF sp AS $$
DECLARE
  i INTEGER :=0;
  r sp%rowtype;
BEGIN
  FOR r IN SELECT * FROM sp LOOP
    CASE i
      WHEN 1 THEN
        RETURN NEXT r;
      WHEN 2 THEN
        RETURN NEXT r;
      ELSE
        RETURN NEXT r;
    END CASE;
    i:=i+1;
    EXIT WHEN i>2;
  END LOOP;
END;
$$ LANGUAGE plpgsql;
/*  OUTPUT
sp=# \i simple.function.06.sql 
CREATE FUNCTION
sp=# select * from sf06('S1','P1');
    sno     |    pno     | qty 
------------+------------+-----
 S1         | P1         | 300
 S1         | P2         | 200
 S1         | P3         | 400
(3 rows)
*/
