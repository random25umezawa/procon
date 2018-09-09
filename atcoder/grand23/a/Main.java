import java.util.*;

class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int n = scan.nextInt();

		Map<Long,Long> map = new HashMap<>();

		long[] arr = new long[n+1];
		arr[0] = 0;
		for(int i = 0; i < n; i++) {
			arr[i+1] = (long)scan.nextInt()+arr[i];
			if(!map.containsKey(arr[i+1])) {
				map.put(arr[i+1],1L);
			}else {
				map.put(arr[i+1],map.get(arr[i+1])+1L);
			}
		}

		long ans = 0;

		for(Map.Entry<Long,Long> entry : map.entrySet()) {
			long lng = entry.getValue();
			//System.out.println(entry);
			if(lng<=1) continue;
			/*
			long plus = 1;
			for(int i = 2; i <= lng; i++) {
				plus *= i;
			}
			plus/=2;
			*/
			long plus = lng*(lng-1)/2;
			ans += plus;
		}

		if(map.containsKey(0L)) ans += map.get(0L);

		System.out.println(ans);
	}
}
