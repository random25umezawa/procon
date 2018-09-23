#include <stdio.h>
#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef long long ll;

long n;
int m;
ll tp[1<<18];
double ta[1<<18],tb[1<<18];

double seg[1 << 18][2];
int size;

void init(int _n)
{
	size = 1;
	while (size < _n) size *= 2;
}

void mix(double la, double lb, double lc, double ld, double *_a, double *_b) {
	*_a = la*lc;
	*_b = lb*lc+ld;
}

void update(int k, double x, double y)
{
	k += size - 1;
	seg[k][0] = x;
	seg[k][1] = y;

	while (k){
		k = (k - 1) / 2;
		mix(seg[k * 2 + 1][0], seg[k * 2 + 1][1], seg[k * 2 + 2][0], seg[k * 2 + 2][1], &seg[k][0],&seg[k][1]);
	}
}

void getAll(int a, int b, int k, int l, int r, double *_a, double *_b)
{
	if (r <= a || b <= l){
		*_a = 1;
		*_b = 0;
		return;
	}

	if (a <= l && r <= b){
		*_a = seg[k][0];
		*_b = seg[k][1];
		return;
	}
	double la,lb,ra,rb;
	getAll(a, b, k * 2 + 1, l, (l + r) / 2, &la,&lb);
	getAll(a, b, k * 2 + 2, (l + r) / 2, r, &ra,&rb);

	mix(la,lb,ra,rb,_a,_b);
	return;
}

int main() {
	cin >> n >> m;

	map<ll,int> _mp;
	for(int i = 0; i < m; i++) {
		cin >> tp[i] >> ta[i] >> tb[i];
		if(_mp[tp[i]]<=0) {
			_mp[tp[i]] = 1;
		}
	}
	int count = 0;
	unordered_map<ll,int> mp;
	for(pair<ll,int> p : _mp) {
		mp[p.first] = count;
		count++;
	}

	init(count);

	for(int i = 0; i < size; i++) {
		update(i,1,0);
	}

	double ans_min = 1;
	double ans_max = 1;
	for(int i = 0; i < m; i++) {
		update(mp[tp[i]],ta[i],tb[i]);
		double a,b;
		getAll(0,count,0,0,size,&a,&b);
		double ans = a+b;
		ans_min = min(ans_min,ans);
		ans_max = max(ans_max,ans);
	}

	printf("%.8lf\n",ans_min);
	printf("%.8lf\n",ans_max);

	return 0;
}
