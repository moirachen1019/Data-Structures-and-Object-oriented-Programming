#ifndef RECORD_H_INCLUDED
#define RECORD_H_INCLUDED

#include <iostream>
#include <vector>
#include "Item.h"
#include "Monster.h"
#include "NPC.h"
#include "Player.h"
using namespace std;
#include <fstream>
using std::ifstream;
using std::ofstream;

#include <sstream>
using std::stringstream;

/* This is the record system. Get the information of the  */
/* player and rooms then save them to (a) file(s). Notice */
/* that using pass by reference can prevent sending the   */
/* whole vector to the function.                          */

class Record
{
private:
    void savePlayer(Player*);
    void saveRooms(Room[]);
    int loadPlayer(Player* , string , Room[]);
    void loadInventory(Player*,string);
    void loadRooms(Room room[], string,int i);
    ifstream inStream;
    ofstream outStream;
    stringstream ss;

public:
    Record();
    void saveToFile(Player*,Room[] );
    //vector<Room>&
    void loadFromFile( Player* player, Room room[] );

};

#endif // RECORD_H_INCLUDED
