import java.util.*;

// 2次元いもす法を使う
// https://imoz.jp/algorithms/imos_method.html

class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int h = scan.nextInt();
		int w = scan.nextInt();
		int n = scan.nextInt();
		int m = scan.nextInt();

		boolean noDotFlag = true;	//何も無いフラグ
		int arrSizeX = Math.min(w,m*2);	//右端と左端ではんこ押したときに領域が重なるかどうか
		int arrSizeY = Math.min(h,n*2);	//重ならないときは間部分の補完が必要
		int[][] arr = new int[arrSizeX][arrSizeY];

		for(int i = 0; i < n; i++) {
			char[] input = scan.next().toCharArray();
			for(int j = 0; j < m; j++) {
				if(input[j]=='#') {
					noDotFlag = false;
					int y = i;
					int x = j;
					//2次元いもす4隅
					//変数に入れなおしたほうがミスは少ない
					arr[x][y]++;
					if(arrSizeX-m+x+1<arrSizeX) arr[arrSizeX-m+x+1][y]--;
					if(arrSizeY-n+y+1<arrSizeY) arr[x][arrSizeY-n+y+1]--;
					if(arrSizeX-m+x+1<arrSizeX && arrSizeY-n+y+1<arrSizeY) arr[arrSizeX-m+x+1][arrSizeY-n+y+1]++;
				}
			}
		}
		if(noDotFlag) {
			System.out.println(0);
			System.exit(0);
		}

		//いもす端っこ情報の出力
		/*
		for(int j = 0; j < arrSizeY; j++) {
			for(int i = 0; i < arrSizeX; i++) {
				System.out.print(arr[i][j]+",");
			}
			System.out.println();
		}
		*/

		//いもす展開
		for(int i = 1; i < arrSizeX; i++) {
			for(int j = 0; j < arrSizeY; j++) {
				arr[i][j] += arr[i-1][j];
			}
		}
		for(int j = 1; j < arrSizeY; j++) {
			for(int i = 0; i < arrSizeX; i++) {
				arr[i][j] += arr[i][j-1];
			}
		}
		//黒いマスを数える
		long ans = 0;
		for(int j = 0; j < arrSizeY; j++) {
			for(int i = 0; i < arrSizeX; i++) {
				if(arr[i][j]>0)ans++;
			}
		}

		//いもす展開後の出力
		/*
		for(int j = 0; j < arrSizeY; j++) {
			for(int i = 0; i < arrSizeX; i++) {
				System.out.print(arr[i][j]+",");
			}
			System.out.println();
		}
		*/

		//補完部分
		//横・縦は、真ん中の行・列を延々引きのばしたもので考える
		//でかいのでintのままだと死ぬことがあるので注意

		//横
		if(arrSizeX<w) {
			long count = 0;
			for(int j = 0; j < arrSizeY; j++) {
				count += (arr[m][j]>0)?1:0;
			}
			ans += count*(w-m*2);
		}
		//縦
		if(arrSizeY<h) {
			long count = 0;
			for(int i = 0; i < arrSizeX; i++) {
				count += (arr[i][n]>0)?1:0;
			}
			ans += count*(h-n*2);
		}
		//中央
		if(arrSizeX<w&&arrSizeY<h) {
			ans += ((long)(h-n*2))*(w-m*2);
		}

		System.out.println(ans);
	}
}
