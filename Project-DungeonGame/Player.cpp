#include "Player.h"
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include "GameCharacter.h"
#include "Room.h"
#include "Item.h"
using namespace std;

Player :: Player() : GameCharacter(){
}
Player :: Player(string name,string type,int maxHealth, int currentHealth, int attack, int defense) : GameCharacter(name,"Player",type,maxHealth, currentHealth, attack, defense){
}
void Player :: addItem(Item new_i){
    ( this->getInventory() ).push_back(new_i); //在inventory vector內增加新item
    cout<<"You get "<<new_i.getName()<<" it has health:"<<new_i.getHealth()<<", attack:"<<new_i.getAttack()<<", defense:"<<new_i.getDefense();
    cout<<endl;
}
void Player :: increaseStates(int health, int attack, int defense){
    this->setCurrentHealth( (this->getCurrentHealth() )+health );
    if( this->getCurrentHealth() >this->getMaxHealth() ){
        this->setCurrentHealth( this->getMaxHealth() );
    }
    this->setAttack( ( this->getAttack() ) + attack );
    if( (this->getAttack())<=0 ){
        this->setAttack(0);
    }
    this->setDefense( ( this->getDefense() )+ defense );
    if( (this->getDefense())<=0 ){
        this->setDefense(0);
    }
}

/*show the status of player.*/
void Player :: triggerEvent(Object* nobody){
    cout<<"Name: "<<this->getName()<<endl;
    cout<<"Health: "<<this->getCurrentHealth()<<"/"<<this->getMaxHealth()<<endl;
    cout<<"Attack: "<<this->getAttack()<<endl;
    cout<<"Defense: "<<this->getDefense() <<endl;
    cout<<"Attribute:"<<this->getType()<<endl;
    cout<<"Inventory:";
    for(int i=0 ; i< ( ( this->getInventory() ).size() ) ; i++){
        if(i==0){
            cout<< ( ( ( this->getInventory() ).at(i) ).getName() );
        }else{
            cout<<" , "<< ( ( ( this->getInventory() ).at(i) ).getName() );
        }
    }
    cout<<"."<<endl;
}

void Player :: setInventory(vector<Item> inventory){
    this->inventory=inventory;
}
void Player :: setPreviousRoom(Room* previous){
    this->previousRoom=previous;
}
void Player :: setCurrentRoom(Room* cur){
    this->currentRoom=cur;
}

vector<Item>& Player :: getInventory(){
    return this->inventory;
}
Room* Player :: getPreviousRoom(){
    return this->previousRoom;
}
Room* Player :: getCurrentRoom(){
    return this->currentRoom;
}
