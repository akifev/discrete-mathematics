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
	ifstream cin("nextperm.in");
	ofstream cout("nextperm.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int>a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	bool voz = false, ub = false;
	for (int i = 1; i < n; i++)
		if (a[i] > a[i - 1])
			voz = true;
		else
			ub = true;
	if (ub) {
		for (int i = n - 1; i > 0; i--)
			if (a[i - 1] > a[i]) {
				int tmp = i;
				for (int j = i + 1; j < n; j++)
					if (a[j]<a[i - 1] && a[j]>a[tmp])
						tmp = j;
				swap(a[i - 1], a[tmp]);
				reverse(a.begin() + i, a.end());
				break;
			}
		for (int i = 0; i < n; i++)
			cout << a[i] << ' ';
		cout << '\n';
	}
	else {
		for (int i = 0; i < n; i++)
			cout << 0 << ' ';
		cout << '\n';
	}
	if (voz) {
		for (int i = n - 1; i > 0; i--)
			if (b[i - 1] < b[i]) {
				int tmp = i;
				for (int j = i + 1; j < n; j++)
					if (b[j] > b[i - 1] && b[j] < b[tmp])
						tmp = j;
				swap(b[i - 1], b[tmp]);
				reverse(b.begin() + i, b.end());
				break;
			}
		for (int i = 0; i < n; i++)
			cout << b[i] << ' ';
		cout << '\n';
	}
	else {
		for (int i = 0; i < n; i++)
			cout << 0 << ' ';
		cout << '\n';
	}
}