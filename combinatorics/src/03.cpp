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
	ifstream cin("antigray.in");
	ofstream cout("antigray.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	ull sz = pow(3, n);
	vector<vector<int>>a(sz, vector<int>(n));
	int k = sz / 3;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < sz; j++) {
			if ((j / k) % 3 == 1) {
				a[j][i] = 0;
			}
			else {
				if ((j / k) % 3 == 2) {
					a[j][i] = 1;
				}
				else {
					a[j][i] = 2;
				}
			}
		}
		k /= 3;
	}
	sz /= 3;
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j];
		}
		cout << '\n';
		for (int j = 0; j < n; j++) {
			cout << (a[i][j] + 1) % 3;
		}
		cout << '\n';
		for (int j = 0; j < n; j++) {
			cout << (a[i][j] + 2) % 3;
		}
		cout << '\n';
	}
	return 0;
}