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
	ifstream cin("telemetry.in");
	ofstream cout("telemetry.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	ull sz = pow(k, n);
	vector<stack<int>>a(sz);
	for (int i = 0; i < k; i++) {
		a[i].push(i);
	}
	int q = k, p = k, beg = k - 1, end = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < q; j++) {
			if (beg < end)
				for (int r = beg; r <= end; r++) {
					a[j*k + r - beg] = a[r];
					a[j*k + r - beg].push(j);
				}
			else
				for (int r = beg; r >= end; r--) {
					a[j*k + beg - r] = a[r];
					a[j*k + beg - r].push(j);
				}
			swap(beg, end);
		}
		for (int j = 0; j < k; j++) {
			a[j].push(0);
		}
		k *= q;
		beg = k - 1;
		end = 0;
	}
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i].top();
			a[i].pop();
		}
		cout << '\n';
	}
	return 0;
}