#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

typedef long long ll;

using namespace std;

int h,w;
bool field[10][10];

struct line{
	int y,x,w;
	bool isV;
};

int main() {
	while(true) {
		//input h,w
		cin >> h >> w;
		if(h==0) break;

		//input field[][]
		for(int i = 0; i < h; i++) {
			string s;
			cin >> s;
			for(int j = 0; j < w; j++) {
				field[i][j] = (s.at(j)=='#');
			}
		}

		//当たり行・列を探す
		queue<line> lines;
		for(int i = 0; i < h; i++) {
			int count = 0;
			for(int j = 0; j <= w; j++) {
				if(j < w && field[i][j]) count++;
				else {
					if(count>=3) {
						lines.push((line){i,j-count,count,false});
					}
					count = 0;
				}
			}
		}
		for(int i = 0; i < w; i++) {
			int count = 0;
			for(int j = 0; j <= h; j++) {
				if(j < h && field[j][i]) count++;
				else {
					if(count>=3) {
						lines.push((line){j-count,i,count,true});
					}
					count = 0;
				}
			}
		}

		//行・列のカーソルを進めながら探索
		queue<ll> q;
		q.push(0LL);
		while(!lines.empty()) {
			unordered_map<ll,bool> m;
			line l = lines.front();	lines.pop();
			cout << "line " << l.x << "," << l.y << "," << l.w << "," << l.isV << endl;
			int size = q.size();
			for(int loop = 0; loop < size; loop++) {
				ll bit = q.front();	q.pop();
				for(int i = 0; i < l.w; i++) {
					int x = l.x;
					int y = l.y;
					if(l.isV) y+=i;
					else x+=i;
					if((bit&(1<<(y*w+x)))==0) {
						ll newbit = (bit|(1<<(y*w+x)));
						if(!m[newbit]) {
							cout << "newbit " << newbit << endl;
							m[newbit] = true;
							q.push(newbit);
						}
					}
				}
			}
			cout << "  " << q.size() << endl;
		}

		cout << q.size() << endl;

		while(!q.empty()) {
			cout << "----------" << endl;
			ll bit = q.front();	q.pop();
			for(int i = 0; i < h*w; i++) {
				cout << (((bit&(1<<i))==0)?'0':'1');
				if(i%w==w-1) cout << endl;
			}
		}

	}
}
