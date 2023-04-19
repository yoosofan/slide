#include<iostream>
using namespace std;
class device{
 public:
  string usage;
  //int hieght,width,depth;
  int color;
  int weight;
  int price;
  int longevity;
};
class industrialDevice: public device{};
class homeDevice: public device {};
class militaryDevice: public device{};

class electricalDevice: public device{
  int power;
  int voltage;
  bool isDc;
  
};
class washingMachine: public homeDevice, public electricalDevice{
};
class electricalDevice: public homeDevice{};
class nonElectrical: public device{};
class handyDevice: public device{};
class cookingDevice: public device {
};
class cleaningDevie: public device{
};
class hobbyDevice: public device{
};
