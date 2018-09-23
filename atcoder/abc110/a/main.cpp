#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int a,b,c;
	cin >> a >> b >> c;
	int ans = a+b+c;
	ans += max(a,max(b,c))*9;
	cout << ans <<endl;
}
