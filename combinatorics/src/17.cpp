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
	ifstream cin("num2brackets.in");
	ofstream cout("num2brackets.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ull n, k;
	cin >> n >> k;
	n *= 2;
	n++;
	vector<vector<ull>>a(n, vector<ull>(n, 0));
	a[0][0] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j - 1 >= 0)
				a[i][j] += a[i - 1][j - 1];
			if (j + 1 < n)
				a[i][j] += a[i - 1][j + 1];
		}
	}

	string s;
	int b = 0;
	for (int i = 0; i < n - 1; i++)
		//if (b + 1 < n)
		if (a[n - i - 2][b + 1] > k)
			s += '(', b++;
		else {
			k -= a[n - i - 2][b + 1];
			s += ')', b--;
		}
		cout << s;
}