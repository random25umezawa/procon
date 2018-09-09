import java.util.*;

class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int a = scan.nextInt();
		int b = scan.nextInt();
		int n = scan.nextInt();
		char[] input = scan.next().toCharArray();
		for(char c : input) {
			if(c=='S') {
				if(a>0)a--;
			}
			if(c=='C') {
				if(b>0)b--;
			}
			if(c=='E') {
				if(a>=b) {
					if(a>0)a--;
				}else {
					if(b>0)b--;
				}
			}
		}
		System.out.println(a);
		System.out.println(b);
	}
}
