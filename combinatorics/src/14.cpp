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
ull fact(ull n) {
	return (n > 1 ? n*fact(n - 1) : 1);
}
int main() {
	ifstream cin("perm2num.in");
	ofstream cout("perm2num.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ull n;
	cin >> n;
	vector<ull>a(n);
	for (ull i = 0; i < n; i++)
		a[i] = i + 1;
	ull tmp, ans = 0, f = n - 1;
	for (ull i = 0; i < n; i++) {
		cin >> tmp;
		ull pos = 0;
		for (ull j = 0; j < a.size(); j++)
			if (a[j] == tmp) {
				pos = j;
				a.erase(a.begin() + j);
				break;
			}
		ans += fact(f--)*pos;
	}
	cout << ans;
}