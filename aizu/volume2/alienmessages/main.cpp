#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef unordered_map<ll,bool> ump;

int w,h;
bool mp[7][7]{};

int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

bool calc(int x, int y, int sx, int sy, int rest_count, ll arrived, ump &_ump) {
	//cout << x << y << endl;
	rest_count--;
	arrived |= (1<<(y*w+x));
	for(int _d = 0; _d < 4; _d++) {
		int dx = x+dir[_d][0];
		int dy = y+dir[_d][1];
		ll arrived_d = arrived+((ll)_d<<50)+((ll)x<<54)+((ll)y<<58);
		if(!(0<=dx&&dx<w&&0<=dy&&dy<h)) continue;
		if(dx==sx&&dy==sy&&rest_count==0) return true;
		if(!(mp[dx][dy]&&!_ump[arrived_d])) continue;
		_ump[arrived_d] = true;
		bool res = calc(dx,dy,sx,sy,rest_count,arrived,_ump);
		if(res) return true;
	}
	return false;
}

int main() {
	while(true) {
		cin >> w >> h;
		if(w==0) break;
		int sx = -1, sy = -1;
		int cell_count = 0;
		for(int j = 0; j < h; j++) {
			for(int i = 0; i < w; i++) {
				cin >> mp[i][j];
				mp[i][j] = !mp[i][j];
				if(mp[i][j]) {
					cell_count++;
					sx = i;
					sy = j;
				}
			}
		}
		ump _ump(1<<20);
		bool ans = ((sx!=-1) && (cell_count%2==0));
		if(ans) ans = calc(sx,sy,sx,sy,cell_count,0,_ump);
		cout << ((ans)?"Yes":"No") << endl;
	}
	return 0;
}
