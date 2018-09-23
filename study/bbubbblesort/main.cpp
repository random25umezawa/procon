#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> arr,arr2;
	vector<int> left,right;
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
		if(i%2==0) left.push_back(a);
		else right.push_back(a);
	}

	sort(arr.begin(),arr.end());
	sort(left.begin(),left.end());
	sort(right.begin(),right.end());
	for(int i = 0; i < n; i++) {
		if(i%2==0) arr2.push_back(left[i/2]);
		else arr2.push_back(right[i/2]);
	}
/*
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " : " << arr2[i] << endl;
	}
*/
	int ans = 0;

	for(int i = 0; i < n; i++) {
		int pos = lower_bound(arr.begin(),arr.end(),arr2[i]) - arr.begin();
//		cout << pos << endl;
		if(pos>i) ans += ((pos-i)%2!=0)?1:0;
	}

	cout << ans << endl;

	return 0;
}
