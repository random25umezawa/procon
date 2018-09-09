import java.io.*;
import java.util.*;

class Main{
	public static void main(String[] args) throws Exception{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(reader.readLine());
		char[][] input = new char[n][];

		Node parent = new Node('N',false);
		for(int i = 0; i < n; i++) {
			input[i] = reader.readLine().toCharArray();
			parent.add(input[i], 0);
		}

		parent.debug();
		parent.shorter();
		System.out.println("------------");
		parent.debug();
		System.out.println("------------");

		int q = Integer.parseInt(reader.readLine());
		for(int loop = 0; loop < q; loop++) {
			String[] dummyInput = reader.readLine().split(" ",0);
			int inputIndex = Integer.parseInt(dummyInput[0]) - 1;
			char[] zisyo = dummyInput[1].toCharArray();

			System.out.println(parent.calc(input[inputIndex],zisyo,0));
		}
	}
}

class Node{
	char myChar;
	boolean end;
	int[] count;
	Node[] next;
	int[] skip;

	int nodeCount = 0;
	int firstNodeIndex = -1;
	boolean firstNodeFlag = false;

	Node(char _myChar, boolean _end) {
		myChar = _myChar;
		end = _end;
		count = new int[26];
		next = new Node[26];
		skip = new int[26];
	}

	void shorter() {
		System.out.println(firstNodeFlag);
		if(!firstNodeFlag) return;
		System.out.println((nodeCount==1) + "," + (next[firstNodeIndex].nodeCount==1) + "," + (!next[firstNodeIndex].end));
		if(nodeCount==1 && next[firstNodeIndex].nodeCount==1 && !next[firstNodeIndex].end) {
			next[firstNodeIndex] = next[firstNodeIndex].next[next[firstNodeIndex].firstNodeIndex];
			System.out.println("shorter");
		}
		skip[firstNodeIndex]++;
		next[firstNodeIndex].shorter();
	}

	void add(char[] input, int insertCount) {
		if(insertCount>=input.length) {
			this.end = true;
			return;
		}
		int insertIndex = (int)(input[insertCount]-'a');
		if(next[insertIndex] == null) {
			next[insertIndex] = new Node(input[insertCount], false);
			nodeCount++;
			if(!firstNodeFlag) {
				firstNodeFlag = true;
				firstNodeIndex = insertIndex;
			}
		}
		count[insertIndex]++;
		next[insertIndex].add(input,insertCount+1);
	}

	public void debug() {
		System.out.println(myChar+","+end);
		for(int i = 0; i < 26; i++) {
			if(next[i] != null) {
				System.out.println(count[i]+"L");
				next[i].debug();
				System.out.println("_l");
			}
		}
	}

	public int calc(char[] input, char[] zisyo, int _count) {
		if(_count>=input.length) return 1;
		int result = 0;
		result += (this.end)?1:0;
		for(int i = 0; i < 26; i++) {
			if(zisyo[i] == input[_count]) break;
			result += count[(int)(zisyo[i]-'a')];
		}
		//System.out.println(_count+":"+result);
		return result + next[input[_count]-'a'].calc(input,zisyo,_count+1+skip[input[_count]-'a']);
	}
}
