#include <iostream>

using namespace std;

int dp[1001]{};

int main() {
	int d,g;
	cin >> d >> g;
	g/=100;
	for(int i = 0; i < d; i++) {
		int p,c;
		cin >> p >> c;
		c/=100;
		for(int k = 1000; k > 0; k--) {
			int _m = 0;
			for(int j = 1; k-j>=0 && j<=p; j++) {
				int _sc = dp[k-j]+(i+1)*j;
				if(j==p) _sc += c;
				_m = max(_m,_sc);
			}
			dp[k] = max(dp[k],_m);
		}
	}
	for(int i = 0; i <= 1000; i++) {
		if(dp[i]>=g) {
			cout << i << endl;
			return 0;
		}
	}
}
