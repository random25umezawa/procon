#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
 
using namespace std; 

typedef unordered_map<int,unordered_map<int,int>> double_map;
 
int dfs(
    int now, int end, int flow, int *cost,
    vector<bool> &arrived, vector<int> &dp, double_map &g, double_map &costs
) {
    if(now==end||flow==0) return flow;
    arrived[now] = true;
    for(pair<int,int> p : costs[now]) {
        int next = p.first;
        int next_cost = p.second;
        if(arrived[next]) continue;
        if(dp[next]-dp[now]==next_cost) {
            int res = dfs(next,end,min(flow,g[now][next]),cost,arrived,dp,g,costs);
            if(res>0) {
                g[now][next] -= res;
                g[next][now] += res;
                costs[next][now] = -costs[now][next];
                if(g[now][next]==0) {
                    costs[now].erase(next);
                }
                *cost += res*next_cost;
                return res;
            }
        }
    }
    return 0;
}
 
void calc(int v, double_map &costs, vector<int> &dp, int s) {
    dp[s] = 0;
    vector<int> vf(v,1<<30);
    for(int loop = 0; loop < v; loop++) {
        for(int now = 0; now < v; now++) {
            if(dp[now]==1<<30) continue;
            vf[now] = min(vf[now],dp[now]);
            for(pair<int,int> p : costs[now]) {
                int next = p.first;
                int next_cost = p.second;
                vf[next] = min(vf[next],dp[now]+next_cost);
            }
        }
        dp.swap(vf);
    }
}

int min_cost_flow(int v, double_map &g, double_map &costs, int f, int s, int e) {
    int cost = 0;
    int ans = 0;
    while(ans<f) {
        vector<int> dp(v,1<<30);
        calc(v,costs,dp,s);
        vector<bool> arrived(v);
        int flow = dfs(s,e,f-ans,&cost,arrived,dp,g,costs);
        if(flow<=0) {
            return -1;   
        }
        else ans += flow;
    }
    return cost;
}
 
int main() {
    int v,e,f;
    double_map g,costs;
    cin >> v >> e >> f;
    for(int i = 0; i < e; i++) {
        int u,v2,c,d;
        cin >> u >> v2 >> c >> d;
        if(c<=0) continue;
        g[u][v2] = c;
        costs[u][v2] = d;
    }
    int cost = min_cost_flow(v,g,costs,f,0,v-1);
    cout << cost << endl;
}