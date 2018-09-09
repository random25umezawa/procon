#include <string>

using namespace std;

string str;
int cursor = 0;

int check(int _count) {
	while(cursor<str.length()&&)
	int count = 0;
	if(cursor >= str.len()) return false;
	if(str[cursor]=='(') {
		cursor++;
		int flag = check();
	}
	if(str[cursor]==')') {
		cursor++;
		count++;
	}
	int next = check(_count+count);

}

int main() {
	cin >> str;
	while(cursor<str.length) {
		while(cursor<str.length()&&str[cursor]==')') cursor++;
		check(0);
	}
}
