#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

int main() {
	ifstream cin("lottery.in");
	ofstream cout("lottery.out");
	int n, m;
	cin >> n >> m;
	vector<double>a(m), b(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i] >> b[i];
	}
	double res = 0, ver = 1;
	for (int i = 0; i < m; i++) {
		ver *= (double)1 / a[i];
		if (i < m - 1) {
			res += ver * b[i] * (1 - 1 / a[i + 1]);
		}
		else {
			res += ver * b[i];
		}
	}
	cout << setprecision(10) << n - res;
	return 0;
}