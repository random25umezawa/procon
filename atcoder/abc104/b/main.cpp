#include <iostream>
#include <string>

using namespace std;

int main() {
	string a;
	cin >> a;
	if(a.at(0)=='A') {
		int ac = 0, cc=0;
		ac++;
		for(int i = 2; i < a.size()-1; i++) {
			if(a.at(i)=='A') ac++;
			else if(a.at(i)=='C') cc++;
			else if(a.at(i)<'A') {
				cout << a.at(i) << "WA" << endl;
				return 0;
			}
		}
		if(ac==1&&cc==1) {
			if(a.at(1)>'Z' && a.at(a.size()-1)>'Z') {
				cout << "AC" << endl;
				return 0;
			}
		}
	}
	cout << "WA" << endl;
}
