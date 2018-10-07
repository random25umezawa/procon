#include <stdio.h>
#include <iostream>
#include <complex>
#include <cmath>
#define prt(cplx) printf("%.8lf %.8lf\n",cplx.real(),cplx.imag())

using namespace std;

typedef complex<double> P;

void draw(P p1, P p2, int depth) {
	if(depth<=0) {
		prt(p1);
		return;
	}

	P _p = (p2-p1);

	P s = p1+_p*1.0/3.0;
	P t = p1+_p*2.0/3.0;

	P _v = _p * P(0,1);
	_v = _v*sqrt(3.0)/6.0;

	P u = p1 + _p/2.0 + _v;

	draw(p1,s ,depth-1);
	draw(s ,u ,depth-1);
	draw(u ,t ,depth-1);
	draw(t ,p2,depth-1);
}

int main() {
	int n;
	cin >> n;
	draw(P(0,0),P(100,0),n);
	prt(P(100,0));
	return 0;
}
