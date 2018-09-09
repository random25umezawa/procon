#include <iostream>
#include <algorithm>
#include <unordered_map>
#define MOD 1000000007LL

using namespace std;

typedef long long ll;

int n;

unordered_map<int,int> nodes[5001];

ll conbinations[5001];

ll calc_pairs(int a) {
	return conbinations[a];
}

void calc(int pre, int now, int sum) {
	//cout << "called : " << pre << "," << now << "," << sum << endl;
	if(nodes[pre][now]!=-1) return;
	for(auto pair : nodes[now]) {
		if(pair.first!=pre) {
			calc(now,pair.first,0);
			sum += nodes[now][pair.first];
		}
	}
	sum++;
	//cout << "dp : " << pre << "," << now << "," << sum << endl;
	nodes[pre][now] = sum;
}

int main() {
	cin >> n;
	conbinations[2] = 1;
	for(int i = 4; i <= n; i+=2) {
		conbinations[i] = (conbinations[i-2]*(i-1)*i/2/(i/2))%MOD;
	}
	for(int i = 0; i < n; i++) {
		int x,y;
		cin >> x >> y;
		nodes[x][y] = -1;
		nodes[y][x] = -1;
	}
	unordered_map<int,bool> checked;
	ll ans = calc_pairs(n);
	//cout << ans << endl;
	for(int i = 1; i <= n; i++) {
		for(auto pair : nodes[i]) {
			int l = min(i,pair.first);
			int r = max(i,pair.first);
			int idx = l*5001+r;
			if(!checked[idx]) {
				checked[idx] = true;
				int size = -1;
				//cout << l << "," << r  << "," << nodes[l][r] << "," << nodes[r][l] << endl;
				if(nodes[l][r]==-1 && nodes[r][l]==-1) {
					calc(l,r, 0);
				}
				if(nodes[l][r]>=0) {
					size=nodes[l][r];
				}else if(nodes[r][l]>=0) {
					size=nodes[r][l];
				}
				//cout << l << "," << r  << "," << nodes[l][r] << "," << nodes[r][l] << endl;
				//cout << size << endl;
				if(size%2==0) {
					ans += MOD * MOD;
					ans -= calc_pairs(size) * calc_pairs(n-size);
					ans %= MOD;
				}
			}
		}
	}
	cout << ans << endl;
}
