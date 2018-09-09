import java.util.*;

class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int n = scan.nextInt();
		LinkedList<Integer> list = new LinkedList<>();
		for(int i = 0; i < n; i++) {
			list.add(scan.nextInt());
		}

		Collections.sort(list);

		long size = list.poll();
		int color = 1;
		for(int i = 1; i < n; i++) {
			long dummy = list.poll();
			if(dummy > size*2) {
				color = 1;
			}else {
				color++;
			}
			size+=dummy;
		}

		System.out.println(color);
	}
}
