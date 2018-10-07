#include <iostream>

using namespace std;

int n,s;

int calc(int start, int count, int sum, int ans) {
	for(int i = start; i <= 9; i++) {
		ans += calc(i,count+1,sum+)
	}

	return ans;
}

int main() {
	while(!eof()) {
		cin >> n >> s;

		int ans = calc(0,0,0,0);

		cout << ans << endl;
	}
}
