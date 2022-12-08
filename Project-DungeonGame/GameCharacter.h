#ifndef GAMECHARACTER_H_INCLUDED
#define GAMECHARACTER_H_INCLUDED
#include <iostream>
#include <string>
#include "Object.h"
using namespace std;

class GameCharacter: public Object
{
private:
    string name;
    string type; //ÄÝ©Ê
    int maxHealth;
    int currentHealth;
    int attack;
    int defense;
public:
    GameCharacter();
    GameCharacter(string,string);
    GameCharacter(string,string,string,int,int,int,int);
    bool checkIsDead();

    void setMaxHealth(int);
    void setCurrentHealth(int);
    void setAttack(int);
    void setDefense(int);
    void setType(string);

    int getMaxHealth();
    int getCurrentHealth();
    int getAttack();
    int getDefense();
    string getType();
};
#endif // GAMECHARACTER_H_INCLUDED
