import java.util.*;

class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int x = scan.nextInt();
		int[] times = new int[n];
		for(int i = 0; i < n; i++) times[i] = scan.nextInt();
		int[][] dp = new int[n+1][n+1];
		for(int timing = 0; timing < n; timing++) {
			int time = times[timing];
			dp[timing][1] = x;
			for(int i = 2; i <= timing+1; i++) {
				for(int j = 0; j < timing; j++) {
					dp[timing][i] = Math.max(
						dp[timing][i],
						dp[timing-j-1][i-1]+Math.min(x,time-times[timing-j-1])
					);
				}
			}
			/*
			for(int i = 0; i < timing; i++) {
				System.out.printf("%3d,%3d,%3d,%3d\n",timing,2+i,timing-i-1,1+i);
				dp[timing][2+i] = Math.max(dp[timing][2+i],dp[timing-i-1][1+i]+Math.min(x,time-times[timing-i-1]));
			}
			*/
		}

		for(int i = 0; i < n+1; i++) {
			for(int j = 0; j < n+1; j++) {
				System.out.printf("%3d ",dp[j][i]);
			}
			System.out.println();
		}
		/*
		for(int i = 1; i <= n; i++) {
			System.out.println(dp[n-1][i]);
		}
		*/
	}
}
