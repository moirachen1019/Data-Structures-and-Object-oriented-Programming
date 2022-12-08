#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> hashing_1;
    vector<int> hashing_2;
    for (int i = 0; i < 19; i++) {
        hashing_1.push_back(0);
        hashing_2.push_back(0);
    }
    int mod = 0;
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        mod = k % 19;
        if (hashing_1[mod] == 0) { //Linear Probing
            hashing_1[mod] = k;
        }
        else {
            p1 = mod;
            while (true) { //not find a place yet
                p1++;
                p1 = p1 % 19; //do mod to avoid beyond 19
                if (hashing_1[p1] == 0) { //blank space
                    hashing_1[p1] = k;
                    break;
                }
            }
        }
        int prob = 0;
        if (hashing_2[mod] == 0) { //Quadratic Probing
            hashing_2[mod] = k;
        }
        else {
            while (true) { //not find a place yet
                prob++;
                p2 = mod + (prob * prob);
                p2 = p2 % 19; //do mod to avoid beyond 19
                if (hashing_2[p2] == 0) { //blank space
                    hashing_2[p2] = k;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < 19; i++) {
        cout << hashing_1[i]<<" ";
    }
    cout << endl;
    for (int i = 0; i < 19; i++) {
        cout << hashing_2[i]<<" ";
    }
    return 0;
}