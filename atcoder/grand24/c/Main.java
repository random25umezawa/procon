import java.util.*;

class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int[] arr = new int[n];
		for(int i = 0; i < n; i++) arr[i] = scan.nextInt();
		if(arr[0]!=0) calc_end();
		long ans = 0L;
		int pre = 0;
		for(int index = n-1; index >= 0; index--) {
			int num = arr[index];
			if(num>index) calc_end();
			if(num>=pre) ans += (long)num;
			else if(num+1!=pre) calc_end();
			pre = num;
		}

		System.out.println(ans);
	}

	public static void calc_end() {
		System.out.println(-1);
		System.exit(0);
	}
}
