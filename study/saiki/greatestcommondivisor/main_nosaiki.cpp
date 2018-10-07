#include <iostream>

using namespace std;

/*
 * x1 ÷ y1 = w1 ... z1
 * (y1,z1) => (x2,y2)
 * x2 ÷ y2 = w2 ... z2
 * ...
 * xp ÷ yp = wp ... 0
 * ans = yp
 */
int gcd(int x, int y) {
	// x%y==0になるまで続ける
	while(x%y!=0) {
		// あまり
		int z = x%y;
		// 数字入れ替え
		x = y;
		y = z;
	}

	// x%y==0なのでyが答え
	return y;
}

int main() {
	int x,y;
	cin >> x >> y;
	cout << gcd(x,y) << endl;
	return 0;
}
