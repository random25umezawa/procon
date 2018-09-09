#include <iostream>
using namespace std;
typedef long long ll;

ll n,k;

int main() {
	cin >> n >> k;

	ll a = 0, b = 0;

	for(int i = 1; i <= n; i++) {
		if(i%k==0) a++;
		if(k%2==0 && i%k==k/2) b++;
	}

	ll ans = a*a*a+b*b*b;

	cout << ans << endl;
}
