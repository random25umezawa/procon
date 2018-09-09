#include <stdio.h>
#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

#define SIZE 500

struct action{
	int y,x,y2,x2;
};

int coin[SIZE][SIZE]{};
vector<action> actions;

int h,w;

int main() {
	cin >> h >> w;
	int ki = 0;
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			cin >> coin[i][j];
			ki += (coin[i][j]%2==1)?1:0;
		}
	}
	ki = (ki/2)*2;

	int x=0,y=0;
	int px,py;
	bool mode = false;
	int ki2 = 0;
	while(true) {
		if(ki==ki2) break;
		//printf("%d,%d\n",y,x);
		if(mode) {
			actions.push_back((action){py,px,y,x});
		}
		if(coin[y][x]%2==1) {
			mode = !mode;
			ki2++;
		}
		px=x;
		py=y;
		if((x==0&&y%2==1)||(x==w-1&&y%2==0)) y++;
		else x+=(y%2==0)?1:-1;
		if(y>=h) break;
	}

	printf("%d\n",actions.size());
	for(action a : actions) {
		printf("%d %d %d %d\n",a.y+1,a.x+1,a.y2+1,a.x2+1);
	}

	return 0;
}
