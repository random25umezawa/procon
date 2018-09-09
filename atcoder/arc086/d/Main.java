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
			if(timing>0)dp[timing][timing+1] = dp[timing-1][timing] + Math.min(x,time - times[timing-1]);
			for(int i = timing; i >= 2; i--) {
				System.out.printf("%3d%3d%3d%3d%3d\n",timing,i,dp[timing][i+1],dp[i-1][i],time - times[i-1]);
				dp[timing][i] = Math.min(
					dp[timing][i+1],
					dp[i-1][i] + Math.min(x,time - times[i-1])
				);
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
