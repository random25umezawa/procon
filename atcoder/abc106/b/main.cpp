#include <iostream>

using namespace std;

int main() {
	int a;
	cin >> a;
	int ans = 0;
	for(int i = 105; i <= a; i++) {
		if(i%2==0) continue;
		int cnt = 0;
		for(int j = 1; j <= i; j++) {
			if(i%j==0) cnt++;
		}
		if(cnt==8) ans++;
	}
	cout << ans << endl;
}
