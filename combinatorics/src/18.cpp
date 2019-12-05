#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <set>
#include <fstream>
#include <map>
#include <list>
using namespace std;
typedef unsigned long long ull;
int main() {
	ifstream cin("brackets2num.in");
	ofstream cout("brackets2num.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	vector<vector<ull>>a(s.size() + 1, vector<ull>(s.size() + 1, 0));
	a[0][0] = 1;
	for (int i = 1; i < s.size() + 1; i++) {
		for (int j = 0; j < s.size() + 1; j++) {
			if (j - 1 >= 0)
				a[i][j] += a[i - 1][j - 1];
			if (j + 1 < s.size() + 1)
				a[i][j] += a[i - 1][j + 1];
		}
	}
	int b = 0;
	ull n = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(')
			b++;
		else {
			n += a[s.size() - i - 1][b + 1];
			b--;
		}
	}
	cout << n;
}