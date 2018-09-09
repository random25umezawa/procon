#include <stdio.h>

int n,q;
#define D 320
int vs[D*2+1][100001]{};
int ts[D][100001]{};

int main() {
	scanf("%d",&n);
	for(int i = 0; i < n; i++) {
		int x,v;
		scanf("%d%d",&x,&v);
		if((v>=0&&v<=D)||(v<0&&v>=-D)) {
			vs[v+D][x]++;
		}else {
			for(int ax = x, j = 0; j < D && ax>=0 && ax<=100000; ax+=v, j++) {
				ts[j][ax]++;
			}
		}
	}
	for(int i = 0; i < D; i++) {
		for(int j = 0; j < 100000; j++) {
			ts[i][j+1] += ts[i][j];
		}
	}
	for(int i = 0; i <= D*2; i++) {
		for(int j = 0; j < 100000; j++) {
			vs[i][j+1] += vs[i][j];
		}
	}
	scanf("%d",&q);
	for(int j = 0; j < q; j++) {
		int t,l,r;
		scanf("%d%d%d",&t,&l,&r);
		int ans = 0;
		if(t<D) {
			int left = 0;
			int right = 0;
			if(l>0) left = ts[t][l-1];
			right = ts[t][r];
			ans += right-left;
		}
		for(int i = -D; i <= D; i++) {
			int left = 0;
			int right = 0;
			int _l = l-t*i;
			int _r = r-t*i;
			if(_l>100001) continue;
			if(_l>0) left = vs[i+D][_l-1];
			if(_r<0) continue;
			else if(_r<100001) right = vs[i+D][_r];
			else right = vs[i+D][100000];
			ans += right-left;
		}
		printf("%d\n",ans);
	}
}
