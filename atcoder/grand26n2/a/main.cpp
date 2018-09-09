#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int pre = 0;
	int c = 0;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if(pre!=a) {
			c = 0;
		}else {
			c++;
			if(c%2==1) ans++;
		}
		pre = a;
	}
	cout << ans << endl;
}
