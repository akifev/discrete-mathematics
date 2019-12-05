#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
ifstream in;
ofstream out;
void f(int q, int k, vector<int>& a) {
	if (k == 0) {
		for (int i = 0; i < a.size(); i++)
			out << a[i] << (i != a.size() - 1 ? '+' : '\n');
	}
	else {
		for (int i = q; i <= k; i++) {
			a.push_back(i);
			f(i, k - i, a);
			a.pop_back();
		}
	}
}
int main() {
	in.open("partition.in");
	out.open("partition.out");
	int n;
	in >> n;
	vector<int>a;
	f(1, n, a);
}