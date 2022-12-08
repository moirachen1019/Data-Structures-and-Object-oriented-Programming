#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct edge {
	int a, b, cost;
};
struct set {
	int parent, num;
};

bool compare(edge a, edge b) { //sorting by cost
	return a.cost < b.cost;
}

int findParent(set* s,int i) { //return the toppest parent
	int ans = i;
	if (i != s[i].parent) {
		ans = findParent(s, s[i].parent);
	}
	return ans;
}

int main() {
	int v_num, e_num;
	cin >> v_num >> e_num;
	int total_cost = 0;

	//reference:https://sites.google.com/site/zsgititit/home/jin-jiec-cheng-shi-she-ji-2/zui-xiao-sheng-cheng-shu
	set* s;
	s = new set[v_num];
	for (int i = 0; i < v_num; i++) {
		s[i].parent = i;
		s[i].num = 1;
	}

	edge* e;
	e = new edge[e_num];
	for (int i = 0; i < e_num; i++) {
		cin >> e[i].a >> e[i].b >> e[i].cost;
	}

	sort(e, e + e_num, compare); //sort by e's cost use compare funciton
	for (int i = 0; i < e_num; i++) {
		if (findParent(s, e[i].a) != findParent(s, e[i].b)) { //如果兩個vertex最上面的parent不一樣
			if (s[e[i].a].num >= s[e[i].b].num) { //a's subsets >= b's
				s[findParent(s, e[i].b)].parent = s[e[i].a].parent; //把b最上面的parent的parent接到a的parent
				s[e[i].a].num++;
			}
			else {
				s[findParent(s, e[i].a)].parent = s[e[i].b].parent;
				s[e[i].b].num++;
			}
			total_cost += e[i].cost;
		}
	}
	cout << total_cost;
	return 0;
}

/*test data
5 7
0 1 10
0 2 20
1 2 30
1 3 5
2 3 15
2 4 6
3 4 8
*/