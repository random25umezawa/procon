#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n,x;
	cin >> n >> x;
	vector<int> arr;
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(),arr.end());
	int ans = 0;
	for(int a : arr) {
		x-=a;
		if(x>=0) ans++;
		if(x<=0) break;
	}
	if(x>0) ans--;
	if(ans<0) ans=0;
	cout << ans << endl;
}
