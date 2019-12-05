//#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
map<ll, vector<string>> trans;
vector<bool> have_way(256, false);
ll n;
ifstream cin("epsilon.in");
ofstream cout("epsilon.out");
void read() {
	for (int i = 0; i < n; i++) {
		char tmp;
		cin >> tmp;
		ll r = (ll)(tmp - 'A');
		string s;
		cin >> s;
		getline(cin, s);
		if (!s.empty())
			s = s.substr(1, s.size() - 1);
		else
			have_way[r] = true;
		if (trans.count(r))
			trans.at(r).push_back(s);
		else
			trans.insert(make_pair(r, vector<string>{ s }));
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	char ch;
	cin >> ch;
	ll st = (ll)(ch - 'A');
	read();
	bool check = true;
	while (check) {
		check = false;
		for (ll i = 0; i < 26; i++)
			if (trans.count(i) && !have_way[i]) {
				for (auto str : trans.at(i)) {
					bool res = true;
					for (auto j : str)
						res &= have_way[j - 'A'];
					if (res) {
						have_way[i] = true;
						check = true;
					}
				}
				if (have_way[i])
					break;
			}
	}
	for (ll i = 0; i < 26; i++)
		if (have_way[i])
			cout << (char)('A' + i) << endl;
	return 0;
}