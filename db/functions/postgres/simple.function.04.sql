DROP FUNCTION somefunc04(nm1 VARCHAR(10)) ;
CREATE FUNCTION somefunc04(nm1 VARCHAR(10)) 
RETURNS SETOF sp AS $$
BEGIN
  IF nm1='S1' THEN
    RETURN QUERY SELECT * FROM sp WHERE sn='S2';
  ELSE
    RETURN QUERY SELECT * FROM sp WHERE sn=nm1 ;
  END IF;
END;
$$ LANGUAGE plpgsql;
/*  OUTPUT
sp=# select somefunc04('S2');
           somefunc04            
---------------------------------
 ("S2        ","P1        ",300)
 ("S2        ","P2        ",400)
(2 rows)
*/
