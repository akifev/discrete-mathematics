#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <ctime>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <fstream>
using namespace std;
struct state {
	int me;
	bool is_term;
	unordered_map<char, state*> transitions;
	unordered_map<char, unordered_set<state*>> reverse_transitions;
	state() : me(-1), is_term(false) {}
	state(int my_number, bool is_term) : me(my_number), is_term(is_term) {}
};
struct dfa {
	unordered_map<int, state*>states;
	unordered_map<int, state*>term;
	dfa() {}
	dfa(int count) {
		for (int i = 0; i < count; i++) {
			state *tmp = new state(i, false);
			states.insert(make_pair(i, tmp));
		}
	}
};
void way_to_term(dfa &kalash, vector<bool> &have_way, int cur) {
	have_way[cur] = true;
	for (auto next_kit : kalash.states.at(cur)->reverse_transitions) {
		for (auto next : next_kit.second) {
			if (!have_way[next->me])
				way_to_term(kalash, have_way, next->me);
		}
	}
}
void way_to_start(dfa &kalash, vector<bool> &have_way, int cur) {
	have_way[cur] = true;
	for (auto next_pair : kalash.states.at(cur)->transitions) {
		auto next = next_pair.second;
		if (next->me != -1 && !have_way[next->me])
			way_to_start(kalash, have_way, next->me);
	}
}
int main() {
	ifstream cin("fastminimization.in");
	ofstream cout("fastminimization.out");
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	dfa kalash(n);
	for (int i = 0; i < k; i++) {
		int tmp;
		cin >> tmp;
		tmp--;
		kalash.states.at(tmp)->is_term = true;
		kalash.term.insert(make_pair(tmp, kalash.states.at(tmp)));
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		char c;
		cin >> a >> b >> c;
		a--;
		b--;
		kalash.states.at(a)->transitions.insert(make_pair(c, kalash.states.at(b)));
		if (kalash.states.at(b)->reverse_transitions.count(c) > 0)
			kalash.states.at(b)->reverse_transitions.at(c).insert(kalash.states.at(a));
		else {
			unordered_set<state*>temporary;
			temporary.insert(kalash.states.at(a));
			kalash.states.at(b)->reverse_transitions.insert(make_pair(c, temporary));
		}
	}
	vector<bool>have_way_to_start(kalash.states.size(), false);
	way_to_start(kalash, have_way_to_start, 0);
	for (int i = 0; i < have_way_to_start.size(); i++) {
		if (!have_way_to_start[i]) {
			if (kalash.states.at(i)->is_term)
				kalash.term.erase(kalash.term.find(i));
			kalash.states.erase(kalash.states.find(i));
		}
	}
	vector<bool>have_way_to_term(kalash.states.size(), false);
	for (auto term_st : kalash.term) {
		way_to_term(kalash, have_way_to_term, term_st.first);
	}
	for (int i = 0; i < have_way_to_term.size(); i++) {
		if (!have_way_to_term[i])
			kalash.states.erase(kalash.states.find(i));
	}
	vector<vector<unordered_map<int, state*>>>qwe(kalash.states.size(), vector<unordered_map<int, state*>>(26));
	for (auto st : kalash.states) {
		for (auto jopa : st.second->transitions) {
			if (jopa.second->me != -1)
				qwe[jopa.second->me][int(jopa.first - 'a')].insert(make_pair(st.first, kalash.states.at(st.first)));
		}
	}
	unordered_map<int, state*>qwerty = kalash.states;
	unordered_map<int, state*>asdfg = kalash.term;
	unordered_map<int, state*>zxcvb;
	for (auto st : kalash.states) {
		if (!st.second->is_term)
			zxcvb.insert(make_pair(st.second->me, st.second));
	}
	vector<unordered_map<int, state*>>poiuy;
	poiuy.push_back(asdfg);
	if (!zxcvb.empty())
		poiuy.push_back(zxcvb);
	queue<pair<unordered_map<int, state*>, char>>lkjhg;
	for (char c = 'a'; c <= 'z'; c++) {
		lkjhg.push(make_pair(asdfg, c));
		if (!zxcvb.empty())
			lkjhg.push(make_pair(zxcvb, c));
	}
	vector<int>mnbvc(kalash.states.size());
	for (auto st : kalash.states) {
		int index = 0;
		for (auto kit : poiuy) {
			if (kit.count(st.first) > 0) {
				mnbvc[st.first] = index;
				break;
			}
			index++;
		}
	}
	while (!lkjhg.empty()) {
		unordered_map<int, state*>C = lkjhg.front().first;
		char a = lkjhg.front().second;
		lkjhg.pop();
		vector<vector<int>>asdfjkl;
		for (auto q : C) {
			for (auto r : qwe[q.first][int(a - 'a')]) {
				int i = mnbvc[r.first];
				if (asdfjkl.size() <= i) {
					asdfjkl.resize(i + 1);
				}
				asdfjkl[i].push_back(r.first);
			}
			for (int i = 0; i < asdfjkl.size(); i++) {
				if (asdfjkl[i].size() < poiuy[i].size()) {
					poiuy.resize(poiuy.size() + 1);
					int j = poiuy.size() - 1;
					for (auto r : asdfjkl[i]) {
						poiuy[i].erase(poiuy[i].find(r));
						poiuy[j].insert(make_pair(r, kalash.states.at(r)));
					}
					/*if (poiuy[j].size() > poiuy[i].size())
						swap(poiuy[i], poiuy[j]);*/
					for (auto r : poiuy[j]) {
						mnbvc[r.first] = j;
					}
					unordered_map<int, state*>temporary;
					temporary.insert(make_pair(j, kalash.states.at(j)));
					for (char c = 'a'; c <= 'z'; c++) {
						lkjhg.push(make_pair(temporary, c));
					}
				}
			}
		}
	}
	vector<bool>is_term(poiuy.size(), false);
	int start = mnbvc[0];
	vector<vector<unordered_set<char>>>trans(poiuy.size(), vector<unordered_set<char>>(poiuy.size()));
	for (auto st : poiuy[start]) {
		if (st.second->is_term)
			is_term[start] = true;
		for (char c = 'a'; c <= 'z'; c++)
			if (st.second->transitions.count(c) > 0)
				trans[start][mnbvc[st.first]].insert(c);
	}
	for (int i = 0; i < poiuy.size(); i++)
		if (i != start)
			for (auto st : poiuy[i]) {
				if (st.second->is_term)
					is_term[i] = true;
				for (char c = 'a'; c <= 'z'; c++)
					if (st.second->transitions.at(c)->me != -1)
						trans[i][mnbvc[st.first]].insert(c);
			}

	int cnt_term = 0, cnt_f = 0;
	for (int i = 0; i < is_term.size(); i++)
		if (is_term[i])
			cnt_term++;
	for (int i = 0; i < trans.size(); i++)
		for (int j = 0; j < trans[i].size(); j++)
			cnt_f += trans[i][j].size();
	cout << poiuy.size() << ' ' << cnt_f << ' ' << cnt_term << endl;
	for (int i = 0; i < is_term.size(); i++)
		if (is_term[i])
			cout << (i < start ? i + 2 : (i == start ? 1 : i + 1)) << ' ';
	cout << endl;
	for (int i = 0; i < trans.size(); i++)
		for (int j = 0; j < trans[i].size(); j++) {
			int h = (i < start ? i + 2 : (i == start ? 1 : i + 1));
			int o = (j < start ? j + 2 : (j == start ? 1 : j + 1));
			for (auto c : trans[i][j])
				cout << h << ' ' << o << ' ' << c << endl;
		}
}