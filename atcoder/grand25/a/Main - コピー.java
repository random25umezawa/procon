import java.util.*;

class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int n = scan.nextInt();

		int ans = 999999999;

		for(int a = 1; a < n; a++) {
			int b = n-a;
			ans = Math.min(ans,getNumSum(a)+getNumSum(b));
		}

		System.out.println(ans);
	}

	static int getNumSum(int n) {
		char[] input = (""+n).toCharArray();
		int sum = 0;
		for(char c : input) {
			sum += (int)(c-'0');
		}
		return sum;
	}
}
