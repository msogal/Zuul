#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <cstring>
#include <map>
#include "Item.h"
#include "Monster.h"
#include <vector>
using namespace std;

class Room{
 public:
  //constructor
  Room(char* name, char* ndescription);
  //name of room
  char* getName();
  //set each room's exits to build the map of the labyrinth
  void addExit(char* direction, Room* r);
  //will be used only a couple times, for traps that shut doors
  void removeExit(char* direction, Room* r);
  //to start with an item in a room; also to pick up and drop items in a room
  void addItem(Item i);
  void removeItem(Item i);
  //to add Monsters to the room for the player to fight
  void addMonster(Monster m);
  //after the player has killed a monster, it will be removed
  void removeMonster(Monster m);
  //when the player enters, the room will say what it is
  void printDescription();
  //getters for the room's exits, items, and monsters in it
  map<char*, Room*> getExits();
  vector<Item*> getInventory();
  vector<Monster*> getMonsters();

 private:
  char* name;
  char* description;
  //holds the room's exits, each keyed to a cardinal direction
  map<char*, Room*>exits;
  //all the items in the room
  vector<Item*>inventory;
  //all the monsters in the room
  vector<Monster*>monsters;
};
#endif
