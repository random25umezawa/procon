import java.util.*;

class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int inu = scan.nextInt();
		int saru = scan.nextInt();

		if(Math.abs(inu-saru)>1) {
			System.out.println(0);
			return;
		}

		int result = 1;
		for(int i = 1; i <= inu; i++) {
			result = kakeru(result,i);
		}
		for(int i = 1; i <= saru; i++) {
			result = kakeru(result,i);
		}
		if(inu==saru) result = kakeru(result,2);

		System.out.println(result);
	}

	static int kakeru(int x, int y) {
		long l = (long)x * (long)y;
		return (int)(l %= 1000000007);
	}
}
