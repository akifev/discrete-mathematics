#define _CRT_SECURE_NO_WARNINGS
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
#include <cstdio>
using namespace std;
typedef unsigned long long ull;
int main() {
	freopen("choose2num.in", "r", stdin);
	freopen("choose2num.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<vector<ull>>col(n, vector<ull>(n, 1e19));
	for (int i = 0; i < n; i++)
		col[i][0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 1; j <= i; j++)
			col[i][j] = col[i][j - 1] * (i - j + 1) / j;
	vector <ull> a(k + 1);
	for (int i = 1; i < k + 1; i++) {
		cin >> a[i];
	}
	a[0] = 0;
	ull ans = 0;
	for (int i = 1; i < k + 1; i++)
		for (int j = 1 + a[i - 1]; j < a[i]; j++)
			ans += col[n - j][k - i];
	cout << ans;
}