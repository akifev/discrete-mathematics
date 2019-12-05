#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	unsigned long long cnt = 0;
	vector<vector<int>>inp(n);
	vector<int>glub(n, -1);
	int d = 0;
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		inp[i] = vector<int>(m + (m != 0 ? 1 : 0) + pow(2, m));
		inp[i][0] = m;
		if (m != 0) {
			glub[i] = 1;
			int maxtmpd = -1;
			for (int q = 1; q <= m; q++) {
				cin >> inp[i][q];
				if (glub[inp[i][q] - 1] != -1 && maxtmpd < glub[inp[i][q] - 1])
					maxtmpd = glub[inp[i][q] - 1];
			}
			if (maxtmpd != -1)
				glub[i] += maxtmpd;
			for (int q = m + 1; q < m + 1 + pow(2, m); q++) {
				cin >> inp[i][q];
			}
			if (glub[i] > d) {
				d = glub[i];
			}
		}
		else {
			cnt++;
		}
	}
	cout << d << '\n';
	string args(cnt, '0');
	unsigned long long sz = pow(2, cnt);
	for (unsigned long long i = 0; i < sz; i++) {
		int point = 0, k = 0;
		vector<char>res(n);
		for (int q = 0; q < n; q++) {
			if (inp[q][0] != 0) {
				int ind = 0, y = inp[q][0] - 1;
				for (int p = 1; p <= inp[q][0]; p++, y--) {
					if (res[inp[q][p] - 1] == '1') {
						ind += pow(2, y);
					}
				}
				res[k++] = (char)('0' + inp[q][ind + inp[q][0] + 1]);
			}
			else {
				res[k++] = args[point++];
			}
		}
		cout << res[n - 1];
		for (int c = cnt - 1; c >= 0; c--) {
			if (args[c] == '1') {
				args[c] = '0';
			}
			else {
				args[c] = '1';
				break;
			}
		}
	}
}