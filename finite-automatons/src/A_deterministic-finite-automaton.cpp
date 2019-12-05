#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <ctime>
#include <algorithm>
#include <fstream>
using namespace std;
typedef long long ll;
string s;
unordered_set<ll>ans;
void strange_func(vector<pair<unordered_set<ll>, unordered_map<char, unordered_set<ll>>>> &dest, ll cur, ll pos) {
	if (dest[cur].second.count(s[pos]) > 0 && dest[cur].first.count(pos) == 0) {
		auto my_set = dest[cur].second.at(s[pos]);
		if (pos == s.size() - 1) {
			for (auto i : my_set)
				ans.insert(i);
		}
		else {
			ll next = -1;
			for (auto it = my_set.begin(); it != my_set.end(); it++) {
				next = *it;
				strange_func(dest, next, pos + 1);
			}
		}
		dest[cur].first.insert(pos);
	}
}
int main() {
	ifstream cin("problem1.in");
	ofstream cout("problem1.out");
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	ll n, m, k;
	cin >> n >> m >> k;
	vector<ll>term(k);
	for (ll i = 0; i < k; i++) {
		cin >> term[i];
		term[i]--;
	}
	vector<pair<unordered_set<ll>, unordered_map<char, unordered_set<ll>>>> dest(n);
	for (ll i = 0; i < m; i++) {
		ll a, b;
		char c;
		cin >> a >> b >> c;
		a--;
		b--;
		if (dest[a].second.count(c) == 0)
			dest[a].second.insert({ c, {b} });
		else
			dest[a].second.at(c).insert(b);
	}
	strange_func(dest, 0, 0);
	for (auto i : term) {
		if (ans.count(i) > 0) {
			cout << "Accepts";
			return 0;
		}
	}
	cout << "Rejects";
	return 0;
}