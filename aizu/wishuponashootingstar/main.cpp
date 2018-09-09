#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

struct collide{
	int a,b;
	double time;
};

bool operator<(const collide &a, const collide &b) {
	return a.time < b.time;
}

int n;
double stars[200][8];

double check(int i, int j) {
	double x = stars[i][0]-stars[j][0];
	double y = stars[i][1]-stars[j][1];
	double z = stars[i][2]-stars[j][2];
	double vx = stars[i][3]-stars[j][3];
	double vy = stars[i][4]-stars[j][4];
	double vz = stars[i][5]-stars[j][5];
	double r = stars[i][6]+stars[j][6];
	double vr = stars[i][7]+stars[j][7];
	double a = vx*vx+vy*vy+vz*vz-vr*vr;
	double b = x*vx+y*vy+z*vz+r*vr;
	b*=2.0;
	double c = x*x+y*y+z*z-r*r;
	double rt = b*b-4.0*a*c;
	if(a==0.0) return -1.0;
	if(rt<0.0) return -1.0;
	//printf("i,j rt,a,b = %d,%d,%lf,%lf,%lf\n",i,j,rt,a,b);
	double ans1 = (-b-sqrt(rt))/2.0/a;
	double ans2 = (-b+sqrt(rt))/2.0/a;
	double ret = min(ans1,ans2);
	if(ret<0.0) ret = max(ans1,ans2);
	return ret;
}

int main() {
	while(true) {
		scanf("%d",&n);
		if(n<=0) break;
		vector<collide> cols;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < 8; j++) {
				scanf("%lf",&stars[i][j]);
			}
		}

		//rintf("-----collide----\n");
		for(int i = 0; i < n; i++) {
			for(int j = i+1; j < n; j++) {
				double collide_time = check(i,j);
				//printf("%d,%d,%lf\n",i,j,collide_time);
				if(collide_time>0.0) {
					collide col{i,j,collide_time};
					cols.push_back(col);
				}
			}
			collide col{i,-1,stars[i][6]/stars[i][7]};
			cols.push_back(col);
		}

		sort(cols.begin(),cols.end());

/*
		printf("-----vector----\n");
		for(int i = 0; i < cols.size(); i++) {
			printf("%d,%d,%lf\n",cols[i].a,cols[i].b,cols[i].time);
		}
		printf("-----calc----\n");
		*/
		double desp_times[200]{};
		for(int i = 0; i < cols.size(); i++) {
			int a = cols[i].a;
			int b = cols[i].b;
			double desp = cols[i].time;
			if(desp_times[a]==0.0) {
				if(b==-1||desp_times[b]==0.0) {
					desp_times[a] = desp;
					if(b!=-1) desp_times[b] = desp;
				}
			}
		}

		for(int i = 0; i < n; i++) {
			printf("%.10lf\n",desp_times[i]);
		}
	}
}
