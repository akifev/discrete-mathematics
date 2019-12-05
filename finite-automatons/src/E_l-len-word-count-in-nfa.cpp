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
#include <bitset>
using namespace std;
vector<unordered_set<int>> states;
queue<int> q_cur;
void bfs(vector <unordered_map<char, unordered_set<int>>> &nka_dest, vector <vector<int>> &dka_dest, vector<bool> &is_term_nka, vector<bool> &is_term_dka, vector<int> &term_dka) {
	states.push_back({ 0 });
	q_cur.push(0);
	int sz = 1;
	while (!q_cur.empty()) {
		int cur = q_cur.front();
		q_cur.pop();
		for (char c = 'a'; c <= 'z'; c++) {
			unordered_set<int> new_set;
			for (int pos = 0; pos < 100; pos++)
				if (states[cur].count(pos) > 0 && nka_dest[pos].count(c) > 0) {
					for (auto &u_pos : nka_dest[pos].at(c))
						new_set.insert(u_pos);
				}
			bool seen = false;
			int position;
			for (position = 0; position < states.size(); position++) {
				seen |= (states[position] == new_set);
				if (seen)
					break;
			}
			if (!(seen)) {
				states.push_back(new_set);
				q_cur.push(sz);
				position = sz;
				sz++;
			}
			//if (dka_dest.size() <= cur)
			//	dka_dest.resize(cur + 1);
			dka_dest[cur].push_back(position);
		}
	}
	is_term_dka.resize(dka_dest.size(), false);
	for (int i = 0; i < dka_dest.size(); i++)
		for (int j = 0; j < nka_dest.size(); j++)
			if ((states[i].count(j) > 0) && (is_term_nka[j]))
				if (!is_term_dka[i]) {
					is_term_dka[i] = true;
					term_dka.push_back(i);
				}
}
int main() {
	ifstream cin("problem5.in");
	ofstream cout("problem5.out");
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k, l, ans = 0;
	cin >> n >> m >> k >> l;
	vector<bool>is_term_nka(n, false);
	vector<int>term_nka(k);
	for (int i = 0; i < k; i++) {
		cin >> term_nka[i];
		term_nka[i]--;
		is_term_nka[term_nka[i]] = true;
	}
	vector<unordered_map<char, unordered_set<int>>> nka_dest(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		char c;
		cin >> a >> b >> c;
		a--;
		b--;
		if (nka_dest[a].count(c) == 0)
			nka_dest[a].insert({ c,{ b } });
		else
			nka_dest[a].at(c).insert(b);
	}
	vector<vector<int>> dka_dest;
	vector<bool>is_term_dka;
	vector<int>term_dka;
	bfs(nka_dest, dka_dest, is_term_nka, is_term_dka, term_dka);
	vector<vector<int>> cnt(dka_dest.size(), vector<int>(l + 1, 0));
	cnt[0][0] = 1;
	for (int q = 0; q < l; q++)
		for (int w = 0; w < dka_dest.size(); ++w)
			for (int u = 0; u < dka_dest[w].size(); u++) {
				cnt[dka_dest[w][u]][q + 1] += cnt[w][q];
				cnt[dka_dest[w][u]][q + 1] %= (int)1e9 + 7;
			}
	for (int i = 0; i < term_dka.size(); i++) {
		ans += cnt[term_dka[i]][l];
		ans %= (int)1e9 + 7;
	}
	cout << ans;
	return 0;
}