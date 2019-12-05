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
	ifstream cin("lzw.in");
	ofstream cout("lzw.out");
	vector<string>p(26);
	string s;
	cin >> s;
	s += ';';
	char c = 'a';
	for (int i = 0; i < 26; i++) {
		p[i].push_back(c++);
	}
	string tmp;
	for (int i = 0; i < s.size(); i++) {
		bool check = true;
		tmp += s[i];
		for (int j = 0; j < p.size(); j++) {
			if (p[j] == tmp) {
				check = false;
			}
		}
		if (check) {
			p.push_back(tmp);
			tmp.pop_back();
			for (int j = 0; j < p.size(); j++) {
				if (p[j] == tmp) {
					cout << j << ' ';
				}
			}
			tmp.clear();
			tmp = s[i];
		}
	}
	return 0;
}