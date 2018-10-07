#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n,t;
	cin >> n >> t;
	vector<int> arr;
	for(int i = 0; i < n; i++) {
		int c,_t;
		cin >> c >> _t;
		if(_t>t) continue;
		arr.push_back(c);
	}
	if(arr.size()<=0) {
		cout << "TLE" << endl;
		return 0;
	}
	sort(arr.begin(),arr.end());
	cout << arr[0] << endl;
	return 0;
}
