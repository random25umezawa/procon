#include <iostream>
using namespace std;
typedef long long ll;

ll n,m,a,b;
int arr[100];

int main() {
	cin >> n >> m >> a >> b;

	for(int i = 0; i < n; i++) arr[i] = b;

	for(int i = 0; i < m; i++) {
		int l,r;
		cin >> l >> r;
		for(int j = l-1; j < r; j++) {
			arr[j] = a;
		}
	}

	int ans = 0;
	for(int i = 0; i < n; i++) ans += arr[i];

	cout << ans << endl;
}
