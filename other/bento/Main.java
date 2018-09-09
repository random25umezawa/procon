import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		while(true) {
			//入力
			int n = scan.nextInt();
			int m = scan.nextInt();
			if(n==0) break;

			int[][] arr = new int[n][m];
			for(int i = 0; i < n; i++) {
				char[] input = scan.next().toCharArray();
				for(int j = 0; j < m; j++) {
					arr[i][j] = (input[j]=='1')?1:0;
				}
			}

			//レシピ数 > 食材数 ( bitDP )
			if(n>m) {
				int[] dp = new int[1<<m];	//食材の余り数集合ごとの、最大できるレシピ数
				int[] resipe = new int[n];	//int型で扱ったほうが楽なので入力を32bitに変換
				int first = 0;	//すべてのレシピを入れたときの、食材余り数集合
				for(int i = 0; i < n; i++) {
					for(int j = 0; j < m; j++) {
						resipe[i] += arr[i][m-1-j]<<j;	//各位のビット値
					}
					first ^= resipe[i];	//繰り上がりなし足し算で偶奇の入れ替え
				}
				Queue<Integer> q = new ArrayDeque<>();
				q.add(first);	//初期状態は全レシピを入れたときの、食材余り数集合
				int maxResipe = n;	//最大で作れるレシピ数
				dp[first] = maxResipe;
				while(maxResipe>0) {
					if(dp[0]>0) break;	//すべての食材の余り０の最大レシピ数が０以上→答え出てる
					maxResipe--;
					int q_size = q.size();	//queueの数分取り出して処理(同じレシピ数作れる場合の集合たち)
					for(int q_loop = 0; q_loop < q_size; q_loop++) {
						int state = q.poll();
						for(int i = 0; i < n; i++) {
							int newState = state^resipe[i];
							if(dp[newState] < maxResipe) {	//初めて出てきた余り数集合
								dp[newState] = maxResipe;
								q.add(newState);
							}
						}
					}
				}
				System.out.println(dp[0]);

			}else {
				//簡単な全探索

				int[] numArr = new int[n];	//全探索用の配列
				int[] material = new int[m];	//食材ごとの使う個数
				int result = 0;
				while(true) {
					int maxResipe = 0;	//使ったレシピ数 ( 下の加算器の１の数 )

					//全探索用のビット加算器(０は飛ばす、最上位が２になるまで加算し続ける)
					numArr[0]++;
					for(int i = 0; i < n-1; i++) {
						if(numArr[i]>1) {
							numArr[i+1]++;
							numArr[i]-=2;
						}
						maxResipe += numArr[i];
					}
					maxResipe += numArr[numArr.length-1];
					if(numArr[numArr.length-1]>1) break;

					//各食材数計算
					Arrays.fill(material,0);
					for(int i = 0; i < n; i++) {
						if(numArr[i]>0) {
							for(int j = 0; j < m; j++) {
								material[j] += arr[i][j];
							}
						}
					}

					//全食材数が偶数なら最大値更新フラグ
					boolean allGuusuuFlag = true;
					for(int i = 0; i < m; i++) {
						allGuusuuFlag &= (material[i]%2==0);
					}
					if(allGuusuuFlag) {
						result = Math.max(result,maxResipe);
					}
				}
				System.out.println(result);
			}
		}
	}
}
