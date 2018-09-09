#include <stdio.h>
#include <vector>

using namespace std;

struct line{
	int next, dist;
	line(int _a, int _b) {
		next = _a;
		dist = _b;
	}
};

int n,m,c,s,g;
vector<line> lines[100][20];
int graph[100][100];
int dijk[100];
bool arrived[100];
int price[20][20000];

void make_graph(int start, int company, int prev, int all_dist) {

}

void dijkstra(int pos) {

}

int main() {
	scanf("%d%d%d%d%d",&n,&m,&c,&s,&g);
	while(n>0) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < c; j++) {
				lines[i][j] = *(new vector<line>());
			}
		}
		for(int i = 0; i < 100; i++) {
			dijk[i] = 1<<30;
			arrived[i] = false;
			for(int j = 0; j < 100; j++) {
				graph[i][j] = -1;
			}
		}

		for(int i = 0; i < m; i++) {
			int x,y,d,c2;
			scanf("%d%d%d%d",&x,&y,&d,&c2);
			lines[x][c2].push_back(line(y,d));
			lines[y][c2].push_back(line(x,d));
		}

		int ps[50], qs[50], rs[50];
		for(int i = 0; i < c; i++) {
			scanf("%d",&ps[i]);
		}
		for(int i = 0; i < c; i++) {
			for(int j = 0; j < ps[i]-1; j++) scanf("%d",&qs[j]);
			for(int j = 0; j < ps[i]; j++) scanf("%d",&rs[j]);
			int _index = 0;
			price[i][0] = 0;
			for(int j = 1; j < 20000; j++) {
				price[i][j] = price[i][j-1] + rs[_index];
				if(_index<ps[i]-1 && j==qs[_index]) _index++;
			}
		}

		for(int i = 0; i < n; i++) {
			for(int j = 0; j < c; j++) {
				make_graph(i,c,-1,0);
			}
		}

		dijkstra(s);

		printf("%d\n",dijk[g]);

		scanf("%d%d%d%d%d",&n,&m,&c,&s,&g);
	}
}
