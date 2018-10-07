#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n,m;
	cin >> n >> m;

	if(m%n==0) {
		cout << (m/n) << endl;
		return 0;
	}

	vector<int> arr;
	for(int i = 2; i < 100000; i++) {
		if(m%i==0) {
			arr.push_back(i);
			arr.push_back(m/i);
		}
		if(i*i>m) break;
	}

	int ans = 1;

	for(int num : arr) {
		int _var = m/num;
		if(_var>n) {
			ans = max(ans,num);
		}
	}

	cout << ans << endl;

	return 0;
}
