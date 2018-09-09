import java.util.*;

class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int[] a_sum = getSumArr(scan,n);
		int[] b_sum = getSumArr(scan,n);
		int[] c_sum = getSumArr(scan,n);
		System.out.println(Arrays.toString(a_sum));
		System.out.println(Arrays.toString(b_sum));
		System.out.println(Arrays.toString(c_sum));
	}

	static int[] getSumArr(Scanner scan, int n) {
		int[] a = new int[n];
		for(int i = 0; i < n; i++) a[i] = scan.nextInt();
		Arrays.sort(a);
		int a_max = a[a.length-1];
		int[] a_sum = new int[a_max+1];
		int index = 0;
		for(int i = 0; i < n; i++) {
			int new_index = a[i];
			for(int j = index; j < new_index; j++) {
				a_sum[j] = i;
			}
			index = new_index;
		}
		a_sum[a_sum.length-1] = a.length;
		return a_sum;
	}

	static int[] getSaidanPair(int[] a, int[] b) {
		int[] result = new int[b.length];
		for(int i = 1; i < b.length-1; i++) {
			if(i>=a.length-1) result[i] = a[a_length-1];
			result[i] += result[i-1];
		}
	}
}
