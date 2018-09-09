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
			lines[b-1].push_back(_a);
			lines[a-1].push_back(_b);
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
		}

		int final_ans = 1<<30;
		for(int i = 0; i < 256; i++) {
			if(pass_dp[i]>=0) {
				int free_bits = i;
				node start_node{s,0,0};
				for(int w = 0; w < n; w++) for(int j = 0; j <= h; j++) dijk_dp[w][j]=-1;
				dijk_dp[s][0] = 0;
				set<node> pri;
				pri.insert(start_node);
				while(!pri.empty()) {
					node n = *(pri.begin());
					//printf("node %d,%d,%d\n",n.p,n.h,n.cost);
					pri.erase(pri.begin());
					if(dijk_dp[n.p][n.h]==-1||dijk_dp[n.p][n.h]<n.cost) continue;
					//printf("TANSAKU %d\n",lines[n.p].size());
					for(int w = 0; w < lines[n.p].size(); w++) {
						line l = lines[n.p][w];
						//printf(" line %d,%d,%d\n",l.a,l.h,l.c);
						int new_h = n.h+l.h;
						//printf("newh/h %d/%d\n",new_h,h);
						if(new_h<=h) {
							int new_cost = n.cost;
							if((free_bits&(1<<l.r))==0) new_cost += l.c;
							//printf(" new_cost %d free_bits %d r:%d\n",new_cost,free_bits,l.r);
							if(dijk_dp[l.a][new_h]==-1 || dijk_dp[l.a][new_h]>new_cost) {
								dijk_dp[l.a][new_h] = new_cost;
								node new_node{l.a,new_h,new_cost};
								pri.insert(new_node);
							}
							/*
							node new_node{l.a,new_h,new_cost};
							pri.insert(new_node);
							dijk_dp[l.a][new_h] = (dijk_dp[l.a][new_h]==-1)?new_cost:min(dijk_dp[l.a][new_h],new_cost);
							*/
						}
					}
				}
/*
				for(int w = 0; w < n; w++) {
					for(int j = 0; j < h; j++) {
						printf("%3d ",dijk_dp[w][j]);
					}
					printf("\n");
				}
*/
				int ans = 1<<30;
				for(int i = 0; i <= h; i++) {
					if(dijk_dp[t][i]!=-1) ans = min(ans,dijk_dp[t][i]);
				}
				if(ans!=(1<<30)) final_ans = min(ans+pass_dp[free_bits],final_ans);
			}
		}

		printf("%d\n",(final_ans==(1<<30))?-1:final_ans);
	}
}
