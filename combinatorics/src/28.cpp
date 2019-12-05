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
	ifstream cin("nextmultiperm.in");
	ofstream cout("nextmultiperm.out");
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
	if (voz) {
		int maxim = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (b[i] < maxim) {
				int tmp = maxim;
				int pos;
				for (int j = i + 1; j < n; j++)
					if (b[i] < b[j] && b[j] <= maxim)
					{
						tmp = b[j];
						pos = j;
					}
				for (int j = 0; j < i; j++)
					cout << b[j] << ' ';
				//cout << b[i << ' ';
				swap(b[pos], b[i]);
				sort(b.begin() + i + 1, b.end());
				for (int j = i; j < n; j++)
					cout << b[j] << ' ';
				//cout << '_' << maxim;
				return 0;
			}
			maxim = max(maxim, a[i]);
		}
	}
	else {
		for (int i = 0; i < n; i++)
			cout << 0 << ' ';
		cout << '\n';
	}
}