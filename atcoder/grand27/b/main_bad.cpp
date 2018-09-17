#include <iostream>

typedef long long ll;

using namespace std;

int main() {
	int n;
	int x;
	cin >> n >> x;
	if(n>2000) {
		cout << "TLE" << endl;
		return 0;
	}
	ll arr[200000];
	for(int i = 0; i < n; i++) {
		cin >> arr[n-i-1];
	}

	ll ans = 1LL<<60;
	for(int i = 1; i <= n; i++) {
		ll sum = 0;
		ll gcount = 1;
		for(int j = 0; j < n; j++) {
			if(j!=0&&j%i==0) gcount++;
			ll l = arr[j];
			if(gcount==1) {
				sum += l*5LL;
			}else {
				sum += (2LL*gcount+1)*l;
			}
		}
		sum += ((ll)i)*x;
		ans = min(ans,sum);
	}

	ans += ((ll)n)*x;

	cout << ans << endl;
}
