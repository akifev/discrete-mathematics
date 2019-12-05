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
	freopen("brackets2num2.in", "r", stdin);
	freopen("brackets2num2.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	vector<vector<ull>>a(s.size() + 1, vector<ull>(s.size() + 1, 0));
	a[0][0] = 1;
	for (int i = 1; i < s.size() + 1; i++) {
		for (int j = 0; j < s.size() + 1; j++) {
			if (j - 1 >= 0)
				a[i][j] += a[i - 1][j - 1];
			if (j + 1 < s.size() + 1)
				a[i][j] += a[i - 1][j + 1];
		}
	}
	int b = 0;
	ull n = 0;
	stack<char>q;
	for (int i = 0; i < s.size(); i++) {
		ll x = s.size() - 1 - i;
		if (s[i] == '(') {
			b++;
			q.push('(');
		}
		else {
			n += a[x][b + 1] * pow(2, (x - b - 1) / 2);
			if (s[i] == ')') {
				b--;
				q.pop();
			}
			else {
				if (b > 0 && !q.empty() && q.top() == '(')
					n += a[x][b - 1] * pow(2, (x - b + 1) / 2);
				if (s[i] == '[') {
					b++;
					q.push('[');
				}
				else {
					n += a[x][b + 1] * pow(2, (x - b - 1) / 2);
					b--;
					q.pop();
					n += a[x][b + 1] * pow(2, (x - b - 1) / 2);
				}
			}
		}
	}
	cout << n;
}