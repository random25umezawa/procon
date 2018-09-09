#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge{
	int from,to,cost;
};

int n,m;
bool arrived[100000];
vector<edge> edges;
int range[100000][2];

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		int u,v,s;
		cin >> u >> v >> s;
		u--;	v--;
		edges.push_back((edge){u,v,s});
		edges.push_back((edge){v,u,s});
		edges.push_back((edge){u,v,s});
		edges.push_back((edge){v,u,s});
	}
	for(int i = 0; i < n; i++) {
		range[i][0] = 1<<31;
		range[i][1] = 1<<30;
	}
	for(edge _e : edges) {
		int from = _e.from;
		int to = _e.to;
		int cost = _e.cost;
		//cout << from << "->" << to << " " << cost << endl;
		if(range[from][0]==(1<<31)&&range[from][1]==(1<<30)) {
			range[from][0] = 1;
			range[from][1] = cost-1;
		}
		range[to][0] = max(range[to][0],cost-range[from][1]);
		range[to][1] = min(range[to][1],cost-range[from][0]);
		/*
		for(int i = 0; i < n; i++) {
			cout << i << " " << range[i][0] << "," << range[i][1] << endl;
		}
		*/
	}
	int ans = 1<<30;
	for(int i = 0; i < n; i++) {
		ans = min(ans,range[i][1]-range[i][0]+1);
	}
	cout << ((ans>0)?ans:0) << endl;
}
