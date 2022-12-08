#include "Record.h"
#include <iostream>
#include <vector>
#include "Item.h"
#include "Monster.h"
#include "NPC.h"
#include "Player.h"
using namespace std;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <sstream>
using std::stringstream;

Record :: Record(){
}

void Record :: saveToFile( Player* player, Room room[] ){
    outStream.open("GameRecord.text");
    savePlayer(player);
    saveRooms(&room[0]);
}
void Record :: loadFromFile( Player* player, Room room[] ){
    inStream.open("GameRecord.text");
    string player_inf;
    string inventory_inf;
    string room_inf;

    getline(inStream , player_inf);
    int i_number;
    i_number=loadPlayer(player, player_inf , &room[0]);

    for(int i=0 ; i<i_number ; i++){
        getline(inStream , inventory_inf);
        loadInventory(player, inventory_inf);
    }

    for(int i=0; i<8 ; i++){
        getline(inStream, room_inf);
        loadRooms(&room[0], room_inf, i);
    }

}

void Record :: savePlayer(Player* player){
    outStream<< player->getName() <<" "<<player->getType()<<" "<< player->getMaxHealth()<<" "<< player->getCurrentHealth()
    <<" "<<player->getAttack() <<" "<< player->getDefense()
    <<" "<< player->getCurrentRoom()->getIndex() <<" "<< player->getPreviousRoom()->getIndex()
    <<" "<< (player->getInventory() ).size()<<endl;
    for(int i=0 ; i<(player->getInventory() ).size() ;i++){
        outStream<< ( ( player->getInventory() ).at(i) ).getName()
        <<" "<<( ( player->getInventory() ).at(i) ).getHealth()
        <<" "<<( ( player->getInventory() ).at(i) ).getAttack()
        <<" "<<( ( player->getInventory() ).at(i) ).getDefense()<<endl;
    }
}
void Record :: saveRooms(Room room[]){
    for(int i=0; i<8 ; i++){
        outStream<< ( room[i].getUpRoom() )->getIndex()
        <<" "<<( room[i].getDownRoom() )->getIndex()
        <<" "<<( room[i].getLeftRoom() )->getIndex()
        <<" "<<( room[i].getRightRoom() )->getIndex();
        if( room[i].getIsExit() ){
            outStream<<" 1";
        }else{
            outStream<<" 0";
        }
        if( (room[i].getObjects())->getTag() == "NPC"){
            outStream<<" 1";
            NPC* n = dynamic_cast<NPC*>( room[i].getObjects() ); //把getObject的Object指標改成NPC
            outStream<<" "<< n->getName();
        }else{
            outStream<<" 0";
        }
        if( (room[i].getObjects())->getTag() == "Monster"){
            outStream<<" 1";
            Monster* m = dynamic_cast<Monster*>( room[i].getObjects() );
            outStream<<" "<< m->getName() <<" "<<m->getType()<<" "<< m->getMaxHealth() <<" "<<m->getCurrentHealth()
            <<" "<< m->getAttack() <<" "<< m->getDefense();
        }else{
            outStream<<" 0";
        }
        if( (room[i].getObjects())->getTag() == "Item"){
            outStream<<" 1";
            Item* ii = dynamic_cast<Item*>( room[i].getObjects() );
            outStream<<" "<<ii->getName()<<" "<< ii->getHealth()
            <<" "<< ii->getAttack() <<" "<< ii->getDefense();
        }else{
            outStream<<" 0";
        }
        outStream<<endl;
    }
}

int Record :: loadPlayer(Player* player, string player_inf ,Room room[]){
    string p_name,p_type;
    int p_maxh, p_currenth, p_attack, p_defense, r_current, r_previous, i_number;
    ss<<player_inf;
    ss>>p_name>>p_type>>p_maxh>>p_currenth>>p_attack>>p_defense>>r_current>>r_previous>>i_number;
    player->setName(p_name);
    player->setType(p_type);
    player->setMaxHealth(p_maxh);
    player->setCurrentHealth(p_currenth);
    player->setAttack(p_attack);
    player->setDefense(p_defense);
    player->setCurrentRoom( &room[r_current] );
    player->setPreviousRoom( &room[r_previous] );
    return i_number;
}
void Record :: loadInventory(Player* player ,string inventory_inf){
    ss.clear( ); //用過之後(有先存player)一定要清空才能再用
    string i_name;
    int i_health, i_attack, i_defense;
    ss<<inventory_inf;
    ss>>i_name>>i_health>>i_attack>>i_defense;
    Item new_i(i_name, i_health, i_attack, i_defense);
    ( player->getInventory() ).push_back(new_i);
}
void Record :: loadRooms(Room room[] ,string room_inf, int i){
    ss.clear( ); //用過之後(有先存player)一定要清空才能再用
    int u, d, l, r, exit, npc, monster, item;
    Room nothing;
    nothing.setIndex(-1);
    ss<<room_inf;
    ss>>u>>d>>l>>r>>exit;
    if(u!=-1){
        room[i].setUpRoom(&room[u]);
    }else{
        room[i].setUpRoom(&nothing);
    }
    if(d!=-1){
        room[i].setDownRoom(&room[d]);
    }else{
        room[i].setDownRoom(&nothing);
    }
    if(l!=-1){
        room[i].setLeftRoom(&room[l]);
    }else{
        room[i].setLeftRoom(&nothing);
    }
    if(r!=-1){
        room[i].setRightRoom(&room[r]);
    }else{
        room[i].setRightRoom(&nothing);
    }
    room[i].setIndex(i);
    if(exit){
        room[i].setIsExit(true);
    }else{
        room[i].setIsExit(false);
    }
    ss>>npc;
    if(npc){
        string n_n;
        ss>>n_n;
        NPC* n=new NPC(n_n);
        n->setCommodity();
        n->setScript();
        Object* object=n;
        room[i].setObjects(object);
        n = dynamic_cast<NPC*>(object);
    }
    ss>>monster;
    if(monster){
        string m_n,m_t;
        int m_mh, m_ch, m_a, m_d;
        ss>>m_n>>m_t>>m_mh>>m_ch>>m_a>>m_d;
        Monster* m=new Monster(m_n, m_t ,m_mh , m_ch , m_a , m_d);
        Object* object=m;
        room[i].setObjects(object);
        m = dynamic_cast<Monster*>(object);
    }
    ss>>item;
    if(item){
        string i_n;
        int i_h, i_a, i_d;
        ss>>i_n>>i_h>>i_a>>i_d;
        Item* ii=new Item(i_n, i_h , i_a , i_d);
        Object* object=ii;
        room[i].setObjects(object);
        ii = dynamic_cast<Item*>(object);
    }


    if( ( (!npc)&&(!monster) )&&(!item) ){ //沒有npc, monster, item
        NPC* n=new NPC;
        Object* object=n;
        room[i].setObjects(object);
        n = dynamic_cast<NPC*>(object);
        ( room[i].getObjects() )->setTag("Nothing"); //因為object為abstract class，不能使用setTag()
    }                                                                            //所以要隨便創一個非Object的物件
}








