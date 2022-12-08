#include <iostream>
#include <queue>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<int> str;
    int n;
    cin>>n;
    for(int i=0 ; i<n ; i++){
        int num;
        cin>>num;
        str.push_back(num);
        while(  ( (str.back())-(str.front()) ) >5000 ){
            str.erase( str.begin() );
        }
        cout<<str.size()<<" ";
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
