#include <stdio.h>
#include <math.h>

int main() {
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++) {
		int a;
		scanf("%d",&a);
		printf("%.5f\n",sqrt(a/2.0));
	}
	return 0;
}
