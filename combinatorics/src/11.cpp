#define _CRT_SECURE_NO_WARNINGS
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
#include <cstdio>
using namespace std;
typedef unsigned long long ull;
int n;
void f(vector<int>& a, int i) {
	for (int j = 0; j < a.size(); j++)
		cout << a[j] << ' ';
	for (; i <= n; i++) {
		cout << '\n';
		a.push_back(i);
		f(a, i + 1);
		a.pop_back();
	}
}
int main() {
	freopen("subsets.in", "r", stdin);
	freopen("subsets.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	vector<int>a;
	f(a, 1);
}