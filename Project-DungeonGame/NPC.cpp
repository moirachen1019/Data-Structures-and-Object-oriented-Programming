#include "NPC.h"
#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Player.h"
#include "Item.h"
using namespace std;

NPC :: NPC() : GameCharacter(){
}
NPC :: NPC(string name) : GameCharacter(name,"NPC"){
}
void NPC :: listCommodity(){ /*print all the Item in this NPC*/
    int i;
    for(i=0 ; i< ( ( this->getCommodity() ).size() ) ; i++){
        cout<<i+1<<". "<< ( ( this->getCommodity() ).at(i) ).getName() <<endl;
    }
    cout<<i+1<<". No, I don't want anything. Thanks!"<<endl;
}

/*deal with the transaction in easy implementation */
void NPC :: triggerEvent(Object* player_object){
    Player* f_player = dynamic_cast<Player*>(player_object); //建立一個新的Player指標，做downcasting
    cout<< this->getScript() <<endl;
    this->listCommodity();
    bool takeItem;
    int choice;
    cin>>choice;
    choice=choice-1; //index從0開始
    if( choice>= ( ( this->getCommodity() ).size() ) ){
            cout<<this->getName()<<": Okay, good luck."<<endl;
            takeItem=false;
    }
    else{
        f_player->addItem( ( ( this->getCommodity() ).at(choice) )  );
        f_player->increaseStates( (((this->getCommodity()).at(choice) ).getHealth()),(((this->getCommodity()).at(choice) ).getAttack()),(((this->getCommodity()).at(choice) ).getDefense()));
        ( this->getCommodity() ).erase( ( this->getCommodity() ).begin() + choice); //不能直接放choice(只是一個int)，要清除的是這個vector往後數choice個
        cout<<endl;
        takeItem=true;
    }
    if( takeItem ){ //已拿過一次東西
        this->setTag("Nothing"); //移除NPC
    }
}

void NPC :: setScript(){
    if( this->getName() =="Liwei_Zhang"){
        this->script="Liwei_Zhang: Hi, have fun and enjoy the game :) Bring a partner with you ! ";
    }
    if ( this->getName() =="Beautiful ChunPei" ){
        this->script="Beautiful ChunPei: Hello, I have some gift for you, pick one !";
    }
}
void NPC :: setCommodity(){
    if( this->getName() == "Liwei_Zhang"){
            Item i1=Item("Cute_baby",0,10,5);
            ( this->getCommodity() ).push_back(i1);
            Item i2 =Item("Cat",0,10,5);
            ( this->getCommodity() ).push_back(i2);
    }
    if ( this->getName() == "Beautiful_ChunPei" ){
            Item i1 =Item("Negligible_gift",5,10,10);
            ( this->getCommodity() ).push_back(i1);
            Item i2 =Item("Double-edged_sword",-20,30,30);
            ( this->getCommodity() ).push_back(i2);
    }
}
string NPC :: getScript(){
    return this->script;
}
vector<Item>& NPC :: getCommodity(){
    return this->commodity;
}

