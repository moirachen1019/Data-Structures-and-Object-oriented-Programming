#include <iostream>
#include <string>

using namespace std;

class Student{ //名為Student的class
public:
    string name;
    int exam_scores[4];
    Student (string student_name); //constructor
    void get_minimum_final_score();
    void print_name_and_score();
};

int main() {

    string student_name;
    cin >> student_name;
    Student student(student_name); //define 一個type為Student的變數student，初始值設為student_name
    for(int i = 0; i < 3; i++){
        cin >> student.exam_scores[i]; //更改student裡面的分數
    }
    student.get_minimum_final_score(); //使用student內的函式
    student.print_name_and_score();
    return 0;
}
void Student::get_minimum_final_score(){
    int sum=0;
    for(int i=0; i<3; i++){
        sum+=exam_scores[i];
    }
    exam_scores[3]=4*60-sum;
    if(exam_scores[3]<0){
        exam_scores[3]=0;
    }
}
void Student::print_name_and_score(){
    cout<<name<<" "<<exam_scores[3];
}
Student::Student(string student_name):name(student_name){ //把從main得到的student_name給name
}
