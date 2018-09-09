#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int MAX_POINTS = 100;

struct cross_point{
	int index;	//line number
	double rate;	//[0.0,1.0]
	cross_point(int _index, double _rate) {
		index = _index;
		rate = _rate;
	}
	bool operator<(const cross_point &right) const {
		return rate < right.rate;
	}
};

double cross_rate(double a, double b, double c, double d, double e, double f, double g, double h) {
	double child = (g-e)*(f-b)-(h-f)*(e-a);
	double mother = (g-e)*(d-b)-(h-f)*(c-a);
	return (mother==0.0)?-1.0:child/mother;
}

int main() {
	int n;
	scanf("%d",&n);
	while(n>0) {
		double lines[MAX_POINTS][4];
		vector<vector<cross_point> > cross_points(n);
		for(int i = 0; i < n; i++) {
			cross_points[i] = vector<cross_point>();
		}
		for(int i = 0; i < n; i++) {
			int a,b,c,d;
			scanf("%d%d%d%d",&a,&b,&c,&d);
			lines[i][0] = a;
			lines[i][1] = b;
			lines[i][2] = c;
			lines[i][3] = d;
		}

		//add all cross points into cross_points
		for(int i = 0; i < n-1; i++) {
			for(int j = i+1; j <n; j++) {
				double rate = cross_rate(lines[i][0],lines[i][1],lines[i][2],lines[i][3],lines[j][0],lines[j][1],lines[j][2],lines[j][3]);
				double rate2 = cross_rate(lines[j][0],lines[j][1],lines[j][2],lines[j][3],lines[i][0],lines[i][1],lines[i][2],lines[i][3]);
				if(rate>=0.0&&rate<=1.0) {
					cross_points[i].push_back(cross_point(j,rate));
					cross_points[j].push_back(cross_point(i,rate2));
				}
			}
		}

		//sort all cross points by rate in each lines
		for(int i = 0; i < n; i++) {
			sort(cross_points[i].begin(),cross_points[i].end());
		}

		int ans = 0;
		bool drawed[100];
		for(int i = 0; i < n; i++) drawed[i] = false;
		//draw lines and check distance from 0.0 to 1.0
		//ignore points on lines not drawed yet
		for(int i = 0; i < n; i++) {
			drawed[i] = true;
			double len = (lines[i][0]-lines[i][2])*(lines[i][0]-lines[i][2])+(lines[i][1]-lines[i][3])*(lines[i][1]-lines[i][3]);
			double rate = 0.0;
			for(int j = 0; j < cross_points[i].size(); j++) {
				if(drawed[cross_points[i][j].index]) {
					double distance = len*(cross_points[i][j].rate-rate)*(cross_points[i][j].rate-rate);
					if(distance>=1.0e-20) ans++;
					rate = cross_points[i][j].rate;
				}
			}
			if(len*(1.0-rate)*(1.0-rate)>=1.0e-20) ans++;
		}
		printf("%d\n",ans+1);
		scanf("%d",&n);
	}
}
