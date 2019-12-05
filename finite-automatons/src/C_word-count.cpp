#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <ctime>
#include <stack>
#include <algorithm>
#include <cmath>
#include <fstream>
using namespace std;
void way_to_term(vector<vector<int>> &destrev, vector<bool> &have_way, int cur) {
	have_way[cur] = true;
	for (int i = 0; i < destrev[cur].size(); i++) {
		int next = destrev[cur][i];
		if (!have_way[next])
			way_to_term(destrev, have_way, next);
	}
}
bool check = true;
void dfs(vector<vector<int>> &dest, vector<int> &color, vector<bool> &have_way, int cur) {
	color[cur] = 1;
	for (int i = 0; i < dest[cur].size(); i++) {
		int next = dest[cur][i];
		if (have_way[next]) {
			if (color[next] == 0) {
				dfs(dest, color, have_way, next);
			}
			if (color[next] == 1) {
				check = false;
				return;
			}
		}
	}
	color[cur] = 2;
}
vector<bool>used;
void upd_cnt(vector<vector<int>> &dest, vector<bool> &have_way, vector<int> &cnt, int cur) {
	used[cur] = true;
	for (int i = 0; i < dest[cur].size(); i++) {
		int next = dest[cur][i];
		if (have_way[next]) {
			if (!used[next]) {
				upd_cnt(dest, have_way, cnt, next);
			}
			cnt[cur] += cnt[next];
		}
	}
}

int main() {
	ifstream cin("problem3.in");
	ofstream cout("problem3.out");
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int>term(k);
	for (int i = 0; i < k; i++) {
		cin >> term[i];
		term[i]--;
	}
	vector<vector<int>> dest(n);
	vector<vector<int>> destrev(n);
	vector<bool>have_way(n);
	vector<int>color(n, 0);
	for (int i = 0; i < m; i++) {
		int a, b;
		char c;
		cin >> a >> b >> c;
		a--;
		b--;
		dest[a].push_back(b);
		destrev[b].push_back(a);
	}
	for (int i = 0; i < k; i++) {
		way_to_term(destrev, have_way, term[i]);
	}
	dfs(dest, color, have_way, 0);
	if (!check) {
		cout << -1;
		return 0;
	}

	used.resize(n, false);

	vector<int> cnt(n, 0);
	for (int i = 0; i < k; i++) {
		cnt[term[i]] = 1;
	}
	upd_cnt(dest, have_way, cnt, 0);
	cout << cnt[0];
	return 0;
}