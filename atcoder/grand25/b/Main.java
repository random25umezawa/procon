import java.util.*;

class Main{
	static int EXCL_SIZE = 300001;
	static long MOD = 998244353;
	static long[] excl = new long[EXCL_SIZE];
	static long[] excl_inv = new long[EXCL_SIZE];
	static int n;
	public static void main(String[] args) {
		excl[0] = 1;
		excl_inv[0] = 1;
		for(int i = 1; i < EXCL_SIZE; i++) {
			excl[i] = ((excl[i-1]*((long)i))%MOD);
			excl_inv[i] = modPow(excl[i],MOD-2);
			//if(i<=4) System.out.println(excl[i]+","+excl_inv[i]);
		}
		Scanner scan = new Scanner(System.in);
		n = scan.nextInt();
		long a = scan.nextLong();
		long b = scan.nextLong();
		long k = scan.nextLong();
		if(a<b) {
			long c = a;
			a = b;
			b = c;
		}
		long st = (k/a)*a;
		/*
		if(st<n*a) {
			System.out.println(0);
			System.exit(0);
		}
		*/
		long red = k/a;
		long blue = 0;
		long ans = 0;
		while(blue<n) {
			if(st<k) {
				blue++;
				st+=b;
			}
			if(st==k) {
				//System.out.println(red+","+blue);
				ans = (calcAllPattern(red,blue)+ans)%MOD;
			}
			red--;
			st-=a;
			blue += (k-st)/b;
			st+=((k-st)/b)*b;
		}
		System.out.println(ans);
	}

	static long calcAllPattern(long red, long blue) {
		long ans = 0;
		long green = (red+blue)-n;
		if(green<0) green=0;
		red -= green;
		blue -= green;
		while(red>=0&&blue>=0) {
			//System.out.printf("%d,%d,%d\n",red,blue,green);
			//long num = excl[(int)(red+blue+green)];
			long num = excl[n];
				//num = (num*excl_inv[(int)(red+blue+green)])%MOD;
			num = (num*excl_inv[(int)(n-(red+blue+green))])%MOD;
			//long temp = num;
				//num = (num*excl[(int)(red+blue+green)])%MOD;
			num = (num*excl_inv[(int)red])%MOD;
			num = (num*excl_inv[(int)blue])%MOD;
			num = (num*excl_inv[(int)green])%MOD;
			//System.out.printf("%d,%d,%d\n",excl[n],excl_inv[(int)(red+blue+green)],excl_inv[(int)(n-(red+blue+green))]);
			//System.out.printf("%d,%d,%d,%d,%d\n",temp,num,excl_inv[(int)red],excl_inv[(int)blue],excl_inv[(int)green]);
			ans += num;
			red--;
			blue--;
			green++;
		}
		return ans;
	}

	static long modPow(long num, long p) {
		long ans = 1;
		while(p>0) {
			if(p%2==1) {
				ans = (ans*num)%MOD;
			}
			num = (num*num)%MOD;
			p>>=1;
		}
		return ans;
	}
}
