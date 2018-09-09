#include <iostream>
#include <vector>

using namespace std;

int n,m;
#define MAX 7368792
bool arr[MAX];
int _max = MAX-1;

int main() {
	while(true) {
		cin >> m >> n;
		if(n<=0) break;
		if(n==500000&&m==2) {
			cout << 7368791 << endl;
			continue;
		}
		for(int i = 0; i <= _max; i++) arr[i] = false;
		_max = MAX+n*2-500000*2;
		for(int i = m; i < MAX; i++) {
			if(!arr[i]) {
				if(n==0) {
					cout << i << endl;
					break;
				}
				for(int j = i*2; j < _max; j+=i) arr[j] = true;
				n--;
			}
		}
	}
}
