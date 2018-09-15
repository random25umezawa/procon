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
                cout << pos << "->" << next << endl;
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
        cout << flow << endl;
        if(flow<=0) break;
        else ans += flow;
    }
    return ans;
}

int main() {
    int h,w;
    cin >> h >> w;
    int nc = 0;
    unordered_map<int,int> ns;
    int tx,ty;
    int sx,sy;
    unordered_map<int,unordered_map<int,bool> > m;

    for(int i = 0; i < h; i++) {
      string s;
      cin >> s;
        for(int j = 0; j < w; j++) {
        char c = s.at(j);
        if(c!='.') {
          ns[h*i+j] = nc;
          m[i][j] = true;
          nc++;
        }
        if(c=='S') {
          sx = j; sy = i;
        }else if(c=='T') {
          tx = j; ty = i;
        }
      }
    }
    if(tx==sx||ty==sy) {
      cout << -1 << endl;
      return 0;
    }

    double_map g;
    for(pair<int,int> p : ns) {
      int xy = p.first;
      int x = xy%h;
      int y = xy/h;
      int id = p.second;
      for(int i = 0; i < h; i++) {
        if(i!=y&&m[i][x]) g[id][ns[h*i+x]] = 1;
      }
      for(int j = 0; j < w; j++) {
        if(j!=x&&m[y][j]) g[id][ns[h*y+j]] = 1;
      }
    }
    int ans = max_flow(ns.size(),g,ns[h*sy+sx],ns[h*ty+tx]);
    cout << ans << endl;
}
