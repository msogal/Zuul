#include<iostream>
#include <cstring>
#include "Monster.h"
#include "Item.h"
#include <vector>

using namespace std;

Monster::Monster(char* nname){
  name = nname;
}

int Monster::getWS(){
  return weapon_skill;
}

int Monster::getStrength(){
  return strength;
}
int Monster::getToughness(){
  return toughness;
}
int Monster::getHP(){
  return hp;
}
int Monster::getAttacks(){
  return attacks;
}

void Monster::setWS(int w){
  weapon_skill = w;
}

void Monster::setStrength(int s){
  strength = s;
}
void Monster::setToughness(int t){
  toughness = t;
}
void Monster::setHP(int h){
  hp = h;
}

int Monster::attack(Item i){
  //add code later
}
