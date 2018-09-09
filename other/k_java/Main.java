import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		for(int i = 0; i < n; i++) {
			System.out.printf("%.5f\n", Math.sqrt(scan.nextInt() / 2.0));
		}

		/*
		System.out.println(100000);
		for(int i = 1; i <= 100000; i++) {
			System.out.println(i);
		}
		*/
	}
}
