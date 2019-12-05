#include <iostream>
#include <vector>

typedef long long ll;

#define forn(i, n) for(ll i = 0; i < n; ++i)
#define sz size()

const ll delit = 998244353;

using namespace std;

vector<ll> first;
vector<ll> second;
vector<ll> sum;
vector<ll> umn;
vector<ll> del;
vector<ll> keeper(1, 1);

bool f() {
    return umn.sz > 0 && !umn[umn.sz - 1];
}

void clear() {
    while (f()) umn.pop_back();
}

int main() {
    ll n;
    ll m;
    cin >> n;
    cin >> m;
    n++;
    m++;
    ll size = max(n, m);
    first.resize(2000 * size, 0);
    second.resize(2000 * size, 0);
    forn(i, n) cin >> first[i];
    forn(i, m) cin >> second[i];
    forn(i, size) sum.emplace_back((first[i] + second[i]) % delit);
    forn(i, n + m) {
        ll cur_ans = 0;
        forn(j, i + 1) {
            cur_ans += first[j] * second[i - j];
            cur_ans %= delit;
        }
        umn.emplace_back(cur_ans);
    }
    clear();
    forn(i, 1000) {
        ll ost = 0;
        forn(j, i + 1) {
            ost += keeper[j] * second[i - j + 1];
            ost %= delit;
        }
        keeper.emplace_back((-ost + delit) % delit);
    }
    forn(i, 1000) {
        ll cur_ans = 0;
        forn(j, i + 1) {
            cur_ans += first[j] * keeper[i - j];
            cur_ans %= delit;
        }
        del.emplace_back(cur_ans);
    }
    cout << size - 1 << endl;
    forn(i, size) cout << sum[i] << ' ';
    cout << endl;
    cout << umn.sz - 1 << endl;
    forn(i, umn.sz) cout << umn[i] << ' ';
    cout << endl;
    forn(i, 1000) cout << del[i] << ' ';
    return 0;
}