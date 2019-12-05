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
ifstream in;
ofstream out;
void f(int n, int k, vector<int>& vec);
int main() {
	in.open("choose.in");
	out.open("choose.out");
	ios_base::sync_with_stdio(false);
	in.tie(NULL);
	int n, k;
	in >> n >> k;
	vector<int>a(k);
	for (int i = 0; i < k; i++) {
		a[i] = i + 1;
		out << i + 1;
		if (i != k - 1)
			out << ' ';
	}
	out << '\n';
	f(n, k, a);
	return 0;
}
void f(int n, int k, vector<int>& vec) {
	for (int i = k - 1, d = n + 1 - k; i >= 0; i--) {
		if (d + i > vec[i]) {
			vec[i]++;
			for (int j = i + 1; j < k; j++)
				vec[j] = 1 + vec[j - 1];
			for (int i = 0; i < k; i++)
				out << vec[i] << ' ';
			out << '\n';
			f(n, k, vec);
		}
	}
}