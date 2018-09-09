#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int v,e,f;
unordered_map<int,unordered_map<int,int> > g,costs,inv_costs;
queue<pair<int,int> > nodes;
int cost = 0;

int dfs(int now, int flow, vector<bool> &arrived, vector<int> &dp) {
	cout << now << endl;
	if(now==0||flow==0) return flow;
	arrived[now] = true;
	for(pair<int,int> p : inv_costs[now]) {
		int next = p.first;
		int next_cost = p.second;
		if(arrived[next]) continue;
		if(dp[now]-dp[next]==next_cost) {
			int res = dfs(next,min(flow,g[next][now]),arrived,dp);
			if(res>0) {
				g[next][now] -= res;
				g[now][next] += res;
				costs[now][next] = -costs[next][now];
				inv_costs[next][now] = -inv_costs[now][next];
				if(g[next][now]==0) {
					//cout << now << "," << next << endl;
					costs[next].erase(now);
					inv_costs[now].erase(next);
				}
				cost += res*next_cost;
				return res;
			}
		}
	}
	return 0;
}

int calc(vector<int> &dp, int flow) {
	vector<int> vf(v,1<<30);
	for(int loop = 0; loop < v; loop++) {
		/*
		for(int i = 0; i < v; i++) {
			cout << dp[i] << ",";
		}
		cout << endl;
		*/
		for(int now = 0; now < v; now++) {
			if(dp[now]==1<<30) continue;
			vf[now] = min(vf[now],dp[now]);
			for(pair<int,int> p : costs[now]) {
				int next = p.first;
				int next_cost = p.second;
				//cout << now << "->" << next << " : " << dp[now] << "," << next_cost << endl;
				vf[next] = min(vf[next],dp[now]+next_cost);
			}
		}
		dp.swap(vf);
	}
	for(int i = 0; i < v; i++) {
		cout << dp[i] << ",";
		if(i%10==9) cout << endl;
	}
	cout << endl;

	vector<bool> arrived(v);
	return dfs(v-1,flow,arrived,dp);
}

int main() {
	cin >> v >> e >> f;
	for(int i = 0; i < e; i++) {
		int u,v2,c,d;
		cin >> u >> v2 >> c >> d;
		if(c<=0) continue;
		g[u][v2] = c;
		costs[u][v2] = d;
		inv_costs[v2][u] = d;
	}
	int ans = 0;
	while(ans<f) {
		vector<int> dp(v,1<<30);
		dp[0] = 0;
		int flow = calc(dp,f-ans);
		cout << flow << ":" << cost << endl;
		if(flow<=0) break;
		else ans += flow;
	}
	cout << ((ans>=f)?cost:-1) << endl;
}
