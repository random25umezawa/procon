import java.util.*;

class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int result = 0;
		for(int i = 0; i < n; i++) result += (scan.nextInt()%2==1)?1:0;
		System.out.println((result%2==0)?"YES":"NO");
	}
}
