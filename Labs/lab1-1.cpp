#include <iostream>

using namespace std;

int add(int num1,int num2){
    return num1+num2;
}

void sub(int* num1,int* num2,int* value){
     *value=*num1-*num2;
}

void mul(int num1,int num2,int &value){ //�۷�O�o��mul�̭���value�Mmain�̭���value�@�ΦP�@�Ӧa�}
    value=num1*num2;
}

void div(int* num1,int num2,int &value){
	value=*num1/num2;
}

int main() {
  int num1;
  int num2;

  cin >> num1 >> num2;

  int value = 0;
  value = add(num1, num2);
  cout << value << " ";
  sub(&num1, &num2, &value);
  cout << value << " ";
  mul(num1, num2, value);
  cout << value << " ";
  div(&num1, num2, value);
  cout << value << endl;
  return 0;
}
