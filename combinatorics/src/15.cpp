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
	ifstream cin("num2choose.in");
	ofstream cout("num2choose.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long  n, k, m;
	cin >> n >> k >> m;
	ull num = 1;
	vector<vector<ull>>col(n, vector<ull>(n, 1e19));
	for (int i = 0; i < n; i++)
		col[i][0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 1; j <= i; j++)
			col[i][j] = col[i][j - 1] * (i - j + 1) / j;
	n--;
	for (long long i = k - 1; i >= 0; num++, n--) {
		if (m >= col[n][i])
			m -= col[n][i];
		else {
			i--;
			cout << num << ' ';
		}
	}
}