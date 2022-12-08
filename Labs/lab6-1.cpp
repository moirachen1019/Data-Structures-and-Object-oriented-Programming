#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void trim(string &str){
    str.erase(0,str.find_first_not_of(" "));
    str.erase(str.find_last_not_of(" ") + 1);
}


void reverse(string &str){
    reverse(str.begin(), str.end());
}

int main()
{
    string input_line;
  	getline(cin ,input_line);
  	trim(input_line);
  	reverse(input_line);
    cout << input_line;
    return 0;
}
