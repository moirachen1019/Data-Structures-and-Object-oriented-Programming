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
    Player* f_player = dynamic_cast<Player*>(player_object); //建立一個新的Player指標，做downcasting
        int p_real_attack=( f_player->getAttack() ) - ( this->getDefense() ); //考慮防禦
        int m_real_attack=( this->getAttack() ) - ( f_player->getDefense() );
        cout<<"The monster's attribute: "<<this->getType()<<endl;
        if( this->getType()== "fire" ){
        if(f_player->getType() =="water"){ //玩家剋怪物
                p_real_attack+=5;
                cout<<"Your attribute prevail the monster's. You get bonus attack!"<<endl;
            }else if(f_player->getType() =="wind"){ //怪物剋玩家
                m_real_attack+=5;
                cout<<"The monster's attribute prevail yours. The monster get bonus attack!"<<endl;
            }
        }
        if( this->getType()== "water" ){
            if(f_player->getType() =="ground"){ //玩家剋怪物
                p_real_attack+=5;
                cout<<"Your attribute prevail the monster's. You get bonus attack!"<<endl;
            }else if(f_player->getType() =="fire"){ //怪物剋玩家
                m_real_attack+=5;
                cout<<"The monster's attribute prevail yours. The monster get bonus attack!"<<endl;
            }
        }
        if( this->getType()== "ground" ){
            if(f_player->getType() =="wind"){ //玩家剋怪物
                p_real_attack+=5;
                cout<<"Your attribute prevail the monster's. You get bonus attack!"<<endl;
            }else if(f_player->getType() =="water"){ //怪物剋玩家
                m_real_attack+=5;
                cout<<"The monster's attribute prevail yours. The monster get bonus attack!"<<endl;
            }
        }
        if( this->getType()== "wind" ){
            if(f_player->getType() =="fire"){ //玩家剋怪物
                p_real_attack+=5;
                cout<<"Your attribute prevail the monster's. You get bonus attack!"<<endl;
            }else if(f_player->getType() =="ground"){ //怪物剋玩家
                m_real_attack+=5;
                cout<<"The monster's attribute prevail yours. The monster get bonus attack!"<<endl;


            }
        }
        if(p_real_attack<0){ p_real_attack=0; } //防禦力比攻擊力大，不造成攻擊
        if(m_real_attack<0){ m_real_attack=0; }

    while( !( f_player->checkIsDead() ) ){ //當玩家活著
        cout<<"Choose action:"<<endl<<"1. Attack "<<this->getName()<<endl<<"2. Retreat"<<endl;
        int choice;
        cin>>choice;
        if(choice==1){
            cout<<"Your attack dose "<<p_real_attack<<" damage."<<endl;
            this->setCurrentHealth( ( this->getCurrentHealth() ) - p_real_attack  );

            if( this->checkIsDead() ){ //怪物死亡
                cout<<"You beat "<<this->getName()<<endl;
                this->setTag("Nothing"); //打贏了，把monster從room清除
                break; //結束迴圈
            }

            cout<<this->getName()<<" 's attack does "<<m_real_attack<<" damage."<<endl;
            f_player->setCurrentHealth( ( f_player->getCurrentHealth() ) - m_real_attack  );

            if( f_player->checkIsDead() ){ //玩家死亡
                cout<<"You dead.QQ"<<endl;
                break;
            }
            cout<<"You have "<<f_player->getCurrentHealth()<<" health, and "<<this->getName()<<" has "<<this->getCurrentHealth()<<endl;
            }
        else if(choice==2){ //選擇撤退
                break; //回到choose action
            }
    }
}
