#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
ifstream in("brackets.in");
ofstream out("brackets.out");
void next(int opened, int b, int n, int p, vector<char>& a) {
	if (opened < n) {
		a[p] = '(';
		next(opened + 1, b + 1, n, p + 1, a);
		if (b > 0) {
			a[p] = ')';
			next(opened, b - 1, n, p + 1, a);
		}
	}
	else
		if (b == 0) {
			for (int i = 0; i < 2 * n; i++)
				out << a[i];
			out << '\n';
		}
		else {
			a[p] = ')';
			next(opened, b - 1, n, p + 1, a);
		}
}
int main() {
	int n;
	in >> n;
	vector<char>a(2 * n);
	next(0, 0, n, 0, a);
}