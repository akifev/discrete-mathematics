#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
#include <set>
#include <fstream>
using namespace std;
int main() {
	ifstream cin("bwt.in");
	ofstream cout("bwt.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int sz = s.size();
	s += s;
	multiset<string>a;
	for (int i = 0; i < sz; i++) {
		a.insert(s.substr(i, sz));
	}
	for (multiset<string>::iterator it = a.begin(); it != a.end(); it++) {
		cout << (*it)[sz - 1];
	}
}