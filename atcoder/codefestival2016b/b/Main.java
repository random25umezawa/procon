import java.util.*;

class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int n = scan.nextInt();
		int a = scan.nextInt();
		int b = scan.nextInt();

		int in = 0;
		int out = 0;

		char[] arr = scan.next().toCharArray();
		for(int i = 0; i < n; i++) {
			if(arr[i] == 'a') {
				if(in+out<a+b) {
					System.out.println("Yes");
					in++;
				}else {
					System.out.println("No");
				}
			}else if(arr[i] == 'b') {
				if(in+out<a+b && out < b) {
					System.out.println("Yes");
					out++;
				}else {
					System.out.println("No");
				}
			}else {
				System.out.println("No");
			}
		}
	}
}
