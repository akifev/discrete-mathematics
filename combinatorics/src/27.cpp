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
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
int main() {
	freopen("nextbrackets.in", "r", stdin);
	freopen("nextbrackets.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int clz = 0, op = 0;
	int i = s.size() - 1;
	for (; i >= 0; i--) {
		if (s[i] == ')')
			clz++;
		else {
			op++;
			if (clz > op)
				break;
		}
	}
	if (i >= 0) {
		cout << s.substr(0, i);
		cout << ')';
		for (int j = 0; j < op; j++)
			cout << '(';
		for (int j = 0; j < clz - 1; j++)
			cout << ')';
	}
	else
		cout << '-';
	return 0;
}