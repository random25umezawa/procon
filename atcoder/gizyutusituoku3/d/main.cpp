#include <iostream>

typedef long long ll;

using namespace std;

int main() {
	int h,w,q;
	cin >> h >> w >> q;
	ll sum_arr[2][2][100001]{};
	for(int i = 0; i < h; i++) {
		ll a;
		cin >> a;
		if(i>0) {
			sum_arr[0][0][i+1] = sum_arr[0][0][i];
			sum_arr[0][1][i+1] = sum_arr[0][1][i];
		}
		sum_arr[0][i%2][i+1] += a;
	}
	for(int i = 0; i < w; i++) {
		ll a;
		cin >> a;
		if(i>0) {
			sum_arr[1][0][i+1] = sum_arr[1][0][i];
			sum_arr[1][1][i+1] = sum_arr[1][1][i];
		}
		sum_arr[1][i%2][i+1] += a;
	}
	/*
	for(int i = 0; i <= h; i++) {
		cout << sum_arr[0][0][i] << "," << sum_arr[0][1][i] << endl;
	}
	cout << "------" << endl;
	for(int i = 0; i <= w; i++) {
		cout << sum_arr[1][0][i] << "," << sum_arr[1][1][i] << endl;
	}
	cout << "------" << endl;
	*/
	for(int i = 0; i < q; i++) {
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		a--;b--;
		ll ans = 0;
		ans += (sum_arr[0][0][a]-sum_arr[0][0][c]) * (sum_arr[1][0][b]-sum_arr[1][0][d]);
		//cout << ans << endl;
		ans -= (sum_arr[0][0][a]-sum_arr[0][0][c]) * (sum_arr[1][1][b]-sum_arr[1][1][d]);
		//cout << ans << endl;
		ans -= (sum_arr[0][1][a]-sum_arr[0][1][c]) * (sum_arr[1][0][b]-sum_arr[1][0][d]);
		//cout << ans << endl;
		ans += (sum_arr[0][1][a]-sum_arr[0][1][c]) * (sum_arr[1][1][b]-sum_arr[1][1][d]);
		cout << ans << endl;
	}
}
