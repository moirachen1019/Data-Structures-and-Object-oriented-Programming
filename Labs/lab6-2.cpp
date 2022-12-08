#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  	vector<int> v;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int number;
    cin>>number;
    char choice;
    int r=0;
    int ans[100];
    int siz;
    for(int i=0 ; i<number ; i++ ){
        cin>>choice;
        if(choice=='a'){
            int x;
            cin>>x;
            v.push_back(x);
        }
        else if(choice=='e'){
            int y;
            cin>>y;
            v.erase(find(v.begin(),v.end(),y));
        }
        else if(choice=='r'){
            reverse(v.begin() , v.end());
        }
        else if(choice=='d'){
            v.pop_back();
        }
        else if(choice=='s'){
            ans[r]=v.size();
            r++;
        }
        else if(choice=='p'){
            for(int k=0 ; k<v.size() ;k++){
                ans[r]=v[k];
                r++;

            }
        }
    }
    cout<<ans[0];
    for(int q=1 ; q<r ; q++){
        cout<<" "<<ans[q];
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}


