import java.util.*;

class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int k = scan.nextInt();
		int t = scan.nextInt();

		int[] arr = new int[t];
		for(int i = 0; i < t; i++) {
			arr[i] = scan.nextInt();
		}

		Arrays.sort(arr);

		int max = arr[arr.length-1];
		int sum = 0;
		for(int i = 0; i < t-1; i++) {
			sum += arr[i];
		}

		int result = max-sum-1;

		System.out.println((result>0)?result:0);
	}
}
