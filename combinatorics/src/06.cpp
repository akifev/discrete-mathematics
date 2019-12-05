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
int main() {
	ifstream cin("vectors.in");
	ofstream cout("vectors.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<string>a;
	string s(n, '0');
	for (int i = 0; i < pow(2, n); i++) {
		bool check = true;
		for (int j = 1; j < s.size(); j++) {
			if (s[j] == '1'&&s[j - 1] == '1') {
				check = false;
				break;
			}
		}
		if (check) {
			a.push_back(s);
		}
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
	cout << a.size() << '\n';
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << '\n';
	}
	return 0;
}