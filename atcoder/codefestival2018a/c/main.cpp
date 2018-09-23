#include <stdio.h>
#include <iostream>
#include <algorithm>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;

ll n,k;
ll a_arr[50];
ll a_b_arr[50];

ll dp[52][5000]{};

int main() {
	cin >> n >> k;
	ll count_sum = 0;
	for(int i = 0; i < n; i++) {
		ll a;
		cin >> a;
		a_arr[i] = a;
		ll count = 0;
		while(a>0LL) {
			count++;
			a>>=1;
		}
		a_b_arr[i] = count;
		count_sum += count;
		cout << count << endl;
	}
	k = min(k,count_sum);
	cout << "k=" << k << endl;

	dp[0][k-1] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < k; j++) {
			//for(int m = 0; m <= min((ll)j,a_b_arr[i-1]); m++) {
			for(int m = 0; m <= j; m++) {
				dp[i][j-m]+=dp[i-1][j];
				dp[i][j-m] %= MOD;
			}
		}
	}

	for(int i = 0; i <= n; i++) {
		for(int j = 0; j < k; j++) {
			printf("%5ld",dp[i][j]);
		}
		cout << endl;
	}

	cout << dp[n][0] << endl;
}
