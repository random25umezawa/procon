/*
 * C++,構造体のソート
 * sort関数は「比較関数が定義されている」型しかソートできない
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct human{
  string s;
  int h,w;

  // 比較関数
  bool operator<( const human& right ) {
    return h < right.h;
  }
} ;

/*
bool operator<( const human& left, const human& right ) {
  return left.h < left.w;
}
*/

int main() {
  int n;
  cin >> n;
  vector<human> arr(n);
  for(int i = 0; i < n; i++) {
    cin >> arr[i].s >> arr[i].h >> arr[i].w;
  }

  sort(arr.begin(),arr.end());

  for(int i = 0; i < arr.size(); i++) {
    cout << arr[i].h << endl;
  }

  return 0;
}
