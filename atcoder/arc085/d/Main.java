import java.io.*;
import java.util.Scanner;
import java.util.Arrays;

class Main{
	static int n;
	static int z;
	static int w;
	static int[] arr;
	static int[][] dp;
	public static void main(String[] args) throws Exception{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		String[] in1 = reader.readLine().split(" ");
		n = Integer.parseInt(in1[0]);
		z = Integer.parseInt(in1[1]);
		w = Integer.parseInt(in1[2]);
		in1 = reader.readLine().split(" ");
		arr = new int[n+2];
		arr[0] = z;
		arr[1] = w;
		for(int i = 0; i < n; i++) {
			arr[i+2] = Integer.parseInt(in1[i]);
		}

		dp = new int[n+2][n+2];
		/*
		for(int i = 0; i < n+2; i++) for(int j = 0; j < n+2; j++) {
			Arrays.fill(dp[0][i],-1);
			Arrays.fill(dp[1][i],-1);
		}
		*/
		//dp[0][0] = Math.abs(z-w);
		int result = tansaku(0,1,0);
/*
		for(int i = 0; i < n+2; i++) {
			System.out.printf("%5d ",arr[i]);
		}
		System.out.println();
		for(int j = 0; j < n+2; j++) {
			for(int i = 0; i < n+2; i++) {
				System.out.printf("(%5d,%5d) ",dp[0][i][j],dp[1][i][j]);
			}
			System.out.println();
		}
*/
		System.out.println(result-1);
	}

	static int tansaku(int x, int y, int isX) {
		if(dp[x][y]>=1) return dp[x][y];
		//System.out.println(x+","+y);
		if(x==n+1 || y==n+1) {
			dp[x][y] = Math.abs(arr[x] - arr[y])+1;
			return dp[x][y];
		}
		int res = 0;
		if(isX==0) {
			for(int i = y+1; i < n+2; i++) {
				res = Math.max(tansaku(i,y,1),res);
			}
		}else {
			res = 2147483647;
			for(int i = x+1; i < n+2; i++) {
				res = Math.min(tansaku(x,i,0),res);
			}
		}
		dp[x][y] = res;
		return res;
	}
}
