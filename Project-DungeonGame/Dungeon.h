#ifndef DUNGEON_H_INCLUDED
#define DUNGEON_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "Player.h"
#include "Monster.h"
#include "NPC.h"
#include "Room.h"
#include "Record.h"
using namespace std;

class Dungeon{
private://直接在dungeon裡面宣告大部分的物件
    Player player; //宣告一個Player物件
    Room room[8];
    Record record;
    Room nothing; //空房間
public:
    Dungeon();

    void loadPreviousData();

    /* Create a new player, and give him/her basic status */
    void createPlayer();

    /* Create a map, which include several different rooms */
    void createMap1();
    void createMap2();

    /* Deal with the player's action     */
    /* including showing the action list */
    /* that player can do at that room   */
    /* and dealing with player's input   */
    Room* chooseAction();

    /* Deal with player's moveing action */
    Room* handleMovement(Room*);

    /* Check whether the game should end or not */
    /* Including player victory, or he/she dead */
    bool checkGameLogic();
};


#endif // DUNGEON_H_INCLUDED
