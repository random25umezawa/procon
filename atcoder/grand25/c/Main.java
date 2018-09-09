import java.util.*;

class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		PriorityQueue<Area> qa = new PriorityQueue<>(new NumCompA());
		PriorityQueue<Area> qd = new PriorityQueue<>(new NumCompD());
		for(int i = 0; i < n; i++) {
			int a = scan.nextInt();
			int b = scan.nextInt();
			Area area = new Area(a,b);
			qa.add(area);
			qd.add(area);
		}
		HashSet<Area> appeared = new HashSet<>();
		long ans = 0;
		int pos = 0;
		boolean rightFlag = true;
		while(!qa.isEmpty()&&!qd.isEmpty()) {
			/*
			System.out.println(qa);
			System.out.println(qd);
			System.out.println(ans);
			*/
			while(true) {
				Area area = null;
				if(rightFlag) {
					area = qa.poll();
				}else {
					area = qd.poll();
				}
				if(area==null) break;
				if(!appeared.contains(area)) {
					appeared.add(area);
					if(area.left<=pos&&pos<=area.right) {
						//nomove
					}else if(pos<area.left) {
						ans += Math.abs(area.left-pos);
						pos = area.left;
					}else if(area.right<pos) {
						ans += Math.abs(area.right-pos);
						pos = area.right;
					}
					break;
				}
			}
			rightFlag = !rightFlag;
		}
		ans += Math.abs(pos);
		System.out.println(ans);
	}
}

class Area{
	int left,right;
	Area(int _left, int _right) {
		left = _left;
		right = _right;
	}
	@Override
	public String toString() {
		return "("+left+","+right+")\n";
	}
}

class NumCompA implements Comparator<Area> {
	@Override
	public int compare(Area _a, Area _b) {
		return _a.right-_b.right;
	}
}

class NumCompD implements Comparator<Area> {
	@Override
	public int compare(Area _a, Area _b) {
		return _b.left-_a.left;
	}
}
