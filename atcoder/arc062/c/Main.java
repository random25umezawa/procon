import java.util.*;

class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int n = scan.nextInt();

		long hyo1 = 1, hyo2 = 1;

		for(int loop = 0; loop < n; loop++) {
			long t = scan.nextInt();
			long a = scan.nextInt();

			long value1 = (hyo2-1)/a+1;
			long value2 = (hyo1-1)/t+1;
			long value3 = Math.max(value1,value2);

			hyo1 = value3 * t;
			hyo2 = value3 * a;
		}

		System.out.println(hyo1+hyo2);
	}
}
