#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
#include <set>
#include <fstream>
#include <map>
#include <list>
using namespace std;
int main() {
	ifstream cin("huffman.in");
	ofstream cout("huffman.out");
	int n;
	cin >> n;
	vector<long long>p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	sort(p.begin(), p.end());
	int pnt = 0;
	long long ans = 0;
	for (int i = 0; i < n - 1; i++) {
		p.push_back(p[pnt] + p[pnt + 1]);
		pnt += 2;
		ans += p[p.size() - 1];
		for (int k = p.size() - 1; k > 0; k--) {
			if (p[k] < p[k - 1])
				swap(p[k], p[k - 1]);
		}
	}
	cout << ans;
	return 0;
}