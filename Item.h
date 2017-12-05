#ifndef Item_H
#define Item_H
#include <iostream>
#include <cstring>
using namespace std;

class Item{
 public:
  //constructor
  Item(char* nname);
  //if the item is a weapon, how much damage it deals; otherwise, this will always be 0
  int getDamage();
  char* getName();
  void setDamage(int d);
 private:
  int damage;
  char*name;
};
#endif
