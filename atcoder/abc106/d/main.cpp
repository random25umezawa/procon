#include <iostream>

typedef long long ll;

using namespace std;

#define SIZE 501

int dp[SIZE][SIZE]{};
int arr[SIZE][SIZE]{};
int sm[SIZE][SIZE]{};

int main() {
	ll n,m,q;
	cin >> n >> m >> q;
	for(int i = 0; i < m; i++) {
		int l,r;
		cin >> l >> r;
		arr[r][l]++;
	}

	for(int i = 1; i <= n; i++) {
		for(int j = i; j > 0; j--) {
			dp[i][j] = arr[i][j];
			dp[i][j] += dp[i-1][j];
			sm[i][j] = arr[i][j];
			if(j<SIZE-1) {
				sm[i][j] += sm[i][j+1];
				dp[i][j] += sm[i][j+1];
			}
		}
	}
/*
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= n; j++) {
					cout << sm[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
				for(int i = 1; i <= n; i++) {
					for(int j = 1; j <= n; j++) {
						cout << dp[i][j] << " ";
					}
					cout << endl;
				}
				cout << endl;
*/
	for(int i = 0; i < q; i++) {
		int p,_q;
		cin >> p >> _q;
		cout << dp[_q][p] << endl;
	}

	return 0;
}
