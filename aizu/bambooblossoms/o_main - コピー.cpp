#include <iostream>
#include <vector>

using namespace std;

int n,m;
#define MAX 7368792
#define NUM 5

int main() {
	while(true) {
		cin >> m >> n;
		if(n<=0) break;
		int arr[MAX]{};
		int count = 0;
		vector<int> prms;
		for(int i = m; i < MAX; i++) {
			m = i;
			bool flag = arr[i]==0;
			if(flag) {
				for(int prm : prms) flag &= m%prm!=0;
				if(flag) {
					if(count>=n) break;
					count++;
					if(prms.size()<=NUM) {
						prms.push_back(m);
					}else {
						for(int j = 1; j*m<MAX; j++) {
							arr[j*m] = 1;
						}
					}
					m++;
				}
			}
		}
		cout << m << endl;
	}
}
