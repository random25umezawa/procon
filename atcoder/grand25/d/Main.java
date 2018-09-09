import java.util.*;

class Main{
	static int n;
	static int[][] ansArr;
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		n = scan.nextInt();
		ansArr = new int[2][n];
		ArrayList<ArrayList<Integer>> graph = new ArrayList<>(n);
		for(int i = 0; i < n; i++) graph.add(new ArrayList<Integer>(n));
		for(int i = 0; i < n-1; i++) {
			int a = scan.nextInt()-1;
			int b = scan.nextInt()-1;
			graph.get(a).add(b);
			graph.get(b).add(a);
		}

		int ans = 999;
		int nodes = 999;

		for(int i = 0; i < n; i++) {
			//System.out.println("  "+i);
			ArrayList<ArrayList<Integer>> graph2 = new ArrayList<>(n);
			for(int j = 0; j < n; j++) graph2.add((ArrayList<Integer>)graph.get(j).clone());
			graph2.add(new ArrayList<Integer>(1));
			graph2.get(i).add(n);
			graph2.get(n).add(i);
			calc(i,graph2);
			if(ansArr[0][i]<ans) {
				ans = ansArr[0][i];
				nodes = ansArr[1][i];
			}else if(ansArr[0][i]==ans) {
				if(ansArr[1][i]<nodes) nodes = ansArr[1][i];
			}
		}
		for(int i = 0; i < n; i++) {
			//System.out.println(ansArr[0][i]+" "+ansArr[1][i]);
		}
		System.out.println(ans+" "+nodes);
	}

	public static void calc(int insertedIndex, ArrayList<ArrayList<Integer>> graph) {
		ArrayList<ArrayList<Integer>> minArr = new ArrayList<>(n+1);
		HashSet<String> set = new HashSet<>();
		int minNodes = 0;
		//for(ArrayList<Integer> _arr : graph) System.out.println(_arr);
		for(int i = 0; i <= n; i++) {
			//calc min distance
			Stack<Integer> posStack = new Stack();
			Stack<Integer> dstStack = new Stack();
			boolean[] arrived = new boolean[n+1];
			int[] minDistance = new int[n+1];
			int leafs = 0;
			posStack.push(i);
			dstStack.push(0);
			while(!posStack.isEmpty()) {
				//System.out.println(posStack);
				int pos = posStack.pop();
				int dst = dstStack.pop();
				//System.out.println(pos);
				if(arrived[pos]) continue;
				arrived[pos] = true;
				minDistance[pos] = dst;
				//System.out.println(graph.get(i));
				int count = 0;
				for(int next : graph.get(pos)) {
					if(arrived[next]) continue;
					count++;
					posStack.push(next);
					dstStack.push(dst+1);
				}
				if(count==0) {
					//System.out.println(i);
					leafs++;
				}
			}
			//end
			ArrayList<Integer> oneMinArr = new ArrayList<Integer>(n+1);
			for(int _min : minDistance) oneMinArr.add(_min);
			//System.out.println(oneMinArr);
			Collections.sort(oneMinArr);
			minArr.add(oneMinArr);

			String arrString = "";
			for(int _min : oneMinArr) arrString += _min+",";
			set.add(arrString);
			minNodes = Math.max(minNodes,leafs);
		}
		ansArr[0][insertedIndex] = set.size();
		ansArr[1][insertedIndex] = minNodes;
	}
}
