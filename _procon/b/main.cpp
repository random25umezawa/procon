#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;

using namespace std;
int n,q;
vector<int> x;
int cd[100000][2];
ll sum_arr[100000];

int main() {
	cin >> n >> q;
	for(int i = 0; i < n; i++) {
		int _x;
		cin >> _x;
		x.push_back(_x);
	}
	sum_arr[0] = x[0];
	for(int i = 1; i < n; i++) {
		sum_arr[i] = x[i]+sum_arr[i-1];
	}
	for(int i = 0; i < q; i++) {
		int c;
		int d;
		cin >> cd[i][0] >> cd[i][1];
	}
	sort(x.begin(),x.end());

	for(int i = 0; i < q; i++) {
		int c = cd[i][0];
		int d = (ll)cd[i][1];
		int left = distance(x.begin(),lower_bound(x.begin(),x.end(),c-d));
		int center = distance(x.begin(),lower_bound(x.begin(),x.end(),c));
		int right = distance(x.begin(),lower_bound(x.begin(),x.end(),c+d+1));
		//cout << left << "," << center << "," << right << endl;
		ll ans = 0;
		ll lc = (ll)c;
		ll ld = (ll)d;
		ans += ld*left;
		//cout << ans <<endl;
		//cout << lc << "," << sum_arr[center-1] << "," << sum_arr[left-1] << endl;
		ans += lc*(center-left)-(sum_arr[center-1]-sum_arr[left-1]);
		//cout << ans <<endl;
		ans += (sum_arr[right-1]-sum_arr[center-1])-lc*(right-center);
		//cout << ans <<endl;
		ans += ld*(n-right);
		cout << ans << endl;
		//cout <<endl;
	}
}
