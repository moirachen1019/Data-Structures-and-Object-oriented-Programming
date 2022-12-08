#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
#include "Object.h"
using namespace std;

class Room
{
private:
    Room* upRoom;
    Room* downRoom;
    Room* leftRoom;
    Room* rightRoom;
    bool isExit;
    /*contain 1 or multiple objects, including monster, npc, etc*/
    Object *o;
    int index;

public:
    Room();
    /* Set & Get function*/
    void setUpRoom(Room*);
    void setDownRoom(Room*);
    void setLeftRoom(Room*);
    void setRightRoom(Room*);
    void setIsExit(bool);
    void setObjects(Object*);
    void setIndex(int);

    bool getIsExit();
    Object* getObjects();
    Room* getUpRoom();
    Room* getDownRoom();
    Room* getLeftRoom();
    Room* getRightRoom();
    int getIndex();
};

#endif // ROOM_H_INCLUDED
