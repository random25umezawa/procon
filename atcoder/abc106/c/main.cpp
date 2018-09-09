#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

int main() {
	string s;
	ll k;
	cin >> s >> k;
	for(int i = 1; i <= s.size(); i++) {
		if((int)(s.at(i-1)-'1') > 0 || i==k) {
			cout << s.at(i-1) << endl;
			return 0;
		}
	}
	cout << 1 << endl;
	return 0;
}
