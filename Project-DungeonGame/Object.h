#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//�Ҧ����~(��Ldungeon��class���~�ӥL
class Object //�b.h�ɸ̭��u�|define���class�Afunction�Mconsturctor�d��cpp��
{                      //�n�جƻ�F���UML
private:
    string name;
    string tag;
public:
    Object();
    Object(string,string);
    /* pure virtual function */
    virtual void triggerEvent(Object*) = 0;

    void setName(string);
    void setTag(string);
    string getName();
    string getTag();
};

#endif // OBJECT_H_INCLUDED
