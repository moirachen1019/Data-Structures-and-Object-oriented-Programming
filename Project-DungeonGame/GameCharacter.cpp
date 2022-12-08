#include "GameCharacter.h"
#include <iostream>
#include <string>
#include "Object.h"
using namespace std;

GameCharacter :: GameCharacter() :Object(){
}
GameCharacter :: GameCharacter(string name, string tag) : Object(name,tag){
}
GameCharacter :: GameCharacter(string name,string tag,string type,int maxHealth, int currentHealth, int attack, int defense): Object(name,tag){
    this->type=type;
    this->maxHealth=maxHealth;
    this->currentHealth=currentHealth;
    this->attack=attack;
    this->defense=defense;
}
bool GameCharacter :: checkIsDead(){
    if( (this->getCurrentHealth())<=0 ){
        return true;
    }else{
        return false;
    }
}


void GameCharacter :: setMaxHealth(int maxHealth){
    this->maxHealth=maxHealth;
}
void GameCharacter :: setCurrentHealth(int currentHealth){
    this->currentHealth=currentHealth;
}
void GameCharacter :: setAttack(int attack){
    this->attack=attack;
}
void GameCharacter :: setDefense(int defense){
    this->defense=defense;
}
void GameCharacter :: setType(string type){
    this->type=type;
}

int GameCharacter :: getMaxHealth(){
    return this->maxHealth;
}
int GameCharacter :: getCurrentHealth(){
    return this->currentHealth;
}
int GameCharacter :: getAttack(){
    return this->attack;
}
int GameCharacter :: getDefense(){
    return this->defense;
}
string GameCharacter :: getType(){
    return this->type;
}
