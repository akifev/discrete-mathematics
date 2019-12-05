//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <set>
//#include <queue>
//#include <map>
//#include <cmath>
//#include <string>
//#include <fstream>
//#include <stack>
//
//using namespace std;
//typedef long long ll;
//#define forn(i, n) for (ll i = 0; i < n; i++)
//#define forna(i, a, n) for (ll i = a; i < n; i++)
//
//const long double INF = 2e18;
//
//enum side {
//    LEFT, RIGHT, CENTER, NONE
//};
//
//struct ed {
//    ll from, to;
//    bool is_draw;
//    side side_edge;
//
//    ed() = default;
//
//    ed(ll a, ll b, bool c, side d) : from(a), to(b), is_draw(c), side_edge(d) {};
//};
//
//struct graph {
//    ll n;
//    ll m;
//    vector<ed> edges; // список рёбер {from, to, is_planar, side_edge}
//    vector<ll> ham_path; // гамильтонов путь
//
//    graph(ll n, ll m) {
//        this->n = n;
//        this->m = m;
//        edges.resize(m);
//        ham_path.resize(n);
//    }
//
//    void read_edges() {
//        forn(i, m) {
//            ll from, to;
//            cin >> from >> to;
//            edges[i] = {min(from, to) - 1, max(to, from) - 1, false, RIGHT};
//        }
//    }
//
//    void read_ham() {
//        forn(i, n) {
//            cin >> ham_path[i];
//            ham_path[i]--;
//        }
//        forna(i, 1, n) {
//            ll f = min(ham_path[i - 1], ham_path[i]);
//            ll t = max(ham_path[i - 1], ham_path[i]);
//            forn(j, m) {
//                if (edges[j].from == f && edges[j].to == t) {
//                    edges[j].is_draw = true;
//                    edges[j].side_edge = CENTER;
//                }
//            }
//        }
//    }
//};
//
//struct point {
//    long double x;
//    long double y;
//
//    point() = default;
//
//    point(long double a, long double b) : x(a), y(b) {};
//};
//
//int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    ll n, m;
//    cin >> n >> m;
//    graph _ = graph(n, m);
//    _.read_edges();
//    _.read_ham();
//    ll cur = 0;
//    for (auto e : _.edges) {
//        if (!e.is_draw) {
//            if (e.from == _.ham_path[cur] || e.to == _.ham_path[cur]) {
//                ll next = (e.from == _.ham_path[cur] ? e.to : e.from);
//                ll next_ind = 0;
//                forn(i, n){
//                    if(_.ham_path[i] == next){
//                        next_ind = i;
//                        break;
//                    }
//                }
//                _.dfs(cur, next_ind){
//
//                }
//            }
//        }
//    }
//
//    cout << "YES\n";
//    vector<point> position(n);
//    long double xx = 0.0, yy = 0.0;
//    forn(i, n) {
//        position[_.ham_path[i]] = point(xx, yy);
//        yy -= 1.0;
//    }
//    forn(i, n) {
//        cout << position[i].x << ' ' << position[i].y << ' ';
//    }
//    cout << endl;
//    for (auto e : _.edges) {
//        long double y = (position[e.from].y + position[e.to].y) / 2;
//        long double x = fabs(y - position[e.from].y);
//        if (e.side_edge == LEFT) {
//            x = -x;
//        } else if (e.side_edge == CENTER) {
//            x = 0.0;
//        }
//        cout.precision(10);
//        cout << x << ' ' << y << endl;
//    }
//}
//
//
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

using namespace std;
typedef long long ll;
#define forn(i, n) for (ll i = 0; i < n; i++)
#define forna(i, a, n) for (ll i = a; i < n; i++)

const long double INF = 2e18;

enum side {
    LEFT, RIGHT, CENTER, NONE
};

struct ed {
    ll from, to;
    bool is_plane;
    side side_edge;

    ed() = default;

    ed(ll a, ll b, bool c, side d) : from(a), to(b), is_plane(c), side_edge(d) {};
};

struct segm {
    ed *link;
    ll cnt;
    ll gran_ind;

    segm() = default;

    segm(ed *e, ll c, ll g) : link(e), cnt(c), gran_ind(g) {};
};

struct graph {
    ll n;
    ll m;
    vector<set<ll>> vertex; // в какую группу входит вершина
    vector<ed> edges; // список рёбер {from, to, is_planar, side_edge}
    vector<ll> ham_path; // гамильтонов путь
    vector<segm> segments; // указатели на рёбра-сегментнты и их числа
    ll gran_cnt; // количество граней
    vector<side> gran_side;
    bool is_planar; // планарен ли

    graph(ll n, ll m) {
        this->n = n;
        this->m = m;
        vertex.resize(n);
        edges.resize(m);
        ham_path.resize(n);
        is_planar = true;
        gran_cnt = 0;
    }

    void read_edges() {
        forn(i, m) {
            ll from, to;
            cin >> from >> to;
            from--;
            to--;
            edges[i] = {min(from, to), max(from, to), false, NONE};
        }
    }

    void init_edge(ll ind, side side1) {
        ll f = min(ham_path[ind - 1], ham_path[ind % n]);
        ll t = max(ham_path[ind - 1], ham_path[ind % n]);
        forn(j, m) {
            if (edges[j].from == f && edges[j].to == t) {
                edges[j].is_plane = true;
                edges[j].side_edge = side1;
            }
        }
    }

    void read_ham() {
        vector<pair<ll, ll>> edg;
        forn(i, n) {
            cin >> ham_path[i];
            ham_path[i]--;
            vertex[ham_path[i]].insert(0);
            vertex[ham_path[i]].insert(1);
        }
        forna(i, 1, n) {
            init_edge(i, CENTER);
        }
        if (n > 2) {
            init_edge(n, RIGHT);
        }
        gran_cnt = 2;
        gran_side.resize(gran_cnt);
        gran_side[0] = LEFT;
        gran_side[1] = RIGHT;
    }

    void update_grani(segm *segment) {
        ll from = segment->link->from;
        ll to = segment->link->to;
        ll start = 0;
        for (; start < n; start++) {
            if (ham_path[start] == from) {
                break;
            }
        }
        gran_cnt++;
        gran_side.emplace_back(segment->link->side_edge);
        vertex[ham_path[start]].insert(gran_cnt - 1);
        start++;
        ll end = start;
        for (; end < n; end++) {
            if (ham_path[end] == to) {
                break;
            }
        }
        vertex[ham_path[end]].insert(gran_cnt - 1);
        forna(i, start, end) {
            vertex[ham_path[i]].insert(gran_cnt - 1);
            vertex[ham_path[i]].erase(segment->gran_ind);
        }
    }

    void add_segm(segm *segment) {
        segment->link->is_plane = true;
        segment->link->side_edge = gran_side[segment->gran_ind];
        update_grani(segment);
    }

    segm *min_segments() {
        segments.clear();
        forn(i, m) {
            if (!edges[i].is_plane) {
                segments.emplace_back(&edges[i], 0, 0);
            }
        }

        ll index = 0;
        ll ans_count = INF;
        ll size_way = INF;
        ll gran = 0;
        forn(i, segments.size()) {
            ll from = segments[i].link->from;
            ll to = segments[i].link->to;
            set<ll> ans;
            for (auto it = vertex[from].begin(); it != vertex[from].end(); it++) {
                if (vertex[to].count(*it)) {
                    ans.insert(*it);
                }
            }
            ll count = ans.size();
            ll gran = *(ans.begin());
            if (count == 0) {
                is_planar = false;
            }
            segments[i].cnt = count;
            segments[i].gran_ind = gran;


            ll ind_from = INF, ind_to = INF;
            forn(i, n) {
                if (ham_path[i] == from) {
                    ind_from = i;
                }
                if (ham_path[i] == to) {
                    ind_to = i;
                }
            }

            if (count < ans_count) {
                index = i;
                ans_count = count;
                size_way = fabs(ind_to - ind_from);
            } else if (count == ans_count && size_way < fabs(ind_to - ind_from)) {
                index = i;
                ans_count = count;
                size_way = fabs(ind_to - ind_from);
            }
        }
        return &segments[index];
    }
};

struct point {
    long double x;
    long double y;

    point() = default;

    point(long double a, long double b) : x(a), y(b) {};
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    graph _ = graph(n, m);
    _.read_edges();
    _.read_ham();
    while (_.is_planar) {
        segm *segment = _.min_segments();
        if (!_.is_planar || _.segments.empty()) {
            if (!_.is_planar)
                cout << "NO";
            else
                break;
            return 0;
        }
        _.add_segm(segment);
    }
    cout << "YES\n";
    vector<point> position(n);
    long double xx = 0.0, yy = 0.0;
    forn(i, n) {
        position[_.ham_path[i]] = point(xx, yy);
        yy += 2.0;
    }
    forn(i, n) {
        cout << position[i].y << ' ' << position[i].x << ' ';
    }
    cout << endl;
    for (auto e : _.edges) {
        long double y = (position[e.from].y + position[e.to].y) / 2;
        long double x = fabs(y - position[e.from].y);
        if (e.side_edge == LEFT) {
            x = -x;
        } else if (e.side_edge == CENTER) {
            x = 0.0;
        }
        cout.precision(10);
        cout << y << ' ' << x << endl;
    }
}