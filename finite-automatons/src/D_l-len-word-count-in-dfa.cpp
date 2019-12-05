#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <ctime>
#include <algorithm>
#include <cmath>
#include <fstream>
using namespace std;
int main() {
	ifstream cin("problem4.in");
	ofstream cout("problem4.out");
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k, l, ans = 0;
	cin >> n >> m >> k >> l;
	vector<int>term(k);
	for (int i = 0; i < k; i++) {
		cin >> term[i];
		term[i]--;
	}
	vector<vector<int>> dest(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		char c;
		cin >> a >> b >> c;
		a--;
		b--;
		dest[a].push_back(b);
	}
	vector<vector<int>> cnt(n, vector<int>(l + 1, 0));
	cnt[0][0] = 1;
	for (int q = 0; q < l; q++) {
		for (int w = 0; w < dest.size(); ++w) {
			for (int u = 0; u < dest[w].size(); u++) {
				cnt[dest[w][u]][q + 1] += cnt[w][q];
				cnt[dest[w][u]][q + 1] %= (int)1e9 + 7;
			}
		}
	}
	for (int i = 0; i < k; i++) {
		ans += cnt[term[i]][l];
		ans %= (int)1e9 + 7;
	}
	cout << ans;
	return 0;
}