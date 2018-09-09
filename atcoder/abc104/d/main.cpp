#include <iostream>
#include <string>

typedef long long ll;

using namespace std;

ll dp[3]{};

int main() {
	string a;
	cin >> a;
	ll ans = 0;
	ll three = 1;
	for(int i = 0; i < a.size(); i++) {
		switch(a.at(i)) {
			case 'A':
				dp[0]+=three;
				break;
			case 'B':
				dp[1]+=dp[0];
				break;
			case 'C':
				dp[2] += dp[1];
				break;
			case '?':
				ll _dp[3];
				for(int i = 0; i < 3; i++) {
					_dp[i] = dp[i];
					dp[i] = _dp[i]*3LL;
				}
				dp[2] += _dp[1];
				dp[1] += _dp[0];
				dp[0] += three;
				three = (three*3LL)%1000000007LL;
				break;
		}
		for(int i = 0; i < 3; i++) {
			dp[i] %= 1000000007LL;
		}
		//cout << dp[0] << "," << dp[1] << "," << dp[2] << endl;
	}
	cout << dp[2] << endl;
}
