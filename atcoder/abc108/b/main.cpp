#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	int n;
	cin >> n;
	map<string,bool> m;
	char c = '\0';
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if(m[s]) {
			cout << "No" << endl;
			return 0;
		}
		m[s] = true;
		if(c!='\0'&&c!=s.at(0)) {
			cout << "No" << endl;
			return 0;
		}
		c = s.at(s.size()-1);
	}
	cout << "Yes" << endl;
	return 0;
}
