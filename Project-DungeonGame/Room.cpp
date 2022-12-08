#include "Room.h"
#define ROOM_H_INCLUDED
#define ROOM_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
#include "Object.h"
using namespace std;

Room :: Room(){
}

    /* Set & Get function*/
void Room :: setUpRoom(Room* upRoom){
    this->upRoom=upRoom;
}
void Room :: setDownRoom(Room* downRoom){
    this->downRoom=downRoom;
}
void Room :: setLeftRoom(Room* leftRoom){
    this->leftRoom=leftRoom;
}
void Room :: setRightRoom(Room* rightRoom){
    this->rightRoom=rightRoom;
}
void Room :: setIsExit(bool isExit){
    this->isExit=isExit;
}
void Room :: setObjects(Object *o){
    this->o=o;
}
void Room :: setIndex(int index){
    this->index=index;
}

bool Room :: getIsExit(){
    return this->isExit;
}
Object*  Room :: getObjects(){
    return this->o;
}
Room* Room :: getUpRoom(){
    return this->upRoom;
}
Room* Room :: getDownRoom(){
    return this->downRoom;
}
Room* Room :: getLeftRoom(){
    return this->leftRoom;
}
Room* Room :: getRightRoom(){
    return this->rightRoom;
}
int Room :: getIndex(){
    return this->index;
}
