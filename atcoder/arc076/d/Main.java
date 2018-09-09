import java.io.*;
import java.util.*;

class Main{
	public static void main(String[] args) throws Exception{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(reader.readLine());
		Map<Integer,HashSet<Integer>> tate = new TreeMap<>();
		Map<Integer,HashSet<Integer>> yoko = new TreeMap<>();
		for(int i = 0; i < n; i++) {
			String[] _input = reader.readLine().split(" ");
			int _x = Integer.parseInt(_input[0]);
			int _y = Integer.parseInt(_input[1]);
			if(!tate.containsKey(_x)) {
				HashSet<Integer> _hs = new HashSet<>();
				_hs.add(i);
				tate.put(_x,_hs);
			}else {
				tate.get(_x).add(i);
			}
			if(!yoko.containsKey(_y)) {
				HashSet<Integer> _hs = new HashSet<>();
				_hs.add(i);
				yoko.put(_y,_hs);
			}else {
				yoko.get(_y).add(i);
			}
		}
/*
				for(Map.Entry e : tate.entrySet()) {
					System.out.println(e.getKey()+" , "+e.getValue());
				}
						for(Map.Entry e : yoko.entrySet()) {
							System.out.println(e.getKey()+" , "+e.getValue());
						}
*/

		PriorityQueue<MySet> pq = new PriorityQueue<>();

		int[] checked = new int[n];
		for(int i = 0; i < n; i++) checked[i] = i;

		int _pre = -1;
		for(Map.Entry<Integer,HashSet<Integer>> e : tate.entrySet()) {
			int key = e.getKey();
			if(_pre==-1) {
				_pre = key;
			}else {
				pq.add(new MySet(true,key,key-_pre));
				_pre = key;
			}
				int max_num = -1;
				HashSet<Integer> hs = e.getValue();
				for(int town : hs) {
					max_num = Math.max(max_num,town);
					break;
				}
				for(int town : hs) {
					set(checked,town,max_num);
				}
		}
		_pre = -1;
		for(Map.Entry<Integer,HashSet<Integer>> e : yoko.entrySet()) {
			int key = e.getKey();
			if(_pre==-1) {
				_pre = key;
			}else {
				pq.add(new MySet(false,key,key-_pre));
				_pre = key;
			}
				int max_num = -1;
				HashSet<Integer> hs = e.getValue();
				for(int town : hs) {
					max_num = Math.max(max_num,town);
					break;
				}
				for(int town : hs) {
					set(checked,town,max_num);
				}
		}
/*
		{
			for(Map.Entry<Integer,HashSet<Integer>> e : tate.entrySet()) {
			}
			for(Map.Entry<Integer,HashSet<Integer>> e : yoko.entrySet()) {
			}
		}
*/

		long result = 0;
		while(!pq.isEmpty()) {
			//System.out.println(Arrays.toString(checked));
			MySet ms = pq.poll();
			Map<Integer,HashSet<Integer>> map = null;
			if(ms.isTate) {
				map = tate;
			}else {
				map = yoko;
			}
			//System.out.println(ms.isTate+","+ms.index+","+ms.value);
			HashSet<Integer> hs = map.get(ms.index);
			int checked_town1 = -1;
			int checked_town2 = -1;
			int group_num = -1;
			int town1 = -1;
			int town2 = -1;
			for(int town : hs) {
				group_num = getGroup(checked,town);
				checked_town1 = Math.max(group_num,checked_town1);
				town1 = town;
				break;
			}
			for(int town : hs) {
				set(checked,town,checked_town1);
			}
			hs = map.get(ms.index-ms.value);
			for(int town : hs) {
				group_num = getGroup(checked,town);
				checked_town2 = Math.max(group_num,checked_town2);
				town2 = town;
				break;
			}
			for(int town : hs) {
				set(checked,town,checked_town2);
			}

			if(getGroup(checked,town1)!=getGroup(checked,town2)) {
				result += ms.value;
				//System.out.println(ms.value+","+result);
				hs = map.get(ms.index);
				int new_group = getGroup(checked,town1);
				for(int town : hs) {
					set(checked,town,new_group);
				}
				hs = map.get(ms.index-ms.value);
				for(int town : hs) {
					set(checked,town,new_group);
				}
			}
		}

		System.out.println(result);
	}

	public static int getGroup(int[] _checked, int _index) {
		if(_index == _checked[_index]) {
			return _index;
		}else {
			int result = getGroup(_checked,_checked[_index]);
			_checked[_index] = result;
			return result;
		}
	}

	public static void set(int[] _checked, int _index, int _value) {
		int next = _checked[_index];
		if(next!=_index) set(_checked,next,_value);
		_checked[_index] = _value;
	}
}

class MySet implements Comparable{
	boolean isTate;
	int index;
	int value;

	public MySet(boolean _isTate, int _index, int _value) {
		isTate = _isTate;
		index = _index;
		value = _value;
	}

	@Override
	public int compareTo(Object _o) {
		return this.value - ((MySet)_o).value;
	}
}
