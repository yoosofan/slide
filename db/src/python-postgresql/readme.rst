create view student_average as
  select student_id, avg(marks) as average_marks
  from student_marks
  group by studnet_id
;

https://www.codevoila.com/post/2/python3-connect-postgresql-with-psycopg2-on-ubuntu

sudo apt-get install libpq-dev
sudo apt-get install libpq-dev
sudo apt-get install python3-psycopg2
sudo apt-get install python3-pip
sudo pip3 install psycopg2
pip3 install psycopg2


GRANT ALL PRIVILEGES ON DATABASE sp TO ali;
GRANT CONNECT ON DATABASE sp TO ali;

GRANT ALL PRIVILEGES ON ALL TABLES IN SCHEMA public TO ali;



postgresql psycopg2.errors.InsufficientPrivilege: permission denied for table
postgresql grant all privileges to user
https://tableplus.com/blog/2018/04/postgresql-how-to-grant-access-to-users.html
https://poanchen.github.io/blog/2018/03/07/How-to-fix-permission-denied-for-relation-some_table_name-in-PostgreSQL
https://www.codegrepper.com/code-examples/sql/psycopg2.errors.InsufficientPrivilege%3A+permission+denied+for+table+django_migrations
https://stackoverflow.com/questions/60138692/sqlalchemy-psycopg2-errors-insufficientprivilege-permission-denied-for-relation
https://www.postgresql.org/docs/9.0/sql-grant.html


pip3 install psycopg2 error ubuntu
https://www.codevoila.com/post/2/python3-connect-postgresql-with-psycopg2-on-ubuntu
https://stackoverflow.com/questions/47318227/cannot-install-psycopg2-ubuntu/62732659
https://stackoverflow.com/questions/11583714/install-psycopg2-on-ubuntu




https://www.postgresqltutorial.com/plpgsql-assert/
https://www.postgresql.org/docs/7.3/sql-createtable.html
https://stackoverflow.com/questions/9657048/constraints-and-assertions-in-postgresql#:~:text=As%20%40ruakh%20already%20cleared%20up,%3A%20INSERT%2C%20UPDATE%2C%20DELETE.


postgresql materialized view concurrently
https://www.postgresqltutorial.com/postgresql-materialized-views/
https://www.postgresql.org/docs/9.4/sql-creatematerializedview.html
https://www.postgresql.org/docs/9.4/sql-refreshmaterializedview.html
