import java.util.*;

class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int n = scan.nextInt();
		int[] arr = new int[n];
		int start = (n)/2;
		for(int i = 1; i <= n; i++) {
			if(n%2==0) arr[start + ((i%2!=0)?1:-1) * (i/2)] = scan.nextInt();
			else arr[start + ((i%2==0)?1:-1) * (i/2)] = scan.nextInt();
		}
		System.out.print(arr[0]);
		for(int i = 1; i < n; i++) {
			System.out.print(" "+arr[i]);
		}
		System.out.println();
	}
}
