import java.util.*;

class Main{
	static int n;
	static int z;
	static int w;
	static int[] arr;
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		n = scan.nextInt();
		z = scan.nextInt();
		w = scan.nextInt();
		arr = new int[n+2];
		arr[0] = z;
		arr[1] = w;
		for(int i = 0; i < n; i++) {
			arr[i] = scan.nextInt();
		}

		int[][][] dp = new int[2][n+2][n+2];
		for(int i = 0; i < n+2; i++) for(int j = 0; j < n+2; j++) dp[0][i][j] = -1; dp[1][i][j] = -1;
		//dp[0][0] = Math.abs(z-w);
		int result = tansaku(dp,0,1,0);
		for(int j = 0; j < n+2; j++) {
			for(int i = 0; i < n+2; i++) {
				System.out.printf("(%5d,%5d) ",dp[0][i][j],dp[1][i][j]);
			}
			System.out.println();
		}
		System.out.println(result);
	}

	static int tansaku(int[][][] dp, int x, int y, int isX) {
		if(dp[isX][x][y]>=0) return dp[isX][x][y];
		System.out.println(x+","+y);
		if(x==n+1 || y==n+1) {
			dp[x][y] = Math.abs(arr[x] - arr[y]);
			return dp[x][y];
		}
		if(isX) {
			int max = 0;
			for(int i = y+1; i < n+2; i++) {
				max = Math.max(tansaku(dp,i,y,false),max);
			}
			dp[x][y] = max;
			return max;
		}else {
			int min = 0;
			for(int i = x+1; i < n+2; i++) {
				min = Math.min(tansaku(dp,x,i,true),min);
			}
			dp[x][y] = min;
			return min;
		}
	}
}
