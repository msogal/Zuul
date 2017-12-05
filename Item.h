#ifndef Item_H
#define Item_H
#include <iostream>
#include <cstring>
using namespace std;

class Item{
 public:
  //constructor
  Item(char* nname);
  int getDamage();
  int getAccuracy();
  char* getName();
 private:
  int damage;
  int accuracy;
  char*name;
};
#endif
