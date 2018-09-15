#include <iostream>
#include <string>
#include <unordered_map>

typedef long long ll;

using namespace std;

int n,m;
string s;

unordered_map<int,bool> edges[100000];

bool ab_flags[100000]{};

bool arrived[100000]{};

void calc(int now, bool *flag) {
	if(arrived[now]) return;
	cout << now << "," << ab_flags[now] <<endl;
	arrived[now] = true;
	*flag = ab_flags[now];
	for(pair<int,bool> p : edges[now]) {
		int next = p.first;
		calc(next,flag);
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
		cout << i << endl;
		for(pair<int,bool> p : edges[i]) {
			int next = p.first;
			if(s.at(next)=='A') ab_bits |= 0b01;
			if(s.at(next)=='B') ab_bits |= 0b10;
			cout << next << ":" << s.at(next) << endl;
		}
		cout << endl << ab_bits << endl;
		ab_flags[i] = (ab_bits==0b11);
	}

	//
	for(int i = 0; i < n; i++) {
		if(!arrived[i]) {
			bool flag = true;
			calc(i,&flag);
			cout << "flag:" << flag << endl;
			if(flag) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}

	cout << "No" << endl;

	return 0;
}
