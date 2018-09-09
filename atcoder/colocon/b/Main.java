import java.util.*;

class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int x = scan.nextInt();
		char[] in = scan.next().toCharArray();
		int result = 0;
		for(char _c : in) {
			if(_c=='0') {
				result += scan.nextInt();
			}else {
				result += Math.min(scan.nextInt(),x);
			}
		}
		System.out.println(result);
	}
}
