import java.util.*;

class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int[] a = new int[n];
		int[] b = new int[n];
		int[] c = new int[n];
		for(int i = 0; i < n; i++) a[i] = scan.nextInt();
		for(int i = 0; i < n; i++) b[i] = scan.nextInt();
		for(int i = 0; i < n; i++) c[i] = scan.nextInt();
		int a_max = 0;
		int b_max = 0;
		int c_max = 0;
		for(int i = 0; i < n; i++) a_max = Math.max(a_max,a[i]);
		for(int i = 0; i < n; i++) b_max = Math.max(b_max,b[i]);
		for(int i = 0; i < n; i++) c_max = Math.max(c_max,c[i]);
		Arrays.sort(a);
		Arrays.sort(b);
		Arrays.sort(c);
		int[] a_sum = new int[n];
	}

	static int[] getSumArr(Scanner scan, int n) {
		int[] a = new int[n];
		for(int i = 0; i < n; i++) a[i] = scan.nextInt();
		int a_max = 0;
		for(int i = 0; i < n; i++) a_max = Math.max(a_max,a[i]);
		Arrays.sort(a);
		int[] a_sum = new int[a_max];
		int sum = 0;
		for(int i = 0; i < a_max; i++) {

		}
	}
}
