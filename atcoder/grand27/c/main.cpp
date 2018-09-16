#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

typedef long long ll;

using namespace std;

int n,m;
string s;

unordered_map<int,bool> edges[200000];

void del_edge(int now) {
	//if(edges[now].empty()) return;
	int ab_bits = 0;
	for(pair<int,bool> p : edges[now]) {
		int next = p.first;
		if(s.at(next)=='A') ab_bits |= 0b01;
		if(s.at(next)=='B') ab_bits |= 0b10;
	}
	if(ab_bits!=0b11) {
		vector<int> q;
		for(pair<int,bool> p : edges[now]) {
			int next = p.first;
		}
		for(pair<int,bool> p : edges[now]) {
			int next = p.first;
			q.push_back(next);
		}
		for(int next : q) {
			edges[next].erase(now);
		}
		edges[now].clear();
		for(int next : q) {
			del_edge(next);
		}
	}
}

int main() {
	cin >> n >> m >> s;
	for(int i = 0; i < m; i++) {
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		edges[a][b] = true;
		edges[b][a] = true;
	}

	//
	for(int i = 0; i < n; i++) {
		del_edge(i);
	}

	//
	for(int i = 0; i < n; i++) {
		if(!edges[i].empty()) {
			cout << "Yes" << endl;
			return 0;
		}
	}

	cout << "No" << endl;

	return 0;
}
