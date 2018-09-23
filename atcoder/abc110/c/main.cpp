#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string s1,s2;
	cin >> s1 >> s2;
	bool flag = true;
	bool appeared[255]{};
	for(char c = 'a'; c <= 'z'; c++) {
		char s2c = '\0';
		for(int i = 0; i < s1.size(); i++) {
			if(c==s1[i]) {
				if(s2c=='\0') {
					s2c=s2[i];
					flag &= !(appeared[s2[i]]);
					appeared[s2[i]] = true;
				}
				else {
					flag &= s2c==s2[i];
				}
			}
		}
	}
	cout << ((flag)?"Yes":"No") << endl;
}
