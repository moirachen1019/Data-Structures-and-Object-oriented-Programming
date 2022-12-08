#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct vertex {
	int weight, visit, parent, index;
};


int main() {
	int v_num, e_num;
	cin >> v_num >> e_num;
	int total_cost = 0;

	vertex* v;
	v = new vertex[v_num];
	for (int i = 0; i < v_num; i++) {
		v[i].weight = 10001; //infinite(excpet vertex0)
		v[i].visit = 0; //unvisited
		v[i].parent = -1; //no parent
		v[i].index = i;
	}
	v[0].weight = 0; //first set 0

	int** matrix; //Adjacency Matrix n*n 
	matrix = new int* [v_num];
	for (int i = 0; i < v_num; i++) {
		matrix[i] = new int[v_num];
	}
	for (int i=0; i < v_num; i++) { //matrix initial = 0
		for (int j=0; j < v_num; j++) {
			matrix[i][j] = 0;
		}
	}

	for (int i = 0; i < e_num; i++) { //set adjacency matrix
		int b, e, cost;
		cin >> b >> e >> cost;
		matrix[b][e] = matrix[e][b] = cost;
	}

	//for (int i = 0; i < n; i++) { 
	//	for (int j = 0; j < n; j++) {
	//		cout<<matrix[i][j]<<" ";
	//	}
	//	cout << endl;
	//}

	int flag = 1;
	while (flag) {
		int min = 10001;
		int target = -1;
		for (int i = 0; i < v_num; i++) {
			if ( v[i].weight < min && v[i].visit==0 ){ //找到最小的weight和它的index, 同時確認v[i]沒被visit過
				min = v[i].weight;
				target = i;
			}
		}
		for (int j = 0; j < v_num; j++) {
			if (matrix[target][j] != 0) { //adjency
				if (matrix[target][j] < v[j].weight && v[j].visit==0) { //edge < present weight, 同時確認v[i]沒被visit過
					v[j].weight = matrix[target][j];
					v[j].parent = target;
				}
				v[target].visit = 1;
			}
		}
		
		flag = 0; //先預設所有vertex沒被visit過
		for (int i = 0; i < v_num; i++) {//測試是否所有vertex都被visit過
			if (v[i].visit == 0) {
				flag = 1; //只要有一個沒被visit過，結束此迴圈繼續while迴圈
				break;
			}
		}
	}
	
	for (int i = 0; i < v_num; i++) {
		total_cost += v[i].weight;
	}

	cout << total_cost;
	return 0;
}


/* 
test data:
5 7
0 1 10
0 2 20
1 2 30
1 3 5
2 3 15
2 4 6
3 4 8

ans:29
*/