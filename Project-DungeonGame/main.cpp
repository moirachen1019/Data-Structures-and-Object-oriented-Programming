#include <iostream>
#include <string>
#include <vector>
#include "Dungeon.h"
#include "Item.h"
#include "Monster.h"
#include "NPC.h"
#include "Player.h"
#include <fstream>
using std::ifstream;
using std::ofstream;
using namespace std;

int main(){
    Dungeon dungeon;
    cout<<"Do you want to load previous data?"<<endl;
    cout<<"1. Yes"<<endl<<"2. No, start a new game."<<endl;
    int choice;
    cin>>choice;
    Record record;
    if(choice==1){ //���J���e���
        dungeon.loadPreviousData();
    }
    else{ //�S�����e��ơA����l��
        dungeon.createPlayer();
        dungeon.createMap1();
        dungeon.createMap2();
    }
    //�}�l�C��
    do{
        dungeon.chooseAction();
    }while(dungeon.checkGameLogic());

    return 0;

}
