
UPDATE Library  
SET fpd = 
( 
CASE
    WHEN fpd<18 THEN fpd = fpd + 5
    WHEN fpd>=18 and fpd<24 THEN fpd = fpd + 8
    ELSE fpd = fpd + 10
END
)
