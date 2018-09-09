#include <iostream>

using namespace std;

void calc(int a) {
	int _a = a;
	if(a<0) {
		a*=-1;
		a-=1;
	}
	int p = 1;
	while(a>p) {
		p*=2;
	}
	calc()
}

int main() {
	int n;
	cin >> n;
	calc(n)
}
