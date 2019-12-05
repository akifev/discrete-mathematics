#define _CRT_SECURE_NO_WARNINGS
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
#include <cstdio>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
int main() {
	freopen("num2brackets2.in", "r", stdin);
	freopen("num2brackets2.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, k;
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
	stack<char>q;
	string s;
	long long b = 0;
	for (int i = 0; i < n - 1; i++) {
		ll x = n - 2 - i;
		if (a[x][b + 1] * pow(2, (x - b - 1) / 2) > k) {
			s += '(';
			b++;
			q.push('(');
		}
		else {
			k -= a[x][b + 1] * pow(2, (x - b - 1) / 2);
			if (!q.empty() && q.top() == '(' && a[x][b - 1] * pow(2, (x - b + 1) / 2) > k) {
				s += ')';
				b--;
				q.pop();
			}
			else {
				if (b > 0 && a[x][b - 1] * pow(2, (x - b + 1) / 2) <= k&&q.top() == '(')
					k -= a[x][b - 1] * pow(2, (x - b + 1) / 2);
				if (a[x][b + 1] * pow(2, (x - b - 1) / 2) > k) {
					s += '[';
					b++;
					q.push('[');
				}
				else {
					k -= a[x][b + 1] * pow(2, (x - b - 1) / 2);
					s += ']';
					b--;
					q.pop();
				}
			}
		}
	}
	cout << s;
	return 0;
}