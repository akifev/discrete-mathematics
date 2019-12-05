#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

int main() {
	ifstream cin("shooter.in");
	ofstream cout("shooter.out");
	int n, m, k;
	cin >> n >> m >> k;
	long double ans = 0;
	long double ver, sum = 0;
	for (int i = 0; i < n; i++) {
		long double a;
		cin >> a;
		if (i == k - 1) {
			ver = pow((long double)1 - a, m);
		}
		sum += pow((long double)1 - a, m);
	}
	cout << setprecision(20) << ver / sum;
	return 0;
}