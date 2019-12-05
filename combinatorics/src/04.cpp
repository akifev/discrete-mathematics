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
#include <unordered_set>
using namespace std;
typedef unsigned long long ull;
int main() {
	ifstream cin("chaincode.in");
	ofstream cout("chaincode.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	unordered_set<string>a;
	string s(n, '0');
	a.insert(s);
	for (int i = 0; i < pow(2, n); i++) {
		cout << s << '\n';
		s = s.substr(1, n - 1) + '1';
		int sz = a.size();
		a.insert(s);
		if (a.size() == sz) {
			s[n - 1] = '0';
			a.insert(s);
			if (a.size() == sz) {
				break;
			}
		}
	}

	return 0;
}