#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ifstream cin("exam.in");
	ofstream cout("exam.out");
	int k, n;
	cin >> k >> n;
	double ans = 0;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		ans += (double)a / n * b / 100;
	}
	cout << ans;
	return 0;
}