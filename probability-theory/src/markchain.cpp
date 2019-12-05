#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ifstream cin("markchain.in");
	ofstream cout("markchain.out");
	int n;
	cin >> n;
	vector<vector<long double>>a(n, vector<long double>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	vector<vector<long double>>v(a);
	for (int k = 0; k < min(14, n); k++) {
		vector<vector<long double>>tmp(n, vector<long double>(n));
		for (int i = 0; i < n; i++) {
			for (int p = 0; p < n; p++) {
				long double sum = 0;
				for (int q = 0; q < n; q++) {
					sum += v[i][q] * v[q][p];
				}
				tmp[i][p] = sum;
			}
		}
		v = tmp;
	}
	for (int i = 0; i < n; i++) {
		long double sum = 0;
		for (int j = 0; j < n; j++) {
			sum += v[j][i];
		}
		cout << sum / n << endl;
	}
	return 0;
}