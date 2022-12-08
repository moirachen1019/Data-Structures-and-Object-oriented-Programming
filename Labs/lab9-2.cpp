#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n = 0;
	int ans[1000] = { 0 };
	int count = 0;
	cin >> n;
	while (n != 0) {
		vector<int> num;
		for (int i = 0; i < n; i++) {
			int k;
			cin >> k;
			num.push_back(k);
		}
		sort(num.begin(), num.end(), std::greater<int>());
		while (num.size() != 1) {
			int temp = 0;
			temp += num.back();
			num.pop_back();
			temp += num.back();
			//cout << num.back();
			num.pop_back();
			ans[count] += temp;
			num.push_back(temp);
			sort(num.begin(), num.end(), std::greater<int>());
		}
		count++;
		cin >> n;
	}



	for (int i = 0; i < count; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}