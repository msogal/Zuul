#include <iostream>
#include <cstring>
#include "Room.h"
#include "Item.h"
#include "Monster.h"
#include<vector>
#include<map>

using namespace std;
//constructor; takes name and description
Room::Room(char* nname, char* ndescription){
  name = nname;
  description = ndescription;
}
//getters and setters; also has functions to add items and monsters
char* Room::getName(){
  return name;
}
void Room::addExit(char* direction, Room* r){
  exits.insert(pair<char*, Room*>(direction, r));
}
void Room:: removeExit(char* direction, Room* r){
    //code will be added later
}
  void Room::addItem(Item i){
  inventory.push_back(i);

}
  void Room::removeItem(Item i){
   for(vector<Item>::iterator it = inventory.begin(); it != inventory.end(); it++){
     //search the inventory for that item by name, then delete it
     if(strcmp(it->getName(), i.getName())==0){
       inventory.erase(it);
       break;
     }
   }
 }
  void Room::addMonster(Monster m){
    monsters.push_back(m);
  }
  void Room::removeMonster(Monster m){
    for(vector<Monster>::iterator it = monsters.begin(); it != monsters.end(); it++){
      if(strcmp(it->getName(), m.getName())==0){
	monsters.erase(it);
	break;
      }
    }
  }
  map<char*, Room*> Room::getExits(){
    return exits;
  }
  vector<Item> Room::getInventory(){
    return inventory;
    
  }
vector<Monster> Room::getMonsters(){
  return monsters;
}
