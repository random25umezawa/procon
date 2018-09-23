#include <iostream>
using namespace std;
typedef long long ll;

ll n,k;

int main() {
	int a,b,c,s;
	cin >> a >> b >> c;
	cin >> s;

	bool flag = (a+b+c<=s);
	flag &= (a+b+c+3>=s);

	cout << ((flag)?"Yes":"No") << endl;
}
