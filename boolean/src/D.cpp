#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;
unsigned long long maxSize = 0;
void umn(string& a, string b) {
	for (unsigned long long i = 0; i < a.size(); i++) {
		a[i] = (b[i] == '0' ? '0' : a[i]);
	}
}
void notStr(string& a) {
	for (unsigned long long i = 0; i < a.size(); i++) {
		a[i] = (a[i] == '0' ? '1' : '0');
	}
}
string to_binary_string(unsigned long long n) {
	string s;
	while (n) {
		s.push_back('0' + n % 2);
		n /= 2;
	}
	if (maxSize < s.size()) {
		maxSize = s.size();
	}
	while (s.size() < 32) {
		s.push_back('0');
	}
	reverse(s.begin(), s.end());
	return s;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unsigned long long n;
	cin >> n;
	vector<string>a(n);
	for (unsigned long long i = 0; i < n; i++) {
		unsigned long long temp;
		cin >> temp;
		a[i] = to_binary_string(temp);
	}
	unsigned long long tmpSize = maxSize;
	unsigned long long tmp;
	cin >> tmp;
	if (tmp == 0) {
		cout << "1&~1";
		return 0;
	}
	string ans = to_binary_string(tmp);
	if (maxSize > tmpSize) {
		cout << "Impossible";
		return 0;
	}
	vector<string>vivod;
	for (int i = 31; i >= 0; i--) {
		if (ans[i] == '1') {
			string result = "";
			string checkStr = a[0];
			if (a[0][i] == '1') {
				result += '1';
			}
			else {
				notStr(checkStr);
				result += "~1";
			}
			for (int j = 1; j < n; j++) {
				string temporary = a[j];
				result += '&';
				if (a[j][i] == '0') {
					notStr(temporary);
					result += '~';
				}
				result += (char)('0' + j + 1);
				umn(checkStr, temporary);
			}
			for (int q = 0; q < 32; q++) {
				if (checkStr[q] == '1'&&ans[q] == '0') {
					cout << "Impossible";
					return 0;
				}
			}
			vivod.push_back(result);
		}
	}
	for (unsigned long long i = 0; i < vivod.size(); i++) {
		cout << vivod[i];
		if (i != vivod.size() - 1) {
			cout << "|";
		}
	}
	return 0;
}