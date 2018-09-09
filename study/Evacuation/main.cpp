#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>

#define rep(i,s,e) for(int i = s; i < e; i++) 
#define reps(i,n) rep(i,0,n)
 
using namespace std;

typedef unordered_map<int,unordered_map<int,int>> double_map;

int dir[4][2]{{0,1},{1,0},{0,-1},{-1,0}};
 
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

struct dpt{int d,p,t;};

void tansaku(int door_id, int x, int y, int t, char m[14][14], bool arrived[14][14], vector<dpt> &dv, unordered_map<int,int> &pm) {
    //cout << x << "," << y << endl;
    arrived[x][y] = true;
    reps(i,4) {
        int nx = x+dir[i][0];
        int ny = y+dir[i][1];
        if(m[nx][ny]=='.'&&!arrived[nx][ny]) {
            dv.push_back((dpt){door_id,pm[nx*100+ny],t+1});
            tansaku(door_id,nx,ny,t+1,m,arrived,dv,pm);
        }
    }
}
 
int main() {
    int x,y;
    char m[14][14]{};
    cin >> x >> y;
    rep(i,1,x+1) scanf("%s",m[i]+1);
    int persons = 0;
    unordered_map<int,int> pm;
    rep(i,1,x+1) {
        rep(j,1,y+1) {
            if(m[i][j]=='.') {
                pm[i*100+j] = persons;
                //cout << i*100+j << "->" << persons << endl;
                persons++;
            }
        }
    }
    int doors = 0;
    vector<dpt> dv;
    rep(i,1,x+1) {
        rep(j,1,y+1) {
            bool arrived[14][14]{};
            if(m[i][j]=='D') {
                tansaku(doors,i,j,0,m,arrived,dv,pm);
                doors++;
            }
        }
    }
    /*
    for(dpt p : dv) {
        printf("%d,%d,%d\n",p.d,p.p,p.t);
    }
    */
    for(int t = 1; t <= x*y; t++) {
        //cout << "t=" << t << endl;
        int v = 1+persons+doors*t+1;
        double_map g;
        for(dpt p : dv) {
            for(int _t = p.t; _t <= t; _t++) {
                g[1+p.p][1+persons+p.d*t+_t-1] = 1;
                //cout << "g " << p.p << " -> (" << p.d << "," <<_t << ")" << endl;
            }
        }
        reps(i,persons) g[0][1+i] = 1;
        reps(i,doors) reps(j,t) g[1+persons+i*t+j][v-1] = 1;
        int ans = max_flow(v,g,0,v-1);
        //cout << ans << endl;
        if(ans==persons) {
            cout << t << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}