import java.util.*;

class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		long x = scan.nextLong();
		long y = scan.nextLong();
		long normal = Math.min(x,y/2L);
		if(y-normal<=1) {
			System.out.println(normal);
			return;
		}
		System.out.println(normal+(y-normal*2)/4L);
	}
}
