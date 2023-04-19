DROP FUNCTION somefunc05(nm1 VARCHAR(10),nm2 VARCHAR(10));
CREATE FUNCTION somefunc05(nm1 VARCHAR(10),nm2 VARCHAR(10)) 
RETURNS SETOF sp AS $$
DECLARE
  i INTEGER :=0;
BEGIN
  LOOP
    CASE i
      WHEN 1 THEN
        RETURN QUERY SELECT * from sp where sn='S2';
      WHEN 2 THEN
        RETURN QUERY SELECT * FROM sp WHERE sn='S3';
      ELSE
        RETURN QUERY (SELECT * FROM sp WHERE pn=nm2);
    END CASE;
    i:=i+1;
    EXIT WHEN i>2;
  END LOOP;
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
