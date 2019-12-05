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
	ifstream cin("num2perm.in");
	ofstream cout("num2perm.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ull n, k;
	cin >> n >> k;
	vector<ull>a(n);
	for (ull i = 0; i < n; i++)
		a[i] = i + 1;
	ull d = 1;
	stack<ull>st;
	while (d < n + 1) {
		st.push(k%d);
		k /= d;
		d++;
	}
	while (!st.empty()) {
		cout << a[st.top()] << ' ';
		a.erase(a.begin() + st.top());
		st.pop();
	}
}