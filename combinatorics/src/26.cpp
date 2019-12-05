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
int f(vector<int>& b, int x) {
	int i = -1;
	for (i = 0; i < b.size(); i++)
		if (b[i] > x)
			break;
	return i;
}
int main() {
	ifstream cin("nextsetpartition.in");
	ofstream cout("nextsetpartition.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	while (cin >> n >> k) {
		if ((n == 0 && k == 0))
			break;
		vector<vector<int>>x(k, vector<int>());
		vector<int>b;
		string tmp;
		getline(cin, tmp);
		for (int i = 0; i < k; i++) {
			getline(cin, tmp);
			int beg = 0, cnt = 0;
			for (int j = 0; j < tmp.size(); j++)
				if (j == tmp.size() - 1) {
					x[i].push_back(stoi(tmp.substr(beg, cnt + 1)));
				}
				else
					if (tmp[j] == ' ') {
						x[i].push_back(stoi(tmp.substr(beg, cnt)));
						beg += cnt + 1;
						cnt = 0;
					}
					else
						cnt++;
		}
		getline(cin, tmp);
		bool replaced = false;
		for (int i = x.size() - 1; i >= 0 && !replaced; i--) {
			int j = 0, tmp;
			if (!b.empty() && x[i].back() < b.back()) {
				x[i].push_back(b[f(b, x[i].back())]);
				b.erase(b.begin() + f(b, x[i][x[i].size() - 2]));
				sort(b.begin(), b.end());
				break;
			}
			for (j = x[i].size() - 1; j >= 0; j--) {
				if (j && !b.empty() && x[i][j] < b.back()) {
					swap(x[i][j], b[f(b, x[i][j])]);
					sort(b.begin(), b.end());
					replaced = true;
					break;
				}
				else {
					b.push_back(x[i][j]);
					sort(b.begin(), b.end());
					x[i].pop_back();
				}
			}
			if (x[i].empty())
				x.pop_back();
			if (replaced)
				break;
		}
		cout << n << ' ' << x.size() + b.size() << '\n';
		for (int i = 0; i < x.size(); i++) {
			for (int j = 0; j < x[i].size(); j++)
				cout << x[i][j] << ' ';

			cout << '\n';
		}
		sort(b.begin(), b.end());
		for (int i = 0; i < b.size(); i++)
			cout << b[i] << '\n';
		cout << '\n';
	}
	return 0;
}