#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
class mergeSort {
public:
    vector<int> v;
    void cut(int b, int e);
    void merge(int b,int m, int e);
};

int main() {
    time_t t_b, t_e; //the variables caculate time
    int n;
    cin >> n;
    //t_b = clock(); //start count time
    mergeSort sorting;
    while (n) {
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            sorting.v.push_back(num);
        }
        sorting.cut(0, (n - 1));
        for (int i = 0; i < n; i++) {
            cout << sorting.v[i] << " ";
        }
        cout << endl;
        sorting.v.clear();
        cin >> n;
    }
    //t_e = clock(); //stop count time
    //double diff = difftime(t_e, t_b); // spending time
    //cout << endl << "Execution Time: " << diff / CLOCKS_PER_SEC << endl;
    return 0;
}

void mergeSort::cut(int b, int e){
    if (b < e) {
        int m;
        m = (b + e) / 2;
        this->cut(b, m);
        this->cut(m + 1, e);
        this->merge(b, m, e);
    }
}

void mergeSort::merge(int b, int m, int e){
    vector<int> temp1;
    vector<int> temp2;
    int i, j;
    for (i = b; i <= m; i++) {
        temp1.push_back( (this->v)[i] );
    }
    for (j = m+1; j <= e; j++) {
        temp2.push_back( (this->v)[j] );
    }
    i = j = 0;
    for (int k = b; k <= e; k++) {
        if (i < temp1.size() && j < temp2.size()) { //當temp1和2都還有東西
            if (temp1[i] <= temp2[j]) { //放入temp1 (當它較小時) 
                (this->v)[k] = temp1[i];
                i++;
            }
            else if (temp1[i] > temp2[j]) { //放入temp2 (當它較小時) 
                (this->v)[k] = temp2[j];
                j++;
            }
        }
        else {
            if ( j >= temp2.size() && i < temp1.size()) { //放temp1 (當temp2已經空了) 
                (this->v)[k] = temp1[i];
                i++;
            }
            else if ( i >= temp1.size() && j < temp2.size()) { //放temp2 (當temp1已經空了) 
                (this->v)[k] = temp2[j];
                j++;
            }
        }
    }
    temp1.clear();
    temp2.clear();
}

/*
5
7 -1 -2 4 9
*/