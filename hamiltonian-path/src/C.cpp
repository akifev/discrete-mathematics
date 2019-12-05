#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <string>
#include <fstream>
#include <stack>
#include <ctime>

using namespace std;
typedef long long ll;
#define forn(i, n) for (ll i = 0; i < n; i++)
#define forna(i, a, n) for (ll i = a; i < n; i++)
#define rforn(i, n) for (ll i = n - 1; i >= 0; i--)
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
ll n;

bool f(ll fi, ll se) {
    string tmp;
    cout << "1 " << fi << ' ' << se << endl;
    cin >> tmp;
    return tmp == "YES";
}

void m(vector<ll> &a, ll l, ll r, ll m) {
    ll fi = 0, se = 0;
    vector<ll> ans(r - l);
    while (l + fi < m && m + se < r) {
        bool res = f(a[l + fi], a[m + se]);
        ans[fi + se] = (res ? a[l + fi] : a[m + se]);
        fi += (res ? 1 : 0);
        se += (res ? 0 : 1);
    }
    while (l + fi < m) ans[fi + se] = a[l + fi], fi++;
    while (m + se < r) ans[fi + se] = a[m + se], se++;
    forn(i, fi + se) a[l + i] = ans[i];
}

void m_sort(vector<ll> &a, ll l, ll r) {
    if (l + 1 >= r) {
        return;
    }
    m_sort(a, l, (l + r) / 2);
    m_sort(a, (l + r) / 2, r);
    m(a, l, r, (l + r) / 2);
}

int main() {
    //ifstream cin("chvatal.in");
    //ofstream cout("chvatal.out");
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<ll> a(n);
    forn(i, n) {
        a[i] = i + 1;
    }
    sort(a.begin(), a.end(), f);
    cout << 0 << ' ';
    forn(i, n) {
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}