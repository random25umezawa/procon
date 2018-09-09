#include <iostream>
#include <algorithm>
#define rep(a,b) for(int a = 0; a < b; a++)

using namespace std;

long int arr[100001];
long int dp[100001*2]{};
long int n;

int main() {
  cin >> n;
  rep(i,n+1) cin >> arr[i];
  rep(i,n) {
    long int temp = 0;
    rep(j,arr[i]) {
      temp = max(temp,dp[j]);
    }
    dp[arr[i]] = temp + arr[i];
  }
  long int ans = 0;
  rep(i,n+1) ans = max(ans,dp[i]);
  //rep(i,n+1) cout << dp[i] << endl;
  long int all = (1+n)*n/2;
  cout << all-ans << endl;
  return 0;
}
