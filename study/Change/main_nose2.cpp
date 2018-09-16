#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  while(true) {
    int input;
    cin >> input;
    if(input==0) break;

    int oturi = 10000 - input;
    int usedNum = 0;
    int ans = 0;

    int a[6] = {500,100,50,10,5,1};
    int num[6];

    for(int i = 0; i < 6; i++) {
      cin >> num[i];
    }

    for(int i = 0; i < 6; i++) {
      usedNum = min(oturi/a[i],num[i]);
      ans += usedNum;
      oturi -= usedNum*a[i];
    }

    cout << ans << endl;
  }

  return 0;
}
