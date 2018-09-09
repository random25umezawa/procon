import java.util.*;

class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int w = scan.nextInt();
		int h = scan.nextInt();

		int count = 0;
		for(int i = 0; i < w; i++) {
				char[] arr = scan.next().toCharArray();
				for(char k : arr) {
					count += ((k == '#')?1:0);
			}
		}

		System.out.println((w+h-1==count)?"Possible":"Impossible");
	}
}
