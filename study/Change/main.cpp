#include <iostream>
#include <queue>

using namespace std;

int changes[6]{500,100,50,10,5,1};

int main() {
	int a;
	while(true) {
		cin >> a;
		if(a==0) break;

		int oturi = 1000-a;

		int ans = 0;

		for(int i = 0; i < 6; i++) {
			int coin = changes[i];
			while(oturi-coin>=0) {
				oturi -= coin;
				ans++;
			}
		}

		cout << ans << endl;
	}
}
