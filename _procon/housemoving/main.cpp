#include <iostream>
#include <algorithm>
#define rep(a,b) for(int a = 0; a < b; a++)

using namespace std;

long int arr[100001];
long int dp[100001*2]{};
long int n;
long int size = 0;

long int update(int index, int num) {
  int seg_index = index+(1<<(size-1));
  dp[index] = max((long int)num,dp[seg_index]);
  for(int i = 1; i <= size; i++) {
    seg_index>>=1;
    dp[seg_index] = max(dp[seg_index],dp[seg_index^1]);
  }
}

long int get_max(int l, int r, int depth) {
  cout << l << "," << r << "," << depth << endl;
  if(l==r) return dp[l+1<<(size-depth)];
  for(int _depth = depth-1; _depth >= 0; _depth--) {
    int interval = 1<<_depth;
    int li = l/interval;
    int ri = r/interval;
    if(ri-li>1||((r+1)/interval-li>=1&&(l%interval==0||(r+1)%interval==0))) {
      cout << "  " << li << "," << ri << "," << _depth << endl;
      cout << "  - " << (1<<_depth)+((l%interval==0)?li:(li+1))*interval << endl;
      long int center = 0, right = 0, left = 0;
      center = dp[(1<<_depth)+((l%interval==0)?li:(li+1))*interval];
      if((r+1)%interval!=0) right = get_max(ri*interval,r,_depth);
      if(l%interval!=0) left = get_max(l,(li+1)*interval-1,_depth);
      return max(center,max(right,left));
    }
  }
}

int main() {
  cin >> n;
  for(int i = 1; i < n; i <<= 1) {
    size++;
  }
  rep(i,n) cin >> arr[i];
  //rep(i,n) update(i+1,arr[i]);
  rep(i,n) {
    /*
    long int temp = 0;
    //for(int l=j,r=arr[i];)
    rep(j,arr[i]) {
      temp = max(temp,dp[j]);
    }
    */
    long int temp = get_max(0,arr[i],size);
    update(arr[i],temp+arr[i]);
      cout << "OK" << endl;
  }
    cout << "OK" << endl;
  long int ans = dp[1];
  long int all = (1+n)*n/2;
  cout << all-ans << endl;
  return 0;
}
