import java.io.*;
import java.util.Arrays;

class Main{
	public static void main(String[] args) throws Exception{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(reader.readLine());
		int[] arr = new int[100003];
		for(int i = 0; i < n; i++) {
			String[] input = reader.readLine().split(" ");
			int a = Integer.parseInt(input[0]);
			int b = Integer.parseInt(input[1]);
			arr[a] ++;
			arr[b+1]--;
		}
		for(int i = 0; i < arr.length-1; i++) {
			arr[i+1] += arr[i];
		}

		int result = 0;
		for(int i = 0; i < arr.length-1; i++) {
			if(i<=arr[i]+1) result=i-1;
		}

		System.out.println(result);
	}
}
