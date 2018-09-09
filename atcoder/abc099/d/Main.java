import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		int M = scan.nextInt();
		ArrayList<Line> lines = new ArrayList<Line>();
		SetArrow[] arrows = new SetArrow[N];
		for(int i = 0; i < N; i++) {
			arrows[i] = new SetArrow();
		}
		for(int i = 0; i < M; i++) {
			int a = scan.nextInt()-1;
			int b = scan.nextInt()-1;
			int c = scan.nextInt();
			lines.add(new Line(a,b,c));
		}
		Collections.sort(lines);
		int result = 0;
		for(Line _l : lines) {
			SetArrow a1 = arrows[_l.a].search();
			SetArrow a2 = arrows[_l.b].search();
			if(a1==a2) {
				result++;
				continue;
			}
			SetArrow.add(a1,a2);
		}
		System.out.println(result);
	}
}

class Line implements Comparable{
	int a,b,c;
	Line(int _a, int _b, int _c) {
		a = _a;
		b = _b;
		c = _c;
	}

	@Override
	public int compareTo(Object _o) {
		return this.c - ((Line)_o).c;
	}
}

class SetArrow{
	SetArrow next;
	SetArrow() {
		next = null;
	}
	SetArrow(SetArrow _next) {
		next = _next;
	}
	SetArrow search() {
		if(next==null) return this;
		next = next.search();
		return next;
	}
	static void add(SetArrow a1, SetArrow a2) {
		SetArrow newArrow = new SetArrow();
		a1.next = newArrow;
		a2.next = newArrow;
	}
}
