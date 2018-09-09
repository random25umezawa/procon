import java.util.*;

class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int m = scan.nextInt();
		int base = 1900*m + 100*(n-m);
		base <<= m;
		System.out.println(base);
	}
}
