#ifndef Monster_H
#define Monster_H
#include <iostream>
#include <cstring>
#include "Item.h"
#include <vector>

using namespace std;

class Monster{
 public:
  //constructor
  Monster(char* nname);
  char* getName();
  int getHP();
  void setHP(int hp);
  void setDamage(int d);
  int getDamage();
 private:
   char* name;
   int hp;
  int damage;
};
#endif
