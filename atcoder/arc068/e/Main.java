import java.io.*;
import java.util.*;

class Main{
	public static void main(String[] args) throws Exception{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		String[] input = reader.readLine().split(" ");
		int n = Integer.parseInt(input[0]);
		int m = Integer.parseInt(input[1]);
		int[][] miyage = new int[2][n];
		for(int i = 0; i < n; i++) {
			input = reader.readLine().split(" ");
			miyage[0][i] = Integer.parseInt(input[0]);
			miyage[1][i] = Math.min(Integer.parseInt(input[1]),m+1-miyage[0][i]);
		}
		int[] result = new int[n+2];
		for(int i = 0; i < n; i++) {
			result[1]++;
			result[miyage[1][i]+1]--;
			for(int j = 1; j < miyage[1][i]; j++) {
				int max = (miyage[0][i]+miyage[1][i])/j;
				int min = miyage[0][i]/j;
			}
		}
		for(int i = 1; i <= n; i++) {
			result[i+1] += result[i];
		}
		StringBuilder sb = new StringBuilder();
		for(int i = 1; i <= n; i++) {
			sb.append(result[i]);
			sb.append('\n');
		}
		System.out.println(sb.toString());
	}
}
