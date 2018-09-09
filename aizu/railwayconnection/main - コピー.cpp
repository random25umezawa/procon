#include <stdio.h>
#include <vector>

using namespace std;

int n,m,c,s,g;
vector<int> line[100][20];
int price[20][20000];

int main() {
	scanf("%d%d%d%d%d",&n,&m,&c,&s,&g);
	while(n>0) {
		printf("%d",n);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < c; j++) {
				line[i][j] = *(new vector<int>());
			}
		}
		for(int i = 0; i < m; i++) {
			int x,y,d,c2;
			scanf("%d%d%d%d",&x,&y,&d,&c2);
		}
		int ps[50], qs[50], rs[50];
		for(int i = 0; i < c; i++) {
			scanf("%d",&ps[i]);
		}
		for(int i = 0; i < c; i++) {
			for(int j = 0; j < ps[i]-1; j++) scanf("%d",&qs[j]);
			for(int j = 0; j < ps[i]; j++) scanf("%d",&rs[j]);
		}
		scanf("%d%d%d%d%d",&n,&m,&c,&s,&g);
	}
}
