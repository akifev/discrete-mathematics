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
set<string>ans;
void next(int pref, vector<int>& a, int n) {
	if (pref < n) {
		for (int i = pref; i < n; i++) {
			swap(a[i], a[pref]);
			next(pref + 1, a, n);
			swap(a[i], a[pref]);
		}
	}
	else {
		string tmp;
		for (int i = 0; i < n; i++) {
			tmp += (char)('0' + a[i]);
			tmp += ' ';
		}
		ans.insert(tmp);
	}
}
int main() {
	ifstream cin("permutations.in");
	ofstream cout("permutations.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++)
		a[i] = i + 1;
	next(0, a, n);
	for (auto it : ans) {
		cout << it << '\n';
	}
}