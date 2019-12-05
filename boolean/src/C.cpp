#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cmath>
using namespace std;
bool save_0(string s) {
	return s[0] == '0';
}
bool save_1(string s) {
	return s[s.size() - 1] == '1';
}
bool monotonna(string s, int a, int cnt) {
	if (cnt > 1) {
		for (int i = a; i < a + cnt / 2; i++) {
			if (s[i] > s[i + cnt / 2]) {
				return false;
			}
		}
		return monotonna(s, a, cnt / 2) && monotonna(s, a + cnt / 2, cnt / 2);
	}
	else {
		return true;
	}
}
bool samodv(string s) {
	if (s.size() > 1) {
		for (int i = 0; i < s.size() / 2; i++) {
			if (s[i] == s[s.size() - i - 1]) {
				return false;
			}
		}
		return true;
	}
	else {
		return false;
	}
}
bool lineina(string s) {
	int size = s.size();
	int k = 0;
	while (size > 0) {
		for (int i = 0; i < size; i++) {
			if (i == 0) {
				if ((k&(k - 1)) && s[0] == '1')
					return false;
				k++;
			}
			else {
				s[i - 1] = ('0' + ((bool)(s[i] - '0') ^ (bool)(s[i - 1] - '0')));
			}
		}
		size--;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>>w(2 * n, vector<int>(2 * n, 0));
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		int indA = (a < 0 ? (-1)*a + n - 1 : a - 1), indB = (b < 0 ? (-1)*b + n - 1 : b - 1);
		w[(indA + n) % (2 * n)][indB] = 1;
		w[(indB + n) % (2 * n)][indA] = 1;
	}
	for (int i = 0; i < 2 * n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			for (int k = 0; k < 2 * n; k++) {
				if (w[j][i] && w[i][k])
					w[j][k] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (w[i][i + n] && w[i + n][i]) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}