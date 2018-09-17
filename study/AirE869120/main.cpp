#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

#define LLINF 100000000000000000LL
#define DIV 2147483647LL

typedef long long ll;

using namespace std;

typedef unordered_map<ll,unordered_map<ll,ll>> double_map;

ll dfs(double_map &g, ll pos, ll end, ll flow, unordered_map<ll,bool> &arrived) {
    if(pos==end) return flow;
    arrived[pos] = true;
    for(pair<ll,ll> p : g[pos]) {
        ll next = p.first;
        ll capacity = p.second;
        if(!arrived[next]&&capacity>0) {
            ll res = dfs(g,next,end,min(flow,capacity),arrived);
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

ll max_flow(double_map &g, ll s, ll e) {
    ll ans = 0;
    while(true) {
        unordered_map<ll,bool> arrived;
        ll flow = dfs(g,s,e,1<<30,arrived);
        cout << flow << endl;
        if(flow<=0) break;
        else ans += flow;
    }
    return ans;
}

int main() {
  ll n,m,d;
  cin >> n >> m >> d;
  ll e = 1e9+d;
  ll input[1000][5];
  map<ll,bool> times[1000];
  for(int i = 0; i < m; i++) {
    cin >> input[i][0] >> input[i][1] >> input[i][2] >> input[i][3] >> input[i][4];
    input[i][0]--; input[i][1]--;
    input[i][3]+=d;
    times[input[i][0]].insert(make_pair(input[i][2],true));
    times[input[i][1]].insert(make_pair(input[i][3],true));
  }
  times[n-1].insert(make_pair(e,true));

  for(int i = 0; i < n; i++) {
    cout << times[i].size() << endl;
  }

  double_map dm;

  for(int i = 0; i < n; i++) {
    pair<ll,bool> pre_p(0,false);
    for(pair<ll,bool> p : times[i]) {
      ll pre_t = pre_p.first;
      ll t = p.first;
      dm[i*DIV+pre_t][i*DIV+t] = LLINF;
      pre_p = p;
    }
  }
  for(int i = 0; i < m; i++) {
    ll u = input[i][0];
    ll v = input[i][1];
    ll p = input[i][2];
    ll q = input[i][3];
    ll w = input[i][4];
    dm[u*DIV+p][v*DIV+q] = w;
  }

  ll ans = max_flow(dm,0,(n-1)*DIV+e);

  cout << ans << endl;
}
