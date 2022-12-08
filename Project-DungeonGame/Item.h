#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
#include "Object.h"
#include "Player.h"
using namespace std;

class Player;
//武器或道具，繼承Object
class Item: public Object //繼承Object
{
private:
    int health,attack,defense;
public:
    Item();
    Item(string, int, int, int);

    /*pick up item&add status to the player. */
    void triggerEvent(Object*);

    int getHealth();
    int getAttack();
    int getDefense();
    void setHealth(int);
    void setAttack(int);
    void setDefense(int);
};

#endif // ITEM_H_INCLUDED
