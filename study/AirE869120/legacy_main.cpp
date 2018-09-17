#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

/**** Const List   ****/

#define INF 1000000000
#define LLINF 100000000000000000LL

#define MAX_FLOW_MAX_V 100000

/**** Network Flow ****/

class MaxFlow {
  struct edge { int to; ll cap; int rev; };

  vector<edge> G[MAX_FLOW_MAX_V];
  bool used[MAX_FLOW_MAX_V];
  ll level[MAX_FLOW_MAX_V];
  ll iter[MAX_FLOW_MAX_V];

  void init() {
    for (int i = 0; i < MAX_FLOW_MAX_V; i++) {
      G[i].clear();
    }
  }
  void add_edge(int from, int to, ll cap) {
    G[from].push_back((edge){to, cap, G[to].size()});
    G[to].push_back((edge){from, 0, G[from].size() - 1});
  }
  void add_undirected_edge(int e1, int e2, ll cap) {
    G[e1].push_back((edge){e2, cap, G[e2].size()});
    G[e2].push_back((edge){e1, cap, G[e1].size() - 1});
  }
  ll dfs(int v, int t, ll f) {
    if (v == t) return f;
    used[v] = true;
    for (int i = 0; i < G[v].size(); i++) {
      edge &e = G[v][i];
      if (!used[e.to]&& e.cap > 0) {
        ll d = dfs(e.to, t, min(f, e.cap));
        if (d > 0) {
          e.cap -= d;
          G[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }
  ll max_flow(int s, int t) {
    int flow = 0;
    while (1) {
      memset(used, 0, sizeof(used));
      ll f = dfs(s, t, LLINF);
      if (f == 0) return flow;
      flow += f;
    }
  }
  void bfs(int s) {
    memset(level, -1, sizeof(level));
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while (!que.empty()) {
      int v = que.front(); que.pop();
      for (int i = 0; i < G[v].size(); i++) {
        edge &e = G[v][i];
        if (e.cap > 0 && level[e.to] < 0) {
          level[e.to] = level[v] + 1;
          que.push(e.to);
        }
      }
    }
  }
  ll dinic_dfs(int v, int t, ll f) {
    if (v == t) return f;
    for (int i= iter[v]; i < G[v].size(); i++) {
      edge &e = G[v][i];
      if (e.cap > 0 && level[v] < level[e.to]) {
        ll d = dinic_dfs(e.to, t, min(f, e.cap));
        if (d > 0) {
          e.cap -= d;
          G[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }
  ll dinic(int s, int t) {
    ll flow = 0;
    while (1) {
      bfs(s);
      if (level[t] < 0) return flow;
      memset(iter, 0, sizeof(iter));
      int f;
      while ((f = dinic_dfs(s, t, INF)) > 0) {
        flow += f;
      }
    }
  }
};

int main() {
  int n,m,d;
  cin >> n >> m >> d;
  ll e = 1e9+d;
  int input[1000][5];
  map<int,bool> times[1000];
  for(int i = 0; i < m; i++) {
    cin >> input[i][0] >> input[i][1] >> input[i][2] >> input[i][3] >> input[i][4];
    input[i][0]--; input[i][1]--;
    input[i][3]+=d;
    times[input[i][0]].insert(input[i][2],true);
    times[input[i][1]].insert(input[i][3],true);
  }
  times[n-1].insert(e,true);

  int node_start_index[1000] = {};
  for(int i = 1; i < n; i++) {
    node_start_index[i] = node_start_index[i-1]+times[i-1].size();
  }

  MaxFlow mf;

  for(int i = 0; i < n; i++) {
    pair<int,bool> pre_p(0,false);
    for(pair<int,bool> p : times[i]) {
      int pre_t = pre_p.first;
      int t = p.first;
      mf.add_edge(i*1e9LL+pre_t,i*1e9LL*t,LLINF);
      pre_p = p;
    }
  }
  for(int i = 0; i < m; i++) {
    int u = input[i][0];
    int v = input[i][1];
    int p = input[i][2];
    int q = input[i][3];
    int w = input[i][4];
    times[i].lower_bound();
  }
}
