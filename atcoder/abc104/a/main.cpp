#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int a;
	cin >> a;
	cout << ((a<1200)?"ABC":((a<2800)?"ARC":"AGC")) << endl;
}
