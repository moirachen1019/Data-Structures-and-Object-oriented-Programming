#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct vertex {
    long long int weight, visit, parent, index;
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
        v[i].index = i;
    }
    v[start].weight = 0; //start set 0

    long long int** matrix; //Adjacency Matrix n*n 
    matrix = new long long int* [v_num];
    for (long long int i = 0; i < v_num; i++) {
        matrix[i] = new long long int[v_num];
    }
    //matrix initial = 0
    for (long long int i = 0; i < v_num; i++) {
        for (long long int j = 0; j < v_num; j++) {
            matrix[i][j] = 0;
        }
    }
    //set adjacency matrix
    for (long long int i = 0; i < e_num; i++) {
        long long int b, e, cost;
        cin >> b >> e >> cost;
        matrix[b][e] = cost;
    }

    //for (int i = 0; i < v_num; i++) { 
    //    for (int j = 0; j < v_num; j++) {
    //        cout<<matrix[i][j]<<" ";
    //    }
    //    cout << endl;
    //}

    sort(v.begin(), v.end(), compare); //從大到小排
    long long int target = (v.back()).index;
    long long int k = (v_num - 1);
    for (int i  =0; i < v_num; i++){//當尚有無visit的vertex
        for (long long int j = 0; j < v_num; j++) {
            if (matrix[target][v[j].index] != 0) { //target和v[j].index相連 (v的順序和原本不一樣，不代表index
                                                   //但沒關係，就照著v的新順序去找到index，再從index看matrix)
                if (matrix[target][v[j].index] + (v[k]).weight < v[j].weight) { //target weight + cost < present weight
                    v[j].weight = matrix[target][v[j].index] + (v[k]).weight;
                    v[j].parent = target;
                }
            }
        }
        (v[k]).visit = 1;
        sort(v.begin(), v.end(), compare); //重新由大到小排列
        for (k = (v_num - 1); k >= 0; k--) {
            if (v[k].visit == 0) { //選最小且沒被尋訪過當target
                target = (v[k]).index;
                break;
            }
        }
    }
    for (int i = 0; i < v_num; i++) { //end是原本的index，要找到end所代表的vertex在sort過的v的哪裡
        if (end == v[i].index) {
            end = i;
            break;
        }
    }
    cout << v[end].weight;
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
0 3 6

ans: 6

test data:
6 9
0 5
0 1 1
0 2 12
1 2 9
1 3 3
2 4 5
3 2 4
3 4 13
3 5 15
4 5 4

ans:
17
*/

//int main() {
//    long long int v_num, e_num;
//    cin >> v_num >> e_num;
//    long long int start, end;
//    cin >> start >> end;
//
//    vector<vertex> v;
//    vector<vertex> sort_v;
//    for (long long int i = 0; i < v_num; i++) {
//        v.push_back(vertex());
//        sort_v.push_back(vertex());
//        v[i].weight = 1000000; //infinite(excpet vertex[start])
//        sort_v[i].weight = 1000000;
//        v[i].parent = -1; //no parent
//        v[i].index = i;
//        sort_v[i].index = i;
//    }
//    v[start].weight = 0; //start set 0
//    sort_v[start].weight = 0; //start set 0
//
//    long long int** matrix; //Adjacency Matrix n*n 
//    matrix = new long long int* [v_num];
//    for (long long int i = 0; i < v_num; i++) {
//        matrix[i] = new long long int[v_num];
//    }
//    //matrix initial = 0
//    for (long long int i = 0; i < v_num; i++) {
//        for (long long int j = 0; j < v_num; j++) {
//            matrix[i][j] = 0;
//        }
//    }
//    //set adjacency matrix
//    for (long long int i = 0; i < e_num; i++) {
//        long long int b, e, cost;
//        cin >> b >> e >> cost;
//        matrix[b][e] = cost;
//    }
//
//
//    //for (int i = 0; i < v_num; i++) { 
//    //    for (int j = 0; j < v_num; j++) {
//    //        cout<<matrix[i][j]<<" ";
//    //    }
//    //    cout << endl;
//    //}
//
//    sort(sort_v.begin(), sort_v.end(), compare); //從大到小排
//    while (sort_v.size()) { //當vertex尚未尋訪完
//        long long int target = (sort_v.back()).index; //選最小的當target
//        for (long long int j = 0; j < v_num; j++) {
//            if (matrix[target][j] != 0) { //target和j相連
//                long long int position = 0;
//                int flag = 0;
//                for (long long int i = 0; i < sort_v.size(); i++) { //這裡的j是代表一開始vertex的index，
//                                                                    //但是sort_v的順序已變，故要找j在sort_v的哪裡
//                    if (j == sort_v[i].index) {
//                        position = i;
//                        flag = 1;
//                        break;
//                    }
//                }
//                if (matrix[target][j] + (sort_v.back()).weight < v[j].weight) { //target weight + cost < present weight
//                    v[j].weight = matrix[target][j] + (sort_v.back()).weight;
//                    if (flag) {
//                        sort_v[position].weight = matrix[target][j] + (sort_v.back()).weight; //v[j]沒被visit過才要改
//                    }
//                    v[j].parent = target;
//                }
//            }
//        }
//        sort_v.pop_back(); //清掉已經被參訪過的
//        sort(sort_v.begin(), sort_v.end(), compare); //重新由大到小排列
//    }
//    cout << v[end].weight;
//    return 0;
//}