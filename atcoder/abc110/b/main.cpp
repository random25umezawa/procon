#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n,m,x,y;
	cin >> n >> m >> x >> y;
	vector<int> xr(n),yr(m);
	for(int i = 0; i < n; i++) cin >> xr[i];
	for(int i = 0; i < m; i++) cin >> yr[i];
	sort(xr.begin(),xr.end());
	sort(yr.begin(),yr.end());
	bool flag = true;
	flag &= yr[0]-xr[xr.size()-1]>0;
	flag &= x<y;
	flag &= x<yr[0];
	flag &= xr[xr.size()-1]<y;
	cout << ((flag)?"No War":"War") << endl;
	return 0;
}
