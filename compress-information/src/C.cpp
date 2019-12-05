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
	ifstream cin("mtf.in");
	ofstream cout("mtf.out");
	vector<int>p(26);
	string s;
	cin >> s;
	for (int i = 0; i < 26; i++) {
		p[i] = i;
	}
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < 26; j++) {
			if (s[i] == p[j] + 'a') {
				cout << j + 1 << ' ';
				for (int k = j; k >= 1; k--) {
					swap(p[k], p[k - 1]);
				}
				break;
			}
		}
	}
	return 0;
}