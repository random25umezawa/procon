import java.io.*;
import java.util.*;

class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int nine = (n/9);
		n-=nine*9;
		int six = n/6;
		n-=six*6;
		int one = n;
		int ans = 99999999;
		while(nine>=0) {
			int sum = 0;
			sum += calc(9,nine);
			sum += calc(6,six);
			sum += one;
			ans = Math.min(ans,sum);
			nine--;
			six+=1;
			one+=3;
			if(one>=6) {
				six++;
				one-=6;
			}
		}
		System.out.println(ans);
	}

	public static int calc(int num, int all) {
		int max = 1;
		int result = 0;
		while(max*num<=all) max *= num;
		while(max>0) {
			int count = all/max;
			result += count;
			all -= count*max;
			max /= num;
		}
		return result;
	}
}
