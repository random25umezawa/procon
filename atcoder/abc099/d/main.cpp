#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n,c;
	int cost_arr[30][30];
	int mixed_arr[30][3];
	scanf("%d%d",&n,&c);
	for(int i = 0; i < 30; i++) for(int j = 0; j < 3; j++) mixed_arr[i][j] = 0;
	for(int i = 0; i < c; i++) {
		for(int j = 0; j < c; j++) {
			scanf("%d",&cost_arr[i][j]);
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			int color;
			scanf("%d",&color);
			color--;
			for(int k = 0; k < c; k++) {
				mixed_arr[k][(i+j)%3] += cost_arr[color][k];
			}
		}
	}
	int ans = 1<<30;
	for(int i = 0; i < c; i++) {
		for(int j = i+1; j < c; j++) {
			for(int k = j+1; k < c; k++) {
				ans = min(ans,mixed_arr[i][0]+mixed_arr[j][1]+mixed_arr[k][2]);
				ans = min(ans,mixed_arr[i][0]+mixed_arr[j][2]+mixed_arr[k][1]);
				ans = min(ans,mixed_arr[i][1]+mixed_arr[j][0]+mixed_arr[k][2]);
				ans = min(ans,mixed_arr[i][1]+mixed_arr[j][2]+mixed_arr[k][0]);
				ans = min(ans,mixed_arr[i][2]+mixed_arr[j][0]+mixed_arr[k][1]);
				ans = min(ans,mixed_arr[i][2]+mixed_arr[j][1]+mixed_arr[k][0]);
			}
		}
	}
	printf("%d\n",ans);
}
