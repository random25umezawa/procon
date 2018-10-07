#include <stdio.h>
#include <stdbool.h>
#define H 12
#define W 12

// 島情報
char island[H+2][W+2] = {};

// 4方向をループで回す用
int dir_x[4] = {0,1,0,-1};
int dir_y[4] = {1,0,-1,0};

// (x,y)が島どうか、ついでに陸続きのマスを海に沈める
bool is_island(int x, int y) {
	if(island[y][x]=='1') {
		// マスを'1'以外にする
		island[y][x] = EOF;
		// 4方向の陸続き判定(返り値は使わない)
		for(int d = 0; d < 4; d++) {
			int dx = x+dir_x[d];
			int dy = y+dir_y[d];
			is_island(dx,dy);
		}
		// 陸だったのでtrue確定
		return true;
	}

	// 陸じゃないのでfalse
	return false;
}

int main() {
	while(true) {
		// 各HごとのWの情報
		for(int i = 0; i < H; i++) {
			scanf("%s",&island[i+1][1]);
		}

		// この段階でeofに来てたら処理終了
		if(getchar()==EOF) break;

		// 全マスについてis_islandである数を答えとする
		int ans = 0;
		for(int i = 1; i <= H; i++) {
			for(int j = 1; j <= W; j++) {
				if(is_island(j,i)) {
					ans++;
				}
			}
		}

		printf("%d\n",ans);
	}
}
