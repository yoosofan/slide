DROP FUNCTION somefunc05_5(nm2 VARCHAR(10));
CREATE FUNCTION somefunc05_5(nm2 VARCHAR(10)) 
RETURNS SETOF sp AS $$
DECLARE
  i INTEGER :=0;
BEGIN
  RETURN QUERY SELECT * from sp where sn='S2';
  RETURN QUERY SELECT * FROM sp WHERE sn='S3';
  RETURN QUERY SELECT * FROM sp WHERE pn=nm2;
END;
$$ LANGUAGE plpgsql;
/*  OUTPUT
sp=# select somefunc05('S1','P1');
           somefunc05            
---------------------------------
 ("S1        ","P1        ",300)
 ("S2        ","P1        ",300)
 ("S2        ","P1        ",300)
 ("S2        ","P2        ",400)
 ("S3        ","P2        ",200)
(5 rows)
*/
