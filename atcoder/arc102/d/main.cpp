#include <stdio.h>
#include <vector>

using namespace std;

int l;

struct edges{
	bool next;
	int weight;
};

vector<edges> edge_arr;

int main(){
	scanf("%d",&l);

	int n = 1;
	int m = 0;

	while(l>1) {
		//printf("%d\n",l);
		if(l%2==1) {
			edge_arr.push_back((edges){true,l});
			n += 1;
			m += 3;
		}else {
			edge_arr.push_back((edges){false,l});
			n += 1;
			m += 2;
		}
		l /= 2;
	}

	printf("%d %d\n",n,m);

	for(int i = 1; i <= edge_arr.size(); i++) {
		edges es = edge_arr[i-1];
		if(es.next) {
			printf("%d %d %d\n",i,n,es.weight-1);
			printf("%d %d %d\n",i,i+1,0);
			printf("%d %d %d\n",i,i+1,es.weight/2);
		}else {
			printf("%d %d %d\n",i,i+1,0);
			printf("%d %d %d\n",i,i+1,es.weight/2);
		}
	}
}
