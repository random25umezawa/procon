import java.util.*;

class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int n = scan.nextInt();
		int x = scan.nextInt();

		if(n==2) System.out.println((x==2)?"Yes\n1\n2\n3":"No");

		if(x==1 || x==2*n-1) {
			System.out.println("No");
			return;
		}

		System.out.println("Yes");
		int start = ((x>2)?x-2:x-1);
		int dum = start;
		for(int i = 1; i <= 2*n-1;i++) {
			if(i>=start && i < start+4) {
				System.out.println(dum);
				dum++;
			}else {
				System.out.println(i);
			}
		}
	}
}
