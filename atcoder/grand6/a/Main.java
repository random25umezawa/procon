import java.util.*;

class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int n = scan.nextInt();
		char[] s1 = scan.next().toCharArray();
		char[] s2 = scan.next().toCharArray();

		char[] arr = new char[n*2];
		for(int i = 0; i < s1.length; i++) {
			arr[i] = s1[i];
		}
		LABEL:for(int i = 0; i < n*2; i++) {
			if(arr[i] == s2[0]) {
				for(int j = 1; i < s2.length && i+j < n; j++) {
					if(arr[i+j] != s2[j]) {
						continue LABEL;
					}
				}
				System.out.println(n+i);
				return;
			}
		}

		System.out.println(2*n);
	}
}
