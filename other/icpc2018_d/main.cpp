#include <iostream>
#include <stdio.h>
#include <queue>
#include <unordered_map>

using namespace std;

typedef long long ll;
int n,m;
long half;
bool fighted[9][9]{};

queue<ll> q;

void add_all(ll bit, ll me, ll team) {
	ll win = (bit>>(me*6+3))&0b111LL;
	ll lose = (bit>>(me*6))&0b111LL;
	if(win>half||lose>half) return;
	if(win==half&&lose==half) {
		q.push(bit);
		return;
	}
	if(fighted[me][team]) {
		add_all(bit,me,team+1);
		return;
	}
	if(win<half) {
		ll t_lose = (bit>>(team*6))&0b111LL;
		if(t_lose<half) {
			add_all(bit+(1LL<<(team*6))+(1LL<<(me*6+3)),me,team+1);
		}
	}
	if(lose<half) {
		ll t_win = (bit>>(team*6+3))&0b111LL;
		if(t_win<half) {
			add_all(bit+(1LL<<(team*6+3))+(1LL<<(me*6)),me,team+1);
		}
	}
}

int main() {
	while(true) {
		cin >> n >> m;
		if(n<=0) break;
		half = n/2;
		ll start = 0;
		for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) fighted[i][j] = false;
		for(int i = 0; i < m; i++) {
			int x,y;
			cin >> x >> y;
			x--;	y--;
			fighted[x][y] = true;
			fighted[y][x] = true;
			start += (1LL<<(x*6+3));
			start += (1LL<<(y*6));
		}

		queue<ll> _q;
		swap(q,_q);

		q.push(start);
		ll ans = 0;
		ll team = 0;
		while(team<n) {
			int size = q.size();
			for(int i = 0; i < size; i++) {
				ll bit = q.front(); q.pop();
				ll win = (bit>>(team*6+3))&0b111LL;
				ll lose = (bit>>(team*6))&0b111LL;
				if(win<=half&&lose<=half) add_all(bit,team,team+1);
			}
			team++;
		}
		cout << q.size() << endl;
	}
}
