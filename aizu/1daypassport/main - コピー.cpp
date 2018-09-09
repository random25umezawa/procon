#include <stdio.h>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

struct line{
	int a,c,h,r;
};
struct node{
	int p,h,cost;
};
bool operator<(const node &a, const node &b) {
	return a.cost*2500+a.p*25+a.h < b.cost*2500+b.p*25+b.h;
}

int n,m,h,k;
vector<line> lines[100];
int s,t,p;
int passports[256][3];

int pass_dp[256]{};
int dijk_dp[100][25]{};

int main() {
	while(true) {
		scanf("%d%d%d%d",&n,&m,&h,&k);
		if(n<=0) break;
		for(int i = 0; i < n; i++) lines[i] = vector<line>();
		for(int i = 0; i < m; i++) {
			int a,b,c,hh,r;
			scanf("%d%d%d%d%d",&a,&b,&c,&hh,&r);
			line _a{a-1,c,hh,r-1};
			line _b{b-1,c,hh,r-1};
			lines[b].push_back(_a);
			lines[a].push_back(_b);
		}
		pass_dp[0] = 0;
		for(int i = 1; i < 256; i++) {
			pass_dp[i] = -1;
		}
		scanf("%d%d%d",&s,&t,&p);
		s--;t--;
		for(int i = 0; i < p; i++) {
			scanf("%d%d",&passports[i][2],&passports[i][1]);
			passports[i][0] = 0;
			for(int j = 0; j < passports[i][2]; j++) {
				int a;
				scanf("%d",&a);
				passports[i][0] |= (1<<(a-1));
			}
			pass_dp[passports[i][0]] = passports[i][1];
		}
				for(int i = 0; i < (1<<p); i++) {
					printf("%3d %4d\n",i,pass_dp[i]);
				}

		queue<int> bits;
		bool appeared[256]{true};
		bits.push(0);
		while(!bits.empty()) {
			//printf("s%d ",bits.front());
			int size = bits.size();
			for(int i = 0; i < size; i++) {
				int bit = bits.front();
				bits.pop();
				if(pass_dp[bit]>=0) {
					for(int j = 0; j < p; j++) {
						int new_bit = bit|passports[j][0];
						int new_cost = pass_dp[bit]+passports[j][1];
						int val = min(new_cost,pass_dp[new_bit]);
						pass_dp[new_bit] = (pass_dp[new_bit]==-1)?new_cost:val;
					}
				}
				for(int i = 0; i < 8; i++) {
					int and_bit = bit&(1<<i);
					int new_bit = bit|(1<<i);
					if(and_bit==0 && !appeared[new_bit]) {
						appeared[new_bit] = true;
						bits.push(new_bit);
					}
				}
			}
			//printf("OKK %d\n",size);
		}
		printf("OK\n");

		for(int i = 0; i < (1<<p); i++) {
			printf("%3d %4d\n",i,pass_dp[i]);
		}

		for(int i = 0; i < 256; i++) {
			if(pass_dp[i]>=0) {
				int free_bits = i;
				node start_node{s,0,0};
				dijk_dp[s][0] = 0;
				for(int i = 0; i < n; i++) for(int j = 0; j <= h; j++) dijk_dp[i][j]=-1;
				set<node> pri;
				pri.insert(start_node);
				while(!pri.empty()) {
					node n = *(pri.begin());
					pri.erase(pri.begin());
					if(dijk_dp[n.p][n.h]!=-1&&dijk_dp[n.p][n.h]<n.cost) continue;
					for(int i = 0; i < lines[n.p].size(); i++) {
						line l = lines[n.p][i];
						int new_h = n.h+l.h;
						if(new_h<=h) {
							int new_cost = n.cost+((free_bits&(1<<l.r))==0)?l.c:0;
							node new_node{l.a,new_h,new_cost};
							pri.insert(new_node);
							dijk_dp[l.a][new_h] = (dijk_dp[l.a][new_h]==-1)?new_cost:min(dijk_dp[l.a][new_h],new_cost);
						}
					}
				}
			}
		}

		int ans = 1<<30;
		for(int i = 0; i < h; i++) {
			if(dijk_dp[t][i]!=-1) ans = min(ans,dijk_dp[t][i]);
		}

		printf("%d\n",(ans==(1<<30))?-1:ans);
	}
}
