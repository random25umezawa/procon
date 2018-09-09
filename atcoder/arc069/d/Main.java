import java.io.*;
import java.util.*;

class Main{
	static boolean[] arr;
	public static void main(String[] args) throws Exception{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(reader.readLine());
		char[] str = reader.readLine().toCharArray();
		arr = new boolean[n];
		for(int i = 0; i < n; i++) arr[i] = str[i]=='o';
		boolean[] animal = new boolean[n+1];
		animal[0] = true;	animal[1] = true;
		if(calc(animal)) return;
		animal[0] = false;	animal[1] = false;
		if(calc(animal)) return;
		animal[0] = true;	animal[1] = false;
		if(calc(animal)) return;
		animal[0] = false;	animal[1] = true;
		if(calc(animal)) return;
		System.out.println(-1);
	}

	static boolean calc(boolean[] animal) {
		for(int i = 0; i < animal.length-2; i++) {
			animal[i+2] = !(animal[i+1]^!(animal[i]^arr[i+1]));
		}
		boolean result = animal[animal.length-1]==animal[0];
		boolean last = !(animal[0]^!(animal[1]^arr[0]));
		result &= last==animal[animal.length-2];
		if(result) {
			StringBuilder sb = new StringBuilder();
			for(int i = 0; i < animal.length-1; i++) sb.append((animal[i])?'S':'W');
			System.out.println(sb.toString());
		}
		return result;
	}
}
