#include "Object.h" //include .h檔
#include <iostream>
#include <string>
#include <vector>
using namespace std;
Object :: Object(){ //class Object的constructor1
}

Object :: Object(string name, string tag){ //class Object 的constructor2
    this->name=name;
    this->tag=tag;
}

void Object :: setName(string name){ //需要set和get函數，因為private資料不能從外面取得
    this->name=name;
}

void Object :: setTag(string tag){
    this->tag=tag;
}

string Object :: getName(){
    return this->name;
}

string Object :: getTag(){
    return this->tag;
}
