#include <iostream>
#include <algorithm>

using namespace std;
int n;

int main() {
	cin >> n;
	int ans = 9999;
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		int count = 0;
		while(a%10==0) {
			count++;
			a/=10;
		}
		ans = min(ans,count);
		//cout << ans << "," << count <<endl;
	}
	cout << ((ans==9999)?0:ans) << endl;
}
