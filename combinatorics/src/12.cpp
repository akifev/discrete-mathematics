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
int n, k;
void subsets(vector <vector <int> > a, int it)
{
	if (it == n + 1 && a.size() == k)
	{
		for (int i = 0; i < a.size(); i++) {
			for (int j = 0; j < a[i].size(); j++) {
				cout << a[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << endl;
	}
	if (it >= n + 1)
		return;

	for (int i = 0; i < a.size(); i++)
	{
		a[i].push_back(it);
		subsets(a, it + 1);
		a[i].pop_back();
	}

	a.push_back({ it });
	subsets(a, it + 1);
	a.pop_back();
}

int main() {
	freopen("part2sets.in", "r", stdin);
	freopen("part2sets.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	vector <vector <int> > a;
	subsets(a, 1);
}