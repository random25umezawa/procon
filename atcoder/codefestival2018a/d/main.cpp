#include <iostream>
#include <unordered_map>
#include <vector>

#define MOD 1000000007LL

using namespace std;

typedef long long ll;

int main(){
	ll d,f,t;
	int n;
	cin >> d >> f >> t >> n;
	vector<ll> x_arr(n);
	for(int i = 0; i < n; i++) {
		cin >> x_arr[i];
	}
	x_arr.push_back(d);

	unordered_map<ll,ll> mp(n),pre_mp(n);
	pre_mp[f] = 1;
	for(int x : x_arr) {
		cout << " " << x << endl;
		cout << pre_mp.size() << "," << mp.size() << endl;
		for(pair<ll,ll> p : pre_mp) {
			ll _f = p.first;
			ll _pattern = p.second;
				cout << "  " << _f << "," << _pattern << endl;
			if(_f-x<0LL) continue;
			if(_f-x<t) {
				mp[_f] += _pattern;
				mp[t+x] += _pattern;
			}else {
				mp[_f] += _pattern*2;
			}
		}
		pre_mp.clear();
		mp.swap(pre_mp);
	}
	cout << pre_mp.size() << "," << mp.size() << endl;
	ll ans = 0;
	for(pair<ll,ll> p : pre_mp) {
		ll _f = p.first;
		ll _pattern = p.second;
		cout << "  " << _f << "," << _pattern << endl;
		ans += p.second;
		ans %= MOD;
	}
	cout << ans << endl;
}
