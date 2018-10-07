#include <iostream>
#define MOD 1000000007LL

using namespace std;

typedef long long ll;

/*
 * hoge_pow(m,n) = {
 * 	・ (n=1)    m
 * 	・ (n%2==0) hoge_pow(m,n)^2     (mod 1000000007)
 * 	・ (n%2==1) hoge_pow(m,n)^2 * m (mod 1000000007)
 * }
 *
 */
ll hoge_pow(ll m, ll n) {
	// 乗数1ならストップ
	if(n==1) return m;

	// 乗数半分のやつ
	ll ret = hoge_pow(m,n/2);
	ret = (ret*ret)%MOD;

	// 乗数が奇数の時の端数のやつ
	if(n%2==1) {
		ret = (ret*m)%MOD;
	}

	return ret;
}

int main() {
	ll m,n;
	cin >> m >> n;
	ll ans = hoge_pow(m,n);
	cout << ans << endl;
}
