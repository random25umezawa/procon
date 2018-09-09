#include <iostream>

using namespace std;

void calc(int n, int keta) {
	cout << n << "," << keta << endl;
	int _n = n;
	bool flag = false;
	int p = 1;

	if(n<0) {
		_n*=-1;
		_n-=1;
	}

	for(int i = 0; i < keta; i++) p*=2;
	flag = (_n>=p);

	cout << ((flag)?'1':'0');
	if(flag) {
		_n -= p;
	}
	if(n<0) {
		_n++;
		_n*=-1;
	}
	if(keta>0) calc(_n,keta-1);
	else {
		cout << endl;
	}
}

int main() {
	int n;
	cin >> n;
	int _n = n;
	int range = 2;
	int keta = 1;
	int plus = 2;
	if(_n<0) {
		_n*=-1;
		keta+=1;
		_n-=1;
	}
	while(_n>=range) {
		plus*=4;
		range+=plus;
		keta+=2;
	}
	cout << keta << endl;

	calc(n,keta-1);
}
