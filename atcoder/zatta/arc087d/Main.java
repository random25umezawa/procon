import java.util.*;

class Main{
	static int lastX;
	static int lastY;
	static char[] input;
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		input = scan.next().toCharArray();
		lastX = scan.nextInt();
		lastY = scan.nextInt();
		HashSet<Robot> nset = null;
		HashSet<Robot> oset = null;
		HashSet<Robot> set1 = new HashSet<>(1<<20);
		HashSet<Robot> set2 = new HashSet<>(1<<20);
		boolean isOne = true;
		set1.add(new Robot(0,0,0));
		oset = set1;
		nset = set2;
		//for(char operation : input) {
		int fCount = 0;
		for(int i = 0; i < input.length; i++) {
			char operation = input[i];
			nset.clear();
			if(operation=='F') {
				fCount++;
				if(i+1==input.length || input[i+1]=='T') {
					for(Robot _r : oset) {
						_r.move(fCount);
						//System.out.println(_r.canAchieve(input.length-i-1));
						if(!_r.canAchieve(input.length-i-1)) continue;
						nset.add(_r);
					}
					fCount=0;
				}
			}else {
				for(Robot _r : oset) {
					if(!_r.canAchieve(input.length-i-1)) continue;
					nset.add(new Robot(_r.x,_r.y,(_r.dir+5)%4));
					_r.dir = (_r.dir+3)%4;
					nset.add(_r);
				}
			}
/*
			System.out.println("-----"+operation+"-----");
			for(Robot _r : nset) {
				System.out.printf("(%d,%d,%d)\n",_r.x,_r.y,_r.dir);
			}
*/
			if(fCount==0) {
				if(isOne) {
					oset = set2;
					nset = set1;
				}else {
					oset = set1;
					nset = set2;
				}
				isOne = !isOne;
			}
		}
		for(int i = 0; i < 4; i++) {
			Robot robot = new Robot(lastX,lastY,i);
			if(oset.contains(robot)) {
				System.out.println("Yes");
				return;
			}
		}
		System.out.println("No");
	}
}

class Robot{
	int x,y;
	int dir;
	Robot(int _x, int _y, int _dir) {
		x = _x;
		y = _y;
		dir = _dir;
	}
	void move(int fCount) {
		if(dir%2==0) {
			if(dir==0) x+=fCount;
			else x-=fCount;
		}else {
			if(dir==1) y+=fCount;
			else y-=fCount;
		}
	}
	boolean canAchieve(int _rest) {
		int count = Math.abs(Main.lastX-x)+Math.abs(Main.lastY-y);
		return count<=_rest;
	}
	@Override
	public int hashCode() {
		return Objects.hash(x,y,dir);
	}
	@Override
	public boolean equals(Object _o) {
		return this.hashCode() == _o.hashCode();
	}
}
