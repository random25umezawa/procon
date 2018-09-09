import java.util.*;

class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int n = scan.nextInt();
		int a = scan.nextInt();
		int b = scan.nextInt();

		System.out.println(Math.max(a+b-n,0));
	}
}
