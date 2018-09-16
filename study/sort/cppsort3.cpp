/*
 * C++,抜け道的なソート
 * 複数の値を桁数決めて一つの数字に入れ込む
 * ソートすると一番位が高い項目でソートされる
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for(int i = 0; i < n; i++) {
    string s;
    int h,w;
    cin >> s >> h >> w;
    arr[i] = h*10000+w;
  }

  sort(arr.begin(),arr.end());

  for(int i = 0; i < arr.size(); i++) {
    cout << "height = " << (arr[i]/10000) << ", weight = " << (arr[i]%10000) << endl;
  }

  return 0;
}
