#include "Monster.h"
#include "GameCharacter.h"
#include <iostream>
#include <string>
#include "Object.h"
using namespace std;

Monster :: Monster() : GameCharacter(){
}
Monster :: Monster(string name , string type, int maxHealth,int currentHealth,int attack ,int defense) : GameCharacter(name,"Monster",type,maxHealth, currentHealth, attack, defense){
}

void Monster :: triggerEvent(Object* player_object){
    Player* f_player = dynamic_cast<Player*>(player_object); //�إߤ@�ӷs��Player���СA��downcasting
        int p_real_attack=( f_player->getAttack() ) - ( this->getDefense() ); //�Ҽ{���m
        int m_real_attack=( this->getAttack() ) - ( f_player->getDefense() );
        cout<<"The monster's attribute: "<<this->getType()<<endl;
        if( this->getType()== "fire" ){
        if(f_player->getType() =="water"){ //���a�g�Ǫ�
                p_real_attack+=5;
                cout<<"Your attribute prevail the monster's. You get bonus attack!"<<endl;
            }else if(f_player->getType() =="wind"){ //�Ǫ��g���a
                m_real_attack+=5;
                cout<<"The monster's attribute prevail yours. The monster get bonus attack!"<<endl;
            }
        }
        if( this->getType()== "water" ){
            if(f_player->getType() =="ground"){ //���a�g�Ǫ�
                p_real_attack+=5;
                cout<<"Your attribute prevail the monster's. You get bonus attack!"<<endl;
            }else if(f_player->getType() =="fire"){ //�Ǫ��g���a
                m_real_attack+=5;
                cout<<"The monster's attribute prevail yours. The monster get bonus attack!"<<endl;
            }
        }
        if( this->getType()== "ground" ){
            if(f_player->getType() =="wind"){ //���a�g�Ǫ�
                p_real_attack+=5;
                cout<<"Your attribute prevail the monster's. You get bonus attack!"<<endl;
            }else if(f_player->getType() =="water"){ //�Ǫ��g���a
                m_real_attack+=5;
                cout<<"The monster's attribute prevail yours. The monster get bonus attack!"<<endl;
            }
        }
        if( this->getType()== "wind" ){
            if(f_player->getType() =="fire"){ //���a�g�Ǫ�
                p_real_attack+=5;
                cout<<"Your attribute prevail the monster's. You get bonus attack!"<<endl;
            }else if(f_player->getType() =="ground"){ //�Ǫ��g���a
                m_real_attack+=5;
                cout<<"The monster's attribute prevail yours. The monster get bonus attack!"<<endl;


            }
        }
        if(p_real_attack<0){ p_real_attack=0; } //���m�O������O�j�A���y������
        if(m_real_attack<0){ m_real_attack=0; }

    while( !( f_player->checkIsDead() ) ){ //���a����
        cout<<"Choose action:"<<endl<<"1. Attack "<<this->getName()<<endl<<"2. Retreat"<<endl;
        int choice;
        cin>>choice;
        if(choice==1){
            cout<<"Your attack dose "<<p_real_attack<<" damage."<<endl;
            this->setCurrentHealth( ( this->getCurrentHealth() ) - p_real_attack  );

            if( this->checkIsDead() ){ //�Ǫ����`
                cout<<"You beat "<<this->getName()<<endl;
                this->setTag("Nothing"); //��Ĺ�F�A��monster�qroom�M��
                break; //�����j��
            }

            cout<<this->getName()<<" 's attack does "<<m_real_attack<<" damage."<<endl;
            f_player->setCurrentHealth( ( f_player->getCurrentHealth() ) - m_real_attack  );

            if( f_player->checkIsDead() ){ //���a���`
                cout<<"You dead.QQ"<<endl;
                break;
            }
            cout<<"You have "<<f_player->getCurrentHealth()<<" health, and "<<this->getName()<<" has "<<this->getCurrentHealth()<<endl;
            }
        else if(choice==2){ //��ܺM�h
                break; //�^��choose action
            }
    }
}
