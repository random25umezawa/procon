#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n,k;
ll arr[100001];

int main() {
	cin >> n >> k;
	ll sum = 0LL;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sum = arr[k-1]-arr[0];

	ll ans = (1LL<<30);

	for(int i = 0; i < n-k; i++) {
		int _min = min(abs(arr[i]),abs(arr[i+k-1]));
		ans = min(ans,sum+_min);
		sum -= arr[i];
		sum += arr[i+k];
	}

	cout << ans << endl;
}
