import java.io.*;
import java.util.*;

class Main{
	//各処理部分
	//今回、縦と横という見方で同じデータ構造に対して同じ処理を行うため、一般化した関数をそれらで各１回呼び出すように共通化した。

	//引数の型宣言が面倒ならグローバル変数使うのもあり(今回は上の事情でそもそも使えない)


	//入力から同じ行or列にある町の集合を作る
	public static void setInput(Map<Integer,Set<Integer>> _map, int _val, int _town) {
		if(!_map.containsKey(_val)) {
			Set<Integer> _hs = new HashSet<>();
			_hs.add(_town);
			_map.put(_val,_hs);
		}else {
			_map.get(_val).add(_town);
		}
	}

	//隣り合う列or行の間隔についての情報をヒープに入れていく
	public static void setNexttoQueue(Queue<MySet> pq, Map<Integer,Set<Integer>> _map, boolean isTate) {
		int _pre = -1;
		for(Map.Entry<Integer,Set<Integer>> e : _map.entrySet()) {
			int key = e.getKey();
			if(_pre==-1) {
				_pre = key;
			}else {
				pq.add(new MySet(isTate,key,key-_pre));
				_pre = key;
			}
		}
	}

	//同じ短冊状にあるコスト０の枝を入れていく
	//枝一覧に追加せず直接待ち集合を作る処理に変更
	public static void addNocostBranches(int[] townGroup, Map<Integer,Set<Integer>> _map) {
		for(Map.Entry<Integer,Set<Integer>> e : _map.entrySet()) {
			Set<Integer> set = e.getValue();
			int preTownNum = -1;
			for(int townNum : set) {
				if(preTownNum!=-1) {
					//もともとは枝一覧に追加する処理をしていた
					//breanches.add(new Branch(townNum,preTownNum,0));
					townGroup[getGroup(townGroup,townNum)] = getGroup(townGroup,preTownNum);
				}
				preTownNum = townNum;
			}
		}
	}

	//隣合う短冊間を結ぶ道を１つだけ追加
	public static void addNexttoRowBranches(Queue<Branch> branches, Queue<MySet> pq, Map<Integer,Set<Integer>> tate, Map<Integer,Set<Integer>> yoko) {
		while(!pq.isEmpty()) {
			MySet ms = pq.poll();
			Map<Integer,Set<Integer>> _map = null;
			if(ms.isTate) {
				_map = tate;
			}else{
				_map = yoko;
			}

			//System.out.println(ms.isTate+","+ms.index+","+(ms.index-ms.value));

			Set<Integer> set1 = _map.get(ms.index);
			Set<Integer> set2 = _map.get(ms.index-ms.value);
			int townNum1 = -1;
			int townNum2 = -1;
			for(int i : set1) {
				townNum1 = i;
				break;
			}
			for(int i : set2) {
				townNum2 = i;
				break;
			}

			branches.add(new Branch(townNum1,townNum2,ms.value));
		}
	}

	//クラスカル
	public static int calcMinAllareaTree(int[] townGroup, Queue<Branch> branches) {
		int result = 0;
		while(!branches.isEmpty()) {
			/*
			for(int i = 0; i < townGroup.length; i++) {
				System.out.print(townGroup[i].getParent().toString().substring(5,10)+",");
			}
			*/
			//System.out.println();
			Branch branch = branches.poll();
			int group1 = getGroup(townGroup,branch.n1);
			int group2 = getGroup(townGroup,branch.n2);
			//System.out.println(branch.n1+","+branch.n2+","+branch.value);
			if(group1!=group2) {
				//System.out.println(branch.value);
				result += branch.value;
				townGroup[group1] = group2;
			}
		}
		return result;
	}

	//所属するグループを辿って取得する
	public static int getGroup(int[] townGroup, int _index) {
		int group = townGroup[_index];
		if(group==_index) return group;
		else {
			int newGroup = getGroup(townGroup,group);
			townGroup[_index] = newGroup;
			return newGroup;
		}
	}


	public static void main(String[] args) throws Exception{
		//入力が多い(n=100000)時はScannerだと間に合わないことがある
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(reader.readLine());

		//同じx座標(key)上にある町の集合(value),同じくyも
		Map<Integer,Set<Integer>> tate = new TreeMap<>(), yoko = new TreeMap<>();
		for(int i = 0; i < n; i++) {
			String[] _input = reader.readLine().split(" ");
			int _x = Integer.parseInt(_input[0]);
			int _y = Integer.parseInt(_input[1]);
			setInput(tate,_x,i);
			setInput(yoko,_y,i);
		}
/*
			//縦横の短冊上ラインごとに存在する町を出力
			for(Map.Entry e : tate.entrySet()) System.out.println(e.getKey()+" , "+e.getValue());
			for(Map.Entry e : yoko.entrySet()) System.out.println(e.getKey()+" , "+e.getValue());
*/

		//短冊セット間の距離が短い順に取り出せるヒープ
		Queue<MySet> pq = new PriorityQueue<>();
		setNexttoQueue(pq, tate, true);
		setNexttoQueue(pq, yoko, false);

		//各町が所属するノード
		int[] townGroup = new int[n];
		for(int i = 0; i < n; i++) townGroup[i] = i;

		//枝をコストの少ない順に取り出せるヒープ
		Queue<Branch> branches = new PriorityQueue<>();
		//同じ短冊上にあるコスト０の枝を追加
		//ヒープに追加せず直接グループをまとめるように変更
		addNocostBranches(townGroup,tate);
		addNocostBranches(townGroup,yoko);
		//隣合う短冊間を結ぶ枝を１本だけ追加する
		addNexttoRowBranches(branches,pq,tate,yoko);

		//クラスカル
		int result = calcMinAllareaTree(townGroup, branches);

		System.out.println(result);
	}
}

class MySet implements Comparable{
	boolean isTate;	//縦かどうか
	int index;	//x,yどっちかの座標
	int value;	//隣接距離

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

class Branch implements Comparable{
	int n1,n2;	//つながっている２つの町番号
	int value;	//コスト

	public Branch(int _n1, int _n2, int _value) {
		n1 = _n1;
		n2 = _n2;
		value = _value;
	}

	@Override
	public int compareTo(Object _o) {
		return this.value - ((Branch)_o).value;
	}
}
