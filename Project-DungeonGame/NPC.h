#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Player.h"
#include "Item.h"
using namespace std;

class NPC: public GameCharacter
{
private:
    string script;
    vector<Item> commodity;
public:
    NPC();
    NPC(string);
    void listCommodity(); /*print all the Item in this NPC*/

    /*deal with the transaction in easy implementation */
    void triggerEvent(Object*);

    void setScript();
    void setCommodity();
    string getScript();
    vector<Item> &getCommodity();
};


#endif // NPC_H_INCLUDED
