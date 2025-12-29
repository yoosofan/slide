#include<iostream>
#include<fstream>
using namespace std;
int main(){
  ifstream f1("input.integers.txt");
  //ifstream f1("folder2/folder3/file1.txt");
  //ifstream f1("../../folder2/folder3/file1.txt");
/* \\
  Relative addressing:
  آدرس دهی نسبی در این جا یعنی از پوشه‌ی کنونی یکی بالاتر برو
  سپس در آن پوشه به داخل پوشه‌ی folder2 برو سپس از آنجا به پوشه‌ی folder3 برو
  در آن پوشه‌ی آخری پرونده‌ای به نام file1.txt باید وجود داشته باشد
  ../folder2/folder3/file1.txt
 Absolute addressing
 آدرس دهی مطلق، مسیر را کامل از / مشخص می‌کند و دقیق مسیر مشخص می‌شود.
 /home/ahmad/folder2/file1.txt
 یا در ویندوز به صورت
 D:\\folder2\\file1.txt
 توضیح بیشتر درباره‌ی آن را در کلاس بپرسید تا توضیح دهم
*/
  if(!f1){
    cout<<"The file could not be opened "<<endl;
    throw 1;
  }
  int i; //cin>>i;
  f1 >> i;
  cout << i << endl;
  f1 >> i;
  cout << i << endl;
  f1.close();
}
