#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct line {
    int a,b,max,now;
    bool atob;
};

int v,e;
vector<line*> lines[100];
bool arrived[100]{};

int dfs(int start, int end, int flow) {
    if(start==end) return flow;
    /*
    if(flow<=0) return -1;
    if(arrived[start]) return -1;
    */
    arrived[start] = true;

    for(int i = 0; i < lines[start].size(); i++) {
        line *_line = lines[start][i];
        bool atob = start==_line->a;
        if(_line->now == 0) {
            int res = 0;
            int _flow = min(flow,_line->max);
            if(atob) if(_flow>0) if(arrived[(atob)?_line->b:_line->a]) res = dfs((atob)?_line->b:_line->a,end,_flow);
            if(res>0) {
                _line->now += res;
                _line->atob = atob;
                arrived[start] = false;
                return res;
            }
        }else {
            if(!atob^_line->atob) {
                int res = 0;
                int _flow = min(flow,_line->max-_line->now);
                if(_flow>0) if(arrived[(atob)?_line->b:_line->a]) res = dfs((atob)?_line->b:_line->a,end,_flow);
                if(res>0) {
                    _line->now += res;
                    arrived[start] = false;
                    return res;
                }
            }else {
                int res = 0;
                int _flow = min(flow,_line->now);
                if(_flow>0) if(arrived[(atob)?_line->b:_line->a]) res = dfs((atob)?_line->b:_line->a,end,_flow);
                if(res>0) {
                    _line->now -= res;
                    arrived[start] = false;
                    return res;
                }
            }
        }
    }

    arrived[start] = false;
    return -1;
}

int main() {
    scanf("%d%d",&v,&e);
    for(int i = 0; i < v; i++) lines[i] = vector<line*>();
    for(int i = 0; i < e; i++) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        line *new_line = new line{a,b,c,0,false};
        lines[a].push_back(new_line);
        //lines[b].push_back(new_line);
    }

    int ans = 0;
    int count = 0;
    while(true) {
        int flow = dfs(0,v-1,1<<30);
        if(flow>0) ans+=flow;
        else break;
/*
        for(int i = 0; i < v; i++) {
            for(int j = 0; j < lines[i].size(); j++) {
                printf("(%2d,%2d => %3d/%3d %d) ",lines[i][j]->a,lines[i][j]->b,lines[i][j]->now,lines[i][j]->max,lines[i][j]->atob);
            }
            printf("\n");
        }
        printf("%d\n",ans);
*/
        count++;
        //if(count>5) break;
    }

    printf("%d\n",ans);

    return 0;
}
