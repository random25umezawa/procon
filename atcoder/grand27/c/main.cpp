#include <iostream>
#include <string>
#include <unordered_map>

typedef long long ll;

using namespace std;

int n,m;
string s;

unordered_map<int,bool> edges[100000];

bool arrived[100000]{};

void calc(int now, int pre, bool *loop_flag) {
	cout << now << "," << edges[now].size() << endl;
	if(arrived[now]) {
		*loop_flag |= !edges[now].empty();
		cout << "  " << edges[now].size() << " " << *loop_flag << endl;
		return;
	}
	arrived[now] = true;
	for(pair<int,bool> p : edges[now]) {
		int next = p.first;
		if(next==pre) continue;
		calc(next,now,loop_flag);
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
		int ab_bits = 0;
		for(pair<int,bool> p : edges[i]) {
			int next = p.first;
			if(s.at(next)=='A') ab_bits |= 0b01;
			if(s.at(next)=='B') ab_bits |= 0b10;
		}
		if(ab_bits!=0b11) {
			edges[i].clear();
		}
	}

	//
	for(int i = 0; i < n; i++) {
		if(!arrived[i]) {
			bool loop_flag = false;
			calc(i,-1,&loop_flag);
			cout << "loop_flag:" << loop_flag << endl;
			if(loop_flag) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}

	cout << "No" << endl;
	return 0;
}
