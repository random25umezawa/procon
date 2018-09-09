#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;

using namespace std;
int n,q;
int x[100000];
int cd[100000][2];
vector<ll> arr;
ll ans[100000];

int main() {
	cin >> n >> q;
	for(int i = 0; i < n; i++) cin >> x[i];
	for(int i = 0; i < q; i++) {
		int c;
		int d;
		cin >> cd[i][0] >> d[i][1];
	}
	sort(arr.begin(),arr.end());

	for(int i = 0; i < n; i++) {
		int _x = x[i];
		int _d = d[i];
		upper_bound(arr.begin(),arr.end());
	}
}
