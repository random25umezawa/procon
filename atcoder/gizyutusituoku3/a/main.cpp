#include <iostream>
#include <string>

using namespace std;

int main() {
	string as,bs;
	int a,b;
	cin >> as >> a;
	cin >> bs >> b;
	//cout << a << b << endl;
	int c = ((as=="W")?-a:a);
	int d = ((bs=="W")?-b:b);
	//cout << c << d << endl;
	int ans = ((c-d))/15;
	cout << ((ans>0)?ans:-ans) << endl;
}
