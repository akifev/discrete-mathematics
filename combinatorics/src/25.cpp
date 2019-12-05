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
	ifstream cin("nextchoose.in");
	ofstream cout("nextchoose.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int>a(k + 1);
	a[k] = 1 + n;
	for (int i = 0; i < k; i++)
		cin >> a[i];
	if (!(a[0] == n - k + 1)) {
		int p = k - 1;
		for (; p >= 0; p--)
			if (abs(a[p + 1] - a[p]) >= 2)
				break;
		++a[p];
		p++;
		for (; p < k; p++)
			a[p] = a[p - 1] + 1;
		for (int i = 0; i < k; i++)
			cout << a[i] << ' ';
	}
	else
		cout << -1;
}