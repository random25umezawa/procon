#include <iostream>

typedef long long ll;

using namespace std;

int t;

ll gdb(ll a, ll b) {
	ll c = a%b;
	while(c!=0) {
		a = b;
		b = c;
		c = a%b;
	}
	return b;
}

int main() {
	cin >> t;
	for(int i = 0; i < t; i++) {
		ll a,b,c,d;
		cin >> a >> b >> c >> d;
		if(a<b) {
			cout << "No" << endl;
			continue;
		}
		if(a>c) {
			a -= ((a-c)/b)*b;
			while(a>c&&a-b>0) a-=b;
		}
		//cout << a << endl;
		if(b==d) {
			if(a>c&&a-b<0) {
				cout << "No" << endl;
				continue;
			}
			else {
				cout << "Yes" << endl;
				continue;
			}
		}else {
			if(b<d) {
				if(d%b==0) {
					if(a>c&&a-b<0) {
						cout << "No" << endl;
						continue;
					}
					else {
						cout << "Yes" << endl;
						continue;
					}
				}else {
					ll e = d-b;
					a += ((c-a)/e)*e;
					while(a<=c) a += e;
					//cout << a << endl;
					if(a>=b) {
						cout << "Yes" << endl;
						continue;
					}else {
						cout << "No" << endl;
						continue;
					}
				}
			}
		}
		cout << "No" << endl;
		continue;
	}
}
