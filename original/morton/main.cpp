#include <iostream>

using namespace std;

int main() {
	while(true) {
		int n;
		cin >> n;
		if(n<0) break;

		int x = 0;
		int y = 0;

		int size = 1;
		while(size*size*4<n) size*=2;

		//cout << "n = " << n << " -> ";

		while(size>0) {
			int index = n/(size*size);
			if(index%2==1) x+=size;
			if(index/2==1) y+=size;
			n -= index*size*size;
			size/=2;
		}

		cout << x << " " << y << endl;
	}
}