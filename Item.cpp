#include <iostream>
#include <cstring>
#include "Item.h"

using namespace std;
Item::Item(char* nname){
  name = nname;
}
int Item::getDamage(){
  return damage;
}
void Item::setDamage(int d){
  damage = d;
}
char* Item::getName(){
  return name;
}
