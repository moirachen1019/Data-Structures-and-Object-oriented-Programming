#include "Object.h" //include .h��
#include <iostream>
#include <string>
#include <vector>
using namespace std;
Object :: Object(){ //class Object��constructor1
}

Object :: Object(string name, string tag){ //class Object ��constructor2
    this->name=name;
    this->tag=tag;
}

void Object :: setName(string name){ //�ݭnset�Mget��ơA�]��private��Ƥ���q�~�����o
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
