#include <iostream>
#include <unordered_map>
 
using namespace std;
 
int v;
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
    int n,k;
    cin >> n >> k;
    v = n+n+2;
    for(int i = 0; i < k; i++) {
        int u,v2;
        cin >> u >> v2;
        g[u+1][v2+n+1] = 1;
    }
    for(int i = 0; i < n; i++) {
        g[0][1+i] = 1;
    }
    for(int i = 0; i < n; i++) {
        g[1+n+i][v-1] = 1;
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