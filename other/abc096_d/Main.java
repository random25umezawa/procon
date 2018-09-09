import java.util.*;
import java.util.stream.*;

class Main{
	public static void main(String[] args) {
		List<Integer> primes = new ArrayList<>(1<<15);
		LABEL: for(int i = 2; i < 55555; i++) {
			for(int prime : primes) {
				if(prime*prime>i) break;
				if(i%prime==0) continue LABEL;
			}
			primes.add(i);
		}

		Scanner scan = new Scanner(System.in);
		int input = scan.nextInt();

		String ans = primes.stream()
			.filter(num -> num%5==1)
			.limit(input)
			.map(String::valueOf)
			.collect(Collectors.joining(" "));
		System.out.println(ans);
	}
}
