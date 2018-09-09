import java.util.Scanner;

class Main{
	static int cursor = 0;
	static char[] input;
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		input = scan.next().toCharArray();
		System.out.println((check() && cursor==input.length)?"Cat":"Rabbit");
	}

	static boolean check() {
		if(cursor>=input.length) return false;
		if(input[cursor]!='m') return false;
		cursor++;
		if(cursor>=input.length) return false;
		if(!(input[cursor]=='e' || check())) return false;
		cursor++;
		if(cursor>=input.length) return false;
		if(!(input[cursor]=='w' || check())) return false;
		cursor++;
		return true;
	}
}
