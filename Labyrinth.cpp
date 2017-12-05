#include <iostream>
#include <cstring>
#include "Item.h"
#include "Monster.h"
#include "Room.h"

using namespace std;

int main(){
  //setup
  //create each room, with the monsters and items that go in it. Also set the description for each room (the info given to player upon entering)
  Room* entrance = new Room("Entrance", " ");
  Room* room16 = new Room("room16", " ");
  Room*  room17 = new Room("room17", " ");
  Room* room14 = new Room("room14", " ");
  Room* room15 = new Room("room15", " ");
  Room* room9 = new Room("room9", " ");
  Room* room8 = new Room("room8", " ");
  Room* room3 = new Room("room3", " ");
  Room* room2 = new Room("room2", " ");
  Room* room5 = new Room("room5", " ");
  Room* room6 = new Room("room6", " ");
  Room* room7 = new Room("room7", " ");
  Room* room1 = new Room("room1", " ");
  Room* room10 = new Room("room10", " ");
  Room* room11 = new Room("room11", " ");
  Room* room12 = new Room("room12", " ");
  Room* room13 = new Room("room13", " ");
  Room* room4 = new Room("room4", " ");
  Room* mino_layer = new Room("mlayer", " ");
  //create the map by setting the exits that it has 
  entrance->addExit("NORTH", room17);
  entrance->addExit("WEST", room16);
  entrance->addExit("EAST", room8);



  return 0;
}
