import java.util.*;

class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		char[] s1 = scan.next().toCharArray();

		boolean result1 = false, result2 = false;
		int cpos = 99999999, fpos = -1;
		for(int i = 0; i < s1.length; i++) {
			if(s1[i] == 'C') {
				cpos = i;
				result1 = true;
				break;
			}
		}
		for(int i = s1.length-1; i >=0; i--) {
			if(s1[i] == 'F') {
				fpos = i;
				result2 = true;
				break;
			}
		}

		boolean result = result1 && result2 && (cpos<fpos);

		System.out.println((result)?"Yes":"No");
	}
}
