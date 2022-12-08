#include <iostream>
#include <string>

using namespace std;

class Student{ //�W��Student��class
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
    Student student(student_name); //define �@��type��Student���ܼ�student�A��l�ȳ]��student_name
    for(int i = 0; i < 3; i++){
        cin >> student.exam_scores[i]; //���student�̭�������
    }
    student.get_minimum_final_score(); //�ϥ�student�����禡
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
Student::Student(string student_name):name(student_name){ //��qmain�o�쪺student_name��name
}
