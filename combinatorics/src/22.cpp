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
	ifstream cin("part2num.in");
	ofstream cout("part2num.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ull tmp, sum = 0;
	vector<ull>v;
	while (cin >> tmp) {
		char c;
		if (cin >> c)
			;
		v.push_back(tmp);
		sum += tmp;
	}
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

	ull ans = 0, qwe = sum + 1;
	int j = 1;
	for (int i = 0; i < v.size(); i++)
		while (j <= v[i] && j < qwe && sum >= j) {
			if (j == v[i]) {
				sum -= v[i];
				break;
			}
			else {
				ans += a[sum - j][j];
				j++;
			}
		}
	cout << ans;
}