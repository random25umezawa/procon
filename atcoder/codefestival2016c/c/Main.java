import java.io.*;
import java.util.*;

class Main{
	public static void main(String[] args) throws Exception{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(reader.readLine());
		String[] takaString = reader.readLine().split(" ",0);
		String[] aokiString = reader.readLine().split(" ",0);
		int[] taka = new int[n];
		for(int i = 0; i < n; i++) taka[i] = Integer.parseInt(takaString[i]);
		int[] aoki = new int[n];
		for(int i = 0; i < n; i++) aoki[i] = Integer.parseInt(aokiString[i]);

		int[] yama = new int[n];
		{
			int max = 0;
			for(int i = 0; i < n; i++) {
				if(max < taka[i]) {
					max = taka[i];
					yama[i] = taka[i];
				}
			}
		}
		{
			int max = 0;
			for(int i = n-1; i >= 0; i--) {
				if(max < aoki[i]) {
					max = aoki[i];
					if(yama[i]!=0 && yama[i]!=aoki[i]) {
						System.out.println(0);
						return;
					}
					yama[i] = aoki[i];
				}
			}
		}

		long result = 1;
		for(int i = 0; i < n; i++) {
			if(yama[i]==0) {
				result *= (long)Math.min(aoki[i],taka[i]);
				result %= 1000000007L;
			}
		}

		System.out.println(result);
	}
}
