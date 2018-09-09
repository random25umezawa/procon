import java.util.*;

class Main{
	public static void main(String[] args) {
		int h = scan.nextInt();
		int w = scan.nextInt();
		int n = scan.nextInt();
		int m = scan.nextInt();
		int[] x_max = new int[n];
		int[] x_min = new int[n];
		int[] y_max = new int[m];
		int[] y_min = new int[m];
		Arrays.fill(x_max,-1);
		Arrays.fill(x_min,99999999);
		Arrays.fill(y_max,-1);
		Arrays.fill(y_min,99999999);
		boolean noDotFlag = true;
		for(int i = 0; i < n; i++) {
			char[] input = scan.next().toCharArray();
			for(int j = 0; j < m; j++) {
				if(input[j]=='#') {
					noDotFlag = false;
					int x = i;
					int y = j;
					x_max[i] = Math.max(x_max[i],x);
					x_min[i] = Math.min(x_min[i],x);
					y_max[i] = Math.max(y_max[i],y);
					y_min[i] = Math.min(y_min[i],y);
				}
			}
		}
		if(noDotFlag) {
			System.out.println(0);
			exit(0);
		}
	}
}
