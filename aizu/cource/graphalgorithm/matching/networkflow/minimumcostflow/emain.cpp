#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int v,e,f;
unordered_map<int,unordered_map<int,int> > g,costs;
queue<pair<int,int> > nodes;
int cost = 0;

int dfs(int now, int flow, vector<bool> &arrived, vector<int> &dp) {
	if(now==0||flow==0) return flow;
	arrived[now] = true;
	for(pair<int,int> p : costs[now]) {
		int next = p.first;
		int next_cost = p.second;
		if(arrived[next]) continue;
		if(dp[now]-dp[next]==next_cost) {
			int res = dfs(next,min(flow,g[next][now]),arrived,dp);
			if(res>0) {
				g[next][now] -= res;
				g[now][next] += res;
				costs[now][next] = -costs[next][now];
				if(g[next][now]==0) {
					costs[next].erase(now);
				}
				cost += res*next_cost;
				return res;
			}
		}
	}
	return 0;
}

int calc(vector<bool> &arrived, vector<int> &dp, int flow) {
	while(!nodes.empty()) {
		for(int i = 0; i < v; i++) {
			cout << dp[i] << ",";
		}
		cout << endl;
		int s = nodes.size();
		while(true) {
			if(s==0) break;	s--;
			pair<int,int> now_pair = nodes.front();	nodes.pop();
			arrived[now_pair.first] = true;
			now_pair.second = dp[now_pair.first];
			nodes.push(now_pair);
		}
		s = nodes.size();
		while(true) {
			if(s==0) break;	s--;
			pair<int,int> now_pair = nodes.front();	nodes.pop();
			int now = now_pair.first;
			int node_cost = now_pair.second;
			arrived[now] = true;
			for(pair<int,int> p : costs[now]) {
				int next = p.first;
				int next_cost = p.second;
				dp[next] = min(dp[next],next_cost+node_cost);
				if(!arrived[next]) {
					pair<int,int> new_pair(next,0);
					arrived[next] = true;
					nodes.push(new_pair);
				}
			}
		}
	}
	for(int i = 0; i < v; i++) {
		cout << dp[i] << ",";
	}
	cout << endl;

	fill(arrived.begin(),arrived.end(),false);
	return dfs(v-1,flow,arrived,dp);
}

int main() {
	cin >> v >> e >> f;
	for(int i = 0; i < e; i++) {
		int u,v2,c,d;
		cin >> u >> v2 >> c >> d;
		g[u][v2] = c;
		costs[u][v2] = d;
	}
	int ans = 0;
	while(ans<f) {
		vector<bool> arrived(v);
		vector<int> dp(v);
		fill(dp.begin()+1,dp.end(),1<<30);
		pair<int,int> start(0,0);
		nodes.push(start);
		int flow = calc(arrived,dp,f-ans);
		cout << flow << ":" << cost << endl;
		if(flow<=0) break;
		else ans += flow;
	}
	cout << ((ans>=f)?cost:-1) << endl;
}
