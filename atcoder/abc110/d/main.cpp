#include <iostream>
#include <unordered_map>
#define MOD 1000000007LL
#define P_SIZE 123456

typedef long long ll;

using namespace std;

ll p[P_SIZE], p_inv[P_SIZE];

ll pow(ll x, ll n) { //x^n 計算量O(logn)
	ll ans = 1;
	while (n > 0) {
		if ((n & 1) == 1) {
			ans = ans * x;
			ans %= MOD;
		}
		x = x * x; //一周する度にx, x^2, x^4, x^8となる
		x %= MOD;
		n >>= 1; //桁をずらす n = n >> 1
	}
	return ans;
}

void calc_p() {
	p[0] = 1;
	p[1] = 1;
	for(int i = 2; i < P_SIZE; i++) {
		p[i] = (p[i-1]*(ll)i)%MOD;
	}
	p_inv[0] = 1;
	for(int i = 1; i < P_SIZE; i++) {
		p_inv[i] = (pow(p[i],MOD-2))%MOD;
	}
}

ll combination(ll a, ll b) {
	ll ans = 1;
	ans *= p[a];
	ans *= p_inv[a-b];
	ans %= MOD;
	ans *= p_inv[b];
	ans %= MOD;
	return ans;
}

int main() {
	ll n,m;
	cin >> n >> m;
	calc_p();
	unordered_map<int,ll> mp;
	while(m>1) {
		int loop_max = m;
		for(int i = 2; i <= loop_max; i++) {
			if(m%i==0) {
				mp[i]++;
				m /= i;
				break;
			}
			//loop_max = m/i;
			if(i*i>m) {
				mp[m]++;
				m=1;
				break;
			}
		}
	}

	ll ans = 1;

	for(pair<int,ll> pr : mp) {
		//cout << n << "," << pr.second << endl;
		//if(pr.second==1LL) ans *= n;
		ans *= combination(n-1+pr.second,pr.second);
		ans %= MOD;
		//cout << ans << endl;
	}

	cout << ans << endl;

	return 0;
}
