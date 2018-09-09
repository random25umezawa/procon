import java.util.*;

class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int n = scan.nextInt();

		char[][] arr = new char[n*2][n*2];
		for(int i = 0; i < n; i++) {
			char[] input = scan.next().toCharArray();
			for(int j = 0; j < n; j++) {
				arr[i][j] = input[j];
				arr[i+n][j] = input[j];
				arr[i][j+n] = input[j];
				arr[i+n][j+n] = input[j];
			}
		}

		long ans = 0;

		for(int offset = 0; offset < n; offset++) {
			boolean flag = true;
			for(int x = 1; x < n; x++) {
				for(int y = 0; y < x; y++) {
					flag &= (arr[x+offset][y] == arr[y+offset][x]);
				}
			}
			ans += (flag)?n:0;
		}

		System.out.println(ans);
	}
}
