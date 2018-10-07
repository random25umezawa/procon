#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

typedef pair<int,int> P;

int n;

int main() {
	cin >> n;

	unordered_map<int,int> mp[2];
	vector<P> vr[2];

	for(int i = 0; i < n; i++) {
		int v;
		cin >> v;
		mp[i%2][v]++;
	}

	for(P p : mp[0]) vr[0].push_back(P(p.second,p.first));
	for(P p : mp[1]) vr[1].push_back(P(p.second,p.first));
	vr[0].push_back(P(0,0));
	vr[1].push_back(P(0,0));
	sort(vr[0].begin(),vr[0].end(),greater<P>());
	sort(vr[1].begin(),vr[1].end(),greater<P>());

	if(vr[0][0].second!=vr[1][0].second) {
		cout << (n-(vr[0][0].first+vr[1][0].first)) << endl;
	}else {
		int res = max((vr[0][0].first+vr[1][1].first),(vr[0][1].first+vr[1][0].first));
		cout << (n-res) << endl;
	}

	return 0;
}
