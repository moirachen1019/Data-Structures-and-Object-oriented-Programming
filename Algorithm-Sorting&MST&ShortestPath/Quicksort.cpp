#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;
class quickSort {
public:
    vector<long long int> v;
    void sort(long long int b, long long int e);
    long long int partition(long long int b, long long int e);
};


int main() {
    time_t t_b, t_e; //the variniables caculate time
    long long int n;
    cin >> n;
    //t_b = clock(); //start count time
    quickSort sorting;
    while (n) {
        for (long long int i = 0; i < n; i++) {
            long long int num;
            cin >> num;
            sorting.v.push_back(num);
        }
        sorting.sort(0, (n - 1));
        for (long long int i = 0; i < n; i++) {
            cout << sorting.v[i]<<" ";
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

void quickSort::sort(long long int b, long long int e){
    if (b < e) { //頭小於尾
        long long int r = 0 ;
        r = this->partition(b, e); //pivot在經過partition後會跑到正確大小的位置
        this->sort(b, (r - 1));
        this->sort((r + 1), e);
    }
}

long long int quickSort::partition(long long int b, long long int e) {
    long long int pivot = (this->v)[e];
    long long int i = b - 1;
    for (long long int j = b; j <= e; j++) {
        if ((this->v)[j] <= pivot) {
            i++; //代表下一個小於pivot的數字的位置
            swap((this->v)[i], (this->v)[j]);
        }

    }
    return i;
}

