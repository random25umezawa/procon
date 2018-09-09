import java.util.*;

class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		long a = scan.nextLong();
		long b = scan.nextLong();
		boolean[][] res = new boolean[(int)(b-a)+1][(int)(b-a)+1];
		for(int i = 0; i <= b-a; i++) {
			for(int j = 0; j <= b-a; j++) {
				res[i][j] = isSo((long)i+a,(long)j+a);
				res[j][i] = res[i][j];
			}
		}
		int result = 0;
		long kinum = (b+1)/2 - a/2;
		long firstki = a;
		long firstgu = a;
		if(a%2==0) firstki++;
		else firstgu++;
		ArrayList<Long> list = new ArrayList<>(64);
		bit: for(int bit = 0; bit < (1<<kinum); bit++) {
			list.clear();
			for(int i = 0; i < kinum; i++) {
				long newki = firstki+2*i;
				if((bit&(1<<i))!=0) {
					for(long _l : list) {
						if(!res[(int)(_l-a)][(int)(newki-a)]) continue bit;
					}
					list.add(newki);
				}
			}
			result++;
			gu: for(long i = firstgu; i <= b; i+=2) {
				for(long _l : list) {
					if(!res[(int)(_l-a)][(int)(i-a)]) continue gu;
				}
				result++;
			}
		}
		System.out.println(result);
	}

	static boolean isSo(long a, long b) {
		long c = a%b;
		while(c!=0) {
			a = b;
			b = c;
			c = a%b;
		}
		return b==1;
	}
}
