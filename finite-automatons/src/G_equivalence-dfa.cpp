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
vector<vector<bool>>used;
queue<pair<int, int>> q;
bool bfs(vector<unordered_map<char, int>> &dest1, vector<unordered_map<char, int>> &dest2, vector<bool> &is_term1, vector<bool> &is_term2) {
	q.push({ 0, 0 });
	while (!q.empty()) {
		pair<int, int> tmp = q.front();
		q.pop();
		int cur1 = tmp.first;
		int cur2 = tmp.second;
		if (is_term1[cur1] != is_term2[cur2]) {
			return false;
		}
		used[cur1][cur2] = true;
		for (char c = 'a'; c <= 'z'; c++) {
			if (dest1[cur1].count(c) > 0 && dest2[cur2].count(c) == 0) {
				if (!used[dest1[cur1].at(c)][dest2.size() - 1])
					q.push({ dest1[cur1].at(c), dest2.size() - 1 });
			}
			else if (dest1[cur1].count(c) == 0 && dest2[cur2].count(c) > 0) {
				if (!used[dest1.size() - 1][dest2[cur2].at(c)])
					q.push({ dest1.size() - 1, dest2[cur2].at(c) });
			}
			else if (dest1[cur1].count(c) > 0 && dest2[cur2].count(c) > 0) {
				if (!used[dest1[cur1].at(c)][dest2[cur2].at(c)])
					q.push({ dest1[cur1].at(c), dest2[cur2].at(c) });
			}
		}
	}
	return true;
}
int main() {
	ifstream cin("equivalence.in");
	ofstream cout("equivalence.out");
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	n++;
	vector<bool>is_term1(n, false);
	for (int i = 0; i < k; i++) {
		int tmp;
		cin >> tmp;
		tmp--;
		is_term1[tmp] = true;
	}
	vector<unordered_map<char, int>> dest1(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		char c;
		cin >> a >> b >> c;
		a--;
		b--;
		dest1[a].insert({ c, b });
	}
	int r, w, e;
	cin >> r >> w >> e;
	r++;
	used.resize(n, vector<bool>(r));
	vector<bool>is_term2(r);
	for (int i = 0; i < e; i++) {
		int tmp;
		cin >> tmp;
		tmp--;
		is_term2[tmp] = true;
	}
	vector<unordered_map<char, int>> dest2(r);
	for (int i = 0; i < w; i++) {
		int a, b;
		char c;
		cin >> a >> b >> c;
		a--;
		b--;
		dest2[a].insert({ c, b });
	}
	for (char c = 'a'; c <= 'z'; c++) {
		dest1[n - 1].insert({ c, n - 1 });
		dest2[r - 1].insert({ c, r - 1 });
	}

	cout << (bfs(dest1, dest2, is_term1, is_term2) ? "YES" : "NO");
	return 0;
}