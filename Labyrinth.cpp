/*
Labyrinth is a game where you navigate a maze and fight monsters
By Mihira Sogal 
12/4/2017
 */

#include <iostream>
#include <cstring>
#include "Item.h"
#include "Monster.h"
#include "Room.h"
#include <vector>
#include <map>
using namespace std;

Item* itemByName(char itemname[80], vector<Item*> v);

int main(){
  //setup
  //create each room, with the monsters and items that go in it. Also set the description for each room (the info given to player upon entering)
  Room* entrance = new Room("Entrance", "you are in the enterance of the Labyrinth ");
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
  Room* exit = new Room("exit", " ");
  Room* mino_layer = new Room("mlayer", " ");
  //create the map by setting the exits that it has
  //add exits to enterance
  entrance->addExit("NORTH", room17);
  entrance->addExit("WEST", room16);
  entrance->addExit("EAST", room8);
  //add exits to room16
  room16->addExit("NORTH", room14);
  room16->addExit("EAST", room17);
  //add exits to room 17
  room17->addExit("NORTH", room15);
  room17->addExit("WEST", room16);
  room17->addExit("SOUTH", entrance);
  //add exits to room14
  room14->addExit("EAST", room15);
  room14->addExit("NORTH", room9);
  room14->addExit("SOUTH", room16);
  //add exits to room 15
  room15->addExit("NORTH", room8);
  room15->addExit("SOUTH", room17);
  room15->addExit("WEST", room14);
  //add exits to room 9
  room9->addExit("NORTH", room2);
  room9->addExit("SOUTH", room14);
  room9->addExit("EAST", room8);
  room9->addExit("WEST", room3);
  //add exits to room 8
  room8->addExit("NORTH", room7);
  room8->addExit("SOUTH", room15);
  room8->addExit("WEST", room9);
  //add exits to room 3
  room3->addExit("NORTH", mino_layer);
  room3->addExit("EAST", room9);
  //add exits to room 13
  room13->addExit("NORTH", room11);
  room13->addExit("EAST", room4);
  //add exits to room 5
  room5->addExit("EAST", room6);
  room5->addExit("WEST", room1);
  room5->addExit("SOUTH", room2);
  //add exits to room 6
  room6->addExit("SOUTH", room7);
  room6->addExit("WEST", room5);
  //add exits to room 7
  room7->addExit("NORTH", room6);
  room7->addExit("SOUTH", room8);
  room7->addExit("WEST", room2);
  //add exits to room1
  room1->addExit("SOUTH", mino_layer);
  room1->addExit("EAST", room5);
  room1->addExit("WEST", room10);
  //add exits to room10
  room10->addExit("NORTH", room12);
  room10->addExit("SOUTH", room4);
  room10->addExit("EAST", room1);
  room10->addExit("WEST", room11);
  //add exits to room11
  room11->addExit("NORTH", room12);
  room11->addExit("SOUTH", room2);
  room11->addExit("EAST", room1);
  //add exits to room 12
  room12->addExit("NORTH", exit);
  room12->addExit("SOUTH", room11);
  room12->addExit("EAST", room10);
  //add exits to room2
  room2->addExit("NORTH", room5);
  room2->addExit("SOUTH", room9);
  room2->addExit("EAST", room7);
  room2->addExit("WEST", mino_layer);
  //add exits to room4
  room4->addExit("NORTH", room10);
  room4->addExit("EAST", mino_layer);
  room4->addExit("WEST", room13);
  //add exits to the maze exit room
  exit->addExit("SOUTH", room12);
  //add exits to the minotaur's layer
  mino_layer->addExit("NORTH", room1);
  mino_layer->addExit("SOUTH", room3);
  mino_layer->addExit("EAST", room2);
  mino_layer->addExit("WEST", room4);

  //create items. Place a pointer to that item in a main vector that stores all the items, and another pointer to that item in the room where it goes
  vector<Item*> main_inventory;
 
  Item* astring = new Item("Ariadne's string");
  astring->setDamage(0);
  Item* astring2 = astring;
  room17->addItem(astring2);
  main_inventory.push_back(astring);

  Item* sword = new Item("Sword");
  sword->setDamage(3);
  Item* sword2 = sword;
  room1->addItem(sword2);
  main_inventory.push_back(sword);
    
  Item* axe = new Item("Axe");
  axe->setDamage(5);
  Item* axe2 = axe;
  room4->addItem(axe2);
  main_inventory.push_back(axe);

  Item* mirror = new Item("Mirror");
  mirror->setDamage(0);
  Item* mirror2 = mirror;
  room7->addItem(mirror2);
  main_inventory.push_back(mirror);
  
  Item* shield = new Item("Shield");
  shield->setDamage(0);
  Item*shield2 = shield;
  room2->addItem(shield2);
  main_inventory.push_back(shield);

  
  //add the monsters to their rooms
  Monster* minotaur = new Monster("Minotaur");
  minotaur->setHP(15);
  minotaur->setDamage(7);
  mino_layer->addMonster(minotaur);
  Monster* medusa = new Monster("Medusa");
  medusa->setHP(12);
  medusa->setDamage(3);
  room9->addMonster(medusa);

  //set up the player's health
  int hp = 10;

  vector<Item*> inventory; //keeps track of what the player has picked up
  //the player starts with a knife
  Item* knife = new Item("knife");
  knife->setDamage(1);
  Item* knife2 = knife;
  main_inventory.push_back(knife2);
  inventory.push_back(knife);
    
  vector<Room*> travelled; //tracks which rooms the player has been to

  //set the current room to the entrance
  Room* current_room = entrance;

  //introduce the game
  cout<<"Welcome to Labyrinth"<<endl<<"In this game, you will try and find your way out of a maze, and slay the legendary Minotaur."<<endl<<"Remember, you need to kill the Minotaur, AND escape alive to win!"<<endl;
  //main loop; repeatedly ask the player for an action (move, pick up an object, drop and object, do nothing)
  bool playing = true;
  while(playing){
    //print the current room description, if there is one
    cout<<current_room->getName();
    /*if(!(strcmp(current_room->getDescription(), " ")==0)){
      cout<<current_room->getDescription();
    }else{//give the generic room description
      cout<<"You are in a room of the Labyrinth"<<endl;
      }*/


    //if the player has already travelled here, and they have Ariadne's string, tell them
    //check for the string
    bool has_string = false;
    if(!inventory.empty()){
    for(vector<Item*>::iterator it = inventory.begin(); it != inventory.end(); it++){
      if(strcmp((*it)->getName(), "Ariadne's string")==0){
	has_string = true;
      }
    }
    }
    //check if the player has been here
    bool travelled_here = false;
    if(!travelled.empty()){
    for(vector<Room*>::iterator it = travelled.begin(); it != travelled.end(); it++){
      if(strcmp((*it)->getName(), current_room->getName())==0){
	travelled_here = true;
      }
      
    }
    }
    //if both are true, tell the player
    if(has_string && travelled_here){
      cout<<"You have been here before"<<endl;
    }

    
    //print exits of the current room
    current_room->printExits();
    //present items and/or monsters in the current room; fight monsters
    //first, list all the items in the room
    cout<<"There are the following items in the room: "<<endl;
    if(!current_room->getInventory().empty()){
      current_room->printItems();
    }
    //then, list the monsters, and have the player fight them
    if(!current_room->getMonsters().empty()){
      cout<<"These monsters are in the room!: "<<endl;
      current_room->printMonsters();
      cout<<"Choose a weapon to fight them with! (by typing in the item's name"<<endl;
      cout<<"This is what you are carrying: "<<endl;
      if(!inventory.empty()){
	for(vector<Item*>::iterator it = inventory.begin(); it != inventory.end(); it++){
	  cout<<(*it)->getName();
	}
      }
      //choose weapon
      Item* weapon;
      char choose_weapon [80];
      cin.get(choose_weapon, 80);
      cin.ignore(80, '\n');
      if(!inventory.empty()){
	//find the first match
	for(vector<Item*>::iterator it = inventory.begin(); it != inventory.end(); it++){
	  if(strcmp((*it)->getName(), choose_weapon)==0){
	    weapon = *it;
	    break;
	  }
	}
      }
      //fight with the monsters
      int dead_monsters = 0;
      for(vector<Monster*>::iterator it = current_room->getMonsters().begin(); it != current_room->getMonsters().end(); it++){
	hp -= (*it)->getDamage();
	(*it)->setHP((*it)->getHP() - weapon->getDamage());
	if((*it)->getHP()==0){
	  dead_monsters++;
	}
      }
      //remove dead monsters
      for(int i = 0; i < dead_monsters; i++){
	for(vector<Monster*>::iterator it = current_room->getMonsters().begin(); it != current_room->getMonsters().end(); it++){
	  if((*it)->getHP()==0){
	    //monster is dead
	    delete (*it);
	    current_room->getMonsters().erase(it);
	    break;
	  }
	}
      }
      
    }
    
    
    //prompt for action
    cout<<"Enter what you want to do"<<endl;
    cout<<"Type 'MOVE' to take an exit"<<endl;
    cout<<"Type 'TAKE' to pick up an item"<<endl;
    cout<<"Type 'DROP' to drop an item"<<endl;
    cout<<"Hit any key to do nothing and stay in this room"<<endl;
    cout<<"Type 'QUIT' to quit"<<endl;

    char action[80];
    cin.get(action, 80);
    cin.ignore(80, '\n');
    if(strcmp(action, "MOVE")==0){
      //change the current room
      Room* r = current_room;
      travelled.push_back(r);//logs having been to the current room
      //chose which exit to take
      char ext[80];
      cout<<"Which exit do you wish to take?"<<endl;
      cin.get(ext, 80);
      cin.ignore(80, '\n');
      current_room = current_room->nextRoom(ext);
    }else if(strcmp(action, "TAKE")==0){
      //pick up an item: go through the main inventory until a match is found; then, create an Item* in the player inventory pointing to that item. Finally, remove the corresponding item* from the room
      cout<<"Enter the name of the item you wish to take"<<endl;
      char itemname[80];
      cin.get(itemname, 80);
      cin.ignore(80, '\n');
      //add to player inventory
      Item* i = itemByName(itemname, current_room->getInventory());
      inventory.push_back(i);
      //remove from room
      current_room->removeItem(i);

      
    }else if(strcmp(action, "DROP")==0){
      //drop the item; find a match, then add a pointer to the current room pointing to it. Then erase from the player inventory
      char itemname[80];
      cout<<"Enter the name of the item you wish to drop"<<endl;
      cin.get(itemname, 80);
      cin.ignore(80, '\n');
      //add to room
      Item* i = itemByName(itemname, inventory);
      current_room->addItem(i);
      //remove from player
      if(!current_room->getInventory().empty()){
	for(vector<Item*>::iterator it = inventory.begin(); it != inventory.end(); it++){
	  if(strcmp((*it)->getName(), itemname)==0){
	    inventory.erase(it);
	    break;
	  }
	}
      }
    }else if(strcmp(action, "QUIT")==0){
      playing = false;
    }
  
    //now check for victory and defeat conditions
    if(hp ==0){
      //you die and lose
      cout<<"You are dead"<<endl;
      playing = false;
    }
    //check if the minotaur is alive, by seeing it it's lair is empty
    if(strcmp(current_room->getName(), exit->getName())==0 && mino_layer->getMonsters().empty()){
      cout<<"You win!!"<<endl;
      playing = false;
    }
  }
  

  return 0;
}
Item* itemByName(char itemname[80], vector<Item*> v){
  if(!v.empty()){
    for(vector<Item*>::iterator it = v.begin(); it != v.end(); it++){
      if(strcmp((*it)->getName(), itemname)==0){
	return *it;
      }
					    
    }
  }
 
}




