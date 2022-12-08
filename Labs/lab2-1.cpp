#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Student {
public:
	Student( ) { }
	string generate_address(){
        string result;
        result="1001 University Road, Hsinchu, Taiwan 300, ROC, dorm "+dormitory+", ("+ID+") "+first_name+" "+last_name;
        return result;
    }
    void get_first_name(string a);
    void get_last_name(string b);
    void get_dormitory(string c);
    void get_ID(string d);
  private:
	string first_name;
    string last_name;
	string dormitory;
	string ID;
};


int main() {
  	Student mStudent;
  	string a;
  	string b;
  	string c;
  	string d;
    cin>>a;
    mStudent.get_first_name(a); //學生資訊都放在class的private內，必須得用class內的function才能讀取
    cin>>b;
    mStudent.get_last_name(b);
    cin>>c;
    mStudent.get_dormitory(c);
    cin>>d;
    mStudent.get_ID(d);
  	cout << mStudent.generate_address() << endl;
    return 0;
}

    void Student::get_first_name(string a){
        first_name=a;
    }
    void Student::get_last_name(string b){
        last_name=b;
    }
    void Student::get_dormitory(string c){
        dormitory=c;
    }
    void Student::get_ID(string d){
        ID=d;
    }
