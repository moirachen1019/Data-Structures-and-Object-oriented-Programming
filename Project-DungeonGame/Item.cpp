#include "Item.h"
#include <iostream>
#include <string>
#include <vector>
#include "Object.h"
#include "Player.h"
using namespace std;

Item :: Item() : Object(){
}
Item :: Item(string name, int health, int attack, int defense) : Object(name,"Item") { //Object的constructor2
    this->health=health;                                                                                                         //在 .h 檔內宣告， .cpp 檔內寫implementation
    this->attack=attack;                                                                                                          //繼承Object設定名字的constructor，tag直接設定為Item
    this->defense=defense;
}

/*pick up item&add status to the player. */
void Item :: triggerEvent(Object* player_object){
    Player* f_player = dynamic_cast<Player*>(player_object); //建立一個新的Player指標，做downcasting
    f_player->increaseStates( this->getHealth(), this->getAttack(), this->getDefense() ); //把item的參數更新到play status
    Item i=Item( this->getName(), this->getHealth(), this->getAttack(), this->getDefense() ); //創一個新item，內容和原本的一模一樣
    f_player->addItem(i);
    this->setTag("Nothing"); //撿起來後把item從房間清除
}

int Item :: getHealth(){
    return this->health;
}
int Item :: getAttack(){
    return this->attack;
}
int Item :: getDefense(){
    return this->defense;
}
void Item :: setHealth(int health){
    this->health=health;
}
void Item :: setAttack(int attack){
    this->attack=attack;
}
void Item :: setDefense(int defense){
    this->defense=defense;
}
