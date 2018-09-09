#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n;
double arr[300][2];

int main() {
	while(true) {
		scanf("%d",&n);
		if(n<=0) break;
		for(int i = 0; i < n; i++) {
			scanf("%lf%lf",&arr[i][0],&arr[i][1]);
		}
		int ans = 0;
		for(int i = 0; i < n; i++) {
			double x1 = arr[i][0];
			double y1 = arr[i][1];
			for(int j = i+1; j < n; j++) {
				double x2 = arr[j][0];
				double y2 = arr[j][1];
				double dx = x2-x1;
				double dy = y2-y1;
				double dlen = dx*dx+dy*dy;
				if(dlen>=4.0) continue;
				double len = sqrt(1-dlen/4.0);
				double cx1 = (x1+x2)/2.0+dy/sqrt(dlen)*len;
				double cy1 = (y1+y2)/2.0-dx/sqrt(dlen)*len;
				double cx2 = (x1+x2)/2.0-dy/sqrt(dlen)*len;
				double cy2 = (y1+y2)/2.0+dx/sqrt(dlen)*len;
				int _ans1 = 0;
				int _ans2 = 0;
				for(int k = 0; k < n; k++) {
					double x3 = arr[k][0];
					double y3 = arr[k][1];
					if((cx1-x3)*(cx1-x3)+(cy1-y3)*(cy1-y3)<=1.0000001) _ans1++;
					if((cx2-x3)*(cx2-x3)+(cy2-y3)*(cy2-y3)<=1.0000001) _ans2++;
				}
				ans = fmax(ans,_ans1);
				ans = fmax(ans,_ans2);
			}
		}
		printf("%d\n",(ans==0)?1:ans);
	}
}
