/*
 * C++,pairを使う場合
 * pair.firstの要素でソートされるらしい
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector< pair<int,int> > arr(n);
  for(int i = 0; i < n; i++) {
    string s;
    int h,w;
    cin >> s >> h >> w;
    pair<int,int> p(h,w); // pair.first = h, pair.second = w となる
    arr[i] = p;
  }

  sort(arr.begin(),arr.end());

  for(int i = 0; i < arr.size(); i++) {
    cout << "height = " << (arr[i].first) << ", weight = " << (arr[i].second) << endl;
  }

  return 0;
}
