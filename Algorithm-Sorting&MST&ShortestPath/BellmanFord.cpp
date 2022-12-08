#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct vertex {
    long long int weight, parent, index;
};
struct edge {
    long long int a, b, cost;
};
bool compare(vertex a, vertex b) {
    return a.weight > b.weight;
}

int main() {
    long long int v_num, e_num;
    cin >> v_num >> e_num;
    long long int start, end;
    cin >> start >> end;

    vector<vertex> v;
    for (long long int i = 0; i < v_num; i++) {
        v.push_back(vertex());
        v[i].weight = 1000000; //infinite(excpet vertex[start])
        v[i].parent = -1; //no parent
    }
    v[start].weight = 0; //start set 0

    vector<edge> e;
    for (long long int i = 0; i < e_num; i++) {
        e.push_back(edge());
        cin >> e[i].a >> e[i].b >> e[i].cost;
    }

    for (long long int i = 0; i < (v_num - 1); i++) { //run v_num-1 times
        for (long long int j = 0; j < e_num; j++) {
            if ( v[e[j].b].weight > v[e[j].a].weight + e[j].cost ) {
                v[e[j].b].weight = v[e[j].a].weight + e[j].cost;
                v[e[j].b].parent = v[e[j].a].parent;
            }
        }
    }
    int flag = 1; 
    for (long long int j = 0; j < e_num; j++) {
        if ( v[e[j].b].weight > v[e[j].a].weight + e[j].cost ) {
            cout << "Negative loop detected!";
            flag = 0;
            break;
        }
    }
    if (flag) {
        cout <<v[end].weight;
    }
    return 0;
}

/*
test data:
5 8
4 0
1 0 3
2 3 2
4 3 2
3 1 1
0 2 6
4 1 4
3 2 1
0 3 -6

ans: Negative loop detected!



0 1 5
1 2 6
1 4 -4
2 4 -3
2 5 -2
3 2 4
4 3 1
4 5 6
5 0 3
5 1 7

test data:
5 8
4 0
1 0 3
2 3 2
4 3 2
3 1 1
0 2 6
4 1 4
3 2 1
0 3 6

ans:
6

test data:
5 5
0 4
1 2 2
0 1 -3
0 4 5
3 4 2
2 3 3

ans:
4
*/