class Main{
	public static void main(String[] args) {
		int[][] arr = new int[4][1];
		arr[0][0] = 0;
		arr[1][0] = 1;
		arr[2][0] = 2;
		arr[3][0] = 3;
		int[][] newArr = orikaesi(orikaesi(arr,true),true);
		for(int i = 0; i < newArr.length; i++) {
			for(int j = 0; j < newArr[i].length; j++) {
				System.out.print(newArr[i][j]+" ");
			}
			System.out.println();
		}
	}

	static int[][] orikaesi(int[][] moto, boolean isLeft) {
		int[][] newArr = new int[moto.length/2][moto[0].length*2];
		if(isLeft) {
			for(int i = 0; i < moto.length/2; i++) {
				for(int j = 0; j < moto[i].length; j++) {
					if(i<moto.length/2) newArr[newArr.length-i-1][newArr[0].length-j-1] = moto[i][j];
					else newArr[i-newArr.length-1][j+newArr[0].length-1] = moto[i][j];
				}
			}
		}
		return newArr;
	}
}
/*
0 1 2 3

1 0
2 3

2
1
0
3

1 2 3 4
5 6 7 8

6 5
2 1
3 4
7 8*/
