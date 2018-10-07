#include <iostream>
#include <unordered_map>
#include <queue>
#include <stack>
#define WIDTH 1000000001LL

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

int main() {
	int n;
	cin >> n;
	vector<P> ps(n);
	for(int i = 0; i < n; i++) {
		P p;
		cin >> p.first >> p.second;
		if(abs(p.first)>10||abs(p.second)>10) return 0;
		ps[i] = p;
	}

	bool ans_flag = ((abs(ps[0].first)+abs(ps[0].second))%2==0);
	int max_len = 0;
	for(P p : ps) {
		int _sum = (abs(p.first)+abs(p.second));
		if(ans_flag != (_sum%2)==0) {
			cout << -1 << endl;
			return 0;
		}
		max_len = max(max_len,_sum);
	}

	cout << max_len << endl;
	cout << 1;
	for(int i = 1; i < max_len; i++) cout << " 1";
	cout << endl;
	for(P p : ps) {
		int _sum = (abs(p.first)+abs(p.second));
		int now = max_len;
		while(_sum<now) {
			cout << "UD";
			now-=2;
		}
		for(int i = 0; i < abs(p.first); i++) {
			if(p.first>0) cout << "R";
			else cout << "L";
		}
		for(int i = 0; i < abs(p.second); i++) {
			if(p.second>0) cout << "U";
			else cout << "D";
		}
		cout << endl;
	}

	return 0;
}
