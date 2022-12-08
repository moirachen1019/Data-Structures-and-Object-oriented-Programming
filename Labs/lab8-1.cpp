#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
     /*Enter your code here. Read input from STDIN. Print output to STDOUT*/
    int n;
    cin>>n;
    string ans[n];
    for(int i=0 ; i<n ; i++ ){
        vector<char> str;
        ans[i]="unknown";
        char p='n';
        while(p!='\n' && p!=EOF){ //檔案結尾（英語：End of File），是作業系統無法從資料來源讀取更多資料的情形
            char test;
            cin>>test;
            if( test=='{' || test=='[' || test=='(' ){
                str.push_back(test);
            }
            else if( test=='}'){
                if(str.back()=='{'){
                        str.pop_back();
                }else{
                    ans[i]="no";
                }
            }
            else if( test==']'){
                if(str.back()=='['){
                        str.pop_back();
                }else{
                    ans[i]="no";
                }
            }
            else if( test==')'){
                if(str.back()=='('){
                        str.pop_back();
                }else{
                    ans[i]="no";
                }
            }
            p=cin.peek();
        }
        if(str.size()!=0){
            ans[i]="no";
        }
        else if(ans[i]=="unknown"){
            ans[i]="yes";
        }
    }
    for(int i=0 ; i<n ; i++){
        cout<<ans[i]<<endl;
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
