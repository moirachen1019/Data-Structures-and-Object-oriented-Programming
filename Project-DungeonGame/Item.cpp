#include "Item.h"
#include <iostream>
#include <string>
#include <vector>
#include "Object.h"
#include "Player.h"
using namespace std;

Item :: Item() : Object(){
}
Item :: Item(string name, int health, int attack, int defense) : Object(name,"Item") { //Object��constructor2
    this->health=health;                                                                                                         //�b .h �ɤ��ŧi�A .cpp �ɤ��gimplementation
    this->attack=attack;                                                                                                          //�~��Object�]�w�W�r��constructor�Atag�����]�w��Item
    this->defense=defense;
}

/*pick up item&add status to the player. */
void Item :: triggerEvent(Object* player_object){
    Player* f_player = dynamic_cast<Player*>(player_object); //�إߤ@�ӷs��Player���СA��downcasting
    f_player->increaseStates( this->getHealth(), this->getAttack(), this->getDefense() ); //��item���ѼƧ�s��play status
    Item i=Item( this->getName(), this->getHealth(), this->getAttack(), this->getDefense() ); //�Ф@�ӷsitem�A���e�M�쥻���@�Ҥ@��
    f_player->addItem(i);
    this->setTag("Nothing"); //�߰_�ӫ��item�q�ж��M��
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
