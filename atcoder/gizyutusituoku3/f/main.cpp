#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

struct hsm{
	int i,h;
	ll w;
};

bool operator>(const hsm &a, const hsm &b) {
	return a.w>b.w;
}

int main() {
	int n;
	cin >> n;
	if(n>10) {
		cout << "もぅﾏﾁﾞ無理。" << endl;
		return 0;
	}
	int arr[10][2];
	ll w_sum = 0;
	for(int i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1];
		w_sum += arr[i][1];
	}

	ll ans = 0;
	priority_queue<hsm,vector<hsm>,greater<hsm> > q;
	queue<hsm> q2;
	for(int i = 0; i < n; i++) {
		q.push((hsm){i,arr[i][0],arr[i][0]*(w_sum-arr[i][1])});
	}
	ll h_sum = 0;
	while(w_sum>0) {
		hsm h = q.top();	q.pop();
		cout << h.i << "," << h.h << "," << h.w << endl;
		h_sum += h.h;
		ans += h.w;
		w_sum -= arr[h.i][1];
		int size = q.size();
		while(!q.empty()) {
			q2.push(q.top());
			q.pop();
		}
		while(!q2.empty()) {
			hsm h2 = q2.front();
			cout << h2.i << "," << h2.h << "," << h2.w << endl;
			h2.w = arr[h2.i][0]*(w_sum-arr[h2.i][1]);
			q.push(h2);
			q2.pop();
		}
		cout << "-----0-0-" << endl;
	}

	cout << ans << endl;
}
