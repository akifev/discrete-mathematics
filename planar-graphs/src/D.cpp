#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <string>
#include <fstream>
#include <stack>
#include <cassert>

using namespace std;
typedef long long ll;
#define forn(i, n) for (ll i = 0; i < n; i++)
#define forna(i, a, n) for (ll i = a; i < n; i++)

const long double INF = 2e18;

struct ed { // ребро
    ll from, to;

    ed() = default;

    ed(ll a, ll b) : from(a), to(b) {};
};

struct graph {
    ll n;
    ll m;
    vector<vector<ll>> matrix;
    vector<ed> edges;
    vector<ll> ham_path;
    vector<ll> in_ham;
    vector<ll> color;
    vector<vector<ll>> link;
    bool is_planar;

    graph(ll n, ll m) {
        this->n = n;
        this->m = m;
        matrix.resize(n, vector<ll>(n, 0));
        ham_path.resize(n);
        in_ham.resize(n);
        color.resize(m, -1);
        is_planar = true;
    }

    void dfs(ll cur, ll col) {
        color[cur] = col;
        forn(i, link[cur].size()) {
            ll next = link[cur][i];
            if (color[next] == color[cur]) {
                is_planar = false;
            }
            if (color[next] == -1) {
                dfs(next, (col * 2) % 3);
            }
        }
    }
};

int main() {
    ifstream cin("planaritycheck.in");
    ofstream cout("planaritycheck.out");
    ios::sync_with_stdio(0);
    cin.tie(0);
    string num;
    getline(cin, num);
    ll t = stoll(num);
    ll n, m;
    forn(i, t) {
        string tmp;
        getline(cin, tmp);
        m = tmp.size();
        forn(y, tmp.size()) {
            if (tmp[y] == '0') {
                m--;
            }
        }
        n = sqrt(tmp.size() * 2) + 1;
        graph _(n, m);
        ll ind = 0;
        forn(u, n) {
            forn(v, u) {
                if (tmp[ind] == '1') {
                    _.edges.emplace_back(u, v);
                    _.matrix[u][v] = 1;
                    _.matrix[v][u] = 1;
                }
                ind++;
            }
        }
        forn(y, n) {
            _.ham_path[y] = y;
        }
        bool jjjj = false;
        do {
//            bool tr = false;
//            forna(y, 1, n) {
//                if (!_.matrix[_.ham_path[y - 1]][_.ham_path[y]]) {
//                    tr = true;
//                    break;
//                }
//            }
//            if (n > 2) {
//                if (!_.matrix[_.ham_path[n - 1]][_.ham_path[0]]) {
//                    tr = true;
//                    break;
//                }
//            }
//            if (tr) continue;

            forn(y, n) {
                _.in_ham[_.ham_path[y]] = y;
            }
            _.link.resize(m, vector<ll>());
            forn(i, m) {
                ll i_from = _.edges[i].from;
                ll i_to = _.edges[i].to;
                ll in_from = min(_.in_ham[i_from], _.in_ham[i_to]);
                ll in_to = max(_.in_ham[i_from], _.in_ham[i_to]);
                forn(j, m) {
                    ll j_from = _.edges[j].from;
                    ll j_to = _.edges[j].to;
                    ll jn_from = min(_.in_ham[j_from], _.in_ham[j_to]);
                    ll jn_to = max(_.in_ham[j_from], _.in_ham[j_to]);
                    if ((in_from > jn_from && in_from < jn_to && in_to > jn_to) ||
                        (jn_from > in_from && jn_from < in_to && jn_to > in_to)) {
                        _.link[i].push_back(j);
                        _.link[j].push_back(i);
                    }
                }
            }
            forn(p, m) {
                if (_.color[p] == -1) {
                    _.dfs(p, 1);
                }
                if (!_.is_planar) {
                    break;
                }
            }
            if (!_.is_planar) {
                forn(y, m) {
                    _.color[y] = -1;
                }
                _.is_planar = true;
                _.link.clear();
                continue;
            }
            jjjj = true;
            cout << "YES\n";
            break;
        } while (std::next_permutation(_.ham_path.begin(), _.ham_path.end()));
        if (!jjjj) {
            cout << "NO\n";
        }
    }
}