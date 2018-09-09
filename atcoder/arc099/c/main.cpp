#include <stdio.h>

int n,k,a,index;

int main() {
	scanf("%d%d",&n,&k);
	k--;
	for(int i = 0; i < n; i++) {
		scanf("%d",&a);
		if(a==1) index = i;
	}
	int ans = 0;
	if(index>0) {
		ans += (index+k-1)/k;
		index = ans*k;
	}
	ans += (n+k-2-index)/k;
	printf("%d\n",ans);
}
