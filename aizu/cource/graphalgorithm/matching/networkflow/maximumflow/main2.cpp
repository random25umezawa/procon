#include <iostream>
#include <unordered_map>

using namespace std;

int v,e;
unordered_map<int,unordered_map<int,int> > g;

int dfs(int pos, int flow, unordered_map<int,bool> &arrived) {
	if(pos==v-1) return flow;
	arrived[pos] = true;
	for(pair<int,int> p : g[pos]) {
		int next = p.first;
		int capacity = p.second;
		if(!arrived[next]&&capacity>0) {
			int res = dfs(next,min(flow,capacity),arrived);
			if(res>0) {
				g[pos][next] -= res;
				g[next][pos] += res;
				if(g[pos][next]<=0) g[pos].erase(next);
				return res;
			}
		}
	}
	return 0;
}

int main() {
	cin >> v >> e;
	for(int i = 0; i < e; i++) {
		int u,v2,c;
		cin >> u >> v2 >> c;
		g[u][v2] = c;
	}
	int ans = 0;
	while(true) {
		unordered_map<int,bool> arrived(v);
		int flow = dfs(0,1<<30,arrived);
		if(flow<=0) break;
		else ans += flow;
	}
	cout << ans << endl;
}
