#include <iostream>

using namespace std;

typedef long long ll;

int calced_keta = -1;

void calc(ll n) {
	ll keta = 1;
	ll p = 1;
	ll edge = 0;
	ll max_edge = 0;

	//cout << endl;
	if(n!=0) {
		while(true) {
			//cout << n << "," << keta << "," << p << "," << edge << "," << max_edge << endl;
			edge = max_edge+p*((keta%2LL==1LL)?1LL:-1LL);
			if(edge>0LL) {
				max_edge = edge+p;
				if(edge<=n&&n<max_edge) break;
			}else {
				max_edge = edge-p;
				if(max_edge<=n&&n<edge) break;
			}

			keta++;
			p *= 2LL;
			//if(keta>10) return;
		}
	}

	if(calced_keta==-1LL) {
	}else {
		for(int i = calced_keta-1LL; i > keta; i--) {
			cout << '0';
		}
	}
	cout << ((n==0LL)?'0':'1');
	calced_keta=keta;

	//cout << n << "," << p << "," << keta << endl;
	if(keta>1LL) calc(n+p*((keta%2LL==0)?1LL:-1LL));
	else {
		cout << endl;
	}
}

int main() {
	ll n;
	cin >> n;
	calc(n);
}
