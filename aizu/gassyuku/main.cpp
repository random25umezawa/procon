#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

//insert into arrived_num sorted by depth
void dfs(int pos, vector<vector<int> > &graph, vector<bool> &arrived_flag, vector<int> &arrived_num) {
	if(arrived_flag[pos]) return;
	arrived_flag[pos] = true;
	for(int i = 0; i < graph[pos].size(); i++) dfs(graph[pos][i],graph,arrived_flag,arrived_num);
	arrived_num.push_back(pos);
}

//return group ([] , [node] , [loop_nodes])
vector<int>& rdfs(int pos, vector<vector<int> > &graph, vector<bool> &arrived_flag, vector<int> &group) {
	if(arrived_flag[pos]) return group;
	arrived_flag[pos] = true;
	for(int i = 0; i < graph[pos].size(); i++) rdfs(graph[pos][i],graph,arrived_flag,group);
	group.push_back(pos);
	return group;
}

int main() {
	int n;
	scanf("%d",&n);
	while(n>0) {
		vector<vector<int> > graph(n);
		vector<vector<int> > r_graph(n);
		vector<double> ps(n);
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

		fill(arrived_flag.begin(),arrived_flag.end(),false);
		double ans = 1.0;
		for(int i = n-1; i >= 0; i--) {
			vector<int> group = rdfs(arrived_num[i],r_graph,arrived_flag, *(new vector<int>(0)));
			if(group.size()>0) {
				//map of group nodes
				map<int,bool> group_nums;
				for(int j = 0; j < group.size(); j++) {
					group_nums[group[j]] = true;
				}
				//final nodes have no r_graph destinations without group nodes
				bool is_final = true;
				for(int j = 0; j < group.size(); j++) {
					int next = group[j];
					for(int k = 0; k < r_graph[next].size(); k++) {
						is_final &= group_nums[r_graph[next][k]];
					}
				}
				if(is_final) {
					double all_p = 1.0;
					for(int j = 0; j < group.size(); j++) {
						all_p *= ps[group[j]];
					}
					ans *= (1-all_p);
				};
			}
		}
		printf("%.9lf\n",ans);

		scanf("%d",&n);
	}
}
