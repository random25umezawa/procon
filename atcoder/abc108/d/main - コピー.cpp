#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

typedef long long ll;

using namespace std;

#define SIZE 502

struct act{
	int y,x,y2,x2;
};

bool arrived[SIZE][SIZE]{};
int coin[SIZE][SIZE]{};
vector<act> actions;
int dir[2][4]{{0,1,0,-1},{1,0,-1,0}};

int h,w;

bool dfs(int y, int x, int tesu[SIZE][SIZE]) {
	//cout << "dfs " << y << "," << x << "," << tesu[y][x] << endl;
	for(int d = 0; d < 4; d++) {
		int dx = x+dir[0][d];
		int dy = y+dir[1][d];
		//cout << dy << dx << tesu[dy][dx] << tesu[y][x] << endl;
		if(tesu[dy][dx] == -1) {
			actions.push_back((act){y,x,dy,dx});
			arrived[dy][dx] = true;
			arrived[y][x] = true;
			return true;
		}
		if(tesu[dy][dx] > 0) {
			if(tesu[dy][dx] == tesu[y][x]-1) {
				tesu[y][x] = -2;
				bool res = dfs(dy,dx,tesu);
				if(res) {
					//cout << "OKKK" << endl;
					actions.push_back((act){y,x,dy,dx});
					arrived[y][x] = true;
					return true;
				}
			}
		}
	}
	return false;
}

int main() {
	cin >> h >> w;
	for(int i = 0; i < h+2; i++) {
		for(int j = 0; j < w+2; j++) {
			coin[i][j] = -1;
		}
	}
	for(int i = 1; i <= h; i++) {
		for(int j = 1; j <= w; j++) {
			cin >> coin[i][j];
		}
	}
	for(int i = 1; i <= h; i++) {
		for(int j = 1; j <= w; j++) {
			//cout << i << "," << j << "," << coin[i][j] << endl;
			if(!arrived[i][j]&&coin[i][j]>0&&coin[i][j]%2==1) {
				int tesu[SIZE][SIZE]{};
				tesu[i][j] = -1;
				/*
				for(int k = 1; k<= h; k++) {
					for(int l = 1; l <= w; l++) {
						cout << tesu[k][l] << " ";
					}
					cout << endl;
				}
				*/
				queue<int> qx,qy;
				qx.push(j);
				qy.push(i);
				int count = 0;
				while(!qx.empty()) {
					count++;
					int size = qx.size();
					for(int loop = 0; loop < size; loop++) {
						int x = qx.front(); qx.pop();
						int y = qy.front(); qy.pop();
						if(arrived[y][x]) continue;
						for(int d = 0; d < 4; d++) {
							int dx = x+dir[0][d];
							int dy = y+dir[1][d];
							if(arrived[dy][dx]) continue;
							//cout << "temp " << dy << "," << dx << endl;
							if(tesu[dy][dx]==0) tesu[dy][dx] = count;
							if(tesu[dy][dx]!=-1) tesu[dy][dx] = min(tesu[dy][dx],count);
							if(coin[dy][dx]>0&&!arrived[dy][dx]&&coin[dy][dx]%2==1) {
								//yatta
								/*
									cout << "YATTA" << endl;
									for(int k = 1; k<= h; k++) {
										for(int l = 1; l <= w; l++) {
											cout << tesu[k][l] << " ";
										}
										cout << endl;
									}
									*/
								dfs(dy,dx,tesu);
								goto label;
							}
							if(coin[dy][dx]!=-1&&tesu[dy][dx]>0&&tesu[dy][dx]!=-1) {
								//cout << "  " << dy << dx << endl;
								qx.push(dx);
								qy.push(dy);
							}
						}
					}
				}
			}
			label:
			continue;
		}
	}

	printf("%d\n",actions.size());
	for(act a : actions) {
		printf("%d %d %d %d\n",a.y,a.x,a.y2,a.x2);
	}

	return 0;
}
