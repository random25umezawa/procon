#include <iostream>

using namespace std;

int n;

int main() {
	cin >> n;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		ans += a;
	}
	cout << ans << endl;
}
