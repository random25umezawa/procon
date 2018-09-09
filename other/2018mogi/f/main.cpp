#include <stdio.h>
#include <algorithm>
#include <cmath>

using namespace std;

int n,m;
int arr[1000003]{};

int main() {
	while(true) {
		scanf("%d%d",&n,&m);
		if(n<=0) break;
		for(int i = 0; i < m-1; i++) {
			int a,x;
			scanf("%d%d",&a,&x);
			x--;
			int temp[100003];
			int d = floor(sqrt(a));
			for(int j = 1; j <= 3; j++) {
				temp[x-d+j] = max(a-(x-d+j)*(x-d+j),0);
				temp[x+d-j] = max(a-(x+d-j)*(x+d-j),0);
			}
			for(int j = 1; j <= 3; j++) {
				temp[x-d+j] = max(a-(x-d+j)*(x-d+j),0);
				temp[x+d-j] = max(a-(x+d-j)*(x+d-j),0);
			}
			for(int j = 1; j <= 6; j++) {
				arr[x-d+j-1] += temp[j];
				if(a==1) arr[x+d-j-1] += -temp[j];
			}
		}
		for(int i = 0; i < 100002; i++) arr[i+1] += arr[i];
		for(int i = 0; i < 100002; i++) arr[i+1] += arr[i];
		for(int i = 0; i < 100002; i++) arr[i+1] += arr[i];
		for(int i = 0; i < 25; i++) printf("%d\n",arr[i]);
		int a;
		scanf("%d",&a);
	}
}
