#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
string w;
map<char, set<string>>tr;
bool check(ll pos, char current) {
	if (pos == w.size())
		return tr.count(current) == 0;
	if (tr.count(current) > 0)
		for (auto s : tr.at(current))
			if (s[0] == w[pos])
				if (check(pos + 1, s[s.size() - 1]))
					return true;
	return false;
}
int main() {
	ifstream cin("automaton.in");
	ofstream cout("automaton.out");
	ll n, m;
	char start;
	cin >> n >> start;
	for (ll i = 0; i < n; i++) {
		char ch;
		cin >> ch;
		string str;
		cin >> str >> str;
		if (tr.count(ch) == 0)
			tr.insert(make_pair(ch, set<string>{str}));
		else
			tr.at(ch).insert(str);
	}
	cin >> m;
	for (ll i = 0; i < m; i++) {
		cin >> w;
		cout << (check(0, start) ? "yes" : "no") << endl;
	}
	return 0;
}