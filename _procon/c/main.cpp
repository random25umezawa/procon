#include <string>
#include <iostream>
typedef long long ll;

using namespace std;

string str;
int cursor = 0;
ll ans = 0;

int check() {
	//cout << "cursor=" << cursor << endl;
	//int pre_cursor = cursor;
	int count = 0;
	while(cursor<str.length()&&str[cursor]=='(') {
		cursor++;
		int flag = check();
		if(flag>0&&str[cursor-1]==')') {
			count++;
		}
	}
	//if(cursor<str.length()&&str[cursor]==')') {
		//cout << "return ... " << cursor << endl;
		cursor++;
		ll lc = (ll)count;
		ans += lc*(lc+1)/2;
		//cout << pre_cursor << "," << cursor << "," << count << endl;
		return 1;
	//}
	//return -1;
}

int main() {
	cin >> str;
	while(cursor<str.length()) {
		while(cursor<str.length()&&str[cursor]==')') cursor++;
		check();
	}
	cout << ans << endl;
}
