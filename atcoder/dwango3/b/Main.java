import java.util.*;

class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		char[] arr = scan.next().toCharArray();
		boolean[] nico0 = new boolean[arr.length];
		boolean[] nico1 = new boolean[arr.length];

		for(int i = 0; i < arr.length; i++) {
			nico0[i] = arr[i]=='2'&&(i%2==0) || arr[i]=='5'&&(i%2==1) || arr[i]=='?';
			nico1[i] = arr[i]=='2'&&(i%2==1) || arr[i]=='5'&&(i%2==0) || arr[i]=='?';
		}

		int result = Math.max(calc(nico0,true),calc(nico1,false));

		if(result%2==1) result--;

		System.out.println(result);
	}

	static int calc(boolean[] arr, boolean flag) {
		int max = 0;
		int min = 0;
		int result = 0;
		for(int i = 0; i < arr.length; i++) {
			if(arr[i] && ((flag&&(i%2==0))||(!flag&&(i%2==1)))) {
				max++;
				result = Math.max(max-min,result);
			}else {
				max = i;
				min = i;
			}
		}
		return result;
	}
}
