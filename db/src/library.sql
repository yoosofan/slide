CREATE TABLE book (
  isbn CHAR(13) PRIMARY KEY,
  bname CHAR(30) , -- book name
  pyear INT ,  --- publication_year
  category CHAR(20),
  author     CHAR(20),
  city CHAR(20)  -- publication city
);
CREATE TABLE member (
  ssn   CHAR(15) PRIMARY KEY,
  mname  CHAR(30), -- member name
  byear  INT, -- birth year
  category CHAR(20) REFERENCE book, -- most liked book category
  city CHAR(20)  -- member city
);
CREATE TABLE borrow(
  isbn CHAR(13) REFERENCES book,
  ssn  CHAR(15) REFERENCES member,
  PRIMARY KEY(isbn,ssn)
);

insert into book values('12','قصه‌های خوب' , 1340,'علی آذری یزدی');
insert into book values('14','علی بابا و جراغ جادو', 1354,'فریبا حسنی');
insert into book values('16','قصه‌های مجید', 1365,'شهرزاد محمدی');



