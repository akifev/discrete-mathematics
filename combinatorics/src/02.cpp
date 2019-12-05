#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <set>
#include <fstream>
#include <map>
#include <list>
using namespace std;
typedef unsigned long long ull;
int main() {
	ifstream cin("gray.in");
	ofstream cout("gray.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	ull sz = pow(2, n);
	vector<stack<int>>a(sz);
	a[0].push(0);
	a[1].push(1);
	int m = 2;
	for (int i = 1; i < n; i++) {
		for (int j = m - 1; j >= 0; j--) {
			a[m] = a[j];
			a[m++].push(1);
			a[j].push(0);
		}
	}
	for (int i = 0; i < sz; i++) {
		while (!a[i].empty()) {
			cout << a[i].top();
			a[i].pop();
		}
		cout << '\n';
	}
	return 0;
}