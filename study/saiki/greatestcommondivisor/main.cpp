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
	// あまり
	int z = x%y;

	// あまり0ならyが答え
	if(z==0) return y;

	// そうでないならgcd(y,z)に任せて、帰ってきたやつがそのまま答え
	return gcd(y,z);
}

int main() {
	int x,y;
	cin >> x >> y;
	cout << gcd(x,y) << endl;
	return 0;
}
