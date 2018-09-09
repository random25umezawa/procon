#include <iostream>

typedef long long ll;

using namespace std;

int main() {
	int n;
	ll p;
	cin >> n >> p;
	int arr[100000];
	for(int i = 0; i < n; i++) cin >> arr[i];
	ll ans = 1;
	int l = 0;
	int r = 0;
	while(r<n) {
		while(ans<p&&r<n) {
			ans *= arr[r];
			r++;
		}
		while(ans>p&&l<n) {
			ans /= arr[l];
			l++;
		}
		if(ans==p) {
			cout << "Yay!" << endl;
			return 0;
		}
	}
	cout << ":(" << endl;
	return 0;
}
