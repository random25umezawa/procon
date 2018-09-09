import java.util.*;

class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		boolean[] arr = new boolean[n];
		int[] count = new int[n];
		for(int i = 0; i < n; i++) {
			int p = scan.nextInt()-1;
			arr[p] = true;
			if(p>0 && arr[p-1]) count[p] = count[p-1]+1;
		}
		//System.out.println(Arrays.toString(count));
		int max = 0;
		for(int num : count) max = Math.max(max,num);
		System.out.println(n-max-1);
	}
}
