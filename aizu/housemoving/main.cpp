#include <iostream>
#include <algorithm>

int n;
int arr[100000];
int dp[18][100000]{};
int seg[18][100000]{};
int max_bit;
int max_seg_depth;

int calc(int start, int depth) {
	if(dp[depth][start]>0) return dp[depth][start];
	int pre;
	if(start==0) pre = 0;
	else pre = arr[start];
	int result = 0;
	for(int i = max_seg_depth; i >= 0; i--) {
		int interval = 1<<i;
		int seg_index = start/interval;
		int index = start%interval;
		int top_i = seg_index*interval;
		if(index==0 && seg[i][top_i]) {
			int nexts = dp[i][start+interval];
			if(nexts==0) nexts = calc(start+interval,i);
			int temp = nexts + seg[depth][start];
			dp[i][top_i] = temp;
			result = max(result,temp);
			break;
		}
	}
	return result;
}

int main() {
	cin >> n;
	max_bit = ((n-1)&(~(n-1)+1))<<1;
	if(max_bit==0) max_bit = 1;
	for(int j = 0; (1<<j)<=max_bit; j++) {
		max_seg_depth = j+1;
	}
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr[i] = a;
		for(int j = 0; (1<<j)<=max_bit; j++) {
			int interval = 1<<j;
			int seg_index = i/interval;
			int index = i%interval;
			int top_i = seg_index*interval;
			if(index==0) seg[j][top_i] = a;
			else {
				if(seg[j][top_i]>0) {
					if(arr[i] > arr[i-1]) {
						seg[j][top_i] += a;
					}else {
						seg[j][top_i] = 0;
					}
				}
			}
		}

		for(int i = 0; i < n; i++) {
			for(int j = max_seg_depth; j >= 0; j--) {
				calc(i,j);
			}
		}
	}
}
