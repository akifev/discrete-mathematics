#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <set>


using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define forn(i, n) for (ll i = 0; i < n; i++)
#define forna(i, a, n) for (ll i = a; i < n; i++)
const ld EPS = 1e-9;
const ll INF = static_cast<const ll>(1e18);

int main() {
    ifstream cin("schedule.in");
    ofstream cout("schedule.out");
    cout.sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    map<ll, multiset<ll>> m;
    ll ans = 0;
    forn(i, n) {
        ll d, w;
        cin >> d >> w;
        m[d].insert(w);
        ans += w;
    }
    vector<ll> diff;
    if (m.size() > 1) {
        auto it1 = m.rbegin(), it2 = m.rbegin();
        it2++;
        for (; it2 != m.rend(); it2++, it1++) {
            diff.push_back(it1->first - it2->first);
        }
    }
    diff.push_back(m.begin()->first);
    ll k = 0;
    multiset<ll> use;
    for (auto it = m.rbegin(); it != m.rend(); it++, k++) {
        for (auto i : it->second) {
            use.insert(i);
        }
        forn(i, diff[k]) {
            if (use.empty()) {
                break;
            }
            ans -= *(use.rbegin());
            ll to_del = *(use.rbegin());
            ll cnt = use.count(to_del);
            use.erase(to_del);
            forn(j, cnt - 1) {
                use.insert(to_del);
            }
        }
    }
    cout << ans;
}
