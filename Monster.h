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
  Monster(char* name);
  int getWS();
  int getBS();
  int getStrength();
  int getToughness();
  int getHP();
  void setWS(int w);
  void setBS(int b);
  void setStrength(int s);
  void setToughness(int t);
  void setHP(int hp);
  vector<Item*> getWeapons();
 private:
  vector<Item*> weapons;
  int weapon_skill;
  int ballistic_skill;
  int strength;
  int toughness;
  int hp;
};
#endif
