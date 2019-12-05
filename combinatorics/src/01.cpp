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
	ifstream cin("allvectors.in");
	ofstream cout("allvectors.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string s(n, '0');
	for (int i = 0; i < pow(2, n); i++) {
		cout << s << '\n';
		for (int j = n - 1; j >= 0; j--) {
			if (s[j] == '0') {
				s[j] = '1';
				break;
			}
			else {
				s[j] = '0';
			}
		}
	}

	return 0;
}