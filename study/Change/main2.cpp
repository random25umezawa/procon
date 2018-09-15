#include <iostream>
#include <queue>

using namespace std;

int changes[6]{500,100,50,10,5,1};

int main() {
	int a;
	while(true) {
		cin >> a;
		if(a==0) break;

		int coin_count[6];
		for(int i = 0; i < 6; i++) {
			cin >> coin_count[i];
		}

		int oturi = 10000-a;

		int ans = 0;

		for(int i = 0; i < 6; i++) {
			int coin = changes[i];
			int count = coin_count[i];
			while(oturi-coin>=0 && count>0) {
				oturi -= coin;
				count--;
				ans++;
			}
		}

		cout << ans << endl;
	}
}
