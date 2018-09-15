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
    int h,w;
    cin >> h >> w;
    int tx,ty;
    int sx,sy;

    double_map g;
    for(int i = 0; i < h; i++) {
      string s;
      cin >> s;
      for(int j = 0; j < w; j++) {
        char c = s.at(j);
        if(c!='.') {
          g[1+i][1+h+j] = 1;
          g[1+h+j][1+i] = 1;
        }
        if(c=='S') {
          sx = j; sy = i;
          g[0][1+i] = 10001;
          g[0][1+h+j] = 10001;
        }else if(c=='T') {
          tx = j; ty = i;
          g[1+i][1+h+w] = 10001;
          g[1+h+j][1+h+w] = 10001;
        }
      }
    }
    if(tx==sx||ty==sy) {
      cout << -1 << endl;
      return 0;
    }

    int ans = max_flow(1+h+w+1,g,0,1+h+w);
    cout << ans << endl;
}
