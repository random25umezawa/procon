#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct req{
	int a,b;
};

const bool operator< (const req &r1, const req &r2) {
	return (r1.b==r2.b)?r1.a>r2.a:r1.b>r2.b;
}

const bool operator> (const req &r1, const req &r2) {
	return (r1.a==r2.a)?r1.b>r2.b:r1.a>r2.a;
}

int n,m;
priority_queue<req,vector<req>,greater<req> > req_q;
priority_queue<req> calc_q;

int main() {
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int a,b;
		cin >> a >> b;
		req_q.push((req){a,b});
	}

	int ans = 0;
	while(!req_q.empty()) {
		req r = req_q.top();	req_q.pop();
		//cout << r.a << "," << r.b << endl;
		if(!calc_q.empty()) {
			req c = calc_q.top();
			//cout << "  " << c.a << "," << c.b << endl;
			if(c.b<=r.a) {
				while(!calc_q.empty()) calc_q.pop();
				ans++;
			}
		}
		calc_q.push(r);
	}
	ans++;

	cout << ans << endl;
}
