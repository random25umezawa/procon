#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main(){
	cin >> n;
	vector<int> arr;
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}
	for(int size = 1; size <= n; size++) {
		vector<int> centers;
		for(int count = 1; count < (1<<size); count++) {
			vector<int> tmp;
			for(int i = 0; i < size; i++) {
				if((count&(1<<i))!=0) {
					tmp.push_back(arr[i]);
				}
			}
			cout << tmp[tmp.size()/2] << endl;
			centers.push_back(tmp[tmp.size()/2]);
		}
		sort(centers.begin(),centers.end());
		cout << size << " : " << centers[centers.size()/2] << "," << centers.size() << endl;
	}
}
