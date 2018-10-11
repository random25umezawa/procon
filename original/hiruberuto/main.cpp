#include <iostream>

using namespace std;

int x_arr[16] = {0,0,1,1,2,3,3,2,2,3,3,2,1,1,0,0};
int y_arr[16] = {0,1,1,0,0,0,1,1,2,2,3,3,3,2,2,3};
int dir_arr[16] = {0,1,1,2,1,0,0,3,1,0,0,3,2,3,3,0};

int main() {
	while(true) {
		int n;
		cin >> n;
		if(n<0) break;

		int x = 0;
		int y = 0;

		int size = 1;

		while(size*size<=n) {
			int index = (n/(size*size))%16;
			int _x = x_arr[index];
			int _y = y_arr[index];
			cout << index << "," << _x << "," << _y << "," << ((n/(size*size*16))%16) << endl;

			int _z;
			switch(dir_arr[(n/(size*size*16))%16]) {
				case 1:
					_z = _y;
					_y = _x;
					_x = _z;
					break;
				case 2:
					_x = 3-_x;
					_y = 3-_y;
					break;
				case 3:
					_z = _x;
					_x = 3-_y;
					_y = 3-_z;
					break;
			}

			x += _x*size;
			y += _y*size;
			
			//n -= index*size*size;

			cout << "n=" << n << " -> " << size << endl;
			cout << x << " " << y << endl;
			size*=4;
		}

		//cout << x << " " << y << endl;
	}
}