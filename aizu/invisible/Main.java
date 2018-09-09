import java.util.*;

class Main{
	static final int DEFAULT = -1000000000;
	static final int PASS = -555;
	static Stack<Card> p1,p2;
	static Stack<Card> stack;
	static Stack<Integer> score;
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int input1 = scan.nextInt();
		int input2 = scan.nextInt();
		p1 = new Stack<Card>();
		for(int i = 0; i < input1; i++) p1.push(new Card(scan.nextInt(),1));
		p2 = new Stack<Card>();
		for(int i = 0; i < input2; i++) p2.push(new Card(scan.nextInt(),2));
		stack = new Stack<Card>();
		score = new Stack<Integer>();

		System.out.println(calc(0,0,true,false));
	}

	static int calc(int p1_index, int p2_index, boolean isP1, boolean pass) {
		System.out.printf("%3d,%3d,%b,%b\n",p1_index,p2_index,isP1,pass);
		int result = 0;
		if(p1_index==p1.size() && p2_index==p2.size()) {

			result += calcPoint();
			System.out.println(score.toString()+result);
			for(Integer _score : score) result += _score;
			System.out.println(stack);
			System.out.println("result: "+result);
			return result;
		}
		result = DEFAULT;
		if(isP1) {
			if(p1_index<p1.size()) {
				stack.push(p1.get(p1_index));
				result = calc(p1_index+1,p2_index,!isP1,false);
				stack.pop();
			}
			if(!pass) {
				score.push(calcPoint());
				stack.push(new Card(PASS,3));
				int _score = calc(p1_index,p2_index,!isP1,true);
				if(result==DEFAULT) result = _score;
				else result = Math.max(_score,result);
				score.pop();
				stack.pop();
			}
			System.out.println((p1_index+p2_index)+"max: "+result);
		}else {
			if(p2_index<p2.size()) {
				stack.push(p2.get(p2_index));
				result = calc(p1_index,p2_index+1,!isP1,false);
				stack.pop();
			}

			if(!pass) {
				score.push(calcPoint());
				stack.push(new Card(PASS,3));
				int _score = calc(p1_index,p2_index,!isP1,true);
				if(result==DEFAULT) result = _score;
				else result = Math.min(_score,result);
				score.pop();
				stack.pop();
			}
			System.out.println((p1_index+p2_index)+"min: "+result);
		}
		return result;
	}

	static int calcPoint() {
		int result = 0;
		boolean p1flag = true;
		boolean p2flag = true;
		for(int i = stack.size()-1; i >= 0; i--) {
			Card card = stack.get(i);
			if(card.num!=PASS) {
				if(card.num==-1) {
					if(card.player == 1) p2flag = false;
					else if(card.player == 2) p1flag = false;
				}else {
					if(p1flag&&card.player==1) result += card.num;
					else if(p2flag&&card.player==2) result -= card.num;
				}
				if(!p1flag&&!p2flag) break;
			}else {
				break;
			}
		}
		return result;
	}
}

class Card{
	int num;
	int player;
	Card(int _num, int _player) {
		num = _num;
		player = _player;
	}

	public String toString() {
		return ""+num;
	}
}
