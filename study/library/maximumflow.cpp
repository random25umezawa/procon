#include <iostream>
#include <vector>
#include <unordered_map>
 
using namespace std;

typedef unordered_map<int,unordered_map<int,int>> double_map;
 
int dfs(double_map &g, int pos, int end, int flow, vector<bool> &arrived) {
    if(pos==end) return flow;
    arrived[pos] = true;
    for(pair<int,int> p : g[pos]) {
        int next = p.first;
        int capacity = p.second;
        if(!arrived[next]&&capacity>0) {
            int res = dfs(g,next,end,min(flow,capacity),arrived);
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

int max_flow(int v, double_map &g, int s, int e) {
    int ans = 0;
    while(true) {
        vector<bool> arrived(v);
        int flow = dfs(g,s,e,1<<30,arrived);
        if(flow<=0) break;
        else ans += flow;
    }
    return ans;
}
 
int main() {
    int v,e;
    cin >> v >> e;
    double_map g;
    for(int i = 0; i < e; i++) {
        int u,v2,c;
        cin >> u >> v2 >> c;
        g[u][v2] = c;
    }
    int ans = max_flow(v,g,0,v-1);
    cout << ans << endl;
}