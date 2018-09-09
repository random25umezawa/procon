import java.util.*;

class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		char[] s1 = "CODEFESTIVAL2016".toCharArray();
		char[] s2 = scan.next().toCharArray();

		int result = 0;
		for(int i = 0; i < s1.length; i++) {
			result += (s1[i]!=s2[i])?1:0;
		}

		System.out.println(result);
	}
}
