#include<fstream>
#include<iostream>
using namespace std;
const int MAX_STR = 200;
int main(){
  char st[MAX_STR];
  ifstream f1;
  f1.open("input.students.txt");
  if(!f1)
    cout << "couldn't open" << endl;
  else {
    f1.getline(st, MAX_STR - 1); // \n
    while(! f1.eof()){
      cout << st << endl;
      f1.getline(st, MAX_STR - 1);
    }
    f1.close();
  }
}
/* Rererence for more study
 * http://www.cplusplus.com/reference/fstream/fstream/open/
*/
