#include "Dungeon.h"
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

Dungeon :: Dungeon(){
}

void Dungeon :: loadPreviousData(){
        record.loadFromFile(&player, &room[0]);
}

/* Create a new player, and give him/her basic status */
void Dungeon :: createPlayer(){
    string PlayerName,PlayerType;
    cout<<"Please enter the player's name: ";
    cin>>PlayerName;
    cout<<"Choose the attribute of the player:"<<endl<<"water"<<endl<<"fire"<<endl<<"wind"<<endl<<"ground"<<endl;
    cin>>PlayerType;
//    Player p;
//    player=&p; //錯誤，因為p只會活在這個function內而已，但我們是整個dungeon要用
    player=Player(PlayerName,PlayerType,100, 100, 30, 10); //new一個Player物件並construct
    player.setCurrentRoom(&room[0]); //cur指向room[0]
    player.setPreviousRoom(&room[0]);
}

//     Create a map, which include several different rooms
void Dungeon :: createMap1(){ //把地圖link起來
    room[0].setRightRoom(&nothing);
    room[0].setDownRoom(&nothing);
    room[1].setDownRoom(&nothing);
    room[1].setUpRoom(&nothing);
    room[1].setLeftRoom(&nothing);
    room[2].setLeftRoom(&nothing);
    room[3].setUpRoom(&nothing);
    room[3].setDownRoom(&nothing);
    room[4].setUpRoom(&nothing);
    room[4].setDownRoom(&nothing);
    room[4].setRightRoom(&nothing);
    room[5].setRightRoom(&nothing);
    room[6].setUpRoom(&nothing);
    room[6].setRightRoom(&nothing);
    room[6].setLeftRoom(&nothing);
    room[7].setUpRoom(&nothing);
    room[7].setDownRoom(&nothing);
    room[7].setLeftRoom(&nothing);
    room[0].setLeftRoom( (room+1) ); //透過setter將room[0]的leftRoom指標指向room[1]
    room[1].setRightRoom( (room) );
    room[0].setUpRoom( (room+2) );
    room[2].setDownRoom( (room) );
    room[2].setRightRoom( (room+3) );
    room[3].setLeftRoom( (room+2) );
    room[3].setRightRoom( (room+4) );
    room[4].setLeftRoom( (room+3) );
    room[2].setUpRoom( (room+5) );
    room[5].setDownRoom( (room+2) );
    room[5].setUpRoom( (room+6) );
    room[6].setDownRoom( (room+5) );
    room[5].setLeftRoom( (room+7) );
    room[7].setRightRoom( (room+5) );
    for(int i=0;i<7;i++){
        room[i].setIsExit(false);
        room[i].setIndex(i);
    }
    room[7].setIsExit(true);
    room[7].setIndex(7);
    nothing.setIndex(-1); //空房間index為-1
}
void Dungeon :: createMap2(){ //在每個房間都放入物件
    NPC* npc1=new NPC("Liwei_Zhang");
    npc1->setCommodity();
    npc1->setScript();
    Object* object0=npc1; //upcasting，「子類別物件」交由「父類別參考」指著，安全，父親有的兒子一定有
    room[0].setObjects(object0);
    npc1 = dynamic_cast<NPC*>(object0); //downcasting，「父類別物件」交由「子類別參考」指著
//    NPC npc1("Liwei_Zhang");
//    npc1.setCommodity();
//    npc1.setScript();
//    room[0].setObjects(&npc1);

    Item* item1=new Item("Armor",10,10,20);
    Object* object1=item1;
    room[1].setObjects(object1);
    item1 = dynamic_cast<Item*>(object1);

    Monster* monster1=new Monster("Red_Bacteria","fire",100, 100, 50, 10);
    Object* object3=monster1;
    room[2].setObjects(object3);
    monster1 = dynamic_cast<Monster*>(object3);

    NPC* npc2=new NPC("Beautiful_ChunPei");
    npc2->setCommodity();
    npc2->setScript();
    Object* object2=npc2;
    room[3].setObjects(object2);
    npc2 = dynamic_cast<NPC*>(object2);

    Item* item2=new Item("Groza",10,30,0);
    Object* object4=item2;
    room[4].setObjects(object4);
    item2 = dynamic_cast<Item*>(object4);

    Monster* monster2=new Monster("Sticky_Baby","water",150,150,60,30);
    Object* object5=monster2;
    room[5].setObjects(object5);
    monster2 = dynamic_cast<Monster*>(object5);

    Item* item3=new Item("Remedy",50,10,10);
    Object* object6=item3;
    room[6].setObjects(object6);
    item3 = dynamic_cast<Item*>(object6);

    Monster* monster3=new Monster("Bad_James","wind",200,200,80,30);
    Object* object7=monster3;
    room[7].setObjects(object7);
    monster3 = dynamic_cast<Monster*>(object7);
}

/* Deal with the player's action     *//* including showing the action list */
/* that player can do at that room   */
/* and dealing with player's input   */
Room* Dungeon :: chooseAction(){
    cout<<"What do you want to do ?"<<endl;
    cout<<"1. Move"<<endl<<"2. Check status"<<endl<<"3. Save to file"<<endl;
    if( (player.getCurrentRoom()->getObjects())->getTag() == "NPC"){
        cout<<"4. Talk to NPC \""<<(player.getCurrentRoom()->getObjects())->getName()<<"\""<<endl;
    }
    else if( (player.getCurrentRoom()->getObjects())->getTag() == "Item"){
        cout<<"4. Pick up the item \""<<(player.getCurrentRoom()->getObjects())->getName()<<"\""<<endl;
    }
    else if( (player.getCurrentRoom()->getObjects())->getTag() == "Monster"){
        cout<<"4. Fight with the monster \""<<(player.getCurrentRoom()->getObjects())->getName()<<"\""<<endl;
    }
    int choice;
    cin>>choice;
    if(choice==1){
        player.setCurrentRoom(  handleMovement(player.getCurrentRoom()) );
        cout<<endl;
    }else if(choice==2){
        Object* nobody; //為了配合override triggerEvent建的空白物件
        player.triggerEvent(nobody); //nobody在函式裡面不會用到
    }else if(choice==3){
        record.saveToFile(&player, &room[0]);
        player.setTag("saved"); //標記為已儲存，等等跳出迴圈
    }else if( choice==4 ){
//        Object* player_object=player; //做upcasting，改成用Object的指標指向player的內容，但內容不會流失，之後做downcasting就可以轉回來>>其實不用那麼複雜
        ( player.getCurrentRoom()->getObjects() )->triggerEvent(&player); //把player的地址丟進triggerEvent，用Object的指標指著
        cout<<endl;
    }
}

/* Deal with player's moveing action */
Room* Dungeon :: handleMovement(Room* cur){
    cout<<"Which direction do you want to go ?"<<endl;
    if( (cur->getObjects())->getTag() == "Monster" ){ //房間有monster
        cout<<"1.Go back to previous room.(Your only moving choice)"<<endl;
        cout<<"2.Choose other actions."<<endl;
        int choice;
        cin>>choice;
        if(choice==1){
            Room* temp; //暫存的Room指標
            temp=cur;
            cur=player.getPreviousRoom();
            player.setPreviousRoom(temp);//cur和previous交換
            return cur;
        }
        else if(choice==2){
            chooseAction(); //重新選操作
        }
    }
    else{ //正常狀況
        if( ( (cur->getUpRoom() )->getIndex() )>=0 && ( (cur->getUpRoom() )->getIndex() )<8  ){
            cout<<"up"<<endl;
        }
        if( ( (cur->getDownRoom() )->getIndex() )>=0 && ( (cur->getDownRoom() )->getIndex() )<8  ){
            cout<<"down"<<endl;
        }
        if( ( (cur->getLeftRoom() )->getIndex() )>=0 && ( (cur->getLeftRoom() )->getIndex() )<8  ){
            cout<<"left"<<endl;
        }
        if( ( (cur->getRightRoom() )->getIndex() )>=0 && ( (cur->getRightRoom() )->getIndex() )<8  ){
            cout<<"right"<<endl;
        }
        player.setPreviousRoom(cur); //紀錄上一個房間
        string direction;
        cin>>direction;
        if(direction=="up"){
            cur=cur->getUpRoom();
            return cur;
        }else if(direction=="down"){
            cur=cur->getDownRoom();
            return cur;
        }else if(direction=="left"){
            cur=cur->getLeftRoom();
            return cur;
        }else if(direction=="right"){
            cur=cur->getRightRoom();
            return cur;
        }
    }
}

/* Check whether the game should end or not */
/* Including player victory, or he/she dead */
bool Dungeon :: checkGameLogic(){
    if( ( player.getCurrentHealth()<=0 ) ){ //玩家死亡
        cout<<"Game Over."<<endl;
        return false;
    }
    else if( (player.getCurrentRoom()->getIsExit()) && ( (player.getCurrentRoom())->getObjects())->getTag() == "Nothing" ){ //是出口且沒怪物
        cout<<"You win!"<<endl;
        return false;
    }else if( player.getTag()=="saved" ){
        cout<<"Save succeed! See you next time."<<endl;
        return false;
    }
    else{
        return true;
    }
}

