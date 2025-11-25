#pragma once
#include <iostream>
#include <cmath>
using namespace std;
class complexCls{ double r,i;
 public:
  complexCls(int m=0,int n=0);
  void Show();
  double Magnitude();
  void input();
  complexCls add(complexCls b);
  friend complexCls add(complexCls a, complexCls b);
};
