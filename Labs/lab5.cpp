#include <vector>
#include <iostream>
using namespace std;

class Object{
public:
    virtual void response() = 0; //pure virtual function
    virtual ~Object() = default; //destructor
};

class IceMonster : public Object{
	//add constructor or functions if you need
	void response() override{
        cout<<" fire attack"<<endl;
	}
};

class FireMonster : public Object{
	//add constructor or functions if you need
	void response() override{
        cout<<" ice attack"<<endl;
	}
};

class Treasure : public Object{
	//add constructor or functions if you need
	void response() override{
        cout<<" ya"<<endl;
	}
};

class Empty : public Object{
    void response() override{
        cout<<endl;
	}
};

class Room{
public:
    Room *up_room;
    Room *down_room;
    Room *left_room;
    Room *right_room;
    int index;
    Object *o;
    //add constructor or functions if you need
    Room(){
    }
    //coding
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int roomnum,stepnum,i;
    cin>>roomnum>>stepnum;
    char type,step;
    int u,d,l,r;
    Room cube[10]; //�����ŧi���A��Room���}�C
    for(i=0;i<10;i++){
        cube[i].index=i;
    }
    Room *first;
    first=&cube[0];
    Room *cur;
    cur=first;
    for(i=0;i<roomnum;i++ ){
        cin>>type>>u>>d>>l>>r;
        if(u== (-1) ){
            cur->up_room=new Room;
            cur->up_room->index=u;
        }else{
            cur->up_room=&cube[u]; //cur��up_room��cude[u]
            cur->up_room->down_room=cur; //�إ�cur�Mcude[u]��link
        }
        if(d== (-1) ){
            cur->down_room=new Room;
            cur->down_room->index=d;
        }else{
            cur->down_room=&cube[d];
            cur->down_room->up_room=cur;
        }
        if(l== (-1) ){
            cur->left_room=new Room;
            cur->left_room->index=l;
        }else{
            cur->left_room=&cube[l];
            cur->left_room->right_room=cur;
        }
        if(r== (-1) ){
            cur->right_room=new Room;
            cur->right_room->index=r;
        }else{
            cur->right_room=&cube[r];
            cur->right_room->left_room=cur;
        }

        if(type=='e'){
            cur->o=new Empty;
        }else if(type=='i'){
            cur->o=new IceMonster;
        }else if(type=='f'){
            cur->o=new FireMonster;
        }else if(type=='t'){
            cur->o=new Treasure;
        }
        cur=&cube[i+1];
    }
    cur=first;
    for(i=0;i<stepnum;i++){
        cin>>step;
        if(cur==first){
            cout<<cur->index<<endl;
        }
        if(step=='u'){
                if( (cur->up_room->index)==(-1) ){
                    cout<<"-1"<<endl;
                    continue;
                }
                cur=cur->up_room;
                cout<<cur->index;
                cur->o->response();
                cur->o=new Empty;
        }else if(step=='d'){
                if( (cur->down_room->index)==(-1) ){
                    cout<<"-1"<<endl;
                    continue;
                }
                cur=cur->down_room;
                cout<<cur->index;
                cur->o->response();
                cur->o=new Empty;
        }else if(step=='l'){
                if( (cur->left_room->index) ==(-1) ){
                    cout<<"-1"<<endl;
                    continue;
                }
                cur=cur->left_room;
                cout<<cur->index;
                cur->o->response();
                cur->o=new Empty;
        }else if(step=='r'){
                if( (cur->right_room->index)==(-1) ){
                    cout<<"-1"<<endl;
                    continue;
                }
                cur=cur->right_room;
                cout<<cur->index;
                cur->o->response();
                cur->o=new Empty;
        }
    }
    //coding
    return 0;
}
