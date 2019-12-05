#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
typedef long long ll;
using namespace std;
ifstream cin("useless.in");
ofstream cout("useless.out");
vector<char>been(26);
struct node {
	vector<string> trans;
	bool dostij;
	bool is_term;
	node() : dostij(false), is_term(false) {}
};
vector<node>ks(26);
void f(bool _do) {
	for (ll step = 0; step < 9999; step++)
		for (ll c = 0; c < 26; c++) {
			if ((_do ? !ks[c].is_term : ks[c].is_term))
				for (auto &_tr : ks[c].trans) {
					bool check = true;
					for (auto &_next : _tr)
						check &= ks[_next].is_term;
					if (check) {
						if (_do) {
							ks[c].is_term = true;
							break;
						}
						else
							for (auto &to : _tr)
								if (ks[to].is_term)
									ks[to].dostij |= ks[c].dostij;
					}
				}
		}
}
int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	char ch;
	cin >> n >> ch;
	ll fi = ch - 'A';
	been[fi] = true;
	ks[fi].dostij = true;
	for (ll i = 0; i < n; i++) {
		cin >> ch;
		ll l = ch - 'A';
		string str;
		cin >> str;
		getline(cin, str);
		been[l] = true;
		ks[l].trans.emplace_back();
		bool check = true;
		for (auto j : str)
			if ('A' <= j && j <= 'Z') {
				check = false;
				ks[l].trans.back().push_back(j - 'A');
				been[j - 'A'] = 1;
			}
		if (check)
			ks[l].is_term = true;
	}
	f(true);
	f(false);
	for (ll i = 0; i < 26; i++)
		if (!ks[i].dostij || !ks[i].is_term)
			if (been[i])
				cout << char('A' + i) << ' ';
	return 0;
}