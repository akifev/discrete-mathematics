#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
int main() {
	ifstream cin("nfc.in");
	ofstream cout("nfc.out");
	ll n;
	cin >> n;
	char ch;
	cin >> ch;
	ll start = ch - 'A';
	vector<vector<vector<ll>>>nt(26);
	vector<vector<ll>>t(26);
	for (ll i = 0; i < n; i++) {
		char tmp;
		cin >> tmp;
		ll new_ = tmp - 'A';
		string s;
		cin >> s;
		cin >> s;
		if (s.size() != 2)
			t[new_].push_back({ s[0] - 'a' });
		else
			nt[new_].push_back(vector<ll>{s[0] - 'A', s[1] - 'A'});
	}
	string str;
	cin >> str;
	ll len = str.size();
	vector<vector<vector<ll>>> cubik(26, vector<vector<ll>>(len, vector<ll>(len)));
	for (ll i = 0; i < 26; i++)
		for (ll j = 0; j < len; j++)
			for (auto term : t[i])
				if (term == str[j] - 'a') {
					cubik[i][j][j] = 1;
					break;
				}
	for (ll suf = 2; suf <= len; suf++)
		for (ll pref = 0; pref <= len - suf; pref++)
			for (ll c = 0; c < 26; c++)
				for (auto neterm : nt[c])
					for (ll j = pref; j < min(pref + suf - 1, len - 1); j++)
						cubik[c][pref][pref + suf - 1] = (cubik[c][pref][pref + suf - 1] + cubik[neterm[1]][j + 1][pref + suf - 1] * cubik[neterm[0]][pref][j]) % 1000000007;
	cout << cubik[start][0][len - 1];
}