import java.io.*;
import java.util.*;

class Main{
	public static void main(String[] args) throws Exception{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		char[] input = reader.readLine().toCharArray();

		int result = 0;
		for(int i = 1; i < input.length; i++) {
			int me = (i%2==0)?0:1;
			int you = (input[i]=='g')?0:1;
			result += me-you;
		}

		System.out.println(result);
	}
}
