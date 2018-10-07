#include <iostream>
#include <string>
#define H 12
#define W 12

using namespace std;

// 島情報と到達情報
bool island[H][W];
bool arrived[H][W];

// (x,y)が島&&到達済みでないかどうか、ついでに陸続きのマスを到達済みにする
bool is_not_arrived(int x, int y) {
	if(x<0 || W<=x || y<0 || H<=y) return false;

	if(island[y][x] && !arrived[y][x]) {
		// マスにフラグ立てる
		arrived[y][x] = true;
		// 4方向の陸続き判定(返り値は使わない)
		is_not_arrived(x+1,y);
		is_not_arrived(x-1,y);
		is_not_arrived(x,y+1);
		is_not_arrived(x,y-1);
		// 陸&&到達済みじゃなかったのでtrue確定
		return true;
	}

	// 陸じゃないか到達済みなのでfalse
	return false;
}

int main() {
	while(true) {
		// 各HごとのWの情報
		for(int i = 0; i < H; i++) {
			string s;
			cin >> s;
			for(int j = 0; j < H; j++) {
				// 1のマスがtrue
				island[i][j] = (s[j]=='1');
				arrived[i][j] = false;
			}
		}

		// この段階でeofに来てたら処理終了
		if(cin.eof()) break;

		// 全マスについてis_not_arrivedである数を答えとする
		int ans = 0;
		for(int i = 0; i < H; i++) {
			for(int j = 0; j < W; j++) {
				if(is_not_arrived(j,i)) {
					ans++;
				}
			}
		}

		cout << ans << endl;
	}
}
