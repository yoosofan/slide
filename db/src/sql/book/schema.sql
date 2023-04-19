CREATE TABLE "book" (
  "isbn" CHAR(13) PRIMARY KEY,
  "name" CHAR(30) ,
  "year" INT ,
  "نام نویسنده"     CHAR(20)
);
CREATE TABLE "member" (
  "ssn"   CHAR(15) PRIMARY KEY,
  "name"  CHAR(30),
  "year"  INT
);
CREATE TABLE "borrow"(
   "isbn" CHAR(13) REFERENCES "book",
   "ssn"  CHAR(15) REFERENCES "member",
   PRIMARY KEY("isbn","ssn")
);

insert into book values('12','قصه‌های خوب' , 1340,'علی آذری یزدی');
insert into book values('14','علی بابا و جراغ جادو', 1354,'فریبا حسنی');
insert into book values('16','قصه‌های مجید', 1365,'شهرزاد محمدی');



