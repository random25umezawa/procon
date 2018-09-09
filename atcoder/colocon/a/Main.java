import java.util.*;

class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int m = scan.nextInt();
		String in = scan.next();
		System.out.println((n<=in.length()&&in.length()<=m)?"YES":"NO");
	}
}
