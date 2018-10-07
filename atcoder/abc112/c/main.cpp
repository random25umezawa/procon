#include <iostream>
#include <algorithm>

using namespace std;

int arr_x[100],arr_y[100],arr_h[100];

bool is_ok(int cx, int cy, int ch, int x, int y, int h) {
	int calced_h = max(ch-abs(cx-x)-abs(cy-y),0);
	return h == calced_h;
}

int get_h(int cx, int cy, int x, int y, int h) {
	int dist = abs(cx-x)+abs(cy-y);
	return h+dist;
}

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> arr_x[i] >> arr_y[i] >> arr_h[i];
	}
	for(int cx = 0; cx <= 100; cx++) {
		for(int cy = 0; cy <= 100; cy++) {
			int ch = -1;
			for(int i = 0; i < n; i++) {
				if(arr_h[i]>0) {
					ch = get_h(cx,cy,arr_x[i],arr_y[i],arr_h[i]);
					break;
				}
			}
			//cout << "ch = " << ch << endl;
			bool flag = true;
			for(int i = 0; i < n; i++) {
				flag &= is_ok(cx,cy,ch,arr_x[i],arr_y[i],arr_h[i]);
			}
			if(flag) {
				cout << cx << " " << cy << " " << ch << endl;
				return 0;
			}
		}
	}
	return 0;
}
