import java.util.*;

class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		long n = scan.nextLong();
		long k = scan.nextLong();
		int[] arr = new int[200001];
		for(int i = 0; i < n; i++) {
			arr[scan.nextInt()]++;
		}
		PriorityQueue<Integer> q = new PriorityQueue<>(200000);
		for(int val : arr) {
			if(val>0) q.add(val);
		}
		int result = 0;
		while(q.size()>k) {
			result += q.poll();
		}
		System.out.println(result);
	}
}
