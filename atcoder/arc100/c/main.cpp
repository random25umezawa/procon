#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int n;
vector<ll> arr;
vector<ll> ans_arr;

ll calc(ll b) {
	ll ret = 0;
	for(int i = 0; i < n; i++) {
		ret += abs(arr[i]-b);
	}
	return ret;
}

void dev2(ll l, ll r) {
	ll c = (l+r)/2;
	ll lr = calc(l);
	ll cr = calc(c);
	ll rr = calc(r);
	ans_arr.push_back(lr);
	ans_arr.push_back(cr);
	ans_arr.push_back(rr);
	if(l-r<2) return;
	if(lr-calc(l+1)>0L&&calc(r-1)-rr>0L) {
		dev2(l,c);
		dev2(c,r);
	}
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		ll a;
		cin >> a;
		arr.push_back(a-i);
	}
	sort(arr.begin(),arr.end());
	{
		ll first = arr[0];
		for(int i = 0; i < n; i++) {
			arr[i] -= first;
		}
	}
	dev2(arr[0],arr[n-1]);
	sort(ans_arr.begin(),ans_arr.end());
	cout << ans_arr[0] << endl;
}
