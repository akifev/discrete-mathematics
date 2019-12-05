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
	ifstream cin("num2part.in");
	ofstream cout("num2part.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ull sum, k;
	vector<ull>v;
	cin >> sum >> k;
	vector<vector<int>>a(sum + 1, vector<int>(sum + 1, 0));
	for (int i = 0; i < sum + 1; i++)
		a[i][i] = 1;
	for (int i = 0; i < sum + 1; i++)
		for (int j = i - 1; j >= 0; j--) {
			if (i - j >= 0)
				a[i][j] += a[i - j][j];
			if (j + 1 < sum + 1)
				a[i][j] += a[i][j + 1];
		}
	/*for (auto i : a) {
		for (auto j : i)
			cout << j << ' ';
		cout << '\n';
	}/*/
	int x = sum, y = 1;
	do {
		if (a[x - y][y] > k) {
			v.push_back(y);
			x -= y;
		}
		else {
			k -= a[x - y][y];
			y++;
		}
		if (x == y) {
			v.push_back(y);
			break;
		}
	} while (true);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
		if (i != v.size() - 1)
			cout << '+';
	}
}