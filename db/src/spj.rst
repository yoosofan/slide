
S(sn_ ,sname,status,city)   
P(pn_ ,pname,color,weight,city)   
J(jn_ ,jname,budget,city)   
SPJ(sn_ , pn_ , jn_ ,qty)


1. نام عرضه‌کنندگانی که قطعهٔ قرمز رنگ عرضه کرده باشند.
2. نام پروژه‌هایی را بیابید که عرضه‌کننده‌ای از شهر خودشان برایش قطعه‌ای عرضه کرده باشند.
((S join SPJ) join J){jname}
3. نام عرضه‌کنندگانی را بیابید که قطعه‌ای عرضه کرده باشند که در شهر خودشان باشد و در پروژهٔ شهر خودشان نیز به کار گرفته شده باشد.
(SPJ join P join S join J){sname}
4. بودجه‌های پروژه‌هایی را بیابید که عرضه‌کننده‌ای از شهر خودشان برای آنها قطعه‌ای را عرضه نکرده باشند.

5. 6. 



بخش تستی آزمون


پایگاه داده‌های به کار گرفته شده در این آزمون

عرضه کنندگان قطعات

P(pn_, pname, color, weight, city) S(sn_, sname, status, city) SP(sn_, pn_, qty)

عرضه کنندگان قطعات پروژه‌ها

S(sn_ ,sname,status,city) P(pn_ ,pname,color,weight,city) J(jn_ ,jname,budget,city) SPJ(sn_ , pn_ , jn_ ,qty) 


