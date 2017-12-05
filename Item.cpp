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
int Item::getAccuracy(){
  return accuracy;
}
char* Item::getName(){
  return name;
}
