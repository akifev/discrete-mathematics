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

vector<vector<bool>> a;

int main() {
    ifstream cin("chvatal.in");
    ofstream cout("chvatal.out");
    ios::sync_with_stdio(0);
    cin.tie(0);
    srand(time(0));
    cin >> n;
    a.resize(n, vector<bool>(n, false));
    forna(i, 1, n) {
        string s;
        cin >> s;
        forn(j, i) {
            if (s[j] == '1') {
                a[i][j] = true;
                a[j][i] = true;
            }
        }
    }
    deque<ll> deq;
//    vector<ll> tmp;
//    forn(i, n) {
//        tmp.push_back(i);
//    }
//    forn(i, n) {
//        ll p = rand() % n;
//        ll q = rand() % n;
//        swap(tmp[p], tmp[q]);
//    }
//    forn(i, n) {
//        deq.push_back(tmp[i]);
//    }
    forn(i, n) {
        deq.push_back(i);
    }
    forn(i, n * (n - 1)) {
        ll fi = deq.front();
        deq.pop_front();
        auto it = deq.begin();
        ll u = 1;
        ll se = *it;
        if (!a[fi][se]) {
            vector<ll> st = {se};
            it++;
            u++;
            while ((!a[fi][*it] || !a[se][*(it + 1)]) && u < n - 1) {
                st.push_back(*it);
                it++;
                u++;
            }
            st.push_back(*it);
            it = deq.begin();
            if (u == n - 1) {
                st.clear();
                st.resize(0);
                while (!a[fi][*it]) {
                    st.push_back(*it);
                    it++;
                }
                st.push_back(*it);
            }
            forn(j, st.size()) {
                deq.pop_front();
            }
            forn(j, st.size()) {
                deq.push_front(st[j]);
            }
        }
        deq.push_back(fi);
    }
    for (auto it : deq) {
        cout << it + 1 << ' ';
    }
}