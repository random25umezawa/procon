#include <iostream>
#include <string>

using namespace std;

int main() {
	int n,a;
	cin >> n;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		cin >> a;
		ans += a;
	}
	cout << (ans-n) << endl;
}
