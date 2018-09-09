#include <iostream>
#include <string>

using namespace std;

int main() {
	string a,b;
	cin >> a >> b;
	bool flag = false;
	for(int i = 0; i < a.size(); i++) {
		bool flag2 = true;
		for(int j = 0; j < a.size(); j++) {
			int k = (i+j)%a.size();
			flag2 = flag2 && (a.at(k)==b.at(j));
		}
		flag = flag || flag2;
	}
	cout << ((flag)?"Yes":"No") << endl;
}
