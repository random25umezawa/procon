#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	int n,c;
	scanf("%d%d",&n,&c);
	int cost_arr[30][30];
	int mixed_arr[1000][30];
	for(int i = 0; i < 1000; i++) for(int j = 0; j < 30; j++) mixed_arr[i][j] = 0;;
	for(int i = 0; i < c; i++) {
		for(int j = 0; j < c; j++) {
			scanf("%d",cost_arr[i][j]);
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			int color;
			scanf("%d",&color);
			color--;
			for(int k = 0; k < c; k++) {
				mixed_arr[i+j][k] += cost_arr[color][k];
			}
		}
	}
}
