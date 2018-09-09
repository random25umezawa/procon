import java.util.*;

class Main{
	public static void main(String[] args) throws Exception{
		Scanner scan = new Scanner(System.in);
		int a = scan.nextInt();
		int b = scan.nextInt();

		int[] arr = new int[1000];
		for(int i = 1; i < 1000; i++) {
			arr[i] = arr[i-1]+i;
		}
		System.out.println(arr[b-a]-b);
	}
}
