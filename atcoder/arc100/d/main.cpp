#include <stdio.h>
#include <algorithm>

long int k;

int sunuke(long int a) {
	int res = 0;
	while(a>0L) {
		res += int(a%10L);
		a/=10L;
	}
	return res;
}

int main() {
	scanf("%ld",&k);
	double min_sunuke = 1.0e32;
	for(long int i = k; i > 0; i--) {
		double sunuke_num = (double)i/sunuke(i);
		double pre_sunuke = min_sunuke;
		min_sunuke = std::min(min_sunuke,sunuke_num);
		if(pre_sunuke!=min_sunuke) printf("%15lf,%8d,%8d,%15lf\n",min_sunuke,i,sunuke(i),sunuke_num);
	}
}
