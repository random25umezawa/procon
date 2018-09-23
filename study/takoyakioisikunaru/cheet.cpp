/*
* 繰り返し二乗法
* http://keita-matsushita.hatenablog.com/entry/2016/12/05/175024
*/

long pow(long x, int n) { //x^n 計算量O(logn)
	long ans = 1;
	while (n > 0) {
		if ((n & 1) == 1) {
			ans = ans * x;
		}
		x = x * x; //一周する度にx, x^2, x^4, x^8となる
		n >>= 1; //桁をずらす n = n >> 1
	}
	return ans;
}

/*
* セグメント木(max調べる版)
* getMaxのインデックス範囲はa<=x<b、それに対応するseg配列インデックスはk
* http://kagamiz.hatenablog.com/entry/2012/09/24/230035
*/

typedef long long ll;

ll seg[1 << 18];
int size;

void init(int n)
{
	size = 1;
	while (size < n) size *= 2;
}

void update(int k, ll x)
{
	k += size - 1;
	seg[k] = x;

	while (k){
		k = (k - 1) / 2;
		seg[k] = max(seg[k * 2 + 1], seg[k * 2 + 2]);
	}
}

ll getMax(int a, int b, int k, int l, int r)
{
	if (r <= a || b <= l){
		return (0);
	}

	if (a <= l && r <= b){
		return (seg[k]);
	}
	ll lch = getMax(a, b, k * 2 + 1, l, (l + r) / 2);
	ll rch = getMax(a, b, k * 2 + 2, (l + r) / 2, r);

	return (max(lch, rch));
}

/*
* 二分探索 [l,r)の範囲を探索
* 自作
*/
#include <stdio.h>

int n;
int arr[1<<20];

int search(int l, int r, int num) {
	if(arr[l]==num) return l;
	if(r-l<=1) return -1;
	int _l = search(l,(l+r)/2,num);	if(_l>=0) return _l;
	int _r = search((l+r)/2,r,num); if(_r>=0) return _r;
	return -1;
}

int main() {
	scanf("%d",&n);
	for(int i = 0; i < n; i++) scanf("%d",&arr[i]);
	int index = search(0,n,125);
	printf("%d\n",index);
}

/*
* 交点判定(特殊事例は-1.0を返す)
* 自作
*/


struct cross_point{
	int index;	//line number
	double rate;	//[0.0,1.0]
	cross_point(int _index, double _rate) {
		index = _index;
		rate = _rate;
	}
	bool operator<(const cross_point &right) const {
		return rate < right.rate;
	}
};

double cross_rate(double a, double b, double c, double d, double e, double f, double g, double h) {
	double child = (g-e)*(f-b)-(h-f)*(e-a);
	double mother = (g-e)*(d-b)-(h-f)*(c-a);
	return (mother==0.0)?-1.0:child/mother;
}

/*
* たぶん優先度つきキューの早いdijkstra
* http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=1190374#1
*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define INF 20000000
typedef struct Edge edge;

struct Edge{
	int src,dst,weight;
	Edge(int start,int end,int cost) :
		src(start),dst(end),weight(cost) {}
};

bool operator < (const edge &e,const edge &f){
	return (e.weight != f.weight) ? (e.weight > f.weight) : (e.src != f.src) ? (e.src < f.src) : (e.dst < f.dst);
}

typedef vector<edge> Edges;

vector<int> dijkstra(Edges,int);

int main(int argc,char* argv[]){
	int n,v,k,dst,weight;
	Edges es;
	vector<int> vec;

	cin >> n;
	for(int i = 0;i < n;i++){
		cin>> v >> k;
		vec.push_back(v);
		for(int j = 0;j < k;j++){
			cin >> dst >> weight;
			edge e(i,dst,weight);
			es.push_back(e);
		}
	}

	vector<int> dist = dijkstra(es,n);

	for(int i = 0;i < n;i++)
		printf("%d %d\n",vec[i],dist[i]);
	return 0;
}

vector<int> dijkstra(Edges es,int n){
	vector<int> dist(n);
	priority_queue<edge> que;
	Edges l[n];
	dist.assign(n,INF);
	dist[0] = 0;

	for(int i = 0;i < (int)es.size();i++){
		edge e = es[i];
		l[e.src].push_back(e);
	}

	for(int i = 0;i < (int)l[0].size();i++)
		que.push(l[0][i]);

	while(!que.empty()){
		edge e = que.top();
		que.pop();
		if(dist[e.dst] > dist[e.src] + e.weight){
			dist[e.dst] = dist[e.src] + e.weight;

			for(int i = 0;i < (int)l[e.dst].size();i++)
				que.push(l[e.dst][i]);
		}
	}

	return dist;
}

/*
* 最大流
* http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=1700498#1
*/

#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define rrep2(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define all(a) (a).begin(),(a).end()

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<P> vp;
typedef vector<ll> vll;

const int INF = 99999999;
const int MAX_V = 1000;

struct edge { int to, cap, rev; };

vector<edge> G[MAX_V];
bool used[MAX_V];       // for DFS

// add graph the edge
void add_edge(int from, int to, int cap) {
    G[from].emplace_back((edge){to, cap, (int)G[to].size()});
    G[to].emplace_back((edge){from, 0, (int)G[from].size() - 1});
}

int dfs(int v, int t, int f) {
    if (v == t) return f;
    used[v] = true;
    rep(i, G[v].size()) {
        edge &e = G[v][i];
        if (!used[e.to] && e.cap > 0) {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t) {
    int flow = 0;
    for(;;) {
        memset(used, 0, sizeof(used));
        int f = dfs(s, t, INF);
        if (f == 0) return flow;
        flow += f;
    }
}


signed main() {
    int V, E;
    cin >> V >> E;
    rep(i, E) {
        int u, v, c;
        cin >> u >> v >> c;
        add_edge(u, v, c);
    }
    cout << max_flow(0, V - 1) << endl;
}

/*
* 文字列を区切り文字列で分割(vector使うように変更版)
* https://qiita.com/_meki/items/4328c98964ea33b0db0d
*/

vector<string> split(const std::string& s, const std::string& delim)
{
		vector<string> result;

		using string = std::string;
		string::size_type pos = 0;

		while(pos != string::npos )
		{
				string::size_type p = s.find(delim, pos);

				if(p == string::npos)
				{
						result.push_back(s.substr(pos));
						break;
				}
				else {
						result.push_back(s.substr(pos, p - pos));
				}

				pos = p + delim.size();
		}
		return result;
}

/*
* vectorを二分探索してインデックスを知る
*/
int a;
vector<int> x;
distance(x.begin(),lower_bound(x.begin(),x.end(),a));	//含む
distance(x.begin(),upper_bound(x.begin(),x.end(),a));	//含まない
