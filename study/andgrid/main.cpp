#include <iostream>
#include <vector>
#include <string>

using namespace std;

int h,w;
bool mp[500][500] = {};
bool arrived[500][500] = {};
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

bool dfs(int y, int x, bool tmp_arr[500][500]) {
	if(!(x>0&&x<w-1&&y>0&&y<h-1)) return false;
	if(tmp_arr[y][x]) return false;
	tmp_arr[y][x] = true;
	if(mp[y][x]) return true;
	for(int i = 0; i < 4; i++) {
		int dx = x+dir[i][0];
		int dy = y+dir[i][1];
		bool flg = dfs(dy,dx,tmp_arr);
		if(flg) {
			arrived[y][x] = true;
			return true;
		}
	}
}

int main() {
	cin >> h >> w;

	int scount = 0;

	for(int i = 0; i < h; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < w; j++) {
			mp[i][j] = (s.at(j)=='#');
			scount += (s.at(j)=='#')?1:0;
		}
	}

	for(int i = 1; i < h-1; i++) {
		for(int j = 1; j < w-1; j++) {
			bool tmp_arr[500][500] = {};
			dfs(i,j,tmp_arr);
		}
	}

	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			bool flag = false;
			flag |= arrived[i][j];
			flag |= mp[i][j];
			cout << ((flag)?'#':'.');
		}
		cout << endl;
	}

	cout << endl;

	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			bool flag = false;
			flag |= !arrived[i][j];
			flag |= mp[i][j];
			cout << ((flag)?'#':'.');
		}
		cout << endl;
	}

}
