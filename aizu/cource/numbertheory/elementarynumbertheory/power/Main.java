import java.util.*;

class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		long m = scan.nextLong();
		long n = scan.nextLong();
		long MOD = 1000000007L;
		long ans = 1;
		while(n>0) {
			if(n%2==1) {
				ans = (ans*m)%MOD;
			}
			m = (m*m)%MOD;
			n>>=1;
		}
		System.out.println(ans);
	}
}
