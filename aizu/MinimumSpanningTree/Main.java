import java.util.*;
import java.io.*;

class Main{
	public static void main(String[] args){
		MyScanner scan = new MyScanner(System.in);
		int v = scan.nextInt();
		int e = scan.nextInt();
		Group[] groups = new Group[v];
		for(int i = 0; i < v; i++) groups[i] = new Group();
		List<List<Branch>> nodeHavingBranches = new ArrayList<>(v);
		for(int i = 0; i < v; i++) nodeHavingBranches.add(new ArrayList());
		for(int i = 0; i < e; i++) {
			int s = scan.nextInt();
			int t = scan.nextInt();
			int v = scan.nextInt();
			Branch _b = new Branch(s,t,v);
			nodeHavingBranches.get(s).append(_b);
			nodeHavingBranches.get(t).append(_b);
		}
		TreeSet<Branch> branches = new TreeSet<>();
		branches.addAll(nodeHavingBranches.get(0));
		int result = 0;
		while(groups[0].num<v) {
			for(Branch _b : branches) {
				Group g1 = groups[_b.s].getGroup();
				Group g2 = groups[_b.t].getGroup();
				if(g1==g2) continue;
				Group newg = new Group();
				g1.parent = newg;
				g2.parent = newg;
				newg.num = g1.num + g2.num;
				result += _b.v;
				break;
			}
			branches.addAll();
		}
		System.out.println(result);
	}
}

class Group{
	Group parent;
	int num;
	Group(){
		num = 1;
	}
	Group getGroup() {
		return (parent==null)?this:parent.getGroup();
	}
}

class Branch implements Comparable<Branch>{
	int s,t;
	int v;
	Branch(int _s, int _t, int _v) {
		s = _s;
		t = _t;
		v = _v;
	}
	@Override
	public int compareTo(Branch _b) {
		if(this==_b) return 0;
		if(this.v == _b.v) return 1;
		return this.v - _b.v;
	}
}

class MyScanner{
	InputStream in;
	MyScanner(InputStream _in) {
		in = _in;
	}
	int nextInt() {
		int result = 0;
try{
		int _i = in.read();
		while(_i<'0'||_i>'9') {
			_i = in.read();
		}
		while(_i>='0'&&_i<='9') {
			result *= 10;
			result += (int)(_i-'0');
			_i = in.read();
		}
		return result;
}catch(Exception e) {
	e.printStackTrace();
	return 0;
}
	}
}
