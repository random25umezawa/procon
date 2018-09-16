#include <iostream>

using namespace std;

int main() {
  while(true) {
    //input
    int num;
    cin >> num;
    //if 0 finish
    if(num==0) break;

    //oturi
    num = 1000 - num;

    int ans = 0;

    //500yen
    if(num>=500) {
      ans++;
      num-=500;
    }

    //100yen
    while(num>=100) {
      ans++;
      num-=100;
    }

    //50yen
    if(num>=50) {
      ans++;
      num-=50;
    }

    //10yen
    while(num>=10) {
      ans++;
      num-=10;
    }

    //5yen
    if(num>=5) {
      ans++;
      num-=5;
    }

    //1yen
    while(num>=1) {
      ans++;
      num-=1;
    }

    cout << ans << endl;

  }

  return 0;
}
