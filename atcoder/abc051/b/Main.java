import java.util.*;

class Main{
	public static void main(String[] args) throws Exception{
		Scanner scan = new Scanner(System.in);
		int K = scan.nextInt();
		int S = scan.nextInt();

		int answer = 0;
		for(int x = 0; x <= K; x++) {
			for(int y = 0; y <= K; y++) {
				if(S-x-y<=K && S-x-y>=0) {
					answer++;
					//System.out.printf("%d,%d,%d\n",x,y,S-x-y);
				}
			}
		}
		System.out.println(answer);
	}
}
