import java.util.*;

class Main{
	static String[] checkArr = {"dreamer","dream","eraser","erase"};
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String in = scan.next();

		int last = in.length();

		LABEL:while(true) {
			//System.out.print(last);
			//System.out.println(in.substring(0,last));
			if(last==0) {
				System.out.println("YES");
				return;
			}

			for(String com : checkArr) {
				int dum = in.lastIndexOf(com,last-1);
				//System.out.println(dum+",");
				if(dum>=0 && last-dum==com.length()) {
					last -= com.length();
					continue LABEL;
				}
			}

			System.out.println("NO");
			return;
		}
	}
}
