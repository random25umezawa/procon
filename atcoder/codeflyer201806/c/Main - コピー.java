import java.util.*;

class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int d = scan.nextInt();
		int[] arr = new int[n];
		//for(int i = 0; i < n; i++) arr[i] = scan.nextInt();
		TreeSet<Num> tree = new TreeSet<>();
		for(int i = 0; i < n; i++) {
			/*
			arr[i] = scan.nextInt();
			list.add(arr[i]);
			tree.add(arr[i]);
			*/

			arr[i] = scan.nextInt();
			tree.add(new Num(arr[i],i));
		}
		System.out.println(tree);
		long ans = 0;
		for(int i = 0; i < n-2; i++) {
			Num tohoMax = tree.floor(new Num(arr[i]+d,0));
			Num densyaMin = tree.higher(new Num(arr[i]+d,0));
			if(tohoMax!=null && densyaMin!=null) {
				//ans += (i-left)*(right-i);
				int left = tohoMax.index;
				int right = densyaMin.index;
				for(int j = i; j < (int)left; j++) {
					Num moreTohoMax = tree.floor(new Num(arr[left]+d,0));
					int moreLeft = moreTohoMax.index;
					ans += ((long)(j-i))*(moreLeft-j);
					System.out.println((i+1)+","+(j+1)+","+(moreLeft+1));
				}
			}
		}
		System.out.println(ans);
	}
}

class Num implements Comparable<Num>{
	int num,index;
	Num(int _num, int _index) {
		num = _num;
		index = _index;
	}
	@Override
	public int compareTo(Num _num) {
		return this.num - _num.num;
	}
	@Override
	public String toString() {
		return "("+num+","+index+")";
	}
}
