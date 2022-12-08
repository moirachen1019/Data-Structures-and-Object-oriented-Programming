#include <iostream>
#include <string>
using namespace std;

class Pet {
public:
string name;
int age;

Pet(string name, int age){
//TODO
this->name = name;
this->age = age;
}

string get_status() {
return "(" + name + ", " + to_string(age) + ")";
}

string get_info(){
return "Unknown species" + get_status();
}

virtual ~Pet() = default;
};

class Cat : public Pet {
public:
Cat(string name, int age) : Pet(name, age){}
string get_info(){
return "Cat" + get_status();
};
};

class Dog : public Pet {
public:
Dog(string name, int age) : Pet(name, age){}
string get_info(){
return "Dog" + get_status();
};
};

void printInfo(Pet *pet) {
//TODO
//Do casting and cout here
Cat *ptr1 = dynamic_cast<Cat*>(pet);
if(ptr1) {
cout << ptr1->get_info() << endl;
}
Dog *ptr2 = dynamic_cast<Dog*>(pet);
if(ptr2) {
cout << ptr2->get_info() << endl;
}


}

int main() {

string catName, dogName;
int catAge, dogAge;
cin >> catName >> catAge >> dogName >> dogAge;

Cat cat(catName, catAge);
Dog dog(dogName, dogAge);

printInfo(&cat);
printInfo(&dog);

return 0;
}
