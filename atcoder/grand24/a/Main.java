import java.util.*;

class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		long a = scan.nextLong();
		long b = scan.nextLong();
		long c = scan.nextLong();
		long k = scan.nextLong();
		k %= 2;
		if(k==1) {
			long sumA = b+c;
			long sumB = a+c;
			a = sumA;
			b = sumB;
		}
		long ans = a-b;
		System.out.println((Math.abs(ans)>1000000000000000000L)?"Unfair":ans);
	}
}
