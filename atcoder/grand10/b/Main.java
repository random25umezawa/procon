import java.util.*;

class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int n = scan.nextInt();
		int[] arr = new int[n];
		int[] dx = new int[n];
		long sum = 0;
		int min = 1<<30;
		int loopSum = (n*(n+1)/2);
		for(int i = 0; i < n; i++) {
			arr[i] = scan.nextInt();
			sum += (long)arr[i];
			if(i>0) {
				dx[i-1] = Math.abs(arr[i]-arr[i-1]);
			}
		}
		if(sum%loopSum!=0) {
			System.out.println("NO");
			return;
		}
		boolean flag = false;
		for(int i = 0; i < n-1; i++) {
			flag |= Math.abs(dx[i]-dx[i+1])%(n-1)==0;
		}
		if(flag) {
			System.out.println("YES");
			return;
		}
		for(int i = 0; i < n-1; i++) {
			flag |=  Math.abs(dx[i]-dx[i+1])%n==0;
		}
		if(flag) {
			System.out.println("YES");
			return;
		}
		System.out.println("NO");
	}
}
