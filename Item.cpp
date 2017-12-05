#include <iostream>
#include <cstring>
#include "Item.h"

using namespace std;
//constructor
Item::Item(char* nname){
  name = nname;
}
//getters and settes for damage
int Item::getDamage(){
  return damage;
}
void Item::setDamage(int d){
  damage = d;
}
char* Item::getName(){
  return name;
}
