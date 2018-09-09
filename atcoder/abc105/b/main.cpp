#include <iostream>

using namespace std;

bool arr[101]{};

int main() {
	for(int i = 0; i <= 100; i+=4) arr[i] = true;
	for(int i = 0; i <= 100; i++) {
		if(arr[i]){
			for(int j = 0; i+j<=100 && j<=21; j+=7) {
				arr[i+j] = true;
			}
		}
	}
	int a;
	cin >> a;
	cout << ((arr[a])?"Yes":"No") << endl;
}
