#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//所有物品(其他dungeon的class都繼承他
class Object //在.h檔裡面只會define整個class，function和consturctor留到cpp檔
{                      //要建甚麼東西看UML
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
