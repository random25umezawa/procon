import java.io.*;
import java.util.*;

class Main{
	public static void main(String[] args) throws Exception{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(reader.readLine());
		String[] input = reader.readLine().split(" ");
		TreeSet<Stone> set = new TreeSet<Stone>();
		for(int i = 0; i < input.length; i++) {
			set.add(new Stone(i,Long.parseLong(input[i])));
		}
		//for(Stone _stone : set) System.out.println(_stone.num+","+_stone.index);

		long[] result = new long[n];
		while(!set.isEmpty()) {
			Stone last = set.last();
			set.remove(last);
			if(set.isEmpty()) {
				result[last.index] += last.getNum();
			}else {
				Stone newLast = set.last();
				set.remove(newLast);
				if(last.num!=newLast.num) result[last.index] += (last.num-newLast.num)*last.kind;
				newLast.add(last);
				set.add(newLast);
			}
		}
		for(long _result : result) System.out.println(_result);
	}
}

class Stone implements Comparable{
	long num;
	long kind;
	int index;
	Stone(int _index, long _num) {
		num = _num;
		kind = 1;
		index = _index;
	}
	void add(Stone _stone) {
		this.kind += _stone.kind;
		this.index = Math.min(this.index,_stone.index);
	}
	boolean canAdd(Stone _stone) {
		return num*_stone.kind == _stone.num*kind;
	}
	long getNum() {
		return num*kind;
	}
	@Override
	public int compareTo(Object _obj) {
		Stone _stone = (Stone)_obj;
		if(this.num == _stone.num) {
			if(this.index == _stone.index) return 0;
			return (this.index > _stone.index)?1:-1;
		}
		return (this.num > _stone.num)?1:-1;
	}
}
