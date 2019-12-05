#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cmath>
using namespace std;
int isThereOne(vector<vector<int>>& input, int line) {
	int cnt = 0, col = -1;
	for (int i = 0; i < input[line].size() && cnt < 2; i++) {
		if (input[line][i] != -1) {
			cnt++;
			col = i;
		}
	}
	return (cnt == 1 ? col : -1);
}
void deleteRow(vector<vector<int>>& input, int line) {
	for (int i = 0; i < input[line].size(); i++) {
		input[line][i] = -1;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<vector<int>>input(k, vector<int>(n));
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			cin >> input[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		int col = isThereOne(input, i);
		if (col != -1) {
			int val = input[i][col];
			for (int j = 0; j < k; j++) {
				if (input[j][col] == val) {
					deleteRow(input, i);
				}
				else {
					if (input[j][col] != -1) {
						int tmp = isThereOne(input, j);
						if (tmp != -1) {
							cout << "YES";
							return 0;
						}
						else {
							input[j][col] = -1;
						}
					}
				}
			}
			i = -1;
		}
	}
	cout << "NO";
	return 0;
}