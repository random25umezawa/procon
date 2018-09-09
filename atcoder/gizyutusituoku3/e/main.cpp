#include <stdio.h>

typedef long long ll;

int main() {
	int n;
	scanf("%d",&n);
	if(n==1) {
		printf("%.12lf",1.0);
		return 0;
	}
	double ans = 0.0;
	/*
	for(int i = 1; i <= n; i++) {
		double _ans = 0.0;
		_ans = ((double)n-i)*i*(n+1)/n/2.0;
		ans += _ans;
	}
	*/
	for(int i = 1; i <= n; i++) {
		double _ans = 0.0;
		_ans = 1*(n+1)*i/2.0/n;
		ans += _ans;
	}
	printf("%.14lf",ans);
}
