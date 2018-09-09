#include <stdio.h>
#include <vector>

using namespace std;

void dfs(int pos, vector<vector<int> > &graph, vector<bool> &arrived_flag, vector<int> &arrived_num) {
	if(arrived_flag[pos]) return;
	arrived_flag[pos] = true;
	for(int i = 0; i < graph[pos].size(); i++) dfs(graph[pos][i],graph,arrived_flag,arrived_num);
	arrived_num.push_back(pos);
}

&vector<int> rdfs(int pos, vector<vector<int> > &graph, vector<bool> &arrived_flag, vector<int> &group) {

}

int main() {
	int n;
	scanf("%d",&n);
	while(n>0) {
		printf("n=%d\n",n);
		vector<vector<int> > graph(n);
		vector<vector<int> > r_graph(n);
		vector<vector<double> > ps(n);
		for(int i = 0; i < n; i++) {
			graph[i] = vector<int>();
			r_graph[i] = vector<int>();
		}
		for(int i = 0; i < n; i++) {
			double p;
			int m;
			scanf("%lf%d",&p,&m);
			for(int j = 0; j < m; j++) {
				int a; scanf("%d",&a);
				a--;
				graph[i].push_back(a);
				r_graph[a].push_back(i);
			}
			ps[i] = p;
		}
		vector<bool> arrived_flag(n);
		vector<int> arrived_num(0);
		for(int i = 0; i < n; i++) dfs(i,graph,arrived_flag,arrived_num);
		/*
		for(int j = 0; j < n; j++) printf("%d,",arrived_num[j]);
		printf("\n");
		*/
		arrived_flag.clear();
		vector<int> new_groups(n);
		vector<int> new_groups_ends(0);
		vector<double> new_ps(0);
		for(int i = 0; i < n; i++) {
			vector<int> group = rdfs(i,graph,arrived_flag, new vector<int>(0));
		}
		/*
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < graph[i].size(); j++) printf("%d,",graph[i][j]);
			printf("\n");
		}
		printf("^^^^^^graph^^^^^^\n");
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < r_graph[i].size(); j++) printf("%d,",r_graph[i][j]);
			printf("\n");
		}
		printf("^^^^^r_graph^^^^^\n");
		*/
		double ans = 0.0;
		printf("%lf\n",ans);
		scanf("%d",&n);
	}
}
