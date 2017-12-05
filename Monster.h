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
  //getters+setters from name, damage, and health
  char* getName();
  int getHP();
  void setHP(int hp);
  void setDamage(int d);
  int getDamage();
 private:
   char* name;
   //the monster's health
   int hp;
   //how much damage it deals
  int damage;
};
#endif
