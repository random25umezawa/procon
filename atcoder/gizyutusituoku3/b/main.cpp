#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	int ans1 = 0;
	for(int i = 0; i < s.size(); i++) {
		ans1 += (int)(s.at(i)-'0');
	}
	cout << ((ans1%3==0&&(s.at(s.size()-1)-'0')%2==0)?"yES":"nO") << endl;
	int ans2 = 0;
	for(int i = s.size()-1; i >= 0; i--) {
		int num = (int)(s.at(i)-'0');
		num *= ((i-s.size()+1)%2==0)?1:10;
		ans2 += num;
	}
	cout << ((ans2%11==0)?"yES":"nO") << endl;
}
