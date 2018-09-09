import java.util.*;

class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		char[] arr = scan.next().toCharArray();
		int syakuMax = 0;
		int syakuMin = 0;
		int result = 0;
		boolean now2 = true;
		for(int i = 0; i < arr.length; i++) {
			boolean flag = false;
			if(arr[i]=='2') {
				flag = !(now2^(i%2==0));
			}else if(arr[i]=='5') {
				flag = !(now2^(i%2==1));
			}else	if(arr[i]=='?') {
				flag = true;
			}
			if(flag) {
				syakuMax++;
				result = Math.max(result,syakuMax-syakuMin);
			}else {
				syakuMax = i;
				syakuMin = i;
				now2 = (i%2==1);
			}
		}

		if(result%2==1) result--;

		System.out.println(result);
	}
}
