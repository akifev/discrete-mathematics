#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	int ans;
	int n;
	cin >> n;
	int size = pow(2, n);
	vector<string>arg(size);
	vector<bool>table(size);
	for (int i = 0; i < size; i++) {
		cin >> s;
		arg[i] = s;
		cin >> ans;
		table[i] = (bool)ans;
	}
	int k = 0;
	while (size > 0) {
		for (int i = 0; i < size; i++) {
			if (i == 0) {
				cout << arg[k++] << " " << table[0] << endl;
			}
			else {
				table[i - 1] = table[i] ^ table[i - 1];
			}
		}
		size--;
	}
	return 0;
}