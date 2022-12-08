#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Player.h"
using namespace std;

class Monster: public GameCharacter
{
public:
    Monster();
    Monster(string,string,int,int,int,int);

    /* deal with the combat system.*/
    void triggerEvent(Object*);
};
#endif // ENEMY_H_INCLUDED
