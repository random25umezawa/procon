#include <iostream>
#include <string>

using namespace std;

string s;
int w;

int main() {
	cin >> s >> w;
	for(int i = 0; i < s.size(); i+=w) {
		cout << s.at(i);
	}
	cout << endl;
}
