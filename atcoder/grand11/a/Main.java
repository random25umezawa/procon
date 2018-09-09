import java.util.*;

class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int n = scan.nextInt();
		int c = scan.nextInt();
		int k = scan.nextInt();

		int[] arr = new int[n];
		for(int i = 0; i < n; i++) {
			arr[i] = scan.nextInt();
		}
		Arrays.sort(arr);

		int ans = 1;
		int firstTime = arr[0];
		int passenger = 1;
		for(int i = 1; i < n; i++) {
			if(passenger >= c || arr[i] > firstTime+k) {
				ans++;
				firstTime = arr[i];
				passenger = 0;
			}
			passenger++;
		}

		System.out.println(ans);
	}
}
