#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

typedef long long ll;

int gcd(int a, int b) {
	int c = a%b;
	while(c!=0) {
		a = b;
		b = c;
		c=a%b;
	}
	return b;
}

int main() {
	int n,x;
	cin >> n >> x;
	vector<int> v;
	v.push_back(x);
	for(int i = 0; i < n; i++) {
		int _x;
		cin >> _x;
		v.push_back(_x);
	}
	sort(v.begin(),v.end());
	for(int i = n; i >= 0; i--) {
		v[i] -= v[0];
	}
	int ans = -1;
	for(int i = 1; i < n; i++) {
		int res = gcd(v[i],v[i+1]);
		if(ans>0) res = gcd(ans,res);
		ans = res;
	}
	if(ans==-1) ans = v[1];
	cout << ans << endl;
	return 0;
}
