#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Room.h"
#include "Item.h"
using namespace std;

class Item;

class Player: public GameCharacter
{
private:
    Room* currentRoom;
    Room* previousRoom;
    vector<Item> inventory;
public:
    Player();
    Player(string,string,int,int,int,int);
    void addItem(Item);
    void increaseStates(int,int,int);

    /*show the status of player.*/
    void triggerEvent(Object*);

    void setCurrentRoom(Room*);
    void setPreviousRoom(Room*);
    void setInventory(vector<Item>);
    vector<Item>& getInventory();
    Room* getCurrentRoom();
    Room* getPreviousRoom();
};

#endif // PLAYER_H_INCLUDED
