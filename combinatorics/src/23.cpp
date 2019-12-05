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
	ifstream cin("nextvector.in");
	ofstream cout("nextvector.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	string n = s;
	bool next = false;
	for (int i = n.size() - 1; i >= 0; i--)
		if (n[i] == '0') {
			n[i] = '1';
			next = true;
			break;
		}
		else
			n[i] = '0';
	bool check = false;
	for (int i = s.size() - 1; i >= 0; i--)
		if (s[i] == '1') {
			s[i] = '0';
			check = true;
			break;
		}
		else
			s[i] = '1';
	cout << (check ? s : "-") << '\n' << (next ? n : "-");
}