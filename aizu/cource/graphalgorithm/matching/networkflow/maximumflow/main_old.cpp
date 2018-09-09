#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

struct line{
	int a, b, limit, now;
	line(int _a, int _b, int _limit) {
		a = _a;
		b = _b;
		limit = _limit;
		now = 0;
	}
};

int dfs(int now, int end, int flow, vector<vector<line> > &graph, bool *arrived) {
	if(now == end) return flow;
	if(arrived[now]) return 0;
	arrived[now] = true;
	int result = flow;
	for(int i = 0; i < graph[now].size(); i++) {
		line next_line = graph[now][i];
		int next_index = (next_line.a==now)?next_line.b:next_line.a;
		if(next_line.now>0 && flow>0 && flow!=9999) {
			int ret = dfs(next_index,end,min(next_line.now,flow),graph,arrived);
			if(ret>0) {
				(&graph[now][i])->now -= ret;
				return ret;
			}
		}
		if(next_line.now<next_line.limit) {
			if(now==0) flow = next_line.limit-next_line.now;
			int ret = dfs(next_index,end,min(next_line.limit-next_line.now,flow),graph,arrived);
			if(ret>0) {
				(&graph[now][i])->now += ret;
				return ret;
			}
		}
	}
	arrived[now] = false;
	return result;
}

int main() {
	int v,e;
	scanf("%d%d",&v,&e);
	vector<vector<line> > graph(v);
	for(int i = 0; i < v; i++) graph[i] = vector<line>();
	for(int i = 0; i < e; i++) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		line new_line(a,b,c);
		graph[a].push_back(*&new_line);
		graph[b].push_back(*&new_line);
	}

	int ans = 0;
	int count = 0;
	while(true) {
		for(int i = 0; i < v; i++) {
			for(int j = 0; j < graph[i].size(); j++) {
				printf("(%2d->%2d, %3d/%3d) ",graph[i][j].a,graph[i][j].b,graph[i][j].now,graph[i][j].limit);
			}
			printf("\n");
		}
		int flow = dfs(0,v-1,9999,graph,new bool[100]);
		if(flow==0) break;
		printf("%d\n",flow);
		count++;
		ans += flow;
		if(count>10) break;
	}

	printf("%d\n",ans);
}
