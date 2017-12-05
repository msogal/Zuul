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
char* Room::getDescription(){
  return description;
}
void Room::addExit(char* direction, Room* r){
  exits.insert(pair<char*, Room*>(direction, r));
}
void Room::addItem(Item* i){
  inventory.push_back(i);

}
  void Room::removeItem(Item* i){
   for(vector<Item*>::iterator it = inventory.begin(); it != inventory.end(); it++){
     //search the inventory for that item by name, then delete it
     if(strcmp((*it)->getName(), i->getName())==0){
       inventory.erase(it);
       break;
     }
   }
 }
  void Room::addMonster(Monster* m){
    monsters.push_back(m);
  }
  void Room::removeMonster(Monster* m){
    for(vector<Monster*>::iterator it = monsters.begin(); it != monsters.end(); it++){
      if(strcmp((*it)->getName(), m->getName())==0){
	monsters.erase(it);
	break;
      }
    }
  }
  map<char*, Room*> Room::getExits(){
    return exits;
  }
  vector<Item*> Room::getInventory(){
    return inventory;
    
  }
vector<Monster*> Room::getMonsters(){
  return monsters;
}

//returns the next room in a certain direction:
Room* Room::nextRoom(char* direction){
  for(map<char* , Room*>::iterator it = exits.begin(); it != exits.end(); it++){
    if(strcmp(direction, get<0>(*it))==0){
      return get<1>(*it);
    }
    return new Room("noexit", " ");
  }
}
//list the names of all Monsters in this room
void Room::printMonsters(){
  cout<<"Monsters: "<<endl;
  for(vector<Monster*>::iterator it = monsters.begin(); it != monsters.end(); it++){
    cout<<(*it)->getName()<<endl;
  }
}
//list the names of all items in this room
void Room::printItems(){
  cout<<"Items: "<<endl;
  for(vector<Item*>::iterator it = inventory.begin(); it != inventory.end(); it++){
    cout<<(*it)->getName()<<endl;
  }
}
//lists the exits
void Room::printExits(){
  cout<<"There are exits: "<<endl;
  for(map<char*, Room*>::iterator it = exits.begin(); it != exits.end(); it++){
    cout<<get<0>(*it)<<endl;
  }
}
