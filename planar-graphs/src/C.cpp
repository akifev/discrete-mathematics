#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <cfloat>
#include <set>

using namespace std;
typedef long long ll;
typedef long double ld;
#define forn(i, n) for (ll i = 0; i < n; i++)
#define forna(i, a, n) for (ll i = a; i < n; i++)
const ld EPS = 1e-9;

struct ed {
    bool was;
    ll next, chetvert, id;
    ld tg;

    ed() = default;

    ed(ld _tg, pair<pair<ld, ld>, ll> v1, pair<pair<ld, ld>, ll> v2, ll _id) : was(false), next(v2.second),
                                                                               tg(_tg), id(_id) {
        if (v1.first.second < v2.first.second) {
            chetvert = (v1.first.first <= v2.first.first ? 1 : 2);
        } else if (v1.first.second > v2.first.second) {
            chetvert = (v1.first.first >= v2.first.first ? 3 : 4);
        } else {
            chetvert = (v1.first.first < v2.first.first ? 1 : 3);
        }
    }
};

struct ver {
    ld x, y;
    vector<ed> ways;
};
vector<pair<pair<ll, ll>, ll>> edges;

void update(vector<ed> &_new, ll ind_grani) {
    for (auto &e : _new) {
        ll e_ind = e.id;
        if (edges[e_ind].first.first == 1e18 || edges[e_ind].first.second == 1e18)
            if (edges[e_ind].first.first == 1e18)
                edges[e_ind].first.first = ind_grani;
            else
                edges[e_ind].first.second = ind_grani;
    }
}

bool check(vector<vector<ed>> &graph, ll i, ll s, ll t) {
    bool is_here_s = false, is_here_t = false;
    ll pos_s, pos_t;
    forn(j, graph[i].size()) {
        ed &e = graph[i][j];
        if (e.next == s) {
            is_here_s = true;
            pos_s = j;
        }
        if (e.next == t) {
            is_here_t = true;
            pos_t = j;
        }
    }
    if (is_here_s && is_here_t) {
        ll new_cnt = (pos_t > pos_s ? pos_t - pos_s : pos_t + graph[i].size() - pos_s);
        set<ll> in_new_id;
        vector<ed> _new(new_cnt); // t
        vector<ed> _new2; // s
        for (auto &e : graph[i]) {
            ll e_ind = e.id;
            if (edges[e_ind].first.first == i) {
                edges[e_ind].first.first = 1e18;
            } else {
                edges[e_ind].first.second = 1e18;
            }
        }
        forn(j, new_cnt) {
            ll pos = (pos_t - j + graph[i].size()) % graph[i].size();
            _new[j] = graph[i][pos];
            in_new_id.insert(graph[i][pos].id);
        }
        forn(j, graph[i].size()) {
            if (!in_new_id.count(graph[i][j].id)) {
                _new2.push_back(graph[i][j]);
            }
        }
        graph.push_back(_new); // t
        update(_new, graph.size() - 1);
        graph.push_back(_new2); // s
        update(_new2, graph.size() - 1);
        update(_new, graph.size() - 1);
        update(_new2, graph.size() - 2);
        return true;
    }
    return false;
}

vector<ver> g;
map<pair<ld, ld>, ll> num_of_way;

void obhod(ll u, ed &e, vector<ed> &ivec) {
    ivec.push_back(e);
    e.was = true;
    ed &rebro = g[e.next].ways[(num_of_way[{e.next, u}] - 1 + g[e.next].ways.size()) % g[e.next].ways.size()];
    if (!rebro.was)
        obhod(e.next, rebro, ivec);
}

int main() {
    cout.sync_with_stdio(0);
    cin.tie(0);
    ll n, m, s, t;
    cin >> n >> m >> s >> t;
    s--;
    t--;
    ll cnt = n;
    g.resize(cnt);
    forn(i, cnt) {
        cin >> g[i].x >> g[i].y;
    }
    ll max_w = 0;
    edges.resize(m);
    forn(i, m) {
        ll from, to, w;
        cin >> from >> to >> w;
        if (max_w < w) {
            max_w = w;
        }
        from--;
        to--;
        edges[i] = {{1e18, 1e18}, w};
        ld x1 = g[from].x, y1 = g[from].y;
        ld x2 = g[to].x, y2 = g[to].y;
        ld tg = (fabs(x1 - x2) < EPS ? 1e9 : (ld) (y1 - y2) / (ld) (x1 - x2));
        g[from].ways.emplace_back(tg, make_pair(make_pair(x1, y1), from), make_pair(make_pair(x2, y2), to), i);
        g[to].ways.emplace_back(tg, make_pair(make_pair(x2, y2), to), make_pair(make_pair(x1, y1), from), i);
    }
    if (cnt <= 2) {
        cout << max_w;
        return 0;
    }
    forn(i, cnt) {
        sort(g[i].ways.begin(), g[i].ways.end(), [](ed a, ed b) {
            return (a.chetvert < b.chetvert) || (a.chetvert == b.chetvert && a.tg < b.tg);
        });
    }
    forn(i, cnt) {
        forn(j, g[i].ways.size()) {
            num_of_way.insert({{i, g[i].ways[j].next}, j});
        }
    }
    vector<vector<ed>> graph;
    forn(i, cnt) {
        for (auto edge : g[i].ways) {
            if (!edge.was) {
                vector<ed> ivec;
                obhod(i, edge, ivec);
                ivec.erase(ivec.begin() + ivec.size() - 1);
                update(ivec, graph.size());
                graph.emplace_back(ivec);
            }
        }
    }
    forn(i, graph.size()) {
        if (check(graph, i, s, t)) break;
    }
    ll count = graph.size();
    vector<vector<pair<ll, ll>>> link(count);
    forn(i, m) {
        link[edges[i].first.first].emplace_back(edges[i].first.second, edges[i].second);
        link[edges[i].first.second].emplace_back(edges[i].first.first, edges[i].second);
    }
    vector<ll> ans(count, 1e18);
    set<pair<ll, ll>> _set;
    ll cur = count - 1;
    ans[cur] = 0;
    _set.emplace(ans[cur], cur);
    while (!_set.empty()) {
        cur = _set.begin()->second;
        _set.erase(make_pair(ans[cur], cur));
        for (auto next: link[cur]) {
            if (ans[next.first] > ans[cur] + next.second) {
                if (_set.count(make_pair(ans[next.first], next.first))) {
                    _set.erase(make_pair(ans[next.first], next.first));
                }
                _set.insert(make_pair(ans[cur] + next.second, next.first));
                ans[next.first] = ans[cur] + next.second;
            }
        }
    }
    cout << ans[count - 2];
}