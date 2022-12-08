#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    int target=0;
    int flag=0;
    int all_zero=0;
    int size = 0;
    vector<int> v;
    vector<int> ans;
    vector<int> alone;
    int m[50][50];
    for (int i = 0; i < n; i++) { //input
        for (int j = 0; j < n; j++) {
            int k;
            cin >> k;
            m[i][j] = k;
        }
    }
    int count = 0;
    while (true) {
        flag = 0;
        for (int i = 0; i < n; i++) { 
            all_zero = 0;
            for (int j = 0; j < n; j++) {
                if (m[i][j]) { 
                    if (flag == 0) { //find the first vertice=1
                        target = i;
                        ans.push_back(i);
                        flag = 1;
                        if (i == j) {
                            m[i][j] = 0;
                        }
                    }
                    all_zero = 1; //this row at least one not zero
                    break;
                }
            }
            if (all_zero == 0 && count == 0) { //first time but some row all zero
                alone.push_back(i);
            }
        }
        if (flag==0) { //all are zero , break the while loop
            break;
        }
        do { //stack is not empty
            if (v.size() > 0) {
                target = v.back();
                ans.push_back(v.back());
                v.pop_back();
            }
            for (int j = 0; j < n; j++) {
                if (m[target][j]) {
                    v.push_back(j);
                    m[target][j] = 0;
                    m[j][target] = 0;
                }
            }
        } while (v.size() > 0);
        sort(ans.begin(), ans.end()); //sort
        size = ans.size();
        for (int i = 0; i < size-1; i++) {
            if (ans[i] != ans[i + 1]) {
                cout << ans[i] << " ";
            }
        }
        cout << ans[size - 1];
        ans.clear();
        cout << endl;
        count++;
    }
    //find the alone one
    size = alone.size();
    for (int i = 0; i < size; i++) {
        cout << alone[i] << endl;
    }
    return 0;
}