#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n,k;
ll arr[100001];

int main() {
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	ll ans = (1LL<<30);

	for(int i = 0; i <= n-k; i++) {
		int _min = min(abs(arr[i]),abs(arr[i+k-1]));
		ll len = arr[i+k-1]-arr[i];
		ans = min(ans,len+_min);
		//cout << "----" << endl;
	}

	if(ans==(1LL<<30)) ans = 0;

	cout << ans << endl;
}
