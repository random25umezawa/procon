#include <iostream>
#include <unordered_map>
#include <vector>
//#define MOD 1000000007LL

typedef long long ll;

using namespace std;

int main() {
	ll n,m;
	cin >> n >> m;
	unordered_map<ll,ll> mp;
	vector<ll> ar;
	ll ts = 0;
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		ll a;
		cin >> a;
		if(a%m==0) ans += 1;
		/*
		ll _index = (ts+(a%MOD))%MOD;
		if(mp[_index]>0) ans += mp[_index];
		*/
		ll _index = (m+m-(ts+a)%m)%m;
		if(mp[_index]>0) ans += mp[_index];

		for(int j = 0; j < ar.size(); j++) {
			ar[j] = (ar[j]+a)%m;
			if(ar[j]==0) ans += 1;
		}
		ar.push_back(a);
		ts+=a;

		if(i!=0&&i%987==0) {
			unordered_map<ll,ll> _mp;
			for(int j = 0; j < ar.size(); j++) {
				_mp[(ar[j]%m)] += 1;
			}
			for(pair<ll,ll> num : mp) {
				_mp[(num.first+ts)%m] += num.second;
				//cout << num.first << "," << num.second << endl;
			}
			mp.swap(_mp);
			//cout << "gegegege" << endl;
			vector<ll> _ar;
			ar.swap(_ar);
			ts = 0;
		}
	}
	cout << ans << endl;
}
