import java.util.*;

class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int d = scan.nextInt();
		int[] arr = new int[n];
		for(int i = 0; i < n; i++) arr[i] = scan.nextInt();
		int left = 0;
		int center = 1;
		int right = 2;
		int ans = 0;
		while(center<n-1) {
			while(arr[center]-arr[left]>d) left++;
			while(right<n-1 && arr[right]-arr[center]<=d) {
				if(right<n-1) right++;
				if(arr[right]-arr[center]>d) {
					right--;
					break;
				}
			}
			//System.out.println((left+1)+","+(center+1)+","+(right+1));
			int j = center+1;
			for(int i = left; i < center; i++) {
				/*
				for(int j = center+1; j <= right; j++) {
					ans += (arr[j]-arr[i]>d)?1:0;
				}
				*/
				while(j<n-1 && arr[j]-arr[i]<d) {
					j++;
				}
				if(arr[j]-arr[i]<d) break;
				System.out.println((left+1)+","+(center+1)+","+(right+1));
				System.out.println((i+1)+","+(center+1)+","+(j+1));
				ans += (right-j)+1;
			}
			center++;
		}
		System.out.println(ans);
	}
}
