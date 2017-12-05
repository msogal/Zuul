#include<iostream>
#include <cstring>
#include "Monster.h"
#include "Item.h"
#include <vector>

using namespace std;

Monster::Monster(char* nname){
  name = nname;
}

char* Monster::getName(){
  return name;
}

int Monster::getHP(){
  return hp;
}

void Monster::setHP(int h){
  hp = h;
}
int Monster::getDamage(){
  return damage;
}
void Monster::setDamage(int d){
  damage = d;
}


