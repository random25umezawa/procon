#include <iostream>
#include <algorithm>

using namespace std;

int n,m,t,p;
int arr[1000][1000]{};

int main() {
	while(true) {
		cin >> n >> m >> t >> p;
		if(n<=0) break;
		int l=0,b=0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				arr[i][j] = 1;
			}
		}
		for(int i = 0; i < t; i++) {
			int d,c;
			cin >> d >> c;
			if(d==1) {
				for(int j = b; j < m; j++) {
					for(int k = 0; k < c; k++) {
						arr[l+c*2-k-1][j] += arr[l+k][j];
					}
				}
				l+=c;
				n=max(n,l+c*2);
			}else {
				for(int j = l; j < n; j++) {
					for(int k = 0; k < c; k++) {
						arr[j][b+c*2-k-1] += arr[j][b+k];
					}
				}
				b+=c;
				m=max(m,b+c*2);
			}
		}
		/*
		cout << l << "," << b << "," << n << "," << m << endl;
		for(int j = b; j < m; j++) {
			for(int i = l; i < n; i++) {
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
		*/
		for(int i = 0; i < p; i++) {
			int x,y;
			cin >> x >> y;
			cout << arr[l+x][b+y] << endl;
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				arr[i][j] = 0;
			}
		}
	}
}
