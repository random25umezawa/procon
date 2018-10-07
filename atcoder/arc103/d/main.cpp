#include <iostream>
#include <unordered_map>
#include <queue>
#include <stack>
#define WIDTH 1000000001LL

typedef long long ll;

using namespace std;

ll dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

struct Point{
	int x,y;
	bool operator<(const Point &r) const {
		int _a = x+y;
		int _b = r.x+r.y;
		if(_a!=_b) return _a < _b;
		else {
			_a = abs(x-y);
			_b = abs(r.x-r.y);
			return _a < _b;
		}
	}
};

int main() {
	int n;
	cin >> n;
	priority_queue<Point> q;
	for(int i = 0; i < n; i++) {
		Point p;
		cin >> p.x >> p.y;
		p.x = abs(p.x);
		p.y = abs(p.y);
		q.push(p);
	}

	Point p = q.top();	q.pop();
	int len = max(p.x,p.y);
	stack<int> arms;
	int arm_len = min(p.x,p.y);
	if(arm_len!=0) arms.push(arm_len);

	unordered_map<ll,bool> mp;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			ll x = len*dir[i][0]+arm_len*dir[j][0];
			ll y = len*dir[i][1]+arm_len*dir[j][1];
			mp[x*WIDTH+y] = true;
		}
	}

	bool noans_flag = false;

	while(!q.empty()) {
		p = q.top();	q.pop();
		cout << p.x << "," << p.y << "," << len << endl;
		if(mp[p.x*WIDTH+p.y]) continue;

		arm_len = p.x+p.y;

		if((len-arm_len)%2!=0) {
			noans_flag = true;
			break;
		}

		arm_len = len-max(p.x,p.y);

		arms.push(arm_len/2);
		len -= arm_len;

		unordered_map<ll,bool> temp_mp(mp.size());
		for(pair<ll,bool> p : mp) {
			for(int i = 0; i < 4; i++) {
				ll x = (p.first/WIDTH)+arm_len*dir[i][0];
				ll y = (p.first%WIDTH)+arm_len*dir[i][1];
				temp_mp[x*WIDTH+y] = true;
			}
		}

		for(pair<ll,bool> p : temp_mp) {
				ll x = (p.first/WIDTH);
				ll y = (p.first%WIDTH);
				cout << x << "," << y << endl;
		}

		mp.swap(temp_mp);
	}

	arms.push(len);

	if(noans_flag) {
		cout << -1 << endl;
		return 0;
	}

	return 0;
}
