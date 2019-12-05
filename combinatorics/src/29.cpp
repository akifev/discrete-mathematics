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
typedef long long ll;
int main() {
	freopen("nextpartition.in", "r", stdin);
	freopen("nextpartition.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int sum, tmp;
	cin >> sum;
	char c;
	cin >> c;
	vector<int>a;
	while (cin >> tmp) {
		a.push_back(tmp);
		if (cin >> c);
	}
	if (a.size() == 1) {
		cout << "No solution";
		return 0;
	}
	int p = a.size() - 2;
	a.back()--;
	a[p]++;
	if (a[p] > a.back()) {
		a[p] += a.back();
		a.back() = 0;
	}
	else
		while (2 * a[p] <= a.back()) {
			a.push_back(a.back() - a[p]);
			a[p + 1] = a[p];
			p++;
		}
	cout << sum << '=';
	for (int i = 0; i < a.size(); i++) {
		if (a[i]) {
			cout << a[i];
			if (i < a.size() - 1 && a[i + 1])
				cout << '+';
		}
	}
	return 0;
}