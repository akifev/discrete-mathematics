#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <fstream>

using namespace std;
typedef long long ll;
#define forn(i, n) for (ll i = 0; i < n; i++)
#define forna(i, a, n) for (ll i = a; i < n; i++)
#define rforn(i, n) for (ll i = n - 1; i >= 0; i--)
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
ll n;

vector<vector<bool>> a;
vector<ll> ans;
vector<ll> time_to;

void f() {
    forna(next, 1, n) {
        bool check = false;
        forn(i, ans.size()) {
            if (!a[ans[i]][next]) {
                ans.insert(ans.begin() + i, next);
                check = true;
                break;
            }
        }
        if (!check) {
            ans.push_back(next);
        }
    }
}

int main() {
    ifstream cin("guyaury.in");
    ofstream cout("guyaury.out");
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    cin >> n;
    a.resize(n, vector<bool>(n, false));
    forna(i, 1, n) {
        string s;
        cin >> s;
        forn(j, i) {
            if (s[j] == '1') {
                a[i][j] = true;
            } else {
                a[j][i] = true;
            }
        }
    }
    ans.resize(1);
    ans[0] = 0;
    f();
    int pos = -1;
    forna(i, 2, n) {
        if (a[ans[i]][ans[0]])
            pos = i;
    }
    pos++;
    ll cycle_size = pos;
    vector<ll> to_cycle;
    forna(k, pos, n) {
        to_cycle.push_back(ans[k]);
        ll place = -1;
        forn(i, cycle_size) {
            if (a[ans[k]][ans[i]]) {
                auto it = ans.begin() + i;
                ans.insert(it, to_cycle.begin(), to_cycle.end());
                cycle_size += to_cycle.size();
                it = ans.begin() + cycle_size;
                auto it_end = ans.begin() + cycle_size + to_cycle.size();
                ans.erase(it, it_end);
                to_cycle.clear();
                to_cycle.resize(0);
                break;
            }
        }
    }
    forn(i, n) {
        cout << ans[i] + 1 << ' ';
    }
}