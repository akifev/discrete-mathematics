#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <ctime>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <fstream>
using namespace std;
vector<bool>used;
vector<bool>d1;
vector<bool>d2;
bool obhod(vector<unordered_map<char, int>> &dest1, vector<unordered_map<char, int>> &dest2, vector<bool> &is_term1, vector<bool> &is_term2, int cur1, int cur2) {
	if (is_term1[cur1] != is_term2[cur2]) {
		return false;
	}
	used[cur1] = true;
	bool ans = true;
	for (char c = 'a'; c <= 'z'; c++) {
		int next1 = -1, next2 = -1;
		if (dest1[cur1].count(c) > 0)
			next1 = dest1[cur1].at(c);
		if (dest2[cur2].count(c) > 0)
			next2 = dest2[cur2].at(c);
		if (next1 == -1 && next2 == -1)
			continue;
		if ((next1 == -1 && next2 != -1) || (next1 != -1 && next2 == -1) || (d1[next1] && !d2[next2]) || (!d1[next1] && d2[next2]))
			return false;
		if (!used[next1])
			ans &= obhod(dest1, dest2, is_term1, is_term2, next1, next2);
	}
	return ans;
}
int main() {
	ifstream cin("isomorphism.in");
	ofstream cout("isomorphism.out");
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<bool>is_term1(n, false);
	for (int i = 0; i < k; i++) {
		int tmp;
		cin >> tmp;
		tmp--;
		is_term1[tmp] = true;
	}
	vector<unordered_map<char, int>> dest1(n);
	d1.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		char c;
		cin >> a >> b >> c;
		a--;
		b--;
		dest1[a].insert({ c, b });
	}
	for (int i = 0; i < n; i++) {
		bool check = true;
		for (char c = 'a'; c <= 'z'; c++) {
			if (dest1[i].count(c) != 0)
				if (dest1[i].at(c) != i) {
					check = false;
					break;
				}
		}
		d1[i] = check;
	}
	int r, w, e;
	cin >> r >> w >> e;
	used.resize(n, false);
	vector<bool>is_term2(r);
	for (int i = 0; i < e; i++) {
		int tmp;
		cin >> tmp;
		tmp--;
		is_term2[tmp] = true;
	}
	vector<unordered_map<char, int>> dest2(r);
	d2.resize(r);
	for (int i = 0; i < w; i++) {
		int a, b;
		char c;
		cin >> a >> b >> c;
		a--;
		b--;
		dest2[a].insert({ c, b });
	}
	for (int i = 0; i < r; i++) {
		bool check = true;
		for (char c = 'a'; c <= 'z'; c++) {
			if (dest2[i].count(c) != 0)
				if (dest2[i].at(c) != i) {
					check = false;
					break;
				}
		}
		d2[i] = check;
	}
	cout << (obhod(dest1, dest2, is_term1, is_term2, 0, 0) ? "YES" : "NO");
	return 0;
}