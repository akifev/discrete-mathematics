#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <set>
#include <bitset>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define forn(i, n) for (ll i = 0; i < n; i++)
#define forna(i, a, n) for (ll i = a; i < n; i++)
const ld EPS = 1e-9;
const ll INF = static_cast<const ll>(1e18);

int main() {
    ifstream cin("check.in");
    ofstream cout("check.out");
    cout.sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    set<ll> S;
    hash<vector<bool>> f;
    vector<vector<ll>> sem(m);
    forn(i, m) {
        ll sizeA;
        cin >> sizeA;
        vector<bool> A(10, false);
        forn(j, sizeA) {
            ll tmp;
            cin >> tmp;
            sem[i].push_back(tmp - 1);
            A[tmp - 1] = true;
        }
        S.insert(f(A));
    }
    vector<bool> tmpA(10, false);
    if (!S.count(f(tmpA))) {
        cout << "NO";
        return 0;
    }
    forn(i, m) {
        if (sem[i].size() > 1) {
            vector<ll> curA = sem[i];
            bitset<10> mask(0);
            ll start = 0;
            while (start < 1024) {
                vector<bool> A(10, false);
                forn(k, sem[i].size()) {
                    if (mask[sem[i][k]]) {
                        A[sem[i][k]] = true;
                    }
                }
                if (!S.count(f(A))) {
                    cout << "NO";
                    return 0;
                }
                start++;
                mask = bitset<10>(start);
            }
        }
    }
    forn(i, m) {
        forn(j, m) {
            if (sem[i].size() < sem[j].size()) {
                vector<ll> curA = sem[i];
                bool check_zamena = false;
                for (auto it : sem[j]) {
                    bool have = false;
                    forn(k, curA.size()) {
                        if (curA[k] == it) {
                            have = true;
                            break;
                        }
                    }
                    if (have) {
                        continue;
                    }
                    curA.push_back(it);
                    vector<bool> A(10, false);
                    forn(k, curA.size()) {
                        A[curA[k]] = true;
                    }
                    if (S.count(f(A))) {
                        check_zamena = true;
                        break;
                    }
                    curA.pop_back();
                }
                if (!check_zamena) {
                    cout << "NO";
                    return 0;
                }
            }
        }
    }
    cout << "YES";
}
