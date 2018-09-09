#include <stdio.h>

int n;
int arr[1<<20];

int search(int l, int r, int num) {
	if(arr[l]==num) return l;
	if(r-l<=1) return -1;
	int _l = search(l,(l+r)/2,num);	if(_l>=0) return _l;
	int _r = search((l+r)/2,r,num); if(_r>=0) return _r;
	return -1;
}

int main() {
	scanf("%d",&n);
	for(int i = 0; i < n; i++) scanf("%d",&arr[i]);
	int index = search(0,n,125);
	printf("%d\n",index);
}
