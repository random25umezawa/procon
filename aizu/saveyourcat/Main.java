import java.util.*;

class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int m = scan.nextInt();
		int[][] kui = new int[2][n];
		Group[] groups = new Group[n];
		for(int i = 0; i < n; i++) {
			kui[0][i] = scan.nextInt();
			kui[1][i] = scan.nextInt();
			groups[i] = new Group();
		}
		double allLen = 0.0;
		Queue<Branch> q = new PriorityQueue<>();
		for(int i = 0; i < m; i++) {
			int e1 = scan.nextInt()-1;
			int e2 = scan.nextInt()-1;
			int _w = kui[0][e1] - kui[0][e2];
			int _h = kui[1][e1] - kui[1][e2];
			double len = Math.sqrt(_w*_w+_h*_h);
			q.add(new Branch(e1,e2,len));
			allLen += len;
		}
		double resultLen = 0.0;
		while(!q.isEmpty()) {
			Branch _b = q.poll();
			//System.out.println(_b.len);
			Group g1 = groups[_b.e1].getGroup();
			Group g2 = groups[_b.e2].getGroup();
			if(g1==g2) continue;
			Group ng = new Group();
			g1.parent = ng;
			g2.parent = ng;
			resultLen += _b.len;
		}
		System.out.println(allLen-resultLen);
	}
}

class Group{
	Group parent;
	Group(){}
	Group getGroup() {
		return (parent==null)?this:parent.getGroup();
	}
}

class Branch implements Comparable<Branch> {
	int e1,e2;
	double len;
	Branch(int _e1, int _e2, double _len) {
		e1 = _e1;
		e2 = _e2;
		len = _len;
	}
	@Override
	public int compareTo(Branch _b) {
		return (_b.len - this.len>0.0)?1:-1;
	}
}
