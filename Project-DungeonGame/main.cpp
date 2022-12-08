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
    if(choice==1){ //載入先前資料
        dungeon.loadPreviousData();
    }
    else{ //沒有先前資料，做初始化
        dungeon.createPlayer();
        dungeon.createMap1();
        dungeon.createMap2();
    }
    //開始遊戲
    do{
        dungeon.chooseAction();
    }while(dungeon.checkGameLogic());

    return 0;

}
