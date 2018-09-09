class Rand{
	public static void main(String[] args) {
		for(int i = 5; i <= 20; i++) {
			System.out.println(i);
			for(int j = 0; j < i; j++) {
				System.out.print((int)(Math.random()*9+1)+" ");
			}
			System.out.println();
		}
		System.out.println(0);
	}
}
