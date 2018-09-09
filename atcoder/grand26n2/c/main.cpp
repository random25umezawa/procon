#include <iostream>
#include <string>
#include <unordered_map>

typedef long long ll;

using namespace std;

int n;
string s;
ll ans = 0;

unordered_map<ll,ll> dp;

ll make_bit(ll bits, int index, char c, bool rev) {
	bits |= (1<<index);
	for(int i = 0; i < s.size(); i++) {
		int l = (rev)?s.size()-i-1:i;
		if(bits&(1<<l)==0&&s.at(l)==c) {
			bits |= (1<<l);
			for(int j = 0; j < s.size(); j++) {
				int k = (rev)?s.size()-j-1:j;
				if(k==l) break;
				ll ret = make_bit(bits,k,s.at(k),!rev);
			}
		}
	}
}

ll calc(ll bits) {
	if(dp[bits]==-1) return 0;
	if(dp[bits]>0) return dp[bits];
	for(int i = s.size()-1; i >= 0; i--) {
		if(bits&(1<<i)==0) {
			make_bit(bits,i,s.at(i),true);
		}
	}
}

int main() {
	cin >> n >> s;
	calc(0);
}
