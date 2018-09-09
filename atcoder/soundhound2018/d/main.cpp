#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

struct edge{
	int a,b;
	ll c;
};

bool operator > (const edge &e1,const edge &e2){
	return (e1.c!=e2.c)?(e1.c>e2.c):(e1.a+200000+e1.b>e2.a+200000+e2.b);
}

int n,m,s,t;
unordered_map<int,int> edges[2][100000];

int main() {
	cin >> n >> m >> s >> t;
	s--; t--;
	for(int i = 0; i < m; i++) {
		int u,v,a,b;
		cin >> u >> v >> a >> b;
		u--; v--;
		edges[0][u][v] = a;
		edges[0][v][u] = a;
		edges[1][u][v] = b;
		edges[1][v][u] = b;
	}
	unordered_map<int,bool> arrived[2];
	unordered_map<int,ll> dp[2];
	priority_queue<edge,vector<edge>,greater<edge> > q[2];
	{
		for(auto itr = edges[0][s].begin(); itr != edges[0][s].end(); itr++) {
			q[0].push((edge){s,itr->first,itr->second});
		}
		arrived[0][s] = true;
		dp[0][s] = 0;
		while(!q[0].empty()) {
			edge _e = q[0].top(); q[0].pop();
			if(arrived[0][_e.b]) continue;
			arrived[0][_e.b] = true;
			dp[0][_e.b] = dp[0][_e.a]+edges[0][_e.a][_e.b];
			for(auto itr = edges[0][_e.b].begin(); itr != edges[0][_e.b].end(); itr++) {
				if(!arrived[0][itr->first]) q[0].push((edge){_e.b,itr->first,itr->second+dp[0][_e.b]});
			}
		}
	}
	{
		for(auto itr = edges[1][t].begin(); itr != edges[1][t].end(); itr++) {
			q[1].push((edge){t,itr->first,itr->second});
		}
		arrived[1][t] = true;
		dp[1][t] = 0;
		while(!q[1].empty()) {
			edge _e = q[1].top(); q[1].pop();
			if(arrived[1][_e.b]) continue;
			arrived[1][_e.b] = true;
			dp[1][_e.b] = dp[1][_e.a]+edges[1][_e.a][_e.b];
			for(auto itr = edges[1][_e.b].begin(); itr != edges[1][_e.b].end(); itr++) {
				if(!arrived[1][itr->first]) q[1].push((edge){_e.b,itr->first,itr->second+dp[1][_e.b]});
			}
		}
	}
	/*
	for(int i = 0; i < n; i++) {
		cout << dp[0][i] << " " << dp[1][i] << endl;
	}
	*/
	ll ans[100000];
	ans[n-1] = (dp[0][n-1]+dp[1][n-1]);
	for(int i = n-2; i >= 0; i--) {
		ans[i] = min(ans[i+1],(dp[0][i]+dp[1][i]));
	}
	for(int i = 0; i < n; i++) {
		cout << 1000000000000000LL-(ans[i]) << endl;
	}
}
