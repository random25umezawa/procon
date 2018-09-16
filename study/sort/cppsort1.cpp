/*
 * C++,単純な配列のソート
 */

#include <iostream>
#include <vector>     // 可変長配列
#include <algorithm>  // sort関数使うのに要る

using namespace std;  // とりあえず要る

int main() {
  int n;
  cin >> n;
  vector<int> arr(n); // vector<型> で好きな型の配列になる
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  // この書き方でソートできる。
  sort(arr.begin(),arr.end());

  for(int i = 0; i < arr.size(); i++) {
    cout << arr[i] << endl;
  }

  return 0;
}
